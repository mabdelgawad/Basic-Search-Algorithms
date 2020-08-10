/*
 * astar.cpp file: source file represents
 * the implementation of A-Star Algorithm ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "astar.hpp"

namespace WeightedGraphSearch {


//! clean frontier, closed list, parents, and path
void AStar::clean(){
    while(!frontier.empty()) frontier.pop();
    if(!closed_list.empty()) closed_list.clear();
    if(!parents.empty()) parents.clear();
}


////! frontier node duplication detection
bool AStar::frontierContainNode(std::priority_queue<PQ_element,
                             std::vector<PQ_element>,
                             std::greater<PQ_element>>& frontiers_,
                             Node& node) const{

    while(!frontiers_.empty()){
        auto top_node = frontiers_.top().second;
        frontiers_.pop();
        if(top_node == node)
            return true;
    }

    return false;
}


//! closed list node duplication detection
bool AStar::closedListContainNode(Node& node) const{
    if(closed_list.find(node) == closed_list.end())
        return false;
    else
        return true;
}


//! A-Star process to find a path from start to goal node
std::deque<Node> AStar::findPath(Node& start, Node& goal){

    //! check if the start and target
    //! are exist in the graph
    if(!graph.containsNode(start) ||
       !graph.containsNode(goal))
            return path;

    //! clean all lists used for A-Star
    clean();

    //! push start node into the frontier
    frontier.push(std::make_pair(0,start));

    while (!frontier.empty()) {

           //! pop the top node from frontiers priority queue
           PQ_element frontierTopNode = frontier.top();
           frontier.pop();

           //! push this node into visited node set
           closed_list.insert(frontierTopNode.second);


           //! check if the node pushed in the closed
           //! list is the goal, then constract a path
           if(frontierTopNode.second == goal){
               Path(goal);
               return path;
           }

           //! Otherwise, get the outgoing edges of the frontier node
           std::vector<Edge> outgoingEdges =
                   graph.getOutgoingEdges(frontierTopNode.second);

           //! for each succesor, update the frontiers, closed list,
           //! and parents for next iteration
           for(auto& outgoingEdge : outgoingEdges){

               //! set the successor node f_value as infinite
               PQ_element successor = std::make_pair(INFINITE_NUM,
                                      outgoingEdge.getSuccessor());

               improve(frontierTopNode, successor,
                                         outgoingEdge.getWeight());
           }
    }

    return path;
}


//! Updating frontier, closed list, and parents
void AStar::improve(PQ_element& predecussor, PQ_element& successor,
                       int weight){

    bool successorNode_exist_in_frontier = false;
    //! scope to copy the frontier for search for a
    //! successor in the frontier, and then destroy copy
    {
        std::priority_queue<PQ_element,
                  std::vector<PQ_element>,
                  std::greater<PQ_element>> frontiers_(frontier);

        successorNode_exist_in_frontier =
                frontierContainNode(frontiers_, successor.second);
    }

  if(successorNode_exist_in_frontier){
      //! check if the f-value is less successor's f-value
      if((predecussor.first + weight) < successor.first){
          //! store edge (predecessor - successor) into
          //! the parents list for backtracking process
          parents.push_back({predecussor.second, successor.second});

          //! update the f-value of the successor (f = g + h)
          successor.first = (predecussor.first + weight) +
                            (getHeuristic(predecussor.second,
                                          successor.second));
      }
  }

  //! check if successor has been visited
else if(closedListContainNode(successor.second)){

      //! check if the f-value is less successor's f-value
      if((predecussor.first + weight) < successor.first){

          //! store edge (predecessor - successor) into
          //! the parents list for backtracking process
          parents.push_back({predecussor.second, successor.second});

          //! update the f-value of the successor (f = g + h)
          successor.first = (predecussor.first + weight) +
                            (getHeuristic(predecussor.second,
                                          successor.second));

          //! then, push it into the frontier
          frontier.push(successor);

          //! and, remove it from closed list
          removeNodeFromcloseList(successor.second);
      }
  }
else{
//! store edge (predecessor - successor) into
//! the parents list for backtracking process
parents.push_back({predecussor.second, successor.second});

//! initialize the f-value of the successor (f = g + h)
successor.first = (predecussor.first + weight) +
                  (getHeuristic(predecussor.second,
                                successor.second));

//! then, push it into the frontiers
frontier.push(successor);
}

}


//! remove a node from closed list
void AStar::removeNodeFromcloseList(Node& node){
//! lookup the node to get its index, if it exist,
auto it = closed_list.find(node);
if (it != closed_list.end())
  closed_list.erase(it);
}

//! build a path using backtracking
void AStar::Path(Node& goal){

    //!clean the path for a new one
    if(!path.empty()) path.clear();

    //! push the goal node into path
    path.push_front(goal);

    //! loop backward through parents and
    //! push each predecessor that its
    //! successor is the last node in the path
    for(auto rit = parents.rbegin(); rit != parents.rend(); rit++)
        if((*rit).getSuccessor() == path.front())
            path.push_front((*rit).getPredecessor());
}


//! use floyd warshall to get the h-value
int AStar::getHeuristic(Node& preducessor, Node& successor){

    //! check if it has been initiated,
    //! if NOT, then initiate it by using
    //! floyd warshall algorithm
    if(h_values.empty()){
        FloydWarshall floydWarshall(graph);
        h_values = floydWarshall.allPairsShortestPaths();
    }

    int ROW = graph.getIndexOf(preducessor);
    int COLUMN = graph.getIndexOf(successor);

    return (h_values[ROW][COLUMN]);
}


} /* end of the name space */

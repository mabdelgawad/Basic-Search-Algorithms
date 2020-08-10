/*
 * bellman_ford.cpp file: source file represents
 * the implementation of Bellman-Ford Algorithm ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "bellman_ford.hpp"

namespace WeightedGraphSearch {


//! clean frontier, closed list, parents, and path
void BellmanFord::clean(){
    if(!frontier.empty()) frontier.clear();
    if(!closed_list.empty()) closed_list.clear();
    if(!parents.empty()) parents.clear();
}


////! frontier node duplication detection
bool BellmanFord::frontierContainNode(Node& node) const{
    for(auto& element : frontier)
        if(element.second == node)
            return true;

    return false;
}

//! closed list node duplication detection
bool BellmanFord::closedListContainNode(Node& node) const{
    if(closed_list.find(node) == closed_list.end())
        return false;
    else
        return true;
}


//! Bellman-Ford process to find a path from start to goal node
std::deque<Node> BellmanFord::findPath(Node& start, Node& goal){

    //! check if the start and target
    //! are exist in the graph
    if(!graph.containsNode(start) ||
       !graph.containsNode(goal))
            return path;

    //! clean all lists used for Dijkstra
    clean();

    //! push start node into the frontiers
    frontier.push_back(std::make_pair(h_value,start));

    while (!frontier.empty()) {

           //! pop the top node from frontiers priority queue
           PQ_element frontierFrontNode = frontier.front();
           frontier.pop_front();

           //! push this node into visited node set
           closed_list.insert(frontierFrontNode.second);


           //! check if the node pushed into closed list
           //! is the goal, then constract a path and exit
           if(frontierFrontNode.second == goal){
               Path(goal);
               return path;
           }

           //! get the outgoing edges of the frontier node
           std::vector<Edge> outgoingEdges =
                   graph.getOutgoingEdges(frontierFrontNode.second);

           //! for each succesor, update the frontiers, closed list,
           //! and parents for next iteration
           for(auto& outgoingEdge : outgoingEdges){

               //! set the successor node f_value as infinite
               PQ_element successor = std::make_pair(INFINITE_NUM,
                                      outgoingEdge.getSuccessor());

               improve(frontierFrontNode, successor,
                                         outgoingEdge.getWeight());
           }
    }

    return path;
}


//! Updating frontiers, closed list, and parents
void BellmanFord::improve(PQ_element& predecussor, PQ_element& successor,
                       int weight){

    //! Number of nodes in the graph
    unsigned int num_nodes = graph.getNumber_nodes();

    //! check if the node is generated but not expanded
    if(frontierContainNode(successor.second)){

      //! check if new path is cheaper
      if((predecussor.first + weight) < successor.first){

          //!create a path from start to successor, and
          //!check if the path contains some node twice
          Path(successor.second);
          if(path.size() >= (num_nodes - 1)) return;

          //! store edge (predecessor - successor) into
          //! the parents list for backtracking process
          parents.push_back({predecussor.second, successor.second});

          //! update the f-value of the successor
          successor.first = predecussor.first + weight;
      }
    }

    //! check if successor has been visited
    else if(closedListContainNode(successor.second)){

        //! check if the f-value is less successor's f-value
        if((predecussor.first + weight) < successor.first){

            //!create a path from start to successor, and
            //!check if the path contains some node twice
            Path(successor.second);
            if(path.size() >= (num_nodes - 1)) return;

            //! store edge (predecessor - successor) into
            //! the parents list for backtracking process
            parents.push_back({predecussor.second, successor.second});

            //! initialize the f-value of the successor
            successor.first = predecussor.first + weight;

            //! then, push it into the frontiers
            frontier.push_back(successor);

            //! and, remove it from closed list
            removeNodeFromcloseList(successor.second);

         }
    }
    else{
        //! store edge (predecessor - successor) into
        //! the parents list for backtracking process
        parents.push_back({predecussor.second, successor.second});

        //! initialize the f-value of the successor
        successor.first = predecussor.first + weight;

        //! then, push it into the frontier
        frontier.push_back(successor);
        }

}


//! build a path using backtracking
void BellmanFord::Path(Node& goal){

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

//! remove a node from closed list
void BellmanFord::removeNodeFromcloseList(Node& node){
    //! lookup the node to get its index, if it exist,
    auto it = closed_list.find(node);
    if (it != closed_list.end())
        closed_list.erase(it);
}


} /* end of the name space */

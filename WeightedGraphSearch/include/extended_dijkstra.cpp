/*
 * Extended Dijkstra.cpp file: source file represents
 * the implementation of Extention of Dijkstra Algorithm ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "extended_dijkstra.hpp"

namespace WeightedGraphSearch {

//! Extended Dijkstra process to find a path from start to goal node
std::deque<Node> ExtendedDijkstra::findPath(Node& start, Node& goal){

    //! check if the start and target
    //! are exist in the graph
    if(!graph.containsNode(start) ||
       !graph.containsNode(goal))
            return path;

    //! clean all lists used for Dijkstra
    clean();

    //! push start node into the frontier
    frontier.push(std::make_pair(0,start));

    while (!frontier.empty()) {

           //! pop the top node from frontier priority queue
           PQ_element frontierTopNode = frontier.top();
           frontier.pop();

           //! push this node into visited node set
           closed_list.insert(frontierTopNode.second);

           //! check if the last node pushed in the closed
           //! list is the goal, then constract a path
           if(frontierTopNode.second == goal){
               Path(goal);
               return path;
           }

           //! Otherwise, get the outgoing edges of the frontier node
           std::vector<Edge> outgoingEdges =
                   graph.getOutgoingEdges(frontierTopNode.second);

           //! for each succesor, update the frontier, closed list,
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




//! Updating frontier, close list, and parents
void ExtendedDijkstra::improve(PQ_element& predecussor, PQ_element& successor,
                       int weight){

    bool successorNode_exist_in_frontier = false;
    //! scope to copy the frontier for search for a
    //! successor in the frontiers, and then destroy copy
    {
        std::priority_queue<PQ_element,
                  std::vector<PQ_element>,
                  std::greater<PQ_element>> frontier_(frontier);

        successorNode_exist_in_frontier =
                frontierContainNode(frontier_, successor.second);
    }

  if(successorNode_exist_in_frontier){
      //! check if the f-value is less successor's f-value
      if((predecussor.first + weight) < successor.first){
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

                //! store edge (predecessor - successor) into
                //! the parents list for backtracking process
                parents.push_back({predecussor.second, successor.second});

                //! initialize the f-value of the successor
                successor.first = predecussor.first + weight;

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

      //! initialize the f-value of the successor
      successor.first = predecussor.first + weight;

      //! then, push it into the frontiers
      frontier.push(successor);
  }

}


//! remove a node from closed list
void ExtendedDijkstra::removeNodeFromcloseList(Node& node){
    //! lookup the node to get its index, if it exist,
    auto it = closed_list.find(node);
    if (it != closed_list.end())
        closed_list.erase(it);
}

} /* end of the name space */

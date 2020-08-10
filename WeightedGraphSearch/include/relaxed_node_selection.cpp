/*
 * Relaxed Node Selection.cpp file: source file represents
 * the implementation of Relaxed Node Selection Algorithm ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "relaxed_node_selection.hpp"

namespace WeightedGraphSearch {


//! clean frontier, closed list, parents, and path
void RelaxedNodeSelection::clean(){
    Dijkstra::clean();
    if(!bestPath.empty()) bestPath.clear();
}


//! Extended Dijkstra process to find a path from start to goal node
std::deque<Node> RelaxedNodeSelection::findPath(Node& start, Node& goal){

    //! check if the start and target
    //! are exist in the graph
    if(!graph.containsNode(start) ||
       !graph.containsNode(goal))
            return bestPath;

    //! clean all lists used for RelaxedNodeSelection
    clean();

    //! push start node into the frontier with heuristic
    frontier.push(std::make_pair(h_value,start));

    //! the best path length (U) starts with infinite
    int path_length_U = INFINITE_NUM;

    while (!frontier.empty()) {

           //! pop the top node from frontier priority queue
           PQ_element frontierTopNode = frontier.top();
           frontier.pop();

           //! push this node into visited node set
           closed_list.insert(frontierTopNode.second);

           //! Prune expansion if costs are too high
           if(frontierTopNode.first > path_length_U)
               continue;


           //! improve solution established and update
           //! solution path
           if((frontierTopNode.second == goal)&&
              (frontierTopNode.first < path_length_U)){

               //! create a path and save it as best path
               //! and save the length as best as well
               Path(goal);
               bestPath = path;
               path_length_U = frontierTopNode.first;

           }
           else
           {

               //! Otherwise, expand and generate successor nodes
               std::vector<Edge> outgoingEdges =
                       graph.getOutgoingEdges(frontierTopNode.second);

               //! for each succesor, update the frontiers, closed list,
               //! and parents for next iteration
               for(auto& outgoingEdge : outgoingEdges){

                   //! set the successor f_value as heuristic
                   PQ_element successor = std::make_pair(h_value,
                                          outgoingEdge.getSuccessor());
                   //! update solution path
                   improve(frontierTopNode, successor,
                                             outgoingEdge.getWeight());
               }
           }


    }

    return bestPath;
}


} /* end of the name space */

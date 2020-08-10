/*
 * Edge.cpp file: source file implements the edge class ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#include "depthfirstsearch.hpp"

namespace UnweightedGraphSearch {


//! clean frontier, closed_list, parents, and path
void DepthFirstSearch::clean(){
    if(!frontier.empty()) frontier.clear();
    if(!closed_list.empty()) closed_list.clear();
    if(!parents.empty()) parents.clear();
}

//! frontier node duplication detection
bool DepthFirstSearch::frontierContainNode(Node& node) const{
    if(std::find(frontier.begin(), frontier.end(), node) == frontier.end())
        return false;
    else
        return true;
}


//! closed_list node duplication detection
bool DepthFirstSearch::closeListContainNode(Node& node) const{
    if(closed_list.find(node) == closed_list.end())
        return false;
    else
        return true;
}


//! DFS process to find a path from
//! start to goal node
std::deque<Node> DepthFirstSearch::findPath(Node& start, Node& goal){

    //! check if the start and target
    //! are exist in the graph
    if(!graph.containsNode(start) ||
       !graph.containsNode(goal))
            return path;

    //! clean all lists used for BFS
    clean();

    //! push start node into the frontiers
    frontier.push_back(start);

    while (!frontier.empty()) {

           //! pop the front node from frontier stack as
           //! FILO technique
           Node frontierNode = frontier.back();
           frontier.pop_back();

           //! push the node into visited set (closed list)
           closed_list.insert(frontierNode);


           //! check if the last node pushed in the close
           //! list is the goal, then constract a path
           if(frontierNode == goal){
               Path(goal);
               return path;
           }

           //! get the successors of the frontier node
           std::vector<Node> successors = graph.getSuccessors(frontierNode);

           //! for each succesor, update the frontiers, closed_list,
           //! and parents for next iteration
           for(auto successor : successors)
               improve(frontierNode, successor);
    }

    return path;
}


//! Updating frontier, closed_list, and parents
void DepthFirstSearch::improve(Node& predecussor, Node& successor){

    //! check if successor has not been visited
    //! and, it's not in the frontiers
    if((!closeListContainNode(successor))&&
      (!frontierContainNode(successor))){

        //! then, push it in front of the frontiers
         frontier.push_back(successor);

         //! store (predecessor-successor) into
         //! parents list for backtracking process
         parents.push_back({predecussor, successor});
    }

}


//! build a path using backtracking
void DepthFirstSearch::Path(Node& goal){

    //! clean the deque for building a new path
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


} /* end of the name space */

/*
 * breadthfirstsearch.hpp file: Header file represents BFS process ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include <deque>
#include <unordered_set>

#include "graph.hpp"
#include "hashfunction.hpp"

namespace UnweightedGraphSearch {

class BreadthFirstSearch
{
public:
    //! Graph Constructor
    BreadthFirstSearch(Graph graph_): graph(graph_){}

    //! Graph Destructor
    virtual ~BreadthFirstSearch(){}

    //! BFS process to find a path
    //! from start node to target node
    std::deque<Node> findPath(Node&, Node&);

private:

    //! Private Member functions defination ----------

    //! private member functions help findPath to find
    //! a path from start to goal node, as:

    //! clean frontier, closed, parents, and path
    void clean();

    //! frontiers node duplication detection
    bool frontierContainNode(Node&) const;

    //! closed_list's node duplication detection
    bool closeListContainNode(Node&) const;

    //! Updating frontier, closed_list, and parents
    void improve(Node&, Node&);

    //! build a path using backtracking
    void Path(Node&);


    //! Data member defination --------------------

    //! Directed Graph
    Graph graph;

    //! frontier is a queue structure (FIFO)
    std::deque<Node> frontier;

    //! closed_list (a set of visited nodes)
    std::unordered_set<Node, myNodeHashFunction> closed_list;

    //! parent is set of predecessor & successor used
    //! to backtrack a path
    std::vector<Edge> parents;

    //! path generated by BFS process
    std::deque<Node> path;

};

} /* end of the name space */

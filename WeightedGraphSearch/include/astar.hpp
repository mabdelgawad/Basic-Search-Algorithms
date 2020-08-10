/*
 * astar.hpp file: Header file represents
 * the A-Star Algorithm Class ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include <deque>
#include <queue>
#include <unordered_set>

#include "graph.hpp"
#include "hashfunction.hpp"

//! Floyd-Warshall is used to generate matrix of
//! shortest distances for all pairs of nodes to
//! be the exact heuristic (h-values) for all nodes
#include "floyd_warshall.hpp"


namespace WeightedGraphSearch {

//! define a pair of (f-value , Node) as
//! prioirty queue element
typedef std::pair<int, Node> PQ_element;

//! infinite number as 9999999
#define INFINITE_NUM 9999999

class AStar
{
public:
    //! Constructor
    AStar(Graph graph_): graph(graph_){}

    //! Destructor
    virtual ~AStar(){}

    //! A* process to find a path
    //! from start node to target node
    std::deque<Node> findPath(Node&, Node&);

private:

    //! Member functions -----------------------------------

    //! private member functions help findPath to find
    //! a path from start to goal node, as:

    //! clean frontier, close list, parents, and path
    void clean();

    //! close list node duplication detection
    bool frontierContainNode(std::priority_queue<PQ_element,
                              std::vector<PQ_element>,
                              std::greater<PQ_element>>&,
                              Node&) const;


    //! closed list node duplication detection
    bool closedListContainNode(Node&) const;

    //! Updating frontiers, close list, and parents
    void improve(PQ_element&, PQ_element&, int);

    //! remove a node from closed list
    void removeNodeFromcloseList(Node&);

    //! build a path using backtracking
    void Path(Node&);

    //! use floyd warshall to get the h-value
    int getHeuristic(Node&, Node&);

    //! Data member defination ----------------------------

    //! Directed Graph
    Graph graph;

    //! frontiers is a min heap priority queue
    std::priority_queue<PQ_element,
                    std::vector<PQ_element>,
                    std::greater<PQ_element>> frontier;

    //! closed_list (a set of visited nodes)
    std::unordered_set<Node, myNodeHashFunction> closed_list;

    //! Exact heuristic h-value for all nodes
    std::vector<std::vector<int>> h_values;

    //! parent is set of predecessor & successor used
    //! for backtracking a path
    std::vector<Edge> parents;

    //! path generated by Dijhstra's process
    std::deque<Node> path;
};

} /* end of the name space */
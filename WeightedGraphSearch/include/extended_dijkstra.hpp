/*
 * Extended Dijkstra.hpp file: Header file represents
 * the Extention of Dijkstra Algorithm Class ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include "dijkstra.hpp"


namespace WeightedGraphSearch {

//! The Negatively Weighted Graph (Extended Dijkstra).
//! The extended version of Dijkstra's algorithm inherits
//! data members & methods from Dijkstra class and
//! overrides the findpath() and improve() methods.
//! It can handle negative weighted graph but it does not
//! imply to negatively weighted cycles exist.
//!
//! The idea is that the algorithm reopens not only the
//! frontier but also the closed ones.

class ExtendedDijkstra : public Dijkstra
{
public:
    //! Graph Constructor
    ExtendedDijkstra(Graph graph_): Dijkstra(graph_){}

    //! Graph Destructor
    virtual ~ExtendedDijkstra(){}

    //! Extended Dijkstra process to find a path
    //! from start node to target node
    std::deque<Node> findPath(Node&, Node&);

protected:

    //! Relaxing the f-value of successor, and then
    //! updating frontiers, closed list, and parents
    void improve(PQ_element&, PQ_element&, int);

    //! remove a node from close list
    void removeNodeFromcloseList(Node& node);
};

} /* end of the name space */

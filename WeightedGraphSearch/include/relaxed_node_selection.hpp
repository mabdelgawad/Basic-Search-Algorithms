/*
 * Relaxed Node Selection.hpp file: Header file represents
 * the Relaxed Node Selection Algorithm Class ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include "extended_dijkstra.hpp"


namespace WeightedGraphSearch {

//! Relaxed Node Selection Algorithm continues until
//! the frontiers is empty, and the global best solution
//! is found. It starts with heuristic and relaxing the
//! successors to select the best node. The best path is
//! the less length among the soltions.

class RelaxedNodeSelection : public ExtendedDijkstra
{
public:

    //! Constructor
    RelaxedNodeSelection(Graph graph_, int h_value_ = 0):
        ExtendedDijkstra(graph_), h_value(h_value_) {}

    //! Destructor
    virtual ~RelaxedNodeSelection(){}

    //! Extended Dijkstra process to find a path
    //! from start node to target node
    std::deque<Node> findPath(Node&, Node&);

    //! get & set heuristic value
    int getHeuristic() const {return h_value;}
    void setHeuristic(int h_value_){ h_value = h_value_;}

    void clean();

private:

    //! the best path
    std::deque<Node> bestPath;

    //! heuristic (h-value)
    int h_value = 0;

};

} /* end of the name space */

/*
 * floyd_warshalls.hpp file: Header file represents
 * the Floyd-Warshall Algorithm Class ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include "graph.hpp"


namespace WeightedGraphSearch {

//! infinite number as 9999999
#define INFINITE_NUM 9999999

class FloydWarshall
{
public:

    //! Constructor
    FloydWarshall(Graph graph_):
        graph(graph_){ initDMatrix(); }


    //! Destructor
    virtual ~FloydWarshall(){}

    //! compute the shortest distances between all pairs of nodes
    std::vector<std::vector<int>> allPairsShortestPaths() const;

private:
    //! Private Member functions -------------------------

    //! initialize distance matrix to be n-by-n,
    //! and fill it out with edges' costs (distances)
    void initDMatrix();

    //! Data member defination ----------------------------

    //! Directed Graph
    Graph graph;

    //! n-by-n adjancey matrix
    std::vector<std::vector<int>> DMatrix;

};

} /* end of the name space */

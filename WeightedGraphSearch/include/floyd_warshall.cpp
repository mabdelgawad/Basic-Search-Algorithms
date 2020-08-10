/*
 * floyd_warshalls.cpp file: source file represents
 * the implementation of Floyd Warshall Algorithm ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#include "floyd_warshall.hpp"

namespace WeightedGraphSearch {

//! compute the shortest distances between all pairs of nodes
std::vector<std::vector<int>> FloydWarshall::allPairsShortestPaths() const{

    //! (num_nodes is number of nodes)
    unsigned int num_nodes = graph.getNumber_nodes();

    //! sequence of distances matrices
    std::vector<std::vector<std::vector<int>>> DMatrices;

    //! resize the DMatricrs to n-by-n-by-n
    DMatrices.resize(num_nodes);
    for(auto& matrix: DMatrices){

        //! resize the rows
        matrix.resize(num_nodes);

        //! resize the columns
        for(auto& it: matrix)
            it.resize(num_nodes);
    }

    //! set D(0) as initial DMatrix
    DMatrices.at(0).assign(DMatrix.begin(), DMatrix.end());

    //! loop over intermediate node
    for(unsigned int k = 1 ; k <num_nodes; k++){

        //! loop over start node
        for(unsigned int i = 0 ; i <num_nodes; i++){

            //! loop over end node
            for(unsigned int j = 0 ; j <num_nodes; j++){

                //! Floyd Warshall optimality (shortest distance)
                DMatrices[k][i][j] = std::min(DMatrices[k-1][i][j],
                                              (DMatrices[k-1][i][k]+
                                               DMatrices[k-1][k][j]));
            }
        }
    }

    //! return last matrix, which
    //! contains shortest path distances
    return DMatrices.at(num_nodes - 1);
}


//! initialize distance matrix to be n-by-n,
//! and fill it out with edges' costs (distances)
void FloydWarshall::initDMatrix(){

    //! resize the distances matrix to be n-by-n
    //! where n is the number of nodes
    unsigned int num_nodes = graph.getNumber_nodes();

    DMatrix.resize(num_nodes);
    for(auto& it: DMatrix)
        it.resize(num_nodes, INFINITE_NUM);


    //! fill the matrix out with costs
    for(unsigned int i = 0 ; i < num_nodes ; i++){
        Node preducessor = graph.getNode_at(i);

        for(unsigned int j = 0; j < num_nodes ; j++){

            Node successor = graph.getNode_at(j);
            DMatrix[i][j] =
                    graph.getCost(Edge(preducessor, successor));
        }
    }
}

} /* end of the name space */

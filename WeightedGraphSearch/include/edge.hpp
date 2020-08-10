/*
 * Edge.hpp file: Header file represents an edge in a graph class ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include "node.hpp"

namespace WeightedGraphSearch {

//! Edge class represents edge connects two nodes with int weight
class Edge
{
public:
    //! Edge Constructor assigns predecessor, successor, and
    //! weight into an initiated edge. The weight default is zero
    Edge(){}
    Edge(Node predecessor_, Node successor_, int weight_= 0):
        predecessor(predecessor_), successor(successor_),
        weight(weight_){}

    //! Edge Destructor
    virtual ~Edge(){}


    //! Getters functions
    Node getPredecessor() const;
    Node getSuccessor() const;
    int getWeight() const;

    //! Calculate the hash code of this edge
    //! (predecussor node hash code + successor node hash code + weight)
    int getHashCode() const;

    //! Setters functions
    void setPredecessor(const Node&);
    void setSuccessor(const Node&);
    void setWeight(const int);

    //! checks if this edge equals to an another edge
    //! includes the weight
    bool equals(const Edge& edge) const;

    //! == operator checks if this edge equals to an another edge
    bool operator==(const Edge&) const;

    //! != operator checks if this edge doen't equal to an another edge
    bool operator!=(const Edge&) const;

    //! < operator checks if this edge less than the another edge
    bool operator<(const Edge&) const;

    //! > operator checks if this edge greater than the another edge
    bool operator>(const Edge&) const;

    //! = operator assigns an edge into this edge
    void operator=(const Edge&);

private:

    //! Predecessor and Successor Nodes
    Node predecessor, successor;

    //! Edge weight is a tamplate
    int weight = 0;

};

} /* end of the name space */


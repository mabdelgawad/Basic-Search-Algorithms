/*
 * Edge.hpp file: Header file represents an edge in a graph ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include "node.hpp"

namespace UnweightedGraphSearch {

//! Edge class represents edge connects two nodes
class Edge
{
public:
    //! Edge Constructor assigns predecessor and successor into
    //! into an initiated edge.
    Edge(){}
    Edge(Node predecessor_, Node successor_):
        predecessor(predecessor_), successor(successor_){}

    //! Edge Destructor
    virtual ~Edge(){}


    //! Getters functions
    Node getPredecessor() const;
    Node getSuccessor() const;

    //! Calculate the hash code of this edge
    //! (predecussor node hash code + successor node hash code)
    int getHashCode() const;

    //! Setters functions
    void setPredecessor(const Node&);
    void setSuccessor(const Node&);

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

};

} /* end of the name space */


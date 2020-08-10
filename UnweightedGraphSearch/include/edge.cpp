/*
 * Edge.cpp file: source file implements the edge class ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "edge.hpp"

namespace UnweightedGraphSearch {

//! Getters functions
Node Edge::getPredecessor() const {
    return predecessor;
}

Node Edge::getSuccessor() const {
    return successor;
}


//! Calculate the hash code of this edge
//! (source node hash code + destination node hash code)
int Edge::getHashCode() const {
    return predecessor.getHashCode() + successor.getHashCode() ;
}

//! Setters functions
void Edge::setPredecessor(const Node& predecessor_) {
    predecessor = predecessor_;
}

void Edge::setSuccessor(const Node& successor_) {
    successor = successor_;
}


//! == operator checks if this edge equals to an another edge
bool Edge::operator==(const Edge& edge) const {
    return (predecessor == edge.getPredecessor() &&
            successor == edge.getSuccessor());
}


//! != operator checks if this edge doen't equal to an another edge
bool Edge::operator!=(const Edge& edge) const {
    return (predecessor != edge.getPredecessor() &&
            successor != edge.getSuccessor());
}


//! < operator checks if this edge less than the another edge
bool Edge::operator<(const Edge& edge) const {
    return (predecessor < edge.getPredecessor());
}


//! > operator checks if this edge greater than the another edge
bool Edge::operator>(const Edge& edge) const {
    return (predecessor > edge.getPredecessor());
}

//! = operator assigns an edge into this edge
void Edge::operator=(const Edge& edge) {
    predecessor = edge.getPredecessor();
    successor = edge.getSuccessor();
}


} /* end of the name space */

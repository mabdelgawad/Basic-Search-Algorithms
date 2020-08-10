/*
 * Edge.cpp file: source file implements the edge class ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "edge.hpp"

namespace WeightedGraphSearch {

//! Getters functions
Node Edge::getPredecessor() const {
    return predecessor;
}

Node Edge::getSuccessor() const {
    return successor;
}

int Edge::getWeight() const {
    return weight;
}


//! Calculate the hash code of this edge
//! (source node hash code + destination node hash code + weight)
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

void Edge::setWeight(const int weight_) {
    weight = weight_;
}


//! checks if this edge equals to an another edge
//! includes the weight
bool Edge::equals(const Edge& edge) const {
    return (predecessor == edge.getPredecessor() &&
            successor == edge.getSuccessor() &&
            weight == edge.getWeight());
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
    return (predecessor == edge.getPredecessor() &&
            weight < edge.getWeight());
}


//! > operator checks if this edge greater than the another edge
bool Edge::operator>(const Edge& edge) const {
    return (predecessor == edge.getPredecessor() &&
            weight > edge.getWeight());
}

//! = operator assigns an edge into this edge
void Edge::operator=(const Edge& edge) {
    predecessor = edge.getPredecessor();
    successor = edge.getSuccessor();
    weight = edge.getWeight();
}


} /* end of the name space */

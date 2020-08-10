/*
 * Node.cpp file: source file implements the node class ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */


#include "node.hpp"

namespace UnweightedGraphSearch {

//! Getter function
std::string Node::getNodeID() const {
    return nodeID;
}

//! Calculate the hash code of this node (ASCII * length)
int Node::getHashCode() const {
    int intValueOfString= 0;
        for(unsigned int i = 0; i < nodeID.size() ; i++)
            intValueOfString+= (int)(nodeID.at(i));
     return intValueOfString * nodeID.size();
}

//! Setter function
void Node::setNodeID(const std::string nodeID_){
    nodeID = nodeID_;
}

//! == operator checks if this node equals to an another node
bool Node::operator==(const Node& node) const {
    return getHashCode() == node.getHashCode();
}

//! != operator checks if this node doesn't equal to an another node
bool Node::operator!=(const Node& node) const {
    return getHashCode() != node.getHashCode();
}

//! < operator check if this node is less than an another node.
bool Node::operator<(const Node& node) const {
    return getHashCode() < node.getHashCode();
}

//! > operator check if this node is greater than an another node.
bool Node::operator>(const Node& node) const {
    return getHashCode() > node.getHashCode();
}

//! = operator assigns a node into this node
void Node::operator=(const Node& node) {
    nodeID = node.getNodeID();
}

} /* end of the name space */

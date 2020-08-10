/*
 * Node.hpp file: Header file represents a node in a graph ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

#include <string>

namespace UnweightedGraphSearch {

//! Node class represents a node and its string element
class Node
{
public:
    //! Node Constructors
    Node(){}
    Node(std::string nodeID_): nodeID(nodeID_){}

    //! Node Destructor
    virtual ~Node(){}

    //! Getter function
    std::string getNodeID() const ;

    //! Calculate the hash code of this node (ASCII + length)
    int getHashCode() const;

    //! Setter function
    void setNodeID(const std::string);

    //! == operator checks if this node equals to an another node
    bool operator==(const Node&) const;

    //! != operator checks if this node doesn't equal to an another node
    bool operator!=(const Node&) const;

    //! < operator check if this node is less than an another node.
    bool operator<(const Node&) const;

    //! > operator check if this node is greater than an another node.
    bool operator>(const Node&) const;

    //! = operator assigns a node into this node
    void operator=(const Node&);

private:

    //! a node's identification
    std::string nodeID;

    //! Plug the data here
    //! as veriable to struct
};

} /* end of the name space */


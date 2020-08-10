/*
 * graph.hpp file: Header file represents a graph ***
 * Created   : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#pragma once

//! define the graph's cpacity
//! the maxium number of nodes, and
//! the maxium number of edges
#define MAX_NODES 999999
#define MAX_EDGES 999999

#include <iostream>
#include <vector>
#include <algorithm>

#include "node.hpp"
#include "edge.hpp"

namespace UnweightedGraphSearch {

//! class represents a  unweighted Direct Graph
class Graph
{
public:
    //! Graph Constructor
    Graph(){}

    //! Graph Destructor
    virtual ~Graph(){}

    //! get all nodes
    std::vector<Node> getNodes() const;

    //! get all edges
    std::vector<std::vector<Edge>> getEdges() const;

    //! node duplication detection
    bool containsNode(const Node&) const;

    //! edge duplication detection
    bool containsEdge(const Edge&) const;

    //! lookup the node to get its index
    int getIndexOf(const Node&) const;

    //! lookup the index to get its node
    Node getNode_at(unsigned int) const;

    //! get the total number of nodes
    unsigned int getNumber_nodes() const;

    //! get the total number of edges
    unsigned int getNumber_edges() const;

    //! get outgoing edges from a node
    std::vector<Edge> getOutgoingEdges(const Node&) const;

    //! get successors of a parent node
    std::vector<Node> getSuccessors(const Node&) const;

    //! Add a new node with an empty outgoing edges vector
    bool add_node(const Node&);

    //! Add a new edge
    bool add_edge(const Edge&);

    //! remove a node and its outgoing edges
    bool removeNode(const Node&);

    //! remove an edge from the graph
    bool removeEdge(const Edge&);

    //! display all nodes in the graph
    void display_nodes() const;

    //! display all edges in the graph
    void display_edges() const;

    //! display the entire graph (nodes and edges)
    void display_graph() const;

private:

    //!  An unweighted directed graph represented as adjacancy list
    std::vector<Node> nodes;
    std::vector<std::vector<Edge>> edges;
};

} /* end of the name space */


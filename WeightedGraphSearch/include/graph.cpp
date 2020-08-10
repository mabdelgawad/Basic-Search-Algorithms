/*
 * graph.cpp file: Header file implements a graph ***
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#include "graph.hpp"

namespace WeightedGraphSearch {

//! get all nodes
std::vector<Node> Graph::getNodes() const{
    return nodes;
}


//! get all edges
std::vector<std::vector<Edge>> Graph::getEdges() const{
    return edges;
}


//! node duplication detection
bool Graph::containsNode(const Node& node) const {
    if(std::find(nodes.begin(), nodes.end(), node) == (nodes.end()))
            return false;
       else
            return true;
}


//! edge duplication detection
bool Graph::containsEdge(const Edge& edge) const {
    for(auto edges_ : edges)
    if(std::find(edges_.begin(), edges_.end(), edge) != edges_.end())
        return true;

    return false;
}


//! get edge cost (distance), and return
//! INFINIT if the edge does not exist
int Graph::getCost(const Edge& edge) const {

    for(auto edges_ : edges) {

        auto it = std::find(edges_.begin(), edges_.end(), edge);
        if(it != edges_.end())
            return (*it).getWeight();
    }

    return INFINITE_NUM;
}


//! get an index of a node
int Graph::getIndexOf(const Node& node) const{
    //! lookup the node to get its index, if it exist,
    //! get the edges at this index (which are the outgoing edges)
    int node_index = -1;
    auto it = std::find(nodes.begin(), nodes.end(), node);
    if (it != nodes.end())
        node_index = std::distance(nodes.begin(), it);

    return node_index;
}



//! lookup an index to get a node, and return
//! empty node if the index out of range
Node Graph::getNode_at(unsigned int index) const {

    Node emptyNode;
    if(index < nodes.size())
        return nodes.at(index);
    else
        return emptyNode;
}



//! get the total number of nodes
unsigned int Graph::getNumber_nodes() const{
    return nodes.size();
}


//! get the total number of edges
unsigned int Graph::getNumber_edges() const{
    unsigned int counter = 0;
        for (auto& element : edges)
                counter += element.size();
    return counter;
}


//! get outgoing edges from a node
std::vector<Edge> Graph::getOutgoingEdges(const Node& node) const{

    std::vector<Edge> edges_;
    int index = getIndexOf(node);
    if (index > -1)
        edges_ = edges.at(index);

    return edges_;
}


//! get successors of a parent node
std::vector<Node> Graph::getSuccessors(const Node& node) const{

    std::vector<Node> successors;
    //! if the node exists, get the outgoing edges
    //! then, store the successor of every edge
    if(containsNode(node)){
        std::vector<Edge> edges_ = getOutgoingEdges(node);
        for(auto edge : edges_)
        if (edge.getSuccessor() != node)
            successors.push_back(edge.getSuccessor());
    }

    return successors;
}


//! Add a new node with an empty outgoing edges vector
bool Graph::add_node(const Node& newNode){

    //! check the graph's capacity
    if((getNumber_nodes() + 1) >= MAX_NODES){
        std::cout<<"The graph reaches the maxium size"<<std::endl;
        return false;
    }

    //! check if the new node exist in the graph
    if (containsNode(newNode)) return false;
    else{
    //! the new node will be added safely
    nodes.push_back(newNode);
    edges.push_back({});
    return true;
    }
}


//! Add a new edge
bool Graph::add_edge(const Edge& newEdge){

    //! check the graph's capacity
    if((getNumber_edges() + 1) >= MAX_EDGES){
        std::cout<<"The graph reaches the maxium size"<<std::endl;
        return false;
    }

    //! check if the edge already exists, or
    //! the source node doesn't exist in the graph
    if (containsEdge(newEdge) || (!containsNode(newEdge.getPredecessor())))
        return false;
    else{
        //! find source node in the graph
         int node_index = getIndexOf(newEdge.getPredecessor());
         edges.at(node_index).push_back(newEdge);
        return true;
        }
}


//! remove a node and its outgoing and incoming edges
bool Graph::removeNode(const Node& node){

    int node_index = getIndexOf(node);
    if (node_index == -1)
        return false;
    else{
        nodes.erase(nodes.begin() + node_index);
        edges.erase(edges.begin() + node_index);
        //! Also, remove every incoming edge
        int outgoingEdges_index = 0;
        for(auto& edges_ : edges){
            int edge_index = 0;
            for(auto& edge_ : edges_){
                if(edge_.getSuccessor() == node){
                    edges.at(outgoingEdges_index).erase(
                             edges.at(outgoingEdges_index).begin() +
                             edge_index);
                }
               edge_index++;
              }

            outgoingEdges_index++;
         }

        return true;
    }
}


//! remove an edge from the graph
bool Graph::removeEdge(const Edge& edge){

    //! check if the source node exists, and get its index
    int node_index = getIndexOf(edge.getPredecessor());
    if (node_index == -1)
        return false;

    //! find edge index if it exists and erase it
    std::vector<Edge> edges_ = edges.at(node_index);
    int edge_index = -1;
    for(auto edge_ : edges_){
            edge_index++;
            if(edge_  == edge){
                edges.at(node_index).erase(
                         edges.at(node_index).begin() +
                         edge_index);
                return true;
            }
        }

    return false;
}


//! display all nodes graph
void Graph::display_nodes() const{

    std::cout<<"Nodes are: ";

    for(auto node : nodes)
        std::cout<<" ("<<node.getNodeID()<<")";

    std::cout<<std::endl;
}


//! display all edges
void Graph::display_edges() const{

    std::cout<<"Edges are:"<<std::endl;

    for(auto edges_ : edges)
        for(auto edge : edges_){
            std::cout<<"("<<edge.getPredecessor().getNodeID() <<"-"<<
            edge.getSuccessor().getNodeID()<<":"<<
            edge.getWeight()<<")"<<std::endl;
        }
}


//! display the entire graph
void Graph::display_graph() const{
    display_nodes();
    display_edges();
    std::cout<<std::endl;
}


} /* end of the name space */


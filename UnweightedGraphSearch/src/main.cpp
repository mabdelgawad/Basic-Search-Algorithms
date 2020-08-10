#include <iostream>

#include "include/graph.hpp"
#include "include/breadthfirstsearch.hpp"
#include "include/depthfirstsearch.hpp"

using namespace UnweightedGraphSearch;

int main()
{

    /*********** Graph Representation **********************/
    //! create an empty graph
    Graph graph;

    //! create all nodes that represent the graph
    Node A("A"), B("B"), C("C"), D("D"), E("E"), F("F"),
         Q("Q"), Z("Z");

    //! insert a node into the graph
    if(!graph.add_node(A))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(B))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(C))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(D))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(E))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(F))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(Q))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! insert a node into the graph
    if(!graph.add_node(Z))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //! add an edge into the graph
    Edge AB(A,B);
    if(!graph.add_edge(AB))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge AC(A,C);
    if(!graph.add_edge(AC))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;


    //! add an edge into the graph
    Edge AD(A,D);
    if(!graph.add_edge(AD))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge BE(B,E);
    if(!graph.add_edge(BE))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge BF(B,F);
    if(!graph.add_edge(BF))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge CD(C,D);
    if(!graph.add_edge(CD))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge DE(D,E);
    if(!graph.add_edge(DE))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge EQ(E,Q);
    if(!graph.add_edge(EQ))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge FZ(F,Z);
    if(!graph.add_edge(FZ))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;


    //! add an edge into the graph
    Edge QF(Q,F);
    if(!graph.add_edge(QF))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph (making cyclic graph)
    Edge ZB(Z,B);
    if(!graph.add_edge(ZB))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;


    /******* Graph Created *********************************/


    /******* Search on the Graph Created *******************/

    std::cout<<"The graph consists of "<<graph.getNumber_nodes()
        <<" Nodes and "<<graph.getNumber_edges()<<" Edges"<<std::endl;

    graph.display_nodes();
    graph.display_edges();

    auto successors = graph.getSuccessors(A);
    std::cout<<"Successors of ("<<A.getNodeID()<<") are : ";
    for(auto n : successors)
        std::cout<<" ("<<n.getNodeID() <<")";

    std::cout<<std::endl;

    auto outgoingEdges_ = graph.getOutgoingEdges(A);
    std::cout<<"Outgoing edges of ("<<A.getNodeID()<<") are : "<<std::endl;
    for(auto outgoinEdge_ : outgoingEdges_)
        std::cout<<"("<<outgoinEdge_.getPredecessor().getNodeID() <<"-"<<
        outgoinEdge_.getSuccessor().getNodeID()<<")"<<std::endl;

    {
    //! Test remove an edge from the graph
    Edge A_D(A,D);
    if(graph.removeEdge(A_D)){
        std::cout<<"Edge (A-D) was deleted"<<std::endl;
        std::cout<<"Now the # of Edges is:"<<graph.getNumber_edges()<<std::endl;
        std::cout<<"The Edges are:"<<std::endl;
        graph.display_edges();
    } else std::cout<<"Edge (A-D) doesn't exist in the graph."<<std::endl;
    }

    //! Test if a node exists in the graph
    Node W("A");
    if (graph.containsNode(W))
        std::cout <<"Yes, node ("<< W.getNodeID() <<") exists in the graph."<<std::endl;
    else std::cout<<"No, node ("<< W.getNodeID() <<") doesn't exist in the graph."<<std::endl;

    //! Test if an edge exists in the graph
    Edge DB(D,B);
    if (graph.containsEdge(DB))
        std::cout<<"Yes, edge ("<<DB.getPredecessor().getNodeID()<<"-"<<
                   DB.getSuccessor().getNodeID()<<") exists in the graph."<<std::endl;
    else std::cout<<"No, edge ("<<DB.getPredecessor().getNodeID()<<"-"<<
                    DB.getSuccessor().getNodeID()<<") doesn't exist  in the graph."<<std::endl;


    {
    //! test add an edge into the graph
    Edge A_D(A,D);
    if(graph.add_edge(A_D))
        std::cout<<"Edge ("<<A_D.getPredecessor().getNodeID()<<"-"<<
                   A_D.getSuccessor().getNodeID()<<") was successfully added"<<std::endl;
    else std::cout<<"Failed to add edge"<<std::endl;
    }

    //! test add another edge into the graph
    Edge EF(E,F);
    if(graph.add_edge(EF))
        std::cout<<"Edge ("<<EF.getPredecessor().getNodeID()<<"-"<<
                   EF.getSuccessor().getNodeID()<<") was successfully added"<<std::endl;
    else std::cout<<"Failed to add edge"<<std::endl;

    graph.display_graph();
    /*********************BFS Test ************************/
    {
        std::cout<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        std::cout<<"Test BFS Algorithm on Directed Graph: "<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;

    //! create BFS object and pass the graph to it
    BreadthFirstSearch BFS(graph);

    //! declare the start and goal node to find a path

    //! first test: find a path from C to B
    { // begin of the first test scope
    Node start("C"), goal("B");
    auto path_ = BFS.findPath(start, goal);

       if(!path_.empty()){
            std::cout<<"The BFS path from "<<start.getNodeID()<<" to "<<
                  goal.getNodeID()<<" is : ";
            for(auto node_in_path : path_)
                std::cout<<"("<<node_in_path.getNodeID()<<") ";
            std::cout<<std::endl;
        }
        else std::cout<<"There is no path from "<<start.getNodeID()<<
                   " to "<<goal.getNodeID()<<std::endl;

        } // end of the first test scope

      {// begin of the second test scope
      //! second test: find a path from A to Z
      Node start("A"), goal("Z");
      auto path_ = BFS.findPath(start, goal);

         if(!path_.empty()){
              std::cout<<"The path from "<<start.getNodeID()<<" to "<<
                    goal.getNodeID()<<" is : ";
              for(auto node_in_path : path_)
                  std::cout<<"("<<node_in_path.getNodeID()<<") ";
              std::cout<<std::endl;
          }
          else std::cout<<"There is no path from "<<start.getNodeID()<<
                     " to "<<goal.getNodeID()<<std::endl;
        } // end of the second test scope
    }
   /*******************************************************/


    /*********************DFS Test ************************/
    {
        std::cout<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;
        std::cout<<"Test DFS Algorithm on Directed Graph: "<<std::endl;
        std::cout<<"------------------------------------"<<std::endl;

    //! create DFS object and pass the graph to it
    DepthFirstSearch DFS(graph);

    //! declare the start and goal node to find a path

    //! first test: find a path from C to B
    { // begin of the first test scope
    Node start("C"), goal("B");
    auto path_ = DFS.findPath(start, goal);

       if(!path_.empty()){
            std::cout<<"The DFS path from "<<start.getNodeID()<<" to "<<
                  goal.getNodeID()<<" is : ";
            for(auto node_in_path : path_)
                std::cout<<"("<<node_in_path.getNodeID()<<") ";
            std::cout<<std::endl;
        }
        else std::cout<<"There is no path from "<<start.getNodeID()<<
                   " to "<<goal.getNodeID()<<std::endl;

        } // end of the first test scope

      {// begin of the second test scope
      //! second test: find a path from A to Z
      Node start("A"), goal("Z");
      auto path_ = DFS.findPath(start, goal);

         if(!path_.empty()){
              std::cout<<"The path from "<<start.getNodeID()<<" to "<<
                    goal.getNodeID()<<" is : ";
              for(auto node_in_path : path_)
                  std::cout<<"("<<node_in_path.getNodeID()<<") ";
              std::cout<<std::endl;
          }
          else std::cout<<"There is no path from "<<start.getNodeID()<<
                     " to "<<goal.getNodeID()<<std::endl;
        } // end of the second test scope
    }
   /*******************************************************/

    std::cout<<std::endl;
    return 0;
}

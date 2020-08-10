/*
 * main.cpp file: source file tests the node,
 * edge, and the graph classes. It also exrcises
 * all 6 algorithms: Dijkstra, Extend Dijkstra,
 * Bellman-Ford, Relaxed Node Selection,
 * Floyd-Warshall and A-Star.
 *
 * Project Start Date  : June 30, 2020
 * Author    : Mahmoud Abdelgawad
 *
 */

#include <iostream>

#include "include/graph.hpp"
#include "include/dijkstra.hpp"
#include "include/extended_dijkstra.hpp"
#include "include/relaxed_node_selection.hpp"
#include "include/bellman_ford.hpp"
#include "include/floyd_warshall.hpp"
#include "include/astar.hpp"

using namespace WeightedGraphSearch;

int main()
{

    /*********** Graph Representation **********************/
    //! create an empty graph
    Graph graph;

    //--------------------- add nodes into the grapg -----------------

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
    if(!graph.add_node(Z))
        std::cout<<"Failed to add the node into the graph"<<std::endl;

    //---------------------------------------------------------------


    //--------------------- add edges into the grapg -----------------
    //! add an edge into the graph
    Edge AB(A,B,3);
    if(!graph.add_edge(AB))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge AC(A,C,5);
    if(!graph.add_edge(AC))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;


    //! add an edge into the graph
    Edge AD(A,D,3);
    if(!graph.add_edge(AD))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge BF(B,F,4);
    if(!graph.add_edge(BF))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge CD(C,D,3);
    if(!graph.add_edge(CD))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge DB(D,B,10);
    if(!graph.add_edge(DB))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge DE(D,E,5);
    if(!graph.add_edge(DE))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge EF(E,F,1);
    if(!graph.add_edge(EF))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph
    Edge FZ(F,Z,1);
    if(!graph.add_edge(FZ))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //! add an edge into the graph (making cyclic graph)
    Edge ZB(Z,B,1);
    if(!graph.add_edge(ZB))
        std::cout<<"Failed to add the edge into the graph"<<std::endl;

    //---------------------------------------------------------------


    /******* Graph Created *********************************/


    /******* Tests on the Graph functionality **************/

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

    //---------------------------------------------------------------
    {
    //! Test remove an edge from the graph
    Edge A_D(A,D);
    if(graph.removeEdge(A_D)){
        std::cout<<"Edge (A-D) was successfully deleted"<<std::endl;
        std::cout<<"Now the # of Edges is:"<<graph.getNumber_edges()<<std::endl;
        graph.display_edges();
    } else std::cout<<"Edge (A-D) doesn't exist in the graph."<<std::endl;
    }
    //---------------------------------------------------------------

    //---------------------------------------------------------------
    {
    //! Test if a node exists in the graph
    Node W("A");
    if (graph.containsNode(W))
        std::cout <<"Yes, node ("<< W.getNodeID() <<") exists in the graph."<<std::endl;
    else std::cout<<"No, node ("<< W.getNodeID() <<") doesn't exist in the graph."<<std::endl;
    }
    //---------------------------------------------------------------

    //---------------------------------------------------------------
    {
    //! Test if an edge exists in the graph
    Edge DB(D,B);
    if (graph.containsEdge(DB))
        std::cout<<"Yes, edge ("<<DB.getPredecessor().getNodeID()<<"-"<<
                   DB.getSuccessor().getNodeID()<<") exists in the graph."<<std::endl;
    else std::cout<<"No, edge ("<<DB.getPredecessor().getNodeID()<<"-"<<
                    DB.getSuccessor().getNodeID()<<") doesn't exist  in the graph."<<std::endl;
    }
    //---------------------------------------------------------------

    //---------------------------------------------------------------
    {
    //! test add an edge into the graph
    Edge A_D(A,D,3);
    if(graph.add_edge(A_D))
        std::cout<<"Edge ("<<A_D.getPredecessor().getNodeID()<<"-"<<
                   A_D.getSuccessor().getNodeID()<<") was successfully added"<<std::endl;
    else std::cout<<"Failed to add edge"<<std::endl;
    }
    //---------------------------------------------------------------

    graph.display_graph();


    /************ Dijkstra's Algorithms Test **************/
    {
        std::cout<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;
        std::cout<<"Test Dijkstra's Algorithm on Directed Graph: "<<std::endl;
        std::cout<<"--------------------------------------------"<<std::endl;


        //! create Dijkstra object and pass the graph to it
        Dijkstra dijkstra(graph);

        //! declare the start and goal node to find a path

        //! first test: find a path from C to B
        { // begin of the first test scope
        Node start("C"), goal("B");
        auto path_ = dijkstra.findPath(start, goal);

           if(!path_.empty()){
                std::cout<<"The Dijkstra's path from "<<start.getNodeID()<<" to "<<
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
          auto path_ = dijkstra.findPath(start, goal);

             if(!path_.empty()){
                 std::cout<<"The Dijkstra's path from "<<start.getNodeID()<<" to "<<
                       goal.getNodeID()<<" is : ";
                  for(auto node_in_path : path_)
                      std::cout<<"("<<node_in_path.getNodeID()<<") ";
                  std::cout<<std::endl;
              }
              else std::cout<<"There is no path from "<<start.getNodeID()<<
                         " to "<<goal.getNodeID()<<std::endl;
            } // end of the second test scope

        } // end of Dijkstra's Algorithms Test
   /*******************************************************/



   /********** Extended Dijkstra's Algorithms Test ********/
    {
        std::cout<<std::endl;
        std::cout<<"------------------------------------------------------"<<std::endl;
        std::cout<<"Test Extended Dijkstra's Algorithm on Directed Graph: "<<std::endl;
        std::cout<<"------------------------------------------------------"<<std::endl;


        //! create Extended Dijkstra object and pass the graph to it
        ExtendedDijkstra extendeddijkstra(graph);

        //! declare the start and goal node to find a path

        //! first test: find a path from C to B
        { // begin of the first test scope
        Node start("C"), goal("B");
        auto path_ = extendeddijkstra.findPath(start, goal);

           if(!path_.empty()){
                std::cout<<"The Extended Dijkstra's path from "<<start.getNodeID()<<" to "<<
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
          auto path_ = extendeddijkstra.findPath(start, goal);

             if(!path_.empty()){
                  std::cout<<"The Extended Dijkstra's path from "<<start.getNodeID()<<" to "<<
                      goal.getNodeID()<<" is : ";
                  for(auto node_in_path : path_)
                      std::cout<<"("<<node_in_path.getNodeID()<<") ";
                  std::cout<<std::endl;
              }
              else std::cout<<"There is no path from "<<start.getNodeID()<<
                         " to "<<goal.getNodeID()<<std::endl;
            } // end of the second test scope

        } // end of Extended Dijkstra's Algorithms Test
   /*******************************************************/



   /********** Relaxed Node Selection Algorithms Test ********/
     {
         std::cout<<std::endl;
         std::cout<<"---------------------------------------------------------"<<std::endl;
         std::cout<<"Test Relaxed Node Selection Algorithm on Directed Graph: "<<std::endl;
         std::cout<<"---------------------------------------------------------"<<std::endl;


         //! create Relaxed Node Selection object and pass the graph to it
         RelaxedNodeSelection relaxedNodeSelection(graph, 3);

         //! declare the start and goal node to find a path

         //! first test: find a path from C to B
         { // begin of the first test scope
         Node start("C"), goal("B");
         auto path_ = relaxedNodeSelection.findPath(start, goal);

            if(!path_.empty()){
                 std::cout<<"The Relaxed Node Selection's path from "<<start.getNodeID()<<" to "<<
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
           auto path_ = relaxedNodeSelection.findPath(start, goal);

              if(!path_.empty()){
                   std::cout<<"The Relaxed Node Selection's path from "<<start.getNodeID()<<" to "<<
                       goal.getNodeID()<<" is : ";
                   for(auto node_in_path : path_)
                       std::cout<<"("<<node_in_path.getNodeID()<<") ";
                   std::cout<<std::endl;
               }
               else std::cout<<"There is no path from "<<start.getNodeID()<<
                          " to "<<goal.getNodeID()<<std::endl;
             } // end of the second test scope

      } // end of Relaxed Node Selection Algorithms Test
    /*******************************************************/




    /********** Bellman-Ford Algorithms Test ***************/
      {
          std::cout<<std::endl;
          std::cout<<"-----------------------------------------------"<<std::endl;
          std::cout<<"Test Bellman-Ford Algorithm on Directed Graph: "<<std::endl;
          std::cout<<"-----------------------------------------------"<<std::endl;


          //! create Bellman-Ford object and pass the graph to it
          BellmanFord bellmanFord(graph, 3);

          //! declare the start and goal node to find a path

          //! first test: find a path from C to B
          { // begin of the first test scope
          Node start("C"), goal("B");
          auto path_ = bellmanFord.findPath(start, goal);

             if(!path_.empty()){
                  std::cout<<"The Bellman-Ford's path from "<<start.getNodeID()<<" to "<<
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
            auto path_ = bellmanFord.findPath(start, goal);

               if(!path_.empty()){
                    std::cout<<"The Bellman-Ford's path from "<<start.getNodeID()<<" to "<<
                        goal.getNodeID()<<" is : ";
                    for(auto node_in_path : path_)
                        std::cout<<"("<<node_in_path.getNodeID()<<") ";
                    std::cout<<std::endl;
                }
                else std::cout<<"There is no path from "<<start.getNodeID()<<
                           " to "<<goal.getNodeID()<<std::endl;
              } // end of the second test scope

       } // end of Bellman-Ford Algorithms Test
     /*******************************************************/


    /********** Floyd Warshall Algorithms Test ***************/
    {
        std::cout<<std::endl;
        std::cout<<"-------------------------------------------------"<<std::endl;
        std::cout<<"Test Floyd Warshall Algorithm on Directed Graph: "<<std::endl;
        std::cout<<"-------------------------------------------------"<<std::endl;


        //! create Floyd Warshall object and pass the graph to it
        FloydWarshall floydWarshall(graph);
        std::vector<std::vector<int>> allPairsShortPaths =
                        floydWarshall.allPairsShortestPaths();

        std::cout<<"Matrix: Shortest path distances between"
                   " all pairs of nodes:"<<std::endl<<std::endl;

        for(unsigned int i = 0 ; i < allPairsShortPaths.size() ; i++){
            for(unsigned int j = 0; j < allPairsShortPaths[i].size() ; j++){

                if(allPairsShortPaths[i][j] == INFINITE_NUM)
                    std::cout<<" -";
                else
                     std::cout<<" "<<allPairsShortPaths[i][j];
            }

                std::cout<<std::endl;
        }


    } // end of Floyd Warshall Algorithms Test
  /***********************************************************/


  /************ A-Star's Algorithms Test *********************/
     {
         std::cout<<std::endl;
         std::cout<<"-------------------------------------------"<<std::endl;
         std::cout<<"Test A-Star's Algorithm on Directed Graph: "<<std::endl;
         std::cout<<"-------------------------------------------"<<std::endl;


         //! create A-Star object and pass the graph to it
         AStar aStar(graph);

         //! declare the start and goal node to find a path

         //! first test: find a path from C to B
         { // begin of the first test scope
         Node start("C"), goal("B");
         auto path_ = aStar.findPath(start, goal);

            if(!path_.empty()){
                 std::cout<<"The A-Star's path from "<<start.getNodeID()<<" to "<<
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
           auto path_ = aStar.findPath(start, goal);

              if(!path_.empty()){
                   std::cout<<"The A-Star's path from "<<start.getNodeID()<<" to "<<
                       goal.getNodeID()<<" is : ";
                   for(auto node_in_path : path_)
                       std::cout<<"("<<node_in_path.getNodeID()<<") ";
                   std::cout<<std::endl;
               }
               else std::cout<<"There is no path from "<<start.getNodeID()<<
                          " to "<<goal.getNodeID()<<std::endl;
             } // end of the second test scope

         } // end of A-Star's Algorithms Test
  /*************************************************************/

    std::cout<<std::endl;
    return 0;
}

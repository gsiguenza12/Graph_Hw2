/****************************
Templated created by Kazumi Slott
CS311

Your name: Gabriel Siguenza
Your programmer number: 32
Date last modified: 11.28.21

Any difficulties?:
*****************************/
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <queue>
#include <list>
#include <array> 

using namespace std;
class edge
{
  //????????????;  //## You want to access the private members of edge class from graph class
  friend class graph;

  int neighbor; //adjacent vertex
  int wt; //weight of the edge
 public:
  edge() { neighbor = -999, wt = -999;};
  edge(int u, int w) { neighbor = u; wt = w; }; //?
   
};

class graph
{
  int num_ver; //the total number of vertices in the graph
  list<edge*>* ver_ar; //pointer to the dynamic array that holds linked lists. The element of a node in a linked list is a pointer to an edge object 
                       //Let's use the library's list class. It is actually a doubly linked list. 
  int nextUnvisitedNodes(int* num);
  void DFT_helper(int v, int i, int* num, string& edges);
 public:
  graph(int V);
  ~graph();
  void addEdge(int v, int u, int w=1);
  void BFT(int start);
  void DFT(int start);
  void shortestPath(int start);
  void printSOMETHING();

  // **Not sure if I am supposed to create new constructors here or not. **/
  //void addEdge(int v, int u); //If the weight is not given, 1 is used for wt.
  //void addEdge(int v, int u, int w);
};

//constructor: num is the number of vertices
graph::graph(int num)
{
  num_ver = num; // set graph class instance var, num_ver

  //make a dynamic array with num slots where each slot holds a list object.
  ver_ar = new list<edge*>[num]; // the dynamic array of linked lists
  //The element of a node in the linked list is a pointer to an edge object  
             
  //list<list*> myList = new list[num_ver]{};
  //array<list<edge*>*> arrOfLists = new array()[num];  // create dynamically allocated array with pointers to list objects
  //list<list<edge*>*> aList[10];
  //ver_ar = new list<edge*>*[num]
}

/** MAKE THIS FUNCTION LAST **/
graph::~graph()
{
  /* 
  NOTE: You can call the destructor on every element of your array, 
  thats how I destroyed objects in heap 
  */
  
  //destroy all the edge objects created in heap                                                                                                        
  //For each vertex in ver_ar
  //    go through each node in the linked list. The element field of each node points to an edge object created with "new". You need to delete these.  

  //The library's list class has a destructor. All nodes belonging to the list will be destroyed by the destructor.
  //https://www.cplusplus.com/reference/list/list/~list/

  //destroy the ver_ar dynamic array
}

//add an edge from v to u with weight w into the graph
void graph::addEdge(int v, int u, int w)
{  
    //We are using the list class from the library. Which member function do you need to use to add a node at the end of the list?
    //https://www.cplusplus.com/reference/list/list/
    //Don't create an edge object statically, then it would get destroyed as soon as you leave this function. You need to create an edge object dymamically in heap, which will remain in heap even after you leave this function.. Remember "new" operator returns the memory address of the newly created object.
    //I have one line of code in this function.
    edge* E = new edge(u, w);
    cout << "This will print a memory address: " << E;
    ver_ar[v].push_back(E);
}

//add an edge from v to u with weight w into the graph
//void graph::addEdge(int v, int u, int w)
//{
//  //We are using the list class from the library. Which member function do you need to use to add a node at the end of the list?
//  //https://www.cplusplus.com/reference/list/list/
//  //Don't create an edge object statically, then it would get destroyed as soon as you leave this function. You need to create an edge object dymamically in heap, which will remain in heap even after you leave this function.. Remember "new" operator returns the memory address of the newly created object.
//  
//  //I have one line of code in this function.
//    //edge* E = new edge(v,u,w);
//    //ver_ar[v].push_back(E);
//}


//start Traversal at start
void graph::DFT(int start)
{
  string edges = "";
  //I made dynamic array called "num"

  //I used do-while
  //I am calling nextUnvisitedNodes() to see if there are more unvisited nodes.


  cout << "edges = " << edges << endl;

  //Don't forget to destroy the dynamic array
}

//I made the following function to see if there are still unvisited nodes
int graph::nextUnvisitedNodes(int* num)
{
  //go through the num array to see if you find a vertext with num=0. If so, return the index. If all visited, return -1.
  return 0;
}

void graph::DFT_helper(int v, int i, int* num, string& edges)
{
  //I have to use a c-string to make a string of edges. You don't need to use it if you know another way.
  char ar[5] = "v->u"; //v->u plus NULL character = size 5   

  //u returns the edge element, not the neighbor

  //The following shows how to iterate the library's linked list. You use an iterator.
  //https://www.cplusplus.com/reference/list/list/end/ 
  //iterator class is nested inside list class
  for (list<edge*>::iterator u = ver_ar[0].begin(); u != ver_ar[0].end(); u++) // from hw notes
    {
      //From the example on https://www.cplusplus.com/reference/list/list/end/
      //Notice *u gives you the element of the node pointed to by u. The element is a pointer to an edge object.
      //Between * and -> operator, -> has higher precedence. You need to use () around *u to get the element first.  

      /* 
      NOTE: ar[0] to char(u + 'A')
      know how to access the neighbor through the iterator, 
      Try (*u)->neighbor
      what this does is it will deference u FIRSTand then it will access the neighbor
      */

      //ar[0] =  ????;//replace index 0 by the name of v 
      //ar[3] = ????; //replace index 3 by the name of u
      edges += string(ar) + ","; //add v->u, to the end of edges


    }
}

//start is the index for the start vertex
void graph::BFT(int start)
{
  // Print all vertices from start vertex of distance 1
  // Print all vertices from start vertex of distance 2
  // ... 
  // Print all vertices from start vertex of distance 3

  string edges = ""; // use append to concatenate to string edges?
  edges.append("->");
  
  //edges.append((string)ver_ar[0]->(u + 'A');
  //Use the queue class from the library
  queue<int> queue;

  //I used do-while to visit all unconnected graphs

  //Check the manual to figure out what member functions of the queue class you need to use.
  // https://www.cplusplus.com/reference/queue/queue/


  cout << "edges = " << edges << endl;

  //Don't forget to destroy the dynamic array if you used one
}



void graph::shortestPath(int start)
{
  //I have 2 dynamic arrays here.

  //I used a queue for toBeChecked 




  //After the each vertex gets the minimum distance from the start point and predecessor,
  //Show the information about each vertex and shortest path from origine to destination and total distance.
  //For expected outputs, please check /cs/slott/cs311/graph.out
  cout << "\nShowing the info on each vertex" << endl;
  //?????????

  char dest;
  cout << "Enter the destination: ";
  cin >> dest;
  
  string path = "";//will have all paths from origine to destination
 
  cout << "The shortest path from " << char(start + 'A') << " to " << dest << " is " << path << endl;
  //cout << "The total distance is " << ???????? << endl;

  //Don't forget to destroy the dynamic arrays
}

inline void graph::printSOMETHING()
{
    cout << "printing something";
}

#endif

/*
 * Title: ts.cpp
 * Abstract: program takes in number of vertexes, number of edges, and the 
 * start and end point of each edge. using this it finds if it is a DAG graph.
 * if it is then it continues to find the starting nodes and finds the topological
 * order of the graph using dfs and prints that out along with the popping off order
 * of the graph
 * Author: Kyle Kern
 * ID: 1313
 * Date: 03/29/2018 
 *
 * A lot of the code comes from geeks4geeks sample questions I worked on over winter break
 * and I reused it because I couldn't find any other way of solving the problem presented
 * professor Byun said it was fine as long as i don't tell other students
 * https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
 * https://www.geeksforgeeks.org/topological-sorting/
 *
*/
#include<iostream>
#include <list>
#include <limits.h>
#include <fstream>
#include <stack>
using namespace std;
 stack<int> popOrder;
 int* topOrder= new int[98];
 bool* topCounter= new bool[98];
 bool* popTracker = new bool[98];
 int count =0;
 int startCount=0;
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
    bool isCyclicUtil(int V, bool visited[], bool *rs);
    void DFSUtil(int V, bool visited[]);
    
public:
    Graph(int V);   // Constructor
    void addEdge(int V, int w);   // to add an edge to graph
    void DFS(int V);
    bool isCyclic();    // returns true if there is a cycle in this graph
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    //adding to main graph by what is going where
    adj[v].push_back(w); .
}
 
//
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current vertex as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
 
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}
void popSetup(){
    for(int x=0;x<98;x++){
        popTracker[x]=false;
        topCounter[x]=false;
    }
}
// Returns true if the graph contains a cycle, else false.
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
 
    // Call the recursive helper function to detect cycle with other starting vertex
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
 
    return false;
}
void Graph::DFSUtil(int V, bool visited[])
{
    // Mark the current node as visited and add it to the stack and array for top order
    visited[V] = true;
    if(popTracker[V]==false){
        popOrder.push(V);
        popTracker[V]=true;
    }
    if(topCounter[V]==false){
        topCounter[V]=true;
        topOrder[count]=V;
         count++;
    }
    // Recur for all the vertices adjacent to current vert
    list<int>::iterator i;
    for (i = adj[V].begin(); i != adj[V].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v.
// It uses recursive DFSUtil()
void Graph::DFS(int V)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // call function to dfs search
    DFSUtil(V, visited);
}
//creating adjacency matrix that will be used to find starting nodes
int** create2DArray(int numVert,int numEdge, int* arr){
    int ** matrix = new int*[numVert];
    for(int a=0;a<numVert;a++){
         matrix[a] = new int[numVert];
    }
    for(int i = 0; i < numVert; ++i){
        for(int j = 0; j < numVert; ++j){
            matrix[i][j] = 0;
        }
    }
    int x=0;
    for(int a=0;a<numEdge;a++){
        matrix[arr[x]][arr[x+1]]+=1;
        x=x+2;
    }
    return matrix;
}
//using the matrix to find starting nodes
int* findStarting(int numVert,int** matrix){
    int i=0;
    int value;
    int startingSum=0;
    int* startingNum=new int[numVert];
    for(int x=0;x<numVert;x++){
        startingNum[x]=-1;
    }
    for(int x=0;x<numVert;x++){
        for(int y=0;y<numVert;y++){
            startingSum+=matrix[y][x];
            value=x;
        }
        if(startingSum==0){
            startingNum[i]=value;
             popOrder.push(i);
            popTracker[i]=true;
            i++;
            startCount++;
        }
        startingSum=0;
    }
    int reverse=startCount;
    while(reverse>=0){
        popOrder.push(startingNum[reverse]);
        popTracker[startingNum[reverse]]=true;
        reverse--;
    }
    return startingNum;
}
int main()
{
   
    string fileName="t1.txt";
    //opening file and setting the first index to the array size
    cout<<"Please input file name: ";
    cin>>fileName;
    ifstream file(fileName.c_str());
    int numEdge;
    int numVert;
    file>>numVert;
    file>>numEdge;
    int arrSize=numEdge*2;
    int * arr;
    arr = new int[numEdge*2];
    int** matrix;
    
    int i=0;
    //reading the file after the first index and assigning it to the array
     while(!file.eof())
    {
        file >> arr[i];
        i++;
    }
     
    // Create a graph given in the above diagram
    Graph g(numVert);
    for(int a=0;a<arrSize;a+=2){
        g.addEdge(arr[a],arr[a+1]);
    }
     //detecting if graph has a cycle within it
    if(g.isCyclic()){
        cout << "This isn't a DAG";
    }
    else{
        cout << "This Is a Dag"<<endl;
        //setting 2d array that will be used to find all starting vertexes
        matrix=create2DArray(numVert,numEdge,arr);
        int* startingNum=findStarting(numVert,matrix);
        cout<<"Starting Node(s): ";
        for(int x=0;x<numVert;x++){
            if(startingNum[x]!=-1){
                cout<<startingNum[x]<<" ";
            }
        }
        //adding starting verts to topolagical array to keep order
        for(int x=startCount;x>=0;x--){
            if(topCounter[startingNum[x]]==false){
                topOrder[count]=x;
                topCounter[startingNum[x]]=true;
                count++;
            }
        }
        //mapping out dfs graph using starting arrary
        for(int x=0;x<numVert;x++){
            if(startingNum[x]!=-1){
                g.DFS(startingNum[x]);
            }
        }
        //popping off the stack
        cout<<endl<<"Popping-off order: ";
        int count2=numVert;
        while(!popOrder.empty()&&count2!=0){
            count2--;
            cout<<popOrder.top()<< " ";
            popOrder.pop();
            
        }
        //printing topological order
        int count3=numVert;
        cout<<endl<<"Topological order: ";
        for(int x=1;x<count;x++){
            cout<<topOrder[x];
            if(x!=count-1){
                cout<<"->";
            }
        }
        
    }
    cout<<endl;
}
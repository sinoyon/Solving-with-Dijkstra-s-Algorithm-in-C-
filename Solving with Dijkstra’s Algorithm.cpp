#include<iostream>
#include<climits> 
using namespace std;
//this method returns a minimum distance for the 
//vertex which is not included in Tset.
int minimumDist(int dist[], bool Tset[]) 
{ int min=INT_MAX,index; 
for(int i=0;i<10;i++) 
{ if(Tset[i]==false && dist[i]<=min) 
{ min=dist[i];
index=i;
}
}return index;
} void Dijkstra(int graph[10][10],int src) // adjacency matrix used is 6x6
{ int dist[10]; // integer array to calculate minimum distance for each node. 
bool Tset[10];// boolean array to mark visted/unvisted for each node.
// set the nodes with infinity distance // except for the initial node and mark 
// them unvisited. 
for(int i = 0; i<10; i++)
{ dist[i] = INT_MAX;
Tset[i] = false;
}
dist[src] = 0; // Source vertex distance is set to zero.
for(int i = 0; i<10; i++){ 
int m=minimumDist(dist,Tset); // vertex not yet included.
Tset[m]=true;// m with minimum distance included in Tset.
for(int i = 0; i<10; i++) 
{ 
// Updating the minimum distance for the particular node.
if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && 
dist[m]+graph[m][i]<dist[i])
dist[i]=dist[m]+graph[m][i];
}
}
cout<<"Vertex\t\tDistance from source"<<endl;
for(int i = 0; i<10; i++) 
{ char str=65+i; // Ascii values for pritning A,B,C..
cout<<str<<"\t\t\t"<<dist[i]<<endl;
}
}int main()
{ 
int graph[10][10]={
{0, 104, 66, 0, 0, 0, 0, 0, 0, 0},
{104, 0, 72, 64, 0, 0, 0, 0, 0, 0},
{66, 72, 0, 68, 51, 77, 0, 0, 0, 0},
{0, 64, 68, 0, 0, 19, 77, 31, 0, 0},
{0, 0, 51, 0, 0, 23, 0, 0, 45, 0},
{0, 0, 77, 19, 23, 0, 13, 0, 0, 56},
{0, 0, 0, 77, 0, 13, 0, 20, 0, 0},
{0, 0, 0, 31, 0, 0, 20, 0, 0, 60},
{0, 0, 0, 0, 45, 0, 0, 0, 0, 52},
{0, 0, 0, 0, 0, 56, 0, 60, 52, 0}};
Dijkstra(graph,0);
return 0; 
}

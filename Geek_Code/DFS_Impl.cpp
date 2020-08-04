#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int node;

class Graph {

    int V; // No. of vertices
    
    list<int> *adj; // Adjacency list to store a graph

    void DFSUtil(int node,bool *vis);
public:
    Graph(int V)
    {
        this->V=V;
        adj = new list<int>[V];
    }

    void addEdge(int u,int v);
    void DFS();
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::DFSUtil(int node,bool *vis)
{
    vis[node]=true;
    cout<<node<<" ";
    list<int>::iterator i;

    for(i=adj[node].begin();i!=adj[node].end();++i)
    if(!vis[*i])
    DFSUtil(*i,vis);
}

void Graph::DFS()
{
    bool *vis = new bool[V];

    for(int i=0;i<V;i++)
    vis[i]=false;

    /*this part also covers if the Graph is disconneted.*/
    for(int i=0;i<V;i++)  // if value of node  is in the range of V;
    if(!vis[i])
    DFSUtil(i,vis);
}

int main()
    {
        int t;
        cin>>t;
        while(t--)
        {
            int V,E,a,b;
            cin>>V>>E;

            Graph g(V);
            for(int i=0;i<E;i++)
            {
                cin>>a>>b;
                g.addEdge(a,b);
            }

            g.DFS();
            cout<<endl;
        }
	
	return 0;
}
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int node;

class Graph {

public:

    int V; // No. of vertices
    
    list<int> *adj; // Adjacency list to store a graph

    Graph(int V)
    {
        this->V=V;
        adj = new list<int>[V];
    }

    void addEdge(int u,int v);
    void BFS(int u);
};

void Graph::addEdge(int u,int v)
{
    adj[u].push_back(v);
}

void Graph::BFS(int s)
{
    bool *vis = new bool[V];

    for(int i=0;i<V;i++)
    vis[i]=false;

    list<int> queue;

    vis[s]=true;
    queue.push_back(s);
    
    list<int>::iterator i;

    while(!queue.empty())
    {
        node = queue.front();
        cout<<node<<" ";
        queue.pop_front();

        for(i=adj[node].begin();i!=adj[node].end();++i)
        {
            if(!vis[*i])
            {
                vis[*i]=true;
                queue.push_back(*i);
            }
        }
    }
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

            g.BFS(0);
            cout<<endl;
        }
	
	return 0;
}
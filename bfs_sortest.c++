#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<vector>
using namespace std;

template<typename T>


class Graph
{
	map<T,list<T> > adjList;

	public:

	 	void addEdge( T u, T v, bool bider = true)
	 	{
	 		adjList[u].push_back(v);

	 		if(bider)
	 			adjList[v].push_back(u);


	 	}

	 	void printGraph()
	 	{
	 		for(auto i : adjList)
	 		{
	 			cout<<i.first<<" -> ";

	 			for(T entry : i.second)
	 				cout<<entry<<" ";
	 			cout<<endl;
	 		}
	 	}

		void bfs_sortestpath(T start)
		
		{
			map<T,int> dist;

			for(auto i : adjList )
				dist[i.first] = INT_MAX;

			map<T,T> parent;

			map<T,bool> visited;
			queue <T> q;

			dist[start] = 0;
			parent[start] = start;

			q.push(start);
			visited[start] = true;

			while(!q.empty())
			{
				T node = q.front();
				q.pop();

				cout<<node<<" ";

				for(T i : adjList[node]) 
				{
					if( visited[i] == false)
					{
						q.push(i);
						visited[i] = true;

						dist[i] = dist[node] +1;
						parent[i] = node;
						
					}
				}

			}

			cout<<endl;

			for( auto i : dist)
			{
				cout<<"Distance from "<<start<<" to "<<i.first<<" is "<<i.second<<endl;

			}

			for(auto i: parent)
			{
				cout<<"parent of "<<i.first<<" is "<<i.second<<endl;
			}
		}
};


int main()
{

	Graph <int> g;
	g.addEdge(1,2,false);
	g.addEdge(2,3,false);
	g.addEdge(3,4,false);
	g.addEdge(4,1,false);
	g.printGraph();
	g.bfs_sortestpath(1);
	return 0;
}
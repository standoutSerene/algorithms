#include<iostream>
#include<map>
#include<list>
using namespace std;


template<typename T>

class Graph{
	map<T,list<T> > adjList;

public:
	Graph(){

	}

	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}


	bool isCyclicHelper(T node,map<T,bool> &visited,map<T,bool> &inStack){
		visited[node]=true;
		inStack[node]=true;
		for(T neighbour:adjList[node]){
			if((!visited[neighbour] && isCyclicHelper(neighbour,visited,inStack))|| (inStack[neighbour]))
				return true;
		}
		inStack[node]=false;
		return false;
	}

	bool isCyclic(){
		map<T,bool> visited;
		map<T,bool> inStack;

		for(auto i:adjList){
			T node =i.first;
			    if(!visited[node]){
				    bool cyclePresent=isCyclicHelper(node,visited,inStack);
			    if(cyclePresent)
				    return true;
                }

		}
		return false;
	}
};

int main(){
	Graph<int> g;
	g.addEdge(0,2);
	g.addEdge(0,1);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,0);
	g.addEdge(4,5);
	g.addEdge(1,5);
	if(g.isCyclic())
		cout<<"Cycle Present!";
	else
		cout<<"No cycle found!";
	cout<<endl;
	return 0;
}
#include<iostream>
#include<list>
#include<map>
using namespace std;


template<typename T>
class Graph{
	int V;
	map<T,list<T> > adjList;
public:
	Graph(int v){
		V=v;
	}

	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);
	}

	

	bool isCyclicHelper(T node,map<T,bool> &visited,T parent){
		visited[node]=true;
		for(T neighbour :adjList[node]){
			if(!visited[neighbour]){
				bool cycleDetected = isCyclicHelper(neighbour,visited,node);
				if(cycleDetected)
					return true;
			}else if(neighbour!=parent)
					return true;       
		}
		return false;
	}


    bool isCyclicDFS(){
		map<T,bool> visited;
		for(auto i:adjList){
			T node = i.first;
			if(!visited[node]){
				bool ans=isCyclicHelper(node,visited,node);
				if(ans)
					return true;
            } 
		}
		return false;
	}
};
int main(){
	Graph<int> g(4);
	g.addEdge(1,2);
	g.addEdge(1,4);
	g.addEdge(2,3);
	if(g.isCyclicDFS())
		cout<<"Cyclic Graph"<<endl;
	else
		cout<<"Non-Cyclic"<<endl;
}

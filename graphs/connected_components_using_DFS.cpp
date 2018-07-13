#include<iostream>
#include<map>
#include<list>


using namespace std;

template<typename T>

class Graph{
	map<T,list<T>> adjList;


public:
	Graph(){

	}


	void addEdge(T u,T v,bool bidir=true){
		adjList[u].push_back(v);
		if(bidir)
			adjList[v].push_back(u);

	}

	void print(){
		for(auto i:adjList){
			cout<<i.first<<"->";
			for(T entry:i.second)
				cout<<entry<<",";
			cout<<endl;
		}
	}

	void dfsHelper(T node,map<T,bool> &visited){
		visited[node]=true;
		cout<<node<<" ";
		for(T neighbour:adjList[node])
			if(!visited[neighbour])
				dfsHelper(neighbour,visited);
	}

	void dfs(T src){
		int components=1;
		map<T,bool> visited; 
		dfsHelper(src,visited);
        cout<<endl;
		for(auto i:adjList){
			T city=i.first; 
			if(!visited[city]){
				dfsHelper(city,visited);
                cout<<endl;
				components++;
            }
		}
		cout<<"The graph had "<<components<<" components."<<endl;
	}

};

int main(){
	Graph<string> g;
	g.addEdge("Amritsar","Jaipur");
	g.addEdge("Amritsar","Delhi");
	g.addEdge("Delhi","Jaipur");
	g.addEdge("Mumbai","Jaipur");
	g.addEdge("Mumbai","Bhopal");
	g.addEdge("Delhi","Bhopal");
	g.addEdge("Mumbai","Bangalore");
	g.addEdge("Agra","Delhi");
	g.addEdge("Andaman","Nicobar");
	g.print();
	g.dfs("Amritsar");
}
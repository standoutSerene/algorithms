#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<list>
#include<climits>
using namespace std;

template<typename T>
class Graph{
	unordered_map<T,list<pair< T,int > > > m;

public:
	void addEdge(T u,T v,int dist,bool bidir=true){
		m[u].push_back(make_pair(v,dist));
		if(bidir){
			m[v].push_back(make_pair(u,dist));
		}
	}
	void printAdjList(){
		for(auto j :m){
			cout<<j.first<<"->";
			for(auto l:j.second)
				cout<<"("<<l.first<<","<<l.second<<")";
			cout<<endl;
		}
	}
	void dijkstraSSSP(T src){
        unordered_map<T,int> dist;
        for(auto j:m)
            dist[j.first]=INT_MAX;
        set<pair<int,T>> s;
        dist[src]=0;
        s.insert(make_pair(0,src));
        while(!s.empty()){
            auto p=*(s.begin());
            T node=p.second;

            int nodeDist=p.first;
            s.erase(s.begin());

            for(auto childPair:m[node]){
                if(nodeDist+childPair.second<dist[childPair.first]){
                    //updation is not possible in set
                    //remove the old pair,add new pair to simulate updation
                    T dest =childPair.first;
                    auto f=s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[dest]=nodeDist+childPair.second;
                    s.insert(make_pair(dist[dest],dest)); 


                }
            }
        }


        for(auto d:dist){
            cout<<d.first<<" is located at a distance of "<<d.second<<endl;
        }

	}
};

int main(){
	Graph<string> india;
	india.addEdge("Amritsar","Delhi",1);
	india.addEdge("Amritsar","Jaipur",4);
	india.addEdge("Jaipur","Delhi",2);
	india.addEdge("Jaipur","Mumbai",8);
	india.addEdge("Bhopal","Agra",2);
	india.addEdge("Mumbai","Bhopal",3);
	india.addEdge("Agra","Delhi",1);
	//india.printAdjList();
    india.dijkstraSSSP("Amritsar");
}
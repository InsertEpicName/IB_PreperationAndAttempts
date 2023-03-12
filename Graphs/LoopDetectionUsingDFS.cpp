#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> adj_list [N];
bool visited[N];

vector <vector<int>> cc;
vector <int> current_cc;
void dfs(int vertex){
	current_cc.push_back(vertex);
	visited[vertex]=true;
	for(int child: adj_list[vertex]){
		if(visited[child])continue;
		else{
			dfs(child);
		}
	}
}

bool detectCycle(int vertex,int parent){
    visited[vertex]=true;
    bool isLoopExists=false;
    for(int child: adj_list[vertex]){
        if(visited[child] && child==parent)continue;
        if(visited[child]){
            return true;
        }
        isLoopExists |= detectCycle(child,vertex); //This is |= means that it will return true if any of the recursion gives true 
    }
    return isLoopExists;
}

//To detect cycle: If we end up going to a vertex that is already visited and is not the parent vertex of the given node
//then we say that a cycle exists in a graph. parent node means the node that occured just before the given node 

int main() {
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}
	
	bool isLoopExists=false;
	//For cycle too.. we need to run for every vertex as there may be connected components with cycles among themselves 
	for(int i=1;i<=n;i++){
	    if(visited[i])continue;
	    if(detectCycle(i,0)){
	        isLoopExists=true;
	        break;
	    }
	}
	cout<<isLoopExists<<endl;
	return 0;
}

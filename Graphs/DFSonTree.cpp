#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int depth[N];
int height[N];
vector <int> adj_list [N];
void DFSforTree(int vertex,int parent){
    
    for(int child : adj_list[vertex]){
        //This is section where we compute just before going inside the child (means depth)
        if(child==parent)continue;
        depth[child]=depth[vertex]+1;
        DFSforTree(child,vertex);
        
        //This is section where we compute after all the depth of the child DFS is completed
        height[vertex]=max(height[vertex],height[child]+1);
    }
}

//To detect cycle: If we end up going to a vertex that is already visited and is not the parent vertex of the given node
//then we say that a cycle exists in a graph. parent node means the node that occured just before the given node 

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++){
		int v1,v2;
		cin>>v1>>v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}
    DFSforTree(1,0);
    cout<<endl;
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
}

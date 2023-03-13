#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int depth[N+1];
vector <int> adj_list[N];

void dfsForTree(int vertex,int parent=0){
    for(int child: adj_list[vertex]){
        if(child==parent)continue;
        depth[child]=depth[vertex]+1;
        dfsForTree(child,vertex);
        
    }
}
int main()
{
    //Write subtree sum for every node and display on console
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int v1,v2;
        cin>>v1>>v2;
        adj_list[v1].push_back(v2);
        adj_list[v2].push_back(v1);
    }
    
    dfsForTree(1);
    int mx_d=-1;
    int mx_d_node;
    for(int i=1;i<=n;i++){
        if(mx_d<depth[i]){
            mx_d=depth[i];
            mx_d_node=i;
        }
        depth[i]=0;
    }
    dfsForTree(mx_d_node);
     mx_d=-1;
    for(int i=1;i<=n;i++){
        if(mx_d<depth[i]){
            mx_d=depth[i];
            mx_d_node=i;
        }
        depth[i]=0;
    }
    cout<<"Diameter of the given tree is: "<<mx_d<<endl;
    return 0;
}

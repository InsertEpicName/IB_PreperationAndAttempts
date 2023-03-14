#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int par[N];
vector <int> adj_list[N];
void dfsForTree(int vertex,int parent=-1){
    par[vertex]=parent;
    for(int child: adj_list[vertex]){
        if(child==parent)continue;
        
        dfsForTree(child,vertex);
        
        
    }
}

vector <int> path(int v){
    vector <int> ans;
    while(v!=-1){
        ans.push_back(v);
        v=par[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
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
    cout<<endl;
    int x,y;
    cin>>x>>y;
    vector <int> px=path(x);
    vector <int> py=path(y);
    int min_ln=min(px.size(),py.size());
    int lca=-1;
    for(int i=0;i<min_ln;i++){
        if(px[i]==py[i]){
            lca=px[i];
        }
        else{
            break;
        }
    }
    cout<<"The LCA of given nodes is "<<lca<<endl;
    return 0;
}

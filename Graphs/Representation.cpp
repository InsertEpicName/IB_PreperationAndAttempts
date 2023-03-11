#include <bits/stdc++.h>

using namespace std;

const int N=1e3;
int adj_mat[N][N];
int main()
{
    //Make adjacency matrix representation for 
    // 6 9
    // 1 3
    // 1 5 
    // 3 5 
    // 3 4 
    // 3 6 
    // 3 2 
    // 2 6 
    // 4 6 
    // 5 6
    
    int n,m;
    cin>>n>>m;
    // int adj_mat[n+1][n+1];
    // for(int i=0;i<m;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     adj_mat[u][v]=1;
    //     adj_mat[v][u]=1;
    // }
    
    // for(int i=0;i<n+1;i++){
    //     for(int j=0;j<n+1;j++){
    //         cout<<adj_mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    vector <pair<int,int>> adj_list[n+1];
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj_list[u].push_back({v,wt});
        adj_list[v].push_back({u,wt});
    }
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<adj_list[i].size();j++){
            cout<<adj_list[i]<<"->"<<adj_list[i][j].first<<" "<<adj_list[i][j].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}

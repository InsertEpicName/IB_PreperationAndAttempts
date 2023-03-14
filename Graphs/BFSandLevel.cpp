#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
const int M=1e9+7;
bool visited[N+1];
vector <int> adj_list[N];
int level[N];
void BFS(int source){
    queue <int> q;
    visited[source]=true;
    q.push(source);
    // cout<<source<<" ";
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cout<<x<<" at level "<<level[x]<<endl;
        
        for(int child: adj_list[x]){
            if(!visited[child]){
                q.push(child);
                visited[child]=true;
                level[child]=level[x]+1;

            }
        }
    }
    cout<<endl;
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
    
    BFS(1);
    

    return 0;
}

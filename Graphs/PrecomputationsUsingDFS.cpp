#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;
int subtree_sum[N];
int even_ct[N];
vector <int> adj_list[N];

void dfsForTree(int vertex,int parent=0){
    subtree_sum[vertex]+=vertex;
    if(vertex%2==0){
        even_ct[vertex]++;
    }
    for(int child: adj_list[vertex]){
        if(child==parent)continue;
        dfsForTree(child,vertex);
        subtree_sum[vertex]+=subtree_sum[child];
        even_ct[vertex]+=even_ct[child];
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
    for(int i=1;i<=(n);i++){
        cout<<"The subtree sum for "<<i<<"th node is: "<<subtree_sum[i]<<" and even count is "<<even_ct[i]<<endl;
    }
    
    return 0;
}

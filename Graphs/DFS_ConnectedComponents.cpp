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
int main() {
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		int v1,v2;
		cin>>v1>>v2;
		adj_list[v1].push_back(v2);
		adj_list[v2].push_back(v1);
	}
	int ct=0;
	for(int i=1;i<=n;i++){
		if(visited[i])continue;
		current_cc.clear();
			dfs(i);
		cc.push_back(current_cc);
			ct++;
		
	}
	for(int i=0;i<cc.size();i++){
		for(int j=0;j<cc[i].size();j++){
			cout<<cc[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<ct<<endl;
	return 0;
}

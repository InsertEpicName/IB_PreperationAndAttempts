https://www.onlinegdb.com/edit/zg266Y1Xp#editor_1#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector <int> adj_list [N];
bool visited[N][N];


void dfs (vector<vector<int>>& image, int i, int j, int initialcolor,int newColor){
   int n=image.size();
   int m=image[0].size();
   if(i<0 || j<0)return;
   if(i>=n || j>=m)return;
   if(image[i][j]!=initialcolor)return;
   image[i][j]=newColor;
   dfs(image,i-1,j,initialcolor,color);
   dfs(image,i+1,j,initialcolor,color);
   dfs(image,i,j-1,initialcolor,color);
   dfs(image,i,j+1,initialcolor,color);
   
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
        int initialcolor=image[sr][sc];
        if(initialcolor!=color)
        {dfs(image,sr,sc,initialcolor,color);}
        
        return image; //Because image matrix passed by reference 
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

}

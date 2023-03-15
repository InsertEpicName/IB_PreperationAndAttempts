#include <bits/stdc++.h>
using namespace std;

const int N=1e3+9;
int level[N][N];
int visited[N][N];
const int INF=1e9+10;

int GetX(string s){
    int ans= s[0]-'a';
    return ans;
}
int GetY(string s){
        return s[1]-'1';
}

void reset(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            level[i][j]=0;
            visited[i][j]=0;
        }
    }
}

vector <pair<int,int>> movements={
    {-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{2,-1},{2,1},{1,2}
};

bool valid(int x,int y){
    return ((x>=0 && y>=0)&&(x<8 && y<8));
}

int NAKANJ(string source,string destination){
    int sourcex=GetX(source);
    int sourcey=GetY(source);
    int destx=GetX(destination);
    int desty=GetY(destination);
    queue<pair<int,int>>q;
    q.push({sourcex,sourcey});
    visited[sourcex][sourcey]=1;
    level[sourcex][sourcey]=0;
    while(!q.empty()){
        pair<int,int>v=q.front();
        q.pop();
        int X=v.first;
        int Y=v.second;
        for(auto move: movements){
            int Xn=X+move.first;
            int Yn=Y+move.second;
            if(!valid(Xn,Yn))continue;
            if(!visited[Xn][Yn]){
                q.push({Xn,Yn});
                level[Xn][Yn]=level[X][Y]+1;
                visited[Xn][Yn]=1;
            }
        }
        // if(lev[destx][desty]!=INF){
        //     break;
        // }
    }
    return level[destx][desty];
}

int main(){
    
        int t;
        cin>>t;
        while(t--){
        string source,destination;
        cin>>source>>destination;
       cout<<NAKANJ(source,destination)<<endl;
        }
        
    return 0;
}

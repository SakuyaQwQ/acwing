
/*
单源最短路模板题
*/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,f,t;
vector<vector<pair<int,int>>> edges;
vector<int> vis;

struct cmp{
    auto operator()(const pair<int,int>& e1, const pair<int,int>& e2)const{
        return e1.second>e2.second;
    }  
};

int main(){
    cin>>n>>m>>f>>t;
    edges.resize(n+1);
    vis.resize(n+1,0x3f3f3f3f);
    for(int i=0;i<m;++i){
        int x,y,k;
        cin>>x>>y>>k;
        edges[x].emplace_back(y,k);
        edges[y].emplace_back(x,k);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q;
    q.emplace(f,0);
    while(!q.empty()){
        auto [now,cost]=q.top();
        q.pop();
        if(vis[now]==0x3f3f3f3f){
            vis[now]=cost;
            if(now==t)break;
            for(auto&[to,val]:edges[now]){
                if(vis[to]==0x3f3f3f3f){
                    q.emplace(to,val+cost);
                }
            }
        }
    }
    cout<<vis[t];
}

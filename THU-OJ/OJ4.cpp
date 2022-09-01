//
//  main.cpp
//  ByteDance
//
//  Created by 张凯 on 2022/3/27.
//  Copyright © 2022 张凯. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <unordered_map>
using namespace std;
void dfs(vector<vector<int>>&adj,vector<bool>&visit,int id){
    for(auto i:adj[id]){
        if(!visit[i]){
            visit[i] = true;
            dfs(adj, visit, i);
        }
    }
    return;
}

int main(){
    int m,k;
    cin>>m>>k;
    int t1,t2;
    vector<vector<int>> adj(m+1);
    vector<bool> visit(m+1);
    unordered_map<int, int>degree;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
        degree[t1] ++;
        degree[t2] ++;
    }
    visit[0] = true;
    dfs(adj, visit, 0);
    for(auto v:visit)
        if(!v){
            cout<<"It's not a tree!"<<endl;
            return 0;
        }
    for(int i=0;i<=m;i++){
        if(degree[i]>=(k+2)){
            cout<<"No such a node!"<<endl;
            return 0;
        }
    }
    for(int i=0;i<=m;i++){
        if(degree[i]<=k){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<"No such a node!"<<endl;
}

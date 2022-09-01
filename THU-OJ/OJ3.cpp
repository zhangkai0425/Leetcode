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

const int max_int = 1000000000;
vector<int> dijkstra(vector<vector< pair<int,int>>>&adj,int &s,vector<int> &t){
    int n = int(adj.size());
    vector<int>dist(n,max_int);
    vector<bool>st(n,0);
    // 堆优化dijkstra算法
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> heap;
    heap.push({0,s});
    dist[s] = 0;
    while (!heap.empty()) {
        auto t = heap.top();
        heap.pop();
        auto distance = t.first,id = t.second;
        if(st[id]) continue;
        st[id] = true;
//        cout<<"t.id = "<<id<<endl;
        for(auto x:adj[id]){
//            cout<<"adj[id]:x = ("<<x.first<<","<<x.second<<")"<<endl;
            auto j = x.second;
            if(dist[j]>(distance+x.first))
                dist[j] = distance+x.first;
            heap.push({dist[j],j});
        }
    }
    vector<int> min_dis;
//    for(int i=0;i<dist.size();i++)
//        cout<<"d"<<"["<<i<<"] = "<<dist[i]<<" ";
//    cout<<endl;
    for(auto tid:t)
        min_dis.push_back(dist[tid]);
    return min_dis;
}

int main(){
    int N,M;
    cin>>N>>M;
    int A = N * M;
    vector<vector<pair<int,int>>>adj(A);
    vector<pair<int,int>> x; //发电厂 pair<下标,代价>
    vector<int> y; // 工厂
    int tmp;
    for(int i=0;i<N;i++)
        for (int j=0; j<M; j++) {
            cin>>tmp;
            if(tmp==0) continue;
            else if(tmp>0) x.push_back({i*M+j,tmp});
            else if(tmp==-1) y.push_back(i*M+j);
        }
    vector<vector<int>> LR(N,vector<int>(M-1,0));
    vector<vector<int>> UD(N-1,vector<int>(M,0));
    for(int i=0;i<N;i++)
        for(int j=0;j<M-1;j++){
            cin>>tmp;
            LR[i][j] = tmp;
        }
    for(int i=0;i<N-1;i++)
        for(int j=0;j<M;j++){
            cin>>tmp;
            UD[i][j] = tmp;
        }

    //构造邻接表
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++){
            vector<int> lr = {j-1,j+1};
            vector<int> ud = {i-1,i+1};
//            cout<<"i::"<<i<<","<<"j::"<<j<<endl;
            auto id = i*M + j;
            // 左右方向加入邻接表
            // 上下方向加入邻接表
//            cout<<"id="<<id<<"  lr="<<lr[0]<<" "<<lr[1]<<"  ud="<<ud[0]<<" "<<ud[1]<<endl;
            for(auto dx:lr){
                if(dx<0||dx>=M) continue;
                adj[id].push_back({LR[i][(j+dx)/2],i*M+dx});
            }
            for(auto dy:ud){
                if(dy<0||dy>=N) continue;
                adj[id].push_back({UD[(i+dy)/2][j],dy*M+j});
            }
        }
//    cout<<"debug::"<<adj.size()<<endl;
//    for(auto x:adj)
//        cout<<x.size()<<" ";
//    cout<<endl;
    
    if((x.size()==1)&&(y.size()==1)){
        int s = x[0].first;
        auto t = y; //工厂集合
        auto min_dis = dijkstra(adj, s, t);
        int ans = x[0].second + min_dis[0];
        cout<<ans<<endl;
    }
    else if(y.size()==1){
        int ans = max_int;
        int s = y[0];
        vector<int> t(x.size(),0);
        for(int i=0;i<t.size();i++)
            t[i] = x[i].first;
        auto min_dis = dijkstra(adj, s, t);
        for(int i=0;i<t.size();i++)
            ans = min(ans,min_dis[i]+x[i].second);
        cout<<ans<<endl;
    }
    else if((x.size()==1)&&(y.size()!=1)){
        vector<int>all;
        int ans = x[0].second; //一定有一个发电厂的代价
        for(int i=0;i<N*M;i++)
            all.push_back(i);
        vector<vector<int>> Dist;
        //工厂的所有全员最短路径
        for(auto yy:y){
            auto min_dis = dijkstra(adj, yy, all);
            Dist.push_back(min_dis);
        }
        auto min_dis = dijkstra(adj, x[0].first, all);
        Dist.push_back(min_dis);
        int min_sum = max_int;
        for(int i=0;i<N*M;i++){
            auto sum = 0;
            for(auto d:Dist)
                sum += d[i];
            min_sum = min(min_sum,sum);
        }
        ans += min_sum;
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }
//    for(auto d:min_dis)
//        cout<<"最短距离为:"<<d<<endl;
//    for(auto d:min_dis)
//        ans += d;
//    cout<<ans<<endl;
}
/*
3 4
0 5 0 -1
0 0 0 0
-1 0 0 0
2 5 2
2 1 2
1 1 1
3 1 5 1
3 5 1 5
 
3 4
0 5 0 0
0 0 0 0
-1 0 7 0
2 5 2
2 1 2
1 1 1
3 1 5 1
3 5 1 5

3 4
0 5 0 -1
0 0 0 0
-1 0 0 0
2 5 2
2 1 2
1 1 1
3 1 5 1
3 5 1 5
*/

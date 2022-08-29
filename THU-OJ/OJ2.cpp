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

bool isSame(vector<int>id,vector<int>version){
    for(auto i:id)
        if(version[i]!=version[id[0]])
            return false;
    return true;
}
pair<int, int> getMode(vector<int>version,int w,vector<int>tmp_id){
    unordered_map<int, int> record;
    unordered_map<int, bool> visit;
    for(auto x:tmp_id){
        auto v = version[x];
        record[v] ++;
        visit[x] = true;
    }
    int num = int(tmp_id.size());
    for(int i=0;i<version.size();i++){
        if(visit[i])
            continue;
        auto v = version[i];
        record[v] ++;
        num ++;
        if(record[v]>=w){ //寻找到的众数候选
            auto new_version = v;
            return make_pair(new_version, num);
        }
    }
    return make_pair(0, 0);
}
int main(){
    int n,m,w,d;
    cin>>n>>m>>w>>d;
    vector<int>version(n,0);//版本号
    vector<int>all_id(n,0);
    vector<pair<int, int>>ans;
    queue< pair< int, vector<int> > > update; //更新信息:pair<更新版本int，更新序列<vector<int>>>
    queue<bool> refresh; //记录是更新还是写入 更新为0,写入为1
    //逐行进行操作
    char order;
    int time,tmp;
    for(int i=0;i<n;i++)
        all_id[i] = i;
    for (int i=0; i<m; i++) {
        cin>>order>>time;
        //首先进行更新和写入操作
        while(!update.empty()){
            auto u = update.front();
            if(u.first>time) //还未到更新和写入时机 time为版本号 time+d为更新时间
                break;
            else{
                //更新和写入
                int new_version = u.first;
                auto flag = refresh.front();
                if(!flag)
                    new_version -= d;
                for(auto id:u.second){
                    version[id] = new_version>version[id]?new_version:version[id]; //更新版本号
                }
                refresh.pop();
                update.pop();
            }
        }
        
        if(order=='R'){
            vector<int> tmp_id;
            for(int j=0;j<w;j++){
                cin>>tmp;
                tmp_id.push_back(tmp-1);
            }
            if(isSame(tmp_id,version)){
                ans.push_back(make_pair(w, version[tmp_id[0]]));
            }
                
            else{
                //准备更新
                auto p = getMode(version,w,tmp_id);
                auto new_version = p.first,num = p.second;
                ans.push_back(make_pair(num, new_version));
                //更新->全部
                update.push(make_pair(new_version+d, all_id));
                refresh.push(false);
            }
            
        }
        else if(order=='W'){
            vector<int> tmp_id;
            int num = 0;
            cin>>num;
            for(int j=0;j<num;j++){
                cin>>tmp;
                tmp_id.push_back(tmp-1);
            }
            //发送写命令
            update.push(make_pair(time+d, tmp_id));
            refresh.push(true);
        }
        
    }
    for(auto x:ans)
        cout<<x.first<<" "<<x.second<<endl;
}
/*
5 6 3 3
R 0 2 3 4
R 2 2 3 4
R 2 3 4 1
W 3 5 1 2 5 3 4
R 5 1 2 3
R 6 2 3 5
 
 
5 9 3 3
R 0 2 3 4
R 2 2 3 4
R 2 3 4 1
W 3 5 1 2 5 3 4
R 5 1 2 3
R 6 2 3 5
W 6 3 2 4 5
R 8 1 2 3
R 9 1 2 3
 */

#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int>p1,pair<int, int>p2){
    return p1.first>p2.first;
}
int main(){
    int num,x,y;
    cin>>num;
    vector<pair<int,int>> p;
    for(int i=0;i<num;i++){
        scanf("%d %d",&x,&y);
        p.push_back(make_pair(x,y));
    }
    sort(p.begin(),p.end(),cmp);
    int ymax = -1;
    stack<pair<int,int>>s;
    for(int i=0;i<num;i++)
        if(p[i].second>ymax)
            s.push(p[i]),ymax = p[i].second;
    while(!s.empty()){
        printf("%d %d\n",s.top().first,s.top().second);
        s.pop();
    }   
}

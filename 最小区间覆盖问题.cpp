#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<pair<int, int> > ver;
int main(){
    cin>>n;
    int l,r,t;
    for(int i=0; i<n; i++){
        scanf("%d",&t);
        l = (i-t)>=0?(i-t):0;
        r = (i+t)<n?(i+t):n-1;
        ver.push_back(make_pair(l,r));
    }
    sort(ver.begin(), ver.end());
    int now=0,pos=0,ans=0; // now未打扫
    while(pos<ver.size() && now<n){
        int mx=0;
        while(pos<ver.size() && ver[pos].first<=now){
            mx = max(mx, ver[pos].second);
            pos++; // pos之前的R都比下一次的now要小,全部舍弃
        }
        if(mx<=now-1)break; // 无法打扫到新的地方
        now = mx+1;
        ans++;
    }
    if(now>=(n-1))
        cout<<ans;
    else
        cout<<-1;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    int num,tmp;
    cin>>num;
    vector<int> v;
    for(int i=0;i<num;i++){
        cin>>tmp;
        v.push_back(tmp);
    }
//    sort(v.begin(),v.end());
    int cmax = -1;
    for(int i=0;i<num;i++){
        int l = i-1,r = i+1,sum = v[i];
        while(l>=0){
            if(v[l]>=v[i])
                sum += v[l--];
            else
                break;
        }
        while(r<num){
            if(v[r]>v[i])
                sum += v[r++];
            else
                break;
        }
        cmax = max(cmax,sum*v[i]);
    }
    cout<<cmax<<endl;
}

#include <iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
struct uv{
    int x;
    int y;
};
bool cmp(struct uv &u1,struct uv &u2){
    return u1.x > u2.x;
}
int main(){
    int num,x,y;
    vector<struct uv>p;
    cin>>num;
    for(int i=0;i<num;i++){
        scanf("%d %d",&x,&y);
        struct uv pi = {x,y};
        p.push_back(pi);
    }
    sort(p.begin(),p.end(),cmp);
    int ymax = -100;
    stack<struct uv> ans;
    for(int i=0;i<num;i++){
        if(p[i].y>ymax){
            ymax = p[i].y;
            ans.push(p[i]);
        }
    }
    while(!ans.empty()){
        printf("%d %d\n",ans.top().x,ans.top().y);
        ans.pop();
    }
}

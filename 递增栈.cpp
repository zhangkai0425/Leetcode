#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    if(heights.size()==1)
        return heights[0];
    heights.push_back(-1);
//    heights.insert(heights.begin(), 0);
    stack<int> h;
    h.push(0);
    int maxarea = 0;
    for(int i=1;i<heights.size();i++){
        if(h.empty()||heights[i]>=heights[h.top()])
            h.push(i);
        else{
            while(!h.empty()){
                if(heights[i]<=heights[h.top()]){
                    int L;
                    int H = heights[h.top()];
                    h.pop();
                    if(h.empty())
                        L = -1;
                    else
                        L = h.top();
                    maxarea = max(maxarea,H*(i-L-1));
                }
                else
                    break;
            }
            h.push(i);
        }
    }
    return maxarea;
}
int main(){
    vector<int> height = {1,1};
    int x = largestRectangleArea(height);
    cout<<x<<endl;
}

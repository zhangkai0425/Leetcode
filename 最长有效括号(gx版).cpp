//时间复杂度O(n)、空间复杂度O(n)
#include<iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string a;
    cin>>a;
    auto len=a.size();//输入字符串长度
    auto maxnum=0,num=0;
    stack<int>s;
    for(int i=0;i<len;i++)
    {
        if(a[i]=='(') s.push(i);
        else
        {
            if(s.empty()||a[s.top()]==')') s.push(i);
            else if(a[s.top()]=='(') s.pop();
        }
    }
    auto temp=len;
    while(!s.empty()){
        num = temp - s.top()-1;
        temp = s.top();
        s.pop();
        maxnum = max(num,maxnum);
    }
    num = temp;
    maxnum = max(num,maxnum);
    cout<<maxnum<<endl;
}

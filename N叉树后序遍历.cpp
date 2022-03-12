#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        dfs(ret,root);
        return ret;
    }
    void dfs(vector<int>& ret,Node* root)
    {
        if(!root)return ;//叶节点返回
        for(int i=0;i<root->children.size();i++)//中间结点先深度
            dfs(ret,root->children[i]);
        ret.push_back(root->val);//处理当前节点
    }
};

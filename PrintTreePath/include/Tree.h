#ifndef TREE_H
#define TREE_H
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<ctime>
#include<cstdio>
#include<string>
#include<vector>
#include<climits>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include "Tree.h"
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left, *right;
};
class Tree
{
    public:
        Tree();
        virtual ~Tree();


        void Print(TreeNode* root)
        {
            cur.clear();
            dfs(root);
        }

    protected:
    private:
        vector<int> cur;
        void dfs(TreeNode* root)
        {
            if(!root)
            {
                for(auto e: cur) cout<<e<<" ";
                cout<<endl;
                return ;
            }
            cur.push_back(root->val);
            dfs(root->left);
            dfs(root->right);
            cur.pop_back();
        }
};

#endif // TREE_H

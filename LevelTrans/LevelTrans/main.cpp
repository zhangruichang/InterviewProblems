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
#include <unordered_map>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
#define f first
#define s second
int getint(){
	int t = 0, flag = 1;
	char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
	{
		t = t * 10 + c - '0';
		c = getchar();
	}
	return t*flag;
}
struct TreeNode
{
    int val;
    TreeNode* left, *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};
int stoi(string x)
{
    int sum=0;
    for(auto e: x)
        sum=sum*10+e-'0';
    return sum;
}
int main()
{

#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    //freopen ("out.txt" , "w" , stdout);
#endif

    TreeNode*root=new TreeNode(INT_MIN);
    bool invalid=0;string str;
    while(cin>>str)
    {
        int len=str.size();
        str=str.substr(1, len-2);
        int pos=str.find(",");
        if(pos==-1) break;
        int val=stoi(str.substr(0,pos));
        string dir=str.substr(pos+1, str.size()-pos-1);
        //cout<<dir<<endl;
        TreeNode* p=root;
        for(auto e: dir)
        {
            if(e=='L')
            {
                if(!p->left) p->left=new TreeNode(INT_MIN);
                p=p->left;
            }
            else
            {
                if(!p->right) p->right=new TreeNode(INT_MIN);
                p=p->right;
            }
        }
        if(p->val==INT_MIN) p->val=val;
        else
        {
            invalid=1;
            break;
        }
    }
    queue<TreeNode*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        auto cur=q.front();q.pop();
        if(cur->val!=INT_MIN) ans.push_back(cur->val);
        else
        {
            invalid=1;
            break;
        }
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    if(invalid) cout<<"-1"<<endl;
    else
    {
        for(auto e: ans) cout<<e<<" ";
        cout<<endl;
    }
	return 0;
}

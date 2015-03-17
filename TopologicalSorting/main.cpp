/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
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
	int t = 0, flag = 1; char c = getchar();
	while (c<'0' || c>'9' || c == '-')
	{
		if (c == '-')
			flag = -1;
		c = getchar();
	}
	while (c >= '0'&&c <= '9')
		t = t * 10 + c - '0', c = getchar();
	return t*flag;
}
int GCD(int m, int n)
{
    if(!m) return n;
    return GCD(n%m, m);//yushu and chushu
}
int a[maxn], n;

vector<int> TopoSort(vector<vector<int>> G)//direced G, and no circle
{
    n=G.size();
    int indegree[n];memset(indegree, 0, sizeof indegree);
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
            if(G[i][j]) indegree[j]++;
    }
    //for(int i=0;i<n;i++) cout<<indegree[i]<<" ";
    //for(auto e: indegree) cout<<e<<" ";
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        int j;
        for(j=0;j<n;j++)
            if(!indegree[j]) break;
        if(j==n)
        {cout<<"No Topo Sort";return ans;}
        indegree[j]=-1;//-1 as visited
        ans.push_back(j);
        for(int k=0;k<n;k++)
            if(G[j][k]) indegree[k]--;
    }
    return ans;
}


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    vector<vector<int>> G({{0, 1, 1, 0, 0, 0, 0},
                          {0, 0, 0, 1, 1, 0, 0},
                          {0, 0, 0, 1, 0, 1, 0},
                          {0, 0, 0, 0, 1, 0, 0},
                          {0, 0, 0, 0, 0, 1, 0},
                          {0, 0, 0, 0, 0, 0, 1},
                          {0, 0, 0, 0, 0, 0, 0}});
    auto ans=TopoSort(G);
    for(auto e: ans) cout<<e<<" ";
	return 0;
}

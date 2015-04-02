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
const int maxn = 1e3 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
int n, m;
vector<pii> cur;
int v[maxn][maxn];
int Out[maxn][maxn];
/*
const int dx[] = {-2,-2,2,2,-1,-1,1,1};
const int dy[] = {1,-1,1,-1,2,-2,2,-2};
*/
const int dx[8]={-2, -1, 1, 2, 2, 1, -1, -2}, dy[8]={1, 2 ,2,1, -1, -2, -2, -1};

bool out(int i, int j)
{
    if(i>=n || i<0 || j>=m || j<0) return 1;
    return 0;
}
bool dfs(int i, int j, int cnt)
{
    if(out(i, j) || v[i][j]) return 0;
    if(cnt==n*m) return 1;
    v[i][j]=1;
    for(int k=0;k<8;k++)
    {
        int ni=i+dx[k], nj=j+dy[k];
        cur.push_back({ni, nj});
        if(dfs(ni, nj, cnt+1)) return 1;
        cur.pop_back();
    }
    v[i][j]=0;
    return 0;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>n>>m)
    {
        bool ok=0;
        memset(v,0, sizeof(v));cur.clear();
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            cur.push_back({i, j});
            if(dfs(i, j, 1)) {ok=1;goto L1;}
            cur.pop_back();
        }

    L1: if(!ok) continue;
        int cnt=1;
        for(int i=0;i<cur.size();i++) //for(int j=0;j<m;j++)
        {
            Out[cur[i].fi][cur[i].se]=cnt++;
            //cout<<cur[i*m+j].fi*m+cur[i*m+j].se+1<<" \n"[j==m-1];
        }
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            cout<<Out[i][j]<<" \n"[j==m-1];
    }
	return 0;
}

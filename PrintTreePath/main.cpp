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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19

vector<vector<char>> mat_;
int m, n;
vector<char> curmatrix;
void dfs(int i, int j);
void PrintMatrixPath(vector<vector<char>> mat)
{
    mat_=mat;
    curmatrix.clear();
    m=mat.size(), n=mat[0].size();
    dfs(0, 0);
}
void dfs(int i, int j)
{
    if(i<0 || i>=m || j<0 || j>=n || mat_[i][j]=='#') return ;
    if(i==m-1 && j==n-1)
    {
        for(auto e: curmatrix) cout<<e<<" ";
        cout<<endl;
        return ;
    }
    curmatrix.push_back(mat_[i][j]);
    dfs(i+1, j);
    dfs(i, j+1);
    curmatrix.pop_back();
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    vector<vector<char>> mat={{'1','2','3'},{'4','#','5'},{'6','7','8'}};
    PrintMatrixPath(mat);
	return 0;
}

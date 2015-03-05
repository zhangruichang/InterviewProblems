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
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;
//int, -2^31~2^31-1    -2.1*10^9~2.1*10^9 (-2147483648-2147483647)
//unsigned int, 0~2^32-1  0~4.2*10^9
//long long  -2^63~2^63-1 -9*10^18~9*10^18
//unsigned long long 0~2^64-1  0~1.8*10^19

bool FindThief(int n, vector<int> seq)//room 0....n-1, seq: [0, n-1]
{
    int k=seq.size();
    bool dp[k+1][n]; memset(dp, 0, sizeof dp);//k+1 * n
    for(int j=0;j<n;j++) dp[0][j]=1;
    for(int i=1;i<=k;i++)
    {
        bool FindThief=0;
        for(int j=0;j<n;j++)
        {
            dp[i][j]= seq[i-1]!=j&& (j-1>=0 && dp[i-1][j-1] || j+1<n && dp[i-1][j+1]);
            if(dp[i][j]) FindThief=1;
        }
        if(!FindThief) return 1;
    }
    return 0;
}
/*
{'a':'1','b':['c':'2','d':'3']}

a:1
b:[
  c:2
  d:3
  ]
{'d':['c':'2']}

d:[
  c:2
  ]
*/
void ParseJson(string json)
{
    int level=0;
    bool one=1;
    for(int i=1;i+1<json.size();)
    {
        if(json[i]=='\'')
        {
            int ii;
            for(ii=i+1;json[ii]!='\'';ii++);
            if(one)
            {
                for(int j=0;j<2*level;j++) cout<<" ";
                //one=!one;
            }
            //else one=!one;
            cout<<json.substr(i+1, ii-i-1);
            //if(one) cout<<":", one=!one;
            i=ii+1;//skip '\'' and :
        }
        else if(json[i]==':')cout<<":", i++,one=0;
        else if(json[i]=='[')
        {
            //for(int j=0;j<2*level;j++) cout<<" ";
            cout<<'['<<endl;
            level++;i++;one=1;
        }
        else if(json[i]==',') cout<<endl, i++,one=1;
        else if(json[i]==']')
        {
            cout<<endl;
            for(int j=0;j<2*level;j++) cout<<" ";
            cout<<']';
            //<<endl;
            i++;level--;one=1;
        }
    }
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    //vector<int> seq={1,1};
    //cout<<FindThief(3, seq)<<endl;
    string str="{'a':'1','b':['c':'2','d':['3':['5':'a','9':'b']],'e':'3']}";
    //string str2="{'d':['c':'2']}";
    //cout<<str;
    ParseJson(str);

	return 0;
}

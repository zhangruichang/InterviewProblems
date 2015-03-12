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
string v[4];
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    string str;
    for(int i=0;i<4;i++) cin>>str, v[i]=str.substr(2);
    //memset(v, 0 ,sizeof v);
    vector<int> ans;
    for(int i=0;i<4;i++)
    {
        bool shorter=1, longer=1;
        for(int j=0;j<4;j++)
        {
            if(j==i) continue;
            if(!(v[i].size()>=2*v[j].size())) longer=0;
            if(!(v[j].size()>=2*v[i].size())) shorter=0;
        }
        if(longer || shorter) ans.push_back(i);
    }
    if(ans.size()==1) cout<<char(ans[0]+'A')<<endl;
    else cout<<'C'<<endl;
	return 0;
}

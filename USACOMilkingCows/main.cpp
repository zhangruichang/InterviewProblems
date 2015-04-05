/*
ID: zhangru14
PROG: milk2
LANG: C++11
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
typedef vector<int> vi;
#define fi first
#define se second
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
    return !m ? n : GCD(n%m, m);
}
int a[maxn], n, t, m;

struct Node
{
    int time;
    bool se;
    bool operator<(Node n) const
    {
        if(time!=n.time) return time<n.time;
        return se<n.se;
    }
};
vector<Node> v;
int main()
{

//#ifndef ONLINE_JUDGE
    //freopen ("milk2.in" , "r" , stdin);
    //freopen ("milk2.out" , "w" , stdout);
//#endif

    cin>>n;//0 means start, 1 means end
    {
        v.clear();int x, y;
        for(int i=0;i<n;i++) cin>>x>>y, v.push_back({x, 0}), v.push_back({y, 1});
        sort(v.begin(), v.end());
        //for(auto e: v) cout<<e.times<<" "<<e.se<<endl;
        int depth=0;int maxin=0, maxout=0, instart=v[0].time, outstart;
        bool inflag=1, outflag=0;
        for(auto e: v)
        {
            if(e.se==0) depth++;
            else depth--;
            if(!depth)
            {
                if(inflag)
                {
                    maxin=max(maxin, e.time-instart);
                    outstart=e.time;
                    inflag=0;outflag=1;
                }
            }
            else
            {
                if(outflag)
                {
                    maxout=max(maxout, e.time-outstart);
                    instart=e.time;
                    outflag=0;inflag=1;
                }
            }
        }
        cout<<maxin<<" "<<maxout<<endl;
    }
	return 0;
}

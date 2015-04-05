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
double eps=1e-6;
/*
2 4 2 2 1 0 0.95
2 4 2 0 1 0 0.55

*/
//money is 5fen, 1jiao, 2jiao, 5jiao, 1yuan, 2yuan
int MinCoins(int a[], double money)
{
    //cout<<money<<endl;
    int c[]={5,10,20,50,100,200};int n=6;bool f1=0, f2=0;
    //cout<<0.95*100<<endl;
    int m=(int)(money*100+eps), ans=0;
    //cout<<m<<endl;
    for(int i=n-1;m>0 && i>=0;i--)
    {
        int x=min(m/c[i],a[i]);
        ans+=x;
        m-=x*c[i];
    }
    if(m==0) f1=1;
    m=int(money*100+eps);
    int mi=upper_bound(c, c+n, m)-c;
    if(mi>=n) return f1?ans:-1;
    m=c[mi]-m;int ans2=1;
    cout<<c[mi]<<" "<<m<<endl;
    for(int i=n-1;m>0 && i>=0;i--)
    {
        int x=min(m/c[i], a[i]);
        ans2+=x;
        m-=x*c[i];
    }
    if(m==0) f2=1;
    if(f1&&f2) return min(ans, ans2);
    else if(f1) return ans;
    else if(f2) return ans2;
    else return -1;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    while(cin>>a[0])
    {
        for(int i=1;i<6;i++) cin>>a[i];
        double money;cin>>money;
        cout<<money<<endl;
        cout<<MinCoins(a, money)<<endl;
    }
	return 0;
}

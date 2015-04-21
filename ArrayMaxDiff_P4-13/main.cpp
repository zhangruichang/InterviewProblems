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
int bitcount(int x) {//O(cnt), cnt is 1 number of x
    int res = 0;
    while (x) {
	res++;
	x -= x & -x;
    }
    return res;
}

int ArrayMaxDif(int a[], int n)
{
    if(!n) return 0;
    int b[n];
    for(int i=0;i<n;i++) b[i]=a[i];
    sort(a, a+n);
    for(int i=n-2;i>=0;i--)
    {
        a[i]=a[i]*a[i+1]+1;
    }
    int MinDif=a[0];
    sort(b, b+n, greater<int>());
    for(int i=n-2;i>=0;i--)
    {
        b[i]=b[i]*b[i+1]+1;
    }
    int MaxDif=b[0];
    return MaxDif-MinDif;
}
int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int a[]={1,2,3}, n=sizeof(a)/sizeof(int);
    cout<<ArrayMaxDif(a, n)<<endl;

	return 0;
}

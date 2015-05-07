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
#include<sstream>
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
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define iOS  ios_base::sync_with_stdio(false)
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
template <typename T>
string to_string(T value)
{
  //create an output string stream
  ostringstream os ;

  //throw the value into the string stream
  os << value ;

  //convert the string stream into a string and return
  return os.str() ;
}
LL MultMod(LL a,LL b,LL MOD)
{
    a %= MOD;
    b %= MOD;
    LL ret = 0;
    while(b){
        if (b & 1){
            ret += a;
            if(ret >= MOD) ret -= MOD;
        }
        a = a << 1;
        if (a >= MOD) a -= MOD;
        b = b >> 1;
    }
    return ret;
}
//int a[maxn], n, t, m;

bool IsP[maxn];
int P[maxn];
void Phi(LL N)
{
    bool check[N+1];
    LL prime[N+1], fai[N+1];
    memset(check, 0, sizeof check);
    fai[1]=1;
    LL tot=0;
    for(LL i=2;i<=N;i++)
    {
        if(!check[i])
        {
            prime[tot++]=i;
            fai[i]=i-1;
        }
        for(LL j=0;j<tot;j++)
        {
            if(i*prime[j]>N) break;
            check[i*prime[j]]=1;
            if(i%prime[j]==0)
            {
                fai[i*prime[j]]=fai[i]*prime[j];
                break;
            }
            else
                fai[i*prime[j]]=fai[i]*(prime[j]-1);
        }
    }
    /*
    for(int i=0;i<tot;i++) cout<<prime[i]<<" ";
    cout<<endl;
    for(int i=1;i<=N;i++) cout<<fai[i]<<" ";
    cout<<endl;*/
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    //output [1, N] primes
    LL N=maxn;
    Phi(N);
    /*
    LL N=100;
    fill_n(IsP, sizeof(IsP)/sizeof(bool), 1);
    //memset(IsP, 1, sizeof IsP);
    int Pi=0;
    for(LL i=2;i*i<=N;i++)
    {
        if(IsP[i])
        {
            //P[Pi++]=i;
            for(LL j = i *i;j<=N;j+=i)
                IsP[j]=0;
        }
    }
    for(int i=2;i<=N;i++) if(IsP[i]) cout<<i<<' ';*/


	return 0;
}

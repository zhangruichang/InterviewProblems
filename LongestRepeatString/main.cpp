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
int a[maxn], n, t, m;
bool comp(const char* s1, const char* s2)
{
    if(!s1) return 1;
    else if(!s2) return 0;
    while(*s1==*s2) s1++, s2++;
    return *s1<*s2;
}
int comlen(char* s1, char* s2)
{
    if(!s1 || !s2) return 0;
    int len=0;
    while(*s1==*s2) s1++, s2++, len++;
    return len;
}
char* LongestRepeatString(char* s)
{
    int n=strlen(s);
    if(!n) return "";
    char* Suffix[n];
    for(int i=0;i<n;i++) Suffix[i]=s+i;
    sort(Suffix, Suffix+n, comp);
    int maxlen=1, maxi=0;;
    for(int i=0;i<n-1;i++)
    {
        int commonlen=comlen(Suffix[i], Suffix[i+1]);
        if(commonlen>maxlen) maxlen=commonlen, maxi=i;
    }
    char* ans=new char[maxlen+1];
    strncpy(ans, Suffix[maxi],maxlen);
    ans[maxlen]='\0';
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
    char*s="abccabccabce";
    cout<<LongestRepeatString(s)<<endl;
	return 0;
}

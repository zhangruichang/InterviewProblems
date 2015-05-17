/*
Author: richard
Contact: zhangruichang112@gmail.com
*/
#include <bits/stdc++.h>
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

bool IsSubSequence(string str, string pat)
{
    int strn=str.size(), patn=pat.size(), i, j;
    for(i=0, j=0; i<strn && j<patn; )
    {
        if(str[i]==pat[j]) i++, j++;
        else i++;
    }
    return j==patn;
}
void GetNext(string pat);
int Next[maxn];
bool IsSubString(string str, string pat)
{
    //cout<<"zhang"<<endl;
    GetNext(pat);
    //cout<<"zhang"<<endl;
    int strn=str.size(), patn=pat.size();
    int i=0, j=0;
    while(i<strn && j<patn)
    {
        if(j==-1 || str[i]==pat[j])
            i++, j++;
        else
            j=Next[j];
        //if(j==patn) return 1;
    }
    return j==patn;
}

void GetNext(string pat)
{
    Next[0]=-1;
    int n=pat.size();
    for(int i=0;i<=n-2;i++)
    {
        int k=Next[i];
        while(k!=-1 && pat[k]!=pat[i])
            k=Next[k];
        Next[i+1]=k+1;//Next[k+1]=k+1, typos here
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
    string str="richard.zhang", pat="riar.";
    cout<<IsSubSequence(str, pat)<<endl;
	return 0;
}

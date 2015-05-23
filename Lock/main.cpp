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

vector<string> dfs(int i)
{
    if(i==1) return {"0","1","2","3","4","5","6","7","8","9"};
    vector<string> post, cur=dfs(i-1);
    for(int j=0;j<10;j++)
    {
        if(j%2==0)
            for(int k=0;k<cur.size();k++) post.push_back(to_string(j)+cur[k]);
        else
            for(int k=(int)cur.size()-1;k>=0;k--) post.push_back(to_string(j)+cur[k]);
    }
    return post;
}
int main()
{

#ifndef ONLINE_JUDGE
    //freopen ("in.txt" , "r" , stdin);
    //freopen ("out.txt" , "w" , stdout);
#endif

    /*
    while(cin>>n)
    {
        vector<string> cur({"0","1","2","3","4","5","6","7","8","9"});
        for(int i=1;i<n;i++)
        {
            vector<string> post;
            for(int j=0;j<10;j++)
            {
                if(j%2==0)
                    for(int k=0;k<cur.size();k++) post.push_back(to_string(j)+cur[k]);
                else
                    for(int k=(int)cur.size()-1;k>=0;k--) post.push_back(to_string(j)+cur[k]);
            }
            cur=post;
        }
        for(auto e : cur) cout<<e<<endl;
    }*/
    while(cin>>n)
    {
        auto ans=dfs(n);
        for(auto e: ans) cout<<e<<endl;
    }
	return 0;
}

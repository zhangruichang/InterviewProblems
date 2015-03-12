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

string Partition(string s)
{
    list<char> l;
    for(auto e: s) l.push_back(e);
    auto it1=l.begin();
    for(;it1!=l.end();it1++) if(*it1!='*') break;
    auto last=it1;
    for(auto it=it1;it!=l.end();)
    {
        if(*it=='*')
        {
            l.insert(last, *it);
            it=l.erase(it);
        }
        else it++;
    }
    string ans;
    for(auto e: l) ans.push_back(e);
    return ans;
}


//chenshuo
string Partition_ChenShuo(string str)
{
  auto it = remove(str.rbegin(), str.rend(), '*');
  fill(it, str.rend(), '*');
  return str;
}

//laozhao
string Partition_LaoZhao(string str)
{
    int cnt=0;
    for(auto e: str) if(e=='*') cnt++;
    string ans(cnt, '*');
    for(auto e: str) if(e!='*') ans.push_back(e);
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
    string str="aaaaa***aa*a.abb..*a";
    auto ans=Partition_LaoZhao(str);cout<<ans<<endl;
	return 0;
}

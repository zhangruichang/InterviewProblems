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
unordered_map<int, list<int>::iterator> hasht;
list<int> L;
void MoveLeft(int x, int y)
{
    auto it=hasht[x];
    //hasht.erase(x);
    L.erase(it);
    auto ity=hasht[y];
    auto newitx=L.insert(ity, x);
    hasht[x]=newitx;
}
void MoveRight(int x, int y)
{
    auto it=hasht[x];
    L.erase(it);
    auto ity=hasht[y];
    auto newitx=L.insert(next(ity), x);
    hasht[x]=newitx;
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    int n, m;
    while(cin>>n>>m)
    {
        hasht.clear(), L.clear();
        for(int i=n;i>=1;i--) L.push_front(i), hasht[i]=L.begin();
        for(int i=0;i<m;i++)
        {
            int x, y;string ins;
            cin>>ins>>x>>y;
            if(ins=="A")
                MoveLeft(x, y);
            else MoveRight(x, y);
        }
        for(auto e: L) cout<<e<<" ";
        cout<<endl;
    }

	return 0;
}

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
//#include <unordered.set>
//#include <unordered.map>
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
string str[3];
bool f(char c)
{
    bool fx=0;
    for(int i=0;i<3;i++)
    {
        if(str[i][0]==c && str[i][1]==c &&str[i][2]==c) fx=1;
    }
    for(int j=0;j<3;j++)
    {
        if(str[0][j]==c && str[1][j]==c &&str[2][j]==c) fx=1;
    }

    if(str[0][0]==c && str[1][1]==c &&str[2][2]==c) fx=1;
    if(str[0][2]==c && str[1][1]==c && str[2][0]==c) fx=1;
    return fx;
}
int main()
{

#ifndef ONLINE.JUDGE
    //freopen ("in.txt" , "r" , stdin);
    //freopen ("out.txt" , "w" , stdout);
#endif


        for(int i=0;i<3;i++) cin>>str[i];
        int x=0, o=0;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++)
        {
            if(str[i][j]=='X') x++;
            else if(str[i][j]=='0') o++;
        }

        if((x!=o && x!=o+1) || (f('X') && f('0')) || (x==o && f('X')) || (x==o+1 && f('0'))) puts("illegal");
        else
        {
            bool fo=f('0'), fx=f('X');

            if(fx && !fo) puts("the first player won");
            else if(!fx && fo) puts("the second player won");
            else if(x+o==9 && !fx && !fo) puts("draw");
            else
            {
                if(x==o)
                {
                    puts("first");
                    /*
                    bool ok=0;
                    for(int i=0;i<3;i++) for(int j=0;j<3;j++)
                    {
                        if(str[i][j]=='.')
                        {
                            str[i][j]='X';
                            if(f('X')) {ok=1;goto L1;}
                            str[i][j]='.';
                        }
                    }
                L1: puts(ok?"Next win": "Next cannot win");*/
                }
                else
                {
                    puts("second");
                    /*
                    bool ok=0;
                    for(int i=0;i<3;i++) for(int j=0;j<3;j++)
                    {
                        if(str[i][j]=='.')
                        {
                            str[i][j]='O';
                            if(f('O')) {ok=1;goto L2;}
                            str[i][j]='.';
                        }
                    }
                L2: puts(ok?"Next win": "Next cannot win");*/
                }
            }
        }

	return 0;
}

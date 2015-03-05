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
#include<windows.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 10;
typedef long long LL;
typedef unsigned long long ULL;

double F(int a, int b, int c)
{
    return sqrt(abs(a-b)*abs(a-b)+abs(a-c)*abs(a-c)+abs(c-b)*abs(c-b));
}

vector<int> MinDis(vector<int>& a, vector<int>& b,vector<int>& c)
{//a b c size()>=1
    int ansa=a[0], ansb=b[0], ansc=c[0];
    double mindis=F(ansa, ansb, ansc);
    for(int i=0, j=0, k=0; i+1<a.size()||j+1<b.size()||k+1<c.size(); )
    {
        double curdis=F(a[i], b[j], c[k]);
        if(curdis<mindis) ansa=a[i], ansb=b[j], ansc=c[k];
        int minx=INT_MAX;
        if(i+1<a.size()) minx=min(minx, a[i]);
        if(j+1<b.size()) minx=min(minx, b[j]);
        if(k+1<c.size()) minx=min(minx, c[k]);
        if(i+1<a.size())
		{
			if(minx==a[i]) i++;
		}
        else if(j+1<b.size())
		{
			if(minx==b[j]) j++;
		}
        else if(k+1<c.size())
			k++;
    }
    double curdis=F(a[a.size()-1], b[b.size()-1], c[c.size()-1]);
    if(curdis<mindis) ansa=a[a.size()-1], ansb=b[b.size()-1], ansc=c[c.size()-1];
    return {ansa, ansb, ansc};
}

int main()
{
    //cout<<(1ULL<<63)-1+(1ULL<<63)<<endl;

    vector<int> a={1,19}, b={2,3,18}, c={5,6,10,20};
    auto ans=MinDis(a, b, c);
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
	return 0;

}

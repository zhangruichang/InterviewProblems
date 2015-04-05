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
int a[maxn], n, t, m;
int Partition(vector<int> v, int low, int high)
{
    int i=low, j=high, pivot=v[low];
    while(i<j)
    {
        while(i<j && v[j]>=pivot) j--;
        while(i<j && v[i]<=pivot) i++;
        if(i<j) swap(v[i], v[j]);
    }
    swap(v[low], v[i]);
    return i;
}

int QS(vector<int> v, int low, int high, int k)
{
    if(low>high) return -1;
    if(low==high) return v[low];
    int mid=Partition(v, low, high);
    int order=mid-low+1;
    if(order==k) return v[mid];
    else if(order>k) return QS(v, low, mid-1, k);
    else return QS(v, mid+1, high, k-order);
}

int QuickSelect(vector<int> v, int k)
{
    int n=v.size();
    return QS(v, 0, n-1, k);
}



int Topk(vector<int> v, int k)
{
    int n=v.size();
    priority_queue<int> pq;
    for(int i=0;i<k;i++) pq.push(v[i]);
    for(int i=k+1;i<n;i++)
    {
        if(v[i]<pq.top())
        {
            pq.pop();pq.push(v[i]);
        }
    }
    return pq.top();
}

int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    vector<int> v={1,35,23,46,57,457,43,364,574};
    int k=2;
    cout<<QuickSelect(v, k)<<endl;
	return 0;
}

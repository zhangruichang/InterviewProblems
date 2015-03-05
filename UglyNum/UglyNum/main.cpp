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
struct Node
{
    int i, j, k;
    ULL val;
    Node(int i_, int j_, int k_): i(i_), j(j_), k(k_)
    {
        val=pow(2.0, i)*pow(3.0, j)*pow(5.0, k);
    }
    bool operator<(Node n) const
    {
        return val>n.val;
    }
};
int a[maxn];
int ON(int n)
{
    a[0]=1;
    int p1=0, p2=0, p3=0, val=0;
    for(int i=1;i<n;i++)
    {
        while(val<=a[i-1])
        {
            val=min(a[p1]*2, min(a[p2]*3, a[p3]*5));
            if(a[p1]*2==val) p1++;
            else if(a[p2]*3==val) p2++;
            else p3++;
        }
        a[i]=val;
    }
    return a[n-1];
}


int GetNthUglyNum(int n)//2, 3, 5
{
    Node root(0, 0, 0);
    priority_queue<Node> pq;
    pq.push(root);
    unordered_set<int> hash;
    Node cur(0, 0, 0); hash.insert(1);
    for(int i=0;i<n;i++)
    {
        cur=pq.top();
        auto cur1=cur; cur1.i++, cur1.val*=2;
        auto cur2=cur; cur2.j++, cur2.val*=3;
        auto cur3=cur; cur3.k++, cur3.val*=5;
         //pq.push(cur2), pq.push(cur3);
        if(hash.find(cur1.val)==hash.end()) hash.insert(cur1.val),pq.push(cur1);
        if(hash.find(cur2.val)==hash.end()) hash.insert(cur2.val),pq.push(cur2);
        if(hash.find(cur3.val)==hash.end()) hash.insert(cur3.val),pq.push(cur3);
        hash.erase(cur.val), pq.pop();
    }
    return cur.val;
}


int main()
{
/*
#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    freopen ("out.txt" , "w" , stdout);
#endif
*/
    //for(int i=1;i<=10;i++)
    int n=999;
        cout<<ON(n)<<" "<<GetNthUglyNum(n);
    cout<<endl;
	return 0;
}

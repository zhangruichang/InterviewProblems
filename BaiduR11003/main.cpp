#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int a[MAXN];
int n;
bool check(int v){
    int now = -INF;
    for(int i = 0;i < n;i++){
        if(now-a[i] > v)return false;
        now = max(now+1,a[i]-v+1);
    }
    return true;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--){
        iCase++;
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%d",&a[i]);
        int low = 0, high = 2000000;
        //int ans
        while(low < high){
            int mid = (low+high)/2;
            if(check(mid)){
                high = mid;
            }
            else low = mid+1;
        }
        printf("Case #%d:\n%d\n",iCase,low);
    }
    return 0;
}

#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn = 20 + 10;
const int inf = 0x3f3f3f3f;
int x[maxn][2],a[maxn];
int mat[maxn][maxn],n,m,__end__;
bool in(int x,int y)
{
	if(x<0||x>=n || y<0||y>=m)return 0;
	return 1;
}
const int dx[] = {-2,-2,2,2,-1,-1,1,1};
const int dy[] = {1,-1,1,-1,2,-2,2,-2};
bool dfs(int x,int y,int now)
{
	if(now==__end__){
		return true;
	}
	for(int i = 0; i < 8; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(in(nx,ny)&&!mat[nx][ny]){
			mat[nx][ny] = now+1;
			if(dfs(nx,ny,now+1))return true;
			mat[nx][ny] = 0;
		}
	}
	return false;
}
int main(){
	while(~scanf("%d%d",&n,&m)) {
		__end__ = n*m;
		bool ok = false;
		memset(mat,0,sizeof mat);
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < m; ++j){
				mat[i][j] = 1;
				if(ok = dfs(i,j,1)) goto L1;

			}
     L1:if(ok){
			for(int i = 0; i < n; ++i) {
				for(int j = 0; j < m; ++j) {
					printf("%d%c", mat[i][j]," \n"[j+1==m]);
				}
			}
		}else {
			puts("NO Soloution");
		}
	}
    return 0;
}

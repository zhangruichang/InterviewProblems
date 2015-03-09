#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
vector<int>ans[maxn][maxn];
bool G[maxn][maxn];
void init(int n)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++) {
			ans[i][j].clear();
			G[i][j] = false;
		}
}
void floyd(int n)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				G[i][j]=(G[i][k]&&G[k][j])?true:G[i][j];
}
void solve(int n)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++) {
				if(G[i][j]==false)continue;
				vector<int>v(maxn);
				sort(ans[i][k].begin(), ans[i][k].end());
				sort(ans[k][j].begin(), ans[k][j].end());
				sort(ans[i][j].begin(), ans[i][j].end());
				vector<int> ::iterator it=set_intersection(ans[i][k].begin(), ans[i][k].end(),ans[k][j].begin(), ans[k][j].end(),v.begin());
				v.resize(it-v.begin());
				vector<int>v1(maxn);
				it = set_union(v.begin(), v.end(),ans[i][j].begin(), ans[i][j].end(),v1.begin());
				v1.resize(it-v1.begin());
				ans[i][j].clear();
				for (it=v1.begin(); it!=v1.end(); ++it) {
					ans[i][j].push_back(*it);
				}
			}
}
int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m) {
		init(n);
		int u,v,w;
		for(int i=1; i <= m; ++i) {
			cin >> u >> v >> w;
			G[u][v]=G[v][u]=true;
			ans[u][v].push_back(w);
			ans[v][u].push_back(w);
		}
		floyd(n);
		solve(n);
		int Q;
		cin>>Q;
		while(Q--) {
			cin>>u>>v;
			cout<<ans[u][v].size()<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 +5 ;
typedef long long LL;
const LL mod = 1e9 + 7;
int _next_[maxn];
bool f[maxn];
void getFail(const string & p)
{
    int sz = p.size();
    _next_[0] = 0; _next_[1] = 0;
    for(int i = 1; i < sz; i++) {
        int j = _next_[i];
        while(j&&p[i]!=p[j]) j = _next_[j];
        _next_[i+1] = (p[i]==p[j]?j+1:0);
    }
    memset(f,0,sizeof(f));
    int x = _next_[sz];
    while(x>0) {
        f[sz-x] = 1; // p{[sz-x,sz)} == p{[0,x)}
        x = _next_[x];
    }
}

int main(int argc, char const *argv[])
{
    string p;
    while(cin>>p) {
        getFail(p);
        int sz = p.size();
        for(int i = 0; i < sz; i++) if(f[i]){
            cout<<p.substr(i,sz-i)<<endl;
        }
    }
    return 0;
}

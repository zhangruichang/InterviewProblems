#include <bits/stdc++.h>
#define foreach(it,v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
using namespace std;
typedef long long ll;
const int mod = 9973;
const int maxn = 5000000 + 4;
template<typename T>
struct Matrix
{
	int row,colunm;
	T **a;
	Matrix(int n = 1,int m = 1):row(n),colunm(m) {
		a = new T *[n];
		for(int i = 0; i < row; i++) {
			a[i] = new T [m];
			for(int j = 0; j < colunm; j++)
				a[i][j] = 0;
		}
	}
	~Matrix() {
		for(int i = 0; i < row; i++) delete [] a[i];
		delete [] a;
	}
	void debug()
	{
		for(int i = 0; i < row; i++)
			for(int j = 0; j < colunm; j++)
				cout<<a[i][j]<<" \n"[j+1==colunm];
	}
	T * & operator [](const int & i)
	{
		return a[i];
	}
    Matrix<T> operator *(const Matrix<T> & rhs) const
    {
    	if(colunm!=rhs.row) {
    		printf("Multiply the size of (%d,%d) and (%d,%d)\n",row,colunm,rhs.row,rhs.colunm);
    		exit(-1);
    	}
        Matrix<T> c(row,rhs.colunm);
        for(int k = 0; k < colunm; ++k) {
            for(int i = 0; i < row; ++i) {
                T r = this->a[i][k];
                for(int j = 0; j < rhs.colunm; ++j) {
                	//cout<<r<<" "<<rhs.a[k][j]<<" "<<c[i][j]<<" "<<mod<<endl;
                    c[i][j] += r*rhs.a[k][j];
                    if(mod)c[i][j] %= mod;
                }
            }
        }
        c.debug();
        return c;
    }
    void one()
    {
    	for(int i = 0;i < row; i++)
    		for(int j = 0; j < colunm; j++)
    			a[i][j] = T(i==j);
    }
};
template<typename T>Matrix<T>  quick_exp(const Matrix<T> &a,int n)
{
    Matrix<T>res(a.row,a.colunm);
    res.one();
    Matrix<T> base(a.row,a.colunm);
    base = a;
    while(n>0) {
        if(n&1) res = res*base;
        base = base * base;
        //base.debug();
        n >>= 1;
    }
    return res;
}
int main(int argc, char const *argv[])
{

#ifndef ONLINE_JUDGE
    freopen ("in.txt" , "r" , stdin);
    //freopen ("out.txt" , "w" , stdout);
#endif

	int n,k;
	while(scanf("%d%d",&n,&k)==2) {
		Matrix<int>A(n,n);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				scanf("%d",&A[i][j]);
		Matrix<int> ans = quick_exp<int>(A,k);
		int res = 0;
		for(int i = 0; i < n; i++) {
			res += ans[i][i];
		}
		printf("%d\n", res%mod);
	}
	return 0;
}

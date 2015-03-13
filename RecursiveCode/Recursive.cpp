http://www.cnblogs.com/archimedes/p/recursive-practice.html

int Bin(int a[], int low, int high, int x)
{
	if(low>high) return -1;
	int mid=(low+high)/2;
	if(==) return mid;
	else if(a[mid]<x) return Bin(a, mid+1, high, x);
	else return Bin(a, low, mid-1, x);
}

void reverse(char* s, int low, int high)
{
	if(low>=high) return ;
	swap(s[low], s[high]);
	reverse(s, low+1, high-1);
}

int gcd(int m, int n)
{
	if(!m) return n;
	return gcd(n%m, m);
}

int Dig(int n)
{
	if(n<10) return n;
	return Dig(n/10)+n%10;
}

int DigRoot(int n)
{
	int sum=Dig(n);
	if(sum<10) return sum;
	return DigRoot(sum);
}
/*
{
	int sum=Dig(n);
	while(sum>=10)
	{
		sum=Dig(n);
		/*
		int tmp=sum;
		while(tmp>0)
			sum+=tmp%10, tmp/=10;
		
	}
	return sum;
}*/
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

int binaryExponentiation(int x,int n,int m)
{
	if(n==0) return 1;
	if(n==1) return x%m;
	if(x==1) return 1;
	int base = x, ans = 1;
	while(n > 0)
	{
		if(n%2 == 1) //odd
		{
			ans = (ans*base)%m;
			n--;
		}
		else //even
		{
			base = (base*base)%m;
			n/=2;
		}
	}
	return ans;
}

int main()
{
	fio;
	
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
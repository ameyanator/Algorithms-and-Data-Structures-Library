#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

const int msz=2e4+1;
vector<int> seen(msz);
vector<int> primes;

void shieve(int n)
{
	for(int i=3;i*i<=n;i+=2)
	{
		if(!seen[i])
		{
			for(int j=i*2;j<=n;j+=i)
			{
				seen[j]=1;
			}
		}
	}
	primes.push_back(2);
	for(int i=3;i<=n;i+=2)
	{
		if(!seen[i]) primes.push_back(i);
	}
}

int main()
{
	fio;
	
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
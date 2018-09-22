#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

/*
	Question - Find the maximum subarray sum.

	Logic - Find the max subarray sum ending at each
		i and answer is the max of them

		for any i max subarray sum ending at i has 2
		options
			i) it is max subarraysum(i-1) + a[i]
			ii) it is a[i]
*/

int kadane(int a[],int n)
{
	// if all negative then initalize to different values
	int sum = 0, best = 0;
	for(int i = 0; i < n; i++)
	{
		sum = max(a[i],sum+a[i]);
		best = max(sum,best);
	}
	return best;
}

int main()
{
	fio;
	
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

/*
	Overview
		The unbounded knapsack problem differs from 
		classical knapsack as in here we are allowed
		to use multiple instances of an item.

	Problem Description
		Given a knapsack weight *W* and a set of *n*
		items with a certain value *vali* and *wti*
		we need to calculate the maximum amount that
		could make up this quantity exactly. We are
		allowed to use multiple instances of the same
		item.

	Logic and Thinking
		Have a simple 1D array dp[W+1] such that
		dp[i] stores the maximum value which can be
		achieved using all the items and i capacity
		of knapsack. 

		dp[0] = 0
		dp[i] = max(dp[i],dp[n-wt[j]]+val[j])
				where j varies from 0 to n-1
				such that wt[j]<=i
		ans = dp[W]
*/

const int INF = 2e9+1;

map<int,int> memo;

int unboundedKnapsackMinTopDown(int W,int n,int val[],int wt[])
{
	//make sure to clear the memo for each test case
	if(W < 0) return INF;
	if(W == 0) return 0;
	if(memo.find(W) != memo.end()) return memo[W];
	int ans = INF;
	for(int i = 0; i < n; i++)
	{
		if(wt[i] <= W)
		{
			ans = min(ans,solve(W-wt[i],n,val,wt) + val[i]);
		}
	}
	return memo[W] = ans;
}

int unboundedKnapsackMaxTopDown(int W,int n,int val[],int wt[])
{
	//make sure to clear the memo for each test case
	if(W < 0) return -INF;
	if(W == 0) return 0;
	if(memo.find(W) != memo.end()) return memo[W];
	int ans = -INF;
	for(int i = 0; i < n; i++)
	{
		if(wt[i] <= W)
		{
			ans = max(ans, solve(W-wt[i],n,val,wt) + val[i]);
		}
	}
	return memo[W] = ans;
}

int unboundedKnapsackMaxBottomUp(int W,int n,int val[],int wt[])
{
	//handle edge cases such as not possible
	int dp[W+1];
	for(int i = 0; i <= W; i++) dp[i] = 0;

	int ans = 0;

	for(int i = 0; i <= W; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(wt[j] <= i)
			{
				dp[i] = max(dp[i],dp[i - wt[j]] + val[j]);
			}
		}
	}

	return dp[W];
}

int main()
{
	fio;
	
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

const int msz=1000;
vector<int> g[msz];
int level[msz];
bool visited[msz];

void dfs(int s)
{
	visited[s]=true;
	for(int i=0;i<g[s].size();i++)
	{
		if(visited[g[s][i]]==false)
		{
			level[g[s][i]]=level[s]+1;
			dfs(g[s][i]);
		}
	}
}

int main()
{
	fio;
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int source;
	cin>>source;
	dfs(source);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

const int msz=1000;
vector<int> g[msz];
bool visited[msz];
int level[msz];

void bfs(int s)
{
	visited[s]=true;
	queue<int> q;
	q.push(s);
	level[s]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int i=0;i<g[node].size();i++)
		{
			if(visited[g[node][i]]==false)
			{
				visited[g[node][i]]=true;
				q.push(g[node][i]);
				level[g[node][i]]=level[node]+1;
			}
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
	bfs(source);
	return 0;
}
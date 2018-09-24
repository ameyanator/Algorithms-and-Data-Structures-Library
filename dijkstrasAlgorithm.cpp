#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

const int msz = 1e4+1;
vector<pair<int,int> > g[msz];
vector<int> dist(msz);
vector<bool> visited(msz);
int INF = 2e9+1;

void initialize()
{
	visited.assign(msz,0);
	dist.assign(msz,INF);
	for(int i=0;i<msz;i++)
	{
		g[i].clear();
	}
}

void dijkstra(int s)
{
	dist[s]=0;
	multiset<pair<int, int> > mst;
	mst.insert({dist[s],s});
	while(!mst.empty())
	{
		pair<int,int> node = *mst.begin();
		mst.erase(mst.find(*mst.begin()));
		int x = node.second;
		int weight = node.first;
		if(visited[x]) continue;
		visited[x] = true;
		for(auto y: g[x])
		{
			int to = y.first;
			int w = y.second;
			if(dist[x] + w < dist[to])
			{
				dist[to] = dist[x] + w;
				mst.insert({dist[to],to});
			}
		}
	}
}

int main()
{
	fio;
	
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
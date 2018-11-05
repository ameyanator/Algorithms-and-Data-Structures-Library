#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

string suffix(int i,string s)
{
	return s.substr(i,s.length()-i+1);
}

const int msz = 1e5+1;
const int mszlg = log2(msz) + 1;
int sortIndex[mszlg][msz];

int findLCP(int i,int j,int N,int step)
{
	if(i==j) return N-i+1;
	int lcp = 0;
	for(int k = step;k>=0;k--)
	{
		if(sortIndex[k][i] == sortIndex[k][j])
		{
			lcp+=(int)pow(2,k);
			i+=(int)pow(2,k);
			j+=(int)pow(2,k);
		}
	}
	return lcp;
}

int main()
{
	fio;
	string s;
	cin>>s;
	int N = s.length();
	for(int i=0;i<(int)ceil(log2(N))+2;i++)
	{
		for(int j=0;j<N;j++) sortIndex[i][j] = 0;
	}
	for(int i = 0; i < N; i++)
	{
		sortIndex[0][i] = s[i] - 'a';
	}
	int doneTill = 1;
	int step = 1;
	while(doneTill < N)
	{
		vector<pair<int, pair<int,int> > > L(N);
		for(int i=0;i<N;i++)
		{
			//here at step we have sorted till the first doneTill characters
			//now we want to sort for each index i : i+doneTill+doneTill characters
			//we do that by tuple (indexOf(i:i+doneTill-1), indexOf(i+doneTill:i+doneTill+doneTill-1))
			L[i] = {sortIndex[step-1][i],{ (i+doneTill < N ? sortIndex[step-1][i+doneTill] : -1) ,i}};
		}
		sort(L.begin(),L.end());
		for(int i=0;i<N;i++)
		{
			//if ((i:i+doneTill-1) and (i+doneTill:i+doneTill+doneTill-1)) are equal then we assign the same index otherwise we assign i which is now the order in which it comes after sorting
			sortIndex[step][L[i].second.second] = L[i].first == L[i-1].first and L[i].second.first == L[i-1].second.first ? sortIndex[step][L[i-1].second.second] : i ;
		}
		step++;
		doneTill*=2;
	}
	vector<pair<string,int> > v;
	vector<int> suffixArray(N); //suffixArray[i] denotes that the ith suffix starts at index suffixArray[i] in the string
	for(int j=0;j<N;j++)
	{
		v.push_back({suffix(j,s),sortIndex[step-1][j]});
		cout<<sortIndex[step-1][j]<<" ";
		suffixArray[sortIndex[step-1][j]] = j;
	}
	cout<<endl;
	sort(v.begin(),v.end());
	for(auto x:v)
	{
		cout<<x.first<<" "<<x.second<<endl;
	}
	cout<<"suffixArray"<<endl;
	for(int x:suffixArray) cout<<x<<" ";
		cout<<endl;
	vector<int> lcp(N);
	for(int i=1;i<N;i++)
	{
		lcp[i] = findLCP(i-1,i,N,step-1);
	}
	cout<<"LCP"<<endl;
	for(int x:lcp) cout<<x<<" ";
		cout<<endl;
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
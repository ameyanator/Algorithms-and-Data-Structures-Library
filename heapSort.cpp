#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long int lli;

int parent(int i)
{
	return floor(i/2.0);
}

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return 2*i+1;
}

int heapsize;

void max_heapify(vector<int> &a,int i)
{
	int l=left(i);
	int r=right(i);
	int largest=i;
	if(l<=heapsize and a[l]>a[largest]) largest=l;
	if(r<=heapsize and a[r]>a[largest]) largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		max_heapify(a,largest);
	}
}

void build_max_heap(vector<int> &a,int n)
{
	heapsize=n;
	for(int i=floor(n/2.0);i>=1;i--)
		max_heapify(a,i);
}

void heapsort(vector<int> &a,int n)
{
	build_max_heap(a,n);
	for(int i=n;i>=2;i--)
	{
		swap(a[1],a[i]);
		heapsize--;
		max_heapify(a,1);
	}
}

int main()
{
	fio;
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	heapsort(a,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
	return 0;
}
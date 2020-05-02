#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n,q;
	cin>>n>>q;
	int a[n],pref[n];
	memset(pref,0,sizeof(pref));
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int aa,b;
	while(q--)
	{
		cin>>aa>>b;
		pref[--aa]++;
		if(b<n)pref[b]--;
	}
	for(int i=1;i<n;i++)
	{
		pref[i]+=pref[i-1];
	}
	sort(pref,pref+n,greater<int>());
	sort(a,a+n,greater<int>());
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=pref[i]*a[i];
	}
	cout<<sum;
	
}

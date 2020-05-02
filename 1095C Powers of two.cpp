#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main()
{	ios::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	int i=0;
	queue<int>q;
	while(n)
	{
		if(n&1){
			if(i>0)q.push(i);	
			mp[i]++;
		}
		i++;
		n>>=1;
	}
	if(mp.size()>k)
	{
		cout<<"NO";
		return 0;
	}
	int z =mp.size();
	while(z<k && !q.empty())
	{
		int u = q.front();
		mp[u]--;
		q.pop();
		mp[u-1]+=2;
		if(u-1>0)
		{
			q.push(u-1);
			q.push(u-1);
			}	
		z++;
	}
	if(z<k)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(auto u:mp)
	{
		while(u.second--)
		{
			cout<<((long long)1<<u.first)<<" ";
		}
	}
}


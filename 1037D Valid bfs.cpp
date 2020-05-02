#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200010],ans;
int order[200010],rel[200010];
bool vis[200010];
bool compare(int a,int b)
{
	return rel[a]<rel[b];
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		cin>>order[i];
		rel[order[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		sort(adj[i].begin(),adj[i].end(),compare);
	}
	queue<int>q;
	q.push(1);
	vis[1]=true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x]=true;
		ans.push_back(x);
		for(auto u:adj[x])
		{
			if(!vis[u])
			q.push(u);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(order[i]!=ans[i])
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
}

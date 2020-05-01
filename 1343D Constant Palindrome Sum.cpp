#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		vector<int>cnt(2*k+1),pref(2*k+2);
		//COUNTING ALL THE PAIRS HAVING SUM X
		for(int i=0;i<n/2;i++)
		{
			++cnt[a[i]+a[n-i-1]];
		}
		//FINDING MINIMUM AND MAXIMUM VALUE OF A PAIR
		//ADDING 1 TO LEFT BOUNDARY AND -1 TO THE (RIGHT BOUNDARY +1)
		for(int i=0;i<n/2;i++)
		{
			int minv = min(a[i],a[n-i-1])+1;
			int maxv = max(a[i],a[n-i-1])+k;
			++pref[minv];
			--pref[maxv+1];
		}
		for(int i=1;i<2*k+2;i++)
		pref[i]+=pref[i-1];
		int sum =1e9;

		for(int i=2;i<=2*k;i++)
		{
			sum= min(sum,pref[i]-cnt[i]+((n/2)-pref[i])*2);
		}
		cout<<sum<<"\n";
	}
}

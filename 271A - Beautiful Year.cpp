//45551082	 2018-11-11   08:21:04   vvp_15	   271A - Beautiful Year   GNU     C++14   	Accepted	    62 ms     	0 KB
#include<iostream>
using namespace std;
int main()
{
	int n,a,b,c,d;
	cin>>n;
	for(int i=n+1;i<10000;i++)
	{  int t=i;
	    a=t%10;
		t/=10;
		b= t%10;
		t/=10;
		c=t%10;
		t/=10;
		d=t;
   if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
    {  
	  cout<<i;
	  return 0;
      } 
    else
    continue;
}
}

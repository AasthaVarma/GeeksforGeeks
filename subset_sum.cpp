#include<bits/stdc++.h>
#define  ll long long
using namespace std;

ll int util(ll int a[], ll int n, ll int sum)
{
	if(sum==0)
		return 1;
	if(n==0 && sum!=0)
		return 0;
	return util(a, n-1, sum) + util(a, n-1, sum-a[n-1]);		
}

int main()
{
	ll int t;
	cin >> t;
	while(t--)
	{
		ll int n;
		cin >> n;
		ll int a[n];
		for(ll int i=0; i<n; i++)
			cin >> a[i];
		ll int sum;
		cin >> sum;
		
		cout << util(a, n, sum) << endl;
	}
	return 0;
}

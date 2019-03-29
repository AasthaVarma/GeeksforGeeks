#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll int solve(ll int a[], ll int n)
{
	vector<ll int> l(n, 1);
	int len=0;
	
	for(ll int i=1; i<n; i++)
	{
		for(ll int j=0; j<i; j++)
		{
			if(a[i]>a[j] && (i-j)<=(a[i]-a[j]))
				l[i] = max(l[i], l[j]+1);
		}
	}
	
	len = max(len, *max_element(l.begin(), l.end()));
	
	return (n-len);
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
			
		cout << solve(a, n) << endl;
	}
	return 0;
}

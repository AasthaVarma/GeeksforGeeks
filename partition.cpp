#include<bits/stdc++.h>
#define  ll long long
using namespace std;

bool solve(int a[], int n, int sum)
{
	bool s[sum+1][n+1];
	for(int i=0; i<=n; i++)
		s[0][i] = true;
		
	for(int i=1; i<=sum; i++)
		s[i][0] = false;
		
	for(int i=1; i<=sum; i++)
	{
		for(int j=1; j<=n; j++)
		{
			s[i][j] = s[i][j-1];
			if(i >= a[j-1])
				s[i][j] = s[i][j] || s[i-a[j-1]][j-1];
		}
	}
	
	return s[sum][n];
}
bool util(int a[], int n)
{
	int sum=0;
	for(int i=0; i<n; i++)	
		sum += a[i];
		
	if(sum%2!=0)
		return false;
	
	return solve(a, n, sum/2);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
	    int a[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
		if(util(a, n))
		cout << "YES" << endl;
		else
		cout << "NO" << endl;
	}
	return 0;
}

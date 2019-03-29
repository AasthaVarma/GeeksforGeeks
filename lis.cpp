#include<bits/stdc++.h>
using namespace std;

int solve(int a[], int n)
{
	vector<int> l(n, 1);
	int len=0;
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[i]>a[j])
				l[i] = max(l[i], l[j]+1);
		}
	}
	
	len = *max_element(l.begin(), l.end());
	return len;
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
			
		cout << solve(a, n) << endl;
	}
	return 0;
}

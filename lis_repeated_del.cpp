#include<bits/stdc++.h>
#define pb push_back
using namespace std;

void print(vector<int> a)
{
	for(int i=0; i<a.size(); i++)
		cout << a[i] << " ";
	cout <<"\n";
}
void printLIS(vector<int> a, int n)
{
	if(n==0)
	{
		cout << -1 << "\n";
		return;
	}
	int l[n];
	for(int i=0; i<n; i++)
		l[i]=1;
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[i] > a[j])
				l[i] = max(l[i], l[j]+1);
		}
	}
	int flag=0;
	for(int i=0; i<n; i++)
	{
		if(l[i]!=1)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		print(a);
		return;
	}
	/*
	for(int i=0; i<n; i++)
		cout << a[i] << " ";
	cout << "\n";
	for(int i=0 ;i<n; i++)
		cout << l[i] << " ";
	cout << "\n\n" ;
	*/
	
	int length = *max_element(l, l+n);
	int index = max_element(l, l+n)-l;
	
	//cout << index << " -> " << a[index] << "\n";
	a[index] = 0;
	while(length!=0)
	{
		for(int i=0; i<index; i++)
		{
			if(l[i] == length-1)
			{
				index = i;
				//cout << index << " -> " << a[i] << "\n";
				a[i]=0;
				break;
			}
		}
		length--;
	}
	
	vector<int> b;
	for(int i=0; i<n; i++)
	{
		if(a[i]!=0)
			b.push_back(a[i]);
	}
	a = b;
	/*
	cout << "\n";
	for(int i=0; i<a.size(); i++)
		cout << a[i] << " ";
	cout << "\n\n\n";
	*/
	printLIS(a, a.size());
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n, x;
		cin >> n;
		vector<int> a ;
		for(int i=0; i<n; i++)
		{
			cin >> x;
			a.pb(x);
		}
		printLIS(a, n);
		
	}		
	return 0;
}

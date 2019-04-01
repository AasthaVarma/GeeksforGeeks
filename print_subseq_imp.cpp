#include<bits/stdc++.h>
using namespace std;
bool comp(string a, string b)
{
	return a.length() < b.length();
}
set<string> v;
void substrings(string s)
{
	int n = s.length();
	for(int i=0; i<n; i++)
	{
		for(int j=n; j>i; j--)
		{
			int len = j-i;
			string sub_str = s.substr(i, len);
			v.insert(sub_str);
			for(int k=1; k<sub_str.length(); k++)
			{
				string sb = sub_str;
				sb.erase(find(sb.begin(), sb.end(), sb[k-1]));
				substrings(sb);
			}
		}
	}
	
}
int main()
{
	string s = "abcd";
	substrings(s);
	set<string> ::iterator it;
	sort(s.begin(), s.end());
	for(it=v.begin(); it!=v.end(); it++)
		cout << *it << " ";
	cout << "\n";
	return 0;
}

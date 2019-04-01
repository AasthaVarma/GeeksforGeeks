#include<bits/stdc++.h>
#define MAX 4
using namespace std;

void print(int a[MAX][MAX])
{
	for(int i=0; i<MAX; i++)
	{
		for(int j=0; j<MAX; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void print_ans(int mat[MAX][MAX], int len[MAX][MAX], int index)
{
	int val = len[0][index] - mat[0][index];
	int j = index;
	for(int i=0; i<MAX-1; i++)
	{
		cout << mat[i][j] << " + ";
		if(val == len[i+1][j-1])
			j=j-1;
		else if(val == len[i+1][j+1])
			j = j+1;
		val  = val - mat[i+1][j];
		if(val==0)
		{
			cout << mat[i+1][j] << endl;
			break;
		}
		
	}
}
int solve(int mat[MAX][MAX])
{
	int dp[MAX][MAX];
	memset(dp, 0, sizeof(dp));
	for(int i=MAX-1; i>=0; i--)
	{
		for(int j=MAX-1; j>=0; j--)
		{
			int l_d = (j==0||i==MAX-1)?0:dp[i+1][j-1];
			int d = (i==MAX-1)?0:dp[i+1][j];
			int r_d =(j==MAX-1||i==MAX-1)?0:dp[i+1][j+1];
			dp[i][j] = mat[i][j] + max(l_d, max(d, r_d));
		}
	}
	int res = dp[0][0], index=0;
	for(int j=1; j<MAX; j++)
	{
		res = max(res, dp[0][j]);
		if(res == dp[0][j])
			index = j;
	}
	//cout << "index: " << index << endl;
	//cout << "MATRIX:" << endl;
	//print(dp);
	//cout << endl;
	print_ans(mat, dp, index);
	return res;
}
int main()
{
	int mat[4][4] = {{4, 2, 3, 4},
					 {2, 9, 10, 10},
					 {15, 1, 3, 10},
					 {16, 92, 41, 104}};
					 
	cout << solve(mat);
	
	return 0;
}

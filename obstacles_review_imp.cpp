//C++ Code to find the number of unique paths in a matrix with obstacles
#include<bits/stdc++.h>
using namespace std;

const int m=3;
const int n=3;
/*
	mat  : mXn matrix
	i, j : current coordinates
	m, n : dimensions of given matrix
*/
int countAllPathsUtil(int mat[m][n], int i, int j, int m, int n)
{
	// we hit an obstacle so retrace back i.e, don't count this path
	if(mat[i][j] == 1)
		return 0;
	// It's the last row we can only move right
	if(i==m-1)
	{
		for(int k=j; k<n; k++)
		{
			//we hit an obstacle so retrace back
			if(mat[i][k] == 1)
				return 0;	
		}
		return 1;
	}
	//It's the last column we can only move downw
	if(j==n-1)
	{
		for(int k=i; k<m; k++)
		{
			//we hit an obstacle so retrace back
			if(mat[k][j] == 1)
				return 0;
		}
		return 1;
	}
	
	//countAllPathsUtil(mat, i+1, j, m, n) --- Move down 
	//countAllPathsUtil(mat, i, j+1, m, n) --- Move right 
	return countAllPathsUtil(mat, i+1, j, m, n) + countAllPathsUtil(mat, i, j+1, m, n);
}
// This function counts all the possible paths from top left to bottom right 
int countAllPaths(int mat[m][n])
{
	if(mat[0][0]==1)
		return 0;
	return countAllPathsUtil(mat, 0, 0, m, n);
}
// Driver Program
int main()
{
	int mat[m][n] = {{0, 0, 0},
					 {0, 1, 0},
					 {0, 0, 0}
					};
	
	cout << countAllPaths(mat) << endl;
	return 0;
}

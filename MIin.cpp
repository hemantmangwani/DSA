//min cost path dp
#include<bits/stdc++.h>
using namespace std;

int cost[1000][1000];

int solve (int n,int m,int pos_x,int pos_y) {
	
	int dp[n][m];
	dp[0][0] = cost[0][0];
	for (int i=1;i<n;i++) {
		dp[i][0] = dp[i-1][0] + cost[i][0];
	}
	for (int i=1;i<m;i++) {
		dp[0][i] = dp[0][i-1] + cost[0][i];
	}
	for (int i=1;i<n;i++) {
		for (int j=1;j<m;j++) {
			dp[i][j] = min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1])) + cost[i][j];
		}
	}
	
	return dp[pos_x][pos_y];
}

int main () {
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin>>cost[i][j];
		}
	}
	int pos_x,pos_y;
	cin>>pos_x>>pos_y;
	cout<<solve(n,m,pos_x,pos_y);
}

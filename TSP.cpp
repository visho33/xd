#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > dis;
vector<vector<int> > dp;

int DP(int conjunto, int ultimo){
	
	if(dp[conjunto][ultimo]!=-1){
		return dp[conjunto][ultimo];
	}
	int desactivado = conjunto & + ~(1<<ultimo);
	dp[conjunto][ultimo] = 1e9;
	
	for(int i = 0; i<n; i++){
	
		if(desactivado & (1<<i) != 0){
			dp[conjunto][ultimo] = min(dp[conjunto][ultimo], DP(desactivado,i) + dis[i][ultimo]);
		}
		
	}
	
	return dp[conjunto][ultimo];
}

int main(){
	int inicio;
	cin>>n>>inicio;
	
	dis.resize(n, vector<int> (n));
	dp.resize(1<<n, vector<int> (n, -1));	
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n; j++){
			int c; cin>>c;
			dis[i][j] = c;
		}
	}
	
	dp[1<<inicio][inicio] = 0;
	
	int mini = 1e9;
	for(int i = 0; i<n; i++){
		mini = min(mini, DP((1<<n) - 1, i) + dis[i][inicio]);
	}
	
	cout<<mini;
	
	return 0;
}

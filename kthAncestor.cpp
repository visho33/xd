#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > ancestro;
vector<vector<int> > edges;

void dfs(int u, int e){
	ancestro[u][0] = e;
	for(int i = 0; i<edges[u].size();i++){
		if(edges[u][i]!=e)dfs(edges[u][i],u);
	}
	return;
}

int ancestor(int u, int n){
	
	for(int k = 0; (1<<k) <= n; ++k) {
		if(((1<<k)&n) != 0) {
			u = ancestro[u][k];
		}
	}

	return u;
}

int main(){
	
	int v, r, q;
	cin>>v>>r>>q;
	
	int k = 1;
	int l = 0;
	while(k<v){
		k = k*2;
		l++;
	}
		
	ancestro.resize(v+1,vector<int>(l+1,0));
	edges.resize(v+1,vector<int>(0));
	
	for(int i = 0; i<v-1; i++){
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	dfs(r,0);
	
	for(int i = 1; i<l; i++){
		for(int j = 0; j<=v; j++){
			ancestro[j][i] = ancestro[ancestro[j][i-1]][i-1];
		}
	}
	
	while(q--){
		int a, b;
		cin>>a>>b;
		cout<<ancestor(a,b)<<endl;
	}
		
	return 0;
}

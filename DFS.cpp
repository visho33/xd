#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;
vector<bool> visitado;

void dfs(int u){
	
	for(int i = 0; i<edges[u].size();i++){
		if(visitado[edges[u][i]] == false){
			visitado[edges[u][i]] = true;
			dfs(edges[u][i]);
		}
	}
	
	
	return;
}

int main(){
	
	int v, e;
	cin>>v>>e;
	edges.resize(v+1,vector<int>(0));
	visitado.resize(v+1,false);
	
	for(int i = 0; i<e; i++){
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	
	
	visitado[1] = true;
	dfs(1);
	
	for(int i = 0; i<=v; i++){
		if(visitado[i]) cout<<i<<" ";
	}
	
	
	return 0;	
}

#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;
vector<int> subtree;

void dfs(int s, int e){
	subtree[s] = 1;
	for(int i = 0; i<edges[s].size();i++){
		if(edges[s][i]==e) continue;
		dfs(edges[s][i],s);
		subtree[s]+=subtree[edges[s][i]];
	}
	
	return;
}

int main(){
	
	int v, raiz;
	cin>>v>>raiz;
	
	edges.resize(v+1,vector<int>(0));
	subtree.resize(v+1,0);
	
	for(int i = 0; i<v-1; i++){
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	dfs(raiz,0);
	
	for(int i = 1; i<subtree.size();i++){
		cout<<subtree[i]<<" ";
	}
	
	
	return 0;
}

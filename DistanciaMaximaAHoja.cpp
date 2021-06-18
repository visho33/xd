#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;
vector<int> leaflenght;

void dfs(int s, int e){
	
	leaflenght[s] = 0;
	for(int i = 0; i<edges[s].size();i++){
		if(edges[s][i]==e) continue;
		dfs(edges[s][i],s);
		leaflenght[s]=max(leaflenght[s], leaflenght[edges[s][i]]+1);
	}
	
	return;
}

int main(){
	
	int v, raiz;
	cin>>v>>raiz;
	
	edges.resize(v+1,vector<int>(0));
	leaflenght.resize(v+1);
	
	for(int i = 0; i<v-1; i++){
		int a, b;
		cin>>a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	dfs(raiz,0);
	
	for(int i = 1; i<leaflenght.size();i++){
		cout<<leaflenght[i]<<" ";
	}
	
	
	return 0;
}

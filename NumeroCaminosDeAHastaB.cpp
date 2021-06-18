#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > edges;
vector<int> caminos;

int camino(int u){
	
	if(caminos[u]!=-1) return caminos[u];
	
	caminos[u] = 0;
	for(int i = 0; i<edges[u].size();i++){
		caminos[u] += camino(edges[u][i]);
	}
	return caminos[u];
	
}

int main(){
	
	int v, e, inicio, fin;
	cin>>v>>e>>inicio>>fin;
	
	edges.resize(v+1,vector<int>(0));
	caminos.resize(v+1,-1);
	for(int i = 0; i<e; i++){
		int a, b;
		cin>>a>>b;
		edges[b].push_back(a);
	}
	
	caminos[inicio] = 1;
	
	cout<<camino(fin);
	
	
	return 0;
}

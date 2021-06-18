#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<vector<int> > edges;
vector<int> tin;
vector<int> low;
vector<ii> puentes;
int tiempo = 0;

void dfs(int v, int e){
	
	tin[v] = tiempo;
	low[v] = tiempo;
	tiempo++;
	
	for(auto vertice: edges[v]){
		
		if(vertice == e) continue;
		
		if(tin[vertice] != -1){
			low[v] = min(low[v], tin[vertice]);	
		}
		else{
			dfs(vertice, v);
			low[v] = min(low[v], low[vertice]);
			
			if(low[vertice] > tin[v]){
				ii x(v+1, vertice+1);
				puentes.push_back(x);
			}
			
		}
		
	}

	return;
}

int main(){
	
	int n, m;
	cin>>n>>m;
	edges.resize(n);
	tin.resize(n, -1);
	low.resize(n, -1);
	
	for(int i = 0; i<m; i++){
		int a, b;
		cin>>a>>b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}
	
	dfs(0, -1);
	cout<<puentes.size()<<"\n";
	for(int i = 0; i<puentes.size(); i++){
		cout<<puentes[i].first<<" "<<puentes[i].second<<"\n";
	}
	
	return 0;
}

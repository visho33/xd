#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> P, G;
vector<int> L;
int N, M, K;

int raise(int u, int n) {

	for(int k = 0; (1<<k) <= n; ++k) {
		if(((1<<k)&n) != 0) {
			u = P[k][u];
		}
	}

	return u;
}

int lca(int u, int v) {

	if(L[u] < L[v]) swap(u, v);

	int delta = L[v] - L[u];
	if(delta != 0) u = raise(u, delta);

	// Despues de eso, estan en el mismo nivel

	for(int k = K-1; k >= 0; --k) {
		if(P[k][u] != P[k][v]) {

			u = P[k][u];
			v = P[k][v];
		}
	}

	while(u != v) {
		u = P[0][u];
		v = P[0][v];
	}

	return u;
}

int dist(int u, int v) {
	return L[u] + L[v] - 2*L[lca(u,v)];
}

int main(){
	
	int v, raiz;
	cin>>v>>raiz;
	G.resize(v+1);
	L.resize(v+1, -1);

	K = int(log2(N))+3;
	P.resize(K, vector<int>(N, 0));

	for(int i = 0; i < M; ++i){
		
		int u, v; cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	queue<int> Q;
	Q.push(0);

	L[0] = 0;
	P[0][0] = 0;

	while(!Q.empty()) {
		int u = Q.front(); Q.pop();

		for(int v : G[u]) {
			if(L[v] == -1) {
				L[v] = L[u] + 1;
				P[0][v] = u;
				Q.push(v);
			}
		}
	}

	for(int k = 1; k < K; ++k) {
		for(int u = 0; u < N; ++u) {
			P[k][u] = P[k-1][P[k-1][u]];
		}
	}
	
	return 0;
}

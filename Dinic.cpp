#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct Dinic {
    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vector<ll> D;
    vector<int> q, W;
    bool bfs(int s, int t) {
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l) {
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f) {
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i) {
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void add_edge(int u, int v, ll cap) {
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // Use cap instead of 0 if bidirectional
    }
    
    ll max_flow(int s, int t) {
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};

void solve(int n, int m, int g){
	
	vector<int> puntos(n, 0);
    vector<vector<int> > partidos(n, vector<int> (n));
    
    for(int i = 0; i<g; i++){
    	int a, b; char c;
    	cin>>a>>c>>b;
    	partidos[a][b]++;
    	partidos[b][a]++;
    	if(c == '<'){
    		puntos[b]+=2;
		}
		if(c == '>'){
			puntos[a]+=2;
		}
		if(c == '='){
			puntos[a]+=1;
			puntos[b]+=1;
		}
	}
	
	for(int i = 1; i<n; i++){
		if(partidos[0][i] < m){
			g = g + (m-partidos[0][i]); 
			puntos[0] += 2*(m-partidos[0][i]);
			partidos[0][i] = m;
			partidos[i][0] = m;
		}
	}
	
	for(int i = 1; i<n; i++){
		if(puntos[i]>=puntos[0]){
			cout<<"N\n";
			return;
		}
	}
	
	
    int r = m*(n*(n-1))/2 - g;    
    Dinic din(r+n+2);
    
    for(int i = 1; i<n; i++){
    	din.add_edge(r+1+i, 1, puntos[0]-puntos[i]-1);
	}
    
    int xd = 2;
    
    //s = 0, r = 1, m = 2, 3, 4, 5, 6, 7, 8, 9, 10, 11... r+1. (r+1)+i
    for(int i = 0; i<n; i++){
    	for(int j = i+1; j<n; j++){
    		if(i == j) continue;
    		while(partidos[i][j] < m){
    			din.add_edge(0, xd, 2);
    			din.add_edge(xd, r+1+i, 1000);
    			din.add_edge(xd, r+1+j, 1000);
    			xd++;
    			partidos[i][j]++;
			}
		}
	}
	
    int mf = din.max_flow(0,1);
    if(mf == r*2){
    	cout<<"Y\n";
	}
	else{
		cout<<"N\n";
	}
	
	return;
}

int main(){
    
    int n, m, g;
    
    while(true){
    	cin>>n>>m>>g;
    	if(n==0){
    		break;
		}
		else{
			solve(n, m, g);
		}
	}
    
    return 0;
}

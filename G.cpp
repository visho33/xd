#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<int> padre;
vector<int> size;

int findset(int u){
	
	if(u == padre[u]) return u;
	padre[u] = findset(padre[u]);
	return padre[u];
}

bool issameset(int u, int v){
	return findset(u)==findset(v);
}

void joinsets(int u, int v){
	if(issameset(u,v)) return;
	u = findset(u);
	v = findset(v);
	
	if(size[u]>=size[v]){
		padre[v] = u;
		size[u] += size[v];
	}
	else{
		padre[u] = v;
		size[v] += size[u];
	}
	
	return;
	
}

int setsize(int u){
	return size[findset(u)];
}

int main(){
	
	int n, m;
	cin>>n>>m;
	vector<vector<int> > edges(0);
	padre.resize(n+1);
	for(int i = 0; i<=n; i++){
		padre[i] = i;
	}
	
	size.resize(n+1,1);
	
	for(int i = 0; i<m; i++){
		int a, b;
		cin>>a>>b;
		vector<int> x(0);
		x.push_back(b);
		x.push_back(a-1);
		x.push_back(n);
		edges.push_back(x);
	}
	
	for(int i = 0; i<n; i++){
		int c; cin>>c;
		vector<int> x(0);
		if(i == n-1){
			x.push_back(c);
			x.push_back(i);
			x.push_back(0);
		}
		else{
			x.push_back(c);
			x.push_back(i);
			x.push_back(i+1);
		}
		edges.push_back(x);
	}
		
	sort(edges.begin(),edges.end());
	vector<vector<int> > newedges(0);
	
	for(int i = 0; i<edges.size(); i++){
		if(issameset(edges[i][1], edges[i][2]) == false){
			newedges.push_back(edges[i]);
			joinsets(edges[i][1],edges[i][2]);
		}
	}
	
	ll sum = 0;
	
	for(int i = 0; i<newedges.size();i++){
		sum = sum + newedges[i][0];
	}
	
	cout<<sum<<"\n";
	
	return 0;
}

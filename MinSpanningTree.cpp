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
	
	int v, e;
	cin>>v>>e;
	
	vector<vector<int> > edges(0);
	padre.resize(v+1);
	for(int i = 0; i<=v; i++){
		padre[i] = i;
	}
	
	size.resize(v+1,1);
	
	
	while(e--){
		int a, b, w;
		cin>>a>>b>>w;
		vector<int> x(0);
		x.push_back(w);
		x.push_back(a);
		x.push_back(b);
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
	
	for(int i = 0; i<newedges.size();i++){
		cout<<endl<<newedges[i][1]<<" "<<newedges[i][2]<<" "<<newedges[i][0];
	}
	
	return 0;
}

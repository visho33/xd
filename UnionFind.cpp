#include<bits/stdc++.h>
using namespace std;

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
	
	padre.resize(v+1);
	size.resize(v+1,1);
	
	for(int i = 0; i<=v; i++){
		padre[i] = i;
	}
	
	while(e--){
		int a, b;
		cin>>a>>b;
		joinsets(a,b);
	}
	
	for(int i = 0; i<=v; i++){
		cout<<padre[i]<<" ";
	}
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> ii;

int main(){
	
	int v, e;
	cin>>v>>e;
	vector<vector<ii> > edges(v);
	vector<ll> pesos(v, 1e9);
	pesos[0] = 0;
	
	for(int i = 0; i<e; i++){
		int a, b, c;
		cin>>a>>b>>c;
		ii x(c, a);
		ii y(c, b);
		edges[a].push_back(y);
		edges[b].push_back(x);
	}
	
	priority_queue<ii, vector<ii>, greater<ii> > q;
	pair<ll, int> inicio(0, 0);
	q.push(inicio);
	
	while(q.size()>0){
		
		pair<ll, int> x = q.top();
		q.pop();
		ll peso = x.first;
		int nodo = x.second;
		
		for(int i = 0; i<edges[nodo].size(); i++){
			
			if(pesos[edges[nodo][i].second]>pesos[nodo]+edges[nodo][i].first){
				
				pesos[edges[nodo][i].second] = pesos[nodo]+edges[nodo][i].first;
				pair<ll,int> nuevo(pesos[edges[nodo][i].second], edges[nodo][i].second);
				q.push(nuevo);
				
			}
			
		}
		
	}
	
	for(int i = 0; i<v; i++){
		cout<<pesos[i]<<" ";
	}
	
	return 0;
}

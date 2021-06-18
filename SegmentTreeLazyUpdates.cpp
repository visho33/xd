//Segment Tree (actualizaciones por rango)
#include<bits/stdc++.h>
using namespace std;

vector<int> ST;
vector<int> L;

void build(int node, int l, int r, vector<int> A){
	
	if(l==r){
		ST[node] = A[r];
		return;
	}
	
	build(2*node,l,(l+r)/2, A);
	build(2*node+1,(l+r)/2+1,r, A);
	
	ST[node] = min(ST[2*node],ST[2*node+1]);
	return;
	
}

int query(int node, int l, int r, int i, int j){
	
	if(L[node] != 0) {
			ST[node] += L[node];

			// Si no es hoja, pasar la marca
			if(l != r) {
				L[2*node] += L[node];
				L[2*node+1] += L[node];
			}

			L[node] = 0;
		}
	
	if(i <= l && r <= j) return ST[node];

	if(j < l || r < i) return INT_MAX;

	return min(query(2*node, l, (l+r)/2, i, j), query(2*node+1, (l+r)/2+1, r, i, j));
	
}

void update(int node, int l, int r, int i, int j, int x){
	
	if(L[node] != 0) {
			ST[node] += L[node];

			// Si no es hoja, pasar la marca
			if(l != r) {
				L[2*node] += L[node];
				L[2*node+1] += L[node];
			}

			L[node] = 0;
		}

		// Caso 1
		if(i <= l && r <= j) {
			ST[node] += x;

			if(l != r) {
				L[2*node] += x;
				L[2*node+1] += x;
			}

			return;
		}

		// Caso 2 
		if(j < l || r < i) return;

		// Caso 3
		update(2*node, l, (l+r)/2, i, j, x);
		update(2*node+1, (l+r)/2+1, r, i, j, x);

		ST[node] = min(ST[2*node], ST[2*node+1]);
		
		return;
	
}


int main(){
	
	int n,q;
	cin>>n>>q;
	vector<int> A;
	for(int i = 0; i<n; i++){
		int c; cin>>c;
		A.push_back(c);
	}
	ST.resize(4*n);
	L.resize(4*n,0);
	build(1, 0, n-1, A);
	while(q--){
		int a;
		cin>>a;
		if(a==0){
			int i,j, x;
			cin>>i>>j>>x;
			update(1,0,n-1,i,j,x);
		}
		if(a==1){
		int i, j;
		cin>>i>>j;
		cout<<query(1,0,n-1,i,j)<<endl;
		}
	}
	
	return 0;
}

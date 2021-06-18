//Segment Tree (actualizaciones puntuales)
#include<bits/stdc++.h>
using namespace std;

vector<int> ST;

void build(int node, int l, int r, vector<int> A){
	cout<<node<<endl;
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
	
	if(i <= l && r <= j) return ST[node];

	if(j < l || r < i) return INT_MAX;

	return min(query(2*node, l, (l+r)/2, i, j), query(2*node+1, (l+r)/2+1, r, i, j));
	
}

void update(int node, int l, int r, int i, int x){
	
	if(i<l||r<i) return;
	
	if(l==r){
		ST[node] = x;
		return;
	}
	
	update(2*node, l, (l+r)/2, i, x);
	update(2*node+1,(l+r)/2+1,r,i,x);
	
	ST[node] = min(ST[2*node],ST[2*node+1]);
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
	build(1, 0, n-1, A);
	while(q--){
		int a;
		cin>>a;
		if(a==0){
			int i, x;
			cin>>i>>x;
			update(1,0,n-1,i,x);
		}
		if(a==1){
		int i, j;
		cin>>i>>j;
		cout<<query(1,0,n-1,i,j)<<endl;
		}
	}
	
	return 0;
}

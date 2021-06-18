#include<bits/stdc++.h>
using namespace std;

int contador = 0;
int N,K;
vector<int> A;
vector<vector<int> > solucion;
void backtracking(int n, int k, vector<int> B){
	
	for(int i = n+1; i<=N; i++){
		k += A[i-1];
		B.push_back(i);
		if(k==K){
			contador++;
			solucion.push_back(B);
		}
		backtracking(i, k, B);
		k-= A[i-1];
		B.pop_back();
	}
	
	return;
}

int main(){
	
	cin>>N>>K;
	
	for(int i = 0; i<N; i++){
		int c; cin>>c;
		A.push_back(c);
	}
	
	
	vector<int> B(0);
	backtracking(0,0, B);
	
	for(int i = 0; i<solucion.size();i++){
		for(int j = 0; j<solucion[i].size();j++){
			cout<<A[solucion[i][j]-1]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

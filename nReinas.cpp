#include<bits/stdc++.h>
using namespace std;

int contador = 0;
int n;
vector<bool> columna;
vector<bool> diag1;
vector<bool> diag2;

void search(int y){
	
	if(y==n){
		contador++;
		return;
	}
	for(int x = 0; x<n; x++){

		if(columna[x]||diag1[x+y]||diag2[x-y+n-1]) continue;
		columna[x] = diag1[x+y] = diag2[x-y+n-1] = true;
		search(y+1);
		columna[x] = diag1[x+y] = diag2[x-y+n-1] = false;
		
	}
	
}

int main(){
	
	cin>>n;
	columna.resize(n, false);
	diag1.resize(2*n, false);
	diag2.resize(2*n, false);
	
	search(0);
	
	cout<<contador;
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n;
int contador = 0;
vector<vector<bool> > visitado;
int mx[8] = {2,2,1,1,-1,-1,-2,-2};
int my[8] = {1,-1,2,-2,2,-2,1,-1};

void backtracking(int x, int y, int k){
		
	if(k==n*n) contador++;
	
	for(int i = 0; i<8; i++){
		if(x+mx[i] < 0 || x + mx[i] > 7 || y + my[i]<0 || y + my[i] > 7) continue;
		if(visitado[x+mx[i]][y+my[i]] == true) continue;
		
		visitado[x+mx[i]][y+my[i]] = true;
		backtracking(x+mx[i],y+my[i],k+1);
		visitado[x+mx[i]][y+my[i]] = false;
	}
	
	return;
}

 int main(){
 	
 	cin>>n;
 	visitado.resize(n, vector<bool> (n,false));
 	
 	visitado[0][0] = true;
 	backtracking(0,0,1);
 	cout<<contador;
 	
 	
 	return 0;
 }

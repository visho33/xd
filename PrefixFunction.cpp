#include<bits/stdc++.h>
using namespace std;

vector<int> prefix(string &s){
	int n = s.size();
	vector<int> pi(n);
	pi[0] = 0;
	for(int i = 1; i<n; i++){
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j]){
			j = pi[j-1];
		}
		if(s[i] == s[j]){
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

int main(){
	
	string s;
	cin>>s;
	
	vector<int> pi = prefix(s);
	for(int i = 0; i<pi.size(); i++){
		cout<<pi[i]<<" ";
	}
	
	return 0;
}

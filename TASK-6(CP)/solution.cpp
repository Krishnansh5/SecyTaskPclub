#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
vector<int> Divisors[N];

int main(){
	for(int i=2;i<=sqrt(N);i++){
	 for(int j=i;j<N;j+=i){
	   Divisors[j].push_back(i);
	  }
	}
	int t; //t < 10^6
	cin>>t;
	while(t--){
		int n; //n < 10^3
		cin>>n;
		if(n%2==1){
			cout<<0<<"\n";
		}
		else{
			int x=n*n/2,c=0;
			for(int d : Divisors[x]){
				if(n<=d || n<=x/d)continue;
				if(d+x/d-n<=0)continue;
				if(d>x/d)break;
				c++;
			}
			cout<<c<<"\n";
		}
	}
}
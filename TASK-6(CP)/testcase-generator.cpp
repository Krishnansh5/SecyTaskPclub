#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int t,m=1e3;
	srand(time(0));
	cin>>t;
	cout<<t<<"\n";
	while(t--){
		cout<<1+(rand())%m<<"\n"; //generates t randome numbers with constraints to be used as input
	}
}
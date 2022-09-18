#include<iostream>
using namespace std;

int main(){
	long long  a;
	long long  b;
	
	while(cin>>a>>b){
		if(a < b){
			cout<<b-a<<endl;
		}
		else{
			cout<<a-b<<endl;
		}			
	}	
}
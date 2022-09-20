#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int cases;
	cin>>cases;
	
	int data[cases][500];
	int input;
	int times=0;
	int lock=0;
	int ans=0;
	int med;
	
	while(cin>>input){
		data[times][0]=input;
		for(int j=1;j<=input;j++){
			cin>>data[times][j];			
		}
				
		lock=1;
		while(lock){
			lock=0;
			for(int i=2;i<=data[times][0];i++){
				if(data[times][i-1]>data[times][i]){
					swap(data[times][i-1],data[times][i]);
					lock=lock||1;
				}
			}
		}		
		times++;	
	}
	
	
		
	for(int i=0;i<cases;i++){
		if(data[i][0]%2==1){
			med=(data[i][0]+1)/2;			
			for(int j=1;j<=data[i][0];j++){
				ans+=abs(data[i][j]-data[i][med]);
			}
		}
		else{
			med=data[i][data[i][0]/2];
			for(int j=1;j<=data[i][0];j++){
				ans+=abs(data[i][j]-med);
			}				
		}		
		cout<<ans<<endl;
		ans=0;
	}
}	

	

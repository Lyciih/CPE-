#include<iostream>
using namespace std;

int main(){
	int amount,integer,input;
	cin>>amount>>integer;
	cout<<amount<<" "<<integer<<endl;		

	struct mods {
		int sel;
		int modd;
		int type;
		int odev;
	};
	
	mods field[amount];
	
	
	int n=0;
	while(cin>>input){
		if(n==amount){break;}
		field[n].sel=input;
		field[n].modd=input%integer;
		field[n].odev=abs(input)%2;
		n++;		
	}


	

	mods tms;
	

//first	
	
	int end=1;
	while(end){
		end=0;
		for(int i=1;i<amount;i++){
			if(field[i-1].modd>field[i].modd){
				tms=field[i-1];
				field[i-1]=field[i];
				field[i]=tms;
				end=end||1;
			}
		}
	}	
	
	
//mark

	int stat=0;		
	field[0].type=stat;
	for(int i=1;i<amount;i++){
		if(field[i].modd == field[i-1].modd){
			field[i].type = stat;
		}
		else{
			stat++;
			field[i].type = stat;			
		}	
	}	
	

	
	
	
//second
	
	end=1;
	while(end){
		end=0;
		for(int i=1;i<amount;i++){
			if(field[i-1].type==field[i].type){
				if(field[i-1].odev<field[i].odev){
					tms=field[i-1];
					field[i-1]=field[i]	;
					field[i]=tms;
					end=end||1;
				}
			}
		}
	}

	
	
//third
	end=1;
	while(end){
		end=0;
		for(int i=1;i<amount;i++){
			if(field[i-1].type==field[i].type){
				if(field[i-1].odev==field[i].odev){
					if(field[i].odev==1){
						if(field[i].sel>field[i-1].sel){
							tms=field[i-1];
							field[i-1]=field[i];
							field[i]=tms;
							end = end||1;
						}		
					}
					else{
						if(field[i].sel<field[i-1].sel){
							tms=field[i-1];
							field[i-1]=field[i];
							field[i]=tms;
							end = end||1;
						}			
					}
				}
			}
		}		
	}






//ouput
	for(int i=0;i<amount;i++){
		cout<<field[i].sel<<endl;
	}
	
	
	cout<<0<<" "<<0<<endl;
	

}
#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
	int humans [2] = {3,0};
	int monsters [2] = {3,0};
	bool side = true;
void swap_side();
void play(int human, int monster);
void print_game();
int end_game();
int main(int argc, char** argv) {
	int x=0;
	int j=0;
	while(true){
		print_game();
		cout<<"humans: ";
		scanf("%d",&x);
		cout<<"monsters: ";
		scanf("%d",&j);
		play(x,j);
		x=end_game();
		if(x!=0){
			cout<<((x==1)?"you won":"you lost");
			break;
		}
	}
}


void print_game(){
	for(int i=0;i<humans[0];++i){
		cout<<"human ";
	}
	cout<<endl;
	for(int i=0;i<monsters[0];++i){
		cout<<"monster ";
	}
	cout<<endl;
	for(int i=0;i<10;++i){
		cout<<"--";
	}
	cout<<endl;
	for(int i=0;i<humans[1];++i){
		cout<<"human ";
	}
	cout<<endl;
	for(int i=0;i<monsters[1];++i){
		cout<<"monster ";
	}
	cout<<endl<<endl;
	cout<<"your side is: "<<((side)?"first":"second");
	cout<<endl<<endl;
}


void swap_side(){
	side=!side;
}


void play(int human,int monster){
	system("cls");
	if(monster+human>2||monster+human<1){
		cout<<"mistake: select either one or two only please\n\n";
		return;
	}
	else if(humans[!side]<human||monsters[!side]<monster){
		cout<<"there is no enough creatures\n\n";
		return;
	}
	humans[0]+=(!side)?human:human*-1;
	humans[1]+=(side)?human:human*-1;
	monsters[0]+=(!side)?monster:monster*-1;
	monsters[1]+=(side)?monster:monster*-1;
	swap_side();
}


int end_game(){
	if(monsters[0]*humans[0]!=0){
		if(monsters[0]>humans[0]){
			return -1;
		}
	}
	if(monsters[1]*humans[1]!=0){
		if(monsters[1]>humans[1]){
			return -1;
		}
	}
	if(monsters[1]+humans[1]==6){
		return 1;
	}
	return 0;
}

#include <iostream>
#include <array>
#include "EnemyClass.h"
#include "PlayerClass.h"


using std::string; using std::cout; using std::cin; using std::endl;

void OrderArray(std::array<enemy, 5>&enemys);

int main(){
	InitializeSeed();
	int a, b, c, DEnemys = 0;

	std::array<enemy, 5> enemys;
	for(int i = 0; i<=4; i++){enemys[i].setIdName(i);}
	player _player;
	
	
	int turns = RandomNumberBetween(10,25);
	bool PTurn = true;
	int ETurn = 0;
	while(turns>=0){
	
	OrderArray(enemys);
	
	system("cls");
	cout<<"Turns left: "<<turns; if(PTurn) cout<<" YOUR TURN\n"; else cout<<" ENEMY "<<ETurn<<" TURN\n";
	for(int i=0;i<=4;i++){	cout<<"Enemy "<<enemys[i].getIdName()<<" Life: "<<enemys[i].getLife()<<"\tDamage: "<<enemys[i].getDamage()<<"\tDefence: "<<enemys[i].getDefence()<<"\n";	}
	cout<<"\nPlayers character Life: "<<_player.getLife()<<"\tDamage: "<<_player.getDamage()<<"\tDefence: "<<_player.getDefence()<<"\n\n";	
	

	system("pause");
	cout<< "\x1b[1A"<<"\x1b[2K";

	
	if(PTurn){
	cout<<"Players character atacks enemy "<<enemys[0].getIdName()<<"\n";
	enemys[0].TakeDamage(_player.getDamage());
	PTurn = false;
	}else{
	for(int i = 0; i<=4;i++){
	if(enemys[i].getIdName() == ETurn){
		cout<<"Enemy "<<enemys[i].getIdName()<<" atacks players character\n";
		_player.TakeDamage(enemys[i].getDamage());
	}
	}
	if(ETurn >=4) {ETurn = 0;} else {ETurn++;}
	PTurn = true;
	}
	
	
	system("pause");
	
	
	if(enemys[0].isDead()){	DEnemys++;}
	if(_player.isDead() || DEnemys >= 5){	break;	}
	turns--;
	};

	
	OrderArray(enemys);

	
	system("cls");
	cout<<"End of the game.\n";
	for(int i=0;i<=4;i++){	cout<<"Enemy "<<enemys[i].getIdName()<<" Life: "<<enemys[i].getLife()<<"\tDamage: "<<enemys[i].getDamage()<<"\tDefence: "<<enemys[i].getDefence()<<"\n";	}
	cout<<"\nPlayers character Life: "<<_player.getLife()<<"\tDamage: "<<_player.getDamage()<<"\tDefence: "<<_player.getDefence()<<"\n\n";	

	
	if(DEnemys >= 5 && _player.isDead()){
		cout<<"Tie.";
	} else if(DEnemys < 5 && _player.isDead() == false){
		cout<<"Tie.";
	} else if(DEnemys >= 5 &&_player.isDead() == false){
		cout<<"You won.";
	} else if(DEnemys < 5 && _player.isDead()){
		cout<<"You lost.";
	}

	return 0;
}


void OrderArray(std::array<enemy, 5>&enemys){
	
	for(int i = 0; i<=4; i++){
		for(int e = 0; e<=4; e++){
		enemy temp;
		if(enemys[e].getLife() < enemys[e+1].getLife()){
			temp = enemys[e];
			enemys[e] = enemys[e+1];
			enemys[e+1] = temp;
			}
		}
	}
	
}


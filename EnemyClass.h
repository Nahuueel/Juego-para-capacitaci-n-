#include <iostream>
#include "RandomNumbers.h"

class enemy{
	private:
		int idName;
		int damage;
		int life;
		int defence;
	public:
	enemy (){
		damage = RandomNumber(100);
		life = 	RandomNumberBetween(500,1000);
		defence = RandomNumber(50);
	}
	
	void setLife(int a){life = a;}
	
	void setDefence(int a){defence = a;}	
		
	void setDamage(int a){damage = a;}	
	
	void setIdName(int IdNum){idName = IdNum;}
	
	int getLife(){return life;}

	int getDefence(){return defence;}

	int getDamage(){return damage;}
	
	int getIdName(){return idName;}

	void TakeDamage(int a);
	
	bool isDead();
	
};

bool enemy::isDead(){
		if (life <= 0){life = 0;
		return true;
		}else{
		return false;
		}
	}

void enemy::TakeDamage(int a){
	int damtaked = a-defence;
	if(damtaked>0){life = life - damtaked;}else{
	std::cout<<"Miss\n";}
}

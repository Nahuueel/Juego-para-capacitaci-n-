#include <iostream>

class player{
	private:
		int damage;
		int life;
		int defence;
	public:
	player (){
		int a;
		
		while(true){
		std::cout<<"Enter players character life value (between 1000 and 2000)\n";
		std::cin>>a;
		if(a>=1000 && a<=2000){life = a; break;}else std::cout<<"Enter a valid value\n"; system("pause"); system("cls");
		}
		while(true){
		std::cout<<"Enter players character damage value (between 100 and 200)\n";
		std::cin>>a;
		if(a>=100 && a<=200){damage = a; break;}else std::cout<<"Enter a valid value\n"; system("pause"); system("cls");
		}
		while(true){
		std::cout<<"Enter players character defence value (between 50 and 75)\n";
		std::cin>>a;
		if(a>=50 && a<=75){defence = a; break;}else std::cout<<"Enter a valid value\n"; system("pause"); system("cls");
		}
	}
	
	void setLife(int a){life = a;}
	
	void setDefence(int a){defence = a;}	
		
	void setDamage(int a){damage = a;}	
	
	int getLife(){return life;}

	int getDefence(){return defence;}

	int getDamage(){return damage;}
	
	void TakeDamage(int a);
	
	bool isDead();
};

void player::TakeDamage(int a){
	int damtaked = a-defence;
	if(damtaked>0){life = life - damtaked;}else{	
	std::cout<<"Miss\n";
	}
}

bool player::isDead(){
	if (life <= 0){
	life = 0;
	return true;}
	else{return false;}
}

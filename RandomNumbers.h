#include <stdlib.h>     
#include <time.h>


void InitializeSeed(){
	srand((int)time(NULL));
}

int RandomNumber(int max){
	
	int result = rand() % max;

	return result;
}

int RandomNumberBetween(int min, int max){
	
	int	result = (max - min)+(rand() % min);

	return result;
}

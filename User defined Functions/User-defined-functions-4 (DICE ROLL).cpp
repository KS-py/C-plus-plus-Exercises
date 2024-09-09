#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice(int);

int main(){
	cout << "To get a sum of 10, we rolled " << rollDice(10) << " times " << endl;
	cout << "To get a sum of 6, we rolled " << rollDice(6) << " times " << endl;
	srand(time(0));
	cout << rand() << endl;
}

int rollDice(int num){
	int die1;
	int die2;
	int rollCount = 0;
	int sum;
	
	srand(time(0));
	
	do{
		die1 = rand() % 6 + 1;
		die2 = rand() % 6 + 1;
		rollCount++;
		sum = die1 + die2;
	}while(sum != num);
	
	return rollCount;
}

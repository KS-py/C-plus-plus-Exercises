#include <iostream>
#include <iomanip>

using namespace std;

const double GALLONS_IN_CUBIC_FOOT = 7.48;

double poolCapactiy(double len, double wid, double dep);
void poolFillTime(double len, double wid, double dep, double fillRate, int& fTime);
void print(int fTime);

int main(){
	double length, width, depth, fillRate;
	int fillTime;
	
	cout << fixed << showpoint << setprecision(2);
	
	cout << "Enter the length, width and depth of the pool (in feet): " << endl;
	cin >> length >> width >> depth;
	cout << endl;
	
	cout << "Enter the rate at which the pool fills: " << endl;
	cin >> fillRate;
	
	poolFillTime(length, width, depth, fillRate, fillTime);
	print(fillTime);
	
	return 0;
}

double poolCapactiy(double len, double wid, double dep){
	double volume;
	double poolWaterCapacity;
	volume = len * wid * dep;
	poolWaterCapacity = volume * GALLONS_IN_CUBIC_FOOT;
	
	return poolWaterCapacity;
}

void poolFillTime(double len, double wid, double dep, double fillRate, int& fTime){
	double poolWaterCapacity;
	poolWaterCapacity = poolCapactiy(len, wid, dep);
	
	fTime = static_cast<int>(poolWaterCapacity/fillRate + 0.5);
}

void print(int fTime){
	cout << "The time needed to fill the pool is: " << fTime/60 << " hours, "  << fTime % 60 << " minutes" << endl;
}

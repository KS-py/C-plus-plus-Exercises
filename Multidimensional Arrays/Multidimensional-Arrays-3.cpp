#include <iostream>

using namespace std;

void getData(double[][2]);
double averageHigh(double[]);
double averageLow(double lows[]);
int indexHighTemp(double highs[]);
int indexLowTemp(double lows[]);
void printArray(double[], int);
double highs[12];
double lows[12];

int main(){
	double temps[12][2];
	
	getData(temps);
	
	printArray(highs, 12);
	printArray(lows, 12);
	
	cout << "The average high temperature: " << averageHigh(highs) << endl;
	cout << "The average low temperature: " << averageLow(lows) << endl;
	
	
	cout << endl;
	cout << "The index of the highest high temperature: " << indexHighTemp(highs) << endl;
	cout << "The index of the lowest low temperature: " << indexLowTemp(lows) << endl;
	return 0;
}

void getData(double multiDim[][2]){
	for(int j = 0; j < 2; j++){
		if(j == 0){
			cout << "Enter the highest temperatures for each month:" << endl;
		}else{
			cout << "\nEnter the lowest temperatures for each month: " << endl;
		}
		for(int i = 0; i < 12; i++){
			cin >> multiDim[i][j];
			if(j == 0){
				highs[i] = multiDim[i][0];
			}else{
				lows[i] = multiDim[i][1];
			}
		}
	}
}

double averageHigh(double highs[]){
	double averageHigh = 0.0;
	double sum = 0.0;
	
	for(int i = 0; i < 12; i++){
		sum += highs[i];
	}
	
	averageHigh = sum/12;
	
	return averageHigh;
}

double averageLow(double lows[]){
	double averageLow = 0.0;
	double sum = 0.0;
	
	for(int i = 0; i < 12; i++){
		sum += lows[i];
	}
	
	averageLow = sum/12;
	
	return averageLow;
}

int indexHighTemp(double highs[]){
	double max = 0.0;
	int indexHighestHigh = 0;
	
	for(int i = 0; i < 12; i++){
		if(highs[i] > max){
			max = highs[i];
			indexHighestHigh = i;
		}
	}
	
	return indexHighestHigh;
}

int indexLowTemp(double lows[]){
	double min = lows[0];
	int indexLowestLow = 0;
	
	for(int i = 0; i < 12; i++){
		if(lows[i] < min){
			min = lows[i];
			indexLowestLow = i;
		}
	}
	
	return indexLowestLow;
}


void printArray(double array[], int size){
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

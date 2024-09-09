#include <iostream>

using namespace std;

void setZero(int[], int);
void inputArray(int[], int);
void doubleArray(int[], int[], int);
void copyGamma(int[][4], int[], int);
void copyAlphaBeta(int[][4], int[], int[], int);
void setInStock(int inStock[][4], int[], int);
void printArray(int[], int);
void printMultiDimArray(int[][4], int);


int main(){
	int inStock[10][4];
	int alpha[20];
	int beta[20];
	int gamma[4] = {11, 13, 15, 17};
	int delta[10] = {3, 5, 2, 6, 10, 9, 7, 11, 1, 8};
	
	inputArray(alpha, 20);
	doubleArray(beta, alpha, 20);
	
	cout << "\nALPHA: " << endl;
	printArray(alpha, 20);
	
	cout << "\nBETA:" << endl;
	printArray(beta, 20);
	
	cout << "\nDELTA: " << endl;
	printArray(delta, 10);
	
	cout << "\nGAMMA: " << endl;
	printArray(gamma, 4);
	
	copyAlphaBeta(inStock, alpha, beta, 10);
	cout <<"\nINSTOCK after copyAlphaBeta\n";	
    printMultiDimArray(inStock, 10);
    
	copyGamma(inStock, gamma, 10);	
	cout <<"\nINSTOCK after copyGamma\n";
    printMultiDimArray(inStock, 10);
	
	setInStock(inStock, delta, 10);
	cout <<"\nINSTOCK after setInStock"<< endl;
    printMultiDimArray(inStock, 10);	
	return 0;
}


void setZero(int oneDim[], int size){
	for(int i = 0; i < size; i++){
		oneDim[i] = 0;
	}
}


void inputArray(int alpha[], int size){
	cout << "Input 20 numbers to be stored in array alpha"<< endl;
	for(int i = 0; i < 20; i++){
		cin >> alpha[i];
	}
}


void doubleArray(int beta[], int alpha[], int size){
	for(int i = 0; i < size; i++){
		beta[i] = alpha[i] * 2;
	}
}


void copyGamma(int inStock[][4], int gamma[], int rows){
	
	for(int i = 0; i < rows; i++){
		if(i == 0){
			for(int j = 0; j < 4; j++){
				inStock[0][j] = gamma[j];
			}
		}else if(i != 0){
			for(int j = 0; j < 4; j++){
				inStock[i][j] = 3 * inStock[i-1][j];
			}
		}
	}
}


void copyAlphaBeta(int inStock[][4], int alpha[], int beta[], int rows){
	for(int i = 0; i < rows; i++){
		if(i < 5){
			for(int j = 0; j < 4; j++){
				inStock[i][j] = alpha[(4*i)+j];
			}
		}else{
			for(int j = 0; j < 4; j++){
				inStock[i][j] = beta[(4*(i-5))+j];				
			}
		}
	}	
}


void printArray(int array[], int size){
	for(int i = 0; i < size; i++){
		cout << array[i] << " ";
		if(i > 0 && i % 14 == 0){
			cout << endl;
		}
	}
	cout << endl;
}


void printMultiDimArray(int multiDim[][4], int rows){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < 4; j++){
			cout << multiDim[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


void setInStock(int inStock[][4], int delta[], int rows){
	cout << "Enter the elements for the first column of inStock: " << endl;
	for(int i = 0; i < rows; i++){
		cin >> inStock[i][0];
	}
	
	for(int j = 1; j < 4; j++){
		for(int i = 0; i < rows; i++){
			inStock[i][j] = 2 * inStock[i][j-1] - delta[i];
		}
	}
}

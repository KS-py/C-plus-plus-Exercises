#include <iostream>

using namespace std;

void getData(string[], double[][7], int);
void calculateInfo(double[][7], double[], double[]);
void printInfo(double distance[][7], double total[], double avg[], string runners[]);

int main(){
	string runners[5];
	double distanceByDays[5][7];
	double totalByRunner[5];
	double avgByRunner[5];
	
	getData(runners, distanceByDays, 5);
	
	calculateInfo(distanceByDays, totalByRunner, avgByRunner);
	cout << endl;
	
//	cout << "The total by each runner: " << endl;
//	for(int i = 0; i < 5; i++){
//		cout << totalByRunner[i] << " ";
//	}
//	cout << endl;
//	
//	cout << "The average for each runner: " << endl;
//	for(int i = 0; i < 5; i++){
//		cout << avgByRunner[i] << " ";
//	}
//	cout << endl;

	printInfo(distanceByDays, totalByRunner, avgByRunner, runners);

	
	return 0;
}

void getData(string runners[], double distances[][7], int size){
	cout << "Enter the names of the runners: " << endl;
	for(int i = 0; i < size; i++){
		getline(cin, runners[i]);
	}
	
	cout << "Enter the miles run by day ie. at the end of the day" << endl;
	for(int j = 0; j < 7; j++){
		for(int i = 0; i < 5; i++){
			cin >> distances[i][j];
		}
	}
}

void calculateInfo(double distance[][7], double total[], double avg[]){
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			total[i] += distance[i][j];
		}
		avg[i] = total[i]/7;
	}
}

//Improve the formatting for longer names
void printInfo(double distance[][7], double total[], double avg[], string runners[]){
	cout << "Name" <<"\t\t"<< "Distances" << "\t\t\t\t\t" << "Total" << "\t"<< " Average" << endl;
	for(int i = 0; i < 5; i++){	
		cout << runners[i];
		for(int j = 0; j < 7; j++){
			cout << "\t" << distance[i][j] << "  ";
		}
		cout << "\t" << total[i] << "\t" << avg[i];
		cout << endl;
	}
	
}

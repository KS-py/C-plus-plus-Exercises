#include <iostream>
#include <iomanip>

using namespace std;

void mainFitness();
double membershipCost();
int determineMembership();


int main(){
	mainFitness();
	membershipCost();
	
	return 0;
}

void mainFitness(){
	cout << "Fitness Center\n======================" << endl;
	cout << "Senior citizens (70) have a discount of 30%" << endl;
	cout << "Membership paid for more than a year; discount of 15%" << endl;
	cout << "More than 5 personal training sessions paid for; discount on each is 20%" << endl;
	cout << "\nThe membership cost per month is $50.00 \nThe cost per session is $10.00\n" << endl;
	
}

int determineMembership(){
	char res;
	int age = 0;
	int memberType = 0;	
	/* the criteria for classification will be 
	1 prefix for senior 
	2 prefix for younger
	
	_1 for membership for months 
	_2 for sessions
	
	*/
	
	cout << "To determine your membership details, please answer the following questions:" << endl;
	cout << "Enter your age: ";
	cin >> age;
	if(age >= 70){
		cout << "Do you want to attend monthly or per session? (m for monthly, s for session):"; 
		cin >> res;
		if(res == 'm'){
			cout << "\nYou chose the monthly package" << endl;
			memberType = 11;
		}else if(res == 's'){
			cout << "\nYou chose the session package" << endl;
			memberType = 12;
		}
	}else{
		cout << "Do you want to attend monthly or per session? (m for monthly, s for session):"; 
		cin >> res;
		if(res == 'm'){
			cout << "\nYou chose the monthly package" << endl;
			memberType = 21;
		}else if(res == 's'){
			cout << "\nYou chose the session package" << endl;
			memberType = 22;
		}		
	}
	
	return memberType;
}

double membershipCost(){
	double costPerMonth = 50.00;
	double costPerSession = 10.00;
	int type = determineMembership();
	int numberOfMonths = 0;
	int numberOfSessions = 0;
	
	double totalCost = 0.0;
	
//	Ask how many months or sessions here and calculate discount eligibility
	
	switch(type){
		case 11:
			cout << "Enter the number of months you want to pay for: ";
			cin >> numberOfMonths;
			if(numberOfMonths >= 12){
				totalCost = 0.7*0.85 * numberOfMonths * costPerMonth;				
			}else{	
				totalCost = 0.7*numberOfMonths * costPerMonth;				
			}
			break;
		case 12:
			cout << "Enter the number of sessions you want to pay for: ";
			cin >> numberOfSessions;
			if(numberOfSessions >= 5){
				totalCost = 0.7*0.8 * numberOfSessions * costPerSession;				
			}else{	
				totalCost = 0.7*numberOfSessions * costPerSession;				
			}
			break;
		case 21:
			cout << "Enter the number of months you want to pay for: ";
			cin >> numberOfMonths;
			if(numberOfMonths >= 12){
				totalCost = 0.85 * numberOfMonths * costPerMonth;				
			}else{	
				totalCost = numberOfMonths * costPerMonth;				
			}
			break;
		case 22:
			cout << "Enter the number of sessions you want to pay for: ";
			cin >> numberOfSessions;
			if(numberOfSessions >= 5){
				totalCost = 0.8 * numberOfSessions * costPerSession;				
			}else{	
				totalCost = numberOfSessions * costPerSession;				
			}
			break;			
	}
	
	cout << fixed << showpoint  << setprecision(2);
	cout << "The total cost for your package is: $" << totalCost << endl;
	
}

#include <iostream>
#include <string>

using namespace std;


int main(){
	string name;
	string SSN;
	string userID;
	string password;
	
	string SSN_CHAR;
	string PASSWORD_CHAR;
	
	cout << "Enter your name: ";
	getline(cin, name);
	cout << "Enter your SSN: ";
	getline(cin, SSN);
	cout << "Enter your userID: ";
	getline(cin, userID);
	cout << "Enter your password: ";
	getline(cin, password);
	
	for(int i = 0; i < SSN.length(); i++){
		SSN_CHAR.append("*");
	}
	
	//replace spots in ****** where hyphens are supposed to be 
	SSN_CHAR.replace(3, 1, "-");
	SSN_CHAR.replace(6, 1, "-");
	
	
	cout << "SSN hidden: " << SSN_CHAR << endl;
	
	for(int i = 0; i < password.length(); i++){
		PASSWORD_CHAR.append("*");
	}
	
	cout << "Password: " << PASSWORD_CHAR << endl;
	
}

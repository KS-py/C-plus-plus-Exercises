#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

string changeName(string);

int main(){
	ifstream inputFile("data.txt");
	string wrongFormat;
	string correctFormat;

	while(!inputFile.eof()){
		try{
			getline(inputFile, wrongFormat);
			correctFormat = changeName(wrongFormat);
			cout << correctFormat << endl;			
		}catch(const out_of_range& e){
			cerr << "==== End of the file ====="<<  endl;
		}
	}

	return 0;
}

string changeName(string complete){
	int num = complete.find(",");
	string completeName;
	string firstMiddleName = complete.substr(num+1, complete.length());
	string surname = complete.replace(num, complete.length() + 1, " ");
	
	firstMiddleName.erase(0, 1); //erase the whitespace at the start of the string
	firstMiddleName.insert(firstMiddleName.length(), " ");
	completeName = firstMiddleName.append(surname);
	
	return completeName;
}

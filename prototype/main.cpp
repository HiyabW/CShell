#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main () {
	
	string userInput;
	cout << "Enter a command: ";
	getline(cin, userInput);

	int argCount = 0;
	int conCount = 0;
	int execCount = 0;

	vector<string> validArgs;
	vector<string> validCons;
	vector<string> validExecs;

	validArgs.push_back("ls");
	validArgs.push_back("cd");
	validArgs.push_back("push");

	validCons.push_back(";");
        validCons.push_back("||");
        validCons.push_back("&&");
	
	string userArg = "";
	vector<string> userArgVector;
	string userCon = "";
	string userExec = "";
	
	int placeholder = 0;
	
	for(unsigned int i = 0; i < userInput.size(); ++i) {
             //string temp;
	     while((i < userInput.size()) && ((userInput.at(i) != ' ') && (userInput.at(i) != ';'))) {
                  //cout << userExec << " ";
                  userExec.push_back(userInput.at(i));
                  //cout << userExec << endl;
                  ++i;
	     }
             //userExec.push_back(temp);
             ++execCount;
	     //++i;
             cout << execCount << " " << endl;
	     cout << "userExec:" << userExec << endl;
             cout << "pass" << endl;
	     placeholder = i;
	}
       
	 while((placeholder < userInput.size()) && ((userInput.at(placeholder) != '&') && (userInput.at(placeholder) != '|'))) {
                  cout << "arg1" << endl;
	          while((placeholder < userInput.size()) && (userInput.at(placeholder) != ' ')) {
	               userArg += userInput.at(placeholder);
                       //++i;
	          }
                  cout << "arg2" << endl;
	          ++argCount;
	          userArgVector.push_back(userArg);
	          userArg = " ";
	     }
             cout << "userArg:" <<  userArgVector.size() << endl;

//	for (unsigned int i = 0; i < userArgVector.size(); ++i) {
//	          cout << userArgVector.at(i) << endl;
//	}
	return 0;
}

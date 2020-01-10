#include "rShell.hpp"
#include "Execute.hpp"
#include "ExecuteAND.hpp"
#include "ExecuteOR.hpp"
#include "ExecuteSEMI.hpp"
#include "piping.hpp"
#include "InputRedirect.hpp"
#include "OutputRedirect.hpp"
#include "OutputRedirect2.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <cstring>
#include <map>
using namespace std;

rShell* parse(string targetCommand, vector<string> &quotedData, map<int, string> &parenthesisMap);
void print();
string extractParenthesis(string userInput, int &key,  map<int, string> &parenthesisMap);

int main() {
	string userInput;
	bool temp;
	int key = 0;
	map<int, string> parenthesisMap;
	restart:
	print();
	getline(cin, userInput);
	while(userInput != "exit") {
		size_t foundComment = userInput.find('#');
		if(foundComment != string::npos) {
			userInput.erase(foundComment, userInput.size() - 1);
		}
		if(userInput != "") {
			string targetString; //if command has a quoted string(s), temporarly stored here and then into vector
			vector<string> quotedData;
			size_t found = userInput.find('"');
			int firstIndex;
			int secIndex;
			while(found != string::npos) {
				firstIndex = userInput.find_first_of('"');
				secIndex = userInput.find_first_of('"', found + 1);
				targetString = userInput.substr(firstIndex, (secIndex - firstIndex) + 1);
				userInput.replace(firstIndex, (secIndex - firstIndex) + 1, "quoteString");
				quotedData.push_back(targetString);
				found = userInput.find('"');
			}
			found = userInput.find('['); //looks for any bracket test commands in userinput and replaces them with just "test"
                        while (found != string::npos) {
                                firstIndex = userInput.find_first_of('[');
                                userInput.replace(firstIndex, 1, "test");
                                secIndex = userInput.find_first_of(']');
                                userInput.erase(secIndex, 1);
                                found = userInput.find('[');
                        }
			found = userInput.find('(');//looks for parenthesis in the userInput
			if (found != string::npos) {
				int x = 0;
				int y = 0;
				for (size_t found = userInput.find_first_of('('); found != string::npos; found = userInput.find_first_of('(', found + 1)) {
					++x;
				}
				for (size_t found = userInput.find_first_of(')'); found != string::npos; found = userInput.find_first_of(')', found + 1)) {
                                        ++y;
                                }
				if (x != y) {
					cout << "Invalid Input" << endl;
					goto restart;
				}
				found = userInput.find('(');
				while (found != string::npos) {
					userInput = extractParenthesis(userInput, key, parenthesisMap);
					found = userInput.find('(');
				}
			}
			found = userInput.find('|'); //Looks for any pipes but doesn't parse, encases everything to the left in parenthesis for correct tree building
			while (found != string::npos) {
				if (userInput[found + 1] != '|') {
					userInput.insert(0, "(");
    					userInput.insert(found, ")");
					found = userInput.find('|', found + 3);
				} else {found = userInput.find('|', found + 2);}
			}
			found = userInput.find_first_of("<>"); //Looks for any i/o redirection but doesn't parse, encases everything to the left in parenthesis for correct tree building
			while(found != string::npos) {
				userInput.insert(0, "(");
                                userInput.insert(found, ")");
				if(userInput[found + 3] == '>') {
					found += 4;
				} else {found += 3;}
				found = userInput.find_first_of("<>", found);
			}		
			found = userInput.find('(');
			while (found != string::npos) {
       	                        userInput = extractParenthesis(userInput, key, parenthesisMap);
                                found = userInput.find('(');
                        }
			rShell* parentExecute = parse(userInput, quotedData, parenthesisMap);			
			if(!parentExecute->execute()) {
				cout << "Execution failed" << endl;
			}
			print();
 	                getline(cin, userInput);
			key = 0;
			parenthesisMap.clear();
		}
	}
	exit(0);
	return 0;
}

void print() { cout << "$ "; }

rShell* parse(string userCommand, vector<string> &quotedData, map<int, string> &parenthesisMap) {
	vector<string> parser;
	size_t found1 = userCommand.find(';'); 	  //attempts to find any ; connectors in parsed content
        size_t found2 = userCommand.find("&&");	  //attempts to find any && connectors in parsed content 
        size_t found3 = userCommand.find('|');	  //attempts to find any || connectors in parsed content
	size_t found4 = userCommand.find('<');    //attempts to find any < connectors in parsed content
	size_t found5 = userCommand.find('>');    //attempts to find any > connectors in parsed content
	string leftParse;
	string rightParse;
	if((((found1 == string::npos && found2 == string::npos) && found3 == string::npos) && found4 == string::npos) && found5 == string::npos)  {
		//command does not have a connector
		vector<string> parser;
		char c_userCommand[userCommand.length() + 1];//have to convert string into array of chars to use strtokpoint = strtok(c_userCommand, "&&");
	        strcpy(c_userCommand, userCommand.c_str());
	        char* point;

		point = strtok(c_userCommand, " ");
                while(point != NULL) {
			string parenthesisString = string(point);
			string temp = parenthesisString.substr(0, parenthesisString.size() - 1);
                        if(string(point) == "quoteString") {
				string temp = quotedData.at(0);
                                temp = temp.substr(1, temp.size() - 2);
                                parser.push_back(temp);
                                quotedData.erase(quotedData.begin());
               		}
			else if (temp == "parenthesisString") {
				char charToKey = parenthesisString.back();
				int key = charToKey - 48;
				string targetString = parenthesisMap.at(key);
				return parse(targetString, quotedData, parenthesisMap);
			}
			else {
				parser.push_back(string(point));
			}
			point = strtok(NULL, " ");
		}
		rShell* execute = new Execute(parser);
		return execute;
	}
	restartParse:
	if(found1 != string::npos) {
		leftParse = userCommand.substr(0, found1);
		rightParse = userCommand.substr(found1 + 1, userCommand.size() - 1);
                rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);
                rShell* exec2 = parse(rightParse, quotedData, parenthesisMap);
                rShell* semiExec = new ExecuteSEMI(exec1, exec2);
                return semiExec;
	}

	else if(found2 != string::npos) {
		leftParse = userCommand.substr(0, found2);
                rightParse = userCommand.substr(found2 + 2, userCommand.size() - 1);
		rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);
		rShell* exec2 = parse(rightParse, quotedData, parenthesisMap);
		rShell* andExec = new ExecuteAND(exec1, exec2);
		return andExec;
	}

	else if(found3 != string::npos) {
		if (userCommand[found3 + 1] == '|') {
			leftParse = userCommand.substr(0, found3);
	                rightParse = userCommand.substr(found3 + 2, userCommand.size() - 1);
	                rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);
	                rShell* exec2 = parse(rightParse, quotedData, parenthesisMap);
	                rShell* orExec = new ExecuteOR(exec1, exec2);
	                return orExec;
		}
		int pipeIndex = found3;
		found1 = userCommand.find(';', found3 + 1);
        	found2 = userCommand.find("&&", found3 + 1);
        	found3 = userCommand.find("||", found3 + 1);
		found4 = userCommand.find('<', found3 + 1);
                found5 = userCommand.find('>', found3 + 1);
		if ((((found1 != string::npos || found2 != string::npos) || found3 != string::npos) || found4 != string::npos) || found5 != string::npos) {
			goto restartParse;
		}
		leftParse = userCommand.substr(0, pipeIndex);
                rightParse = userCommand.substr(pipeIndex + 1, userCommand.size() - 1);
       	        rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);
                rShell* exec2 = parse(rightParse, quotedData, parenthesisMap);
                rShell* pipeExec = new Piping(exec1, exec2);
                return pipeExec;
	}
	else if(found4 != string::npos) { //input parse
		int inputIndex = found4;
		found1 = userCommand.find(';', found4 + 1);
                found2 = userCommand.find("&&", found4 + 1);
                found3 = userCommand.find("||", found4 + 1);
		found4 = userCommand.find('<', found4 + 1);
		found5 = userCommand.find('>', found4 + 1);
		if ((((found1 != string::npos || found2 != string::npos) || found3 != string::npos)|| found4 != string::npos) || found5 != string::npos) {
                        goto restartParse;
                }
		leftParse = userCommand.substr(0, inputIndex);
                string fileName = userCommand.substr(inputIndex + 2, userCommand.size() - 1);
                rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);
		rShell* inputExec = new InputRedirect(exec1, fileName);
		return inputExec;
	}
	else if(found5 != string::npos) { //output parse
		int outputIndex = found5;
		found1 = userCommand.find(';', found5 + 1);
                found2 = userCommand.find("&&", found5 + 1);
                found3 = userCommand.find("||", found5 + 1);
                found4 = userCommand.find('<', found5 + 1);
		if(userCommand[outputIndex + 1] == '>') {
			found5 = userCommand.find('>', found5 + 2);
		} else {found5 = userCommand.find('>', found5 + 1);}
                if ((((found1 != string::npos || found2 != string::npos) || found3 != string::npos) || found4 != string::npos) || found5 != string::npos){
                        goto restartParse;
                }
		if (userCommand[outputIndex + 1] == '>') {
			leftParse = userCommand.substr(0, outputIndex);
			string fileName = userCommand.substr(outputIndex + 3, userCommand.size() - 1);
			rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);          
			rShell* out2Exec = new OutputRedirect2(exec1, fileName);
			return out2Exec;
		}
		else {
			leftParse = userCommand.substr(0, outputIndex);
                        string fileName = userCommand.substr(outputIndex + 2, userCommand.size() - 1);
                        rShell* exec1 = parse(leftParse, quotedData, parenthesisMap);
                        rShell* outExec = new OutputRedirect(exec1, fileName);
                        return outExec;
		}
	}
}

string extractParenthesis(string userInput, int &key, map<int, string> &parenthesisMap) {
	int firstIndex = userInput.find_first_of('(');
	int secIndex = userInput.find_first_of(')');
	if (firstIndex == string::npos && secIndex == string::npos) {
		parenthesisMap[key] = userInput;
		string mapString = "parenthesisString";
		mapString += (key + 48);
		++key;
		return userInput.replace(0, userInput.size(), mapString);
	}
	size_t found = userInput.find_first_of('(', firstIndex + 1);
	while (found != string::npos) {
		if (found > secIndex) {
			break;
		}
		secIndex = userInput.find_first_of(')', secIndex + 1);
		found = userInput.find_first_of('(', found + 1);
	}
	string temp = userInput.substr(firstIndex + 1, (secIndex - firstIndex) - 1);
	temp = extractParenthesis(temp, key, parenthesisMap);
	string parenthesisString = temp.substr(0, temp.size() - 1);
	if (parenthesisString == "parenthesisString") {
		userInput.replace(firstIndex, (secIndex - firstIndex) + 1, temp);
		return userInput;
	}
	userInput.replace(firstIndex, (secIndex - firstIndex) + 1, extractParenthesis(temp, key, parenthesisMap));
	return userInput;
}

#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

//digits 0-9
const int NUMBER_OF_DIGITS = 10;

//Set to keep track of visited digits
typedef set<string> Digitset;


//int main() {
//	string line;
//	int case_number = 1;	//number of cases in the experiment
//	Digitset myDigits;
//
//	ifstream mystream("A-large.in");
//	ofstream output("A-large-attempt-output.txt");
//	if (mystream.is_open()) {
//		getline(mystream, line);	//get the first line (number of cases [not needed])
//		//extract the number to start counting from
//		while (getline(mystream, line)) {
//			int number = stoi(line);
//			if (number != 0) {
//				int multiplier = 1;
//				while (myDigits.size() < 10) {
//					int operand = number * multiplier;
//					string s = to_string(operand);
//					//split the number into its constituent characters
//					for (size_t i = 0; i < s.length() && myDigits.size() < (size_t) 10; i++) {
//						string digit = s.substr(i, 1);	//extract one digit
//						myDigits.insert(digit);
//					}
//					if (myDigits.size() == 10) {
//						output << "Case #" << case_number << ": " << operand << endl;
//					}
//					multiplier++;
//				}
//			}
//			else {
//				output << "Case #" << case_number << ": " << "INSOMNIA" << endl;
//			}
//			myDigits.clear();	
//			case_number++;
//		}
//		mystream.close();
//		output.close();
//	}
//	else {
//		cout << "Unable to open file";
//	}
//	cin.get();
//	return 0;
//}
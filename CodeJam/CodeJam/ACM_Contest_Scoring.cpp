#include <iostream>		//cin and cout
#include <string>		//getline
#include <unordered_map>	
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(const string &s, char delim, vector<string>& strings) {
	size_t i = 0;
	size_t pos = s.find(delim);
	while (pos != string::npos) {
		strings.push_back(s.substr(i, pos - i));
		i = ++pos;
		pos = s.find(delim, pos);		//find characters before OR AT pos!
	}
	strings.push_back(s.substr(i, string::npos));
	return strings;
}

int main() {
	unordered_map<string, int> freq_of_wrong;
	unordered_map<string, bool> eventually_solved;
	int num_of_right_answers = 0;
	int sum_of_right_answers = 0;
	int sum_of_wrong_answers = 0;
	string s;
	int time_as_int;
	while (getline(cin, s)) {
		if (s != "-1") {			//you typed "=1" not "-1"
			vector<string> details;
			split(s, ' ', details);		//<3, E, right>
			string time = details[0];
			stringstream convert(time);
			convert >> time_as_int;

			string question = details[1];
			bool successful = details[2] == "right";

			if (successful) {
				num_of_right_answers++;
				sum_of_right_answers += time_as_int;
				eventually_solved[question] = true;
			}
			else {		//not sucessful
				freq_of_wrong[question]++;
			}
		}
		else {//output results
			for (const pair<string, bool> p : eventually_solved) {
				sum_of_wrong_answers += 20 * freq_of_wrong[p.first];
			}
			cout << num_of_right_answers << " " << sum_of_right_answers + sum_of_wrong_answers << endl;

			//clear variables
			freq_of_wrong.clear();
			eventually_solved.clear();
			num_of_right_answers = 0;
			sum_of_right_answers = 0;
			sum_of_wrong_answers = 0;
		}
	}
	return 0;
}

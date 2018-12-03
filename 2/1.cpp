#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
enum Occured { TWICE = 1, THRICE = 2 };

int single_line(string line) {
	int result = 0;
	map<char, long> occurences;
	for (char c : line) {
		occurences[c] += 1;
	}

	for (auto it = occurences.begin(); it != occurences.end(); it++) {
		if (it->second == 2){
			result |= TWICE;
		} else if (it->second == 3) {
			result |= THRICE;
		}
	}
	return result;
}

int main(int argc, char** argv) {
	char* file = argv[1];
	string line;
	ifstream infile(file);

	long doubles, triples = 0;

	vector<string> changes;

	while(infile >> line) {
		changes.push_back(line);
	}

	for (auto it = changes.begin(); it != changes.end(); it++) {
		int line_result = single_line(*it);
		if (line_result & TWICE) {
			doubles++;
		}
		if (line_result & THRICE) {
			triples++;
		}
	}

	cout << "wynik: " << doubles * triples << endl;
	return 0;
}

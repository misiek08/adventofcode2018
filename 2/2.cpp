#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;
enum Occured { TWICE = 1, THRICE = 2 };

int distance(string first, string second) {
	int dist = 0;
	for (int i = 0; i < first.length(); i++) {
		if (first[i] != second[i]) dist++;
	}
	return dist;
}

string find_by_distance(vector<string> lines, string needle, int needed_distance) {
	for (auto it = lines.begin(); it != lines.end(); it++) {
		if (distance(needle, *it) == needed_distance) {
			return *it;
		}
	}
	return "";
}

int main(int argc, char** argv) {
	char* file = argv[1];
	string line, found;
	ifstream infile(file);

	long doubles, triples = 0;
	int needed_distance = atoi(argv[2]);

	vector<string> changes;

	while(infile >> line) {
		changes.push_back(line);
	}

	for (auto it = changes.begin(); it != changes.end(); it++) {
		found = find_by_distance(changes, *it, needed_distance);
		if (found != "") {
			line = *it;
			break;
		}
	}

	cout << line << endl;
	cout << found << endl;

	return 0;
}

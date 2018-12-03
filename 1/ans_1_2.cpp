#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
	char* file = argv[1];
	string line;
	ifstream infile(file);
	vector<long long> changes;

	while(infile >> line) {
		changes.push_back(stoll(line));
	}

	long long state = 0;
	map<long long, int> seen;

	vector<long long>::iterator it = changes.begin();

	while(seen[state] == 0) {
		seen[state] = 1;
		state += *it;

		it++;
		if (it == changes.end())
			it = changes.begin();
	}

	cout << "result: " << state << endl;
	return 0;
}

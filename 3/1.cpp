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

	long doubles, triples = 0;

	map<long, map<long,long>> claims;
	long x, y, w, h;
	char id[255];
	while(getline(infile, line)) {
		sscanf(line.c_str(), "#%s @ %ld,%ld: %ldx%ld", id, &x, &y, &w, &h);
		for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + h; j++) {
				claims[i][j] += 1;
			}
		}
	}
	int claimed = 0;
	for (auto it = claims.begin(); it != claims.end(); it++) {
		for (auto itt = it->second.begin(); itt != it->second.end(); itt++) {
			if (itt->second >= 2) claimed++;
		}
	}	

	cout << "result: " << claimed << endl;

	ifstream infile2(file);
	while(getline(infile2, line)) {
		bool overlap = false;
		sscanf(line.c_str(), "#%s @ %ld,%ld: %ldx%ld", id, &x, &y, &w, &h);
		for (int i = x; i < x + w; i++) {
			for (int j = y; j < y + h; j++) {
				if (claims[i][j] > 1) overlap = true;
			}
		}
		if (!overlap) {
			cout << "not overlapping: " << id << endl;
		}
	}

	return 0;
}

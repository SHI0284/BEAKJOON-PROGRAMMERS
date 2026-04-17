#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int score = 1;
		int n;
		map<string, int> fashion;
		cin >> n;

		for (int j = 0; j < n; j++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (fashion.find(s2) != fashion.end()) fashion[s2]++;
			else fashion[s2] = 1;
		}
		
		for (auto iter = fashion.begin(); iter != fashion.end(); iter++) score *= (iter->second) + 1;
		cout << score - 1 << '\n';
	}
	return 0;
}
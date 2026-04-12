#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string input;
	while (true) {
		bool ans = 1;
		cin >> input;
		if (input == "0") break;

		for (int i = 0; i < input.length() / 2; i++) {
			if (input[i] != input[input.length() - 1-i]) {
				ans = 0;
				break;
			}
		}
		if (ans) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	return 0;
}
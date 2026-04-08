#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct person {
	int age, idx;
	string name;
};

bool compare(const person& now, const person& last) {
	if (now.age != last.age) return now.age < last.age;
	return now.idx < last.idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	person num[100001];

	for (int i = 0; i < T; i++) {
		cin >> num[i].age >> num[i].name;
		num[i].idx = i;
	}

	sort(num, num + T, compare);

	for (int i = 0; i < T; i++) cout << num[i].age << " " << num[i].name << "\n";

}
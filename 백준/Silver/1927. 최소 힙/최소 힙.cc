#include <iostream>
#include <queue>
using namespace std;

int heap[100001];
priority_queue<int, vector<int>, greater<int>>pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			if (pq.empty()) cout << 0 << "\n";
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else pq.push(num);
	}
	return 0;
}

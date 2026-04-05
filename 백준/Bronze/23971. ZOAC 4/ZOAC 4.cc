#include <iostream>
using namespace std;

int main() {
	int H, W, N, M;
	cin >> H >> W >> N >> M;

	int row = (H + N) / (N + 1);
	int col = (W + M) / (M + 1);

	cout << row * col << '\n';

	return 0;

}
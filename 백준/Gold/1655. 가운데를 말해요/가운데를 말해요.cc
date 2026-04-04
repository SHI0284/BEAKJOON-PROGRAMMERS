#include <iostream>
#include <queue>
using namespace std;

// 지금까지 들어온 수에서 중앙값을 출력하면 됨.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int N;
	cin >> N;

	//left: 작은 값들을 저장하는 최대 힙
	priority_queue<int> left;

	//right: 큰 값들을 저장하는 최소 힙
	priority_queue<int, vector<int>, greater<int>> right;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// 두 힙의 크기가 같으면 left에 넣음
		//Left가 항상 하나 더 많거나 같은 개수를 가지게 하기 위함.
		// 네 그러는 편이 편함.
		if (left.size() == right.size()) {
			left.push(num);
		}
		else {
			right.push(num);
		}

		//Left의 top은 왼쪽 그룹의 최댓값
		//right의 top은 오른쪽 그룹의 최솟값
		// 만약 Left.top() > right.top() 이면 서로 바꿔야 함.
		// 이거 확인해줘야함
		if (!left.empty() && !right.empty() && left.top() > right.top()) {
			int a = left.top();
			int b = right.top();
			left.pop();
			right.pop();

			left.push(b);
			right.push(a);

		}
		//현재 가운데 값 출력하면 됨
		// 문제 보면 가운데는 원소 개수가 짝수일 때 더 작은 값이므로
		//left.top() 출력 ㄱㄱ
		cout << left.top() << '\n';
		
	}
	return 0;
}
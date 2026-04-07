#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	double element;
	vector <double> v;
	double mean = 0;
	double median = 0;
	double mode = 0;
	double range = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> element;
		v.push_back(element);
	}

	// 산술 평균
	for (int i = 0; i < N; i++) {
		mean += v[i];
	}
	mean = round(mean / N);
	if (mean == -0) mean = 0;

	// 중앙값
	sort(v.begin(), v.end());
	if (N == 1) {
		median = v[0];
	}
	else median = v[(N - 1) / 2];

	// 최빈값
	int count[8001] = { 0, };
	for (int i = 0; i < N; i++) {
		// 4-1. 0 또는 양수일 경우
		if (v[i] >= 0) {
			count[int(v[i])]++;
		}
		// 4-2. 음수일 경우
		else {
			count[int(fabs(v[i])) + 4000]++;
		}
	}

	// 최빈값이 여러개일 경우
	int max = count[0];
	int index = 0;
	for (int i = 0; i < 8001; i++) {
		if (max < count[i]) {
			index = i;
			max = count[i];
		}
	}

	vector <double> mv;
	for (int i = 0; i < 8001; i++) {
		if (max == count[i]) {
			if (i <= 4000) {
				mv.push_back(i);
			}
			else {
				mv.push_back((i - 4000) * (-1));
			}
		}
	}

	// 정렬. 두번째로 작은 최빈값 출력
	sort(mv.begin(), mv.end());
	// 최빈값이 하나인 경우
	if (mv.size() == 1) {
		mode = mv[0];
	}
	else {
		mode = mv[1];
	}


	// 범위 (최댓값과 최솟값의 차이)
	range = v[N - 1] - v[0];


	cout << mean << endl;
	cout << median << endl;
	cout << mode << endl;
	cout << range << endl;

	return 0;


}
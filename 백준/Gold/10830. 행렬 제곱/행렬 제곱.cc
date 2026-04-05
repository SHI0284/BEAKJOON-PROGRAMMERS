#include <iostream>
#include <vector>
using namespace std;

int N;
long long B;

// 두 행렬을 곱하는 함수
vector<vector<int>> multiply(const vector<vector<int>>& A, const vector<vector<int>>& Bmat) {
    vector<vector<int>> result(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * Bmat[k][j];
                result[i][j] %= 1000;
            }
        }
    }

    return result;
}

// 행렬 A를 power 제곱하는 함수
vector<vector<int>> powerMatrix(vector<vector<int>> matrix, long long power) {
    // 지수가 1이면 자기 자신 반환
    if (power == 1) {
        return matrix;
    }

    // 절반 먼저 계산
    vector<vector<int>> half = powerMatrix(matrix, power / 2);

    // half * half
    vector<vector<int>> result = multiply(half, half);

    // 지수가 홀수면 matrix를 한 번 더 곱해줌
    if (power % 2 == 1) {
        result = multiply(result, matrix);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B;

    vector<vector<int>> A(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] %= 1000; // 미리 1000으로 나눠줌
        }
    }

    vector<vector<int>> answer = powerMatrix(A, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] % 1000 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
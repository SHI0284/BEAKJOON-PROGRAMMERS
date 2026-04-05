#include <iostream>
using namespace std;

const long long MOD = 1000000007;

// a^b % MOD 를 구하는 함수
long long power(long long a, long long b) {
    long long result = 1;

    while (b > 0) {
        // b가 홀수이면 현재 a를 result에 곱함
        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }

        // a를 제곱해가면서 지수를 줄임
        a = (a * a) % MOD;
        b /= 2;
    }

    return result;
}

int main() {
    long long N, K;
    cin >> N >> K;

    long long numerator = 1;   // N!
    long long denominator = 1; // K! * (N-K)!

    // N! 계산
    for (long long i = 1; i <= N; i++) {
        numerator = (numerator * i) % MOD;
    }

    // K! 계산
    for (long long i = 1; i <= K; i++) {
        denominator = (denominator * i) % MOD;
    }

    // (N-K)! 계산
    for (long long i = 1; i <= N - K; i++) {
        denominator = (denominator * i) % MOD;
    }

    // denominator의 모듈러 역원 = denominator^(MOD-2)
    long long inverse = power(denominator, MOD - 2);

    // 최종 결과
    cout << (numerator * inverse) % MOD << '\n';

    return 0;
}
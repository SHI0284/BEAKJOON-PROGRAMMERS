#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dynamic

int main() {

    int N, K;
    cin >> N >> K; // N: 물건 개수, K: 최대 무게

    // dp[j] = "무게 j까지 담을 수 있을 때 얻을 수 있는 최대 가치"
    vector<int> dp(K + 1, 0);

    // 물건 하나씩 처리
    for (int i = 0; i < N; i++) {
        int W, V;
        cin >> W >> V; // W: 물건 무게, V: 물건 가치

        // 뒤에서부터 순회해야 같은 물건을 여러 번 쓰는 것을 방지
        for (int j = K; j >= W; j--) {
            // 현재 물건을 넣지 않는 경우 vs 넣는 경우 비교
            // dp[j]          : 안 넣는 경우
            // dp[j - W] + V  : 넣는 경우
            dp[j] = max(dp[j], dp[j - W] + V);
        }
    }

    // 최대 무게 K에서의 최대 가치 출력
    cout << dp[K] << '\n';

    return 0;
}
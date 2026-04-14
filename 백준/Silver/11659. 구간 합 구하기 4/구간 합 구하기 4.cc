#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int v[100001];
    int prefix[100001] = {0};

    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        prefix[i] = prefix[i - 1] + v[i];
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}
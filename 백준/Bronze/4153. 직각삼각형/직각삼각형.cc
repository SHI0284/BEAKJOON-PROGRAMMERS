#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        // 종료 조건
        if (a == 0 && b == 0 && c == 0) break;

        // 정렬해서 가장 큰 값이 c가 되게
        int arr[3] = { a, b, c };
        sort(arr, arr + 3);

        // 피타고라스 정리 확인
        if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1])
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}
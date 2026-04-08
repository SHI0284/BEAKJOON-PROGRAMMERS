#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        queue<pair<int, int>> q;
        priority_queue<int> pq; 
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < n; j++) {
            int num;
            cin >> num;
            q.push({ j,num });
            pq.push(num);
        }

        int count = 0;

        while (1) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if (pq.top() == value) {
                pq.pop();
                count += 1;
                if (index == m) {
                    cout << count << '\n';
                    break;
                }
            }
            else {
                q.push({ index,value });
            }
        }
    }
}

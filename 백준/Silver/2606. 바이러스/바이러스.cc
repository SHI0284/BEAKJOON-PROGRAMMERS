#include <iostream>
#include <queue>
using namespace std;

int V, E;
const int MAX = 101;
int map[MAX][MAX] = { 0, };
bool visited[MAX] = { 0, };
int ans = 0; 
queue<int> q;

void BFS(int v) {
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 1; i <= V; i++) {
            if (map[cur][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
                ans++;
            }
        }
    }
}

int main() {
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	BFS(1);

	cout << ans;
}

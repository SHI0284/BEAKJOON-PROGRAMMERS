#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int answer = 0;

// 현재 보드에서 가장 큰 값 찾기
int getMax(const vector<vector<int>>& board) {
    int mx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mx = max(mx, board[i][j]);
        }
    }
    return mx;
}

// 왼쪽으로 이동
vector<vector<int>> moveLeft(const vector<vector<int>>& board) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        vector<int> line;

        // 0이 아닌 숫자만 추출
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) line.push_back(board[i][j]);
        }

        int idx = 0;
        for (int j = 0; j < (int)line.size(); j++) {
            // 다음 숫자와 같으면 합치기
            if (j + 1 < (int)line.size() && line[j] == line[j + 1]) {
                newBoard[i][idx++] = line[j] * 2;
                j++; // 이미 합쳤으므로 다음 숫자는 건너뜀
            }
            else {
                newBoard[i][idx++] = line[j];
            }
        }
    }

    return newBoard;
}

// 오른쪽으로 이동
vector<vector<int>> moveRight(const vector<vector<int>>& board) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        vector<int> line;

        // 오른쪽부터 0이 아닌 숫자 추출
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] != 0) line.push_back(board[i][j]);
        }

        int idx = N - 1;
        for (int j = 0; j < (int)line.size(); j++) {
            if (j + 1 < (int)line.size() && line[j] == line[j + 1]) {
                newBoard[i][idx--] = line[j] * 2;
                j++;
            }
            else {
                newBoard[i][idx--] = line[j];
            }
        }
    }

    return newBoard;
}

// 위로 이동
vector<vector<int>> moveUp(const vector<vector<int>>& board) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));

    for (int j = 0; j < N; j++) {
        vector<int> line;

        // 위쪽부터 0이 아닌 숫자 추출
        for (int i = 0; i < N; i++) {
            if (board[i][j] != 0) line.push_back(board[i][j]);
        }

        int idx = 0;
        for (int i = 0; i < (int)line.size(); i++) {
            if (i + 1 < (int)line.size() && line[i] == line[i + 1]) {
                newBoard[idx++][j] = line[i] * 2;
                i++;
            }
            else {
                newBoard[idx++][j] = line[i];
            }
        }
    }

    return newBoard;
}

// 아래로 이동
vector<vector<int>> moveDown(const vector<vector<int>>& board) {
    vector<vector<int>> newBoard(N, vector<int>(N, 0));

    for (int j = 0; j < N; j++) {
        vector<int> line;

        // 아래쪽부터 0이 아닌 숫자 추출
        for (int i = N - 1; i >= 0; i--) {
            if (board[i][j] != 0) line.push_back(board[i][j]);
        }

        int idx = N - 1;
        for (int i = 0; i < (int)line.size(); i++) {
            if (i + 1 < (int)line.size() && line[i] == line[i + 1]) {
                newBoard[idx--][j] = line[i] * 2;
                i++;
            }
            else {
                newBoard[idx--][j] = line[i];
            }
        }
    }

    return newBoard;
}

// DFS로 5번 이동까지 탐색
void dfs(int depth, vector<vector<int>> board) {
    answer = max(answer, getMax(board));

    if (depth == 5) return;

    dfs(depth + 1, moveLeft(board));
    dfs(depth + 1, moveRight(board));
    dfs(depth + 1, moveUp(board));
    dfs(depth + 1, moveDown(board));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, board);

    cout << answer << '\n';
    return 0;
}
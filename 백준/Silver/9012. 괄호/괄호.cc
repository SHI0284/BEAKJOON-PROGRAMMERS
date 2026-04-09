#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N > 0) {
        N--;
        string input;
        cin >> input;

        stack<char> temp;
        string answer = "YES";

        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(') {
                temp.push(input[i]);
            }
            else if (!temp.empty() && input[i] == ')' && temp.top() == '(') {
                temp.pop();
            }
            else {
                answer = "NO";
                break;
            }
        }

        if (!temp.empty()) answer = "NO";

        cout << answer << '\n';
    }

    return 0;
}
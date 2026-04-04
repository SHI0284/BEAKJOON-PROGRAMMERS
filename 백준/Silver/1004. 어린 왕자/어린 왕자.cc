#include <iostream>
#include <cmath>
using namespace std;

// 원이랑 선이 교차하는지가 아닌 출발점과 도착점이 같은 원 안에 있는지 비교
// 경우의 수 3가지
//     시작    |      끝      |     결과
//     밖      |      밖      |     통과 안 함
//     안      |      안      |     통과 안 함
//     안(밖)  |      밖(안)  |     통과 함

//그래서 SIC != EIC 이 조건이 핵심


int main() {
    int temp; // 테스트 케이스 개수
    cin >> temp;

    // 테스트 케이스 반복
    for (int i = 0; i < temp; i++) {
        int xs, ys, xe, ye; // 시작점 (xs, ys), 도착점 (xe, ye)
        cin >> xs >> ys >> xe >> ye;

        int num; // 원(행성계) 개수
        cin >> num;

        int digit = 0; // 경계 통과 횟수

        // 각 원에 대해 검사
        for (int j = 0; j < num; j++) {
            int px, py, radius; // 원의 중심 (px, py), 반지름
            cin >> px >> py >> radius;

            // 시작점이 원 내부에 있는지 확인
            bool SIC = (px - xs) * (px - xs) + (py - ys) * (py - ys) <= radius * radius;

            // 도착점이 원 내부에 있는지 확인
            bool EIC = (px - xe) * (px - xe) + (py - ye) * (py - ye) <= radius * radius;

            // 시작점과 도착점이 "서로 다른 상태"라면
            // (하나는 내부, 하나는 외부)
            // → 원의 경계를 반드시 통과함
            if (SIC != EIC) {
                digit++;
            }
        }

        // 결과 출력
        cout << digit << "\n";
    }
}
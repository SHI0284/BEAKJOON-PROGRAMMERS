#include <iostream>
using namespace std;

long long fiboarr[50] = { 0,1, };
long long fibonacci(int N){
    if (N == 0 || N == 1)
        return fiboarr[N];
    else if (fiboarr[N] == 0)
        fiboarr[N] = fibonacci(N - 1) + fibonacci(N - 2);
    return fiboarr[N];
}

int main() {
    int num;

    cin >> num;

    int temp;

    for (int i = 0; i < num; i++)
    {
        cin >> temp;
        if (temp == 0)
            cout << "1 0" << '\n';
        else
            cout << fibonacci(temp - 1) << ' ' << fibonacci(temp) << '\n';
    }
}
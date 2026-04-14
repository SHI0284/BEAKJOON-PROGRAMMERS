#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n; cin >> n;

	vector<int> dp(1000001);
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;


	for (int i = 4; i <= 1000000; i++)
	{
		int count = 0;

		dp[i] = dp[i - 1] + 1;

		if (i % 3 == 0)
		{
			count = 1 + dp[i / 3];
			if (count < dp[i]) { dp[i] = count; }
		}
		if (i % 2 == 0)
		{
			count = 1 + dp[i / 2];
			if (count < dp[i]) { dp[i] = count; }
		}
	}

	cout << dp[n];

}
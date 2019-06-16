
// https://www.acmicpc.net/problem/2749

#include <iostream>
#include <vector>

using namespace std;

int Solution(long long& _number)
{
	// using pisano period
	// divisor = 10^k = 100'0000 = 10^6
	// the period = 15 * 10^(k-1) = 15 * 10'0000
	vector<int> fibs(150'0000);
	fibs[0] = 0;
	fibs[1] = 1;
	for (int i = 2; i < fibs.size(); ++i)
	{
		fibs[i] = fibs[i - 1] + fibs[i - 2];
		fibs[i] %= 100'0000;
	}

	return fibs[_number % 150'0000];
}

int main()
{
	long long number = 0;
	cin >> number;
	cout << Solution(number) << endl;
	return EXIT_SUCCESS;
}
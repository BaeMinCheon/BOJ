
// https://www.acmicpc.net/problem/11444

#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<long long>>;
using Row = vector<long long>;

Matrix MatMul(Matrix& _a, Matrix& _b)
{
	const auto size = _a.size();
	Matrix result(size, Row(size, 0));
	for (int row = 0; row < size; ++row)
	{
		for (int col = 0; col < size; ++col)
		{
			for (int i = 0; i < size; ++i)
			{
				result[row][col] += _a[row][i] * _b[i][col];
				result[row][col] %= 10'0000'0007;
			}
		}
	}
	return result;
}

long long Solution(long long _number)
{
	// algorithm; result = (multiplier)^n
	//	|	F_{n+1}	F_n		|		|	1	1	| ^ n
	//	|					|	=	|			|
	//	|	F_n		F_{n-1}	|		|	1	0	|
	Matrix result = { {1, 0}, {0, 1} };
	Matrix multiplier = { {1, 1}, {1, 0} };
	while (_number > 0)
	{
		// _number is odd
		if (_number & 1)
		{
			result = MatMul(result, multiplier);
		}
		multiplier = MatMul(multiplier, multiplier);
		_number /= 2;
	}
	return result[0][1];
}

int main()
{
	long long number = 0;
	cin >> number;
	cout << Solution(number) << endl;
	return EXIT_SUCCESS;
}
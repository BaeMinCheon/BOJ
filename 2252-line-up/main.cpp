
//	https://www.acmicpc.net/problem/2252

#include <iostream>
#include <stack>
#include <vector>
#include <array>

using namespace std;
using Graph = vector<vector<int>>;

int N;
int M;
Graph Data;
stack<int> Result;
vector<bool> Visits;

bool flag;
void DFS(int _low)
{
	Visits[_low] = true;
	for (int high = 0; high < Data[_low].size(); ++high)
	{
		if (Visits[Data[_low][high]] == false)
		{
			DFS(Data[_low][high]);
		}
	}
	Result.push(_low);
}

void Solution()
{
	for (int i = 0; i < N; i++)
	{
		if (Visits[i] == 0)
		{
			DFS(i);
		}
	}
	
	while (Result.empty() == false)
	{
		cout << Result.top() + 1 << " ";
		Result.pop();
	}
	cout << endl;
}

int main()
{
	cin >> N;
	cin >> M;

	Data.resize(N, vector<int>());
	Visits.resize(N, false);
	for (int i = 0; i < M; i++)
	{
		int A = 0;
		cin >> A;
		A -= 1;
		
		int B = 0;
		cin >> B;
		B -= 1;

		Data[A].push_back(B);
	}

	Solution();

	return EXIT_SUCCESS;
}
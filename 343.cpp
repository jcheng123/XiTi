#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n) 
{
	vector<int> mul(59, 0);
	mul[1] = 0;
	mul[2] = 1;

	for(auto i = 3; i <= n; ++i)
	{
		for(auto j = 1; j < i; ++j)
		    mul[i] = max(mul[i], max(mul[i - j] * j, (i - j) * j));
	}

	return mul[n];

}

int main()
{
	int n = 10;
	cout << integerBreak(n) << endl;
	return 0;
}

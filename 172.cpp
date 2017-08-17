#include <iostream>
#include <cstdlib>

using namespace std;

int trailingZeros(int n)
{
	int sum = 0;
	int m = n;

    while(m)
    {
        sum += m / 5;
        m = m / 5;
    }

    return sum;
}

int main(int argc, char** argv)
{
	int n = atoi(argv[1]);
	cout << trailingZeros(n) << endl;
	return 0;
}
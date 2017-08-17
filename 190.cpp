#include <iostream>
#include <bitset>

using namespace std;

uint32_t reverseBits(uint32_t n)
{
	bitset<32> u(n);
	bitset<32> v;

	for(auto i = 0; i != 32; ++i)
	{
		v[i] = u[31 - i];
	}
	
	uint32_t res = v.to_ulong();
	return res;
}

int main()
{
	uint32_t num = 43261596;

	cout << reverseBits(num) << endl;

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <cstring>

using namespace std;

int countPrimes(int n)
{
  if(n <= 2) return 0;
  vector<int> vec(n - 2, 0);
  vector<int> vi(n - 2, 0);
  iota(vec.begin(), vec.end(), 2);

  int prime = 2;
  int idx = 0;

  while(prime * prime <= vec[vec.size() - 1])
  {
      int i = 2;
      while((i * prime) <= vi.size() + 1)
      {
      	vi[i*prime - 2] = 1;
      	++i;
      }
      ++idx;
      if(vi[idx] == 0) prime = vec[idx];
  }

  int p = count(vi.begin(), vi.end(), 0);
  return p;

}

int main()
{
	    
    int num = 10;
    //countPrimes(num);
	cout <<"i : " << num <<"\t"<< countPrimes(num) << endl;
	return 0;
}
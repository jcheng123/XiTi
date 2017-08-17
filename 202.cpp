#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isHappy(int n) 
{
   int m = n;
   int sum = n;

	  while(sum > 4)
	  {  
	  	   m = sum;
	  	   sum = 0;
		   while(m)
		   {
		     sum += pow(m % 10, 2);
		     m /= 10;
		   }
		   cout << " middle sum : " << sum << endl;
	  }
   
  if(sum == 1) return true;
  return false;
}

int main(int argv, char* argc[])
{
	int n = atoi(argc[1]);
	cout << "number : " << n << "\t" << "is happy number ? " << (isHappy(n) ? "yes! " : "no! ") << endl;
	return 0;
}
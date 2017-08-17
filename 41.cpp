#include <iostream>
#include <vector>

using namespace std;

// use two variables to point to 
// the highest digit and the lowest digit
bool isPalindrome(int x) 
{  
  int tmp = x;
  int res = 0;
 
  while(tmp)
  {
  	res = (res + tmp % 10);
  	// cout << " the value in middle : " << res << endl;
  	tmp = tmp / 10;
  	if(tmp) res *= 10;
  }
  cout << "inverse number : " <<"\t" << res << endl;
  return true;
	
}


int main()
{
	cout<< isPalindrome(1298) << endl;
}
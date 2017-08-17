#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
       
       if(n == 0) return true;
       if(n == 1) return true;
       int num = n;
       while(num > 1)
       {

           if(num & 1 == 1) return false;
           else num = num >> 1;
       }
       return true;
   }

int main()
{

  int num = 16;
  cout << isPowerOfTwo(num) << endl;
  return 0;
}

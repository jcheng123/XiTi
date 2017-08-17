#include <iostream>
#include <string>

using namespace std;

string convertToBase7(int num)
{
	string s = "";
    int n = num;
	if(num < 0) num = abs(num);

	while(num)
	{
		s = to_string(num % 7) + s;
		num = num / 7;
	}
	if(n < 0) s = '-' + s;

	return s;
}

int main()
{
	string str = convertToBase7(-8);
	cout << str << endl;
	return 0;
}
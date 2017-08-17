#include <iostream>
#include <vector>
#include <map>

using namespace std;

int distributeCandies(vector<int>& candies) 
{
	map<int, int> map_n;
	for(auto i = 0; i != candies.size(); ++i)
		map_n[candies[i]] ++;
    
    if(map_n.size() >= candies.size() / 2) return candies.size()/2;
    return map_n.size();
}

int main()
{
	vector<int> can = {1,1,2,3};
	cout << distributeCandies(can) << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool compare(int x, int y)
{
	return (x > y);
}

vector<int> topKFrequent(vector<int>& nums, int k)
{
	 vector<int> res;
	 if(nums.empty()) return res;

	 map<int, int> map_n;
	 multimap<int, int, bool(*)(int, int)> map_m(compare);

     for(auto i = 0; i != nums.size(); ++i)
     	map_n[nums[i]]++;

     for(const auto& i : map_n)
     	map_m.insert({i.second, i.first});

     for(const auto& i : map_m)
     {
     	if(k != 0)
     	{
            res.push_back(i.second);
            k--;
     	}
     	else break;
     }

    return res;
}

int main()
{
	vector<int> nums = {1, 1, 1, 2, 2, 3};
	int k = 2;
	vector<int> tmp  = topKFrequent(nums, k);
	for(auto i : tmp)
		cout << i << endl;
	return 0;
}
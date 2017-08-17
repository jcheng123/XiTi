#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

using namespace std;

bool compare(int x, int y)
{
	return x > y;
}

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
	map<string, pair<int, size_t>> res;
	multimap<int, string> r;

	vector<string> str;

	int max_len = list1.size() + list2.size();


	for(auto i = 0; i < list1.size(); ++i)
	{
		(res[list1[i]]).second += i;
		(res[list1[i]]).first  ++;
	}


	for(auto j = 0; j < list2.size(); ++j)
	{
		(res[list2[j]]).second += j;
		(res[list2[j]]).first ++;
	}
    
    
	for(auto i = res.begin(); i != res.end();)
		if((*i).second.first == 1) res.erase(i++);
	    else ++i;

	for(auto j = res.begin(); j != res.end(); ++j)
    {
        r.insert({(*j).second.second, (*j).first});
    }
    
    int num = (r.begin()) -> first;

    auto iter = r.begin();

    while(iter != r.end() && iter -> first == num)
    {
    	str.push_back(iter -> second);
    	iter ++;
    }

    
    
	return str;
}

/*
 * ["Shogun","Tapioca Express","Burger King","KFC"]
 * ["KFC","Shogun","Burger King"]
 */
int main()
{
	vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
	vector<string> list2 = {"KFC","Shogun","Burger King"};
	vector<string> s = findRestaurant(list1, list2);
	for(auto i : s)
		cout << i << endl;
	return 0;
}

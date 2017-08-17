#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxProfit(vector<int>& prices)
{
	int n = prices.size();
	vector<int> Max(n, 0);
	Max[n - 1] = prices[n - 1];

	for(int i = n - 2; i >= 0; --i)
	{
		Max[i] = max(Max[i + 1], prices[i + 1]);
	}
	int max_profit = 0;

	for(auto i = 0; i <= n - 1; ++i)
	{
       max_profit = max(max_profit, Max[i] - prices[i]);
	}
    
    return max_profit;

}

int main()
{
	vector<int> prices = {7, 6, 4, 3, 1};
	cout << maxProfit(prices) << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int H(vector<int>& height)
{
   int sc = height.size();
   int area = 0;
   vector<vector<int>> len(sc, vector<int>(sc, 0));

   for(auto i = 0; i != sc; ++i)
   	  for(auto j = i; j != sc; ++j)
   	  {
   	  	 len[i][j] = (j - i) * min(height[i], height[j]);
   	  	 area = max(area, len[i][j]);   	 
   	  }

   return area;
}

int main()
{
	vector<int> h = {3, 2, 1, 3};
	cout << H(h) << endl;
	return 0;
} 
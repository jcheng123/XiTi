#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    if(matrix.empty()) return false;
    int m = matrix.size(), n = matrix[0].size();

    int i = 0, j = n - 1;
    while(i < m && j >= 0)
    {
      if(matrix[i][j] > target) j--;
      else if(matrix[i][j] < target) i++;
           else return true;
    }
    return false;
}


int main()
{
  vector<vector<int>> num = {
                             {1, 4, 7, 11, 15},
                             {2, 5, 8, 12, 19},
                             {3, 6, 9, 16, 22},
                             {10,13, 14, 17, 24},
                             {18, 21, 23, 26, 30}
                           };
  int target = 0;
  cout << searchMatrix(num, target) << endl;
  return 0;
}

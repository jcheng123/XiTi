#include <iostream>
#include <vector>

using namespace std;

int arrayNesting(vector<int>& nums)
{
   vector<int> visited(nums.size(), 0);
   int max_num = 0;
   int cur_num = 0;
   int iter;

   for(auto i = 0; i < nums.size(); ++i)
   {
     if(visited[i] == 0)
     {
       iter = i;
       cur_num ++;

       while(nums[iter] != i)
       {
          visited[iter] = 1;
          iter = nums[iter];
          cur_num++;
       }

       max_num = max(max_num, cur_num);
       cur_num = 0;
     }
   }
   return max_num;

 }


 int main()
 {
   vector<int> num = {5, 4, 0, 3, 1, 6, 2};
   cout << arrayNesting(num) << endl;
   return 0;
 }

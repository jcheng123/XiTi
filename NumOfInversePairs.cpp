#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int InversePairs(vector<int> data) {
        int mid=data.size()/2;
        vector<int>pre;
        pre.assign(data.begin(),data.begin()+mid);
        vector<int>after;
        after.assign(data.begin()+mid+1,data.end());
        vector<int>data_pre(pre);
        vector<int>data_after(after);
        sort(data_pre.begin(),data_pre.end());
        sort(data_after.begin(),data_after.end());
        int i=0;
        int j=0;
        int NumOfInversePairs=0;
        while(i<data_pre.size()&&j<data_after.size()){
              if(data_pre[i]>data_after[j]) {NumOfInversePairs++;j++;} 
            else i++;
        }
        return NumOfInversePairs+InversePairs(pre)+InversePairs(after);
   }
       
int main(){
 int d[]={1,2,3,4,5,6,7,0};
 vector<int>data;
 for(int i=0;i!=8;i++)
    data.push_back(d[i]);
 int k=InversePairs(data);
 cout<<k<<endl;
 return 0;
}

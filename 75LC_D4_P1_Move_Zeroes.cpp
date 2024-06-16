#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=nums.size();
        //Approach 1
        // while(i<j){
        //     if(nums[i]==0)
        //         nums.erase(nums.begin()+i), nums.push_back(0),j--;
        //     else
        //         i++;
        // }
        //Approach 2
        for(int l=0;l<j;l++)
            if(nums[l]!=0)
                nums[i++]=nums[l];
        for(int l=i;l<j;l++)
            nums[l]=0;
    }
};
int main() {
   Solution s;
    vector<int> v{0,1,0,3,12};
   s.moveZeroes(v);
    for(auto i:v)
         cout<<i<<" "; 
}
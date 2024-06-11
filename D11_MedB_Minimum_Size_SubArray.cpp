#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=1, minLen=nums.size()+1;
        vector<int> preSum(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++)
            preSum[i+1] = preSum[i]+nums[i];
        while(r<=nums.size()){
            cout<<"min: "<<minLen<<" sum: "<<(preSum[r]-preSum[l])<<" l: "<<l<<"r: "<<r<<endl;
            if((preSum[r]-preSum[l])>=target){
                minLen = min(minLen,r-l);
                l++;
            }
            else
                r++;
        }
        return minLen==nums.size()+1?0:minLen;
    }
};
int main() {
    Solution s;
    vector<int> v{2,3,1,2,4,3};
    cout<<s.minSubArrayLen(7,v);
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        // 1 2 1 2 3
        int count = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                count++, nums[i]++;
            else if(nums[i]<nums[i-1])
                count+=nums[i-1]-nums[i]+1, nums[i] = nums[i-1]+1;
        }
        return count;
    }
};
int main() {
    Solution s;
    vector<int> v{1,2,4,4};
    cout<<s.minIncrementForUnique(v);
}
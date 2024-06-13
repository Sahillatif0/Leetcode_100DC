#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first_small = INT_MAX;
        int second_small = INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<=first_small)
                first_small=nums[i];
            else if( nums[i]<= second_small )
                second_small= nums[i];
            else
                return true;
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<int> v{2,1,5,4,6};
    cout<<s.increasingTriplet(v);
}
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int l=0,r=nums.size()-1, mid;
        while (l<=r){
            mid = (l+r)/2;
            if((mid==(nums.size()-1) || nums[mid]!=nums[mid+1]) && (mid==0 || nums[mid]!=nums[mid-1]))
                return nums[mid];
            else if((mid%2 && (mid==(nums.size()-1) || nums[mid]==nums[mid+1])) || (mid%2==0 && (mid==0 || nums[mid]==nums[mid-1])))
                r = mid%2?mid-1:mid-2;
            else if((mid==0 || (nums[mid]==nums[mid-1]) && mid%2) || ((mid==(nums.size()-1) || nums[mid]==nums[mid+1]) && mid%2==0))
                l = mid%2?mid+1:mid+2;
        }
        return nums[mid];
    }
};
int main() {
    Solution s;
    vector<int>v{1,2,2,3,3};
    cout<<s.singleNonDuplicate(v);
}

// 0 0 1 2 2 3 3 
// l = 0, r = 6;
// mid = 3;
// nums[mid] = 2;
// 0 0 1 1 2 3 3
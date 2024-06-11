#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1, mid;
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]<target)
                l = mid+1;
            else
                r = mid-1;
        }
        return l;
    }
};
int main() {
    Solution s;
    vector<int> v{1,3,5,6};
    cout<<s.searchInsert(v,2);
}
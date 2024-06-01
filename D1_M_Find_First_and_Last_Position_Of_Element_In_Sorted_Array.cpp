#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        bool lf = false, rf = false;
        while(l<=r){
            if(nums[l]!=target)
                l++;
            else
                lf = true;
            if(nums[r]!=target)
                r--;
            else
                rf = true;
            if(lf && rf)
                return {l, r};
        }
        return {-1, -1};
    }
};
int main() {
    Solution s;
    vector<int> v{5, 5,7 ,8,3,8,8};
    vector<int> d =  s.searchRange(v,8);
    cout<<"{"<<d[0]<<", "<<d[1]<<"}";
}
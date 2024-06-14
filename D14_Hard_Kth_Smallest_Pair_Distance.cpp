#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool isCountPairSmall(vector<int> nums, int mid, int k){
        int l=0,r=1, cnt=0;
        while(r<nums.size()){
            if(nums[r]-nums[l]<=mid)
                cnt+=r-l, r++;
            else
                l++;
        }
        return cnt<k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0, r=nums[nums.size()-1] - nums[0];
        while(l<r){
            int mid = (l+r)/2;
            if(isCountPairSmall(nums, mid, k))
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};
int main() {
    Solution s;
    vector<int> v{9,10,7,10,6,1,5,4,9,8};
    cout<<s.smallestDistancePair(v,18);
}
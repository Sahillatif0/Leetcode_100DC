#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt=0;
        for(int i=2;i<nums.size();i++){
            int l=0, r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i])
                    cnt+=r-l, r--;
                else
                    l++;
            }
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> v{2,2,3,4};
    cout<<s.triangleNumber(v);
}
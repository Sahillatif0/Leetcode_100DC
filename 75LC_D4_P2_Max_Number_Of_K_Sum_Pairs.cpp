#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1, cnt=0;
        sort(nums.begin(),nums.end());
        while(l<r){
            int sum = nums[l]+nums[r];
            if(sum<k)
                l++;
            else if(sum>k)
                r--;
            else
                l++,r--,cnt++;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> v{3,1,3,4,3};
    cout<<s.maxOperations(v,6);   
}
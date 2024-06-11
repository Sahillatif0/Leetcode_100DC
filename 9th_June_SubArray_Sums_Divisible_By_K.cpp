#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1);
        unordered_map<int, int> m;
        int cnt=0;
        for(int i=1;i<nums.size()+1;i++){
            sum[i] = (sum[i-1] + nums[i-1])%k;
            if(sum[i]<0)
                sum[i]+=k;
        }
        for(int i=0;i<sum.size();i++){
            if(m.find(sum[i])!=m.end())
                m[sum[i]]++;
            else
                m[sum[i]] = 0;
            cnt+=m[sum[i]];
        }
        return cnt;
    }
};
int main() {
    Solution s;
    // vector<int> v{4,5,0,-2,-3,1};
    vector<int> v{2,-2,2,-4};
    cout<<s.subarraysDivByK(v,6);
}
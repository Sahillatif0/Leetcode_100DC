#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> sum(nums.size()+1);
        unordered_map<int, int> m;
        for(int i=1;i<nums.size()+1;i++)
            sum[i] = (sum[i-1] + nums[i-1])%k;
        for(int i=0;i<sum.size();i++){
            if(m.find(sum[i])!=m.end()){
                if(i-m[sum[i]]>=2)
                    return true;
            }
            else
                m[sum[i]] = i;
        }
        return false;
    }
};
int main() {
  Solution s;
  vector<int>v{23,2,4,6,6};
  cout<<s.checkSubarraySum(v,7);  
}
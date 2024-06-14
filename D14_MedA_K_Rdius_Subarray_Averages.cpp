#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for(int i=1;i<=n;i++)
            prefix[i] = prefix[i-1]+nums[i-1];
        vector<int> ans;
        int l =  - k, r = k;
        while (r-k<n){
            if(l<0 || r>=n)
                ans.push_back(-1);
            else
                ans.push_back((prefix[r+1]-prefix[l])/(r-l+1));
            r++,l++;
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> v{7,4,3,9,1,8,5,2,6},a;
    a = s.getAverages(v,3);
    for(auto n:a){
        cout<<n<<" ";
    }
}
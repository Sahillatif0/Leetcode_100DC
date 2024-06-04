#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        vector<int> temp(n);
        for(int i=0;i<n;i++)
            temp[(i+k)%n] = nums[i];
        for(int i=0;i<n;i++)
            cout<<temp[i]<<" ";
    }

};
int main() {
    Solution s;
    vector<int>v{1,2,3,4,5,6,7};
    s.rotate(v,3);
}
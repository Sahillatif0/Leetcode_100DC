#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freq(3,0), nums2;
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        for(int i=0;i<3;i++)
            for(int j=0;j<freq[i];j++)
                nums2.push_back(i);
        nums = nums2;
    }
};
int main() {
    Solution s;
    vector<int> v={2,0,2,1,1,0};
    s.sortColors(v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
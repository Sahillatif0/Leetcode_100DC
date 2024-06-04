#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intNums, num1freq(1001,0), num2freq(1001,0);
        for(int i=0;i<nums1.size();i++)
            num1freq[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            num2freq[nums2[i]]++;
        for(int i=0;i<=1000;i++)
            if(num1freq[i]>0 && num2freq[i]>0)
                intNums.push_back(i);
        return intNums;
    }
};
int main() {
    Solution s;
    vector<int>v1{1,2,2,1}, v2{2,2};
    vector<int> v3 = s.intersection(v1, v2);
    for(int i=0;i<v3.size();i++)
        cout<<v3[i]<<" ";   
}
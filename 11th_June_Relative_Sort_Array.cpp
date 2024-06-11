#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> nums;
        sort(arr1.begin(),arr1.end());
        for(int i=0;i<arr1.size();i++)
            nums[arr1[i]] = arr2.size()+i;
        for(int i=0;i<arr2.size();i++)
            nums[arr2[i]] = i;
        sort(arr1.begin(), arr1.end(), [&](int a, int b){
            return nums[a]<nums[b];
        });
        return arr1;
    }
};
int main() {
    Solution s;
    vector<int> v1{2,3,1,3,2,4,6,7,9,2,19}, v2{2,1,4,3,9,6}, v3;
    v3 = s.relativeSortArray(v1,v2);
    for(int i=0;i<v3.size();i++)
        cout<<v3[i]<<" ";
}
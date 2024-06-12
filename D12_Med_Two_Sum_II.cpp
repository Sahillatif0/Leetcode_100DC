#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        while(l<r){
            if((numbers[l]+numbers[r])==target)
                return {l+1,r+1};
            else if((numbers[l]+numbers[r])>target)
                r--;
            else
                l++;
        }
        return {l+1,r+1};
    }
};
int main() {
    Solution s;
    vector<int> v{2,7,11,15},v2;
    v2 = s.twoSum(v,19);
    for(auto num:v2)
        cout<<num<<" ";
}
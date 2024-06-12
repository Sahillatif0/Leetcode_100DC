#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //Approach 1
        // vector<int> squares;
        // for(int i=0;i<nums.size();i++)
        //     squares.push_back(nums[i]*nums[i]);
        // sort(squares.begin(), squares.end());
        // return squares;
        // Approach 2
        int n = nums.size();
        vector<int> squares(n);
        int i=0, j=n-1;
        for(int p=n-1;p>=0;p--){
            if(abs(nums[i])>abs(nums[j]))
                squares[p] = (nums[i]*nums[i]), i++;
            else
                squares[p] = (nums[j]*nums[j]), j--;
        }
        return squares;
    }
};
int main() {
    Solution s;
    vector<int> v{-4,-1,0,6,7,10}, v2;
    v2 = s.sortedSquares(v);
    for(auto num:v2)
        cout<<num<<" ";
}
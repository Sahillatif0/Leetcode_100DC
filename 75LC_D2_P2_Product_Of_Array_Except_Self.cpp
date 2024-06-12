#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProducts(n+1, 1), sufProducts(n+1, 1), product(n);
        for(int i=0;i<n;i++){
            preProducts[i+1] = preProducts[i]*nums[i];
            sufProducts[n-1-i] = sufProducts[n-i]*nums[n-1-i];
        }
        for(int i=0;i<n;i++)
            product[i] = preProducts[i]*sufProducts[i+1];
        return product;
    }
};
int main() {
    Solution s;
    vector<int> v={-1,1,0,-3,3},v2;
    v2 = s.productExceptSelf(v);
    for(auto num:v2)
        cout<<num<<" ";
}
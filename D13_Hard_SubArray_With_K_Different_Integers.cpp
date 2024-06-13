#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size(), count=0, l=0, r=k-1;
        // bool expand = true;
        // while(r<n){
        //     cout<<"L: "<<l<<" r: "<<r<<endl;
        //     unordered_map<int,int> m;
        //     for(int i=l;i<=r;i++)
        //         m[nums[i]]++;
        //     if(k==m.size()){
        //         count++;
        //     }
        //     if(expand)
        //         r++;
        //     else
        //         l++;
        //     if(m.size()>k)
        //         expand = false, r--;
        //     if(r==l)
        //         expand = true;
        // }
        //TLE
        for(int i=0;i<n;i++){
            for(int j=i+k-1;j<n;j++){
                unordered_map<int,int> m;
                for(int l=i;l<=j;l++)
                    m[nums[l]]++;
                if(k==m.size())
                    count++;
            }
        }
        return count;
    }
};
int main() {
    Solution s;
    vector<int> v{1,2,1,2,3};
    cout<<s.subarraysWithKDistinct(v,2);
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        //Brute Force  MLE
    //     vector<ll> range{0},tRange(n+1,0);
    //     int s = nums.size();
    //     for (int num : nums) {
    //         int nn = range.size();
    //         for (int i = 0; i < nn; ++i) {
    //             range.push_back(range[i] + num);
    //             tRange[range[i] + num] = 1;
    //         }
    //     }
    //     sort(range.begin(), range.end());
    //     ll cnt = 0;
    //     for(int i=1;i<=n;i++){
    //         if(!tRange[i]){
    //             cnt++;
    //             ll rS = range.size();
    //             range.push_back(i), tRange[i] = 1;
    //             for(int j=0;j<rS;j++){
    //                 ll sum = range[j]+i;
    //                 if(sum<=n && !tRange[sum])
    //                     range.push_back(sum), tRange[sum]=1;
    //                 if(range.size()>=n+1)
    //                     j = rS, i=n+1;
                    
    //             }
    //         }
    //     }
        ll sum=0;
        int cnt=0,i=0;
        while(sum<n){
            if(i<nums.size() && nums[i]<=sum+1){
                sum+=nums[i];
                i++;
            }
            else{
                sum+=(sum+1);
                cnt++;
            }
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,2,31,33};
    cout<<s.minPatches(nums,2147483647);
}
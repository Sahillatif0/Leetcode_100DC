#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size(), sum=0;
        vector<int> preSum(n+1,0);
        for(int i=0;i<n;i++)
            preSum[i+1] = preSum[i]+cardPoints[i];
        if(n==k)
            return preSum[n];
        int l=0,r=n-k;
        while(r<=n){
            sum = max(sum, (preSum[n] - (preSum[r]-preSum[l])));
            l++,r++;
        }
        return sum;
    }
};
int main() {
    Solution s;
    // vector<int> v{11,49,100,20,86,29,72};
    vector<int> v{1,79,80,1,1,200,1};
    cout<<s.maxScore(v,3);
}
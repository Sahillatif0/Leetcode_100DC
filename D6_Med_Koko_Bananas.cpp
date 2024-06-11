#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int mid = (l+r)/2, t = 0;
            for(int i =0;i < piles.size(); i++)
                t += ceil(double(piles[i]) / double(mid));
            if(t <= h)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
int main() {
    Solution s;
    vector<int> v{30,11,23,4,20};
    cout<<s.minEatingSpeed(v,5);
}
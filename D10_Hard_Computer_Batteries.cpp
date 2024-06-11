#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = *min_element(batteries.begin(), batteries.end()), r=0, res;
        for(int i=0;i<batteries.size();i++)
            r += batteries[i];
        r /= n;
        while(l <= r){
            long long mid = (l+r)/2, sum = 0;
            for(int i=0;i<batteries.size();i++)
                sum += min((long long)batteries[i], mid);
            if(sum >= mid*n){
                res = mid;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<int> v{3,3,3};
    cout<<s.maxRunTime(2,v);
}
// 2,   4,5,4,2
// 3,   4,5,4,2
// 5,   8,7,5,9
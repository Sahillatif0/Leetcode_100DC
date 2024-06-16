#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> sum(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++)
            sum[i+1] = sum[i] + nums[i];
        int cnt=0, l=0,r=0;
        while(r<nums.size()){
            int s = sum[r+1]-sum[l];
            if(s==goal){
                int b=-1, a=0;
                while(s==goal && r<nums.size() && l<=r){
                    cout<<"rl = "<<l<<"r: "<<r<<endl;
                    cnt++,r++,b++;
                    if(r<nums.size())
                        s = sum[r+1]-sum[l];
                    else 
                        break;
                }
                r-=(b+1),l++;
                if(l<=r)
                    s = sum[r+1]-sum[l];
                cout<<"ml = "<<l<<"r: "<<r<<endl;
                while(s==goal && l<=r){
                    cout<<"ll = "<<l<<"r: "<<r<<endl;
                    cnt++,l++,a++;
                    s = sum[r+1]-sum[l];
                }
                r++,l-=a;
                if(l>r)
                    l=r;
            }
            else if(s<goal)
                r++;
            else
                l++;
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> v{1,0,1,0,1};
    cout<<s.numSubarraysWithSum(v,2);
}
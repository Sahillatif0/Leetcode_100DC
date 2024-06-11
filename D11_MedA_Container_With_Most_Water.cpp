#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, max_area=0;
        while(r<height.size()){
            int area = (r-l)*(min(height[l], height[r]));
            if(area>max_area)
                max_area = area;
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        return max_area;
    }
};
int main() {
    Solution s;
    vector<int> v{1,1};
    cout<<s.maxArea(v);
}
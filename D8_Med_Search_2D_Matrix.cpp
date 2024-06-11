#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix[0].size()-1, mid;
        for(int i=0;i<matrix.size();i++){
            l=0,r=matrix[i].size()-1;
            while(l<=r){
                mid = (l+r)/2;
                if(matrix[i][r]<target)
                    break;
                else if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]>target)
                    r = mid-1;
                else if(matrix[i][mid]<target)
                    l = mid+1;
            }
        }
        return false;
    }
};
int main() {
    Solution s;
    vector<vector<int>> v{{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    cout<<s.searchMatrix(v, 23);
}
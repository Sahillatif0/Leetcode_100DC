#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt=0, canPlant=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i]==0)
                cnt++;
            else{
                int j=((i==cnt)?2:3);
                for(;j<=cnt;j+=2)
                    canPlant++;
                cnt=0;
            }
        }

            int j=(cnt==flowerbed.size())?1:2;
            for(;j<=cnt;j+=2)
                canPlant++;
        return canPlant>=n;
    }
};
int main() {
    Solution s;
    vector<int> v{0,0,0};
    // vector<int> v{0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,1};
    cout<<s.canPlaceFlowers(v,2);
}
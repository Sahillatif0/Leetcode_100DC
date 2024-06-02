#include<iostream>
using namespace std;
class Solution {
public:
    int minimumChairs(string s) {
        int len = 0, max=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E')
                len++;
            else
                len--;
            max=max<len?len:max;
        }
        return max;
    }
};
int main() {
    Solution s;
    cout<<s.minimumChairs("ELELEEL");
}
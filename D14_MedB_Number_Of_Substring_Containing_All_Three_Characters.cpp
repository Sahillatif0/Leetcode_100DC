#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size(), count = 0;
        vector<int> m(3,-1);
        for(int i=0;i<n;i++){
            m[s[i]-'a'] = i;
            if(m[0]!=-1 && m[1]!=-1 && m[2]!=-1)
                count+=min(m[0],min(m[1],m[2]))+1;
        }
        return count;   
    }
};
int main() {
    Solution s;
    cout<<s.numberOfSubstrings("abcabc");
}
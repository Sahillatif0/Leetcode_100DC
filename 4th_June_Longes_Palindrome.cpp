#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        int cnt=0, odd=0, tChar=0;
        for(auto i:m)
            tChar++;
        if(tChar<2)
            return s.size();
        for(auto i:m){
            if(i.second%2==0)
                cnt+=i.second;
            else
                cnt+=i.second-1,
                odd=1;
        }
        if(odd)
            cnt++;
        return cnt;
    }
};
int main() {
    Solution s;
    cout<<s.longestPalindrome("ababababa");
}
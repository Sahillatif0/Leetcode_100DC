#include<iostream>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        for(int i=0;i<s.size();i++)
            if(s[i]==t[j])
                t[j++] = '0';
        int cnt=0;
        for(int i=0;i<t.size();i++)
            if(t[i]!='0')
                cnt++;
        return cnt;
    }
};
int main() {
    Solution s;
    cout<<s.appendCharacters("coaching", "a");
}
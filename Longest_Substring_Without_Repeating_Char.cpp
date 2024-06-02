#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int, int> present;
        int max_len = 0, len=0;
        for(int i=0;i<s.size();i++){
            if(present.find(s[i])!=present.end()){
                int nl = len;
                len = (i - present[s[i]]);
                present[s[i]] = i;
                for(int j=0;j<nl-len;j++)
                    present.erase(s[i-nl+j]);
            }
            else{
                present[s[i]] = i;
                len++;
            }
            max_len = max_len<len?len:max_len;
        }
        return max_len;
    }
};
int main() {
    Solution s;
    cout<<s.lengthOfLongestSubstring("ddddd");
}
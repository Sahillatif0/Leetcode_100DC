#include<iostream>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string str="";
        int i=0,j=0;
        while(i<word1.size() || j<word2.size()){
            if(i<word1.size())
                str+=word1[i++];
            if(j<word2.size())
                str+=word2[j++];
        }
        return str;
    }
};
int main() {
    Solution s;
    cout<<s.mergeAlternately("abc", "pqr");
}
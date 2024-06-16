#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt=1, n = chars.size();
        char a = chars[0];
        for(int i=1;i<n;i++){
            if(a==chars[i])
                cnt++;
            else{
                chars.push_back(a);
                if(cnt>1){
                    string s = to_string(cnt);
                    for(char c:s)
                        chars.push_back(c);
                }
                a = chars[i];
                cnt = 1;
            }
        }
        chars.push_back(a);
        if(cnt>1){
            string s = to_string(cnt);
            for(char c:s)
                chars.push_back(c);
        }
        for(int i=0;i<n;i++)
            chars.erase(chars.begin());
        return chars.size();
    }
};
int main() {
    Solution s;
    vector<char> chars{'a','a','b','b','c','c','c'};
    cout<<s.compress(chars);
    for(char c:chars)
        cout<<c<<" ";
}
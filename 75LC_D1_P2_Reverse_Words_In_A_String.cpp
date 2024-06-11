#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        string r="", word="";
        int i=0;
        vector <string> words;
        while(i<s.size()){
            while(s[i]==' ' && ((i+1)<s.size() && s[i+1]==' '))
                i++;
            if(s[i]==' '){
                if(word!="")
                    words.push_back(word);
                word="";
            }
            else
                word+=s[i];
            i++;
        }
        if(word!="")
            words.push_back(word);
        for(int i=0;i<words.size();i++){
            cout<<words[i]<<endl;
            r+=words[words.size()-1-i];
            if(i!=words.size()-1)
                r+=" ";
        }
        return r;
    }
};
int main() {
    Solution s;
    cout<<s.reverseWords("  hello world  ");
}
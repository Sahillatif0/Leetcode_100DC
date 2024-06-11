#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string> words;
        string word;
        istringstream wordsList(sentence);
        unordered_set<string> dicts(dictionary.begin(), dictionary.end());
        for(int i=0;i<dictionary.size();i++)
            for(int j=0;j<dictionary.size();j++)
                if(dictionary[i].find(dictionary[j])==0)
                    dictionary[i]=dictionary[j];
        while(wordsList>>word){
            string w = "";
            bool f = false;
            for(int j=0;j<word.size();j++){
                w+=word[j];
                if(dicts.find(w)!=dicts.end() && !f){
                    words.push_back(w);
                    f = true;
                }
            }
            if(!f)
                words.push_back(word);
        }
        string res="";
        for(int i=0;i<words.size();i++){
            res+=words[i];
            if(i!=words.size()-1)
                res+=" ";
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<string> v{"catt","cat","bat","rat"};
    cout<<s.replaceWords(v,"the cattle was rattled by the battery");
}
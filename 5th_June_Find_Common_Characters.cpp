#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        //Approach 1

        // vector<vector<int>> freq;
        // for(int i=0;i<words.size();i++){
        //     vector<int> f(26,0);
        //     for(int j=0;j<words[i].size();j++)
        //         f[words[i][j]-'a']++;
        //     freq.push_back(f);
        // }
        // for(int i=0;i<26;i++){
        //     int min = freq[0][i];
        //     for(int j=1;j<freq.size();j++)
        //         if(freq[j][i]<min)
        //             min = freq[j][i];
        //     for(int j=0;j<min;j++)
        //         res.push_back(string(1, 'a'+i));
        // }

        //Approach 2
        for(int i=0;i<words[0].size();i++){
            bool f = false;
            for(int j=1;j<words.size();j++){
                f = false;
                for(int k=0;k<words[j].size();k++){
                    if(words[0][i]==words[j][k]){
                        f = true;
                        words[j][k] = '0';
                        break;
                    }
                }
                if(!f)
                    break;
            }
            if(f)
                res.push_back(string(1, words[0][i]));
        }
        return res;
    }
};
int main() {
    Solution s;
    vector<string> v{"ali","ahmed","rehman"};
    vector<string> v3 = s.commonChars(v);
    for(int i=0;i<v3.size();i++)
        cout<<v3[i]<<" ";
}
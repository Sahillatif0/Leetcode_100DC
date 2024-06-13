#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size())
            return {};
        vector<int> indices;
        unordered_map<char,int> pMap, sMap;
        for(char ch = 'a';ch<='z';ch++)
            sMap[ch] = 0,pMap[ch] = 0;
        for(char c:p)
            pMap[c]++;
        // for(int i=0;i<=(s.size()-p.size());i++){
        //     sMap = pMap;
        //     for(int j=0;j<p.size();j++)
        //         sMap[s[i+j]]--;
        //     if(sMap==dMap)
        //         indices.push_back(i);
        // }
        sort(p.begin(), p.end());
        int j=p.size();
        for(int i=0;i<s.size();i++){
            sMap[s[i]]++;
            if(i==(j-1)){
                if(sMap==pMap)
                    indices.push_back(i-p.size()+1);
                sMap[s[i-p.size()+1]]--;
                j++;
            }
        }
        return indices;
    }
};
int main() {
    Solution s;
    vector<int> indices = s.findAnagrams("cbaebabacd","abc");
    for(int i:indices)
        cout<<i<<" ";
}
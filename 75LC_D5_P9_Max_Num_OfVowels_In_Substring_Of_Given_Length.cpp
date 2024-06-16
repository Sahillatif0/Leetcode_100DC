#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        // vector<int> preCount(s.size()+1, 0);
        // for(int i=0;i<s.size();i++)
        //     preCount[i+1] = preCount[i] + ((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')?1:0);
        int l=0,r=k-1,max=0,cnt=0;
        while (r<s.size()){
            cnt=0;
            // cnt = preCount[r+1]-preCount[l];
            for(int i=l;i<=r;i++)
                cnt+=((s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')?1:0);
            if(cnt>max)
                max = cnt;
            l++,r++;
        }
        return max;
    }
};
int main() {
    Solution s;
    cout<<s.maxVowels("abciiidef", 3);
}
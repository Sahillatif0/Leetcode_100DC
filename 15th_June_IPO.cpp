#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int totalProfit=0,maxPro=0;
        vector<pair<int, int>> pp;
        for(int i=0;i<profits.size();i++)
            pp.push_back({capital[i],profits[i]});
        sort(pp.begin(), pp.end());
        priority_queue<int> not_imp;
        int n = profits.size(), i = 0;
        while (k > 0) {
            while (i < n && pp[i].first <= w) {
                not_imp.push(pp[i].second);
                i++;
            }
            if (not_imp.empty()) break;
            w += not_imp.top();
            k--;
            not_imp.pop();
        }
        return w;

    }
};
int main() {
  Solution  s;
    vector<int> p{1,2,3}, c{0,1,1};
    cout<<s.findMaximizedCapital(2,0,p,c); 
}
#include<iostream>
#include<vector>
    #include <map>
using namespace std;
class Solution {
public:
    // int countDays(int days, vector<vector<int>>& meetings) {
    //     vector<int> ddone(days+1,0);
    //     for(int i=0;i<meetings.size();i++){
    //         for(int j=meetings[i][0];j<=meetings[i][1];j++)
    //             ddone[j] = 1;
    //     }
    //     int cnt = 0;
    //     for(int i=1;i<=days;i++)
    //         if(ddone[i]==0)
    //             cnt++;
    //     return cnt;
    // }

int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> m;
        for(auto& meeting : meetings){
            m[meeting[0]]++;
            m[meeting[1] + 1]--;
        }
        int cnt = 0, ongoing = 0;
        int prev_day = 1;
        for(auto& [day, change] : m){
            if(ongoing == 0)
                cnt += day - prev_day;
            ongoing += change;
            prev_day = day;
        }
        if(ongoing == 0)
            cnt += days - prev_day + 1;
        return cnt;
    }
};
int main() {
    Solution s;
    vector<vector<int>> v{{5,7},{1,3},{9,10}};
    cout<<s.countDays(10, v);
}
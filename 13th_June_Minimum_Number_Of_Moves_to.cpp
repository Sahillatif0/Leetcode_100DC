#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int moves = 0;
        for(int i=0;i<seats.size();i++)
            moves+=abs(seats[i]-students[i]);
        return moves;
    }
};
int main() {
    Solution s;
    vector<int> seats = {3,1,5}, students{2,7,4};
    cout<<s.minMovesToSeat(seats,students);
}
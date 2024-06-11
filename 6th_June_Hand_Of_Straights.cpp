#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void printVector(vector<int> h){
        for(int i=0;i<h.size();i++)
            cout<<h[i]<<" ";
        cout<<endl;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize)
            return false;
        vector<vector<int>> v;
        int size = hand.size(), j=0;
        sort(hand.begin(), hand.end());
        v.push_back(vector<int>(groupSize));
        v[0][0] = hand[0];
        hand.erase(hand.begin());
        for(int i=0;i<hand.size();){
            cout<<"i= "<<i<<" valur: "<<hand[i]<<" j= "<<j<<" vlur: "<<v[j/groupSize][j%3]<<endl;
            
            if((hand[i]-1)==v[j/groupSize][j%groupSize]){
                j++;
                v[j/groupSize][j%groupSize] = hand[i];
                cout<<"erasing... "<<hand[i]<<" at "<<i<<endl;
                if(hand.size()==1)
                    break;
                else
                    hand.erase(hand.begin()+i);
                printVector(hand);
            }
            else i++;
            if((j+1)%groupSize==0){
            i=0;
            v.push_back(vector<int>(groupSize));
            j++;
            v[j/groupSize][j%groupSize] = hand[i];
            cout<<"erasing... "<<hand[i]<<" at "<<i<<endl;
            hand.erase(hand.begin()+i);
            }
            cout<<"size: "<<hand.size()<<endl;
        }
        for(int i=0;i<v.size();i++)
            for(int k=0;k<v[i].size();k++)
                cout<<v[i][k]<<" ";
        cout<<"j: "<<j<<endl;
     return (j+1)==size;    
    }
};
int main() {
 Solution s;
    vector<int>v{1,2,3,6,2,3,4,7,8};
 cout<<s.isNStraightHand(v,3);   
}
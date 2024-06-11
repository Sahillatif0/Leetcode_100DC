#include<iostream>
#include<queue>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int l=0,r=0,kk=k, max=0;
        queue<int> changedPos;
        while(r<answerKey.size()){
            if(answerKey[r]=='T')
                r++;
            else{
                if(kk>0){
                    kk--;
                    changedPos.push(r);
                    r++;
                }
                else{
                    l=changedPos.front()+1;
                    changedPos.pop();
                    kk++;
                }
                if((r-l)>max)
                    max = r-l;
            }
        }
        for(int i=0;i<changedPos.size();i++)
            changedPos.pop();
        l=0,r=0,kk=k;
        while(r<answerKey.size()){
            if(answerKey[r]=='F')
                r++;
            else{
                if(kk>0){
                    if((r-l)>max)
                        max = r-l;
                    kk--;
                    changedPos.push(r);
                    r++;
                }
                else{
                    l=changedPos.front()+1;
                    changedPos.pop();
                    kk++;
                }
            }
        }
        return max+1;
    }
};
int main() {
 Solution s;
 cout<<s.maxConsecutiveAnswers("TTFTTFTT",1);   
}
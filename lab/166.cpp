#include "header.hpp"
class Solution {
public:
    string check(string want, int cut){
        int size = want.size();
        string curTar = want.substr(0,cut);
        while(want.size()<cut){
            want = want.substr(cut);
            if(curTar.compare(want.substr(0,cut))!=0){
                return "";
            }
        }
        return curTar;
        
    }
    
    //最长子串
    string findLongestSubStr(string want){
        cout<<"enter findLongestS"<<endl;
        int threshold = 0;
        int half = want.size()/2;
        int i = 1;
        while(half>=i){
            cout<<"doing i:"<<i<<endl;
            string repeat = check(want,i);
            if(repeat.compare("")!=0){
                return repeat;
            }
            i *= 2;
        }
        return "";
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        stringstream ss;
        double result = (double)numerator/(double)denominator;
        ss << result;
        string ret;
        ss >> ret;
        string stable = ret.substr(0,ret.find("."));
        string want = ret.substr(ret.find(".")+1);
        string repeat = findLongestSubStr(want);
        if(repeat.compare("")==0){
            //no repeat
            return ret;
        }else{
            stringstream ss2;
            ss2 << stable << ".(" << repeat << ")";
            return ss2.str();
        }
    }
};

int main(){
    Solution s;
    cout << s.fractionToDecimal(4,333);
}
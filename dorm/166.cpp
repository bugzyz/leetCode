#include "header.hpp"
#include <sstream>

class Solution
{
  public:
    string check(vector<string> comArr, int size)
    {
        cout << "checking:" << comArr[0] << endl;
        for (int i = 1; i < size; i++)
        {
            if (comArr[0].compare(comArr[i]) != 0)
            {
                return "";
            }
        }
        return comArr[0];
    }

    //最长子串
    string findLongestSubStr(string want)
    {
        cout << "finding:" << want << endl;
        int half = want.size() / 2;
        for (int i = 1; i <= half; i++)
        {
            int piece = want.size() / i;
            vector<string> comArr;
            for (int j = 0; j < piece; j++)
            {
                comArr.push_back(want.substr(j * i, i));
            }
            string result = check(comArr, piece);
            if (result.compare("") != 0)
            {
                return result;
            }
        }

        return "";
    }

    string fractionToDecimal(int numerator, int denominator)
    {
        stringstream ss;
        double a, b;
        a = numerator;
        b = denominator;
        double result = (double)numerator / (double)denominator;
        double forChecking = (double)numerator * 10 / (double)denominator;
        ss << result;
        string ret;
        ss >> ret;
        ss.str("");
        ss << forChecking;
        string checking;
        ss >> checking;

        string stable = ret.substr(0, ret.find("."));
        string want = ret.substr(ret.find(".") + 1);
        cout << "want:" << want << "\n";

        string wantChecking = checking.substr(checking.find(".") + 1);
        cout << wantChecking << "\n";

        cout << "wantChecking:" << want << endl;
        if (want.size() <= 1)
        {
            return ret;
        }

        int length;
        if (want.substr(want.size() - 1, 1).compare(wantChecking.substr(wantChecking.size() - 2, 1)) == 0)
        {
            //no randing
            length = want.size();
            cout << "no randding" << endl;
        }
        else
        {
            length = want.size() - 1;
        }

        string repeat = findLongestSubStr(want.substr(0, length));
        if (repeat.compare("") == 0)
        {
            //no repeat
            return ret;
        }
        else
        {
            stringstream ss2;
            ss2 << stable << ".(" << repeat << ")";
            return ss2.str();
        }
    }
};

int main(int argc, char *argv[])
{
    cout << Solution().fractionToDecimal(atoi(argv[1]), atoi(argv[2]));
}
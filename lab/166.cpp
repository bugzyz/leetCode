#include "header.hpp"
class Solution2
{
  public:
    string check(string want, int cut)
    {
        int size = want.size();
        string curTar = want.substr(0, cut);
        while (want.size() < cut)
        {
            want = want.substr(cut);
            if (curTar.compare(want.substr(0, cut)) != 0)
            {
                return "";
            }
        }
        return curTar;
    }

    //最长子串
    string findLongestSubStr(string want)
    {
        cout << "enter findLongestS" << endl;
        int threshold = 0;
        int half = want.size() / 2;
        int i = 1;
        while (half >= i)
        {
            cout << "doing i:" << i << endl;
            string repeat = check(want, i);
            if (repeat.compare("") != 0)
            {
                return repeat;
            }
            i *= 2;
        }
        return "";
    }

    string fractionToDecimal(int numerator, int denominator)
    {
        stringstream ss;
        double result = (double)numerator / (double)denominator;
        ss << result;
        string ret;
        ss >> ret;
        string stable = ret.substr(0, ret.find("."));
        string want = ret.substr(ret.find(".") + 1);
        string repeat = findLongestSubStr(want);
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
class Solution
{
  public:
    int pow(int wei)
    {
        if (wei == 0)
        {
            return 1;
        }
        int ret = 10;
        while (--wei)
        {
            ret *= 10;
        }
        return ret;
    }
    string constructStringResult(int shang, int wei, int leftshift)
    {
        wei = wei - 1;
        cout << "shang:" << shang << " wei:" << wei << endl;
        int currentWei = 1;
        int checkWei = shang;
        while ((checkWei = checkWei / 10) != 0)
        {
            currentWei++;
        }
        cout << currentWei << endl;
        int need_zero = wei - currentWei;
        stringstream ss;
        for (int i = 0; i < need_zero; i++)
        {
            ss << "0";
        }
        ss << shang;
        return ss.str();
    }
    string fractionToDecimal(int numerator, int denominator)
    {
        bool minus = false;
        string result = "";
        //if both below zero
        if (numerator < 0 && denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
        else if (numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0)
        {
            minus = true;
        }

        cout << "input: " << numerator << ", " << denominator << ", minus:" << minus << endl;

        //被除数
        int dividend = numerator;
        //除数
        int divisor = denominator;
        //去掉整数，只剩下没办法被除的整数，接下来就是纯小数的部分
        int temp = dividend % divisor;

        int currentDividend;
        for (int checkRepeatAfter1 = 0; checkRepeatAfter1 != 10; checkRepeatAfter1++)
        {
            currentDividend = (dividend * pow(checkRepeatAfter1)) % divisor;
            cout << dividend * pow(checkRepeatAfter1);
            cout << "checkRA:" << checkRepeatAfter1 << " currentDividend:" << currentDividend << endl;
            //10位是我能够看的循环的限度
            int threshold = 10;
            //补0
            int i = 1;
            int current = currentDividend;
            while (threshold--)
            {
                int shang = current / divisor;
                cout << "current: " << current << endl;

                //说明位数不够
                if (shang == 0)
                {
                    cout << "pow:" << pow(i) << endl;
                    current = currentDividend * pow(i);
                    i++;
                    continue;
                }
                int yu = current % divisor;
                cout << "shang:" << shang << " yu:" << yu << ",pow:" << pow(i) << " current:" << current << endl;
                if (yu * pow(i - 1) == current)
                {
                    //hit repeat
                    string repeat = constructStringResult(shang, i, checkRepeatAfter1);
                    stringstream ss;
                    stringstream convert;
                    if (minus)
                    {
                        ss << "-";
                    }
                    convert << dividend * pow(checkRepeatAfter1) / divisor;
                    string waitToSplit;
                    cout << "waitToSplit: " << waitToSplit << endl;
                    convert >> waitToSplit;
                    ss << dividend / divisor;
                    ss << ".";
                    string right = waitToSplit.substr(waitToSplit.size() - checkRepeatAfter1, checkRepeatAfter1);
                    cout << "right: " << right << endl;
                    ss << right;
                    ss << "(" << repeat << ")";
                    return ss.str();
                }
                else
                {
                    current = temp * pow(i);
                    cout << "current update:" << current << endl;
                }

                i++;
            }
            cout << "-------------------------------\n";
        }
        stringstream ss;
        if (minus)
        {
            ss << "-";
        }
        ss << (double)numerator / (double)denominator;
        return ss.str();
    }
};

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    Solution s;
    cout << s.fractionToDecimal(atoi(argv[1]), atoi(argv[2]));
}
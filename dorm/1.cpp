#include <vector>
#include <iostream>

using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> result;
        for (vector<int>::iterator i = nums.begin(); i + 1 != nums.end(); i++)
        {
            for (vector<int>::iterator j = i + 1; j != nums.end(); j++)
            {
                cout << i - nums.begin() << endl;
                cout << j - nums.begin() << endl;
                if (*i + *j == target)
                {
                    cout << "reach target" << i - nums.begin() << endl;
                    cout << "reach target" << j - nums.begin() << endl;

                    result.push_back(i - nums.begin());
                    result.push_back(j - nums.begin());
                    return result;
                }
            }
        }
        // for (int i = 0; i + 1 != nums.size(); i++)
        // {
        //     for (int j = i + 1; j != nums.size(); j++)
        //     {
        //         if (nums[i] + nums[j] == target)
        //         {
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    vector<int> res = s.twoSum(v, 4);
    for (int i = 0; i != res.size(); i++)
        cout << res[i] << endl;
}
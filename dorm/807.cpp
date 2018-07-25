#include <vector>
#include <iostream>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> reverse;
    vector<vector<int>> origin;
    void initReverse(vector<vector<int>> &grid)
    {
        origin = vector<vector<int>>(grid);
        int m = grid.size();
        reverse = vector<vector<int>>(m);
        for (int i = 0; i < reverse.size(); i++)
        {
            vector<int> temp(m);
            for (int j = 0; j < temp.size(); j++)
            {
                temp[j] = grid[j][i];
            }
            reverse[i] = temp;
        }
    }
    int getColumnMin(int col)
    {
        vector<int> &temp = reverse[col];
        int max = temp[0];
        for (int i = 1; i < temp.size(); i++)
        {
            if (max < temp[i])
            {
                max = temp[i];
            }
        }
        return max;
    }
    int getRowMin(int row)
    {
        vector<int> &temp = origin[row];
        int max = temp[0];
        for (int i = 1; i < temp.size(); i++)
        {
            if (max < temp[i])
            {
                max = temp[i];
            }
        }
        return max;
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
    {
        initReverse(grid);

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                std::cout << grid[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        vector<vector<int>> result(grid.size());
        int increment = 0;
        for (int i = 0; i < result.size(); i++)
        {
            result[i] = vector<int>(grid.size());
        }
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                int rowMin = getRowMin(i);
                int colMin = getColumnMin(j);
                result[i][j] = rowMin > colMin ? colMin : rowMin;
                std::cout << result[i][j] << " ";
                //calculate increment
                increment += result[i][j] - grid[i][j];
            }
            std::cout << "\n";
        }
        return increment;
    }
};
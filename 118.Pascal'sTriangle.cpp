#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for(int i = 1; i <= numRows; i++)
        {
            vector<int> row;
            int index = i - 1;

            for(int j = 0; j < i; j++)
            {
                if(j == 0 || j == index)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back((triangle[index - 1][j - 1] + triangle[index - 1][j]));
                }
            }
            triangle.push_back(row);
        }

        return triangle;
    }
};
























int main()
{
    int numRows = 5;

    vector<vector<int>> triangle;

        for(int i = 1; i <= numRows; i++)
        {
            vector<int> row;
            int index = i - 1;

            for(int j = 0; j < i; j++)
            {
                if(j == 0 || j == index)
                {
                    row.push_back(1);
                }
                else
                {
                    row.push_back((triangle[index - 1][j - 1] + triangle[index - 1][j]));
                }
            }
            triangle.push_back(row);
        }


    for(int i = 1; i <= numRows; i++)
    {
        cout << i << ": ";
        int index = i - 1;

        for(int j = 0; j < i; j++)
        {
            cout << triangle[index][j] << " ";
        }
        cout << endl;
    }
}

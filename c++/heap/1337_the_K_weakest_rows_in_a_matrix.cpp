// leetcode easy
/*
Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.
*/
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <utility>
using namespace std;

class Solution
{
public:
    struct weaker
    {
        bool operator()(const pair<int, int> &pair1, const pair<int, int> &pair2)
        {
            return (pair1.first != pair2.first) ? pair1.first < pair2.first : pair1.second < pair2.second;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, weaker> rows;
        vector<int> order;
        for (int r = 0; r < mat.size(); r++)
        {
            int soldiers = 0;
            for (int c = 0; c < mat[r].size(); c++)
            {
                if (mat[r][c] == 1)
                {
                    soldiers++;
                }
            }
            rows.push(make_pair(soldiers, r));
        }
        while (order.size() < k)
        {
            order.push_back(rows.top().second);
            rows.pop();
        }
        return order;
    }
};
// time: O(N), space: O(N)
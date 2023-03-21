// leetcode medium
/*
There are a total of numCourses courses you have to take, labeled from 0 to
numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi]
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers,
return any of them. If it is impossible to finish all courses, return an empty array.
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
using namespace std;

// TOPOLOGICAL SORT DFS
/*
courses = nodes; impossible if there is a cycle
*/
class Solution
{
public:
    vector<int> results;
    vector<vector<int>> prereq;
    vector<int> degree;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        prereq.resize(numCourses);
        degree.resize(numCourses);
        for (auto c : prerequisites)
        {
            prereq[c[1]].push_back(c[0]); // c1 is a prereq of c0
            degree[c[0]]++;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (degree[i] == 0) // courses with no prereq can be taken first
            {
                dfs(i);
            }
        }
        if (results.size() == numCourses)
        {
            return results;
        }
        return {};
    }

private:
    void dfs(int index)
    {
        results.push_back(index);
        degree[index] = -1; // visited
        for (auto c : prereq[index])
        {
            degree[c]--;
            if (degree[c] == 0)
            {
                dfs(c);
            }
        }
    };
};
// time: O(E + V), space: O(E + V)
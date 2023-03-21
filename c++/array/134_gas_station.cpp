// array: leetcode medium (greedy)
/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution,
it is guaranteed to be unique
*/
#include <vector>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int size = gas.size();
        int total_gas = 0;
        int curr_gas = 0;
        int starting = 0;
        for (int i = 0; i < size; i++)
        {
            total_gas += gas[i] - cost[i];
            curr_gas += gas[i] - cost[i];
            if (curr_gas < 0)
            {
                starting = i + 1;
                curr_gas = 0;
            }
        }
        return (total_gas >= 0) ? starting : -1;
    }
};
// time: O(n), space: O(1)
// binary search: leetcode medium
/*
Design a time-based key-value data structure that can store multiple values for the same key at
different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values,
it returns "".
*/
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <string>
#include <iterator>
using namespace std;

/*
for a specific key: we want timestamp:value pair to be sorted => map
*/
class TimeMap
{
public:
    unordered_map<string, map<int, string>> store;
    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        store[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        if (store.count(key) == 0)
        {
            return "";
        }
        else
        { // for given key, there exists entries, check for max value where its time <= timestamp
            // An iterator to the the first element in the container whose key is considered to go after k, or map::end if no keys are considered to go after k.
            auto it = store[key].upper_bound(timestamp);
            if (it == store[key].begin()) // begin means no time <= timestamp exists, all >
            {
                return "";
            }
            return prev(it)->second; // syntax: prev(it, __)
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// leetcode medium
/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.

Implement the WordDictionary class:

WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
*/

#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct TrieNode
{
    bool isEnd;
    vector<TrieNode *> children;
    TrieNode()
    {
        isEnd = false;
        children = vector<TrieNode *>(26, nullptr); // 26 letters
    }
    ~TrieNode()
    {
        for (auto c : children)
        {
            if (c)
                delete c;
        }
    }
};

class WordDictionary
{
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        auto temp = root;
        for (auto w : word)
        {
            if (temp->children[w - 'a'] == nullptr)
            {
                temp->children[w - 'a'] = new TrieNode();
            }
            temp = temp->children[w - 'a'];
        }
        temp->isEnd = true;
    }

    // main challenge is to take care of . => recursively dfs
    bool search(string word)
    {
        return find(word, root, 0);
    }

private:
    TrieNode *root;
    bool find(string &word, TrieNode *node, int index)
    {
        // recursion
        if (node == nullptr)
            return false;
        if (index == word.size())
            return node->isEnd;
        if (word[index] == '.')
        {
            for (auto child : node->children)
            {
                if (find(word, child, index + 1))
                {
                    return true;
                }
            }
        }
        else
        {
            return find(word, node->children[word[index] - 'a'], index + 1);
        }
        return false;
    };
};
// time: O(m), space: O(m)

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
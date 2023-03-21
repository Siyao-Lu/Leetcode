// trie: leetcode medium
/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.
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

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        auto temp = root;
        for (auto c : word)
        {
            if (!temp->children[c - 'a'])
            {
                temp->children[c - 'a'] = new TrieNode();
            }
            temp = temp->children[c - 'a'];
        }
        temp->isEnd = true;
    } // time: O(m); space: O(m) -> m = key length

    bool search(string word)
    {
        const TrieNode *n = find(word);
        return (n && n->isEnd);
    } // time: O(m), space: O(1)

    bool startsWith(string prefix)
    {
        return find(prefix);
    } // time: O(m), space: O(1)
private:
    const TrieNode *find(const string &prefix)
    {
        auto temp = root;
        for (auto p : prefix)
        {
            temp = temp->children[p - 'a'];
            if (!temp)
            {
                return nullptr;
            }
        }
        return temp;
    };
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
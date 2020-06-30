#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class dict
{
public:
    char val;
    dict *children[26];
    dict()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
class Trie
{
public:
    dict *root;
    unordered_set<string> s;
    /** Initialize your data structure here. */
    Trie()
    {
        root = new dict();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        s.insert(word);
        _insert(word, 0, root);
    }

    void _insert(string word, int first, dict *cur)
    {
        if(first >= word.size()) return;
        if (cur->children[word[first] - 'a'] == nullptr)
        {
            cur->children[word[first] - 'a'] = new dict();
            cur->children[word[first] - 'a']->val = word[first];
        }
        _insert(word, first + 1, cur->children[word[first] - 'a']);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return s.find(word) != s.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        dict *cur = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            int ind = prefix[i] - 'a';
            if (cur->children[ind] == nullptr)
                return false;
            cur = cur->children[ind];
        }
        return true;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    trie.search("apple");   // returns true
    trie.search("app");     // returns false
    cout << endl ;
    cout << trie.startsWith("apa") << endl; // returns true
    // trie.insert("app");
    // trie.search("app"); // returns true
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
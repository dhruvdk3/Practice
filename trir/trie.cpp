#include <bits/stdc++.h>

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data = ch;
        for(int i = 0; i<26; i++) children[i] = NULL;
        isTerminal = false;
    }
};


class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }


    void insertUtil(TrieNode* root, string word){
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length() == 0) {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else return false;
        return searchUtil(child, word.substr(1));
    }
    
    bool search(string word){
        return searchUtil(root, word);
    }

    void removeUtil(TrieNode* root, string word){
        if(word.length() == 0) {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        }
        else return;
        removeUtil(child, word.substr(1));
    }

    void remove(string word){
        removeUtil(root, word);
    }

    bool startsWithUtil(TrieNode* root, string prefix) {
        if (prefix.length() == 0) {
            return true;
        }
        int index = prefix[0] - 'a';
        TrieNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }
        return startsWithUtil(child, prefix.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);
    }
};


int main(int argc, char const *argv[]){
    Trie* t = new Trie();
    t->insertWord("lu");
    cout<<t->search("lu");
    t->remove("lu");
    cout<<t->search("lu");
    return 0;
}
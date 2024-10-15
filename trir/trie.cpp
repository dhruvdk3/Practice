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

};


int main(int argc, char const *argv[]){

    return 0;
}
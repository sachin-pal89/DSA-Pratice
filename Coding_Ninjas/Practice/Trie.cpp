#include<iostream>
#include<vector>
#include<string>
using namespace std;

class TrieNode
{
  public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char data)
    {
       this->data = data;
       this->children = new TrieNode*[26];

       for(int i = 0; i < 26; i++)
       {
         this->children[i] = NULL;
       }

       this->isTerminal = false;
    }
};

class Trie
{
  TrieNode* root;
  
  public:
     
     Trie()
     {
         root = new TrieNode('\0');
     }

  private:
     
     // For inserting the word in trie
     void insertWord(TrieNode* root, string word)
     {
        // If reached to last char of the string
        if(word.size() == 0)
        {
           root->isTerminal = true;
           return;
        }

        // To check if the element is children of root
        int index = word[0] - 'a';

        if(root->children[index] == NULL)
        {
          root->children[index] = new TrieNode(word[0]);
        }

        // Recursively add the other part of string
        insertWord(root->children[index],word.substr(1));
     }

     // For searching an word in Trie
     bool searchWord(TrieNode* root, string word)
     {
        // If reach to the last cahr in string
        if(word.size() == 0)
        {
           return root->isTerminal;
        }

        // To get index to store the word
        int index = word[0] - 'a';

        // If word is not present as children of a root
        if(root->children[index] == NULL)
        {
           return false;
        }

        // If word is present as the children of the root
        return searchWord(root->children[index],word.substr(1));
     }

     // For deleting an word from Trie
     void removeWord(TrieNode* root, string word)
     {
        // When reached to the last char of the string
        if(word.size() == 0)
        {
           root->isTerminal = false;
           return;
        }

        // To check if word is present as children of root
        int index = word[0] - 'a';

        // If the word is not a children of root
        if(root->children[index] == NULL)
        {
           return;
        }

        // If the word is a children of root
        removeWord(root->children[index],word.substr(1));

        // To delete the children node
        if(!root->children[index]->isTerminal)
        {
           for(int i = 0; i < 26; i++)
           {
              // if root has a children
              if(root->children[index]->children[i] != NULL)
              {
                 return;
              }
           }

           // if root don't have a children node
           delete root->children[index];
           root->children[index] = NULL;  
        }

        return;
     }

   public:

     // Insertion in Trie
     void insert(string word)
     {
        insertWord(root,word);
     }

     // Searching in Trie
     bool search(string word)
     {
        return searchWord(root,word);
     }

     // Deletion in Trie
     void remove(string word)
     {
        return removeWord(root,word);
     }
};

int main()
{
   Trie t;

   t.insert("sachin");
   t.insert("anjali");
   t.insert("sushma");
   t.insert("chandev");

   cout<<t.search("anjali")<<endl;
   
   t.remove("anjali");

   cout<<t.search("anjali")<<endl;

   return 0;
}
/*

Assignment: Trie.h

Description: This file holds the search function, walk function and addWord function. 

Author: Rachel Tidwell 

HSU ID: 9492-53949
 
*/




#ifndef TRIE_H
#define TRIE_H
#include "TrieNode.h"
#include <string>
#include <cctype>
#pragma once 

using namespace std;

class Trie
{
private:
    TrieNode *_root = nullptr;

protected:
	
	void walk(TrieNode *node, vector<string> &words, string current_word)
{   
	 vector <TrieNode*> children_vector = node->getChildren(); // gets the number of nodes of children
	 
	 if(node->getValue() =='$')
	 {
	 	current_word.pop_back(); 		
	 	words.push_back(current_word);  // add the current word to the vector of words 
	 }
	 for (int i = 0; i < children_vector.size(); i++) 
	 {
		char index = children_vector[i]->getValue(); // get the value at that specific place in the vector 
		string this_word = current_word + index; 
		walk(node->getChild(index), words, this_word); 
		  
		
	 } 
	                                                                                              
}


	void search(TrieNode *node, vector<string> &words, string current_word, string prefix)
	{
		
		
	
		for(int i = 0; i < prefix.size(); i++ )
		{
			if(!node->getChild(prefix[i]))
			{
				cout << "This prefix does not exist" << endl; 
				return; 
			
			}
			else
			{
				node = node->getChild(prefix[i]); //weve traversed the tree up to prefix 
				current_word += prefix[i]; // now we add the prefix to the word
			}
		}
			
	walk(node, words, current_word); 
	
	}


public:
    Trie()
    {
        _root = new TrieNode{};
    }

    virtual ~Trie()
    {
        //TODO: clean up memory
    }

	//TODO: implement
    void addWord(const string &word)
    {
    	TrieNode* mover = _root;   		// setting the mover to root 
    	TrieNode* temp_node;			// for creating new nodes to add to the tree
    	for(int i=0; i< word.size(); i++)	// while we are going through the word
    	{
    		if(mover->hasChild(word[i])	)		// checking to see if mover has a child of the letter we are looking at 
    		{
    			mover = mover->getChild(word[i]);  // we move the mover to the child node 
			}
		
			else
			{
				temp_node = new TrieNode; 		// temporary new node 
				temp_node->setValue(word[i]);	// puts a letter inside of the node 
				mover->setChild(word[i], temp_node); 	// adding this temp node to the tree as a child of mover
				mover = temp_node; 				// moving mover to the temp node 
			}
			
		}
		temp_node = new TrieNode; 			// after getting out of the word, making a new node  
		temp_node->setValue('$'); 			// setting that value of that node to the sentinal value 
		mover->setChild('$',temp_node); 		// adding the sentinal value to the end of the word
	
    }

	//TODO: implement
    vector<string> search(const string &word)
    {
        vector<string> matches;
        
        search(_root, matches, "", word);
        return matches;
        
    }
    
    
  

};

#endif // !TRIE_H

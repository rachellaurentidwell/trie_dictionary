/*

Assignment: main.cpp 

Description: This is the main file of trie_dictionary. This program creates a dictionary stored in a trie trie. 
			 It prompts user for a txt document containing a list of words (examples we have in the program's file are 
			 'complex.txt' and 'simple.txt'.) The user will then be asked for a prefix, (ie 're') which will return all 
			 words in the trie tree that have that prefix. 

Author: Rachel Tidwell 

HSU ID: 9492-53949
 
*/

#include <string>
#include <iostream>
#include "Trie.h"
#include "TrieNode.h"
#include <fstream>
#include <vector>


using namespace std;


int main(void)
{		
    
	Trie dictionary{};

   

    
    string word_file; 
    cout << "Please enter a file of words: " << endl; 
    cin >> word_file; 
    

    //Next, add all words in the file into the Trie using the addWord() function
    string word; 
	ifstream infile(word_file); 
	vector <string> the_words; 
	
	
	while(!infile.eof())
	{
		infile >> word; 
		dictionary.addWord(word); 
		the_words.push_back(word); 
	
  	
	}
	
	

    //Then, prompt the user for a list of partial words to look up.  Display all matches 
    //on the screen.
    vector<string> prefix_words{}; 
    string partial_word; 
    
    cout << "Please enter a partial word or zzz to exit: " << endl; 
    cin >> partial_word; 
    
    prefix_words = dictionary.search(partial_word); 
	
		for(int j= 0; j < partial_word.size(); j++)
		{
			cout << prefix_words[j] << endl; 
		}
    
    
    
    while(partial_word != "zzz")
    {
    	cout << "Please enter a partial word or zzz to exit: " << endl; 
    	cin >> partial_word; 
    	
    	if(partial_word == "zzz")
    	{
    		return 0; 
		} 
		
		
		prefix_words = dictionary.search(partial_word); 
	
		for(int j= 0; j < partial_word.size(); j++)
		{
			cout << prefix_words[j] << endl; 
		}
    	
	}
return 0; 
}


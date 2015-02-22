#ifndef TRIE_H
#define TRIE_H
#include <tree/tree.h> 
#include <iostream> 
#include <string> 
#include <algorithm>
using namespace std ; 
/*
 * This file implements the trie data structure to be used by applications. 
 */
class Trie
{
	private:
		Tree<char> tree ; 
	public: 
		void addWord(string word)
		{
			// first select the appropriate level at which to insert the code and then insert. 
			if(tree.totalLevels() == 0)
			{
				tree.insert(word[0]) ; 
				for(int i=1; i<(int)word.size(); i++)
				{
					tree.insert(word[i], i) ; 
				}
			}
			else
			{
				list<char>::iterator it  ;
				for(int i=0; i<(int)word.size(); i++)
				{
					it = find(tree.getLevel(i), tree.getEndLevel(i), word[i]) ; 
					if(it == tree.getEndLevel(i))
					{
						tree.insert(word[i],i) ; 
					}
				}
			}
		}
		void print()
		{
			for_each(tree.begin(), tree.end(), [](char c) { cout<<"char = "<<c<<"\n" ; }) ; 
		}
} ; 
#endif 

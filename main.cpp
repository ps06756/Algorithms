#include <suffix/sarray.h> 
#include <trie/trie.h> 
#include <tree/bst.h> 
#include <tree/tree.h> 
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include <string> 
using namespace std ; 
void testBst()
{
	BST<int> bs ; 
	//cout<<"Inserting elements in the bst\n" ; 
	bs.insert(3) ; 
	bs.insert(1) ; 
	bs.insert(8) ; 
	bs.insert(2) ; 
	bs.insert(6) ; 
	bs.insert(7) ; 
	bs.insert(5) ; 
	//std::for_each(bs.begin(), bs.end(), [](int n) { cout<<"val = "<<n<<"\n"; }) ; 
	//cout<<"\n" ; 
	//std::for_each(bs.pbegin(), bs.pend(), [](int n) { cout<<"val = "<<n<<"\n"; }) ; 
	//cout<<"\n" ; 
	//std::for_each(bs.pobegin(), bs.poend(), [](int n) { cout<<"val = "<<n<<"\n"; }) ; 
	//cout<<"\n" ; 
}
void testTree()
{
	Tree<int> tree ; 
	cout<<"Inserting elements in BTree\n" ; 
	tree.insert(10) ; tree.insert(20,true) ; tree.insert(30,true) ; 
	tree.insert(40,true) ; tree.insert(50) ; tree.insert(60) ; 
	for_each(tree.begin(), tree.end(), [](int n) { cout<<"val = "<<n<<"\n" ;}) ; 
}
void testTrie()
{
	Trie trie ; 
	trie.addWord("tree") ; trie.addWord("trie") ; trie.addWord("algo") ; trie.addWord("assoc") ; trie.addWord("all") ; trie.addWord("also")  ;
	trie.print() ; 
}
void testSuffix()
{
	SuffixArray arr("banana") ; 
	arr.printArray() ; 
}
int main()
{
	//testBst() ; 
	//testTree() ; 
	//testTrie() ; 
	cout<<"Testing suffix array\n" ; 
	testSuffix() ; 
	cout<<"\n" ; 
	return  0 ; 
}

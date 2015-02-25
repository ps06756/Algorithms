#ifndef SARRAY_H
#define SARRAY_H 
#include <set> 
#include <string> 
#include <iostream> 
#include <algorithm> 
using namespace std ; 
class SuffixArray
{
	public:
		set<string> arr ;
		SuffixArray(string master) ; 
		void construct(string master) ; 
		void printArray() ; 
} ; 
SuffixArray::SuffixArray(string master)
{
	construct(master) ; 
}
void SuffixArray::construct(string master) 
{
	arr.clear() ; // make sure that arr is empty. 
	string s ; // empty string to start with. 
	for(int i=master.size()-1; i>-1; i--) // also insert the empty element. 
	{
		arr.insert(s) ; 
		s.insert(0,1,master[i]) ; 
	}
}
void SuffixArray::printArray()
{
	if(arr.empty() == true)
	{
		cout<<"The array is empty! Did you forget to construct the suffix array first ?\n" ; 
	}
	else
	{
		for(set<string>::iterator it = arr.begin(); it != arr.end(); it++)
		{
			cout<<*it<<"\n" ; 
		}
	}
}
#endif 

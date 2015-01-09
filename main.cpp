#include <simplelist.h> 
#include <heap.h> 
#include <iostream> 
#include <algorithm> 
#include <string> 
using namespace std ; 
int main()
{
	cout<<"Now testing list interface..\n" ; 
	SimpleList<int> list ; 
	list.push_back(10) ; 
	list.push_back(20) ; 
	list.push_back(30) ; 
	list.push_back(40) ; 
	cout<<"size = "<<list.getSize()<<"\n" ; 
	for(SimpleList<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		cout<<*it<<" " ; 
	}
	cout<<"\n" ; 
	cout<<"Now testing the heap interface..\n" ; 
	Heap<int> h ; 
	h.push_back(10) ; 
	h.push_back(5) ; 
	h.push_back(20) ; 
	h.push_back(30) ; 
	cout<<"Using iterators..\n" ; 
	for(Heap<int>::iterator it = h.begin(); it != h.end(); it++)
	{
		cout<<*it<<" "  ; 
	}
	cout<<"\nUsing operators\n" ; 
	for(int i=0; i<h.getSize(); i++)
	{
		cout<<h[i]<<" " ; 
	}
	cout<<"\n" ; 
	return  0 ; 
}

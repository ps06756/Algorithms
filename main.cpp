#include <simplelist.h> 
#include <iostream> 
#include <string> 
using namespace std ; 
int main()
{
	SimpleList<string> list ; 
	list.push_back("Hello") ;
	list.push_back("World") ; 
	list.push_back("Why world") ; 
	cout<<"The elements of the list are :- \n"<<list[0]<<"\t"<<list[1]<<"\t"<<list[2]<<"\n" ; 
	return  0 ; 
}

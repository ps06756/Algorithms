#include <simplelist.h> 
#include <heap.h> 
#include <bst.h> 
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include <string> 
using namespace std ; 
void testBst()
{
	BST<int> bs ; 
	cout<<"Inserting elements in the bst\n" ; 
	bs.insert(10) ;
	bs.insert(20) ; 
	bs.insert(30) ;
	bs.insert(4) ; 
	bs.insert(100) ; 
	std::for_each(bs.begin(), bs.end(), [](int n) { cout<<"val = "<<n<<"\n"; }) ; 
}
int main()
{
	testBst() ; 
	cout<<"\n" ; 
	return  0 ; 
}

#include <tree/bst.h> 
#include <iostream> 
#include <algorithm> 
#include <functional> 
#include <string> 
using namespace std ; 
void testBst()
{
	BST<int> bs ; 
	cout<<"Inserting elements in the bst\n" ; 
	bs.insert(3) ; 
	bs.insert(1) ; 
	bs.insert(8) ; 
	bs.insert(2) ; 
	bs.insert(6) ; 
	bs.insert(7) ; 
	bs.insert(5) ; 
	std::for_each(bs.begin(), bs.end(), [](int n) { cout<<"val = "<<n<<"\n"; }) ; 
}
int main()
{
	testBst() ; 
	cout<<"\n" ; 
	return  0 ; 
}

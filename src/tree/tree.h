#include <vector> 
#include <list> 
using namespace std ; 
template<typename T> 
class Tree
{
	private: 
		vector<list<T> > levels ; 
	public: 
		class iterator
		{
			typedef typename  vector<list<T> >::iterator vit ; 
			typedef typename  list<T>::iterator lit ; 
			vit it ; 
			lit lt ; 
			bool rev ; 
			Tree<T>* tree ; // reference to the outer class.
			public:
//TODO:- Add code to handle the reverse iterators as well. 
			iterator(iterator* cop)
			{
				this->it = cop->it ; 
				this->lt = cop->lt; 
				this->rev = cop->rev ; 
				this->tree = cop->tree ; 
			}
			iterator(Tree* tr, bool reverse=false,bool en=false)
			{
				tree = tr ; 
				rev = reverse ; 
				if(en == false)
				{
					if(rev == false)
					{
						it = tree->levels.begin() ; 
						lt = (*it).begin() ; 
					}
				}
				else
				{
					if(rev == false)
					{
						it = tree->levels.end() ; 
					}
				}
			}
			bool operator == (iterator it2)
			{
				return it == it2.it ; 
			}
			bool operator != (iterator it2)
			{
				return !(this->operator==(it2)) ; 
			}
			T operator *()
			{
				return (*lt) ; 	
			}
			iterator& operator ++()
			{
				this->operator++(1) ; 
				return (*this) ; 
			}
			iterator operator ++(int)
			{
				iterator temp(this) ; 
				if(rev == false) // forward_iterator; 
				{
					if(lt != (*it).end())
						lt++ ; 
					if(lt == (*it).end())  
					{
						it++ ; 
						if(it != tree->levels.end())
							lt = (*it).begin() ; 
					}
				}
				return temp ; 
			}
		} ; 
		void insert(T ele, bool ne=false) // ne means to insert in new level. 
		{
			if(levels.size() == 0)
			{
				list<T> l ; 
				l.push_back(ele) ; 
				levels.push_back(l) ; 
			}
			else
			{
				if(ne == true)
				{
					list<T> l  ; 
					l.push_back(ele) ; 
					levels.push_back(l) ; 
				}
				else
				{
					levels[levels.size()-1].push_back(ele) ; 
				}
			}
		}
		iterator begin()
		{
			iterator it(this) ; 
			return it ; 
		}
		iterator end()
		{
			iterator it(this,false,true) ; 
			return it ; 
		}
} ; 

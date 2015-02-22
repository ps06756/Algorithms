#ifndef TREE_H
#define TREE_H
/* 
 * This file implements the simple tree data structure to be used in other applications. 
 * The interface of the tree data structure is not complete as such but will be completed as soon as we find other methods to add
 * to the class, as we code other data structure. 
 * Compile with :- std=c++1y or std=c++0x 
 * */
#include <vector> 
#include <list> 
#include <iostream> 
using namespace std ; 
template<typename T> 
class Tree
{
	private: 
		vector<list<T> > levels ; 
		//typedef typename Tree<T>::iterator tit ; // to be declared after the declaration of the class iterator.
	public: 
		int totalLevels()
		{
			return levels.size() ; 
		}
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
			iterator()
			{
				tree = nullptr ; 
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
						cout<<"\n" ; 
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
		void insert(T ele, int level) // insertes ele at the level level. 
		{
			if((level < 0)||(level > (int)levels.size()))
			{
				cout<<"Incorrect level information supplied. level = "<<level<<"\n"; 
			}
			else if(level == (int)levels.size())
			{
				insert(ele, true) ;
			}
			else
			{
				levels[level].push_back(ele) ;	
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
	private:
		typedef typename list<T>::iterator tit ; 
	public: 
		tit getLevel(int level)
		{
			if((level < 0)||(level >= (int)levels.size()))
			{
				cout<<"Incorrect arguements supplied to getLevel("<<level<<")\n" ; 
				return getEndLevel(level) ; 
			}
			else
			{
				return levels[level].begin() ; 
			}
		}
		tit getEndLevel(int level)
		{
			if((level < 0)&&(level >= (int)levels.size()))
			{
				cout<<"Incorrect arguments supplied to getEndLevel("<<level<<")\n" ; 
				list<T> dummy ; return dummy.end() ; 	
			}
			else
			{
				return levels[level].end() ; 
			}
		}

} ; 
#endif 

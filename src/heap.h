#ifndef HEAP_H 
#define HEAP_H 
#include <vector> 
using namespace std ; 
template<typename T> 
class Heap
{
	vector<T> nodes ; 
	private:
	void make_heap()  
	{
		while(!is_heap()== true)
		{
			for(int i=0; i<nodes.size(); i++)
			{
				if(2*i+2 < nodes.size())
				{
					if(nodes[2*i+2] > nodes[i])
					{
						int temp = nodes[i] ; 
						nodes[i] = nodes[2*i+2] ; 
						nodes[2*i+2] = temp ; 
					}
					if(nodes[2*i+1] > nodes[i])
					{
						int temp = nodes[i] ;
						nodes[i] = nodes[2*i+1] ; 
						nodes[2*i+1] = temp ; 
					}
				}
				else if (2*i+1 < nodes.size())
				{
					if(nodes[2*i+1] > nodes[i])
					{
						int temp = nodes[i] ; 
						nodes[i] = nodes[2*i+1] ; 
						nodes[2*i+1] = temp ; 
					}
				}
			}
		}
	}
	bool is_heap()
	{
		for(int i=0; i<nodes.size(); i++)
		{
			if(2*i+2 < nodes.size())
			{
				if(nodes[2*i+2] > nodes[i])
					return false ; 
				if(nodes[2*i+1] > nodes[i]) 
					return false ; 
			}
			else if (2*i+1 < nodes.size()) 
			{
				if(nodes[2*i+1] > nodes[i])
					return false ; 
			}
		}
		return true; 
	}
	T get(int pos)
	{
		if((pos < nodes.size()) &&(pos >= 0))
		{
			return nodes[pos] ; 
		}
		else
		{
			// throw some exception. 
		}
	}
	public: 
	class iterator
	{
		private:
			int index   ; 
			Heap* h ; 
		public:
			iterator(int ind, Heap* hi):index(ind), h(hi) { } 
			T operator [](int pos)
			{
				return h->get(pos) ; 
			}
			T operator ++(int pos)
			{
				if(index == h->nodes.size()-1)
				{
					index = -1 ; 
				}
				else
				{
					index++ ;
				}
			}
			T operator *()
			{
				return h->get(index) ; 
			}
			T& operator ++()
			{
				if(index == h->nodes.size()-1)
				{
					index = -1 ; 
				}
				else
				{
					index++ ; 
				}
			}
			bool operator == (iterator it2)
			{
				if(this->index  != it2.index)
					return false ; 
				if(this->h != it2.h)
					return false ; 
				return true ; 
			}
			bool operator != (iterator it2)
			{
				return !(*this == it2) ; 
			}
	} ; 
	void push_back(T num)
	{
		nodes.push_back(num) ; 
		make_heap() ; 
	}
	void pop_max()
	{
		vector<int>::iterator it = nodes.begin() ; 
		nodes.erase(it) ; 
		make_heap() ; 
	}
	iterator begin()
	{
		return iterator(0, this) ; 
	}
	iterator end()
	{
		return iterator(-1, this) ; 
	}

} ; 
#endif 

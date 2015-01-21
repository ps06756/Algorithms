/*  
 *  TODO :- Make the class thread safe. 
 *  TODO :- Compatibility issue with STL library. 
 *  TODO :- Implement a common iterator for classes.*/
#ifndef SIMPLELIST_H 
#define SIMPLELIST_H 
#define NULL 0 
#include <cstdio> 
template<typename T> 
class SimpleList
{
	private:
		template<typename Q> 
			class SimpleNode
			{
				public:
					Q data ; 
					SimpleNode<Q>* next ; 
					SimpleNode(Q dat, SimpleNode<Q>* ne) : data(dat), next(ne) {}    
			} ;   
		int size ; 
		SimpleNode<T>* start ; 
		class lock
		{
			public:
				lock():flag(false) { } 
				bool flag  ;
				bool acquire()
				{
					if(flag == true) // already aquired.
					{
						while(true)
						{
							if(flag == false)
								break ; 
						}
						flag = false ; 
					}
					else if(flag == false)
					{
						flag = true ; // lock acquired...
					}
					return flag ; 
				}
				bool release()
				{
					flag = false;
					return !flag ; 
				}
		} ; 
		lock spinlock ; 
	public:
		class iterator
		{
			private:
				SimpleNode<T>* curr ; 
				int index ; 
				SimpleList<T>* slp ; 
			public:
				iterator(SimpleNode<T>* init, SimpleList<T>* sls):curr(init), slp(sls), index(0) {}
				iterator (SimpleNode<T>* init, SimpleList<T>* sls, int ind):curr(init), slp(sls),index(ind) { }  
				void operator ++()
				{
					if(index >= slp->size-1)
					{
						index = -1 ; 
						curr = NULL ; 
					}
					else
					{
						curr = curr->next ; 
						index++ ; 
					}
				}
				void operator ++(int ind)
				{
					if(index >= slp->size-1)
					{
							index = -1 ; 
							curr = NULL ; 
					}
					else
					{
						curr = curr->next ; 
						index++ ; 
					}
				}
				T operator *()
				{
					return curr->data ; 
				}
				bool operator  == (iterator it2)
				{
					if(index != it2.index)
						return false ; 
					if(slp != it2.slp) 
						return false ; 
					if(curr != it2.curr)
						return false ; 
					return true ; 
				}
				bool operator != (iterator it2)
				{
					return !(*this == it2) ; 
				}
		} ; 
		SimpleList():start(NULL),size(0) { }  
		// default pushes to the top. 
		iterator begin()
		{
			return iterator(start, this) ; 
		}
		iterator end()
		{
			return iterator(NULL, this,-1) ; 
		}
		void push_back(T ele) 
		{
			spinlock.acquire() ; 
			SimpleNode<T>* curr = new SimpleNode<T>(ele, start) ; 
			start = curr ; 
			size++ ; 
			spinlock.release() ; 
		}
		void push_back(T ele , bool top) 
		{
			spinlock.aquire() ; 
			if(top == true)
				push_back(ele) ; 
			else
			{
				SimpleNode<T>* curr = start ; 
				while(curr->next != NULL)
				{
					curr = curr->next; 
				}
				SimpleNode<T>* temp = new SimpleNode<T>(ele, NULL) ; 
				curr->next = temp; 
				size++ ; 
			}
			spinlock.release() ; 
		}
		int getSize()  
		{
			return size ; 
		}
		void del() 
		{
			spinlock.acquire() ; 
			if(start == NULL)
			{
				// throw some exception here.
			}
			else
			{
				SimpleNode<T>* curr = start ; 
				start = curr->next ; 
				delete curr ; 
				size-- ; 
			}
			spinlock.release() ; 
		}
		void del(int pos)  
		{
			spinlock.acquire() ; 
			SimpleNode<T>* curr = start ; 
			int i = 0 ; 
			if(pos >size-1)
			{
				// throw some exception.  
			}
			else
			{
				while(i++<pos-1) 
				{
					curr = curr->next ; 
				}
				SimpleNode<T>* prev = curr ; 
				curr = curr->next ; 
				prev->next = curr->next ; 
				delete curr ; 
				size-- ; 
			}
			spinlock.release() ; 
		}

		T operator [] (int index) const 
		{
			if(index > size-1)
			{
				// throw some exception. 
			}
			else
			{
				int i = 0; 
				SimpleNode<T>* curr = start ; 
				while(i++ < index)
				{
					curr = curr->next ; 
				}
				return curr->data ; 
			}
		}
		~SimpleList()
		{
			while(size != 0)
			{
				del() ; 
			}
		}
} ; 
#endif  

#ifndef simplelist_h
#define simplelist_h 
#define NULL 0 
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
	public:
		class iterator
		{
			private:
				SimpleNode<T>* curr ; 
				int index ; 
				SimpleList<T>* slp ; 
			public:
				iterator(SimpleNode<T>* init, SimpleList<T>* sls):curr(init), slp(sls), index(0) { }
				void operator ++(int ind)
				{
					if(index > slp->size-1)
					{
						// throw some exception. 
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
		} ; 
		SimpleList():start(NULL),size(0) { }  
		// default pushes to the top. 
		iterator begin()
		{
			return iterator(start, this) ; 
		}
		void push_back(T ele) 
		{
			SimpleNode<T>* curr = new SimpleNode<T>(ele, start) ; 
			start = curr ; 
			size++ ; 
		}
		void push_back(T ele , bool top) 
		{
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
			}
		}
		void del() 
		{
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
		}
		void del(int pos)  
		{
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

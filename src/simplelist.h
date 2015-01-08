#ifndef simplelist_h
#define simplelist_h 
#define NULL 0 
template<typename T> 
class SimpleNode
{
	public:
		T data ; 
		SimpleNode<T>* next ; 
		SimpleNode(T dat, SimpleNode<T>* ne) : data(dat), next(ne) {}    
} ; 

template<typename T> 
class SimpleList
{
	private:
		int size ; 
		SimpleNode<T>* start ; 
	public:
		SimpleList():start(NULL),size(0) { }  
		// default pushes to the top. 
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

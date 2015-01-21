#include <vector> 
using namespace std ; 
template<typename T> 
class BST 
{
	private:
		template<typename Q> 
			class Node
			{
				public: 
					Q key ; 
					Node<Q>* left ; 
					Node<Q>* right ; 
					Node<Q>* parent ; 
			} ; 

	public:
		class Iterator
		{
			public: 
				Node<T>* curr ; 
				typedef typename vector<T>::iterator vit ; 
				vit it ; 
				vector<T> order ; 
				void fill_me(Node<T>* r)
				{
					if(r->left != nullptr)
						fill_me(r->left) ; 
					order.push_back(r->key) ; 
					if(r->right != nullptr)
						fill_me(r->right) ; 
				}
				T operator *()
				{
					return (*it) ; 
				}
				void operator ++(int)
				{
					if(it - order.begin() == (int)order.size()-1)
						curr = nullptr ; 
					else
						it++ ; 
				}
				void operator --(int)
				{
					it-- ; 
				}
				Iterator(Node<T>* r)
				{
					curr = r ; 
					Node<T>* x = r ; 
					if(x != nullptr)
					{
						if(x->left != nullptr)
							fill_me(x->left) ; 
						order.push_back(x->key) ; 
						if(x->right != nullptr)
							fill_me(x->right) ; 
						it = order.begin() ; 
					}
					else
					{
						it = order.begin() ; 
					}
				}
				bool operator == (Iterator it2)
				{
					if(curr == it2.curr) return true ; return false ; 
				}
				bool operator != (Iterator it2)
				{
					return !(this->operator==(it2)) ; 
				}
				void operator ++()
				{
					this->operator++(1) ; 
				}
				void operator --()
				{
					this->operator--(1) ; 
				}
		} ; 
		Node<T>* root ;
		int sizei = 0;  
		Iterator begin()
		{
			Iterator it(root) ; 
			return it ; 
		}
		Iterator end()
		{
			Iterator it(nullptr) ; 
			return it ; 
		}
		BST()
		{
			root = nullptr ; 
		}
		~BST()
		{
			if(root != nullptr)
			{
				del(root) ;
			}
		}
		int size()
		{
			return sizei ; 
		}
		void del(Node<T>* nod)
		{
			if(nod == nullptr)
				return  ; 
			if(nod->left != nullptr)
				del(nod->left) ;
			if(nod->right != nullptr)
				del(nod->right) ;
			if(nod == root)
			{
				delete nod ; 
				sizei-- ; 
				return ; 
			}
			if(nod == (nod->parent)->left)
				(nod->parent)->left = nullptr ; 
			else if(nod == (nod->parent)->right)
				(nod->parent)->right = nullptr ; 
			delete nod ; 
			sizei-- ; 
		}
		Node<T>* treeMin(Node<T>* start)
		{
			Node<T>* y=start,*x = start ; 
			if(x == nullptr) return nullptr ; 
			while(x->left != nullptr)
			{
				x = x->right ; 
				y = x ; 
			}
			return y ; 
		}
		void inserts(Node<T>* n)
		{
			Node<T> *y = nullptr,*x = root ; 
			while(x != nullptr)
			{
				y = x ; 
				if(n->key < x->key)
					x = x->left ; 
				else
					x = x->right ; 
			}
			n->parent = y ; 
			if(y == nullptr)
			{
				root = n ; 
			}
			else if(n->key < y->key)
				y->left = n ; 
			else
				y->right = n ; 
			sizei++ ; 
		}
		void dels(Node<T>* val)
		{
			if(val == nullptr)
				return  ;
			if(val->left == nullptr)
				transplant(val, val->right) ; 
			else if(val->right == nullptr)
				transplant(val,val->left) ; 
			else 
			{
				Node<T>* y = treeMin(val->right) ; 
				if(y->parent != val)
				{
					transplant(y,y->right) ; 
					y->right = val->right ; 
					(y->right)->parent = y ; 
				}
				transplant(val,y) ; 
				y->left = val->left; 
				(y->left)->parent = y ; 
			}
			delete val ; 
			sizei-- ; 
		}
		void transplant(Node<T>* u, Node<T>* v)
		{
			if(u->parent == nullptr)
			{
				root = v ; 
			}
			else if(u == (u->parent)->left)
				(u->parent)->left = v ; 
			else 
				(u->parent)->right = v ; 
			if(v != nullptr)
			{
				v->parent = u->parent ; 
			}
		}
		void dels(T val)
		{
			Node<T>* y,*x = root,*temp ; y = x ; 
			while(x != nullptr)
			{
				y = x ; 
				if(val < x->key)
					x = x->left ; 
				else 
					x = x->right ; 
			}
			if(y->key == val)
			{
				temp = y ; 
				dels(temp) ; 
			}

		}
		void insert(T val)
		{
			Node<T>* n = new Node<T> ; n->key = val ; n->left = nullptr ; n->right = nullptr ; n->parent = nullptr ; 
			inserts(n) ; 
		}
} ; 



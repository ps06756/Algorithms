/*
Description :- Implementation of the binary search tree as mentioned in Introduction to algorithms by Cormen. The implementation is more or less C++ STL compatible and provides iterators as an interface to accessing the elements. 
Made by :- Pratik Singhal (ps06756) 
*/ 
/*  
 * Implementation description :- 
 * A binary search tree is a binary tree with the additional restriction that it needs to follow the search tree property.
 * This property is what makes the binary search tree useful than plain binary tree. The search property is as follow :- 
 * 1) The value of left child of the parent must be less than or equal to the parents value and the value of right child of the parent must be greater than that of parent. 
 * As mentioned in Introduction to algorithms A Binary search tree must support these operations :- 
 * 1) Insertion 
 * 2) Deletion 
 * 3) Transplant
 * 4) Inorder Traversal
 * 5) Pre order Traversal
 * 6) Post order traversal 
 *
 * All these operations ar implemented in this file and we also provide the iterators which to do so. 
 * We also provide iterators for in order, post order and pre order traversals of the tree. */
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
		class iterator // iterator for iterating through the tree. 
		{
			public: 
				Node<T>* curr ; 
				typedef typename vector<T>::iterator vit ; 
				vit it ; 
				vector<T> order ; 
				iterator(iterator* ptr)
				{
					this->curr = ptr->curr ; 
					this->it = ptr->it ; 
					this->order = ptr->order ; 
				}
				void fill_me(Node<T>* r) // by default inorder traversal. 
				{
					if(r->left != nullptr)
						fill_me(r->left) ; 
					order.push_back(r->key) ; 
					if(r->right != nullptr)
						fill_me(r->right) ; 
				}
				void fill_me_pre_order(Node<T>* r)
				{
					order.push_back(r->key) ; 
					if(r->left != nullptr)
						fill_me_pre_order(r->left) ; 
					if(r->right != nullptr)
						fill_me_pre_order(r->right) ; 
				}
				void fill_me_post_order(Node<T>* r)
				{
					if(r->left != nullptr)
						fill_me_post_order(r->left) ; 
					if(r->right != nullptr)
						fill_me_post_order(r->right) ; 
					order.push_back(r->key) ; 
				}
				T operator *()
				{
					return (*it) ; 
				}
				iterator operator ++(int)
				{
					iterator temp(this) ; 
					if(it - order.begin() == (int)order.size()-1)
						curr = nullptr ; 
					else
						it++ ; 
					return temp ; 
				}
				void operator --(int)
				{
					it-- ; 
				}
				iterator(Node<T>* r, int state) // 0 for inorder, 1 for preorder and 2 for post order.
				{
					curr = r ; 
					Node<T>* x = r ; 
					if(x != nullptr)
					{
						if(state == 0)
						{
							if(x->left != nullptr)
								fill_me(x->left) ; 
							order.push_back(x->key) ; 
							if(x->right != nullptr)
								fill_me(x->right) ; 
						}
						else if(state == 1)
						{
							order.push_back(x->key) ; 
							if(x->left != nullptr)
								fill_me_pre_order(x->left) ; 
							if(x->right != nullptr)
								fill_me_pre_order(x->right) ; 
						}
						else if(state == 2)
						{
							if(x->left != nullptr)
								fill_me_post_order(x->left) ; 
							if(x->right != nullptr)
								fill_me_post_order(x->right) ; 
							order.push_back(x->key) ; 
						}
						it = order.begin() ; 
					}
					else
					{
						it = order.begin() ; 
					}
				}
				bool operator == (iterator it2)
				{
					if(curr == it2.curr) return true ; return false ; 
				}
				bool operator != (iterator it2)
				{
					return !(this->operator==(it2)) ; 
				}
				iterator& operator ++()
				{
					this->operator++(1) ; 
					return (*this) ; 
				}
				void operator --()
				{
					this->operator--(1) ; 
				}
		} ; 
		Node<T>* root ;
		int sizei = 0;  
		iterator begin() // inorder traversal. 
		{
			iterator it(root,0) ; 
			return it ; 
		}
		iterator end()
		{
			iterator it(nullptr,0) ; 
			return it ; 
		}
		iterator pbegin() // preorder traversal. 
		{
			iterator it(root,1) ; 
			return it ; 
		}
		iterator pend() 
		{
			iterator it(nullptr, 1) ; 
			return it ;
		}
		iterator pobegin() // post-order traversal. 
		{
			iterator it(root,2) ; 
			return it ; 
		}
		iterator poend()
		{
			iterator it(nullptr,2) ; 
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
		Node<T>* treeMin(Node<T>* start) // getMin element from the tree. 
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
		void insert(Node<T>* n) // inserts into the binary search tree. 
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
		void transplant(Node<T>* u, Node<T>* v) // performs the transplant operation on the binary search tree.as mentioned in Cormen CLRS Text book . 
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
			insert(n) ; 
		}
} ; 

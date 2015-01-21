using namespace std ; 
template <typename T> 
class Node
{
	public: 
		T key ; 
		Node<T>* left ; 
		Node<T>* right ; 
		Node<T>* parent ; 
} ; 
template<typename T> 
class BST 
{
	public:
		Node<T>* root ;
		int sizei = 0;  
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
			return sizei ; 
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



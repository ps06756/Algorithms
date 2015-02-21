#include <vector> 
#include <list> 
using namespace std ; 
template<typename T> 
class BT
{
	private: 
		vector<list<T> > levels ; 
	public: 
		void insert(T ele, bool ne=false)
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
} ; 

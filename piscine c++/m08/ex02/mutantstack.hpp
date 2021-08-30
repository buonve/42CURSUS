#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(): std::stack<T>(){};
		MutantStack(const MutantStack &stack){
			*this = stack;	
		};
		~MutantStack(){};
		iterator begin() {return(std::stack<T>::c.begin());}
		iterator end() {return(std::stack<T>::c.end());}
		MutantStack &operator=(const MutantStack &stack){
			std::stack<T>::operator=(stack);
			return *this;
		};
};


#endif
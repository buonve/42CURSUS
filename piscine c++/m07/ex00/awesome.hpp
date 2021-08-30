#ifndef AWESOME_HPP
#define AWESOME_HPP
#include <iostream>

class Awesome
{
	public:
		Awesome(int n): _n(n) {};
		bool operator== (Awesome const &rhs) const {return(this->_n == rhs._n);};
		bool operator!= (Awesome const &rhs) const {return(this->_n != rhs._n);};
		bool operator> (Awesome const &rhs) const {return(this->_n > rhs._n);};
		bool operator< (Awesome const &rhs) const {return(this->_n < rhs._n);};
		bool operator>= (Awesome const &rhs) const {return(this->_n >= rhs._n);};
		bool operator<= (Awesome const &rhs) const {return(this->_n <= rhs._n);};
		int _n;
	private:
};
		std::ostream &operator<<(std::ostream &out, const Awesome data) {
			out << data._n;
			return(out);
			};

#endif
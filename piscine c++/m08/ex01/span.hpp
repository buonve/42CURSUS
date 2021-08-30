#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> nbArr;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &cp);
		~Span();
		Span& operator= (const Span& s);
		void addNumber(int nb);
		class ExceptionFilledArray: public std::exception
		{
			const char *what() const throw();
		};
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);
		class ExceptionNoSpanFound: public std::exception
		{
			const char *what() const throw();
		};
};

#endif
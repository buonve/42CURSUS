#include "span.hpp"

Span::Span(): _N(0) {}

Span::Span(unsigned int N): _N(N) {}

Span &Span::operator= (const Span& s)
{
	this->_N = s._N;
	this->nbArr = s.nbArr;
	return(*this);
}

Span::Span(const Span &cp)
{
	*this = cp;
}

void Span::addNumber(int nb)
{
	if(nbArr.size() + 1 > _N)
		throw ExceptionFilledArray();
	this->nbArr.push_back(nb);
}

const char *Span::ExceptionFilledArray::what() const throw()
{
	return("Exception: Array is already filled!");
}

unsigned int Span::shortestSpan()
{
	if(nbArr.size() <= 1)
		throw ExceptionNoSpanFound();
	//std::vector<int>::iterator iter_start = nbArr.begin();
	//std::vector<int>::iterator iter_end = nbArr.end();
	//std::vector<int>::iterator iter_min = std::min_element(iter_start, iter_end);
	unsigned int minSpan;
	std::vector<int> copy = nbArr;
	std::sort(copy.begin(), copy.end());
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
	{
		if(minSpan > static_cast<unsigned int>(*(it + 1) - *it)) //dereferenziando ottengo direttamente il numero e sottraggo il precedente dal successivo
			minSpan = (*(it + 1) - *it);
	}
	return(minSpan);
}	

unsigned int Span::longestSpan()
{
	if(nbArr.size() <= 1)
		throw ExceptionNoSpanFound();
	return(static_cast<unsigned int> (*(std::max_element(nbArr.begin(), nbArr.end())) - *(std::min_element(nbArr.begin(), nbArr.end()))));
}

const char *Span::ExceptionNoSpanFound::what() const throw()
{
	return("Exception: Span not found!");
}

Span::~Span() {};


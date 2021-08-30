#ifndef KAREN_HPP
#define KAREN_HPP
#include <iostream>
#include <iomanip>

class Karen;
typedef void (Karen::*karen_func)(void);

class Karen
{
	public:
		void complain( std::string level );
		Karen();
		~Karen();
	private:
		std::string levels[4];
		karen_func f[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};

#endif
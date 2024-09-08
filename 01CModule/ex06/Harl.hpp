#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{

public:
	Harl(void);
	~Harl(void);

	void complain(std::string level);


private:
	static const int _levelCount = 4;

	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);

};

typedef void (Harl::*t_func)(void);

#endif

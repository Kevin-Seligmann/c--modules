#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point{

private:
	Fixed const _x;
	Fixed const _y;

public:
	Point(void);
	~Point(void);
	Point(float const x, float const y);
	Point(Point const & other);

	Point & operator=(Point const & rhs);

	Fixed const & y(void) const;
	Fixed const & x(void) const;

};

#endif

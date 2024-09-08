#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void)
	:_x(0)
	,_y(0){
//	std::cout << "Point default contructor" << std::endl;
}

Point::~Point(void){
//	std::cout << "Point default descructor" << std::endl;
}

Point::Point(float const x, float const y)
	:_x(x)
	,_y(y){
//	std::cout << "Point (float, float) constructor" << std::endl;
}

Point::Point(Point const & other)
	:_x(other._x)
	,_y(other._y){
//	std::cout << "Point copy constructor" << std::endl;
}

Point & Point::operator=(Point const & rhs){
//	std::cout << "Point assignment operator" << std::endl;
//	std::cout << "Members of this class are constant, no changes have been made" << std::endl;
	(void) rhs;

	return *this;
}

Fixed const & Point::y() const{
	return this->_y;
}

Fixed const & Point::x() const{
	return this->_x;
}

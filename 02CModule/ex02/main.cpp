#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
	// Subject

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c;

	// Max int is (If int is b bits and s is frac) 	((2^(b-1)) - 1) * (1 / (2 ^ s))
	// So for 32 bits and 8 frac, 8388607.99609
	a = Fixed(8388607.99609f);
	c = Fixed(8388608);
	Fixed d = Fixed(8388607.3f);
	std::cout << "Result: " << a << " " << b << " " << d << std::endl;
	std::cout << a.getRawBits() << std::endl << c.getRawBits() << std::endl << d.getRawBits() << std::endl;

	// Adittion
	std::cout << Fixed(2) + Fixed(5) << std::endl;
	std::cout << Fixed(20.2f) + Fixed(0) << std::endl;

	// Substraction
	std::cout << Fixed(2) - Fixed(5) << std::endl;

	// Multiplication
	std::cout << Fixed(2) * Fixed(5) << std::endl;
	std::cout << Fixed(0) * Fixed(5) << std::endl;
	std::cout << Fixed(2896) * Fixed(2896) << std::endl;
	std::cout << Fixed(2897) * Fixed(2897) << std::endl;

	// Division
	a = Fixed(10);
	c = Fixed(2);
	std::cout << Fixed(2) / Fixed(5) << std::endl;
	std::cout << Fixed(0.5f) / Fixed(3.f) << std::endl;

	// Other
	const Fixed ca(2);
	const Fixed cb(3);

	std::cout << "min 2 3: " << Fixed::min(ca, cb) << std::endl;
	std::cout << "min 3 2: " << Fixed::min(cb, ca) << std::endl;
	std::cout << "max 2 3: " << Fixed::max(ca, cb) << std::endl;
	std::cout << "max 3 2: " << Fixed::max(cb, ca) << std::endl; 

	std::cout << "min 2 3: " << Fixed::min(Fixed(2), Fixed(3)) << std::endl;
	std::cout << "min 3 2: " << Fixed::min(Fixed(3), Fixed(2)) << std::endl;
	std::cout << "max 2 3: " << Fixed::max(Fixed(2), Fixed(3)) << std::endl;
	std::cout << "max 3 2: " << Fixed::max(Fixed(3), Fixed(2)) << std::endl; 

	std::cout << "2 < 3" << (Fixed(2) < Fixed(3)) << std::endl;
	std::cout << "3 < 2" << (Fixed(3) < Fixed(2)) << std::endl;
	std::cout << "3 < 3" << (Fixed(3) < Fixed(3)) << std::endl;
	std::cout << "2 > 3" << (Fixed(2) > Fixed(3)) << std::endl;
	std::cout << "3 > 2" << (Fixed(3) > Fixed(2)) << std::endl;
	std::cout << "3 > 3" << (Fixed(3) > Fixed(3)) << std::endl;
	std::cout << "2 == 3" << (Fixed(2) == Fixed(3)) << std::endl;
	std::cout << "3 == 2" << (Fixed(3) == Fixed(2)) << std::endl;
	std::cout << "3 == 3" << (Fixed(3) == Fixed(3)) << std::endl;
	std::cout << "2 != 3" << (Fixed(2) != Fixed(3)) << std::endl;
	std::cout << "3 != 2" << (Fixed(3) != Fixed(2)) << std::endl;
	std::cout << "3 != 3" << (Fixed(3) != Fixed(3)) << std::endl;
	std::cout << "3 ++" << (Fixed(3)++) << std::endl;
	std::cout << "++ 3 " << (++Fixed(3)) << std::endl;
	std::cout << "3 --" << Fixed(3)-- << std::endl;
	std::cout << "-- 3 " << --Fixed(3) << std::endl;
	return 0;
}

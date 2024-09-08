#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{

public:
	Fixed(void);
	Fixed(const int rawInt);
	Fixed(const float rawFloat);
	Fixed(Fixed const & other);	
	~Fixed(void);
	Fixed & operator=(Fixed const & rhs);
	
	int getRawBits(void) const;
	void setRawBits(int RawBits);
	float toFloat(void) const;
	int toInt(void) const;
	
private:
	static int const _frac = 8;
	int _rawBits;

};

std::ostream& operator<<(std::ostream& os, Fixed const & num);

#endif


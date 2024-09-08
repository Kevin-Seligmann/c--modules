#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{

public:
	Fixed(void);
	Fixed(Fixed const & other);
	~Fixed(void);
	Fixed & operator=(Fixed const & rhs);
	
	int getRawBits(void) const;
	void setRawBits(int RawBits);

private:
	static int const _frac = 8;
	int _rawBits;

};

#endif

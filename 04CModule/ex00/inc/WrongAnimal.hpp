#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const & src);
	virtual ~WrongAnimal(void);

	WrongAnimal & operator=(WrongAnimal const & rhs);

	std::string const & getType(void) const;
	void setType(std::string & type);

	void makeSound(void) const;

protected:
	std::string _type;
};

#endif

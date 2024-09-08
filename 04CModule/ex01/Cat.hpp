#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal 
{
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat & operator=(Cat const & rhs);

		void makeSound(void) const;

		Brain	const *getBrain(void);
		void	setBrain(Brain brain);

	private:
		Brain *_brain;
};

#endif

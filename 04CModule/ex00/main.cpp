#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main (void)
{
	{
		Animal a;
		Animal b(a);
		Animal c;
		std::string str("Othertype");
	
		c.setType(str);

		std::cout << "Type: " << c.getType() << std::endl;
		b = c;

		c.makeSound();
	}

	std::cout << std::endl << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
	delete i;
	delete meta;

	std::cout << std::endl << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongi = new WrongCat();
	std::cout << wrongi->getType() << " " << std::endl;
	wrongi->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongi;

	return 0;
}

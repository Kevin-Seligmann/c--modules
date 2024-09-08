#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main (void)
{
	// Subject
	AAnimal *animals[10];

	for (int i = 0; i < 10; i ++)
	{
		if (i < 5)
		{
			animals[i] = new Dog();
		}
		else
		{
			animals[i] = new Cat();
		}
	}

	for (int i = 0; i < 10; i ++)
	{
		delete animals[i];
	}

	// Other
	// AAnimal animal();

	{
		Brain b;
		Brain *c = new Brain();

		b.setIdea("HI!", 0);

		std::cout << b.getIdea(0) << std::endl;

		std::cout << c->getIdea(0) << std::endl;
		*c = b;
		std::cout << c->getIdea(0) << std::endl;
		delete c;
	}

	{
		Brain *brain = new Brain(); 
		Dog *dog = new Dog();
		Dog *copyDog = new Dog(*dog);
		Dog *copy2Dog = new Dog();
	
		*copy2Dog = *dog;
		dog->setBrain(*brain);

		delete brain;
		delete dog;
		delete copyDog;
		delete copy2Dog;
	}

	{
		Brain *brain = new Brain(); 
		Cat *cat = new Cat();
		Cat *copyCat = new Cat(*cat);
		Cat *copy2Cat = new Cat();
		Cat *copycopy2Cat = copy2Cat;
	
		*copy2Cat = *cat;
		*copy2Cat = *copycopy2Cat;
		cat->setBrain(*brain);

		delete brain;
		delete cat;
		delete copyCat;
		delete copy2Cat;
	}

	return 0;
}

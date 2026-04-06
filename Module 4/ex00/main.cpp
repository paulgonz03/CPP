#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	std::cout << "--- Basic polymorphism test ---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
    
	std::cout << std::endl << "--- WrongAnimal test ---" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrongMeta->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl << "--- WrongCat as WrongCat test ---" << std::endl;
	const WrongCat* realWrongCat = new WrongCat();
	realWrongCat->makeSound();
	delete realWrongCat;

	return 0;
}

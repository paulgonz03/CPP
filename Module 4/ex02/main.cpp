#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define NUMBER_ANIMAL 4

int main()
{
	std::cout << "--- Array of Animals ---" << std::endl;
	const Animal *animals[NUMBER_ANIMAL];
	for (int i = 0; i < NUMBER_ANIMAL / 2; i++)
		animals[i] = new Dog();
	for (int i = 0; i < NUMBER_ANIMAL / 2; i++)
		animals[i + NUMBER_ANIMAL / 2] = new Cat();
	for (int i = 0; i < NUMBER_ANIMAL; i++)
	{
		animals[i]->makeSound();
		delete animals[i];
	}

	std::cout << std::endl << "--- Deep copy: assignment operator ---" << std::endl;
	Dog *dog = new Dog();
	dog->getbrain()->setIdea("hungry", 0);
	Dog *dog2 = new Dog();
	*dog2 = *dog;
	dog->getbrain()->setIdea("changed", 0);
	std::cout << "dog2 idea: " << dog2->getbrain()->getIdeas(0) << std::endl;
	std::cout << "dog  idea: " << dog->getbrain()->getIdeas(0) << std::endl;
	delete dog;
	delete dog2;

	std::cout << std::endl << "--- Deep copy: copy constructor ---" << std::endl;
	Dog basic;
	basic.getbrain()->setIdea("original idea", 0);
	{
		Dog tmp = basic;
		std::cout << "tmp idea: " << tmp.getbrain()->getIdeas(0) << std::endl;
		tmp.getbrain()->setIdea("tmp changed", 0);
		std::cout << "tmp idea after change: " << tmp.getbrain()->getIdeas(0) << std::endl;
	}
	std::cout << "basic idea after tmp destroyed: " << basic.getbrain()->getIdeas(0) << std::endl;

	return 0;
}

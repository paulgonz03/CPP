#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default brain constructor called" << std::endl;
    for (int i = 0; i < IDEAS_LENGTH; i++)
        this->_ideas[i] = "some idea";
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < IDEAS_LENGTH; i++)
        this->_ideas[i] = other._ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
        for (int i = 0; i < IDEAS_LENGTH; i++)
            this->_ideas[i] = other._ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdeas(const int ideaNbr)
{
	if (ideaNbr < 0 || ideaNbr > 99)
		return ("Error there is no ideas here");
	return (this->_ideas[ideaNbr]);
}

void Brain::setIdea(std::string idea, const int& idx)
{
	if (idx >= 0 && idx < 100)
		this->_ideas[idx] = idea;
}
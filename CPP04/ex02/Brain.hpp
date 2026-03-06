#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define IDEAS_LENGTH 100

class Brain
{
private:
    std::string _ideas[IDEAS_LENGTH];

public:
    Brain();
    Brain(const Brain &other);

    Brain &operator=(const Brain &other);

    ~Brain();

	std::string getIdeas(const int ideaNbr);
	void setIdea(std::string, const int& idx);
};

#endif

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

	Harl harl;

	harl.complain(argv[1]);
}
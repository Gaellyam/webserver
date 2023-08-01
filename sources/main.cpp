#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Not enough  arguments." << std::endl;
		return (1);
	}
	(void) argv;
	return 0;
}

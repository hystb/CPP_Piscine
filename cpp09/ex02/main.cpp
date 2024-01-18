#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    try
    {
    	PmergeMe sorter(argc, &argv[1]);
    	if (argc > 2)
        	sorter.run();
    	else
        	std::cout << "There is not in off numbers" << std::endl;
    }
    catch(const std::exception& e)
    {
    	std::cerr << e.what() << std::endl;
    }
    
}
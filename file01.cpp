// Program devoted to educational process with Git

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::cout << "Hello, world!" << std::endl;
	std::cout << "What's going on?" << std::endl;
	std::string input;
	std::cin >> input;
	std::cout << "Don't worry, be happy now!" << std::endl;
	std::cin >> input;
	std::cout << "Perfect! Amazing! Unbelievable!" << std::endl;
	std::cout << "Do you want to continue dialogue?" << std::endl;
	// Now we want to clearify difference between merge and rebase
	// We've done something to understand it
}

/*
Difference between merge and rebase:
When we use merge it takes the source branch content and unites it with the target branch. In this process only the target branch has changes and the history of source branches remains without changes.
Rebase considers all changes as one, compresses them in one entity and then integrates it into the target branch. Therefore in thus process the history of source branches becomes overwritten.
So, merge is easy to use and saves all history, but rebase simplifies history (when clears some commits) and avoid uncorrect merge of commits. 
Usage depends on our aims and way of working.
*/

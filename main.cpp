#include <iostream>
#include <vector>
#include <cstring>
#include "Parser.h"
#include "MyManager.h"

int main(int argc, char* argv[])
{
	MyManager engine;
	Parser parser;

	std::string userInput;
	bool shouldStop = false;
	std::vector<std::string> data;

	while (!shouldStop)
	{
		std::getline(std::cin, userInput);

		data = parser.checkInput(userInput);

		shouldStop = engine.process(data);

		//if (data.size() == 1 || data.size() == 4)
		//{
		//	if (data.size() == 1 && data.at(0) == "STOP")
		//		shouldStop = true;
		//	std::cout << "Cmd is Ok" << std::endl;
		//}
		//else
		//{
		//	std::cout << "Cmd is Not Correct" << std::endl;
		//}

		//for (std::string i : data)
		//	std::cout << i << " ";
		//std::cout << std::endl;
		data.clear();
	}

	return 0;
}
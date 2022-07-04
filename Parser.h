#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
//#include <iostream>

class Parser
{
public:
	std::vector<std::string> separator;
	std::vector<std::string> fields;
	std::vector<std::string> operators;
	std::vector<std::string> data;

	Parser();
	std::vector<std::string> checkInput(std::string userInput);
	std::string removeTabSeparator(std::string userInput);
	std::string removeSpaceSeparator(std::string userInput);
	std::string findField(std::string userInput);
	std::string findOperators(std::string userInput);
	bool isNumber(std::string userInput);
};

#endif // !PARSER_H

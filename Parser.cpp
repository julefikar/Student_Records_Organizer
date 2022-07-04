#include "Parser.h"

Parser::Parser()
{
	separator.push_back("\t");
	separator.push_back(" ");

	fields.push_back("name");
	fields.push_back("age");
	fields.push_back("id");

	operators.push_back("=");
	operators.push_back("<");
	operators.push_back(">");
}

std::string Parser::removeTabSeparator(std::string userInput)
{
	while (userInput.find(separator.front()) != std::string::npos)
	{
		userInput.erase(userInput.find(separator.front()), 1);
	}
	return userInput;
}

std::string Parser::removeSpaceSeparator(std::string userInput)
{
	while (userInput.find(separator.back()) != std::string::npos)
	{
		userInput.erase(userInput.find(separator.back()), 1);
	}
	return userInput;
}

std::string Parser::findField(std::string userInput)
{
	for (std::string i : fields)
	{
		if (userInput.find(i) != std::string::npos)
			return i;
	}
	return "";
}

std::string Parser::findOperators(std::string userInput)
{
	for (std::string i : operators)
	{
		if (userInput.find(i) != std::string::npos)
			return i;
	}
	return "";
}

bool Parser::isNumber(std::string userInput)
{
	for (char c : userInput) 
	{
		if (std::isdigit(c) == 0)
			return false;
	}
	return true;
}

std::vector<std::string> Parser::checkInput(std::string userInput)
{
	data.clear();

	userInput = removeTabSeparator(userInput);

	if (userInput.find("ADD") != std::string::npos)
	{
		data.push_back("ADD");
		userInput.erase(0, userInput.find("ADD") + 3);
		bool flag = false;
		for (int i = 0; i <= userInput.size(); i++)
		{
			if (userInput.find(" ") == 0)
				userInput.erase(0, 1);
			else if (!isNumber(userInput.substr(0, i)) && !flag)
			{
				std::string str = userInput.substr(0, i-1);
				//std::cout << str << std::endl;
				data.push_back(str);
				userInput.erase(0, i-1);
				flag = true;
				i = -1;
			}
			else if (flag && isNumber(userInput.substr(i-1,i)))
			{
				std::string str = userInput.substr(0, i-1);
				//std::cout << str << std::endl;
				if (userInput.find(" ") == str.length() - 1)
					str = str.substr(0, str.length() - 1);

				userInput.erase(0, i-1);
				data.push_back(str);
				flag = false;
				i = 0;
			}
		}
		data.push_back(userInput);
	}
	else if (userInput.find("FIND") != std::string::npos || userInput.find("REMOVE") != std::string::npos)
	{
		if (userInput.find("FIND") != std::string::npos)
			data.push_back("FIND");
		else if (userInput.find("REMOVE") != std::string::npos)
			data.push_back("REMOVE");

		std::string field, op;

		field = findField(userInput);
		if(field != "")
			data.push_back(field);

		op = findOperators(userInput);
		if (op != "")
		{
			data.push_back(op);
			userInput.erase(0, userInput.find(op) + op.length());
		}

		if (field == "name")
		{
			if (userInput.find("\"") != std::string::npos)
			{
				while (userInput.find("\"") != std::string::npos)
					userInput.erase(userInput.find("\""), 1);
				if (!isNumber(userInput))
					data.push_back(userInput);
			}
			else if (userInput.find(" ") != std::string::npos)
			{

			}
			else
			{
				if (!isNumber(userInput))
					data.push_back(userInput);
			}
		}
		else if (field == "age" || field == "id")
		{
			userInput = removeSpaceSeparator(userInput);
			if (isNumber(userInput))
				data.push_back(userInput);
		}
	}
	else if (userInput.find("STOP") != std::string::npos)
	{
		data.push_back("STOP");
	}
	return data;
}

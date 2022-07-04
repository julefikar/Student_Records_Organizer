#include "MyManager.h"

MyManager::MyManager()
{
	dm.read("Input.txt");
}

bool MyManager::ADD(std::vector<std::string> cmd)
{
	Student obj;
	obj.studentId = std::stoi(cmd.at(1));
	obj.name = cmd.at(1);
	obj.age = std::stoi(cmd.at(3));
	dm.records.push_back(obj);
	return false;
}
bool MyManager::FIND(std::vector<std::string> cmd)
{
	bool flag = true;
	for (int i = 0; i < dm.records.size(); i++)
	{
		if(cmd.at(1) == "name")
		{ 
			if (cmd.at(2) == "=" && cmd.at(3) == dm.records.at(i).name)
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
		}
		else if(cmd.at(1) == "age")
		{
			if (cmd.at(2) == "=" && std::stoi(cmd.at(3)) == dm.records.at(i).age)
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
			else if (cmd.at(2) == "<" && dm.records.at(i).age < std::stoi(cmd.at(3)))
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
			else if (cmd.at(2) == ">" && dm.records.at(i).age > std::stoi(cmd.at(3)))
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
		}
		else if(cmd.at(1) == "id")
		{ 
	
			if (cmd.at(2) == "=" && std::stoi(cmd.at(3)) == dm.records.at(i).studentId)
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
			else if (cmd.at(2) == "<" && dm.records.at(i).studentId < std::stoi(cmd.at(3)))
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
			else if (cmd.at(2) == ">" && dm.records.at(i).studentId > std::stoi(cmd.at(3)))
			{
				std::cout << dm.records.at(i).studentId << "   " << dm.records.at(i).name << "   " << dm.records.at(i).age << std::endl;
				flag = false;
			}
		}
	}
	if (flag)
		std::cout << "No Record Found!" << std::endl;
	flag = false;
	return flag;
}
bool MyManager::REMOVE(std::vector<std::string> cmd)
{
	bool flag = true;
	for (int i = 0; i < dm.records.size(); i++)
	{
		if (cmd.at(1) == "name")
		{
			if (cmd.at(2) == "=" && cmd.at(3) == dm.records.at(i).name)
			{
				dm.records.erase(dm.records.begin()+i);
				flag = false;
				i -= 1;
			}
		}
		else if (cmd.at(1) == "age")
		{
			if (cmd.at(2) == "=" && std::stoi(cmd.at(3)) == dm.records.at(i).age)
			{
				dm.records.erase(dm.records.begin() + i);
				flag = false;
				i -= 1;
			}
			else if (cmd.at(2) == "<" && dm.records.at(i).age < std::stoi(cmd.at(3)))
			{
				dm.records.erase(dm.records.begin() + i);
				flag = false;
				i -= 1;
			}
			else if (cmd.at(2) == ">" && dm.records.at(i).age > std::stoi(cmd.at(3)))
			{
				dm.records.erase(dm.records.begin() + i);	
				flag = false;
				i -= 1;
			}
		}
		else if (cmd.at(1) == "id")
		{

			if (cmd.at(2) == "=" && std::stoi(cmd.at(3)) == dm.records.at(i).studentId)
			{
				dm.records.erase(dm.records.begin() + i);
				flag = false;
				i -= 1;
			}
			else if (cmd.at(2) == "<" && dm.records.at(i).studentId < std::stoi(cmd.at(3)))
			{
				dm.records.erase(dm.records.begin() + i);
				flag = false;
				i -= 1;
			}
			else if (cmd.at(2) == ">" && dm.records.at(i).studentId > std::stoi(cmd.at(3)))
			{
				dm.records.erase(dm.records.begin() + i);
				flag = false;
				i -= 1;
			}
		}
	}
	if (flag)
		std::cout << "No Record Found!" << std::endl;
	flag = false;
	return flag;
}
bool MyManager::STOP()
{
	dm.write("Input.txt");
	return true;
}
bool MyManager::process(std::vector<std::string> cmd)
{

	if (cmd.front() == "ADD")
		return ADD(cmd);
	else if (cmd.front() == "FIND")
		return FIND(cmd);
	else if (cmd.front() == "REMOVE")
		return REMOVE(cmd);
	else if (cmd.front() == "STOP")
		return STOP();
}
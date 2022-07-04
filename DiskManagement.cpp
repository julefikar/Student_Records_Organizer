#include "DiskManagement.h"

void DiskManagement::read(std::string inputs)
{
	std::ifstream reader(inputs);
	if (!reader.is_open())
	{
		std::cout << "File Doesn't Exist" << std::endl;
	}
	else
	{
		while (!reader.eof())
		{
			Student obj;
			reader >> obj.studentId;
			reader >> obj.age;
			std::getline(reader,obj.name);
			if (obj.name.find(" ") == 0)
				obj.name.erase(0, 1);
			records.push_back(obj);
		}
	}
	reader.close();
}

void DiskManagement::write(std::string inputs)
{
	std::ofstream writer(inputs);
	if (!writer.is_open())
	{
		std::cout << "File Doesn't Exist" << std::endl;
	}
	else
	{
		for (int i = 0; i < records.size(); i++)
		{
			writer << records.at(i).studentId << " ";
			writer << records.at(i).age << " ";
			writer << records.at(i).name << "\n";

		}
	}
	writer.close();
}
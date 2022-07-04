#ifndef DISKMANAGEMENT_H
#define DISKMANAGEMENT_H

#include <vector>
#include <fstream>
#include <iostream>
#include "Student.h"

class DiskManagement
{
public:
	std::vector<Student> records;
	void read(std::string inputs);
	void write(std::string inputs);
};
#endif // !DISKMANAGEMENT_H

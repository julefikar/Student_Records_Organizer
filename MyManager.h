#ifndef MYMANAGER_H_
#define MYMANAGER_H_

#include <vector>
#include <string>
#include "DiskManagement.h"

class MyManager
{
public:
    DiskManagement dm;
    MyManager();
    bool ADD(std::vector<std::string>);
    bool FIND(std::vector<std::string>);
    bool REMOVE(std::vector<std::string>);
    bool STOP();
    bool process(std::vector<std::string>);

};

#endif // !MYMANAGER_H_
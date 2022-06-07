//----------------------------------
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
class Executer
{
public:
    Executer();
    std::string exec(const char *cmd);
};
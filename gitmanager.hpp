#include <iostream>
#include <string>
#include <algorithm>
#include <filesystem>
// #include "Executer.hpp"
class GitManager
{
public:
    GitManager();
    GitManager(const GitManager &ret) = delete;
    GitManager operator=(GitManager &ref) = delete;

    bool CheckExistance();
    bool add();
    void status();
    bool commit();
    bool push();

    std::string get_files();
    static std::string REPO_DEFUALT;

private:
    void printTemplate();
    static const std::string ACCESS_TOKEN;
    static const std::string USERNAME;

    std::string m_files;
};

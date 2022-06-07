#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <filesystem>
#include "gitmanager.hpp"
#include "decorator.hpp"

// uncomment to show message of debug leevl
//  #define DEBUG_OUT

int main(int argc, char *argv[])
{
#ifdef __linux__
    /*objects*/
    GitManager git;
    decorator doc;
    if (strcmp(argv[1], "help") == 0 || strcmp(argv[1], "--help") == 0)
    {
        std::cout << "pusher_git <repo name>" << std::endl;
        return 0;
    }
    if (argv[1] != 0)
    {
        GitManager::REPO_DEFUALT = std::string(argv[1]);
    }
    if (git.CheckExistance() != true)
    {
        doc.DisplaySpliiter("Error");
        return 0;
    }
    /*start*/
    doc.DisplaySpliiter("Start");
    std::cout << "[+] this status before running our script" << std::endl;
    git.status();

    /* add */
    doc.DisplaySpliiter("add phase");
    if (git.add() == 0)
    {
        std::cout << "[+] added is done successfully" << std::endl;
    }
    else
    {
        std::cout << "[X] added is failed " << std::endl;
        return -1;
    }

    /* commit */
    doc.DisplaySpliiter("commit phase");

    if (git.commit() == 0)
    {
        std::cout << "[+] commit is done successfully" << std::endl;
    }
    else
    {
        std::cout << "[X] commit is failed " << std::endl;
        return -1;
    }

    /* push */
    std::cout << "[+] this status after running our script" << std::endl;
    git.status();
    doc.DisplaySpliiter("push phase");

    git.push();
#else
    std::cout << " This program support Linux only " << std::endl;
#endif

#if DEBUG_OUT
// std::cout << argv[0] << std::endl;
// std::cout << argv[1] << std::endl;
#endif
    return 0;
}
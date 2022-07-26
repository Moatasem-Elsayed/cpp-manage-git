#include "gitmanager.hpp"
#include <vector>
#include <string>
const std::string GitManager::ACCESS_TOKEN = "";
const std::string GitManager::USERNAME = "Moatasem-Elsayed";
std::string GitManager::REPO_DEFUALT = "cpp-manage-git";
GitManager::GitManager()
{
}

std::string GitManager::get_files()
{
    return m_files;
}
void GitManager::printTemplate()
{
    std::string form = R"(echo "#cpp - manage - git " >> README.md
git init
git add README.md
git commit -m "first commit
git branch -M main
git remote add origin <remote link > like -> https://github.com/Moatasem-Elsayed/cpp-manage-git.git
")";
    std::cout << form << std::endl;
}
bool GitManager::CheckExistance()
{
    int ret = 0;

    ret = std::system("[ -d .git ]");
    if (ret != 0)
    {
        std::cout << "[-] Failed : please adjust .git settings " << std::endl;
        printTemplate();
        return false;
    }
    return true;
}
void GitManager::status()
{
    std::system("git status");
}
bool GitManager::add()
{
    std::string answer = "y";
    bool ret = true;
    std::string files;
    std::cout << " would you like to add all changing files Y/N ? " << std::endl;
    // std::cin >> answer;
    std::getline(std::cin, answer);

    std::string cmd("git add ");
    switch (answer[0])
    {
    case 'Y':
    case 'y':
        cmd += " *";
        ret = std::system(cmd.c_str());
        break;
    default:
        std::cout << "please write the name of files to add " << std::endl;
        std::getline(std::cin, files);
        if (files.find('/') || files.find(';') || files.find('&') || files.find('|'))
        {
            std::cout << "Wrong Usage " << std::endl;
            std::cout << "Usage : filename1 filename2 filename3 etc " << std::endl;
            ret = 1;
        }
        else if (files.size())
        {
            cmd += files;
            ret = std::system(cmd.c_str());
        }

        break;
    }
    std::cin.clear();
    return ret;

#ifdef DEBUG_OUT
    std::vector<std::string> lstfiles;
    std::string temp;
    int len = files.length();
    for (int i = 0; i < len; i++)
    {
        if (files[i] != ' ' && i != len - 1)
        {
            temp += files[i];
        }
        else
        {
            lstfiles.push_back(temp);
            temp.clear();
        }
    }
    std::cout << "CMD is " << cmd << std::endl;
    std::for_each(lstfiles.begin(), lstfiles.end(), [=](std::string val)
                  { std::cout << val << std::endl; });
#endif
}

bool GitManager::commit()
{
    std::string message = " ";
    std::cout << "please write your commit message" << std::endl;

    std::getline(std::cin, message);
    std::string cmd("git commit -m \"" + std::string{message} + "\"");
    std::cout << "command is " << cmd << std::endl;
    return std::system(cmd.c_str());
}
bool GitManager::push()
{
    std::string answer;
    bool ret = false;
    std::string reponame;
    std::cout << "please write repo name " << std::endl;
    std::getline(std::cin, reponame);
    if (reponame.size() == 0)
    {
        reponame = REPO_DEFUALT;
    }
    std::string github_username;
    std::cout << "please write github username " << std::endl;
    std::getline(std::cin, github_username);
    if (reponame.size() == 0)
    {
        github_username = USERNAME;
    }
    std::string cmd(" git push https://" + ACCESS_TOKEN + "@github.com/" + github_username + "/" + reponame + ".git");

    // git push https://<GITHUB_ACCESS_TOKEN>@github.com/<GITHUB_USERNAME>/<REPOSITORY_NAME>.git

    std::cout << "would you prefer to use defult (token-name) Y/N ?" << std::endl;
    std::getline(std::cin, answer);

    switch (answer[0])
    {
    case 'Y':
    case 'y':
        std::cout << "Pushing now" << std::endl;
        ret = std::system(cmd.c_str());
        break;

    default:
        std::string access_token;
        std::string name;
        std::cout << "please insert your name" << std::endl;
        std::getline(std::cin, name);
        std::cout << "please insert your access token" << std::endl;
        std::getline(std::cin, access_token);
        std::string cmd(" git push https://" + access_token + "@github.com/" + name + "/" + reponame + ".git");
        ret = std::system(cmd.c_str());
        break;
    }
    return ret;
}

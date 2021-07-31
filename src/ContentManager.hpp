#pragma once

#include <list>
#include <string>
#include <filesystem>

class ContentManager
{

public:
    ContentManager();

    std::list<std::string> getStageList();
    std::list<std::string> getStageShortList();

private:
    void getStageFileNames(const std::filesystem::directory_entry &dir); // fill stagesList

    std::list<std::string> stageList;
    std::list<std::string> stageShortList;
};
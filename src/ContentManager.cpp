#include "ContentManager.hpp"

#include <iostream>

static const std::filesystem::path path = "../base/stages/"; // read this from a config file

ContentManager::ContentManager()
{
    auto directory = std::filesystem::directory_entry(path);
    getStageFileNames(directory);
}

void ContentManager::getStageFileNames(const std::filesystem::directory_entry &dir)
{
    if (dir.exists())
    {
        for (const auto &entry : std::filesystem::directory_iterator(dir))
        {
            stageList.emplace_back(entry.path());                 // result[0] "../base/stages/classic.lvl"
            stageShortList.emplace_back(entry.path().filename()); // classic.lvl
        }
    }
}

std::list<std::string> ContentManager::getStageList()
{
    return stageList;
}

std::list<std::string> ContentManager::getStageShortList()
{
    return stageShortList;
}
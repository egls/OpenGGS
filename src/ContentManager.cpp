#include "ContentManager.hpp"

#include <iostream>

static const std::filesystem::path path = "../base/stages/"; // read this from a config file
std::vector<std::string> ContentManager::stageShortList_;
std::list<std::string> ContentManager::stageList;
std::string ContentManager::selectedStageFile;

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
            stageList.emplace_back(entry.path());                  // result[0] "../base/stages/classic.lvl"
            stageShortList_.emplace_back(entry.path().filename()); // classic.lvl
        }
    }
}

std::string ContentManager::getSelectedStageFile()
{
    return selectedStageFile;
}

// former CONTENT_STAGES_Load_Write::Load_Stagefile(int)
bool ContentManager::selectStageFileToLoad(int stageFileNumber)
{
    auto it = stageList.begin();
    std::advance(it, stageFileNumber-1);
    if (it != stageList.end())
    {
        selectedStageFile = *it;
        //   AUDIO_Sound_Play(AUDIO_DISK); TODO: AudioManager::PlaySound(AudioDisk)
        //   STAGES_Import();
        //   QuitToMenu = true;
        return true;
    }
    return false;
}

std::list<std::string> ContentManager::getStageList()
{
    return stageList;
}

std::list<std::string> ContentManager::getStageShortList()
{
    return stageShortList;
}
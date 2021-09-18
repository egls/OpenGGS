#include "ContentManager.hpp"
#include "Audio.hpp"
#include <iostream>

static const std::filesystem::path path = "base/stages/"; // read this from a config file
std::vector<std::string> ContentManager::stageShortList_;
std::vector<std::string> ContentManager::stageList_;
// set the classic levels as default
std::string ContentManager::selectedStageFile = "base/stages/classic.lvl";

ContentManager::ContentManager() 
{
    auto directory = std::filesystem::directory_entry(path);
    getStageFileNames(directory);
}

void ContentManager::getStageFileNames(const std::filesystem::directory_entry &dir)
{
    std::cout << "getStageFileNames() " << dir.path() << "\n";
    if (dir.exists())
    {
        for (const auto &entry : std::filesystem::directory_iterator(dir))
        {
            std::cout << entry.path() << "\n";
            stageList_.emplace_back(entry.path());                  // result[0] "../base/stages/classic.lvl"
            stageShortList_.emplace_back(entry.path().filename()); // classic.lvl
        }
    }
}

std::string ContentManager::getSelectedStageFile()
{
    std::cout << "selectedStageFile: " << selectedStageFile << "\n";
    return selectedStageFile;
}

// former CONTENT_STAGES_Load_Write::Load_Stagefile(int)
bool ContentManager::selectStageFileToLoad(int stageFileNumber)
{
    std::cout << "selectedStageFileToLoad() : " << stageFileNumber << "\n";
    if(stageFileNumber >= 0 && stageFileNumber < stageList_.size()){
        selectedStageFile = stageList_.at(stageFileNumber);
        Audio::playSound(Audio::AudioTypeEnum::AUDIO_DISK);
        //   STAGES_Import();
        //   QuitToMenu = true;
        return true;
    }

    return false;
}

std::vector<std::string> ContentManager::getStageList()
{
    return stageList_;
}

std::vector<std::string> ContentManager::getStageShortList()
{
    return stageShortList_;
}
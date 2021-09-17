#pragma once

#include <list>
#include <vector>
#include <string>
#include <filesystem>

class ContentManager
{

public:
    ContentManager();

    // STAGE FILE
    std::vector<std::string> getStageList();
    static std::vector<std::string> getStageShortList();
    static std::string getSelectedStageFile();
    static bool selectStageFileToLoad(int stageFileNumber);
   

private:
    void getStageFileNames(const std::filesystem::directory_entry &dir); // fill stagesList
    static std::vector<std::string> stageList_;
    static std::vector<std::string> stageShortList_;
    static std::string selectedStageFile;
};

// Classes Needed

// class Stage
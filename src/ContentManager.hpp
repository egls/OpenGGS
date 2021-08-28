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
    std::list<std::string> getStageList();
    static std::vector<std::string> getStageShortList();
    static std::string getSelectedStageFile();
    static bool selectStageFileToLoad(int stageFileNumber);
   

private:
    void getStageFileNames(const std::filesystem::directory_entry &dir); // fill stagesList
    static std::list<std::string> stageList;
    static std::vector<std::string> stageShortList_;
    // std::list<std::string> stageShortList;
    static std::string selectedStageFile;
};

// Classes Needed

// class Stage
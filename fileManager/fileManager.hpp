#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>

using namespace std;

namespace fs = std::filesystem;

class FileManager
{
private:
    string rootFolder;

public:
    FileManager(string rootFolder);
    void createFile(string fileName);
    void createFolder(string path);
    void deleteFile(string fileName);
    void deleteFolder(string path);

    vector<string> listFiles();
    vector<string> listFiles(string path);

    void move(string source, string destination); // works with files and folders
    void copy(string source, string destination); // works with files and folders
    void rename(string oldName, string newName);  // works with files

    void clear(string path);
    void clear();
};

FileManager::FileManager(string rootFolder)
{
    if (!fs::exists(rootFolder))
    {
        fs::create_directory(rootFolder);
    }
    this->rootFolder = rootFolder;
}

void FileManager::createFile(string fileName)
{
    ofstream file(rootFolder + "/" + fileName);
}

void FileManager::deleteFile(string fileName)
{
    fs::remove(rootFolder + "/" + fileName);
}

vector<string> FileManager::listFiles()
{
    vector<string> files;
    for (const auto &entry : fs::directory_iterator(rootFolder))
    {
        if (fs::is_regular_file(entry.path()))
        {
            files.push_back(entry.path().filename().string());
        }
        else
        {
            files.push_back(entry.path().filename().string() + "/");
        }
    }
    return files;
}

vector<string> FileManager::listFiles(string path)
{
    vector<string> files;
    for (const auto &entry : fs::directory_iterator(rootFolder + "/" + path))
    {
        if (fs::is_regular_file(entry.path()))
        {
            files.push_back(entry.path().filename());
        }
        else
        {
            files.push_back(entry.path().filename().string() + "/");
        }
    }
    return files;
}

void FileManager::deleteFolder(string path)
{
    fs::remove_all(path);
}

void FileManager::createFolder(string path)
{
    fs::create_directory(rootFolder + "/" + path);
}

void FileManager::move(string source, string destination)
{
    fs::rename(source, destination);
}

void FileManager::copy(string source, string destination)
{
    fs::copy(source, destination);
}

void FileManager::rename(string oldName, string newName)
{
    fs::rename(rootFolder + "/" + oldName, rootFolder + "/" + newName);
}

void FileManager::clear(string path)
{
    fs::remove_all(rootFolder + "/" + path);
    fs::create_directory(rootFolder + "/" + path);
}

void FileManager::clear()
{
    fs::remove_all(rootFolder);
    fs::create_directory(rootFolder);
}
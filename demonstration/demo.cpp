#include <iostream>
#include <string>
#include <vector>
#include "../fileManager/fileManager.hpp"

using namespace std;

int main()
{

    // create file manager
    FileManager fileManager("/Get/It/Some/Accessible/Folder");
    //! change to your root folder

    // create file text.txt
    fileManager.createFile("text.py");

    // create folder staff
    fileManager.createFolder("staff");

    // create file in folder staff
    fileManager.createFile("staff/prog.py");

    // list files in root folder
    cout << "Files in root folder:" << endl;
    vector<string> files = fileManager.listFiles();

    for (int i = 0; i < files.size(); i++)
    {
        cout << files[i] << endl;
    }

    // list files in folder staff
    cout << "Files in folder staff:" << endl;
    files = fileManager.listFiles("staff");

    for (int i = 0; i < files.size(); i++)
    {
        cout << files[i] << endl;
    }

    // delete file in folder staff
    fileManager.deleteFile("staff/prog.py");

    // delete folder staff
    fileManager.deleteFolder("staff");

    // clear root folder
    fileManager.clear();

    return 0;
}
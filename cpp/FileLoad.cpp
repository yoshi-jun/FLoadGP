#include<iostream>
#include<fstream>
#include<vector>
//=============================================================================
std::vector<std::vector<std::string>> GetFileName()
{
    std::vector<std::vector<std::string>> f_name;
    
    for (int i=1; i<201; i++) {
        std::string f = std::to_string(i) + ".txt";
        f_name[i].push_back(f);
    }

    return f_name;
}
//-----------------------------------------------------------------------------
int main() {
    // Make File Name
    auto f_names = GetFileName();

    // Loading File
    

    std::exit(EXIT_SUCCESS);
}
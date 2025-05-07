#include<iostream>
#include<fstream>
#include<vector>
#include<chrono>

//=============================================================================
std::vector<std::string> GetFileName()
{
  std::vector<std::string> f_name;

  for (int i=1; i<201; i++) {
    std::string f = "../wikipedia_articles/"+std::to_string(i) + ".txt";
    f_name.push_back(f);
  }

    return f_name;
}
//-----------------------------------------------------------------------------
std::vector<std::vector<std::string>> LoadFile(
  std::vector<std::string> f_names)
{
  // Initialize vec for storing data
  std::vector<std::vector<std::string>> file_data;  
  file_data.resize(f_names.size());

  for (int i=0; i<f_names.size(); i++) {

    std::string url, text;
    std::ifstream fin(f_names[i]);
    
    std::getline(fin, url);
    std::getline(fin, text);

    file_data[i].push_back(url);
    file_data[i].push_back(text);

  };
  return file_data;
}

//-----------------------------------------------------------------------------
int main() {

  auto start = std::chrono::system_clock::now();
  // Make File Name
  auto f_names = GetFileName();

  // Load File
  auto data = LoadFile(f_names);
  
  // //For check data
  // for (std::vector<std::string> d : data) {
  //   std::cout << "url= " << d[0] << std::endl;
  // }

  auto end = std::chrono::system_clock::now();
  auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() / 1000.0;
  auto time = static_cast<double>(diff);
  std::cout << "time =  " << time << std::endl;
  std::exit(EXIT_SUCCESS);
}
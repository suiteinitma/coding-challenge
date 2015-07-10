#include <iostream>
#include <fstream>
#include <map>
#include <string>

typedef std::map<std::string, int> StrIntMap;


// Using std::map to count the occurence of each unique word.
  void countWords(std::istream& in, StrIntMap& words) {
    std::string s;
    while (in >> s) {
        ++words[s];
    }
  }       

  int main(int argc, char** argv) {
//Check input.
     if (argc < 3)
        return -1;

     std::ifstream in(argv[1]);

     if (!in)
        return -1;


     StrIntMap w;
// Count the occurence of each word and store the result in the map w.
     countWords(in, w);

     std::ofstream myfile;
     myfile.open(argv[2]);
     
// Output the occurence of each word from the map (alphabetically).
     for (StrIntMap::iterator p = w.begin();p != w.end(); ++p) {
        myfile << p->first << "\t" << p->second << "\n";
     }

     myfile.close();
     return 0;
  }

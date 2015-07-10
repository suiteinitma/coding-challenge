#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <sstream>

// Count the number of unique words in a given string.
// The input string is tranformed into stringstream type in order to use the >> operator to read each chunk of word separated by spaces.
// std::map is use to store each occurence of a unique word.

int lineWordCount(const std::string& line) {
    std::set<std::string> setstr;
    std::stringstream stream(line); 
    std::string s; 
    while (stream >> s) {
        setstr.insert(s);
     }
    return setstr.size();
}  



  int main(int argc, char** argv) {

// Check input.
     if (argc < 3){
        std::cout << "Not enough input! \n";
        return -1;
     }

     std::ifstream in(argv[1]);

     if (!in){
        std::cout << "Empty File! \n";
        return -1;
     }
         

     std::string line;

     long long int totalWords = 0;
     long long int lineCount = 0;

     std::ofstream myfile;
     myfile.open(argv[2]);
 
// Fetch one line at a time, count the total number of words and update the average.
     while(getline(in, line)){
        totalWords += lineWordCount(line);
        ++lineCount;
        myfile << (float)totalWords/lineCount << "\n" ;
     }

     if(lineCount < 2) std::cout << "wrong \n";

     myfile.close();
     return 0;
  }

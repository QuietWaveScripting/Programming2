#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

std::vector<std::string> split(std::string const &line, char sep, bool ignore_empty = false)
{
    std::vector <std::string> parts;
    //loop through the line
    // add letters to words. if  sep -> add word to vec -> reset
    std::string current_word = "";
    for (char c : line){
        if(c != sep)
        {
            current_word += c;
            continue;
        }

        //check emptiness
        if(!(current_word.empty() && ignore_empty))
        {
            parts.push_back(current_word);
        }
        current_word.clear();
    }
    if(!(current_word.empty() && ignore_empty))
    {
        parts.push_back(current_word);
    }
    return parts;
}

int main()
{
   // fetch filename
   string filename;
   cout << "Input file: ";
   getline (cin, filename);

   // open file
   ifstream file(filename);

   // check if file open
   if(!file){
        cout << "Error! The file " << filename << " cannot be opened." << endl;
        return EXIT_FAILURE;
   }

   // read file
   // map<word(string), rows(set<int>)

   map<string, set<int>> words;

   string line;
   int line_number = 1;
   while(getline(file,line)){
        vector<string> parts = split(line, ' ');
        for(string &word : parts){
            // check if word in map
            if(words.find(word) == words.end()){
                words.insert({word, {}});
            }
            // save line numbers to word's set
            words.at(word).insert(line_number);
        }
        line_number++;
   }

   // print out results
   for(pair<string, set<int>> const &word : words){
       // amount of times word was found = length of set
       int count = word.second.size();
       cout << word.first << ' ' << count << ": ";
       // print line numbers as well
       // we'll use iterators because it makes it possible to check if we've reached the end
       for(set<int>::iterator line_iter = word.second.begin();
           line_iter != word.second.end(); line_iter++)
       {
           //line value
            cout << *line_iter;
            // if line number last on list, don't add comma
            if(++line_iter != word.second.end()){
                cout << ", ";
            }
            --line_iter;
       }
       cout << endl;


   }






    return 0;
}

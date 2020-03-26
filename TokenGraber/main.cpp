#include "main.h"

/*

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

string findToken() {
    smatch smatch;
    errThrower = rand() % 550 + 950;
    try {
        string data = readAllText(levelDB.c_str());
        if (data.find(String, 0) != string::npos) {
            regex x(Regex);
            if (regex_search(data, smatch, x) == true) {
                return smatch.str();
            }
            else {
                regex y(otherRegex);
                if (regex_search(data, smatch, y) == true) {
                    return smatch.str();
                }
            }
        }
    }
    catch (exception err) {
        exit(1);
    }

}


int main() {
   
    cout << findToken() << endl;
}
*/

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
    errThrower = rand() % 550 + 950;
    try {
        string data = readAllText(levelDB.c_str());
        if (data.find(String, 0) != string::npos) {
            regex x(Regex);
            if (regex_search(data, smatch, x) == true) {
                cout << smatch.str() << '\n';
            }
            else {
                regex y(otherRegex);
                if (regex_search(data, smatch, y) == true) {
                    cout << smatch.str() << '\n';
                }
                else {
                    cout << "[REGEX] Not Found" << '\n';
                }
            }
        }
        else {
            return 0;
        }
    }
    catch (exception) {
        return 0;
    }
    cout << "[" << errThrower << "] - Some error happened, screenshot this number and send it to the owner.";
    system("pause >NUL");
}

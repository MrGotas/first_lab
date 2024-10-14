#ifndef MASSIVE_H_INCLUDED
#define MASSIVE_H_INCLUDED

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;
namespace fs = filesystem;

void massive(string file, string actions);
int getParam(string* command, string* value, int* index, string actions);

#endif // MASSIVE_H_INCLUDED

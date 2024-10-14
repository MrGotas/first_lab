#include "libs/massive.h"

struct Massive {
        
};


int getParam(string* command, string* value, int* index, string actions);
int toNum(const string& temporary, int* index);

void massive(string file, string actions){
    string command, value;
    int index;

    if (getParam(&command, &value, &index, actions) == 1){
        cout << "ERROR: incorrect arguments" << endl;
        return;
    }

    
}

int getParam(string* command, string* value, int* index, string actions){
    string temporary = "", firPar = "", secPar = "";
    int countSpase = 0;
    int countParam = 0;
    for (size_t i = 0; actions[i] != '\0'; i++){
        if (actions[i] == ' '){
            countSpase ++;
            if (countSpase >= 3 || actions[i + 1] == ' '){
                return 1;
            }
        }

        if (actions[i] != ' '){
            temporary += actions[i];
        }

        if (countParam == 0 && (countSpase == 1 || actions[i + 1] == '\0')){
            firPar = temporary;
            countParam ++;
            temporary = "";
        }

        if (countParam == 1 && (countSpase == 2 || actions[i + 1] == '\0')){
            secPar = temporary;
            countParam ++;
            temporary = "";
        }
    }

    if (firPar == ""){
        return 1;
    }
    if (firPar != "PUSH" && firPar != "PUSHI" && firPar != "TAKE" && firPar != "DEL" && firPar != "SIZE" && firPar != "GET") {
       return 1;
    }else{
        *command = firPar;
    }

    if (*command == "PUSH"){
        *value = secPar;
    }

    if (*command == "PUSHI"){
        *value = secPar;
        if (toNum(temporary, index) == 1){
            return 1;
        }
    }

    cout << "(firPar)" << *command << "(secPar) " << *value << " (temp) " << *index << endl;////////////////////////////////////////////////
    return 0;
}

int toNum(const string& temporary, int* index) {
    int result = 0;
    int startIndex = 0;

    if (temporary[0] == '-') {
        return 1;
    }

    while (temporary[startIndex] != '\0') {
        char charc = temporary[startIndex];
        if (charc < '0' || charc > '9') {
            return 1;
        }

        result = result * 10 + (charc - '0');
        startIndex++;
    }

    *index = result;
    return 0;
}
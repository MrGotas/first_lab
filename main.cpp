#include "libs/massive.h"
#include "libs/listF.h"
#include "libs/listD.h"
#include "libs/queue.h"
#include "libs/stack.h"
#include "libs/hash_table.h"

int checkActions(string* file, string* actions, string userInput, string* blockName);
void checkAddCreateFile (string filename);

int main (int argc, char* argv[]) {
    string userInput;
    if (argc == 5){
        userInput += argv[2];
        userInput = userInput + " " + argv[4];
    }else if (argc != 1){
        cout << "ERROR: unknown parameters" << endl;
        return 0;
    }

    while (true){
        if (argc == 1){
            getline(cin, userInput);
        }
        argc = 1;

        string blockName, file, actions;
        int error = checkActions (&file, &actions, userInput, &blockName);
        if (error == 1){
            cout << "ERROR: unknown structure" << endl << "----------------------------" << endl;
            continue;
        }else if (error == 2){
            break;
        }

        if (blockName == "M"){
            massive(file, actions);
        }else if (blockName == "LF"){
            listF(file, actions);
        }else if (blockName == "LD"){
            listD(file, actions);
        }else if (blockName == "Q"){
            queue(file, actions);
        }else if (blockName == "S"){
            stack(file, actions);
        }else{
            hash_table(file, actions);
        }
        cout << "----------------------------" << endl;
    }
    return 0;
}

int checkActions(string* file, string* actions, string userInput, string* blockName){
    *file = "files/";
    int space = 0;
    for (size_t i = 0; userInput[i] != '\0'; i++){
        if (userInput[i] == ' ' && space == 0){
            space ++;
            continue;
        }
        if (userInput[i] != ' ' && space == 0){
            *file = *file + userInput[i];
            if (*file == "EXIT"){
                return 2;
            }
            continue;
        }
        if (space == 1){
            if (userInput [i] == 'L'){
                if (userInput[i + 1] == 'F' || userInput[i + 1] == 'D'){
                    *blockName = userInput[i];
                    *blockName += userInput[i + 1];
                    i++;
                    space++;
                    continue;
                }else{
                    return 1;
                }
            }else if (userInput[i] == 'M' || userInput[i] == 'Q' || userInput[i] == 'S' || userInput[i] == 'H'){
                    *blockName = userInput[i];
                    space++;
                    continue;
            }else{
                return 1;
            }
        }
        *actions = *actions + userInput[i];
    }

    checkAddCreateFile (*file);

    return 0;
}

void checkAddCreateFile (string filename){
    if (!fs::exists(filename)) {
        ofstream file(filename);
    }
}
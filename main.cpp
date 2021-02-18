#include<iostream>
#include<fstream>

using namespace std;

int main(void){
    // Getting name of file
    string fileName;
    cout << "Full File Name: ";
    cin >> fileName;
    cout << endl;

    // File being read
    ifstream origin;
    origin.open(fileName);
    if (!origin){
        cout << "Couldn't find " << fileName <<", exiting program." << endl;
        return 1;
    }
    cout << "File read successfully!" << endl;

    // New file being made
    ofstream newFile;
    newFile.open("temp.txt");
    if (!newFile){
        cout << "Couldn't create new file, exiting program." << endl;
        return 1;
    }

    // Getting new word to replace
    string oldWord, newWord;
    cout << "What word do you want to replace in " << fileName << "? ";
    cin >> oldWord;
    
    cout << endl << "What would you like to replace \"" << oldWord << "\" with? ";
    cin >> newWord;

    // Looking for word
    string temp;
    while (origin >> temp){
        if (temp == oldWord){
            temp = newWord;
        }
        // still needs to be worked on
        else if (temp == "\n"){
            temp += "\n\n";
        }

        temp += " ";

        newFile << temp;
    }

    cout << "Word was successfully replaced." << endl;
    return 0;
}
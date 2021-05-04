//
//  caesar.cpp
//
//  Created by HeavyFogNikolay on 05.05.2021.
//

#include <iostream>
#include <fstream>
using namespace std;

// I work with ASCII code.

char shiftSymbol (char symbol, int shift, char minSymbol, char maxSymbol) {
    int allCharacters = (int)(maxSymbol - minSymbol) + 1; // allCharacters is number of the letters in the alphabet
    int currentCodeFromStart = symbol - minSymbol; // i calculate current charecter from the beginning
    int answearCode = ((currentCodeFromStart + shift) % allCharacters + allCharacters) % allCharacters; // Now, i add shift; '% allCharacters' - if shift will be > allCharacters; '+ allCharacters) % allCharacters' - if shift will be < 0
    return answearCode + minSymbol;
}

string code(string str, int shift) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        wchar_t curr = str[i];
        setlocale(LC_ALL, "ru_RU.utf8");
        if (curr >= 'A' && curr <= 'Z') { // You can add alphabet yet
            result += shiftSymbol(curr, shift, 'A', 'Z');
        } else if (curr >= 'a' && curr <= 'z') {
            result += shiftSymbol(curr, shift, 'a', 'z');
        } else if (curr >= '0' && curr <= '9') {
            result += shiftSymbol(curr, shift, '0', '9');
        }
        
    }
    return result;
}

int main() {
    fstream connectFile;
    string path = "WorkFile.txt";
    connectFile.open(path, fstream::in | fstream::out | fstream::app); // '| fstream::app' if you want add a text in to the end of the file
    if (!connectFile.is_open()) { // file check
        cout << "Error! File not found!" << endl;
    } else {
        cout << "File open!" << endl;
    }
    
    string input;
    int shift;
    
    cout << "Enter massage: ";
    getline(cin, input);
    connectFile << "Massage: " << input << endl;
    
    cout << "Enter shift: ";
    cin >> shift;
    connectFile << "Shift: " << shift << endl;
    
    string result = code(input, shift);
    cout << "ENCRYPT: " << result << endl;
    connectFile << "ENCRYPT: " << result << endl;
    
    result = code(result, -1 * shift); // To decrypt it you need to pass a negative shift
    cout << "DECRYPT: " << result << endl;
    connectFile << "DECRYPT: " << result << endl;
    
    connectFile.close();
    return 0;
}

//
//  main.cpp
//  Anagram
//
//  Created at 02.05.2021.
//
//  The task - find anagram (A words which can will be equal via transformation), for example: 'tea' and 'eat'. Input - a pair words. One of the way - it's "sort". We can regularize a words which have the same letters. That's it.

//  Задача - найти в словах анаграмму. На вход - пара слов. Если в словах одинаковые буквы, которые распололжены по-разному, то с помощью сорта мы их упорядочим в одинаковые строчки и все!)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int const numberOfPairs = 2;


int main() {
    string firstWord, secondWord;
    string memory[numberOfPairs];
    
    for (int i = 0; i < numberOfPairs; ++i) {
        cout << "Enter 2 words:\n";
        
        getline(cin, firstWord);
        getline(cin, secondWord);
        
        string sortFirstWord = firstWord;
        string sortSecondWord = secondWord;
        
        sort(sortFirstWord.begin(), sortFirstWord.end());
        sort(sortSecondWord.begin(), sortSecondWord.end());

        if (sortFirstWord == sortSecondWord) {
            memory[i] = "Words is anagrams";
        } else {
            memory[i] = "Words is not anagrams";
        }
        
    }
    
    for (const string &i : memory) {
        cout << i << endl;
    }
    
    return 0;
}

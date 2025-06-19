#include <iostream>
#include <string>

using namespace std;

int main(){
 
   //work1
   int count = 0;
   string word;
   cout << "Enter a sentence: ";
   getline(cin >> ws, word);

   for(int i =0; i<word.length(); i++){
    if(isspace(word[i])){
    count ++;
    }
   }
   cout << "Total White spaces and Tabs: "<< count <<endl;


   //work2
   char character;
   cout << "Enter any character: ";
   cin >> character;
   if(isdigit(character)){
    cout << "Character is digit"<<endl;
   } else if(isalpha(character)){
    cout << "Character is a letter"<<endl;
   }

   // work 3 (word count)
   string word2;
    int spaces = 0;
    int numberOfCharacters = 0;

    cout << "Enter a sentence: ";
    getline(cin >> ws, word2);

    for (int i = 0; i < word2.length(); i++) {
        if (isspace(word2[i])) {
            spaces++;
        } else {
            numberOfCharacters++;  // Only count non-space characters
        }
    }

    cout << "Number of spaces: " << spaces << endl;
    cout << "Number of non-space characters: " << numberOfCharacters << endl;
    return 0;
}
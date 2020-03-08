/* 
File Name: HW10_4.cpp
Description of program: Keep track of words for a dictionary
Course Name: Introduction to Computer Science
Exercise# and Question#: 10, 4
Name: Eli Levin 341318228
Creation date: 22-1-20
Last Modification date: 22-1-20
*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void PrintAll(char **lexicon, int size);
void NewStr(char **&lexicon, char *word, int& size);
void Insert(char **lexicon, char *word, int size);
void DelStr(char **&lexicon, char *word, int& size);
char *SearchStr(char **lexicon, char *word, int size);
void Resize(char **&lexicon, int size, int newSize);
void PrintChar(char **lexicon, char c, int size);

int main()
{ 
    char** lexicon = NULL;
    int size = 0;
    int cmd;
    do
    {
        cout << "enter 0-5:" << endl;
        cin >> cmd;
        cin.ignore(100,'\n');
        char word[80];

        switch (cmd)
        {
            case 0:
                cout << "enter the word:" << endl;
                cin.getline(word, 80);
                NewStr(lexicon, word, size);
                PrintAll(lexicon, size);
                break;

            case 1:
                cout << "enter the word to delete:" << endl;
                cin.getline(word, 80);
                DelStr(lexicon, word, size);
                PrintAll(lexicon, size);
                break;

            case 2:
                cout << "enter the word to search for:" << endl;
                cin.getline(word, 80); 
                char *s;
                s = SearchStr(lexicon, word, size);
                cout << (s == NULL ? "not " : "") << "found" << endl;
                break;

            case 3:
                char c;
                cout << "enter the char:" << endl;
                cin >> c;
                PrintChar(lexicon, c, size);
                break;

            case 4:
                PrintAll(lexicon, size);
                break;
            
            default:
                break;
        }

    } while (cmd != 5);
    
    return 0;
}

void PrintAll(char **lexicon, int size){
    for (int i = 0; i < size; i++){
        cout << lexicon[i] << ' ';
    } 
    cout << endl;  
}

void PrintChar(char **lexicon, char c, int size){
    for (int i = 0; i < size; i++){
        if(c == lexicon[i][0]){
            cout << lexicon[i] << ' ';
        }
    }
    cout << endl;
}

void DelStr(char **&lexicon, char *word, int& size){
    for(int i = 0; i < size; i++){
        if(strcmp(lexicon[i], word) == 0){
            delete[] lexicon[i];
            for(int j = i; j < size-1; j++){
                lexicon[j] = lexicon[j+1];
            }
            //now resize lexicon to one smaller.
            //this is ok because the last pointer now is a repeat
            Resize(lexicon, size, size-1);
            size--;
            break;
        }
    }
}

char *SearchStr(char **lexicon, char *word, int size){
    for (int i = 0; i < size; i++){
        if(strcmp(lexicon[i], word) == 0)
        return lexicon[i];
    } 
    return NULL;
}

void NewStr(char **&lexicon, char *word, int& size){ 
    for (int i = 0; i < size; i++){ //loop through lexicon
        if(strcmp(lexicon[i], word) == 0){
            return;
        }
    }
    Resize(lexicon, size, size+1);
    size++;
    Insert(lexicon, word, size);
}


/*I want a function that will look at lexicon, and a new word, find the correct place for the new word, shift all the pointers (up??) one, and insert the new word there
*/
void Insert(char **lexicon, char *word, int size){
/*
Ask if word is bigger than first word in lexicon, if it is, move on
if it isn't that's your index
*/
int index;
for (int i = 0; i < size; i++){
    if(lexicon[i] == NULL || strcmp(lexicon[i], word) > 0){
        index = i;
        break;
    }
}
//now shift all the pointers in lexicon up by one, until you have reached index
for (int i = size-1; i > index; i--){
    lexicon[i] = lexicon[i-1];
}
//now tell lexicon[index] to point to new array of correct size
lexicon[index] = new char[strlen(word)+1];
// and copy word into your newly allocated array
strncpy((lexicon[index]), word, strlen(word)+1);
}

//make a function that resizes lexicon from size to newSize.
//It will remove pointers from the end of the array if newSize is smaller
// And add NULL pointers at the end if newSize is bigger
void Resize(char **&lexicon, int size, int newSize){
    char **temp = new char*[newSize];
    for (int i = 0; i < size && i < newSize; i++){
        temp[i] = lexicon[i];
    }
    //now delete the lexicon array
    delete[] lexicon;
    if(size > newSize){
       for (int i = newSize; i < size; i++){
            lexicon[i] = NULL; //in order to not delete the arrays that you've copied to temp
        } 
    }
    //if newSize was bigger than size, then fill all the empty pointers with NULL
    if(newSize > size){
        for (int i = size; i < newSize; i++){
            temp[i] = NULL;
        }
    }
    //and set lexicon pointer equal to temp pointer
    lexicon = temp;
}


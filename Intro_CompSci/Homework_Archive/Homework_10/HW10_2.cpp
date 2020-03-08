/* 
File Name: HW10_2.cpp
Description of program: Reverse all the words in a string
Course Name: Introduction to Computer Science
Exercise# and Question#:10, 2
Name: Eli Levin 341318228
Creation date: 21-1-20
Last Modification date:21-1-20
*/
#include <iostream>
#include <cstring>

const int word = 80;

using namespace std;

char *Reverse(const char *str);
void ReverseWord(const char *str, char *reversed, int start, int end);
void PrintString(const char *str);

int main()
{
    char str[word];
    cout << "enter a string: " << endl;
    cin.getline(str, word);

    char *reversed = Reverse(str); 

    cout << "after reverse: ";
    PrintString(reversed);

    //be a good citizen and delete your unused memory
    delete []reversed;

    return 0;

}

char *Reverse(const char *str){

    char *reversed = new char[word];

    for (int i = 0; *(str+i) != '\0'; i++){ // loop until reaching nulltermination
        if(*(str+i) == ' '){ //if it is white space (maybe number also???)
            *(reversed+i) = *(str+i);
        }
        else{ // if it was any other type of character
            int start = i; //remember where the beginning of the word was
            int end;
            for (int j = i;/* *(str+j) != '\0' */; j++, i++){
                if( *(str+j+1)  == ' ' || *(str+j+1)  == '\0'){ // if the next character is whitespace
                    end = j; //then the current character is the last of the word
                    break;
                }
            }

            ReverseWord(str, reversed, start, end);
        }
    }
    return reversed;
}

//this function reads from str and writes to reversed, starting with start and ending with end.
// the reversed word will get printed in reversed in the same location where it came from in str
void ReverseWord(const char *str, char *reversed, int start, int end){
    int length = (end-start)+1;
    for (int i = 0; i < length; i++){ //until end of word   
        *(reversed+start+i) = *(str+end-i);  
    }
}

void PrintString(const char *str){
    for (int i = 0; *(str+i) != 0; i++){
        cout << *(str+i);
    }
    cout << endl;
}



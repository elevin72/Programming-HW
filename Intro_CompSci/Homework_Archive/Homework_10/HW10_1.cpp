/* 
File Name:HW10_1.cpp
Description of program: Encrypt a string that was read in from a file
Course Name: Introduction to Computer Science
Exercise# and Question#: 10, 1
Name: Eli Levin 341318228
Creation date: 20-1-20
Last Modification date: 20-1-20
*/
#include <iostream>
#include <cstring>
#include <fstream>
//#pragma warning (disable:4996) //whats this??
using namespace std;

const int word = 80;

char *Crypto(char *str);
void PrintArray(char *str);

int main()
{ 
    //create file input stream object
    ifstream fin("txt");

    //create array of size word...
    char str[word];
    fin.getline(str, word, '\0'); //and input a string from your object to str
    char *ptr = &str[0]; //now create a pointer to str
    
    char *crypt = Crypto(ptr); // call Crypto and save its pointer

    //print the array that crypt is pointing to
    PrintArray(crypt);

    //be a good citizen and delete the array
    delete []crypt;
    
    return 0;

}

char *Crypto(char *str){
    
    //create new array and pointer pointing to that array

    char *encrypted = new char[word];
   
    for (int i = 0; i <= word && *(str+i) != 0; i++){
        char c = *(str+i);

        //if letter is uppercase
        if(c >= 'A' && c <= 'Z'){
        *(encrypted+i) = 'A'-(c-'Z');
        }

        //if letter is lowercase
        if(c >= 'a' && c <= 'z'){
        *(encrypted+i) = 'a'-(c-'z');
            
        }

        //else letter is special char
        else{
        *(encrypted+i) = c;
        } 
    }

    return encrypted;
}

void PrintArray(char *str){
    cout << endl;
    for (int i = 0; *(str+i) != 0; i++){
        cout << *(str+i);
    }
    cout << endl;
}
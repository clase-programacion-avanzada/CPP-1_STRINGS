// comparing apples with apples
#include <iostream>
//https://stackoverflow.com/questions/9257665/difference-between-string-and-string-h
#include <string.h>

using namespace std;


int main ()
{

    //In the old days of C, strings were simply arrays of characters.
    //The problem with this approach is that you have to keep track of the length of the string yourself.
    //If you forget to do this, you can easily overflow the array, causing your program to crash.

    //char myString[255] = "Hello"; // 255 characters is more than enough for "Hello"
    char myString[255];

    strcpy(myString, "Hello"); // copy "Hello" into myString

    //In this case what is being stored in myString is the characters H, e, l, l, o, and \0.
    //The \0 is called a null terminator, and is how C knows where the end of the string is.

    //The null terminator is why we need to allocate 255 characters for a string that only contains 5 characters.
    cout << "myString value is now: " << myString << endl;

    //if we try to print the string without null terminating it, we get garbage
    cout << "Printing without null terminating it: ";
    for (int i = 0; i < 255; i++)
    {
        cout << myString[i];
    }
    cout << endl;

    //As you may have guessed, this is a very error prone way to work with strings.
    // if we wan to concatenate two strings we need to do this
    char myString2[255] = " World";
    cout << "Concatenating two strings: " << myString << " and" << myString2 << endl;
    strcat(myString, myString2); // myString now contains "Hello World"
    cout << "myString value is now: " << myString << endl;

    //if we want to get the length of a string we need to do this
    int length = 0;
    strlen(myString); // returns 11
    cout << "myString length is: "<< strlen(myString) << endl;

    //if we want to compare two strings we need to do this
    cout << "String comparison result is: " << strcmp(myString, myString2)<< endl; // returns 0 if equal, < 0 if myString comes before myString2, > 0 if myString comes after myString2


    //if we want to copy a string we need to do this
    cout << "Copying a string: " << myString2 << " into " << myString << endl;
    strcpy(myString, myString2); // myString now contains " World"
    cout << "My string value after copying: " << myString << endl;

    //As you can see, working with strings in C is a pain.
    //Fortunately, C++ introduced a new type called std::string that is much more convenient to use.
    
    //std::string is a class that encapsulates a dynamic array of characters.
    //It manages the array's size through an internal counter, 
    // and provides member functions for string manipulation.
    //Because std::string is a class, we can use the . operator to access its member functions.
    //From now on, we will use std::string instead of char arrays to store strings.

    string myString3 = "Hello";

    //if we want to concatenate two strings we need to do this

    string myString4 = " World";
    cout << "Concatenating two strings: " << myString3 << " and" << myString4 << endl;
    myString3 += myString4; // myString now contains "Hello World"

    //if we want to get the length of a string we need to do this
    cout << "myString length is: "<< myString3.length() << endl;

    //if we want to compare two strings we need to do this
    cout << "String comparison result is: " << myString3.compare(myString4)<< endl; // returns 0 if equal, < 0 if myString comes before myString2, > 0 if myString comes after myString2

    //If we want to change the value of a string we can do this
    cout << "Changing the value of a string: " << myString3 << " into " << myString4 << endl;
    myString3 = myString4; // myString now contains " World"

    //We won't need to worry about null terminators or buffer overflows anymore.


    return 0;
}
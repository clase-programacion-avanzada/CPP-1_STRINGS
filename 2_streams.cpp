// Example of streams in C++
#include <iostream>
#include <sstream>

using namespace std;

//In C++, streams are used to perform input and output operations.
//They are a series of bytes that are transferred from the source to the destination.
//For example, from a file to the screen, from a file to a file, from a program to a file, from a program to the screen, etc.
//The source or destination can be a device, file, or memory.
//Streams are used to read and write data to and from the standard input/output devices, files, and memory.




int main () {

    //We already know two types of streams: cin (standard input stream) and cout (standard output stream).
    //cin and cout are part of the iostream library, which is why we need to include it at the beginning of our program.
    // << is the insertion operator, and >> is the extraction operator
    //The insertion operator (<<) is used to write the data to the standard output device.
    cout << "Write a number:" << endl;
    //The extraction operator (>>) is used to read the data from the standard input device.
    int number;
    cin >> number;

    cout << "You entered: " << number << endl;

    //We can also use the stringstream class to treat strings as streams.
    //This is useful to operate on strings in the same way we operate on streams.
    //We can use the stringstream class to treat strings as streams.

    //The stringstream class is used to operate on strings.
    //It is used to read from and write to strings.
    stringstream ss;

    //We can use the insertion operator (<<) to write to the string.
    ss << "Hello World";

    //We can use the extraction operator (>>) to read from the string.
    string myString;
    ss >> myString;

    cout << "The string is: " << myString << endl;

    //We can also use the stringstream class to convert strings to numbers and vice versa.
    //We can use the insertion operator (<<) to write to the string.
    ss << 123;

    //We can use the extraction operator (>>) to read from the string.
    int myNumber;
    ss >> myNumber;

    cout << "The number is: " << myNumber << endl;

    //We can initialize a stringstream with a string.
    stringstream ss2("Hello World");

    //We can use the str() function to get the string from the stringstream.
    cout << "The string is: " << ss2.str() << endl << endl;

    //We can use the str() function to set the string of the stringstream.
    ss2.str("Goodbye World");

    //We can use the str() function to get the string from the stringstream.
    cout << "The string is: " << ss2.str() << endl << endl;

    //Normally, you will see that getline is used in conjunction with the stringstream class, cin, or a file.
    //The getline function is used to read a line from a stream.

    stringstream ss3("Hello World");

    string line;

    //We can use the getline function to read a line from the stringstream.
    getline(ss3, line);

    cout << "The line is: " << line << endl << endl;
    
    //spoiler from workshop, we can use stringstream and getline to split a string into tokens.
    //We cound also use getline with a third parameter to specify the delimiter.
    stringstream ss4("Hello,World");

    string token;

    //We can use the getline function to read a token from the stringstream.
    getline(ss4, token, ',');
    cout << "The token is: " << token << endl << endl;

    //if we use again the getline function, it will read the rest of the string
    getline(ss4, token, ',');
    cout << "The token is: " << token << endl << endl;

    //We can also check if the stringstream has reached the end of the string using eof.
    stringstream ss5("Hello World");

    string word;

    while(!ss5.eof()) {
        getline(ss5, word, ' ');
        cout << "The word is: " << word << endl;
    }
    
    
  return 0;
}

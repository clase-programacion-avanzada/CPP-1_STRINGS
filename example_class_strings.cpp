#include <iostream>

using namespace std;

int main() {
    
    char myString[] = "Hello";

    char myString2[] = {'W', 'o', 'r', 'l', 'd'};

    char* myString3 = "Hello";

    string myString4 = "javeriana";
    string myString5("javeriana");

    string dogCat = "dog:cat";

    //Using find

    int pos = dogCat.find(":");

    cout<< "Position of : in dogCat is: " << pos << endl;

    //Using substr

    string dog = dogCat.substr(pos + 1);


    cout<< "substring of dog:cat starting from position " << pos + 1 << " is: " << dog << endl;

    //using length

    cout<< "Length of dogCat is: " << dogCat.length() << endl;

    //Strings can be looped through

    for (int i = 0; i < dogCat.length(); i++)
    {
        cout << dogCat[i] << endl;
    }

    //In c style strings we need to use the strlen function to get the length of a string

    char myString6[] = "Hello";

    cout << "Length of myString6 is: " << strlen(myString6) << endl;

    //looping through a c style string

    for (int i = 0; i < strlen(myString6); i++)
    {
        cout << myString6[i] << endl;
    }

    //If I dont want to use strlen I can use the null terminator to loop through the string

    for (int i = 0; myString6[i] != '\0'; i++)
    {
        cout << myString6[i] << endl;
    }

    //String comparison

    string myString7 = "Hello";
    string myString8 = "Hello";

    if (myString7 == myString8)
    {
        cout << "myString7 is equal to myString8" << endl;
    }

    //Using compare

    if (myString7.compare(myString8) == 0)
    {
        cout << "myString7 is equal to myString8" << endl;
    }

    string str1 = "green apple";
  //string str1 ("green apple");
    string str2 ("red apple");
        
    if (str1.compare(str2) != 0)
        cout << str1 << " is not " << str2 << '\n';
        
    if (str1.compare(6,5,"apple") == 0)
        cout << "still, " << str1 << " is an apple\n";

    if (str2.compare(str2.size()-5,5,"apple") == 0)
        cout << "and " << str2 << " is also an apple\n";
        
    if (str1.compare(6,5,str2,4,5) == 0)
        cout << "therefore, both are apples\n";
    
    //Concatenating strings

    string myString9 = "Hello";

    string myString10 = " World";

    string myString11 = myString9 + myString10;

    //C style string concatenation

    char myString12[255] = "Hello";

    char myString13[255] = " World";

    strcat(myString12, myString13);

    cout << "myString12 value is now: " + myString11 << endl;

    



    return 0;
}
// comparing apples with apples
#include <iostream>
//https://stackoverflow.com/questions/9257665/difference-between-string-and-string-h
#include <string.h>

using namespace std;

int main () {

      // Take any string
    string s = "dog:cat";
 
    // Find position of ':' using find()
    /*
        int find(const string& str, size_t pos = 0) const;
            const string& str: the string to be searched
            size_t pos: the position to start the search
            return: the position of the first character of the first match
                    or string::npos if no match is found
    */
    int pos = s.find(":");
    
    /*
        string substr(size_t pos = 0, size_t len = npos) const;
            size_t pos: the position of the first character to be returned
            size_t len: the number of characters to be returned
            return: the string from the position pos to the position pos+len
    */
    // Copy substring after pos
    string sub = s.substr(pos + 1);
 
    // prints the result
    cout << "String is: " << sub<<endl;
    cout << endl;
 
    string s1 = "Javeriana";
 
    // Copy three characters of s1 (starting
    // from position 1)
    string r = s1.substr(0, 4);
 
    // prints the result
    cout << "String is: " << r << endl;
    
    /*We can find length of string in three different ways: */
    cout << "String length using length() is: " << s1.length() << endl;
    cout << "String length using size() is: " << s1.size() << endl;
    cout << "String length using strlen is: " << strlen(s1.c_str())<< endl;
    cout << endl;
    /*We can also get a particular character inside of a string treating it as an array*/
    s1[s1.size()-1];
    cout << "Character at position 1 is: " << s1[1] << endl;
    cout << "Character at position 2 is: " << s1[2] << endl;
    cout << "Character at position 3 is: " << s1[3] << endl;
    cout << "Character at position 4 is: " << s1[4] << endl;
    cout << endl;

    /*or using the function .at*/
    cout << "Character at position 1 is: " << s1.at(1) << endl;
    cout << "Character at position 2 is: " << s1.at(2) << endl;
    cout << "Character at position 3 is: " << s1.at(3) << endl;
    cout << "Character at position 4 is: " << s1.at(4) << endl;

   
  string str1 = "green apple";
  //string str1 ("green apple");
  string str2 ("red apple");
    /*  parameters of compare function
        int compare (const string& str)
            const string& str: the string to be compared
            return: 0 if the strings are equal
                    1 if the first string is greater than the second
                    -1 if the first string is less than the second
    */
  if (str1.compare(str2) != 0)
    cout << str1 << " is not " << str2 << '\n';
    /*
    int compare (size_t pos, size_t len, const string& str) const;
            size_t pos: the position of the first character to be compared
            size_t len: the number of characters to be compared
            const string& str: the string to be compared
            return: 0 if the strings are equal
                    1 if the first string is greater than the second
                    -1 if the first string is less than the second
    
    */
  if (str1.compare(6,5,"apple") == 0)
    cout << "still, " << str1 << " is an apple\n";

  if (str2.compare(str2.size()-5,5,"apple") == 0)
    cout << "and " << str2 << " is also an apple\n";
    /*
     int compare (size_t pos, size_t len, const string& str,
             size_t subpos, size_t sublen = npos) const;    
            size_t pos: the position of the first character to be compared
            size_t len: the number of characters to be compared
            const string& str: the string to be compared
            size_t subpos: the position of the first character to be compared
            size_t sublen: the number of characters to be compared
            return: 0 if the strings are equal
                    1 if the first string is greater than the second
                    -1 if the first string is less than the second
    */
  if (str1.compare(6,5,str2,4,5) == 0)
    cout << "therefore, both are apples\n";

  /*Also, we can concatenate strings using the operator '+' */
  string token1 = "Hello";
  string token2 = "World";

  string result = token1 + " " + token2;
  cout << result <<endl;
 
  /*How can I know if a string is empty?*/
  string void_string = "";

  if (void_string.empty()) {
    cout << "String is empty" << endl;
  }

  return 0;
}
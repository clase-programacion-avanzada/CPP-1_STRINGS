#include <iostream>
#include <cstring>
#include <string>


int main() {
    
    /*=====================Operaciones básicas========================*/

    /*Acceso a caracteres*/
    std::string text = "Hola";

    // Acceso con operator[]
    char c1 = text[0];        // 'H' (sin verificación de límites)
    text[0] = 'h';           // texto ahora es "hola"

    // Acceso con at() (con verificación de límites)
    char c2 = text.at(1);    // 'o' (lanza excepción si índice fuera de rango)

    // Primer y último carácter
    char first = text.front();  // 'h' (C++11)
    char last = text.back();    // 'a' (C++11)

    /*Información de la cadena*/
    std::string str = "Hola Mundo";

    size_t length = str.length();    // 10 (también str.size())
    bool empty = str.empty();          // false
    size_t capacity = str.capacity(); // Capacidad actual del buffer interno

    // Reservar espacio (optimización)
    str.reserve(100);  // Pre-asigna espacio para al menos 100 caracteres

    /*============Operaciones de modificación==========================*/

    /*Concatenación*/
    std::string s1 = "Hola";
    std::string s2 = "Mundo";

    // Operador +
    std::string s3 = s1 + " " + s2;        // "Hola Mundo"

    // Operador +=
    s1 += " ";                             // s1 = "Hola "
    s1 += s2;                              // s1 = "Hola Mundo"

    // Método append()
    std::string s4 = "Hola";
    s4.append(" ").append(s2);            // "Hola Mundo"
    s4.append(3, '!');                    // "Hola Mundo!!!"
    s4.append(s2, 0, 3);                  // "Hola Mundo!!!Mun" (append substring)
    

    /*===============Subcadenas & comparaciones============*/

    // Subcadenas
    std::string str = "Hola Mundo Hermoso";

    // substr() - Extraer subcadena
    std::string sub1 = str.substr(5);        // "Mundo Hermoso"
    std::string sub2 = str.substr(5, 5);     // "Mundo"

    // Comparaciones
    std::string s1 = "abc";
    std::string s2 = "abd";

    bool equal = (s1 == s2);                 // false
    bool less = (s1 < s2);                  // true (comparación lexicográfica)
    int comp = s1.compare(s2);               // -1 (s1 < s2)
    int comp2 = s1.compare(0, 2, s2, 0, 2); // 0 (primeros 2 chars son iguales)
    
    /*=============Conversiones============*/


    // Conversiones numéricas (C++11)
    std::string num_str = "123";
    int num = std::stoi(num_str);           // 123
    long lnum = std::stol("123456789");     // 123456789
    double dnum = std::stod("123.45");      // 123.45

    // Números a string
    std::string str1 = std::to_string(42);    // "42"
    std::string str2 = std::to_string(3.14);  // "3.140000"

   
    // Conversión de string a c_string
    std::string str = "Hola Mundo";
    const char* c_str = str.c_str();        // "Hola Mundo" (const char*)
    
    return 0;
}
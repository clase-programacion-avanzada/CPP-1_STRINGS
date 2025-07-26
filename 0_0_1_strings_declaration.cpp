#include <iostream>
#include <string>

int main() {

    // 1. Constructor por defecto (cadena vacía)
    std::string str1;                       // ""

    // 2. Desde un literal de cadena
    std::string str2("Hola");              // "Hola"
    std::string str3 = "Mundo";            // "Mundo"

    // 3. Constructor de copia
    std::string str4(str2);                // Copia de str2: "Hola"
    std::string str5 = str3;               // Copia de str3: "Mundo"

    // 4. Desde un C-string
    const char* cstr = "C-string";
    std::string str6(cstr);                // "C-string"

    // 5. Constructor con repetición
    std::string str7(5, 'A');              // "AAAAA"

    // 6. Subcadena de otro string
    std::string str8(str2, 1, 3);          // "ola" (desde posición 1, 3 caracteres)

    // 7. Desde iteradores (No lo veremos en este curso)
    std::string str9(str2.begin(), str2.end());  // "Hola"
    
    return 0;
}
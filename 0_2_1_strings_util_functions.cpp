#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

std::string trim(const std::string& str) {
    
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

/* 
*   Función para dividir una cadena en tokens usando un delimitador 
*   En este caso, tokens es un arreglo de cadenas y token_count es una referencia para contar los tokens encontrados.
*   Limita el número de tokens a 20 y cada token a 20 caracteres.
*   Retorna el número de tokens encontrados & modifica el arreglo de tokens.
*/
size_t split(std::string str, char delim, char tokens[20][20]) {

    size_t token_count = 0;

    std::stringstream ss(str);
    std::string token;
    token_count = 0;

    while (std::getline(ss, token, delim)) {
        if (!token.empty()) {
            strcpy(tokens[token_count++], token.c_str());
        }
    }

    return token_count;
}

int main() {

    // TRIM
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Cstring%3E%0A%23include%20%3Csstream%3E%0A%0Astd%3A%3Astring%20trim%28const%20std%3A%3Astring%26%20str%29%20%7B%0A%20%20%20%20%0A%20%20%20%20size_t%20first%20%3D%20str.find_first_not_of%28%22%20%5Ct%5Cn%5Cr%22%29%3B%0A%20%20%20%20if%20%28first%20%3D%3D%20std%3A%3Astring%3A%3Anpos%29%20return%20%22%22%3B%0A%20%20%20%20%0A%20%20%20%20size_t%20last%20%3D%20str.find_last_not_of%28%22%20%5Ct%5Cn%5Cr%22%29%3B%0A%20%20%20%20return%20str.substr%28first,%20%28last%20-%20first%20%2B%201%29%29%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20%20%20std%3A%3Astring%20text%20%3D%20%22%20%20Hola%20Mundo!%20%20%22%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20original%3A%20%5C%22%22%20%3C%3C%20text%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%20%20%20%20std%3A%3Astring%20trimmed%20%3D%20trim%28text%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20despu%C3%A9s%20de%20trim%3A%20%5C%22%22%20%3C%3C%20trimmed%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%20%20%20%20%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    std::string text = "  Hola Mundo!  ";
    std::cout << "Texto original: \"" << text << "\"\n";
    std::string trimmed = trim(text);
    std::cout << "Texto después de trim: \"" << trimmed << "\"\n";
    
    // Split
    std::string to_split = "C; C++; Python; Java; JavaScript";
    char tokens[20][20];
    size_t count = split(to_split, ';', tokens);

    std::cout << "Número de tokens encontrados: " << count << "\n";
    for (size_t i = 0; i < count; ++i) {
        std::cout << "Token " << i + 1 << ": " << tokens[i] << "\n";
    }


    return 0;
}
#include <iostream>
#include <cstring>

// https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20saludo%5B%5D%20%3D%20%22Hola%22%3B%20%0A%20%20%20%20char%20str1%5B%5D%20%3D%20%22Hola%20Mundo%22%3B%0A%20%20%20%20char%20str2%5B20%5D%20%3D%20%22Hola%22%3B%0A%20%20%20%20char%20str3%5B%5D%20%3D%20%7B'H',%20'o',%20'l',%20'a',%20'%5C0'%7D%3B%0A%20%20%20%20const%20char*%20str4%20%3D%20%22Hola%20Mundo%22%3B%20%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%20%20%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
int main() {

    // Diferentes formas de declarar C-strings

    char greeting[] = "Hola";  // En memoria: ['H']['o']['l']['a']['\0']

    // 1. Inicialización con literal de cadena
    char str1[] = "Hola Mundo";// El compilador calcula el tamaño automáticamente (11 chars)

    // 2. Especificando el tamaño explícitamente
    char str2[20] = "Hola";// Array de 20 chars, solo los primeros 5 se usan

    // 3. Inicialización carácter por carácter
    char str3[] = {'H', 'o', 'l', 'a', '\0'};// IMPORTANTE: incluir '\0' manualmente

    // 4. Puntero a literal de cadena (SOLO LECTURA)
    const char* str4 = "Hola Mundo";  // Apunta a memoria de solo lectura

    return 0;
}
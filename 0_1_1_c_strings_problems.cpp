#include <iostream>
#include <cstring>


int main() {


    //Buffer overflow
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20%20%20char%20buffer%5B10%5D%3B%0A%20%20%20%20strcpy%28buffer,%20%22Esta%20cadena%20es%20demasiado%20larga%22%29%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=2&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char buffer[10];
    strcpy(buffer, "Esta cadena es demasiado larga");  // ¡PELIGRO! Sobrescribe memoria

    // Olvidar el caracter nulo
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20char%20str%5B5%5D%3B%0A%20%20str%5B0%5D%20%3D%20'H'%3B%20str%5B1%5D%20%3D%20'o'%3B%20str%5B2%5D%20%3D%20'l'%3B%20str%5B3%5D%20%3D%20'a'%3B%0A%20%20//%20%C2%A1ERROR!%20Falta%20str%5B4%5D%20%3D%20'%5C0'%0A%20%20int%20length%20%3D%20strlen%28str%29%3B%0A%20%20std%3A%3Acout%20%3C%3C%20length%3B//puede%20devolver%20cualquier%20valor%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char str[5];
    str[0] = 'H'; str[1] = 'o'; str[2] = 'l'; str[3] = 'a';
    // ¡ERROR! Falta str[4] = '\0'
    strlen(str); //puede devolver cualquier valor
    std::cout << "Longitud de str: " << strlen(str) << std::endl; // Comportamiento indefinido

    // Modificar literales de cadena
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20char*%20str%20%3D%20%22Hola%22%3B%0A%20%20str%5B0%5D%20%3D%20'h'%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=2&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char* str = "Hola";  // ¡ADVERTENCIA! Debería ser const char*
    str[0] = 'h';        // ¡COMPORTAMIENTO INDEFINIDO! Intento de modificar memoria de solo lectura
    
    return 0;
}
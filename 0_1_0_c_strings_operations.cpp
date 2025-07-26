#include <iostream>
#include <cstring>
#include <cstdlib> // Para atoi, atof
#include <cstdio> // Para snprintf
#include <cerrno> // Para errno

// Conversión manual de entero a string
void int_to_string(int num, char* str, size_t tam) {
    snprintf(str, tam, "%d", num);
}

// O implementación manual completa
void int_to_string_manual(int num, char* str) {
    char temp[20];
    int i = 0;
    bool negativo = false;
    
    if (num < 0) {
        negativo = true;
        num = -num;
    }
    
    // Generar dígitos en reversa
    do {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    } while (num > 0);
    
    // Agregar signo si es necesario
    int j = 0;
    if (negativo) {
        str[j++] = '-';
    }
    
    // Copiar en orden correcto
    while (i > 0) {
        str[j++] = temp[--i];
    }
    str[j] = '\0';
}


// Comparación manual de subcadenas
bool compare_substrings(const char* s1, size_t pos1, 
                        const char* s2, size_t pos2, size_t len) {
    return strncmp(s1 + pos1, s2 + pos2, len) == 0;
}

// Concatenación manual más segura
    void safe_concatenate(char* destination, size_t dest_size, const char* source) {
        size_t dest_length = strlen(destination);
        size_t source_length = strlen(source);
        
        if (dest_length + source_length < dest_size) {
            strcat(destination, source);
        } else {
            // Error: no hay espacio suficiente
            // Copiar lo que se pueda
            size_t space = dest_size - dest_length - 1;
            strncat(destination, source, space);
            destination[dest_size - 1] = '\0';  // Asegurar terminación
        }
    }

void substr(const char* origen, char* destination, size_t start, size_t length) {
        size_t origen_length = strlen(origen);
        
        if (start >= origen_length) {
            destination[0] = '\0';
            return;
        }
        
        size_t to_copy = length;
        if (start + length > origen_length) {
            to_copy = origen_length - start;
        }
        
        strncpy(destination, origen + start, to_copy);
        destination[to_copy] = '\0';
}

int main() {
    
    /*=====================Operaciones básicas========================*/

    /*Acceso a caracteres*/

    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20char%20texto%5B%5D%20%3D%20%22Hola%22%3B%0A%0A%20%20char%20c1%20%3D%20texto%5B0%5D%3B%20%0A%20%20texto%5B0%5D%20%3D%20'h'%3B%20%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char text[] = "Hola";

    // Acceso directo (sin verificación de límites)
    char c1 = text[0];        // 'H'
    text[0] = 'h';           // texto ahora es "hola"

    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20char%20texto%5B%5D%20%3D%20%22Hola%22%3B%0A%0A%20%20size_t%20indice%20%3D%2010%3B%0A%20%20if%20%28indice%20%3C%20strlen%28texto%29%29%20%7B%0A%20%20%20%20%20%20char%20c%20%3D%20texto%5Bindice%5D%3B%0A%20%20%7D%20else%20%7B%0A%20%20%20%20%20%20//%20Error%3A%20%C3%ADndice%20fuera%20de%20rango%0A%20%20%7D%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=3&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    // NO hay método at() con verificación
    // Debes verificar manualmente
    size_t index = 10;
    if (index < strlen(text)) {
        char c = text[index];
    } else {
        // Error: índice fuera de rango
    }


    // Primer y último carácter (manual)
    char first = text[0];
    char last = text[strlen(text) - 1];  // ¡Cuidado si strlen es 0!

    /*Información de la cadena*/
    //https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0Aint%20main%28%29%20%7B%0A%20%20char%20str%5B%5D%20%3D%20%22Hola%20Mundo%22%3B%0A%20%20char%20vacio%5B%5D%20%3D%20%22%22%3B%0A%0A%20%20size_t%20longitud%20%3D%20strlen%28str%29%3B%0A%0A%20%20bool%20esta_vacia%20%3D%20%28strlen%28vacio%29%20%3D%3D%200%29%3B%0A%20%20bool%20vacia2%20%3D%20%28vacio%5B0%5D%20%3D%3D%20'%5C0'%29%3B%0A%0A%20%20size_t%20tamano_array%20%3D%20sizeof%28str%29%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=7&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char str[] = "Hola Mundo";
    char empty[] = "";

    // Longitud (sin incluir '\0')
    size_t length = strlen(str);           // 10

    // Verificar si está vacía
    bool is_empty = (strlen(empty) == 0);  // true
    // O más eficiente:
    bool empty2 = (empty[0] == '\0');        // true

    // Tamaño del array (incluyendo '\0')
    size_t array_size = sizeof(str);       // 11

    // NO hay concepto de capacidad dinámica
    // El tamaño es fijo una vez declarado



    /*============Operaciones de modificación==========================*/

    /*Concatenación*/
    //https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0A%0A%0Aint%20main%28%29%20%7B%0A%0A%20%20char%20s1%5B100%5D%20%3D%20%22Hola%22%3B%0A%20%20char%20s2%5B%5D%20%3D%20%22Mundo%22%3B%0A%0A%20%20strcat%28s1,%20%22%20%22%29%3B%0A%20%20strcat%28s1,%20s2%29%3B%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=5&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    // PELIGRO: Debes asegurar que el buffer destino sea suficientemente grande

    char s1[100] = "Hola";  // Buffer con espacio suficiente
    char s2[] = "Mundo";

    // strcat() - Concatenar
    strcat(s1, " ");        // s1 = "Hola "
    strcat(s1, s2);         // s1 = "Hola Mundo"

    // strncat() - Concatenar con límite
    char s3[20] = "Hola";
    strncat(s3, " Mundo Largo", 10);  // Concatena máximo 10 caracteres

    

    //https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20char%20s1%5B100%5D%20%3D%20%22Hola%22%3B%0A%20%20char%20s2%5B%5D%20%3D%20%22Mundo%22%3B%0A%20%20char%20resultado%5B200%5D%3D%7B%7D%3B%0A%20%20sprintf%28resultado,%20%22%25s%20%25s%20%25d%22,%20%22Hola%22,%20%22Mundo%22,%202024%29%3B%0A%0A%20%20snprintf%28resultado,%20sizeof%28resultado%29,%20%22%25s%20%25s%22,%20s1,%20s2%29%3B%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=6&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    // sprintf() para concatenación compleja
    char result[200]={};
    sprintf(result, "%s %s %d", "Hola", "Mundo", 2024);
    // Más seguro: snprintf()
    snprintf(result, sizeof(result), "%s %s", s1, s2);

    /*===============Subcadenas & comparaciones============*/

    // Extraer subcadena (no hay función estándar)
    // Ejemplo de substr()
    //https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0Avoid%20substr%28const%20char*%20origen,%20char*%20destino,%20size_t%20inicio,%20size_t%20longitud%29%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20char%20ejemplo_sub%5B%5D%20%3D%20%22Hola%20Mundo%22%3B%0A%20%20char%20sub%5B20%5D%3B%0A%20%20substr%28ejemplo_sub,%20sub,%205,%205%29%3B%20%20//%20sub%20%3D%20%22Mundo%22%0A%20%20return%200%3B%0A%7D%0A%0Avoid%20substr%28const%20char*%20origen,%20char*%20destino,%20size_t%20inicio,%20size_t%20longitud%29%20%7B%0A%20%20%20%20%20%20%20%20size_t%20len_origen%20%3D%20strlen%28origen%29%3B%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20if%20%28inicio%20%3E%3D%20len_origen%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20destino%5B0%5D%20%3D%20'%5C0'%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20size_t%20copiar%20%3D%20longitud%3B%0A%20%20%20%20%20%20%20%20if%20%28inicio%20%2B%20longitud%20%3E%20len_origen%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20copiar%20%3D%20len_origen%20-%20inicio%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20strncpy%28destino,%20origen%20%2B%20inicio,%20copiar%29%3B%0A%20%20%20%20%20%20%20%20destino%5Bcopiar%5D%20%3D%20'%5C0'%3B%0A%7D&cumulative=false&curInstr=10&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char example_sub[] = "Hola Mundo";
    char sub[20];
    substr(example_sub, sub, 5, 5);  // sub = "Mundo"


    // Comparaciones
    //https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0Aint%20main%28%29%20%7B%0A%20%20char%20s1%5B%5D%20%3D%20%22abc%22%3B%0A%20%20char%20s2%5B%5D%20%3D%20%22abd%22%3B%0A%0A%20%20int%20comp%20%3D%20strcmp%28s1,%20s2%29%3B%0A%20%20bool%20iguales%20%3D%20%28strcmp%28s1,%20s2%29%20%3D%3D%200%29%3B%0A%0A%20%20int%20comp2%20%3D%20strncmp%28s1,%20s2,%202%29%3B%20%0A%20%20%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char s1[] = "abc";
    char s2[] = "abd";

    // strcmp() - Comparación completa
    int comp = strcmp(s1, s2);      // -1 (s1 < s2)
    bool equals = (strcmp(s1, s2) == 0);

    // strncmp() - Comparar primeros n caracteres
    int comp2 = strncmp(s1, s2, 2); // 0 (primeros 2 son iguales)

    /*=============Conversiones============*/

    
    // String a números
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0Aint%20main%28%29%20%7B%0A%20%20%0A%20%20char%20num_str%5B%5D%20%3D%20%22123%22%3B%0A%20%20%20%20%20%20%0A%20%20int%20num1%20%3D%20atoi%28num_str%29%3B%0A%20%20int%20num2%20%3D%20atoi%28%22abc%22%29%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&curInstr=4&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char num_str[] = "123";
    
    // atoi() - Simple pero insegura (no detecta errores)
    int num1 = atoi(num_str);                   // 123
    int num2 = atoi("abc");                     // 0 (sin indicación de error)
    
    // strtod() - Para números flotantes
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0Aint%20main%28%29%20%7B%0A%20%20%0A%0A%20%20char*%20endptr%3B%0A%20%20double%20num4%20%3D%20strtod%28%22123.45%22,%20%26endptr%29%3B%0A%20%20%0A%20%20double%20num5%20%3D%20strtod%28%223.1415%20otro%20texto%22,%20%26endptr%29%3B%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char* endptr;
    double num4 = strtod("123.45", &endptr);

    double num5 = strtod("3.1415 otro texto", &endptr); // num5 = 3.1415, endptr apunta a " otro texto"
    std::cout << "Número convertido: " << num5 << ", resto: '" << endptr << "'" << std::endl;

    // Números a string
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%20%20%0A%0Aint%20main%28%29%20%7B%0A%20%20%0A%0A%20%20char%20buffer%5B50%5D%3B%0A%0A%20%20sprintf%28buffer,%20%22%25d%22,%2042%29%3B%0A%0A%20%20snprintf%28buffer,%20sizeof%28buffer%29,%20%22%25.2f%22,%203.14159%29%3B%20//%20%223.14%22%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char buffer[50];

    // sprintf() - Simple pero peligrosa (buffer overflow)
    sprintf(buffer, "%d", 42);                  // "42"

    // snprintf() - Segura con límite de tamaño
    snprintf(buffer, sizeof(buffer), "%.2f", 3.14159); // "3.14"

    // Conversión de c_string a string
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Cstring%3E%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20//%20Conversi%C3%B3n%20de%20c_string%20a%20string%0A%20%20%20%20%0A%20%20%20%20char%20s3%5B%5D%20%3D%20%22Texto%20de%20ejemplo%22%3B%0A%20%20%20%20std%3A%3Astring%20str3%20%3D%20s3%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char s3[] = "Texto de ejemplo";
    std::string str3 = s3;

    return 0;
}
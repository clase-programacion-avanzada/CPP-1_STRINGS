// Operaciones con cadenas estilo C - Comparación de enfoques heredados
#include <iostream>
#include <string.h>  // Para funciones de cadenas C: strlen, strcpy, strcat, strcmp, strstr, strchr
#include <cstdio>    // Para sprintf

using namespace std;

int main () {
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Ausing%20namespace%20std%3B%0A%0Aint%20main%28%29%20%7B%0A%20%20%0A%20%20%20%20%0A%20%20%20%20char%20s%5B20%5D%20%3D%20%22dog%3Acat%22%3B%20%20%0A%20%20%20%20char*%20pos_ptr%20%3D%20strchr%28s,%20'%3A'%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28pos_ptr%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20int%20pos%20%3D%20pos_ptr%20-%20s%3B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Position%20of%20'%3A'%20is%3A%20%22%20%3C%3C%20pos%20%3C%3C%20endl%3B%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20char%20sub%5B20%5D%3B%0A%20%20%20%20%20%20%20%20strcpy%28sub,%20pos_ptr%20%2B%201%29%3B%0A%20%20%20%20%20%20%20%20%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Substring%20is%3A%20%22%20%3C%3C%20sub%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%20%20%20%20cout%20%3C%3C%20endl%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    // Las cadenas estilo C son arreglos de caracteres terminados por el carácter nulo '\0'
    // A diferencia de las cadenas de C++, necesitamos manejar la memoria y especificar tamaños de búfer
    
    // Tomar una cadena C (arreglo de caracteres)
    char s[20] = "dog:cat";  // Arreglo de tamaño fijo, debe ser lo suficientemente grande
 
    // Encontrar posición de ':' usando strchr()
    /*
        char* strchr(const char* str, int character);
            const char* str: la cadena C a buscar
            int character: el carácter a encontrar (como int, pero típicamente un char)
            return: puntero a la primera ocurrencia del carácter, o NULL si no se encuentra
    */
    char* pos_ptr = strchr(s, ':');
    
    if (pos_ptr != NULL) {
        // Calcular posición restando la dirección base
        int pos = pos_ptr - s;
        cout << "Position of ':' is: " << pos << endl;
        
        // Copiar subcadena después de la posición (enfoque manual)
        char sub[20];  // Debe declarar tamaño de búfer fijo
        strcpy(sub, pos_ptr + 1);  // Copiar desde posición después de ':'
        
        cout << "Substring is: " << sub << endl;
    }
    cout << endl;
    
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Ausing%20namespace%20std%3B%0Aint%20main%28%29%20%7B%0A%20%20char%20s1%5B20%5D%20%3D%20%22Javeriana%22%3B%0A%20%0A%20%20%20%20%0A%20%20%20%20char%20r%5B5%5D%3B%0A%20%20%20%20strncpy%28r,%20s1,%204%29%3B%0A%20%20%20%20r%5B4%5D%20%3D%20'%5C0'%3B%20%0A%20%20%20%20cout%20%3C%3C%20%22Substring%20is%3A%20%22%20%3C%3C%20r%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%20%20%0A%20%20%20%20cout%20%3C%3C%20%22String%20length%20using%20strlen%28%29%20is%3A%20%22%20%3C%3C%20strlen%28s1%29%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%20%20%0A%20%20%20%20cout%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%0A%20%20%20%20cout%20%3C%3C%20%22Character%20at%20position%201%20is%3A%20%22%20%3C%3C%20s1%5B1%5D%20%3C%3C%20endl%3B%0A%20%20%20%20cout%20%3C%3C%20%22Character%20at%20position%202%20is%3A%20%22%20%3C%3C%20s1%5B2%5D%20%3C%3C%20endl%3B%0A%20%20%20%20cout%20%3C%3C%20%22Character%20at%20position%203%20is%3A%20%22%20%3C%3C%20s1%5B3%5D%20%3C%3C%20endl%3B%0A%20%20%20%20cout%20%3C%3C%20%22Character%20at%20position%204%20is%3A%20%22%20%3C%3C%20s1%5B4%5D%20%3C%3C%20endl%3B%0A%20%20%20%20cout%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char s1[20] = "Javeriana";
 
    // Copiar los primeros 4 caracteres (no hay equivalente directo a substr)
    char r[5];  // Necesita espacio para 4 caracteres + terminador nulo
    strncpy(r, s1, 4);  // Copiar 4 caracteres
    r[4] = '\0';        // ¡Debe agregar manualmente el terminador nulo!
 
    cout << "Substring is: " << r << endl;
    
    /* Longitud de cadena C usando strlen() */
    cout << "String length using strlen() is: " << strlen(s1) << endl;
    
    // No hay método size() para cadenas C - strlen() es la única forma
    // strlen() cuenta caracteres hasta que encuentra '\0'
    cout << endl;
    
    /* Acceder a caracteres individuales (igual que las cadenas de C++) */
    cout << "Character at position 1 is: " << s1[1] << endl;
    cout << "Character at position 2 is: " << s1[2] << endl;
    cout << "Character at position 3 is: " << s1[3] << endl;
    cout << "Character at position 4 is: " << s1[4] << endl;
    cout << endl;

    // No hay método .at() para cadenas C - solo indexación de arreglo disponible
    // Las cadenas C no tienen verificación de límites como C++ string.at()

    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Ausing%20namespace%20std%3B%0Aint%20main%28%29%20%7B%0A%20%20%0A%20%20%20%20char%20str1%5B20%5D%20%3D%20%22green%20apple%22%3B%0A%20%20%20%20char%20str2%5B20%5D%20%3D%20%22red%20apple%22%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28strcmp%28str1,%20str2%29%20!%3D%200%29%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20str1%20%3C%3C%20%22%20is%20not%20%22%20%3C%3C%20str2%20%3C%3C%20'%5Cn'%3B%0A%0A%20%20%20%20if%20%28strncmp%28str1%20%2B%206,%20%22apple%22,%205%29%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22still,%20%22%20%3C%3C%20str1%20%3C%3C%20%22%20is%20an%20apple%5Cn%22%3B%0A%0A%20%20%0A%20%20%20%20int%20len%20%3D%20strlen%28str2%29%3B%0A%20%20%20%20if%20%28strncmp%28str2%20%2B%20len%20-%205,%20%22apple%22,%205%29%20%3D%3D%200%29%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22and%20%22%20%3C%3C%20str2%20%3C%3C%20%22%20is%20also%20an%20apple%5Cn%22%3B%0A%0A%0A%20%20%20%20if%20%28strncmp%28str1%20%2B%206,%20str2%20%2B%204,%205%29%20%3D%3D%200%29%20%20%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22therefore,%20both%20are%20apples%5Cn%22%3B%0A%0A%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    // Comparación de cadenas usando strcmp()
    char str1[20] = "green apple";
    char str2[20] = "red apple";
    
    /*  
        int strcmp(const char* str1, const char* str2)
            const char* str1: primera cadena a comparar
            const char* str2: segunda cadena a comparar
            return: 0 si las cadenas son iguales
                   <0 si str1 es lexicográficamente menor que str2
                   >0 si str1 es lexicográficamente mayor que str2
    */
    if (strcmp(str1, str2) != 0)
        cout << str1 << " is not " << str2 << '\n';

    // Comparación parcial de cadenas usando strncmp()
    /*
        int strncmp(const char* str1, const char* str2, size_t num)
            const char* str1: primera cadena a comparar
            const char* str2: segunda cadena a comparar  
            size_t num: número máximo de caracteres a comparar
            return: igual que strcmp pero solo para los primeros 'num' caracteres
    */
    if (strncmp(str1 + 6, "apple", 5) == 0)  // Comparar desde posición 6
        cout << "still, " << str1 << " is an apple\n";

    // Comparar últimos 5 caracteres de str2 con "apple"
    int len = strlen(str2);
    if (strncmp(str2 + len - 5, "apple", 5) == 0)
        cout << "and " << str2 << " is also an apple\n";

    // Comparar subcadenas de ambas cadenas
    if (strncmp(str1 + 6, str2 + 4, 5) == 0)  // Comparar 5 chars empezando en pos 6 y 4
        cout << "therefore, both are apples\n";

    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Ausing%20namespace%20std%3B%0Aint%20main%28%29%20%7B%0A%20%20%20%0A%20%20%20%20char%20token1%5B10%5D%20%3D%20%22Hello%22%3B%0A%20%20%20%20char%20token2%5B10%5D%20%3D%20%22World%22%3B%20%0A%20%20%20%20char%20result%5B30%5D%3B%0A%20%20%20%20%0A%0A%20%20%20%20strcpy%28result,%20token1%29%3B%0A%20%20%20%20%0A%20%20%20%20strcat%28result,%20%22%20%22%29%3B%0A%20%20%20%20%0A%20%20%20%20strcat%28result,%20token2%29%3B%0A%20%20%20%20%0A%20%20%20%20cout%20%3C%3C%20result%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%20%20char%20result2%5B30%5D%3B%0A%20%20%20%20sprintf%28result2,%20%22%25s%20%25s%22,%20token1,%20token2%29%3B%0A%20%20%20%20cout%20%3C%3C%20%22Using%20sprintf%3A%20%22%20%3C%3C%20result2%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    /* Concatenación de cadenas usando strcpy y strcat */
    char token1[10] = "Hello";
    char token2[10] = "World"; 
    char result[30];  // Debe ser lo suficientemente grande para el resultado final
    
    // Primero copiar la primera cadena
    strcpy(result, token1);
    
    // Luego concatenar un espacio
    strcat(result, " ");
    
    // Finalmente concatenar la segunda cadena
    strcat(result, token2);
    
    cout << result << endl;
    /* Alternativa: usando sprintf para más control */
    char result2[30];
    sprintf(result2, "%s %s", token1, token2);
    cout << "Using sprintf: " << result2 << endl;
    
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Ausing%20namespace%20std%3B%0Aint%20main%28%29%20%7B%0A%20%0A%20%20%20%20char%20void_string%5B1%5D%20%3D%20%22%22%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28void_string%5B0%5D%20%3D%3D%20'%5C0'%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22String%20is%20empty%20%28method%201%29%22%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%0A%20%20%20%20if%20%28strlen%28void_string%29%20%3D%3D%200%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22String%20is%20empty%20%28method%202%29%22%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    /* Verificar si la cadena está vacía */
    char void_string[1] = "";  // Cadena vacía es solo '\0'
    
    // Método 1: Verificar primer carácter
    if (void_string[0] == '\0') {
        cout << "String is empty (method 1)" << endl;
    }
    
    // Método 2: Verificar longitud
    if (strlen(void_string) == 0) {
        cout << "String is empty (method 2)" << endl;
    }

    //https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Ausing%20namespace%20std%3B%0Aint%20main%28%29%20%7B%0A%0A%20%20%20%20char%20text%5B50%5D%20%3D%20%22The%20quick%20brown%20fox%22%3B%0A%20%20%20%20char*%20found%20%3D%20strstr%28text,%20%22brown%22%29%3B%0A%20%20%20%20%0A%20%20%20%20if%20%28found%20!%3D%20NULL%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Found%20'brown'%20at%20position%3A%20%22%20%3C%3C%20%28found%20-%20text%29%20%3C%3C%20endl%3B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Remaining%20text%3A%20%22%20%3C%3C%20found%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=6&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    /* Buscar subcadena usando strstr() */
    /*
        char* strstr(const char* haystack, const char* needle)
            const char* haystack: cadena en la cual buscar
            const char* needle: subcadena a buscar
            return: puntero a la primera ocurrencia de needle, o NULL si no se encuentra
    */
    char text[50] = "The quick brown fox";
    char* found = strstr(text, "brown");
    
    if (found != NULL) {
        cout << "Found 'brown' at position: " << (found - text) << endl;
        cout << "Remaining text: " << found << endl;
    }

    return 0;
}

/*
RESUMEN: Operaciones con Cadenas Estilo C - Enfoque Heredado

Este archivo demuestra las operaciones fundamentales con cadenas C (char arrays) 
y contrasta con las capacidades modernas de std::string:

1. ESTRUCTURA Y MEMORIA:
   - Cadenas C: arreglos de char terminados en '\0' (terminador nulo)
   - Gestión manual de memoria: tamaños de búfer fijos (char s[20])
   - Riesgo de desbordamiento de búfer si no se calculan tamaños correctamente
   - Ejemplo: char r[5] para almacenar 4 caracteres + '\0'

2. BÚSQUEDA Y EXTRACCIÓN:
   - strchr(): Busca caracteres individuales, retorna puntero o NULL
   - strstr(): Busca subcadenas completas, retorna puntero a inicio
   - Cálculo manual de posiciones: (puntero_encontrado - puntero_base)
   - strncpy(): Copia parcial SIN terminador automático (¡debe agregarse!)

3. MEDICIÓN Y ACCESO:
   - strlen(): Única forma de obtener longitud (cuenta hasta '\0')
   - Acceso por índice: s[i] (sin verificación de límites)
   - NO existe equivalente a .at() con verificación de límites
   - Vulnerabilidad: acceso fuera de límites sin advertencias

4. COMPARACIÓN:
   - strcmp(): Comparación completa lexicográfica
   - strncmp(): Comparación de primeros n caracteres
   - Aritmética de punteros: str + offset para posiciones específicas
   - Valores de retorno: 0 (iguales), <0 (primera menor), >0 (primera mayor)

5. CONCATENACIÓN Y CONSTRUCCIÓN:
   - Proceso de múltiples pasos: strcpy() + strcat()
   - sprintf(): Enfoque más controlado con formato
   - Gestión manual de tamaños de búfer de destino
   - Riesgo: desbordamiento si el búfer destino es muy pequeño

6. VERIFICACIÓN DE ESTADO:
   - Dos métodos para cadenas vacías:
     * Verificar primer carácter: str[0] == '\0'
     * Verificar longitud: strlen(str) == 0

CONTRASTES CON C++ MODERNO:
✗ C: Gestión manual de memoria y tamaños
✓ C++: Gestión automática con std::string

✗ C: Funciones separadas (strchr, strstr, strcmp)
✓ C++: Métodos integrados (.find(), .substr(), .compare())

✗ C: Riesgo de desbordamiento de búfer
✓ C++: Verificación automática de límites (.at())

✗ C: Terminadores nulos manuales
✓ C++: Gestión interna transparente

LECCIONES CLAVE:
- Las cadenas C requieren programación defensiva constante
- Cada operación necesita consideración cuidadosa del tamaño del búfer
- std::string elimina la mayoría de estos problemas de gestión manual
- Entender cadenas C ayuda a comprender la gestión de memoria en C++
- El código C es más verboso pero ofrece control de bajo nivel
*/



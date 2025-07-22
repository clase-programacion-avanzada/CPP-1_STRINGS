// Tokenización de cadenas usando funciones de C tradicional
#include <iostream>
#include <cstring>
#include <cstdio>

//referencias: https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
//referencias: https://cplusplus.com/reference/cstring/strtok/
//referencias: https://learn.microsoft.com/es-es/cpp/c-runtime-library/reference/strtok-strtok-l-wcstok-wcstok-l-mbstok-mbstok-l?view=msvc-170

//https://pythontutor.com/visualize.html#code=//%20C-style%20string%20tokenization%0A%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0Ausing%20namespace%20std%3B%0A%0Avoid%20tokenizeWithStrtok%28char%20text%5B%5D,%20const%20char*%20delimiter%29%0A%7B%0A%20%20%20%20cout%20%3C%3C%20%22%5CnTokenizing%20with%20strtok%28%29%3A%5Cn%22%3B%0A%20%20%20%20cout%20%3C%3C%20%22Original%20text%3A%20%22%20%3C%3C%20text%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%20%20%20%20char*%20token%20%3D%20strtok%28text,%20delimiter%29%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28token%20!%3D%20nullptr%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Token%3A%20%22%20%3C%3C%20token%20%3C%3C%20endl%3B%0A%20%20%20%20%20%20%20%20token%20%3D%20strtok%28nullptr,%20delimiter%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20texto%5B20%5D%3B%0A%20%20%20%20strcpy%28texto,%20%22Hello%20world%20from%20C%22%29%3B%0A%20%20%20%20%0A%20%20%20%20tokenizeWithStrtok%28texto,%20%22%20%22%29%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
using namespace std;

// En C tradicional, la tokenización se hace principalmente con la función strtok()
// Esta función es parte de la librería <cstring> y modifica la cadena original
// IMPORTANTE: strtok() es destructiva - modifica la cadena original

// Método 1: Usando strtok() básico
void tokenizeWithStrtok(char text[], const char* delimiter) {
    cout << "\nTokenizing with strtok():\n";
    cout << "Texto original: \"" << text << "\"\n";
    cout << "Delimitador: \"" << delimiter << "\"\n";
    
    // La primera llamada a strtok especifica la cadena a tokenizar
    char* token = strtok(text, delimiter);
    
    // Las siguientes llamadas usan nullptr como primer parámetro
    while (token != nullptr) {
        cout << "Token: \"" << token << "\"" << endl;
        token = strtok(nullptr, delimiter); // nullptr significa "continuar con la cadena anterior"
    }
}

// Método 2: Tokenización manual usando strchr() - más control
void tokenizeWithStrchr(char text[], char delimiter) {
    cout << "\nTokenizing with strchr() (manual method):\n";
    cout << "Texto original: \"" << text << "\"\n";
    cout << "Delimitador: '" << delimiter << "'\n";
    
    char* start = text;
    char* end;
    
    // Buscamos el delimitador carácter por carácter
    while ((end = strchr(start, delimiter)) != nullptr) {
        // Temporalmente terminamos la cadena donde encontramos el delimitador
        *end = '\0';
        cout << "Token: \"" << start << "\"" << endl;
        
        // Restauramos el carácter y movemos el puntero de inicio
        *end = delimiter;
        start = end + 1;
    }
    
    // Procesamos el último token
    if (strlen(start) > 0) {
        cout << "Token: \"" << start << "\"" << endl;
    }
}

// Método 3: Tokenización sin modificar la cadena original (usando índices)
void tokenizeWithoutModifying(const char text[], char delimiter) {
    cout << "\nTokenizing without modifying original string:\n";
    cout << "Texto original: \"" << text << "\"\n";
    cout << "Delimitador: '" << delimiter << "'\n";
    
    int len = strlen(text);
    int start = 0;
    char token[256]; // Buffer para cada token
    
    for (int i = 0; i <= len; i++) {
        // Si encontramos el delimitador o llegamos al final
        if (text[i] == delimiter || text[i] == '\0') {
            // Copiamos el token al buffer
            int tokenLen = i - start;
            strncpy(token, text + start, tokenLen);
            token[tokenLen] = '\0'; // Terminamos la cadena
            
            if (tokenLen > 0) { // Solo mostramos tokens no vacíos
                cout << "Token: \"" << token << "\"" << endl;
            }
            
            start = i + 1; // Siguiente token comienza después del delimitador
        }
    }
}

// Método 4: Función para comparar con la versión moderna de C++
void compareWithModernCpp() {
    cout << "\n=== COMPARACIÓN: C vs C++ MODERNO ===\n";
    
    // Método C tradicional
    cout << "\n--- Método C tradicional (strtok) ---\n";
    char textC[100];
    strcpy(textC, "apple,banana,orange,grape");
    
    cout << "Antes de strtok: \"" << textC << "\"\n";
    
    char* token = strtok(textC, ",");
    while (token != nullptr) {
        cout << "Token: \"" << token << "\"" << endl;
        token = strtok(nullptr, ",");
    }
    
    cout << "Después de strtok: \"" << textC << "\" (¡MODIFICADA!)\n";
}

// Ejemplo práctico: Parsear una línea CSV al estilo C
void parseCSVLineC(char csvLine[]) {
    cout << "\nParsing CSV line (C style):\n";
    cout << "CSV: \"" << csvLine << "\"\n";
    
    const char* fieldNames[] = {"Nombre", "Edad", "Profesión", "Ciudad"};
    char* token = strtok(csvLine, ",");
    int fieldIndex = 0;
    
    while (token != nullptr && fieldIndex < 4) {
        cout << fieldNames[fieldIndex] << ": \"" << token << "\"" << endl;
        token = strtok(nullptr, ",");
        fieldIndex++;
    }
}

// Demostración de los problemas de strtok (no es thread-safe)
void demonstrateStrtokProblems() {
    cout << "\n=== PROBLEMAS DE STRTOK ===\n";
    
    char text1[50], text2[50];
    strcpy(text1, "uno dos tres");
    strcpy(text2, "A-B-C");
    
    cout << "Texto 1: \"" << text1 << "\"\n";
    cout << "Texto 2: \"" << text2 << "\"\n";
    
    // Empezamos a tokenizar text1
    char* token1 = strtok(text1, " ");
    cout << "Primer token de texto1: \"" << token1 << "\"\n";
    
    // Ahora tokenizamos text2 (esto interfiere con text1)
    char* token2 = strtok(text2, "-");
    cout << "Primer token de texto2: \"" << token2 << "\"\n";
    
    // Intentamos continuar con text1 - ¡sorpresa! No funciona como esperamos
    token1 = strtok(nullptr, " ");
    cout << "¿Segundo token de texto1?: ";
    if (token1 != nullptr) {
        cout << "\"" << token1 << "\"" << endl;
    } else {
        cout << "nullptr (¡se perdió el contexto!)" << endl;
    }
    
    cout << "\nPROBLEMA: strtok() mantiene estado interno estático,\n";
    cout << "por lo que no se pueden tokenizar múltiples cadenas simultáneamente.\n";
}

int main() {
    cout << "=== TOKENIZACIÓN DE CADENAS ESTILO C ===\n";
    
    // Ejemplo 1: strtok básico
    char texto1[100];
    strcpy(texto1, "Hola mundo desde C");
    tokenizeWithStrtok(texto1, " ");
    
    // Ejemplo 2: usando strchr
    char texto2[100];
    strcpy(texto2, "Programación-avanzada-en-C++");
    tokenizeWithStrchr(texto2, '-');
    
    // Ejemplo 3: sin modificar original
    const char* texto3 = "apple,banana,orange,grape";
    tokenizeWithoutModifying(texto3, ',');
    
    // Ejemplo 4: comparación con C++
    compareWithModernCpp();
    
    // Ejemplo 5: CSV parsing
    char csvData[100];
    strcpy(csvData, "Juan,25,Ingeniero,Bogotá");
    parseCSVLineC(csvData);
    
    // Ejemplo 6: Problemas de strtok
    demonstrateStrtokProblems();
    
    // Ejemplo 7: Múltiples delimitadores
    cout << "\n--- Múltiples delimitadores ---\n";
    char texto4[100];
    strcpy(texto4, "word1,word2;word3 word4");
    cout << "Texto: \"" << texto4 << "\"\n";
    cout << "Delimitadores: \",; \" (coma, punto y coma, espacio)\n";
    
    char* token = strtok(texto4, ",; ");
    while (token != nullptr) {
        cout << "Token: \"" << token << "\"" << endl;
        token = strtok(nullptr, ",; ");
    }
    
    return 0;
}

/*
RESUMEN: Tokenización de cadenas estilo C

1. FUNCIÓN PRINCIPAL - strtok():
   - char* strtok(char* str, const char* delim)
   - Primera llamada: pasa la cadena a tokenizar
   - Siguientes llamadas: pasa nullptr para continuar
   - DESTRUCTIVA: modifica la cadena original

2. ALTERNATIVAS MÁS CONTROLADAS:
   - strchr(): busca un carácter específico
   - strncpy(): copia porciones de cadena
   - Manipulación manual con índices y punteros

3. VENTAJAS DEL MÉTODO C:
   - Eficiente en memoria (no crea copias)
   - Control directo sobre punteros
   - Rápido para casos simples

4. DESVENTAJAS DEL MÉTODO C:
   - Modifica la cadena original
   - No es thread-safe (estado interno estático)
   - Propenso a errores de buffer overflow
   - Menos flexible que los métodos de C++

5. FUNCIONES C RELACIONADAS:
   - strtok(): tokenización básica
   - strchr(): buscar carácter
   - strrchr(): buscar carácter desde el final
   - strstr(): buscar subcadena
   - strcpy(), strncpy(): copiar cadenas
   - strlen(): longitud de cadena

CONCEPTOS CLAVE:
- strtok() mantiene estado interno estático
- char* y nullptr para manejo de punteros
- Terminación de cadenas con '\0'
- Diferencia entre destructivo y no destructivo
- Buffer overflow y seguridad en C
*/

// Tokenización de cadenas en C++ moderno
#include <iostream>
#include <string>
#include <sstream>

//referencias: https://www.geeksforgeeks.org/tokenizing-a-string-cpp/
//referencias: https://learn.microsoft.com/es-es/cpp/standard-library/stringstream-class?view=msvc-170
//referencias: https://cplusplus.com/reference/string/string/find/

//https://pythontutor.com/visualize.html#code=//%20String%20tokenization%20in%20modern%20C%2B%2B%0A%23include%20%3Ciostream%3E%0A%23include%20%3Cstring%3E%0A%23include%20%3Csstream%3E%0A%0Ausing%20namespace%20std%3B%0A%0Avoid%20tokenizeUsingStringstream%28string%20text%29%0A%7B%0A%20%20%20%20cout%20%3C%3C%20%22%5CnTokenizing%20using%20stringstream%3A%5Cn%22%3B%0A%20%20%20%20stringstream%20ss%28text%29%3B%0A%20%20%20%20string%20token%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28getline%28ss,%20token,%20'%20'%29%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Token%3A%20%22%20%3C%3C%20token%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%7D%0A%0Avoid%20tokenizeUsingFind%28string%20text,%20char%20delimiter%29%0A%7B%0A%20%20%20%20cout%20%3C%3C%20%22%5CnTokenizing%20using%20find%28%29%20and%20substr%28%29%3A%5Cn%22%3B%0A%20%20%20%20size_t%20pos%20%3D%200%3B%0A%20%20%20%20string%20token%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28%28pos%20%3D%20text.find%28delimiter%29%29%20!%3D%20string%3A%3Anpos%29%20%7B%0A%20%20%20%20%20%20%20%20token%20%3D%20text.substr%280,%20pos%29%3B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Token%3A%20%22%20%3C%3C%20token%20%3C%3C%20endl%3B%0A%20%20%20%20%20%20%20%20text.erase%280,%20pos%20%2B%201%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20%0A%20%20%20%20if%20%28!text.empty%28%29%29%20%7B%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20%22Token%3A%20%22%20%3C%3C%20text%20%3C%3C%20endl%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20string%20texto%20%3D%20%22Hola%20mundo%20desde%20C%2B%2B%22%3B%0A%20%20%20%20%0A%20%20%20%20tokenizeUsingStringstream%28texto%29%3B%0A%20%20%20%20tokenizeUsingFind%28texto,%20'%20'%29%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

using namespace std;

// La tokenización es el proceso de dividir una cadena en partes más pequeñas llamadas tokens
// usando un delimitador específico (espacio, coma, punto y coma, etc.)
// En C++ moderno tenemos varias formas elegantes de hacer esto

// Método 1: Usando stringstream con getline y delimitador personalizado
void tokenizeUsingStringstream(string text) {
    cout << "\nTokenizing using stringstream:\n";
    cout << "Texto original: \"" << text << "\"\n";
    
    // Creamos un stringstream a partir de la cadena
    stringstream ss(text);
    string token;
    
    // getline puede tomar un delimitador personalizado (por defecto es '\n')
    // Aquí usamos espacio ' ' como delimitador
    while (getline(ss, token, ' ')) {
        cout << "Token: \"" << token << "\"" << endl;
    }
}

// Método 2: Usando stringstream con el operador >> (para espacios como delimitador)
void tokenizeUsingStreamOperator(string text) {
    cout << "\nTokenizing using stream operator (>>):\n";
    cout << "Texto original: \"" << text << "\"\n";
    
    stringstream ss(text);
    string token;
    
    // El operador >> automáticamente usa espacios como delimitadores
    while (ss >> token) {
        cout << "Token: \"" << token << "\"" << endl;
    }
}

// Método 3: Usando find() y substr() - más control manual
void tokenizeUsingFind(string text, char delimiter) {
    cout << "\nTokenizing using find() and substr():\n";
    cout << "Texto original: \"" << text << "\"\n";
    cout << "Delimitador: '" << delimiter << "'\n";
    
    size_t pos = 0;
    string token;
    
    // Buscamos el delimitador y extraemos tokens uno por uno
    while ((pos = text.find(delimiter)) != string::npos) {
        // Extraemos el token desde el inicio hasta la posición del delimitador
        token = text.substr(0, pos);
        cout << "Token: \"" << token << "\"" << endl;
        
        // Eliminamos el token procesado y el delimitador de la cadena
        text.erase(0, pos + 1);
    }
    
    // No olvidemos el último token (después del último delimitador)
    if (!text.empty()) {
        cout << "Token: \"" << text << "\"" << endl;
    }
}

// Método 4: Función genérica para tokenizar con cualquier delimitador
void tokenizeWithCustomDelimiter(string text, string delimiter) {
    cout << "\nTokenizing with custom delimiter:\n";
    cout << "Texto original: \"" << text << "\"\n";
    cout << "Delimitador: \"" << delimiter << "\"\n";
    
    size_t pos = 0;
    string token;
    
    while ((pos = text.find(delimiter)) != string::npos) {
        token = text.substr(0, pos);
        if (!token.empty()) { // Evitamos tokens vacíos
            cout << "Token: \"" << token << "\"" << endl;
        }
        text.erase(0, pos + delimiter.length());
    }
    
    if (!text.empty()) {
        cout << "Token: \"" << text << "\"" << endl;
    }
}

// Ejemplo práctico: Procesar un archivo CSV
void processCSVLine(string csvLine) {
    cout << "\nProcessing CSV line:\n";
    cout << "CSV: \"" << csvLine << "\"\n";
    
    stringstream ss(csvLine);
    string field;
    int fieldNumber = 1;
    
    while (getline(ss, field, ',')) {
        cout << "Campo " << fieldNumber << ": \"" << field << "\"" << endl;
        fieldNumber++;
    }
}

int main() {
    cout << "=== TOKENIZACIÓN DE CADENAS EN C++ ===\n";
    
    // Ejemplo básico con espacios
    string texto1 = "Hola mundo desde C++";
    tokenizeUsingStringstream(texto1);
    
    // El mismo texto pero usando el operador >>
    tokenizeUsingStreamOperator(texto1);
    
    // Usando find() con espacios
    string texto2 = "Programación avanzada en C++";
    tokenizeUsingFind(texto2, ' ');
    
    // Tokenización con diferentes delimitadores
    string texto3 = "apple,banana,orange,grape";
    tokenizeUsingFind(texto3, ',');
    
    // Delimitador de múltiples caracteres
    string texto4 = "uno::dos::tres::cuatro";
    tokenizeWithCustomDelimiter(texto4, "::");
    
    // Ejemplo práctico: procesamiento CSV
    string csvData = "Juan,25,Ingeniero,Bogotá";
    processCSVLine(csvData);
    
    // Ejemplo con delimitadores múltiples consecutivos
    string texto5 = "palabra1;;;palabra2;;;palabra3";
    tokenizeWithCustomDelimiter(texto5, ";;;");
    
    return 0;
}

/*
RESUMEN: Tokenización de cadenas en C++

1. MÉTODOS PRINCIPALES:
   - stringstream + getline(stream, token, delimiter)
   - stringstream + operador >> (para espacios)
   - string::find() + string::substr() + string::erase()
   - Combinaciones personalizadas para delimitadores complejos

2. VENTAJAS DE CADA MÉTODO:
   - stringstream + getline: Fácil de usar, maneja delimitadores simples
   - stringstream + operador >>: Automático para espacios en blanco
   - find() + substr(): Mayor control, permite delimitadores de múltiples caracteres
   - Métodos personalizados: Flexibilidad total

3. CONSIDERACIONES IMPORTANTES:
   - string::npos indica "no encontrado" en métodos de búsqueda
   - Manejar tokens vacíos (delimitadores consecutivos)
   - Recordar procesar el último token
   - size_t para posiciones (tipo sin signo)

4. CASOS DE USO COMUNES:
   - Procesamiento de archivos CSV
   - Análisis de comandos de línea
   - Parsing de URLs y rutas
   - Separación de palabras en texto

CONCEPTOS CLAVE:
- Tokenización = dividir cadenas en partes más pequeñas
- Delimitador = carácter(es) que separan los tokens
- string::npos = constante que indica "posición no encontrada"
- stringstream = flujo de cadena para procesamiento
*/
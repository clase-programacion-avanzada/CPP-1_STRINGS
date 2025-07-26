// Ejemplo de streams en C++
#include <iostream>
#include <sstream>

using namespace std;

//En C++, los streams se usan para realizar operaciones de entrada y salida.
//Son una serie de bytes que se transfieren desde la fuente hasta el destino.
//Por ejemplo, de un archivo a la pantalla, de un archivo a un archivo, de un programa a un archivo, de un programa a la pantalla, etc.
//La fuente o destino puede ser un dispositivo, archivo, o memoria.
//Los streams se usan para leer y escribir datos desde y hacia los dispositivos estándar de entrada/salida, archivos, y memoria.


int main () {

   //Ya conocemos dos tipos de streams: cin (stream de entrada estándar) y cout (stream de salida estándar).
   //cin y cout son parte de la librería iostream, que es por lo que necesitamos incluirla al inicio de nuestro programa.
   // << es el operador de inserción, y >> es el operador de extracción
   //El operador de inserción (<<) se usa para escribir datos al dispositivo de salida estándar.
   cout << "Write a number:" << endl;
   //El operador de extracción (>>) se usa para leer datos del dispositivo de entrada estándar.
   int number;
   cin >> number;

   cout << "You entered: " << number << endl;

   //También podemos usar la clase stringstream para tratar strings como streams.
   //Esto es útil para operar en strings de la misma forma en que operamos en streams.
   //Podemos usar la clase stringstream para tratar strings como streams.

   //La clase stringstream se usa para operar en strings.
   //Se usa para leer desde y escribir hacia strings.
   stringstream ss;

   //Podemos usar el operador de inserción (<<) para escribir al string.
   ss << "Hello World";

   //Podemos usar el operador de extracción (>>) para leer del string.
   string myString;
   ss >> myString;

   cout << "The string is: " << myString << endl;

   //También podemos usar la clase stringstream para convertir strings a números y viceversa.
   //Podemos usar el operador de inserción (<<) para escribir al string.
   ss << 123;

   //Podemos usar el operador de extracción (>>) para leer del string.
   int myNumber;
   ss >> myNumber;

   cout << "The number is: " << myNumber << endl;

   //Podemos inicializar un stringstream con un string.
   stringstream ss2("Hello World");

   //Podemos usar la función str() para obtener el string del stringstream.
   cout << "The string is: " << ss2.str() << endl << endl;

   //Podemos usar la función str() para establecer el string del stringstream.
   ss2.str("Goodbye World");

   //Podemos usar la función str() para obtener el string del stringstream.
   cout << "The string is: " << ss2.str() << endl << endl;

   //Normalmente, verás que getline se usa en conjunto con la clase stringstream, cin, o un archivo.
   //La función getline se usa para leer una línea de un stream.

   stringstream ss3("Hello World");

   string line;

   //Podemos usar la función getline para leer una línea del stringstream.
   getline(ss3, line);

   cout << "The line is: " << line << endl << endl;
   
   //spoiler del taller, podemos usar stringstream y getline para dividir un string en tokens.
   //También podríamos usar getline con un tercer parámetro para especificar el delimitador.
   stringstream ss4("Hello,World");

   string token;

   //Podemos usar la función getline para leer un token del stringstream.
   getline(ss4, token, ',');
   cout << "The token is: " << token << endl << endl;

   //si usamos de nuevo la función getline, leerá el resto del string
   getline(ss4, token, ',');
   cout << "The token is: " << token << endl << endl;

   //También podemos verificar si el stringstream ha llegado al final del string usando eof.
   stringstream ss5("Hello World");

   string word;

   while(!ss5.eof()) {
      getline(ss5, word, ' ');
      cout << "The word is: " << word << endl;
   }
    
  return 0;
}

/*
RESUMEN: ¿Qué son los Streams en C++?

1. CONCEPTO DE STREAMS:
   - Serie de bytes transferidos entre fuente y destino
   - Abstracción para operaciones de entrada/salida (I/O)
   - Fuente/destino: dispositivos, archivos, memoria

2. STREAMS BÁSICOS (iostream):
   - cin: stream de entrada estándar (teclado)
   - cout: stream de salida estándar (pantalla)
   - Operadores: << (inserción), >> (extracción)

3. STRINGSTREAM CLASE:
   - Trata strings como streams
   - Permite operaciones de I/O en strings
   - Útil para conversiones string ↔ números
   - Métodos principales: str(), << (inserción), >> (extracción)

4. FUNCIÓN GETLINE:
   - Lee líneas completas desde un stream
   - Sintaxis: getline(stream, variable)
   - Con delimitador: getline(stream, variable, delimitador)
   - Útil para parsing y tokenización de strings

5. CONTROL DE FLUJO:
   - eof(): verifica fin de stream
   - Loops con streams para procesamiento secuencial
   - Manejo seguro de datos de longitud variable

APLICACIONES PRÁCTICAS:
- Conversión entre tipos de datos
- Parsing de strings con delimitadores
- Procesamiento de entrada de usuario
- Manipulación y análisis de texto
- Preparación para operaciones con archivos

VENTAJAS DE STREAMS:
- Interfaz consistente para diferentes tipos de I/O
- Manejo automático de conversiones de tipos
- Sintaxis intuitiva con operadores
- Integración natural con STL y algoritmos C++
*/

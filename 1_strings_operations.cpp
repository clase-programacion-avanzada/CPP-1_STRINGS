// comparando peras con peras
#include <iostream>
//https://stackoverflow.com/questions/9257665/difference-between-string-and-string-h
#include <string.h>

using namespace std;

int main () {

      // Tomamos cualquier cadena
    string s = "dog:cat";
 
    // Encontrar la posición de ':' usando find()
    /*
        int find(const string& str, size_t pos = 0) const;
            const string& str: la cadena a ser buscada
            size_t pos: la posición donde iniciar la búsqueda
            return: la posición del primer carácter de la primera coincidencia
                    o string::npos si no se encuentra coincidencia
    */
    int pos = s.find(":");
    
    /*
        string substr(size_t pos = 0, size_t len = npos) const;
            size_t pos: la posición del primer carácter a ser retornado
            size_t len: el número de caracteres a ser retornados
            return: la cadena desde la posición pos hasta la posición pos+len
    */
    // Copiar subcadena después de pos
    string sub = s.substr(pos + 1);
 
    // imprime el resultado
    cout << "String is: " << sub<<endl;
    cout << endl;
 
    string s1 = "Javeriana";
 
    // Copia tres caracteres de s1 (empezando
    // desde la posición 1)
    string r = s1.substr(0, 4);
 
    // imprime el resultado
    cout << "String is: " << r << endl;
    
    /*Podemos encontrar la longitud de la cadena de tres maneras diferentes: */
    cout << "String length using length() is: " << s1.length() << endl;
    cout << "String length using size() is: " << s1.size() << endl;
    cout << "String length using strlen is: " << strlen(s1.c_str())<< endl;
    cout << endl;
    /*También podemos obtener un carácter particular dentro de una cadena tratándola como un arreglo*/
    s1[s1.size()-1];
    cout << "Character at position 1 is: " << s1[1] << endl;
    cout << "Character at position 2 is: " << s1[2] << endl;
    cout << "Character at position 3 is: " << s1[3] << endl;
    cout << "Character at position 4 is: " << s1[4] << endl;
    cout << endl;

    /*o usando la función .at*/
    cout << "Character at position 1 is: " << s1.at(1) << endl;
    cout << "Character at position 2 is: " << s1.at(2) << endl;
    cout << "Character at position 3 is: " << s1.at(3) << endl;
    cout << "Character at position 4 is: " << s1.at(4) << endl;

   
  string str1 = "green apple";
  //string str1 ("green apple");
  string str2 ("red apple");
    /*  parámetros de la función compare
        int compare (const string& str)
            const string& str: la cadena a ser comparada
            return: 0 si las cadenas son iguales
                    1 si la primera cadena es mayor que la segunda
                    -1 si la primera cadena es menor que la segunda
    */
  if (str1.compare(str2) != 0)
    cout << str1 << " is not " << str2 << '\n';
    /*
    int compare (size_t pos, size_t len, const string& str) const;
            size_t pos: la posición del primer carácter a ser comparado
            size_t len: el número de caracteres a ser comparados
            const string& str: la cadena a ser comparada
            return: 0 si las cadenas son iguales
                    1 si la primera cadena es mayor que la segunda
                    -1 si la primera cadena es menor que la segunda
    
    */
  if (str1.compare(6,5,"apple") == 0)
    cout << "still, " << str1 << " is an apple\n";

  if (str2.compare(str2.size()-5,5,"apple") == 0)
    cout << "and " << str2 << " is also an apple\n";
    /*
     int compare (size_t pos, size_t len, const string& str,
             size_t subpos, size_t sublen = npos) const;    
            size_t pos: la posición del primer carácter a ser comparado
            size_t len: el número de caracteres a ser comparados
            const string& str: la cadena a ser comparada
            size_t subpos: la posición del primer carácter a ser comparado
            size_t sublen: el número de caracteres a ser comparados
            return: 0 si las cadenas son iguales
                    1 si la primera cadena es mayor que la segunda
                    -1 si la primera cadena es menor que la segunda
    */
  if (str1.compare(6,5,str2,4,5) == 0)
    cout << "therefore, both are apples\n";

  /*También podemos concatenar cadenas usando el operador '+' */
  string token1 = "Hello";
  string token2 = "World";

  string result = token1 + " " + token2;
  cout << result <<endl;
 
  /*¿Cómo puedo saber si una cadena está vacía?*/
  string void_string = "";

  if (void_string.empty()) {
    cout << "String is empty" << endl;
  }

  return 0;
}

/*
RESUMEN: Operaciones con Cadenas (String Operations)

1. BÚSQUEDA Y EXTRACCIÓN:
   - find(): Busca subcadenas y retorna posición o string::npos
   - substr(): Extrae porciones de cadenas con posición y longitud
   - Ejemplo: "dog:cat" → find(":") → substr() → "cat"

2. MEDICIÓN DE LONGITUD:
   - .length(): Método preferido para std::string
   - .size(): Equivalente a length(), retorna el mismo valor
   - strlen(): Función C que requiere conversión con .c_str()

3. ACCESO A CARACTERES:
   - Operador []: Acceso directo por índice (s[0], s[1]...)
   - Método .at(): Acceso seguro con verificación de límites
   - Ambos permiten lectura y modificación de caracteres individuales

4. COMPARACIÓN DE CADENAS:
   - compare(): Método completo con múltiples variantes
     * compare(str): Comparación completa
     * compare(pos, len, str): Comparación parcial
     * compare(pos, len, str, subpos, sublen): Comparación de subcadenas
   - Retorna: 0 (iguales), >0 (primera mayor), <0 (primera menor)

5. CONCATENACIÓN Y MANIPULACIÓN:
   - Operador +: Concatenación de cadenas ("Hello" + " World")
   - Operador +=: Adición en lugar (str1 += str2)
   - Asignación directa con operador =

6. VERIFICACIÓN DE ESTADO:
   - empty(): Verifica si la cadena está vacía
   - Útil para validación antes de operaciones

CONCEPTOS CLAVE:
- std::string maneja automáticamente la memoria y el tamaño
- Indexación basada en 0 (primer carácter en posición 0)
- string::npos como valor de "no encontrado" en búsquedas
- Diferencia entre métodos C++ (.length()) y funciones C (strlen())
- Flexibilidad en comparaciones: completas, parciales, por posición
*/
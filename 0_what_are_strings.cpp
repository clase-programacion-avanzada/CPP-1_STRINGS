// comparando peras con peras
#include <iostream>
//https://stackoverflow.com/questions/9257665/difference-between-string-and-string-h
#include <string.h>

using namespace std;

//https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Cstring.h%3E%0A%0Ausing%20namespace%20std%3B%0A%0A%0Aint%20main%20%28%29%0A%7B%0A%20%20char%20myString%5B30%5D%3B%0A%0A%20%20strcpy%28myString,%20%22Hello%22%29%3B%20//%20copy%20%22Hello%22%20into%20myString%0A%0A%20%20cout%20%3C%3C%20%22myString%20value%20is%20now%3A%20%22%20%3C%3C%20myString%20%3C%3C%20endl%3B%0A%0A%20%20char%20myString2%5B30%5D%20%3D%20%22%20World%22%3B%0A%20%20%0A%20%20cout%20%3C%3C%20%22Concatenating%20two%20strings%3A%20%22%20%3C%3C%20myString%20%3C%3C%20%22%20and%22%20%3C%3C%20myString2%20%3C%3C%20endl%3B%0A%20%20%0A%20%20strcat%28myString,%20myString2%29%3B%20//%20myString%20now%20contains%20%22Hello%20World%22%0A%20%20%0A%20%20cout%20%3C%3C%20%22myString%20value%20is%20now%3A%20%22%20%3C%3C%20myString%20%3C%3C%20endl%3B%0A%0A%20%20int%20length%20%3D%200%3B%0A%20%20%0A%20%20strlen%28myString%29%3B%20//%20returns%2011%0A%20%20%0A%20%20cout%20%3C%3C%20%22myString%20length%20is%3A%20%22%3C%3C%20strlen%28myString%29%20%3C%3C%20endl%3B%0A%20%20%0A%20%20cout%20%3C%3C%20%22String%20comparison%20result%20is%3A%20%22%20%3C%3C%20strcmp%28myString,%20myString2%29%3C%3C%20endl%3B%20//%20returns%200%20if%20equal,%20%3C%200%20if%20myString%20comes%20before%20myString2,%20%3E%200%20if%20myString%20comes%20after%20myString2%0A%0A%20%20cout%20%3C%3C%20%22Copying%20a%20string%3A%20%22%20%3C%3C%20myString2%20%3C%3C%20%22%20into%20%22%20%3C%3C%20myString%20%3C%3C%20endl%3B%0A%20%20%0A%20%20strcpy%28myString,%20myString2%29%3B%20//%20myString%20now%20contains%20%22%20World%22%0A%20%20%0A%20%20cout%20%3C%3C%20%22My%20string%20value%20after%20copying%3A%20%22%20%3C%3C%20myString%20%3C%3C%20endl%3B%0A%0A%20%20string%20myString3%20%3D%20%22Hello%22%3B%0A%0A%20%20string%20myString4%20%3D%20%22%20World%22%3B%0A%20%20%0A%20%20cout%20%3C%3C%20%22Concatenating%20two%20strings%3A%20%22%20%3C%3C%20myString3%20%3C%3C%20%22%20and%22%20%3C%3C%20myString4%20%3C%3C%20endl%3B%0A%20%20%0A%20%20myString3%20%2B%3D%20myString4%3B%20//%20myString%20now%20contains%20%22Hello%20World%22%0A%0A%20%20%0A%20%20cout%20%3C%3C%20%22myString%20length%20is%3A%20%22%3C%3C%20myString3.length%28%29%20%3C%3C%20endl%3B%0A%0A%20%20%0A%20%20cout%20%3C%3C%20%22String%20comparison%20result%20is%3A%20%22%20%3C%3C%20myString3.compare%28myString4%29%3C%3C%20endl%3B%20//%20returns%200%20if%20equal,%20%3C%200%20if%20myString%20comes%20before%20myString2,%20%3E%200%20if%20myString%20comes%20after%20myString2%0A%0A%20%20%0A%20%20cout%20%3C%3C%20%22Changing%20the%20value%20of%20a%20string%3A%20%22%20%3C%3C%20myString3%20%3C%3C%20%22%20into%20%22%20%3C%3C%20myString4%20%3C%3C%20endl%3B%0A%20%20%0A%20%20myString3%20%3D%20myString4%3B%20//%20myString%20now%20contains%20%22%20World%22%0A%0A%20%20%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

int main ()
{

    //En los viejos tiempos de C, las cadenas eran simplemente arreglos de caracteres.
    //El problema con este enfoque es que tienes que llevar el control del tamaño de la cadena por ti mismo.
    //Si olvidas hacer esto, puedes fácilmente desbordar el arreglo, causando que tu programa se cuelgue.

    //char myString[255] = "Hello"; // 255 caracteres es más que suficiente para "Hello"
    char myString[255];

    strcpy(myString, "Hello"); // copia "Hello" en myString

    //En este caso lo que se está almacenando en myString son los caracteres H, e, l, l, o, y \0.
    //El \0 se llama terminador nulo, y es como C sabe dónde termina la cadena.

    //El terminador nulo es por qué necesitamos asignar 255 caracteres para una cadena que solo contiene 5 caracteres.
    cout << "myString value is now: " << myString << endl;

    //si tratamos de imprimir la cadena sin el terminador nulo, obtenemos basura
    cout << "Printing without null terminating it: ";
    for (int i = 0; i < 255; i++)
    {
        cout << myString[i];
    }
    cout << endl;

    //Como puedes haber imaginado, esta es una forma muy propensa a errores de trabajar con cadenas.
    // si queremos concatenar dos cadenas necesitamos hacer esto
    char myString2[255] = " World";
    cout << "Concatenating two strings: " << myString << " and" << myString2 << endl;
    strcat(myString, myString2); // myString ahora contiene "Hello World"
    cout << "myString value is now: " << myString << endl;

    //si queremos obtener la longitud de una cadena necesitamos hacer esto
    int length = 0;
    strlen(myString); // retorna 11
    cout << "myString length is: "<< strlen(myString) << endl;

    //si queremos comparar dos cadenas necesitamos hacer esto
    cout << "String comparison result is: " << strcmp(myString, myString2)<< endl; // retorna 0 si son iguales, < 0 si myString viene antes que myString2, > 0 si myString viene después que myString2


    //si queremos copiar una cadena necesitamos hacer esto
    cout << "Copying a string: " << myString2 << " into " << myString << endl;
    strcpy(myString, myString2); // myString ahora contiene " World"
    cout << "My string value after copying: " << myString << endl;

    //Como puedes ver, trabajar con cadenas en C es una molestia.
    //Afortunadamente, C++ introdujo un nuevo tipo llamado std::string que es mucho más conveniente de usar.
    
    //std::string es una clase que encapsula un arreglo dinámico de caracteres.
    //Maneja el tamaño del arreglo a través de un contador interno, 
    // y proporciona funciones miembro para la manipulación de cadenas.
    //Debido a que std::string es una clase, podemos usar el operador . para acceder a sus funciones miembro.
    // std::string es la forma moderna de trabajar con cadenas en C++.
    string myString3 = "Hello";

    //si queremos concatenar dos cadenas necesitamos hacer esto
    string myString4 = " World";
    cout << "Concatenating two strings: " << myString3 << " and" << myString4 << endl;
    myString3 += myString4; // myString ahora contiene "Hello World"

    //si queremos obtener la longitud de una cadena necesitamos hacer esto
    cout << "myString length is: "<< myString3.length() << endl;

    //si queremos comparar dos cadenas necesitamos hacer esto
    cout << "String comparison result is: " << myString3.compare(myString4)<< endl; // retorna 0 si son iguales, < 0 si myString viene antes que myString2, > 0 si myString viene después que myString2

    //Si queremos cambiar el valor de una cadena podemos hacer esto
    cout << "Changing the value of a string: " << myString3 << " into " << myString4 << endl;
    myString3 = myString4; // myString ahora contiene " World"

    return 0;
}

/*
RESUMEN: ¿Qué son las cadenas (strings)?

1. CADENAS ESTILO C (char arrays):
   - Requieren manejo manual del tamaño y memoria
   - Usan terminador nulo (\0) para marcar el final
   - Funciones como strcpy(), strcat(), strlen(), strcmp()
   - Propensos a errores: desbordamiento de búfer, corrupción de memoria

2. CADENAS MODERNAS C++ (std::string):
   - Manejo automático de memoria y tamaño
   - Operadores intuitivos: +=, =, comparación directa
   - Métodos integrados: .length(), .compare()
   - Seguras y fáciles de usar

CONCEPTOS CLAVE:
- Terminador nulo (\0) en cadenas C
- Diferencia entre arreglos estáticos vs manejo dinámico
- Evolución de C a C++ en el manejo de cadenas
- Ventajas de la programación orientada a objetos para tipos de datos
*/

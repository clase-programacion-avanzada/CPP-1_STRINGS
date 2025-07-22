// Ejemplo de plantillas (templates) en C++
#include <iostream>

//referencia: https://www.geeksforgeeks.org/templates-cpp/
//referencia: https://learn.microsoft.com/es-es/cpp/cpp/templates-cpp?view=msvc-170
using namespace std;

//En C++, las plantillas (templates) son una herramienta poderosa para la programación genérica.
//La idea básica detrás de las plantillas de C++ es permitir al programador crear una clase o función plantilla que pueda ser usada con muchos tipos diferentes.
//Por ejemplo, una empresa de software puede necesitar sort() para diferentes tipos de datos.
//En lugar de escribir y mantener múltiples códigos, podemos escribir un sort() y pasar el tipo de dato como parámetro.
//El compilador genera el código apropiado para el tipo especificado.

template <typename T>
void sort(T a[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (a[j] < a[i]) {
                //https://www.geeksforgeeks.org/swap-in-cpp/
                swap(a[i], a[j]);
            }            
}

template <typename T>
void printArray(T a[], int size)
{
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

template <typename T>
T myMax(T x, T y)
{
    //https://www.programiz.com/cpp-programming/ternary-operator
    return (x > y) ? x : y;
}

//También podemos usar plantillas con múltiples parámetros.
//Por ejemplo, podemos tener una función genérica 
template <typename T, typename U>
void myFunction(T x, U y)
{
    cout << x << " " << y << endl;
}

//También podemos usar plantillas con estructuras.
template <typename T>
struct Pair
{
    T x, y;
    Pair(T i, T j)
    {
        x = i;
        y = j;
    }

    T getMax() {
        return (x > y) ? x : y;
    };
};


int main () {

    //Cuando llamamos sort() con un arreglo de enteros, el compilador crea una función usando int como tipo de dato.
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);

    sort(a, n);

    cout << "Sorted array using int: ";
    printArray(a, n);

    //Cuando llamamos sort() con un arreglo de float, el compilador crea otra función usando float como tipo de dato.
    float b[5] = { 10.5, 50.5, 30.5, 40.5, 20.5 };
    n = sizeof(b) / sizeof(b[0]);

    sort(b, n);

    cout << "Sorted array using float: ";
    printArray(b, n);
    
    //También podemos llamar myMax() con diferentes tipos de datos. 
    //Nota que entre el nombre de la función y la lista de parámetros, hay <typename T>.
    //Esto es necesario para decirle al compilador que es una plantilla, pero no son obligatorios.
    cout << "Showing max between int 3 and 7" << myMax<int>(3, 7) << endl; // Llama myMax para int
    cout << myMax<double>(3.0, 7.0) << endl; // llama myMax para double
    cout << myMax<char>('g', 'e') << endl; // llama myMax para char

    //También podemos llamar myFunction() con diferentes tipos de datos.
    //Nota que entre el nombre de la función y la lista de parámetros, hay <typename T, typename U>.
    //Esto es necesario para decirle al compilador que es una plantilla, pero no son obligatorios.
    myFunction(10, 20.5);
    myFunction<char, double>('A', 20.5);

    //También podemos usar plantillas con estructuras.
    //Nota que entre el nombre de la estructura y la lista de parámetros, hay <typename T>.
    //Esto es necesario para decirle al compilador que es una plantilla.
    //En este caso le estamos diciendo al compilador que tenemos un Pair de int,
    //en el caso de las estructuras es obligatorio especificar el tipo de dato.
    Pair<int> p1(10, 20);
    cout << p1.getMax() << endl;

    Pair<double> p2(10.5, 20.5);
    cout << p2.getMax() << endl;
    


  return 0;
}

/*
RESUMEN: ¿Qué son las plantillas (templates)?

1. PROGRAMACIÓN GENÉRICA:
   - Las plantillas permiten escribir código que funciona con cualquier tipo de dato
   - El compilador genera código específico para cada tipo usado
   - Evita duplicación de código para diferentes tipos de datos

2. TIPOS DE PLANTILLAS:
   - Plantillas de función: template <typename T>
   - Plantillas con múltiples parámetros: template <typename T, typename U>
   - Plantillas de estructura/clase: struct/class con tipos genéricos

3. VENTAJAS:
   - Reutilización de código
   - Type safety (seguridad de tipos)
   - Eficiencia: código optimizado para cada tipo
   - Flexibilidad: funciona con tipos built-in y definidos por el usuario

4. INSTANCIACIÓN:
   - Explícita: myMax<int>(3, 7)
   - Implícita: myFunction(10, 20.5) - el compilador deduce los tipos
   - Para estructuras: siempre explícita Pair<int> p1(10, 20)

CONCEPTOS CLAVE:
- typename vs class (preferir typename para consistencia)
- Instanciación automática del compilador
- Templates = paradigma de programación genérica
- Diferencia entre plantillas de función y de estructura
*/

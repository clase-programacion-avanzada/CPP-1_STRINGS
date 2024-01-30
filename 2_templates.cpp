// Example of templates in C++
#include <iostream>

//reference: https://www.geeksforgeeks.org/templates-cpp/
//reference: https://learn.microsoft.com/es-es/cpp/cpp/templates-cpp?view=msvc-170



using namespace std;

//In C++, templates are a powerful tool for generic programming.
//The basic idea behind C++ templates is to allow the programmer to create a template class or function that can be used with many different types.
//For example, a software company may need sort() for different data types.
//Rather than writing and maintaining the multiple codes, we can write one sort() and pass data type as a parameter.
//The compiler generates the appropriate code for the type specified.

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

//We can also use templates with multiple parameters.
//For example, we can have a generic function 
template <typename T, typename U>
void myFunction(T x, U y)
{
    cout << x << " " << y << endl;
}

//We can also use templates with structs.
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

    //When we call sort() with an integer array, the compiler creates a function using int as the data type.
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);

    sort(a, n);

    cout << "Sorted array using int: ";
    printArray(a, n);

    //When we call sort() with a float array, the compiler creates another function using float as the data type.
    float b[5] = { 10.5, 50.5, 30.5, 40.5, 20.5 };
    n = sizeof(b) / sizeof(b[0]);

    sort(b, n);

    cout << "Sorted array using float: ";
    printArray(b, n);
    
    //We can also call myMax() with different data types. 
    //Notice that between the function name and the parameter list, there is <typename T>.
    //This is necessary to tell the compiler that it is a template but they are not mandatory.
    cout << "Showing max between int 3 and 7" << myMax<int>(3, 7) << endl; // Call myMax for int
    cout << myMax<double>(3.0, 7.0) << endl; // call myMax for double
    cout << myMax<char>('g', 'e') << endl; // call myMax for char

    //We can also call myFunction() with different data types.
    //Notice that between the function name and the parameter list, there is <typename T, typename U>.
    //This is necessary to tell the compiler that it is a template but they are not mandatory.
    myFunction(10, 20.5);
    myFunction<char, double>('A', 20.5);

    //We can also use templates with structs.
    //Notice that between the struct name and the parameter list, there is <typename T>.
    //This is necessary to tell the compiler that it is a template.
    //In this case we are telling to the compiler that we have a Pair of int,
    //in the case of structs it is mandatory to specify the data type.
    Pair<int> p1(10, 20);
    cout << p1.getMax() << endl;

    Pair<double> p2(10.5, 20.5);
    cout << p2.getMax() << endl;
    


  return 0;
}

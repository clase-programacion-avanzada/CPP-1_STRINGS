// Example of templates in C++
#include <iostream>

//reference: https://www.geeksforgeeks.org/templates-cpp/
//reference: https://learn.microsoft.com/es-es/cpp/cpp/templates-cpp?view=msvc-170

//https://pythontutor.com/visualize.html#code=//%20Example%20of%20templates%20in%20C%2B%2B%0A%23include%20%3Ciostream%3E%0A%0Ausing%20namespace%20std%3B%0A%0Atemplate%20%3Ctypename%20T%3E%0Avoid%20sort%28T%20a%5B%5D,%20int%20n%29%0A%7B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20for%20%28int%20j%20%3D%20i%3B%20j%20%3C%20n%3B%20j%2B%2B%29%0A%20%20%20%20%20%20%20%20%20%20%20%20if%20%28a%5Bj%5D%20%3C%20a%5Bi%5D%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20swap%28a%5Bi%5D,%20a%5Bj%5D%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20%7D%20%20%20%20%20%20%20%20%20%20%20%20%0A%7D%0A%0Atemplate%20%3Ctypename%20T%3E%0Avoid%20printArray%28T%20a%5B%5D,%20int%20n%29%0A%7B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20i%20%3C%20n%3B%20i%2B%2B%29%0A%20%20%20%20%20%20%20%20cout%20%3C%3C%20a%5Bi%5D%20%3C%3C%20%22%20%22%3B%0A%20%20%20%20cout%20%3C%3C%20endl%3B%0A%7D%0A%0Atemplate%20%3Ctypename%20T%3E%0AT%20myMax%28T%20x,%20T%20y%29%0A%7B%0A%20%20return%20%28x%20%3E%20y%29%20%3F%20x%20%3A%20y%3B%0A%7D%0A%0A//We%20can%20also%20use%20templates%20with%20multiple%20parameters.%0A//For%20example,%20we%20can%20have%20a%20generic%20function%20%0Atemplate%20%3Ctypename%20T,%20typename%20U%3E%0Avoid%20myFunction%28T%20x,%20U%20y%29%0A%7B%0A%20%20%20%20cout%20%3C%3C%20x%20%3C%3C%20%22%20%22%20%3C%3C%20y%20%3C%3C%20endl%3B%0A%7D%0A%0A//We%20can%20also%20use%20templates%20with%20structs.%0Atemplate%20%3Ctypename%20T%3E%0Astruct%20Pair%0A%7B%0A%20%20%20%20T%20x,%20y%3B%0A%20%20%20%20Pair%28T%20i,%20T%20j%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20x%20%3D%20i%3B%0A%20%20%20%20%20%20%20%20y%20%3D%20j%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20T%20getMax%28%29%20%7B%0A%20%20%20%20%20%20%20%20return%20%28x%20%3E%20y%29%20%3F%20x%20%3A%20y%3B%0A%20%20%20%20%7D%3B%0A%7D%3B%0A%0A%0Aint%20main%20%28%29%20%7B%0A%0A%20%20%20%20int%20a%5B5%5D%20%3D%20%7B%2010,%2050,%2030,%2040,%2020%20%7D%3B%0A%20%20%20%20int%20n%20%3D%20sizeof%28a%29%20/%20sizeof%28a%5B0%5D%29%3B%0A%0A%20%20%20%20sort%28a,%20n%29%3B%0A%0A%20%20%20%20cout%20%3C%3C%20%22Sorted%20array%20using%20int%3A%20%22%3B%0A%20%20%20%20printArray%28a,%20n%29%3B%0A%0A%20%20%20%20float%20b%5B5%5D%20%3D%20%7B%2010.5,%2050.5,%2030.5,%2040.5,%2020.5%20%7D%3B%0A%20%20%20%20n%20%3D%20sizeof%28b%29%20/%20sizeof%28b%5B0%5D%29%3B%0A%0A%20%20%20%20sort%28b,%20n%29%3B%0A%0A%20%20%20%20cout%20%3C%3C%20%22Sorted%20array%20using%20float%3A%20%22%3B%0A%20%20%20%20printArray%28b,%20n%29%3B%0A%20%20%20%20%0A%20%20%20%20cout%20%3C%3C%20%22Showing%20max%20between%20int%203%20and%207%22%20%3C%3C%20myMax%3Cint%3E%283,%207%29%20%3C%3C%20endl%3B%20//%20Call%20myMax%20for%20int%0A%20%20%20%20cout%20%3C%3C%20myMax%3Cdouble%3E%283.0,%207.0%29%20%3C%3C%20endl%3B%20//%20call%20myMax%20for%20double%0A%20%20%20%20cout%20%3C%3C%20myMax%3Cchar%3E%28'g',%20'e'%29%20%3C%3C%20endl%3B%20//%20call%20myMax%20for%20char%0A%0A%20%20%20%20myFunction%2810,%2020.5%29%3B%0A%20%20%20%20myFunction%3Cchar,%20double%3E%28'A',%2020.5%29%3B%0A%0A%20%20%20%20Pair%3Cint%3E%20p1%2810,%2020%29%3B%0A%20%20%20%20cout%20%3C%3C%20p1.getMax%28%29%20%3C%3C%20endl%3B%0A%0A%20%20%20%20Pair%3Cdouble%3E%20p2%2810.5,%2020.5%29%3B%0A%20%20%20%20cout%20%3C%3C%20p2.getMax%28%29%20%3C%3C%20endl%3B%0A%20%20%20%20%0A%0A%0A%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false

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

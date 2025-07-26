# Programación Avanzada - Manejo de Cadenas en C++

## Descripción del Proyecto

Este repositorio contiene ejemplos educativos progresivos para el curso de **Programación Avanzada**, enfocados en la evolución del manejo de cadenas desde el enfoque tradicional de C hasta las capacidades modernas de C++. Los ejemplos están diseñados para demostrar paso a paso la transición de técnicas de programación heredadas a enfoques modernos.

El proyecto sigue una metodología de aprendizaje incremental donde cada concepto se construye sobre el anterior, mostrando las ventajas prácticas de la programación moderna en C++.

---

## Estructura del Aprendizaje

### 📚 Progresión Temática

Los archivos están numerados siguiendo una jerarquía de conceptos para facilitar el aprendizaje secuencial:

#### **Nivel 0: Fundamentos de Cadenas**

- **0.0.0** → Declaración de C-strings
- **0.0.1** → Declaración de std::string  
- **0.1.0** → Operaciones básicas con C-strings
- **0.1.1** → Operaciones básicas con std::string y problemas comunes con C-strings
- **0.2.0** → Funciones utilitarias de C-strings
- **0.2.1** → Funciones utilitarias de std::string

#### **Nivel 1: Conceptos Avanzados**

- **1** → Streams y manejo de flujos de datos

---

## Contenido Detallado

### 🔤 **0.0 - Declaración de Cadenas**

#### **0.0.0 - Declaración de C-strings** (`0_0_0_c_strings_declaration.cpp`)

**Conceptos fundamentales de C-strings:**

- **Arreglos de caracteres**: Terminados en `\0` (null terminator)
- **Diferentes métodos de inicialización**:
  - Literal de cadena: `char str[] = "Hola"`
  - Especificación de tamaño: `char str[20] = "Hola"`
  - Carácter por carácter: `char str[] = {'H', 'o', 'l', 'a', '\0'}`
  - Punteros a literal: `const char* str = "Hola"`
- **Gestión manual de memoria y terminadores nulos**
- **Visualización interactiva** con enlaces a Python Tutor

#### **0.0.1 - Declaración de std::string** (`0_0_1_strings_declaration.cpp`)

**Métodos modernos de declaración:**

- **Constructor por defecto**: Cadena vacía automática
- **Desde literales**: Inicialización directa e indirecta
- **Constructor de copia**: Gestión automática de memoria
- **Desde C-strings**: Conversión transparente
- **Constructor con repetición**: `std::string(5, 'A')`
- **Subcadenas**: Extracción de partes de otras cadenas
- **Ventajas sobre C-strings**: Seguridad y simplicidad

---

### ⚙️ **0.1 - Operaciones con Cadenas**

#### **0.1.0 - Operaciones con C-strings** (`0_1_0_c_strings_operations.cpp`)

**Funciones tradicionales de la biblioteca C:**

- **Búsqueda**: `strchr()`, `strstr()`
- **Medición**: `strlen()`
- **Copia**: `strcpy()`, `strncpy()`
- **Concatenación**: `strcat()`, `strncat()`
- **Comparación**: `strcmp()`, `strncmp()`
- **Conversiones**: `atoi()`, `atof()`, `snprintf()`
- **Problemas comunes**: Buffer overflow, gestión manual de memoria

#### **0.1.1 - Operaciones con std::string y Problemas de C-strings** (`0_1_1_strings_operations.cpp` y `0_1_1_c_strings_problems.cpp`)

**Métodos modernos de std::string:**

- **Búsqueda segura**: `.find()` con retorno `string::npos`
- **Extracción**: `.substr()` con verificación automática de límites
- **Medición**: `.length()`, `.size()`, `.empty()`
- **Comparación**: `.compare()` y operadores (`==`, `!=`, `<`, `>`)
- **Modificación**: `.append()`, `.insert()`, `.erase()`, `.replace()`

**Problemas demostrados de C-strings:**

- Buffer overflow y seguridad
- Gestión compleja de memoria
- Errores comunes y cómo evitarlos

---

### 🔧 **0.2 - Funciones Utilitarias**

#### **0.2.0 - Funciones Utilitarias de C-strings** (`0_2_0_c_strings_util_functions.cpp`)

**Implementaciones manuales y bibliotecas C:**

- **Tokenización**: `strtok()` y sus limitaciones
- **Validación**: Funciones de verificación manual
- **Manipulación**: Transformaciones carácter por carácter
- **Conversiones**: Entre tipos numéricos y cadenas

#### **0.2.1 - Funciones Utilitarias de std::string** (`0_2_1_strings_util_functions.cpp`)

**Herramientas modernas integradas:**

- **Transformaciones**: `.transform()`, `.tolower()`, `.toupper()`
- **Búsqueda avanzada**: Múltiples criterios y patrones
- **Validación integrada**: Métodos seguros y eficientes
- **Operaciones en lote**: Procesamiento de múltiples cadenas

---

### 🌊 **1 - Streams y Flujos de Datos** (`1_streams.cpp`)

**Conceptos fundamentales de streams:**

- **Abstracción de I/O**: Interfaz unificada para entrada/salida
- **Streams estándar**: `cin`, `cout`, `cerr`
- **Operadores de flujo**: `<<` (inserción), `>>` (extracción)

**StringStream para procesamiento avanzado:**

- **Clase `stringstream`**: Tratamiento de cadenas como flujos
- **Conversiones automáticas**: Entre diferentes tipos de datos
- **Parsing con delimitadores**: `getline()` personalizado
- **Control de flujo**: `.eof()`, `.fail()`, `.clear()`

**Aplicaciones prácticas:**

- Conversión segura entre strings y números
- Parsing de datos estructurados
- Preparación para técnicas de tokenización
- Interfaz consistente para operaciones complejas

---

## Metodología Educativa

### 🎯 **Enfoque Comparativo**

Cada concepto se presenta mostrando:

- **Problema en C**: Limitaciones y riesgos del enfoque tradicional
- **Solución en C++**: Ventajas y mejoras del enfoque moderno
- **Código lado a lado**: Comparaciones directas para entender diferencias
- **Casos de uso reales**: Aplicaciones prácticas de cada técnica

### 🔬 **Visualización Interactiva**

- **Enlaces a Python Tutor**: Visualización paso a paso de la ejecución
- **Gestión de memoria**: Comparación visual entre enfoques C y C++
- **Debugging asistido**: Herramientas para entender el comportamiento del código

### 📈 **Progresión de Dificultad**

- **Conceptos básicos**: Declaración y operaciones simples
- **Operaciones intermedias**: Búsqueda, modificación y validación
- **Técnicas avanzadas**: Streams, conversiones y procesamiento complejo

---

## Conceptos Transversales

### 🔄 **Evolución de C a C++**

- **Gestión de memoria**: Manual → Automática
- **Seguridad**: Propensa a errores → Verificación integrada  
- **Sintaxis**: Verbosa → Operadores intuitivos
- **Mantenibilidad**: Compleja → Código más limpio y legible

### 🛡️ **Programación Defensiva**

- **C**: Verificación manual constante de límites
- **C++**: Protección automática con verificaciones internas
- **Prevención de errores**: Técnicas para evitar problemas comunes

---

## Referencias y Recursos Adicionales

### 📖 **Documentación Oficial**

- [Why strtok() should be deprecated](https://stackoverflow.com/questions/44336831/why-should-strtok-be-deprecated) [Artículo]
- [Why should strtok() generally be avoided?](https://benpfaff.org/writings/clc/strtok.html) [Artículo]
- [Templates in c++ with examples](https://www.geeksforgeeks.org/templates-cpp/) [Artículo]
- [C++ Strings](https://www.geeksforgeeks.org/c-string-class-and-its-applications/) [Artículo]
- [Plantillas (c++)](https://learn.microsoft.com/es-es/cpp/cpp/templates-cpp?view=msvc-170) [Artículo]
- [Strings in C++](https://www.geeksforgeeks.org/strings-in-cpp/) [Artículo]
- [How to split a string in C++, java and python](https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java//) [Artículo]
- [What are C++ FUNCTION TEMPLATES? 🍪](https://www.youtube.com/watch?v=spZd2rNtze8) [Video]
- [STL Templates in C++ - Generic Functions and Classes (beginner-friendly)](https://www.youtube.com/watch?v=-Svq5IYPWbc) [Video]
- [Introduction to std::string](https://www.learncpp.com/cpp-tutorial/introduction-to-stdstring/) [Artículo]

### 🔬 **Visualización de Código**

Los archivos incluyen enlaces a [Python Tutor](https://pythontutor.com) para visualización interactiva de:


---

## Filosofía del Proyecto

Este conjunto de ejemplos está diseñado para mostrar **por qué** C++ moderno es preferible al C tradicional, no solo **cómo** usar las nuevas características. Cada archivo contiene:

- **Contexto histórico**: Explicación de problemas en enfoques anteriores
- **Comparaciones directas**: Código C vs C++ lado a lado
- **Explicaciones conceptuales**: Comentarios extensivos en español
- **Referencias externas**: Enlaces a documentación y visualizaciones
- **Progresión lógica**: Conceptos construidos secuencialmente
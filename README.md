# Programación Avanzada - Manejo de Cadenas y Plantillas en C++

## Descripción del Proyecto

Este repositorio contiene ejemplos educativos progresivos para el curso de **Programación Avanzada**, enfocados en la evolución del manejo de cadenas desde el enfoque tradicional de C hasta las capacidades modernas de C++, incluyendo conceptos avanzados de programación genérica con plantillas (templates).

Los ejemplos están diseñados para demostrar la transición de técnicas de programación heredadas a enfoques modernos, mostrando las ventajas de la programación orientada a objetos y la programación genérica en C++.

---

## Estructura del Aprendizaje

### 📚 Progresión Temática

Los archivos están numerados para indicar la secuencia de aprendizaje recomendada:

1. **Fundamentos de Cadenas** (`0_what_are_strings.cpp`)
2. **Operaciones con Cadenas C vs C++** (`1_c_strings_operations.cpp` y `1_strings_operations.cpp`)
3. **Flujos de Datos** (`2_streams.cpp`)
4. **Programación Genérica** (`3_templates.cpp`)
5. **Tokenización Avanzada** (`4_c_string_tokenization.cpp` y `4_string_tokenization.cpp`)

---

## Contenido Detallado

### 🔤 **0. ¿Qué son las Cadenas?** (`0_what_are_strings.cpp`)

**Conceptos fundamentales:**
- **Cadenas estilo C**: Arreglos de caracteres con terminador nulo (`\0`)
- **Cadenas modernas C++**: Clase `std::string` con manejo automático de memoria
- **Gestión de memoria**: Manual vs automática
- **Operaciones básicas**: Comparación entre enfoques C y C++

**Puntos clave:**
- Problemas del enfoque C: desbordamiento de búfer, gestión manual de memoria
- Ventajas de `std::string`: seguridad, facilidad de uso, operadores intuitivos
- Transición histórica de C a C++ en el manejo de cadenas

---

### ⚙️ **1. Operaciones con Cadenas**

#### **1a. Operaciones Estilo C** (`1_c_strings_operations.cpp`)
**Funciones tradicionales de C:**
- `strchr()`: Búsqueda de caracteres individuales
- `strstr()`: Búsqueda de subcadenas
- `strncpy()`: Copia controlada con gestión manual del terminador nulo
- `strlen()`: Medición de longitud
- `strcmp()`: Comparación lexicográfica

**Características del enfoque C:**
- Control directo de memoria y punteros
- Riesgo de desbordamiento de búfer
- Gestión manual de terminadores nulos
- Eficiencia en casos específicos

#### **1b. Operaciones Modernas C++** (`1_strings_operations.cpp`)
**Métodos de la clase `std::string`:**
- `.find()`: Búsqueda flexible con retorno de posición o `string::npos`
- `.substr()`: Extracción de subcadenas con parámetros de posición y longitud
- `.length()` y `.size()`: Medición automática
- `.compare()`: Comparación completa con múltiples variantes
- `.empty()`: Verificación de estado

**Ventajas del enfoque C++:**
- Operadores intuitivos (`+`, `+=`, `==`)
- Verificación automática de límites
- Gestión transparente de memoria
- Métodos integrados y consistentes

---

### 🌊 **2. Flujos de Datos (Streams)** (`2_streams.cpp`)

**Conceptos de streams:**
- **Abstracción de I/O**: Interfaz consistente para diferentes tipos de entrada/salida
- **Streams básicos**: `cin` (entrada), `cout` (salida)
- **Operadores de flujo**: `<<` (inserción), `>>` (extracción)

**StringStream avanzado:**
- Clase `stringstream`: Tratamiento de cadenas como flujos de datos
- Conversiones automáticas entre tipos
- Función `getline()` con delimitadores personalizados
- Control de flujo con `.eof()`

**Aplicaciones prácticas:**
- Conversión entre strings y números
- Parsing de datos con delimitadores
- Preparación para tokenización
- Interfaz unificada para operaciones de I/O

---

### 🔧 **3. Plantillas (Templates)** (`3_templates.cpp`)

**Programación genérica:**
- **Concepto**: Código que funciona con cualquier tipo de dato
- **Instanciación**: Generación automática de código específico por tipo
- **Reutilización**: Evita duplicación de código para diferentes tipos

**Tipos de plantillas:**
- **Plantillas de función**: `template <typename T>`
- **Múltiples parámetros**: `template <typename T, typename U>`
- **Plantillas de estructura**: Tipos de datos genéricos

**Características avanzadas:**
- **Type safety**: Verificación de tipos en tiempo de compilación
- **Instanciación**: Explícita (`myMax<int>()`) vs implícita (deducción automática)
- **Eficiencia**: Código optimizado para cada tipo específico

**Conceptos clave:**
- Diferencias entre plantillas de función y estructura
- Paradigma de programación genérica

---

### ✂️ **4. Tokenización de Cadenas**

#### **4a. Tokenización Estilo C** (`4_c_string_tokenization.cpp`)
**Funciones tradicionales:**
- `strtok()`: Función principal de tokenización
- `strchr()`: Búsqueda manual de delimitadores
- Manipulación directa con punteros e índices

**Características del enfoque C:**
- **Destructivo**: Modifica la cadena original
- **Estado estático**: No es thread-safe
- **Control directo**: Gestión manual de punteros
- **Eficiencia**: Rápido para casos simples

**Problemas comunes:**
- Pérdida de contexto en tokenización simultánea
- Riesgo de buffer overflow
- Gestión manual de terminadores nulos

#### **4b. Tokenización Moderna C++** (`4_string_tokenization.cpp`)
**Métodos modernos:**
- **StringStream + getline**: Con delimitadores personalizados
- **Operador >>**: Automático para espacios en blanco
- **find() + substr() + erase()**: Control manual completo
- **Delimitadores múltiples**: Soporte para strings complejos

**Ventajas del enfoque C++:**
- **No destructivo**: Preserva cadenas originales
- **Thread-safe**: Sin estado estático global
- **Flexibilidad**: Delimitadores de múltiples caracteres
- **Seguridad**: Verificación automática de límites

**Casos de uso prácticos:**
- Procesamiento de archivos CSV
- Análisis de comandos
- Parsing de URLs y rutas
- Separación de texto en tokens

---

## Conceptos Transversales

### 🔄 **Evolución de C a C++**
- **Gestión de memoria**: Manual → Automática
- **Seguridad**: Propensa a errores → Verificación integrada
- **Sintaxis**: Verbosa → Operadores intuitivos
- **Mantenibilidad**: Compleja → Simplicidad de uso

### 🎯 **Programación Defensiva**
- **C**: Verificación manual constante de límites
- **C++**: Protección automática con `.at()` y verificaciones internas
- **Templates**: Type safety en tiempo de compilación

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
- Gestión de memoria en cadenas C vs C++
- Instanciación de templates
- Operaciones de tokenización paso a paso

---

## Filosofía del Proyecto

Este conjunto de ejemplos está diseñado para mostrar **por qué** C++ moderno es preferible al C tradicional, no solo **cómo** usar las nuevas características. Cada archivo contiene:

- **Contexto histórico**: Explicación de problemas en enfoques anteriores
- **Comparaciones directas**: Código C vs C++ lado a lado
- **Explicaciones conceptuales**: Comentarios extensivos en español
- **Referencias externas**: Enlaces a documentación y visualizaciones
- **Progresión lógica**: Conceptos construidos secuencialmente


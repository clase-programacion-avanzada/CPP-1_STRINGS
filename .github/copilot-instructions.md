# C++ Educational Examples - AI Coding Guide

## Project Overview
This is an educational C++ project focusing on string manipulation and templates, structured as progressive learning examples for "Programación Avanzada" (Advanced Programming). The codebase demonstrates the evolution from C-style strings to modern C++ string handling and generic programming concepts.

## Architecture & Learning Flow

### Sequential Learning Structure
Files are numbered to indicate learning progression:
- `0_what_are_strings.cpp` - C-style vs C++ strings fundamentals
- `1_strings_operations.cpp` - String operations (find, substr, compare)
- `2_streams.cpp` - stringstream and stream operations
- `3_templates.cpp` - Generic programming with templates

### Key Educational Patterns

**C-Style vs Modern C++**: Examples deliberately contrast legacy approaches with modern alternatives:
```cpp
// Legacy C approach
char myString[255];
strcpy(myString, "Hello");
strcat(myString, myString2);

// Modern C++ approach  
string myString3 = "Hello";
myString3 += myString4;
```

**Progressive Template Complexity**: Templates are introduced incrementally:
- Single type parameters: `template <typename T>`
- Multiple type parameters: `template <typename T, typename U>`
- Template structs: `Pair<int>`, `List<T>`

**Educational Comments**: All files include extensive inline comments explaining concepts, with external reference links to GeeksforGeeks, Microsoft Learn, and Python Tutor visualizations.

## Build & Development Workflow

### Compilation
Use the VS Code build task (Cmd+Shift+P → "Run Task"):
```bash
# Default build command (clang++ with debug symbols)
clang++ -fcolor-diagnostics -fansi-escape-codes -g ${file} -o ${fileBasenameNoExtension}
```

### Running Examples
Each `.cpp` file compiles to its own executable:
```bash
./0_what_are_strings
./1_strings_operations  
./3_templates
```

### File Structure Conventions
- Numbered files (`0_`, `1_`, etc.) indicate teaching sequence
- `example_*` files contain supplementary practice code

## Project-Specific Patterns

### Template Design Philosophy
- Always use `typename T` (not `class T`) for consistency
- Template instantiation is explicit where educational: `myMax<int>(3, 7)`
- Struct templates require explicit type specification: `Pair<int> p1(10, 20)`

### String Operations Focus
Core string methods demonstrated across examples:
- `.find()`, `.substr()`, `.length()`, `.size()`, `.compare()`, `.empty()`
- Stream operations with `stringstream`, `getline()` with custom delimiters
- C-style string functions for comparison: `strlen()`, `strcpy()`, `strcat()`, `strcmp()`, `strchr()`

### Educational Reference Integration
Files include live code visualization links (Python Tutor) in comments for complex examples, particularly template instantiation and string memory management.

## Development Guidelines

When adding new examples:
- Follow the numbered naming convention for sequential learning
- Include comprehensive comments explaining the "why" behind each concept
- Contrast modern C++ approaches with legacy C methods where relevant
- Add Python Tutor visualization links for complex memory/template scenarios
- Maintain the educational progression from basic to advanced concepts
- Do not use any std containers (e.g., std::vector)
- Ensure all examples are self-contained and executable without external dependencies
- Use consistent formatting and naming conventions across all files
- All comments should be in Spanish to align with the educational context

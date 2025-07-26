# C++ Educational Examples - AI Coding Guide

## Project Overview
This is an educational C++ project focusing on string manipulation, structured as progressive learning examples for "Programación Avanzada" (Advanced Programming). The codebase demonstrates the evolution from C-style strings to modern C++ string handling through a hierarchical learning approach.

## Architecture & Learning Flow

### Hierarchical Learning Structure
Files follow a hierarchical numbering system to indicate detailed learning progression:

#### **Level 0: String Fundamentals**
- `0_0_0_c_strings_declaration.cpp` - C-string declaration methods
- `0_0_1_strings_declaration.cpp` - std::string declaration methods
- `0_1_0_c_strings_operations.cpp` - Basic C-string operations
- `0_1_1_c_strings_problems.cpp` - Common C-string problems and pitfalls
- `0_1_1_strings_operations.cpp` - Modern std::string operations
- `0_2_0_c_strings_util_functions.cpp` - C-string utility functions
- `0_2_1_strings_util_functions.cpp` - std::string utility functions

#### **Level 1: Advanced Concepts**
- `1_streams.cpp` - Stream operations and string processing

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

**Progressive Complexity**: Each level builds upon the previous:
- **0.0.x**: Declaration fundamentals (C vs C++)
- **0.1.x**: Basic operations and common problems
- **0.2.x**: Utility functions and advanced techniques
- **1.x**: Stream processing and I/O operations

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
./0_0_0_c_strings_declaration
./0_0_1_strings_declaration
./0_1_0_c_strings_operations
./0_1_1_strings_operations
./0_1_1_c_strings_problems
./0_2_0_c_strings_util_functions
./0_2_1_strings_util_functions
./1_streams
```

### File Structure Conventions
- Hierarchical numbering (0.0.0, 0.0.1, etc.) indicates detailed learning sequence
- Even numbers (.0, .2) typically represent C-style approaches
- Odd numbers (.1) typically represent modern C++ approaches
- Level 0: String fundamentals, Level 1: Advanced concepts

## Project-Specific Patterns

### String Handling Philosophy
- Focus on evolution from C-style strings to modern C++ std::string
- Direct comparison between unsafe C functions and safe C++ methods
- Progressive complexity from basic declaration to advanced operations
- Emphasis on memory safety and modern programming practices

### String Operations Focus
Core string methods demonstrated across examples:
- `.find()`, `.substr()`, `.length()`, `.size()`, `.compare()`, `.empty()`
- Stream operations with `stringstream`, `getline()` with custom delimiters
- C-style string functions for comparison: `strlen()`, `strcpy()`, `strcat()`, `strcmp()`, `strchr()`
- Problem demonstration: buffer overflow, memory management issues

### Educational Reference Integration
Files include live code visualization links (Python Tutor) in comments for complex examples, particularly string memory management and C vs C++ comparisons.

## Development Guidelines

When adding new examples:
- Follow the hierarchical naming convention for sequential learning (0.0.0, 0.0.1, etc.)
- Include comprehensive comments explaining the "why" behind each concept
- Contrast modern C++ approaches with legacy C methods where relevant
- Add Python Tutor visualization links for complex memory/string scenarios
- Maintain the educational progression from basic to advanced concepts
- Do not use any std containers (e.g., std::vector)
- Ensure all examples are self-contained and executable without external dependencies
- Use consistent formatting and naming conventions across all files
- All comments should be in Spanish to align with the educational context

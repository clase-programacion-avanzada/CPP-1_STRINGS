#include <iostream>
#include <cstring>
#include <cstdlib> // Para atoi, atof
#include <cstdio> // Para snprintf
#include <cctype>


// Eliminar espacios al inicio y final (trim)
char* trim(char* str) {
    // Eliminar espacios al inicio
    while (isspace(*str)) str++;
    
    // Si toda la cadena era espacios
    if (*str == '\0') return str;
    
    // Eliminar espacios al final
    char* end = str + strlen(str) - 1;
    while (end > str && isspace(*end)) end--;
    
    // Escribir terminador
    *(end + 1) = '\0';
    
    return str;
}

// Convertir a mayúsculas
void to_upper(char* str) {
    while (*str) {
        *str = toupper(*str);
        str++;
    }
}

// Convertir a minúsculas
void to_lower(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Reversar cadena
void reverse(char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Verificar si es palíndromo
bool is_palindrome(const char* str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

// Contar ocurrencias de un carácter
size_t count_character(const char* str, char c) {
    size_t count = 0;
    while (*str) {
        if (*str == c) count++;
        str++;
    }
    return count;
}

// Contar palabras
size_t count_words(const char* str) {
    size_t count = 0;
    bool is_in_word = false;
    
    while (*str) {
        if (isspace(*str)) {
            is_in_word = false;
        } else if (!is_in_word) {
            is_in_word = true;
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    
    //TRIM
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdlib%3E%20//%20Para%20atoi,%20atof%0A%23include%20%3Ccstdio%3E%20//%20Para%20snprintf%0A%23include%20%3Ccctype%3E%0A%0A%0A%0Achar*%20trim%28char*%20str%29%20%7B%0A%20%20%20%20//%20Eliminar%20espacios%20al%20inicio%0A%20%20%20%20while%20%28isspace%28*str%29%29%20%7B%0A%20%20%20%20%20%20str%2B%2B%0A%20%20%20%20%7D%3B%0A%20%20%20%20%0A%20%20%20%20//%20Si%20toda%20la%20cadena%20era%20espacios%0A%20%20%20%20if%20%28*str%20%3D%3D%20'%5C0'%29%20%7B%0A%20%20%20%20%20%20return%20str%3B%0A%20%20%20%20%7D%0A%20%20%20%20//%20Eliminar%20espacios%20al%20final%0A%20%20%20%20char*%20end%20%3D%20str%20%2B%20strlen%28str%29%20-%201%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28end%20%3E%20str%20%26%26%20isspace%28*end%29%29%20%7B%0A%20%20%20%20%20%20end--%0A%20%20%20%20%7D%3B%0A%20%20%20%20%0A%20%20%20%20//%20Escribir%20terminador%0A%20%20%20%20*%28end%20%2B%201%29%20%3D%20'%5C0'%3B%0A%20%20%20%20%0A%20%20%20%20return%20str%3B%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20%0A%20%20%20%20char%20text%5B%5D%20%3D%20%22%20%20Hola%20Mundo!%20%20%22%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20original%3A%20%5C%22%22%20%3C%3C%20text%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%20%20%20%20char*%20trimmed%20%3D%20trim%28text%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20despu%C3%A9s%20de%20trim%3A%20%5C%22%22%20%3C%3C%20trimmed%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char text[] = "  Hola Mundo!  ";
    std::cout << "Texto original: \"" << text << "\"\n";
    char* trimmed = trim(text);
    std::cout << "Texto después de trim: \"" << trimmed << "\"\n";

    //TO_UPPER
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdlib%3E%20//%20Para%20atoi,%20atof%0A%23include%20%3Ccstdio%3E%20//%20Para%20snprintf%0A%23include%20%3Ccctype%3E%0A%0A//%20Convertir%20a%20may%C3%BAsculas%0Avoid%20to_upper%28char*%20str%29%20%7B%0A%20%20%20%20while%20%28*str%29%20%7B%0A%20%20%20%20%20%20%20%20*str%20%3D%20toupper%28*str%29%3B%0A%20%20%20%20%20%20%20%20str%2B%2B%3B%0A%20%20%20%20%7D%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20%0A%20%20%20%20char%20upperText%5B%5D%20%3D%20%22hola%20mundo%22%3B%0A%20%20%20%20to_upper%28upperText%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20en%20may%C3%BAsculas%3A%20%5C%22%22%20%3C%3C%20upperText%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=33&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char upper_text[] = "hola mundo";
    to_upper(upper_text);
    std::cout << "Texto en mayúsculas: \"" << upper_text << "\"\n";

    //TO_LOWER
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdlib%3E%20//%20Para%20atoi,%20atof%0A%23include%20%3Ccstdio%3E%20//%20Para%20snprintf%0A%23include%20%3Ccctype%3E%0A%0A//%20Convertir%20a%20min%C3%BAsculas%0Avoid%20to_lower%28char*%20str%29%20%7B%0A%20%20%20%20for%20%28int%20i%20%3D%200%3B%20str%5Bi%5D%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20str%5Bi%5D%20%3D%20tolower%28str%5Bi%5D%29%3B%0A%20%20%20%20%7D%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20%0A%20%20%20%20char%20lowerText%5B%5D%20%3D%20%22HOLA%20MUNDO%22%3B%0A%20%20%20%20to_lower%28lowerText%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20en%20min%C3%BAsculas%3A%20%5C%22%22%20%3C%3C%20lowerText%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=25&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false     
    char lower_text[] = "HOLA MUNDO";
    to_lower(lower_text);
    std::cout << "Texto en minúsculas: \"" << lower_text << "\"\n";

    //REVERSE
    // https://pythontutor.com/render.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdlib%3E%20//%20Para%20atoi,%20atof%0A%23include%20%3Ccstdio%3E%20//%20Para%20snprintf%0A%23include%20%3Ccctype%3E%0A%0A//%20Reversar%20cadena%0Avoid%20reverse%28char*%20str%29%20%7B%0A%20%20%20%20size_t%20len%20%3D%20strlen%28str%29%3B%0A%20%20%20%20for%20%28size_t%20i%20%3D%200%3B%20i%20%3C%20len%20/%202%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20char%20temp%20%3D%20str%5Bi%5D%3B%0A%20%20%20%20%20%20%20%20str%5Bi%5D%20%3D%20str%5Blen%20-%201%20-%20i%5D%3B%0A%20%20%20%20%20%20%20%20str%5Blen%20-%201%20-%20i%5D%20%3D%20temp%3B%0A%20%20%20%20%7D%0A%7D%0A%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20%0A%20%20%20%20char%20reverseText%5B%5D%20%3D%20%22Hola%20Mundo%22%3B%0A%20%20%20%20reverse%28reverseText%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22Texto%20reversado%3A%20%5C%22%22%20%3C%3C%20reverseText%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&curInstr=26&heapPrimitives=nevernest&mode=display&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    char reverse_text[] = "Hola Mundo";
    reverse(reverse_text);
    std::cout << "Texto reversado: \"" << reverse_text << "\"\n";

    //IS_PALINDROME
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0A//%20Verificar%20si%20es%20pal%C3%ADndromo%0Abool%20es_palindromo%28const%20char*%20str%29%20%7B%0A%20%20%20%20size_t%20len%20%3D%20strlen%28str%29%3B%0A%20%20%20%20for%20%28size_t%20i%20%3D%200%3B%20i%20%3C%20len%20/%202%3B%20i%2B%2B%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28str%5Bi%5D%20!%3D%20str%5Blen%20-%201%20-%20i%5D%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20false%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%7D%0A%20%20%20%20return%20true%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20const%20char*%20palindromo%20%3D%20%22anilina%22%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22%C2%BF%5C%22%22%20%3C%3C%20palindromo%20%3C%3C%20%22%5C%22%20es%20pal%C3%ADndromo%3F%20%22%20%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3C%3C%20%28es_palindromo%28palindromo%29%20%3F%20%22S%C3%AD%22%20%3A%20%22No%22%29%20%3C%3C%20%22%5Cn%22%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    const char* palindrome = "anilina";
    std::cout << "¿\"" << palindrome << "\" es palíndromo? " 
              << (is_palindrome(palindrome) ? "Sí" : "No") << "\n";
    
    //COUNT_CHARACTER
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%0A//%20Contar%20ocurrencias%20de%20un%20car%C3%A1cter%0Asize_t%20contar_char%28const%20char*%20str,%20char%20c%29%20%7B%0A%20%20%20%20size_t%20count%20%3D%200%3B%0A%20%20%20%20while%20%28*str%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28*str%20%3D%3D%20c%29%20count%2B%2B%3B%0A%20%20%20%20%20%20%20%20str%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20count%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20const%20char*%20contarText%20%3D%20%22Hola%20Mundo,%20Hola%20C%2B%2B%22%3B%0A%20%20%20%20char%20charToCount%20%3D%20'o'%3B%0A%20%20%20%20size_t%20charCount%20%3D%20contar_char%28contarText,%20charToCount%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22El%20car%C3%A1cter%20'%22%20%3C%3C%20charToCount%20%3C%3C%20%22'%20aparece%20%22%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3C%3C%20charCount%20%3C%3C%20%22%20veces%20en%20%5C%22%22%20%3C%3C%20contarText%20%3C%3C%20%22%5C%22%5Cn%22%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    const char* to_count_text = "Hola Mundo, Hola C++";
    char char_to_count = 'o';
    size_t char_count = count_character(to_count_text, char_to_count);
    std::cout << "El carácter '" << char_to_count << "' aparece "
                << char_count << " veces en \"" << to_count_text << "\"\n";
    
    //COUNT_WORDS
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccctype%3E%0A%0A//%20Contar%20palabras%0Asize_t%20contar_palabras%28const%20char*%20str%29%20%7B%0A%20%20%20%20size_t%20count%20%3D%200%3B%0A%20%20%20%20bool%20en_palabra%20%3D%20false%3B%0A%20%20%20%20%0A%20%20%20%20while%20%28*str%29%20%7B%0A%20%20%20%20%20%20%20%20if%20%28isspace%28*str%29%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20en_palabra%20%3D%20false%3B%0A%20%20%20%20%20%20%20%20%7D%20else%20if%20%28!en_palabra%29%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20en_palabra%20%3D%20true%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20count%2B%2B%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20str%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20count%3B%0A%7D%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20const%20char*%20palabrasText%20%3D%20%22Hola%20mundo,%20este%20es%20un%20texto%20de%20prueba%22%3B%0A%20%20%20%20size_t%20wordCount%20%3D%20contar_palabras%28palabrasText%29%3B%0A%20%20%20%20std%3A%3Acout%20%3C%3C%20%22El%20texto%20%5C%22%22%20%3C%3C%20palabrasText%20%3C%3C%20%22%5C%22%20tiene%20%22%0A%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%3C%3C%20wordCount%20%3C%3C%20%22%20palabras%5Cn%22%3B%0A%20%20%20%20%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    const char* to_count_word = "Hola mundo, este es un texto de prueba";
    size_t word_count = count_words(to_count_word);
    std::cout << "El texto \"" << to_count_word << "\" tiene "
                << word_count << " palabras\n";
    
    //Tokenización de cadenas
    // https://pythontutor.com/visualize.html#code=%23include%20%3Ciostream%3E%0A%23include%20%3Ccstring%3E%0A%23include%20%3Ccstdio%3E%0A%0Aint%20main%28%29%20%7B%0A%20%20%20%20char%20texto%5B%5D%20%3D%20%22Hola,Mundo,desde,C%22%3B%0A%20%20%20%20char*%20token%20%3D%20strtok%28texto,%20%22,%22%29%3B%0A%0A%20%20%20%20while%20%28token%20!%3D%20nullptr%29%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22Token%3A%20%25s%5Cn%22,%20token%29%3B%0A%20%20%20%20%20%20%20%20token%20%3D%20strtok%28nullptr,%20%22,%22%29%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&cumulative=false&heapPrimitives=nevernest&mode=edit&origin=opt-frontend.js&py=cpp_g%2B%2B9.3.0&rawInputLstJSON=%5B%5D&textReferences=false
    // strtok() - Modifica la cadena original
    char texto[] = "Hola,Mundo,desde,C";
    char* token = strtok(texto, ",");

    while (token != nullptr) {
        printf("Token: %s\n", token);
        token = strtok(nullptr, ",");
    }
    // NOTA: texto queda modificado con '\0' en lugar de ','

    std::cout << "Texto después de tokenización: \"" << texto << "\"\n";

    return 0;
}
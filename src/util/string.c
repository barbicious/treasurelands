#include "string.h"

#include <string.h>

string_s string_create(char* string) {
    return (string_s){
        .raw = string,
        .len = strlen(string),
    };
}

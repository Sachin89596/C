#include <stdio.h>
#include <string.h>

int main() {
    
     char *string = "Sachin Saggu";
     char *substring = "Saggu";

    
    char *result = strstr(string, substring);

    
    if (result != NULL) {
        printf("Substring '%s' found at position %d.\n", substring, (result - string));
    } else {
        printf("Substring '%s' not found.\n", substring);
    }

    return 0;
}

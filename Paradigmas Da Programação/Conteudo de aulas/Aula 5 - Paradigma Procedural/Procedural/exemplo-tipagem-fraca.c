#include <stdio.h>

int main() {
    
    int i = 92;
    void *v = &i;
    char *c = v;
    
    printf("%c", *c);
    
    return 0;
}
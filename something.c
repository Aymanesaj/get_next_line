#include <stdlib.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

void *ft_calloc(size_t count, size_t size) {
    void *s;
    if (size != 0 && count > SIZE_MAX / size)
        return (NULL);
    s = malloc(count * size);
    if (s == NULL)
        return (NULL);
    ft_memset(s, 0, count * size);  // Assuming you replace ft_memset with memset here
    return (s);
}

int main() {
    int *arr1 = ft_calloc(10, sizeof(int));  // Using ft_calloc
    int *arr2 = calloc(10, sizeof(int));     // Using real calloc

    if (arr1) free(arr1);  // Free the allocated memory
    if (arr2) free(arr2);  // Free the allocated memory

    return 0;
}

#include "get_next_line_bonus.h"



int main()
{
    int fd = open("file1.txt", O_RDONLY);
    char *str;
    while((str = get_next_line(fd)))
    {
        printf("%s",get_next_line(fd));
        free(str);
    }
}


// int main ()
// {
//     char *ptr = malloc(10);
//     // free(ptr);
//     ptr[0] = 'a';

//     // return(0);
// }


// int main()
// {
//     int fd = open("file1.txt", O_RDONLY);
//     // int i = 0;
//     int SIZE = 0;
//     char buffer[100];
//     printf("fd = %i\n------\n",fd);
//     ssize_t bytes_read;
//     // read(fd, buffer, 100);
//     // close(fd);
//     // fd = open("file1.txt", O_RDONLY);
//     // printf("second fd = %i\n------\n",fd);
//     printf("BUFFER_SIZE : %i\n--------\n",SIZE);
//     // close(fd);
//     bytes_read = read(fd, buffer, SIZE);
//     SIZE = buff_size(buffer);
//     if (BUFFER_SIZE != -1)
//         SIZE = BUFFER_SIZE;
//     while (bytes_read > 0 && SIZE)
//     {
//         printf("bytes :%zu\n",bytes_read);
//         buffer[bytes_read] = '\0';
//         printf("string : %s\n--------\n", buffer);
//         SIZE = BUFFER_SIZE - SIZE;
//     }
//     return 0;
// }

// int main()
// {
//     int fd = open ("file1.txt", O_RDONLY);
//     printf("%s",buff_size(fd));
// }
// int main() {
//     int fd ;
//     fd = open("file1.txt", O_RDONLY);
//     printf("fd: %d\n", fd); 
//     fd = open("numbers.txt", O_RDONLY);
//     printf("fd: %d\n", fd); 
//     fd = open("example.txt", O_RDONLY);
//     close(fd);
//     printf("fd: %d\n", fd); 
//     fd = open("file4.txt", O_RDWR);
//     printf("fd: %d\n", fd); 
//     fd = open("numbers.bin", O_RDONLY);
//     printf("fd: %d\n", fd); 
// }

// int main() {
//     int fd = open("example.txt", O_RDONLY);

    
//     if (fd == -1) {
        
//         perror("Failed to open file");
//         return 1;
//     } else {
        
//         printf("File opened successfully. File descriptor: %d\n", fd);
//     }
//     close(fd);
//     return 0;
// }



// int main() 
// {
//     int buffer;
//     int fd = open("numbers.txt", O_RDONLY);

//     if (fd == -1) {
//         perror("Failed to open file");
//         return 1;
//     }

//     ssize_t bytes_read = read(fd, &buffer, sizeof(int));
//     if (bytes_read == -1) {
//         perror("Failed to read from file");
//         close(fd);
//         return 1;
//     }

//     printf("Read integer: %d\n", buffer);

//     close(fd);
//     return 0;
// }




// int main()
// {
//    int fd = open("numbers.bin", O_RDONLY);
//    int buffer;
//    ssize_t bytes_read;
//    while ((bytes_read = read(fd, &buffer, 2)) > 0) 
//    {
//        buffer &= 0xFFFF; // Ensure only the lower 2 bytes are used
//        printf("bytes: %zu\n", bytes_read);
//        printf("number: %i\n", buffer);
//    }
//    close(fd);
//    return 0;
// }


// int c = 20;


// int main()
// {
//     {
//         int c = 500;
//         printf("%d\n",c);
//     }
//     printf("%d\n",c);
//     c = 10;
//     printf("%d\n",c);
//}


// int main() {

//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("example.txt", O_RDONLY);
//     int fd3 = open("numbers.txt", O_RDONLY);    
//     int fd4 = open("file4.txt", O_RDONLY);
//     int fd5 = open("numbers.bin", O_RDONLY);

//     printf("fd1: %d\n", fd1);  
//     printf("fd2: %d\n", fd2);
//     printf("fd3: %d\n", fd3);
//     printf("fd4: %d\n", fd4);
//     printf("fd4: %d\n", fd5);

//     close(fd1);
//     close(fd2);
//     close(fd3);
//     close(fd4);

//     return 0;
// }
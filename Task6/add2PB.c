#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{

    char first_name[256];  // Buffer to store the first name
    int index1 = 0;
    char ch1;

    printf("Enter first name: ");

    // Read characters until a space is encountered or buffer is full
    while ((ch1 = getchar()) != '\n' && ch1 != EOF && index1 < sizeof(first_name) - 2) {
        first_name[index1++] = ch1;
    }
    
    // Null-terminate the string
    first_name[index1] = ' ';
    index1++;
    first_name[index1] = '\0';

    char last_name[256];  // Buffer to store the first name
    int index2 = 0;
    char ch2;

    printf("Enter last name: ");

    // Read characters until a space is encountered or buffer is full
    while ((ch2 = getchar()) != '\n' && ch2 != EOF && index2 < sizeof(last_name) - 2) {
        last_name[index2++] = ch2;
    }
    
    // Null-terminate the string
    last_name[index2] = ',';
    index2++;
    last_name[index2] = '\0';

    char phone[256];  // Buffer to store the first name
    int index3 = 0;
    char ch3;

    printf("Enter phone: ");

    // Read characters until a space is encountered or buffer is full
    while ((ch3 = getchar()) != '\n' && ch2 != EOF && index3 < sizeof(phone) - 2) {
        phone[index3++] = ch3;
    }
    
    // Null-terminate the string
    phone[index3] = '\n';
    index3++;
    phone[index3] = '\0';

    char buffer[1024];
    strcpy(buffer, first_name);
    strcat(buffer, last_name);
    strcat(buffer, phone);

    FILE *file = NULL;
    file = fopen("PhoneBook.txt", "a+");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 1;
    }

    fprintf(file, "%s", buffer);
}
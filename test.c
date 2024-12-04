#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ANSI color codes
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

char *test_1_en(char a[])
{
    int j, k = strlen(a), x = 1;
    for (j = 0; j < k; j++)
    {
        a[j] = a[j] - x++;
        if (x > 5)
            x = 1;
    }
    return a;
}

char *test_1_de(char a[])
{
    int j, k = strlen(a), x = 1;
    for (j = 0; j < k - 1; j++)
    {
        a[j] = a[j] + x++;
        if (x > 5)
            x = 1;
    }
    return a;
}

int main()
{
    char a[10000];
    int choose = 0;

    // Welcome message with color
    printf(CYAN "\nWelcome to the Encryption Tool!\n\n" RESET);
    printf(YELLOW "  1. Encrypt\n" RESET);
    printf(GREEN "  2. Decrypt\n" RESET);
    printf("\n");
    printf(BLUE "Enter your option: " RESET);
    scanf("%d", &choose);
    getchar(); // Consume newline left by scanf

    switch (choose)
    {
    case 1:
    {
        printf(CYAN "\nEncryption Selected.\n" RESET);
        char fname[50];
        printf(BLUE "Enter Filename: " RESET);
        fgets(fname, sizeof(fname), stdin);
        fname[strcspn(fname, "\n")] = '\0'; // Remove trailing newline

        FILE *z = fopen(fname, "r");
        if (z == NULL)
        {
            printf(RED "\nFile not found! Please try again.\n" RESET);
            return 1;
        }

        int j = 0;
        a[j] = fgetc(z);
        while (a[j] != EOF)
        {
            j++;
            a[j] = fgetc(z);
        }
        fclose(z);
        a[j] = '\0';

        FILE *f = fopen(fname, "w");
        if (f == NULL)
        {
            printf(RED "Error writing to file! Try again.\n" RESET);
            return 1;
        }
        fprintf(f, "%s\n", test_1_en(a));
        fclose(f);

        printf(GREEN "\nFile successfully encrypted!\n" RESET);
        break;
    }
    case 2:
    {
        printf(CYAN "\nDecryption Selected.\n" RESET);
        char fname2[50];
        printf(BLUE "Enter Filename: " RESET);
        fgets(fname2, sizeof(fname2), stdin);
        fname2[strcspn(fname2, "\n")] = '\0'; // Remove trailing newline

        FILE *g = fopen(fname2, "r");
        if (g == NULL)
        {
            printf(RED "\nFile not found! Please try again.\n" RESET);
            return 1;
        }

        int j = 0;
        a[j] = fgetc(g);
        while (a[j] != EOF)
        {
            j++;
            a[j] = fgetc(g);
        }
        fclose(g);
        a[j] = '\0';

        FILE *h = fopen(fname2, "w");
        fprintf(h, "%s\n", test_1_de(a));
        fclose(h);

        printf(GREEN "\nFile successfully decrypted!\n" RESET);
        break;
    }
    default:
        printf(RED "\nInvalid option! Please restart the program.\n" RESET);
        break;
    }

    // Exit message
    printf(YELLOW "\nThank you for using the tool. Goodbye!\n" RESET);
    return 0;
}

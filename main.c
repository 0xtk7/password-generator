// gcc -o password-generator main.c
// password-generator

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Characters used to create password
char charPool[75] = {
    'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
    '0','1','2','3','4','5','6','7','8','9',
    '!','"','$','%','^','&','*','(',')','-','_','=','+'
};

void helpMessage() {
    printf("Command structure: ./password-generator argv[1] argv[2]\n\
    argv[1] = -g, -help, -list\n\
    argv[2] = Integer\n\n\
    Commands: \n\n\
    -g = Command used to generage password (requires argv[2]) \n\
    -help = Displays this message \n\
    -list = Lists the characters used in creating the password \n\n\
    Commands are case sensitive meaning \"-G\" will not work\n");

}

void generatePassword(int length) {
    int i = 0;

    time_t t;
    srand((unsigned) time(&t));

    char password[length];
    for (i; i < length; i++) {
        password[i] = charPool[rand() % 75];   
    }
    printf("%s", password);
}

int main(int argc, char *argv[])
{      

    // Throw error if there are less than 2 a
    if (argc < 2) {
        printf("\nError: Too little arguments\nType -help for help\n");
        return 1;
    }

    else if (argc > 3) {
        printf("\nError: Too many arguments\nType -help for help\n");
        return 1;
    }
    
    // Throw error if argv[2] isnt an interger if -g is selected
    if (strcmp(argv[1], "-g") == 0 && atoi(argv[2]) == 0) {
        printf("\nError: argv[2] isn't an integer\n");
        return 1;
    }

    // Help message
    if (strcmp(argv[1], "-help") == 0) {
        helpMessage();
    }

    // Generate password if argv[1] is -g
    else if (strcmp(argv[1], "-g") == 0) {
        generatePassword(atoi(argv[2]));
    }

    // List characters
    else if (strcmp(argv[1], "-list") == 0) {
        printf("\nCharacters: %s\n", charPool);
    }

    return 0;
}

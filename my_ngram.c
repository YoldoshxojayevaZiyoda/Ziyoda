// // #include <stdio.h>

// // int main() 
// // {
// //     char word[100];
// //     int count[26] = {0};  
// //     printf("Enter a word: ");
// //     scanf("%s", word);
// //     for (int i = 0; word[i] != '\0'; i++) 
// //     {
// //         char ch = word[i];
// //         if (ch >= 'a' && ch <= 'z') {
// //             count[ch - 'a']++;
// //         } else if (ch >= 'A' && ch <= 'Z') {
// //             count[ch - 'A']++;
// //         }
// //     }
// //     printf("Letter counts:\n");
// //     for (int i = 0; i < 26; i++) 
// //     {
// //         if (count[i] > 0) {
// //             printf("%c: %d\n", 'a' + i, count[i]);
// //         }
// //     }

// //     return 0;
// // }


// // #include <stdio.h>
// // #include <string.h>

// // int main()
// // {
// //  char str[] = "Hello";
// //  int len = strlen (str);
// //  int i = 0;
// //  printf ("%c\n",str[i]);
// //  printf ("%c\n",str[len - 1]);
// //  return 0;
// // }


// #include <stdio.h>

//         int main() 
//         {
//             char word[100];
//             int count[26] = {0};  
//             printf("Enter a word: ");
//             scanf("%s", word);
//             for (int i = 0; word[i] != '\0'; i++) 
//             {
//                 char ch = word[i];
//                 if (ch >= 'a' && ch <= 'z') {
//                     count[ch - 'a']++;
//                 } else if (ch >= 'A' && ch <= 'Z') {
//                     count[ch - 'A']++;
//                 }
//             }
//             printf("Letter counts:\n");
//             for (int i = 0; i < 26; i++) 
//             {
//                 if (count[i] > 0) {
//                     printf("%c: %d\n", 'a' + i, count[i]);
//                 }
//             }

//             return 0;
//         }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_ngram(int argc, char *argv[]) {


    int counts[256] = {0};
    char *concatenated = NULL;

    for (int i = 1; i < argc; i++) {
        size_t len = strlen(argv[i]);
        concatenated = realloc(concatenated, sizeof(char) * (len + 1));
        strcpy(concatenated, argv[i]);

        for (int j = 0; j < len; j++) {
            counts[(unsigned char)concatenated[j]]++;
        }
    }

    free(concatenated);

    for (int i = 0; i < 256; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", (char)i, counts[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    my_ngram(argc, argv);
    return 0;
}
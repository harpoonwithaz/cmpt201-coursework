#define _POSIX_C_SOURCE 200809l
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *input = NULL;
  size_t len = 0;
  while (1) {
    // Collect user input
    printf("Please enter some text: ");
    if (getline(&input, &len, stdin) != -1) {
      // Check if user just pressed "Enter"
      if (strcmp(input, "\n") == 0) {
        printf("goodbye\n");
        free(input);
        return 0;
      }

      // Tokenize the string
      char *saveptr = NULL;
      char *delim = " ";
      char *tokens = strtok_r(input, delim, &saveptr);
      printf("Tokens:\n");
      while (tokens != NULL) {
        printf("   %s\n", tokens);
        tokens = strtok_r(NULL, " ", &saveptr);
      }
    }
  }
}

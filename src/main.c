#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // Captures the user's command in the "command" variable
  char command[1024];

  while (1)
  {
    printf("$ ");

    fgets(command, sizeof(command), stdin);

    // strcspn counts how many characters you can read in a string before hitting any of the letters you want to avoid.
    // strcspn(command, "\n") finds the position of the first newline.
    // The code then replaces that character with '\0', which marks the end of the string.
    command[strcspn(command, "\n")] = '\0';

    if (strcmp(command, "exit") == 0)
    {
      break;
    }
    // strncmp(a, b, n) compares the first up to n characters of two strings.
    // It returns 0 if those characters match.
    else if (strncmp(command, "echo ", 5) == 0)
    {
      char *remainChar = strchr(command, ' ');
      if (remainChar != NULL)
      {
        printf("%s\n", remainChar + 1);
      }
    }
    else
    {
      printf("%s: command not found\n", command);
    }
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);

  // TODO: Uncomment the code below to pass the first stage
  printf("$ ");

  // Captures the user's command in the "command" variable
  char command[1024];
  fgets(command, sizeof(command), stdin);

  // strcspn counts how many characters you can read in a string before hitting any of the letters you want to avoid.
  command[strcspn(command, "\n")] = '\0';
  printf("%s: command not found", command);

  return 0;
}

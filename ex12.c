#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  if(argc < 2){
    printf("You ony have one argument you suck!\n");
  } else if (argc > 1 && argc < 4) {
    // print the arguments to the screen
    for(i = 1; i < argc; i++) {
      printf("arg %d: %s\n", i, argv[i]);
    }
  } else {
    printf("You have too many arguments\n");
  }

  return 0;
}

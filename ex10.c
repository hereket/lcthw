#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  // go through each string in argv
  // Why am I skipping arv[0]?
  for(i = 1; i < argc; i++){
    printf("arg %d: %s\n", i, argv[i]);
  }

  // let's make out own array of strings
  char *states[] = {
    "California", "Oregon",
    "Washington", "Alabama" 
  };

  int num_states = 4;

  for(i = 0; i < num_states; i++){
    if (i==1) continue;
    printf("states %d: %s\n", i, states[i]);
  };

  return 0;
}

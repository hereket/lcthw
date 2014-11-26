#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;
  char *str = "alfred";
  int strn[] = {1,2,3,4,5,6,7,8,9,10};
  //int str_l = sizeof(*str) / char;

  for(i = 0; i < 110; i++){
    printf("id %d: %d \n", i, (strn+i));
  }
  return 0;
}

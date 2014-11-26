#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays we care about
  int ages[] = {23,42,16,2,122};
  char *names[] = {"Alan", "Frank",
    "Alfred", "Jon", "Max"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using inexing
  for(i = 0; i < count; i++) {
    printf("%s has %d years alive\n",
        names[i], ages[i]);
  }

  printf("-----\n");

  // setup the pointers to the start of the array
  int *cur_age = ages;
  char **cur_name = names;

  // second way using poionters
  for(i = 0; i < count; i++) {
    printf("%s is %d years old\n", 
        *(cur_name + i), *(cur_age+i));
  }

  printf("-----\n");

  // third way, pointers are just arrays
  for(i = 0; i < count; i++) {
    printf("%s is %d years old\n", 
        cur_name[i], cur_age[i]);
  }

  printf("----\n");

  // fourth way, in a complex stupid way
  for(cur_name = names, cur_age = ages;
      (cur_age - ages) < count;
      cur_name++, cur_age++)
  {
    printf("%s is %d years old\n", 
        *cur_name, *cur_age);
  }

  return 0;
}


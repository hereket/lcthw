#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays we care about
  void print_array(int *ages, char **names, int count);

  int ages[] = {23,42,16,2,122};
  char *names[] = {"Alan", "Frank",
    "Alfred", "Jon", "Max"
  };
  // setup the pointers to the start of the array
  int *cur_age = ages;
  char **cur_name = names;
  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using inexing
  print_array( ages, names, count );
  printf("-----\n");




  // fourth way, in a complex stupid way
  for(cur_name = names, cur_age = ages;
      (cur_age - ages) < count;
      cur_name++, cur_age++)
  {
    printf("%s is %d years old\n", 
        *cur_name, *cur_age);
  }

  for(i = 0; i < count; i++) {
    printf("%p is %p years old\n",
        &cur_name[i], &cur_age[i]);
  }


  return 0;
}

void print_array(int *ages, char **names, int count) {
  int i = 0;
  for( i = 0; i < count; i++) {
    printf("%s is \t%d years old\n",
        names[i], ages[i]);
  }
}

#include <stdio.h>
#include <assert.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person Person_create(char *name, int age, int height, int weight)
{
  struct Person who;
  who.name = name;
  who.age = age;
  who.height = height;
  who.weight = weight;

  return who;
}

void Person_print(struct Person who) 
{
  printf("Name: %s\n", who.name);
  printf("\tAge; %d\n", who.age);
  printf("\tHeight; %d\n", who.height);
  printf("\tWidth; %d\n", who.weight);
}

int main()
{
  // Create two people
  struct Person joe = {"Joe Alex", 32, 64, 140};
  struct Person frank = {"Frank Sinatra", 20, 72, 180};

  printf("Joe is at memory %p\n", &joe);
  Person_print(joe);

  printf("Frank is at memory %p\n", &frank);
  Person_print(frank);

  joe.age += 20;
  joe.height -= 2;
  joe.weight += 40;
  Person_print(joe);

  frank.age += 20;
  frank.weight += 20;
  Person_print(joe);

  return 0;
}

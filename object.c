#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "object.h"

int Object_init(void *self)
{
  // do nothing really
  return 1;
}

void Object_describe(void *self)
{
  Object *obj = self;
  printf("%s\n", obj->description);
}

void Object_destroy(void *self)
{
  Object *obj = self;

  if(obj) {
    if(obj->description) free(obj->description);
    free(obj);
  }
}

void *Object_move(void *self, Direction direction)
{
  printf("You cannot go that direction\n");
  return NULL;
}

int Object_attack(void *self, int damage)
{
  printf("You cannot attack that.\n");
  return 0;
}

void *Object_new(size_t size, Object proto, char *description)
{
  // Setup the default functions in case there are not set
  if(!proto.init) proto.init = Object_init;
  if(!proto.describe) proto.describe = Object_describe;
  if(!proto.destroy) proto.destroy = Object_destroy;
  if(!proto.move) proto.move = Object_move;
  if(!proto.attack) proto.attack = Object_attack;

  // this seems weird but we can make a struct of one size,
  // then point a different pointer at it to "cast" it
  Object *el = calloc(1, size);
  *el = proto;

  // copy the discription over
  el->description = strdup(description);

  // initialize it with whatever init it was given
  if(!el->init(el)) {
    // looks like it didn't initiallize properly 
    el->destroy(el);
    return NULL;
  } else {
    // all done we made an object of all type
    return el;
  }
}

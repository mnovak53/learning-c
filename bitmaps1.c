#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheduler1.h"

// TODO
bit_array createBitArray (int times, int position) {
  // implement the function and replace the return line below

 bit_array myArray;
  switch (times){
    case 1:
      if (position > 4) {return 0;}
      myArray = 0b00000001;
      break;
    case 2:
      if (position > 3) {return 0;}
      myArray = 0b00000011;
      break;
    case 3:
      if (position > 2) {return 0;}
      myArray = 0b00000111;
      break;
    case 4:
      if (position > 1) {return 0;}
      myArray = 0b00001111;
      break;
    case 5:
      if (position > 0) {return 0;}
      myArray = 0b00011111;
      break;
  }
  for(int i = 0; i < position; i++)
  {
    myArray = myArray << 1;
  }

  return myArray;
}

// TODO
bitmap * createBitmap (int times, int id) {
  // implement this function and change the following return statement
  if(times<=0 && times<=D) return 0;
  bitmap * map = malloc(sizeof(bitmap));
  map->offer_id = id;

  for(int i=0; i<D; i++){
    map->b[i] = createBitArray(times,i);
}

  return map;
}

/* TODO: insert n in the beginning of list head */
bitmap * insertHead (bitmap * head, bitmap * n) {
  // implement this function and change the following return statement
  n->next = head;
  head = n;
  return head;
}


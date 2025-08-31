#include <stdio.h>
#include <stdlib.h>
#include "scheduler1.h"

int main (int argc, char * argv[]) {
  printf("argv: %s",argv[0]);
  for(int i =0; i<argc; i++){
    printf("argv[%d] = %s\n", i, argv[i]);
  }

  if ( argc < 2 ) {
    printf("Program expects a text file input. Exiting...\n");
    exit(1);
  }
  offer * c = readOffers(argv[1]);
printf("after offer");
  offer * temp = c;
  printf("after temp");
  while ( temp != NULL ) {
    printOffer(temp);
    temp = temp->next;
  }
  printf("after while");
  printf("\n");
  printTable(p);
  printf("\n print");
  
  createSchedule();
  printSchedule();
}

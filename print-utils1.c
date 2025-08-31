#include <stdio.h>
#include "scheduler1.h"

void printOffer (offer * k) {
    if (k == NULL)
        return;

    printf("Offer id: %2d ", k->id);

    printf("Grade: %12s ", k->grade);
    person * t = k->teacher;

    printf("Teacher(s): ");
    while (t != NULL) {
        printf("%10s ", t->name);
        t = t->next;
    }

    t = k->assistant;
    printf("Assistant(s): ");
    while (t != NULL) {
        printf("%10s ", t->name);
        t = t->next;
    }
    printf("\n");
}

void printBinary (char n) {
  if (n == 0) {
    printf("0\n");
    return;
  }
  unsigned int s = 0x0080;
  int i;
  for (i=0; i<8; i++) {
    if (n & s) printf("1");
    else printf("0");
    s = s >> 1;
  }
  printf("\n");
}

void printBitmap (bitmap * m) {

  if ( m == NULL) return;

  printf("Bitmap/Offer id: %2d\n", m->offer_id);
  int i;
  printf("\tBitarrays:\n");
  for ( i=0; i<D; i++ ) {
    printf("\t%d: ", i);
    printBinary(m->b[i]);
  }
}

void printTable(bitmap * t[G][D]) { /* print the bitmap lists of the table */
  if ( t == NULL ) return;

  int i, j;
  for (i=0; i<G; i++)
    for (j=0; j<D; j++) {
      bitmap * tmp = t[i][j];
      while ( tmp != NULL ) {
        printf("Table Entry (Grade Index %d, Times %d)\t", i, j+1);
        printBitmap(tmp);
        tmp = tmp->next;
        printf("");
      }
    }
}

void printOption (option * t) {
  if ( t == NULL ) return;
  while ( t != NULL ) {
      printf("\tOption/Offer id(s): %d", t->offer_id[0]);
      if ( t->offer_id[1] != INVALID_OFFER_ID )
        printf(", %d\n", t->offer_id[1]);
      else
        printf("\n");
      printf("\tSchedule:\n\t\t");
      printBinary(t->a[0]);
      if ( t->a[1] != INVALID_BIT_ARRAY ) {
        printf("\t\t");
        printBinary(t->a[1]);
      }
      t = t->next;
  }
}

void printSchedule () {
  int i;
  for (i=0; i<G; i++) {
    printf("GRADE Index %d\n", i);
    printOption(schedule[i]);
  }
}
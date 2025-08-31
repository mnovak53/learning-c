#include <stdio.h>
#include <stdlib.h>
#include "scheduler1.h"
#define MASK 0x1F  // assuming D == 5, then it covers all D days
//bitmap * p[G][D];
//option * schedule[G];
// TODO
option * optionsForGrade (bitmap * g[D]) {
  printf("it started running");
  option *head = (option *)malloc(sizeof(option));
  option * current = (option *)malloc(sizeof(option));
  if (head == NULL || current == NULL) {
    // Handle memory allocation failure
    exit(EXIT_FAILURE);
}
head->next = NULL;
current->next = NULL;

  printf("Malloc worked");
  if(g[4] != NULL){
    printf("if statement worked");
  head->a[0] = g[4]->b[0];
  head->a[1] = 0;
  printf("assigning the bit array worked");
  head->offer_id[0] = g[4]->offer_id;
  head->offer_id[1] = 0;
  printf("assigning the offer id worked");
  current = head->next;

}

//Check to see if there is teachers willing to work 2 and 3 times to see if there an option for the scedule.
if(g[2] != NULL && g[1] != NULL){
  printf("2 and 1");
  //Take first bitmap postion for the teacher willing to work 2 times.
  option * temp = (option *)malloc(sizeof(option));
  int i = 1;
  temp->a[0] = g[1]->b[0];
  temp->offer_id[0] = g[4]->offer_id;

  //Take the last postion of the teacher willinng to work 3 times.
  while(g[2]->b[i] != 0){
     temp->a[1] = g[2]->b[i];
     i++;
  }
  temp->offer_id[1] = g[2]->offer_id;
  current = temp;
  current = current->next;

//Take first bitmap postion for the teacher willing to work 3 times
  option * temp2 = (option *)malloc(sizeof(option));
  i = 1;
  temp2->a[0] = g[2]->b[0];
  temp2->offer_id[0] = g[2]->offer_id;

  //Take the last postion of the teacher willinng to work 2 times.
  while(g[1]->b[i] != 0){
     temp2->a[1] = g[1]->b[i];
     i++;
  }
  temp2->offer_id[1] = g[1]->offer_id;
  current = temp2;
  current = current->next;
  
  //Freeing the allocated memory from the heep.
  free(temp2);
  free(temp);
}
if(g[0] != NULL && g[3] != NULL){
  printf("0 and 3");
  option * temp = (option *)malloc(sizeof(option));
  int i = 1;
  temp->a[0] = g[0]->b[0];
  temp->offer_id[0] = g[0]->offer_id;
  while(g[3]->b[i] != 0){
     temp->a[1] = g[3]->b[i];
     i++;
  }
  temp->offer_id[1] = g[3]->offer_id;
  current = temp;
  current = current->next;

  option * temp2 = (option *)malloc(sizeof(option));
  i = 1;
  temp2->a[0] = g[3]->b[0];
  temp2->offer_id[0] = g[3]->offer_id;
  while(g[0]->b[i] != 0){
     temp2->a[1] = g[0]->b[i];
     i++;
  }
  temp2->offer_id[1] = g[0]->offer_id;
  current = temp2;
  current = current->next;
  free(temp2);
  free(temp);
  free(head);
  free(current);

}

  return head;
}


void createSchedule () {
  int i;
  printf("reat schedule ran");
  for (i=0; i<G; i++) {
    schedule[i] = optionsForGrade(p[i]);
  }
}


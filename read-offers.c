#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "scheduler1.h"
#include <ctype.h>


int gradeIndex(char * s) {

  if ( s == NULL ) return -1;

  if ( strstr("PreK\0", s) != NULL )
    return 0;
  if ( strstr("K-1st\0", s) != NULL )
    return 1;
  if ( strstr("2nd\0", s) != NULL )
    return 2;
  if ( strstr("3rd-4th\0", s) != NULL )
    return 3;
  if ( strstr("5th-6th\0", s) != NULL )
    return 4;
  if ( strstr("Junior High\0", s) != NULL )
    return 5;
  if ( strstr("High School\0", s) != NULL )
    return 6;

  return -2;
}

char* trim(char* str) {
    // Trim leading spaces
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Trim trailing spaces
    char* end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *(end + 1) = '\0';

    return str;
}

// TODO: Add to your implementation from Homework 7
// to create the p table
// Use functions from the bitmaps.c file
offer * readOfferLine (char * line, int id) {
   offer * newOffer = malloc(sizeof(offer));
    if (newOffer == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    // Allocate memory for teacher and assistant structs and set their names
    newOffer->teacher = malloc(sizeof(person));
    newOffer->assistant = malloc(sizeof(person));
    person * exteach1 = malloc(sizeof(person));
    person * exteach2 = malloc(sizeof(person));
    person * exassistant1 = malloc(sizeof(person));
    person * exassistant2 = malloc(sizeof(person));
    if (newOffer->teacher == NULL || newOffer->assistant == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    newOffer->id = id;
    char name[L];
    char grade[L];
    char teacher1[L];
    char teacher2[L];
    char asteacher1[L];
    char asteacher2[L];

  
   char* headteacher1 = strtok(line, ":,");
    char* grades = strtok(NULL, ":,");
    strncpy(newOffer->grade, trim(grades), L);

    int time = atoi(strtok(NULL, ":,"));
    newOffer->times = time;
    char* assistantteach = strtok(NULL, ":,");
    


  char* teach = strtok(headteacher1, "/");
  if (teach != NULL) {
    strncpy(exteach1->name, trim(teach), L);
    newOffer->teacher->next = exteach1;

    teach = strtok(NULL, "/");

    if (teach != NULL) {
        strncpy(exteach2->name, trim(teach), L);
        exteach1->next = exteach2;
    }
    else {
        exteach1->next = NULL;
    }
}
     else {
      exteach1->next = NULL;
    }   

    char* teach2 = strtok(assistantteach, "/");
    if (teach2 != NULL) {
        strncpy(exassistant1->name, trim(teach2), L);
        newOffer->assistant->next = exassistant1;
        teach2 = strtok(NULL, "/");
        if (teach2 != NULL) {
            strncpy(exassistant2->name, trim(teach2), L);
            exassistant1->next = exassistant2;
        }
        else {
        exassistant1->next = NULL;
        }
    }
    else {
        exassistant1->next = NULL;
    }
    
    return newOffer;
}

// Your implementation from Homework 7
offer * readOffers (char * filename) {
  FILE *file = fopen(filename, "r");
    size_t len = 0;
    ssize_t nread;
    char *line = NULL;
    offer *head = NULL;
    int id = 0;
    int index;

    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    
    while ((nread = getline(&line, &len, file)) != -1) {
              offer *newOffer = readOfferLine(line, id);
              if (newOffer != NULL && line != NULL && newOffer->times != 0) {
            newOffer->next = head;
            head = newOffer;
            
            printf("%p \n", head);
            
            index = gradeIndex(newOffer->grade);
            printf("%d \n", index);
            
            if (index >= 0 && index < G && newOffer->times > 0 && newOffer->times <= D) {
                if (p[index][newOffer->times - 1] == NULL) {
                    p[index][newOffer->times - 1] = createBitmap(newOffer->times, id);
                } else {
                    p[index][newOffer->times - 1] = insertHead(p[index][newOffer->times - 1], createBitmap(newOffer->times, id));
                }
            } else {
                // Handle the case when indices are out of bounds
            }
        } else {
            // Handle the case when newOffer or line is NULL or times is 0
            // You might want to log an error or take appropriate action
        }
    id++;

        

}
    
    free(line);
    fclose(file);
    return head;
}


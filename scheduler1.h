#ifndef SCHED_H
#define SCHED_H

#define L 50 // maximum number of characters in a name
#define D 5 // number of days of instruction in the schedule
#define H 1 // number of hours per day of instruction
#define G 7 // number of grades

#define INVALID_BIT_ARRAY 0xE0 // assuming D == 5
#define INVALID_OFFER_ID -1

typedef struct person_struct {
    char name[L];
    struct person_struct * next;
} person;

typedef struct teaching_offer {
    int id; // unique identifier for offer
    int times;
    char grade[L];
    person * teacher; // one or more lead teachers
    person * assistant; // one or more assistants
    struct teaching_offer * next;
} offer;

typedef unsigned char bit_array; // D*H should be less than 8

typedef struct bitmap_struct {
    int offer_id;
    bit_array b[D];
    struct bitmap_struct * next;
} bitmap;

 bitmap * p[G][D]; // global variable
// the table should contain a list of bitmaps corresponding to
// a specific grade level and number of times in availability

// combinations of up to two offers allowed
typedef struct schedule_option_for_grade {
    int offer_id[2];
    bit_array a[2];
    struct schedule_option_for_grade * next;
} option;

extern option * schedule[G]; // global variable
// should contain scheduling options for each grade

// defined in print-utils.c:
void printOffer (offer * k);
void printBinary (char n);
void printBitmap (bitmap * m);
void printTable (bitmap * t[G][D]);
void printOption (option * t);
void printSchedule ();

// defined in bitmaps.c:
bitmap * createBitmap (int times, int id);
bitmap * insertHead (bitmap * head, bitmap * n);

//defined in read-offers.c:
offer * readOffers (char * filename);

//defined in scheduler.c:
option * optionsForGrade (bitmap * g[D]);
void createSchedule ();

#endif //SCHED_H

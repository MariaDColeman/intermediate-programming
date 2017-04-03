/*
File: functions.h

Homework 5

600.120 Spring 2017

Maria Coleman

date due: 4/2/17

*/

struct individualCourse {
  char courseDiv[3];
  char courseDep[4];
  char courseNum[4];
  float credits;
  char courseTitle[33];
};

typedef struct transcriptCourse {
  struct transcriptCourse *next;
  struct individualCourse *course;
  char semester[7];
  char grade[3];
} transcriptCourse;


int numLines(FILE *filehandleIN);
struct individualCourse* getValidInput(struct individualCourse *catalog, int len);
void clear(void);
int semesterLessThanCheck(char sem1[], char sem2[]);
void insertSorted(transcriptCourse **head, struct individualCourse * course, char semester[], char grade[]);
void removeSorted(transcriptCourse** phead, struct individualCourse * course, char semester[]);
int semesterGreaterThanCheck(char sem1[], char sem2[]);
void removeSortedOneCourse(transcriptCourse** phead, struct individualCourse * course);
void printList(transcriptCourse *head);
transcriptCourse* create(struct individualCourse *course, char semester[], char grade[]);
/*
File: hw5.c

Homework 5

600.120 Spring 2017

Maria Coleman

date due: 4/2/17

*/




#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include "prompts.h"
#include "functions.h"




int main(int argc, char* argv[]) {

//confirm that a command-line argument is present (and only the name of the catalog text input file)
    if (argc != 2) {
        printf("Usage: hw5 catalog.txt\n");
        return 1; //exit program because improper number of command-line arguments present
    }

//declare a char array to hold the command-line argument string
//ensure last char is null character
    int length = strlen(argv[1]);
    char inputFileName[length+1];
    strcpy(inputFileName, argv[1]);
    inputFileName[length] = '\0';

    FILE *filehandleIN;

//open the input file in "read" mode
    filehandleIN = fopen(inputFileName, "r");
    if (!filehandleIN) {
        printf("Error: Unable to open input catalog file\n");
        return 1;
    }


    int len = numLines(filehandleIN);


    struct individualCourse * catalog;
    catalog = malloc(sizeof(struct individualCourse) * len);

    for(int i=0; i<len; i++) {
        char tempStr[3] = {getc(filehandleIN), getc(filehandleIN), '\0'};

        strcpy((catalog[i].courseDiv), tempStr);
        getc(filehandleIN); //read the period character
        char tempStr2[4] = {getc(filehandleIN), getc(filehandleIN), getc(filehandleIN), '\0'};

        strcpy((catalog[i].courseDep), tempStr2);
        getc(filehandleIN); //read the period character
        char tempStr3[4] = {getc(filehandleIN), getc(filehandleIN), getc(filehandleIN), '\0'};

        strcpy((catalog[i].courseNum), tempStr3);
        fscanf(filehandleIN, "%f ", &(catalog[i].credits));
        fgets(catalog[i].courseTitle, 33, filehandleIN);

    }



    transcriptCourse* head = NULL;


    char menuInput;
    char nextChar;
    struct individualCourse * newIndividualCourse;

    int valid=0;
    char semesterTemp[7];
    char gradeTemp[3];
    double gpa;
    do {
        menu_prompt();
        scanf(" %c%c", &menuInput, &nextChar);

        while(nextChar != '\n') {
            while(getchar() != '\n');
            menu_prompt();
            scanf("%c%c", &menuInput, &nextChar);
        }

        switch(menuInput) {
            int gotostepb = 0;

        case 'q':
        case 'Q':

            free(catalog);

            transcriptCourse *temp;
            while (head != NULL) {
                temp = head;
                head=head->next;
                free(temp);
            }
            free(head);
            break;

//display the catalog:
        case '1':
            for (int i = 0; i < len; i++) {
                printf("%s.%s.%s %.1f %s\n", catalog[i].courseDiv, catalog[i].courseDep, catalog[i].courseNum, catalog[i].credits, catalog[i].courseTitle);
            }
            break;

//display information on a specific course in the catalog:
        case '2':

            newIndividualCourse = getValidInput(catalog, len);
            printf("%s.%s.%s %.1f %s\n", newIndividualCourse->courseDiv, newIndividualCourse->courseDep, newIndividualCourse->courseNum, newIndividualCourse->credits, newIndividualCourse->courseTitle);

            break;

//update the title of a specific course:
        case '3':
            //steps b-d in separate function
            newIndividualCourse = getValidInput(catalog, len);
            new_title_prompt();
            char inputStr[34];
            fgets(inputStr, 34, stdin);
            int numOfCharacters = strlen(inputStr);
            while (numOfCharacters >= 33) {
                invalid_input_msg();
                new_title_prompt();
                fgets(inputStr, 34, stdin);
                numOfCharacters = strlen(inputStr);
            }
            char inputStr2[33];
            strncpy(inputStr2,inputStr,33);
//update corresponding course's entry in the catalog with new title
            for (int i = 0; i<len; i++) {
                if ((strcmp((catalog[i].courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((catalog[i].courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((catalog[i].courseNum),newIndividualCourse->courseNum) == 0)) {
                    strcpy(catalog[i].courseTitle, inputStr2);
                }
            }


            course_updated_msg();


            break;

//update the credit assignment of a specific course:
        case '4':
            //steps b-d in separate function
            newIndividualCourse = getValidInput(catalog, len);
            int success = 0;
            float inputCredits;
            do {
                new_credit_prompt();
                inputCredits = 0;
                success = 0;
                success  = fscanf(stdin, " %f", &inputCredits);
                if (!success) {
                    invalid_input_msg();
                }

            } while (!success);

//update corresponding course's entry in the catalog with new title
            for (int i = 0; i<len; i++) {
                if ((strcmp((catalog[i].courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((catalog[i].courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((catalog[i].courseNum),newIndividualCourse->courseNum) == 0)) {

                    catalog[i].credits = inputCredits;
                    newIndividualCourse->credits = catalog[i].credits;
                }
            }


            course_updated_msg();

            break;


//add a course to the student transcript:
        case '5':

            gotostepb = 0;


            do {


                gotostepb=0;
                //steps b-d in separate function


                newIndividualCourse = getValidInput(catalog,len);

                valid = 0;

                while (valid == 0) {
                    valid = 1;

                    semester_prompt();
                    char stringTemp[7] = {'0', '0', '0', '0', '0', '0', '\0'};

                    int cond = 1;
                    char c;
                    for (int i=0; (cond && (i<6)) == 1; i++) {
                        c = getc(stdin);
                        if (c == '\n') {
                            valid = 0;
                            cond = 0;
                        }
                        else {
                            stringTemp[i] = c;
                        }
                    }


                    if (valid != 0) {

                        if (getc(stdin) != '\n') {
                            valid = 0;
                            clear();
                        }

                        strcpy(semesterTemp, stringTemp);


                        for (int i=0; i<4; i++) {
                            if (isdigit(semesterTemp[i])==0) {
                                valid = 0;
                            }
                        }

                        if (semesterTemp[4] != '.') {
                            valid = 0;
                        }

                        semesterTemp[5] = toupper(semesterTemp[5]);
                        if (semesterTemp[5] != 'F' && semesterTemp[5] != 'S') {
                            valid = 0;
                        }

                    }

                } //end of loop to get proper semester format

                valid = 0;

                while(valid == 0) {
                    valid = 1;
                    grade_prompt();
                    char tempString[3] = {'0','0','\0'};
                    int cond = 1;
                    char c;
                    for (int i=0; (cond && (i<2)) == 1; i++) {
                        c=getc(stdin);
                        if (c == '\n') {
                            valid = 0;
                            cond = 0;
                        }
                        else {
                            tempString[i] = c;
                        }
                    }
                    if (valid != 0) {

                        if (getc(stdin) != '\n') {
                            valid = 0;
                            clear();
                        }

                        strcpy(gradeTemp, tempString);

                        gradeTemp[0] = toupper(gradeTemp[0]);
                        int validInv = 0;
                        switch(gradeTemp[0]) {
                        case 'A':
                        case 'B':
                        case 'C':
                        case 'D':
                        case 'F':
                        case 'I':
                        case 'S':
                        case 'U':
                            validInv = 1;
                            break;
                        default:
                            validInv = 0;
                            break;
                        }
                        valid = valid*validInv;
                        int validInv2 = 0;
                        switch(gradeTemp[1]) {
                        case '+':
                        case '-':
                        case '/':
                            validInv2 = 1;
                            break;
                        default:
                            validInv = 0;
                            break;
                        }
                        valid = valid*validInv2;
                    }

                } // end of loop to get proper grade format



                transcriptCourse *e2;

//check if the same course with the same semester already exists in the list
                int exists = 0;
                int skip2=1;
                if (head == NULL) {
                    exists=0;
                    head = create(newIndividualCourse, semesterTemp, gradeTemp);
                    skip2=0;

                }
                else {
                    for(e2=head; (e2)!=NULL; e2=e2->next) {

                        if ((strcmp((e2->course->courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((e2->course->courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((e2->course->courseNum),newIndividualCourse->courseNum) == 0) && (strcmp((e2->semester),semesterTemp) == 0)) {
                            exists = 1;
                        }
                    }

                    if (exists == 1) {
                        duplicate_course_msg();
                        gotostepb = 1;
                    }

                }

                if (!gotostepb) {
                    if (skip2) {
                        transcriptCourse** headPtr = &head;
                        insertSorted(headPtr, newIndividualCourse, semesterTemp, gradeTemp);
                    }
                    transcript_updated_msg();
                }

            } while (gotostepb);


            break;


//remove a course from the student transcript:
        case '6':

            gotostepb = 0;
            int exists = 0;

            do  {
                //steps b-d in separate function
                newIndividualCourse = getValidInput(catalog, len);

//check if the course exists in the catalog
                exists = 0;

                if (!head) {
                    exists=0;
                }
                transcriptCourse *e;

                for(e=head; (e)!=NULL; e=e->next) {
                    if ((strcmp((e->course->courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((e->course->courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((e->course->courseNum),newIndividualCourse->courseNum) == 0)) {
                        exists += 1;
                    }
                }

                if (exists == 0) {
                    course_absent_msg();
                    gotostepb = 1;
                }

            } while (gotostepb);

            int skip = 0;

            if (exists == 1) {
                transcriptCourse **headPtr2= &head;
                removeSortedOneCourse(headPtr2, newIndividualCourse);
                transcript_updated_msg();
                skip = 1;
            }

            if (!skip) {
                int valid = 0;

                int courseTaken = 0;
                while ((valid == 0) || (courseTaken == 0)) {
                    valid = 1;

                    semester_prompt();

                    char stringTemp[7] = {'0', '0', '0', '0', '0', '0', '\0'};

                    int cond = 1;
                    char c;
                    for (int i=0; (cond && (i<7)) == 1; i++) {
                        c = getc(stdin);
                        if (c == '\n') {
                            valid = 0;
                            cond = 0;
                        }
                        else {
                            stringTemp[i] = c;
                        }
                    }



                    if (valid != 0) {

                        if (getc(stdin) != '\n') {
                            valid = 0;
                            clear();
                        }

                        char semesterTemp[7];
                        strcpy(semesterTemp, stringTemp);


                        for (int i=0; i<4; i++) {
                            if (isdigit(semesterTemp[i])==0) {
                                valid = 0;
                            }
                        }

                        if (semesterTemp[4] != '.') {
                            valid = 0;
                        }

                        semesterTemp[5] = toupper(semesterTemp[5]);
                        if (semesterTemp[5] != 'F' && semesterTemp[5] != 'S') {
                            valid = 0;
                        }

                        transcriptCourse *e;
                        for(e=head; (e)!=NULL; e=e->next) {
                            if ((strcmp((e->course->courseDiv),newIndividualCourse->courseDiv) == 0) && (strcmp((e->course->courseDep),newIndividualCourse->courseDep) == 0) && (strcmp((e->course->courseNum),newIndividualCourse->courseNum) == 0)) {
                                if(strcmp((e->semester),semesterTemp) == 0) {
                                    courseTaken=1;
                                }
                            }
                        }

                    }

                } //end of loop to get proper semester format and check if course wa taken in that semester

//Delete the specific course from the transcript list
                transcriptCourse** headPtr2 = &head;
                removeSorted(headPtr2, newIndividualCourse, semesterTemp);

            }

            break;

//display the current transcript:
        case '7':
            if (head == NULL) {
                empty_transcript_msg();
            }
            else {
                printList(head);

            }
            break;

//display information about a specific course in the transcript:
        case '8':

            gotostepb=0;
            int exists2=0;

            do {
                newIndividualCourse = getValidInput(catalog, len);

                exists2 = 0;

                if (!head) {
                    exists2 = 0;
                }
                transcriptCourse *e;

                for(e=head; (e)!=NULL; e=e->next) {
                    if ((strcmp((e->course->courseDiv),newIndividualCourse->courseDiv)==0) && (strcmp((e->course->courseDep),newIndividualCourse->courseDep)==0) && (strcmp((e->course->courseNum),newIndividualCourse->courseNum)==0)) {
                        exists2 +=1;
                        printf("%s %s\n", e->semester, e->grade);
                    }
                }
                if(exists2 == 0) {
                    course_absent_msg();
                    gotostepb = 1;
                }

            } while (gotostepb);



            break;

//compute the cumulative GPA for the student:
        case '9':


            if (head==NULL) {
                gpa = 0;
            }
            else {
                transcriptCourse *e;
                double points = 0;
                double pointSum = 0;
                double creditSum = 0;
                for(e=head; (e)!=NULL; e=e->next) {
                    if(((e->grade)[0] != 'I')&&((e->grade)[0] != 'S')&&((e->grade)[0] != 'U')) {
                        switch((e->grade)[0]) {
                        case 'A':
                            points = 4;
                            break;
                        case 'B':
                            points = 3;
                            break;
                        case 'C':
                            points = 2;
                            break;
                        case 'D':
                            points = 1;
                            break;
                        case 'F':
                            points = 0;
                            break;

                        }//end of switch

                        //only add 0.3 for a + if its not an A or F
                        if(((e->grade)[0]!='A')&&((e->grade)[0]!='F')&&((e->grade)[1]=='+')) {
                            points += 0.3;
                        }
                        //only subtract 0.3 for a - if its not a D or F
                        if(((e->grade)[0]!='D')&&((e->grade)[0]!='F')&&((e->grade)[1]=='-')) {
                            points -= 0.3;
                        }

                        pointSum += points * (e->course->credits);
                        creditSum += (e->course->credits);
                    }


                }
                //free(e);

                gpa = pointSum / creditSum;
            }
            gpa_msg(gpa);

            break;

        default:
            break;

        } //end of switch statement

    } while ((menuInput != 'q') && (menuInput != 'Q')); //the menuInput variable is equal to Q or q when the user wants to quit



    fclose(filehandleIN);
    filehandleIN = NULL;

    return 0;
} //end of main

/* 
Program Name: Project3_MatthewBlanchard.c
Programmer: Matthew Blanchard
Class: CS 3335 
Project: 03
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

struct Line {
    struct Point *a;
    struct Point *b;
    float length;
};

float computeDistance (int x1, int x2, int y1, int y2) {
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

struct Line* readFile(char file_name[], int *n) {

    struct Line *lines;
    lines = (struct Line*)malloc(*n * sizeof(struct Line));
    printf("Array of size %d created", *n);
    printf("Data read");
    return lines;

}

void computeLengths(struct Line *lines, int n) {
    printf("Computing lengths...");

    printf("Length computation completed");
}

void saveLengths(struct Line *lines, int n, char file_name[]) {
    printf("Saving lengths...");
    
}

int main(int argc, char *argv[]) {
    FILE *fp;
    
    return 0;
}
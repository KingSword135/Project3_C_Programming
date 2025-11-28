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
    struct Point a;
    struct Point b;
    float length;
};

float computeDistance (int x1, int x2, int y1, int y2) {
    return sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
}

struct Line* readFile(char file_name[], int *n) {

    FILE *fp;
    fp = fopen("test.txt","r");
    struct Line *lines;

    if (fp == NULL) {
        printf("Guess there as an issue opening the file.");
        return NULL;
    }

    fscanf(fp,"%d",n);

    lines = (struct Line*)malloc(*n * sizeof(struct Line));
    if (lines == NULL) {
        printf("Guess there as an issue mallocing.");
        return NULL;
    }
    printf("Array of size %d created\n", *n);
    for (int i = 0; i < *n; ++i) {
        fscanf(fp,"%d %d %d %d",&lines[i].a.x,&lines[i].a.y,&lines[i].b.x,&lines[i].b.y);
    }
    fclose(fp);
    printf("Data read");
    return lines;

}

void computeLengths(struct Line *lines, int n) {
    printf("\nComputing lengths...");
    for (int i = 0; i < n; ++i) {
        lines[i].length = computeDistance(lines[i].a.x,lines[i].b.x,lines[i].a.y,lines[i].b.y);
    }
    printf("\nLength computation completed");
}

void saveLengths(struct Line *lines, int n, char file_name[]) {
    printf("\nSaving lengths...");
    FILE *fp;
    fp = fopen(file_name,"w");
    if (fp == NULL) {
        printf("\nGuess there as an issue opening the file.");
        return;
    }
    for (int i = 0; i < n; ++i) {
        fprintf(fp,"%.1f",lines[i].length);
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {

    int num;
    struct Line* lineArray = readFile("test.txt",&num);
    int length = sizeof(lineArray) / sizeof(struct Line);
    computeLengths(lineArray,length);
    saveLengths(lineArray,length,"lengths_Matthew_Blanchard.txt");

    return 0;
}
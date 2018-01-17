#include<stdio.h>
#include<stdlib.h>


long int f(int n);//factorial
int nCr(int n, int r);//to calculate the element at any location in the triangle

int* createLine(int n);//allocate space in an array of n integers
int** createTriangle(int n);//make a triangle. Use the createLine function
int* fillLine(int* line, int n);//fill up the nth row
int** fillTriangle(int** tr, int n);//fill up an empty triangle
void printKthLine(int* line, int k, int total);//print the kth line with appropriate spaces
void printTr(int** tr, int n);//print the triangle

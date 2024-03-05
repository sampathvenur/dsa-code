/*
Design and implement a Program in C on Frequency Histogram, that builds a frequency array for
data values in the range 1 to n and then prints their histogram.
The Program should,
a) Read, store and print the data in an array.
b) Analyse the data in the array, one element at a time. Add 1 to the corresponding element
in a frequency array based on the data value.
c) Print a histogram using asteriods for each occurence of an element.
*/
#include <stdio.h>
#include <stdlib.h>

int a[100], i, j, k, n;
int frequency[10] = {0};

void getdata();
void printdata();
void makefrequency();
void makeHistogram();

// main() function
void main() {
    getdata();
    printdata();
    makefrequency();
    makeHistogram();
}


// Function to take input from user
void getdata() {
    printf("Enter how many number of array elements: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Array is empty\n");
        exit(0);
    }
    printf("Enter %d elements between the range 0-9\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}


// Function to print the data taken from the user
void printdata() {
    printf("The array elements are\n");
    for (int i = 0; i < n; i++)
        printf("%d\t", a[i]);
}


// Function to calculate the frequency of user entered data
void makefrequency() {
    for (i = 0; i < 10; i++) {
        for (j = 0; j < n; j++) {
            if (a[j] == i)
                frequency[i]++;
        }
    }
}


// Function to print the histogram
void makeHistogram() {
    printf("\nFrequncy Histogram is: \n");
    printf("------Histo Frequency------\n");

    for (i = 0; i < 10; i++) {
        printf("\n[%d] ", i);
        for (j = 0; j < frequency[i]; j++) {
            printf("*\t");
        }
        printf("\n");
    }
}
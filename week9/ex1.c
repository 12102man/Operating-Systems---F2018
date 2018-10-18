#include <stdio.h>
#include <stdlib.h>


struct Page {
    int counter;
    int frameNumber;
};


int isInTheList(struct Page *pageTable, int pageNumber, int size) {
    for (int i = 0; i < size; i++) {
        if (pageTable[i].frameNumber == pageNumber) {
            return i;
        }
    }
    return -1;
}

int getOldestPage(struct Page *pageTable, int size) {
    int minCounter = -1;
    int page = -1;
    for (int i = 0; i < size; i++) {
        if (pageTable[i].counter < minCounter) {
            minCounter = pageTable[i].counter;
            page = i;
        }
    }
    return page;
}

int main(int argc, char **argv) {
    int numberOfPageFrames = atoi(argv[1]);
    int counter = 0;
    FILE *fp;
    char buf[10];

    int miss, hit = 0;


    // Opening file
    fp = fopen("/Users/mikhailtkachenko/CLionProjects/untitled1/input.txt", "r");

    // Creating a page table (array of Page structs)
    struct Page *pageTable = malloc(sizeof(struct Page) * numberOfPageFrames);


    // Reading words
    while (fscanf(fp, "%s", buf) == 1) {
        // Getting number of page table
        int readPageFrameNumber = atoi(buf);

        // Getting index of read page in page table, -1 otherwise
        int listNumber = isInTheList(pageTable, readPageFrameNumber, counter);

        // If it's in the list, bitshift counter to 1
        if (listNumber != -1) {
            hit++;

            for (int i = 0; i < counter; i++) {
                pageTable[i].counter >>= 1;
            }
            pageTable[listNumber].counter = pageTable[listNumber].counter | 1 << (sizeof(int) - 1);


        } else {
            // If not, create a page and replace
            miss++;
            struct Page newPage;
            newPage.counter = 0;
            newPage.frameNumber = readPageFrameNumber;

            if (counter < numberOfPageFrames) {
                pageTable[counter] = newPage;
                counter++;
            } else {
                pageTable[getOldestPage(pageTable, counter)] = newPage;
            }
        }

    }
    printf("%d hits \n%d misses\n\nhit/miss: %f", hit, miss, (double) hit/miss);


}
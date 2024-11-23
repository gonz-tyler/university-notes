#include <stdio.h>

/*
FIFO (First-In-First-Out):
  - Pages are replaced in the order they entered memory.
  - The front pointer tracks which page to replace, and when a page fault occurs, 
    the front pointer moves forward (with wrap-around) to simulate the queue-like behavior.
*/

void fifo(int pages[], int n, int frames) {
    int frame[frames], front = 0, page_faults = 0;

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < frames; i++) frame[i] = -1;

    // Iterate through each page in the page reference string
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;  // Page is found in one of the frames
                break;
            }
        }

        // If the page is not found in the frame, a page fault occurs
        if (!found) {
            frame[front] = pages[i];  // Place the current page into the front frame
            front = (front + 1) % frames;  // Move the "front" index forward in a circular manner
            page_faults++;  // Increment the page fault count
        }
    }
    printf("Page Faults: %d\n", page_faults);  // Print the total number of page faults
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};  // Page reference string
    int n = sizeof(pages) / sizeof(pages[0]);  // Length of the page reference string
    int frames = 3;  // Number of frames available in memory

    // Run FIFO page replacement algorithm
    fifo(pages, n, frames);
    return 0;
}

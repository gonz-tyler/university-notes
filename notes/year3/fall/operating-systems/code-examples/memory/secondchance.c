#include <stdio.h>

/*
Second Chance:
  - A variation of FIFO with a "second chance" for pages. Pages are only replaced if their reference bit is 0.
  - When a page is accessed, its reference bit is set to 1, and when a page fault occurs, 
    if a page has a reference bit of 1, it gets a "second chance" before being replaced.
*/

// Function to implement the Second Chance Page Replacement algorithm
void second_chance(int pages[], int n, int frames) {
    int frame[frames], ref[frames], front = 0, page_faults = 0;

    // Initialize all frames to -1 (empty) and reference bits to 0 (not recently used)
    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        ref[i] = 0;
    }

    // Iterate through each page in the page reference string
    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;  // Page is found in one of the frames
                ref[j] = 1; // Set reference bit to 1 (page was recently used)
                break;
            }
        }

        // If the page is not found in the frame, a page fault occurs
        if (!found) {
            // Look for a page with reference bit 0 (not recently used)
            while (ref[front] == 1) {
                ref[front] = 0;  // Set reference bit to 0, indicating it's been given a "second chance"
                front = (front + 1) % frames;  // Move the "front" index forward in a circular manner
            }

            // Replace the page at the front index with the new page
            frame[front] = pages[i];
            ref[front] = 1;  // Set reference bit to 1 (page was recently used)
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

    // Run Second Chance page replacement algorithm
    second_chance(pages, n, frames);
    return 0;
}

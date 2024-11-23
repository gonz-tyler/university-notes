#include <stdio.h>

/*
LRU (Least Recently Used):
  - Pages that haven't been used for the longest time are replaced when a page fault occurs.
  - The time array tracks the last access time of each page, and find_lru() selects the page with the oldest access time.
*/

// Function to find the index of the Least Recently Used (LRU) page
int find_lru(int time[], int n) {
    int min = time[0], pos = 0; // Initialize with the first element as the minimum
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {  // Find the page with the least recent access time
            min = time[i];
            pos = i;
        }
    }
    return pos;  // Return the index of the least recently used page
}

void lru(int pages[], int n, int frames) {
    int frame[frames], time[frames], page_faults = 0, count = 0;

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < frames; i++) frame[i] = -1;

    // Iterate through each page in the page reference string
    for (int i = 0; i < n; i++) {
        int found = 0;
        
        // Check if the page is already in one of the frames
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;       // Page found in frame
                time[j] = count++; // Update the time for the page
                break;
            }
        }

        // If the page is not found in the frame, a page fault occurs
        if (!found) {
            int pos = find_lru(time, frames);  // Find the least recently used page
            frame[pos] = pages[i];             // Replace it with the current page
            time[pos] = count++;               // Update the time of this page
            page_faults++;                      // Increment the page fault count
        }
    }
    printf("Page Faults: %d\n", page_faults);  // Print the total number of page faults
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};  // Page reference string
    int n = sizeof(pages) / sizeof(pages[0]);  // Length of the page reference string
    int frames = 3;  // Number of frames available in memory

    // Run LRU page replacement algorithm
    lru(pages, n, frames);
    return 0;
}

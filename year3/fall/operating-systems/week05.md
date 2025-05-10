# Week 5: Paging and Virtual Memory Management

## Notes

---

**Page Table of a Process**
file:///home/gonz/Pictures/Screenshots/Screenshot%20from%202024-11-23%2016-29-51.png

**Page Table and Virtual Memory Concepts**

- Page Table: Maps logical pages of a process to physical frames in memory.
  - Contains entries for each page, including frame number.
  - Size Considerations:
    - Large address spaces (e.g., 32-bit or 64-bit) result in massive page tables.
      - Page tables may be paged themselves if memory is insufficient.
- Issues with Page Tables:
  - Can grow very large.
  - Paging the page table can result in additional page faults.

**Page Table Management Approaches**

1. Hierarchical Page Tables:
  - Divide page tables into smaller, hierarchical structures.
  - Splits virtual address into parts: root index, table index, and page offset.
  - May result in extra page faults for loading hierarchical structures.
2. Inverted Page Tables:
  - Single table for all processes; indexed by physical frame.
  - Uses hashing to map pages; includes process ID, page number, and offset.
  - Fixed size based on physical memory, but hash collisions can occur.
3. Translation Lookaside Buffer (TLB):
  - A small, fast cache for page table entries.
  - Reduces overhead by storing frequently accessed entries.
  - Hit: Quick lookup; Miss: Slower, fetch from page table.
  - Reloaded on context switches.

**Virtual Memory Design Concepts**

- Fetch Policy:
  - Demand Paging: Loads pages only when accessed, efficient but high initial page faults.
  - Prepaging: Anticipates future needs, loads multiple pages.
- Principle of Locality:
  - Memory references cluster spatially or temporally.
  - Explains why demand paging stabilises performance after startup.
- Replacement Policy:
  - Selects which page to replace when memory is full.
  - Aims to minimise page-fault rate.

**Page Replacement Algorithms**

1. Optimal Policy (OPT):
  - Replaces the page with the longest time until its next use.
  - Not implementable but serves as a benchmark.
2. Least Recently Used (LRU):
  - Replaces the page least recently accessed.
  - Good performance but costly to implement (requires timestamps or stacks).
  - Approximation: Use "reference bits" or periodic resets.
3. First-In-First-Out (FIFO):
  - Replaces the oldest page.
  - Simple but may discard frequently used pages (thrashing).
4. Second Chance Algorithm:
  - FIFO with reference bits.
  - Pages with recently set reference bits get a "second chance."
5. Clock Policy:
  - Circular buffer-like implementation of Second Chance.
  - Finds and replaces the first page with a "use" bit of 0.

**Page Buffering**

- Free Page List:
  - Stores unmodified pages for quick reuse.
- Modified Page List:
  - Stores modified pages and writes them to disk in clusters, reducing I/O.

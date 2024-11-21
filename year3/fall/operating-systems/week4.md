# Week 4: Memory Management

## Notes

---

**Virtual Memory**

- **Definition**: Virtual memory is a memory management technique that allows an operating system to use hardware and software to enable a computer to compensate for physical memory shortages, effectively giving the illusion of a large, contiguous block of memory to applications.
- **Benefits**:
    - **Isolation**: Each process operates in its own virtual address space, which enhances security and stability. Processes cannot access each other’s memory directly.
    - **Efficiency**: Virtual memory allows for more efficient use of physical memory by only loading necessary pages into RAM and keeping other parts on disk.
    - **Simplified Memory Management**: Developers can write programs as if they have access to a large, continuous memory space, without needing to manage physical memory constraints directly.

**Paging**

- **Definition**: Paging is a memory management scheme that eliminates the need for contiguous allocation of physical memory. It divides the virtual memory into fixed-size blocks called **pages** and the physical memory into blocks of the same size called **frames**.
- **Page Table**: Each process has a page table that maps virtual pages to physical frames. When a process accesses a memory address, the system uses the page table to translate the virtual address into a physical address.
- **Page Faults**: When a process tries to access a page that is not currently in physical memory, a page fault occurs. The operating system then retrieves the required page from disk (secondary storage) and loads it into a free frame in physical memory. If no frames are available, the OS may need to evict an existing page, often using a replacement algorithm (like Least Recently Used, LRU).
- **Fragmentation**: Paging helps eliminate external fragmentation since pages and frames are fixed-size, but it can lead to internal fragmentation if the last page of a process is not completely filled.

**Segmentation**

- **Definition**: Segmentation is another memory management technique that divides the virtual address space into variable-sized segments based on the logical structure of a program. Each segment represents a different logical unit, such as a function, an array, or a stack.
- **Segment Table**: Each process has a segment table that contains the base address and limit for each segment. The base address indicates where the segment is located in physical memory, and the limit specifies the segment's size.
- **Advantages**: Segmentation provides a more logical way of organizing memory than paging, as it reflects the program's structure. This can make it easier for programmers to manage memory.
- **Segmentation Faults**: Similar to page faults in paging, if a process tries to access memory outside its segment limit, a segmentation fault occurs, prompting the OS to handle the error.

**Comparison of Paging and Segmentation**

- **Size**: Paging uses fixed-size blocks, while segmentation uses variable-sized units based on logical divisions in a program.
- **Ease of Use**: Segmentation can be more intuitive for programmers, as it aligns with how programs are structured. Paging is simpler from a memory management perspective.
- **Fragmentation**: Paging can lead to internal fragmentation, whereas segmentation may lead to external fragmentation due to variable sizes.

**Summary**

In summary, virtual memory is a crucial concept that enhances memory management in modern operating systems by allowing processes to use a larger logical address space than the available physical memory. Paging and segmentation are two different methods for implementing virtual memory, each with its own advantages and trade-offs. Paging simplifies memory management with fixed-size units, while segmentation aligns with logical program structures, providing more flexibility but potentially leading to fragmentation issues.

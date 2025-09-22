# Week 6: File Systems

## Notes

---

## Objectives of File Management
- Meet user data management needs.
- Ensure data validity.
- Optimize performance.
- Provide I/O support for multiple storage devices and users.
- Minimize data loss risks.
- Standardize I/O interface routines.

---

## Key Concepts in File Management

### File Abstraction
- **Operations**: Read, write, seek, create, delete.
- **Attributes**:
  - Name, type, location, size, access control, timestamps, version.
- **Meta-data**: Stored on disk, usually in directory entries.

### File Representation
- Files on disk are stored as a set of disk blocks.
- Questions addressed:
  - Which blocks belong to a file?
  - How to find the next block in sequence?

---

## File System Roles
- Organize disk space and structure files.
- Key Concerns:
  1. **Localisation**: Track file storage.
  2. **Structure**: Use directories/folders.
  3. **Access**: Enable read/write operations.
  4. **Performance**: Use buffering to reduce I/O.
  5. **Reliability**: Enable recovery from crashes.
  6. **Security**: Protect ownership.

---

## File Allocation Methods
1. **Contiguous Allocation**:
   - Simple, good read performance.
   - Suffers from fragmentation.
2. **Chained Allocation**:
   - Non-contiguous; blocks form a chain.
   - Pros: Avoids external fragmentation.
   - Cons: Sequential reading is slow, memory waste due to pointers.
3. **Indexed Allocation**:
   - Uses an index table for block pointers.
   - Examples:
     - **FAT (File Allocation Table)**:
       - Combines chaining with a central index.
       - Pros: Efficient for both sequential and direct access.
       - Cons: FAT can be large.
     - **i-Nodes**:
       - Used in UNIX systems.
       - Pros: Efficient for large disks.
       - Cons: Hierarchical indexing adds complexity for large files.

---

## Contiguous Allocation
- Simplest; files span a sequence of blocks.
- Used in DVDs and tapes where file size is pre-determined.
- Suffers from external fragmentation over time.

## Chained Allocation
- Blocks contain pointers to the next block.
- **Advantages**:
  - No external fragmentation.
- **Disadvantages**:
  - Random access is slow.
  - Chain pointers consume space.

---

## Indexed Allocation
- Central index table holds pointers to all file blocks.
- **Advantages**:
  - Eliminates chaining inefficiencies.
  - Reduces I/O for block retrieval.
- **Implementations**:
  - **FAT**:
    - Combines chaining with a separate table stored at disk start.
    - Pros: Efficient for direct/sequential access.
    - Cons: Requires memory for FAT table.
  - **i-Nodes**:
    - Used in UNIX; stores file attributes and block indices.
    - Supports direct, single, double, and triple indirect indexing.

---

## FAT: Specifics
- Stores block chains in memory for quick access.
- Efficient for extending files and deleting files.
- Example:
  - 8GB USB Drive, 4KB block size → 2048 blocks required for FAT.

---

## i-Nodes: Details
- Each file has one i-node storing:
  - Attributes, pointers to file blocks.
- Supports hierarchical indexing:
  - Direct, single, double, triple indirect blocks for scalability.
- **Advantages**:
  - Efficient for small files.
  - Optimized memory use (loaded into memory only when file is open).
- **Disadvantages**:
  - Fixed block references may require additional I/O for large files.

---

## Summary of File Allocation Methods

| Method | Pros | Cons |
|---------------|-------------------------------|--------------------------------|
| Contiguous | Fast sequential access | Fragmentation, inflexible size |
| Chained | No fragmentation | Slow random access |
| Indexed (FAT) | Efficient access, scalable | Memory and disk overhead |
| Indexed (i-Node) | Large file support, efficient | Complexity for large hierarchies |

---

## Important Concepts for Exam
- Understand the pros/cons of allocation methods.
- Be able to calculate FAT size requirements.
- Explain i-Node indexing levels and their scalability.

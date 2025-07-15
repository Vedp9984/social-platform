# Data Structures and Algorithms Assignment

## Project Overview
This project implements a system using linked list data structures to manage posts and comments. The implementation is memory leak free, verified using memory management tools like Valgrind.

## Features
- Command-line interface for user interaction
- Post creation and management
- Comment functionality
- Memory-efficient implementation with proper cleanup
- No memory leaks (verified with Valgrind)

## Implementation Details

### Core Logic
- A while loop controlled by an integral value `x` processes user commands
- The loop terminates when the user enters the "exit" command (setting x to 0)
- Custom functions calculate the size of linked lists for both posts and comments

### Data Structures
- Custom linked list implementations for storing posts
- Linked lists for managing comments on posts
- Efficient memory management through proper allocation and deallocation

### Memory Management
- All dynamically allocated memory is properly freed
- No memory leaks as verified by Valgrind
- Careful implementation of destructors and cleanup functions

## How to Use
1. Compile the program using your C/C++ compiler
2. Run the executable
3. Follow the on-screen prompts to interact with the system
4. Type "exit" to quit the program

## Commands
- `[command details would go here]`



## Development Notes
- The project was implemented with a focus on memory efficiency
- Valgrind was used to verify no memory leaks occur
- Each data structure was designed for optimal performance and minimal memory overhead

## Future Improvements
- [Potential improvements could be listed here]



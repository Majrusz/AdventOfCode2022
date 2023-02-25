# What is Advent of Code?
Advent of Code is a recurring event based on solving small programming puzzles in any programming language. \
Find out more about the event here: [https://adventofcode.com/2022/about](https://adventofcode.com/2022/about)

# About the Project Structure
The entire project has been divided to many subprojects to increase readability.

## Days
Each day has two separate projects - one for a puzzle solution and one for unit tests (where XX is the day number):
- *DayXX*
- *DayXX_Tests*

## Utility
There is also one additional project which shares common code between all puzzles. \
It is built as static library and it is included in all other projects.

## All Unit Tests
The last project is just a combination of all unit tests for Utility project and all puzzle solutions. \
It has been created to ensure backward compatibility when adding/removing functions to/from **Utility** project.

# Technologies
- **C++17**
- **STL**
- **CMake**
- **[Catch2](https://github.com/catchorg/Catch2)** (unit testing framework for C++)
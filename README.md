
# Project StringUtils README

## Project Status
This project implements a suite of string manipulation utilities in C++, similar to those in Python. All functions have been thoroughly tested and verified.

## Known Issues
- No current issues. All functions perform as expected, and unit tests cover various scenarios, including edge cases.

## Code References
- [C++ String Reference](https://en.cppreference.com/w/cpp/string/basic_string)
- [C++ Algorithms Library](https://en.cppreference.com/w/cpp/algorithm)
- Stack overflow - Google test and how to install Gtest and how it works.
                    https://stackoverflow.com/questions/15852631/how-to-install-gtest-on-mac-os-x-with-homebrew
                    https://stackoverflow.com/questions/26216429/unit-testing-with-google-test
                

## Generative AI Use
Generative AI was utilized to assist in addressing specific syntactical challenges and edge case logic in C++ implementations. Below are the detailed prompts, AI responses, and modifications.

### Prompt 1: Syntax for Handling Negative Indices in `Slice` Function
**Prompt:** "Provide C++ code snippet to handle negative start or end indices in a string slicing function similar to Python's slicing."

**AI Response:** The AI provided a basic code snippet demonstrating the use of conditional statements to adjust negative indices to their positive equivalents, based on the string's length.

**Changes Made:** Integrated this logic into the `Slice` function, modifying the indices adjustment to handle scenarios where negative indices exceed the string's length, setting them to zero in such cases.

### Prompt 2: Edge Case in `ExpandTabs` Function
**Prompt:** "Show C++ code for replacing tab characters with spaces, considering edge cases where tabsize is zero or negative."

**AI Response:** The AI suggested a loop iterating over each character, replacing tabs with a string of spaces equal to `tabsize`. It did not initially account for edge cases with `tabsize`.

**Changes Made:** Added a condition to handle `tabsize` being zero or negative, in which case tabs are not expanded. This ensures robustness in varying `tabsize` scenarios.

### Prompt 3: Case-Insensitive Comparison in Edit Distance Algorithm
**Prompt:** "In C++, how to modify the standard Levenshtein edit distance algorithm for case-insensitive comparison?"

**AI Response:** The AI provided a modification to the standard algorithm, suggesting the use of `std::tolower` before character comparison but did not consider locale-specific case insensitivity.

**Changes Made:** Enhanced the implementation to use `std::tolower` with a specific locale (e.g., `std::locale::classic()`) to ensure consistent case-insensitive behavior across different environments.

### Prompt 4: Handling Zero Width in `Center` Function
**Prompt:** "In C++, how should I handle the case where the specified width is less than the string length in a string centering function?"

**AI Response:** Recommended returning the original string unchanged if the specified width is less than the string's length.

**Changes Made:** Applied this advice in the `Center` function, ensuring it doesn't attempt to pad a string when the width is too small.

### Prompt 5: Makefile Syntax for Directory Creation
**Prompt:** "What is the correct syntax in a Makefile to create directories if they don't exist?"

**AI Response:** Suggested using shell commands within the Makefile, specifically `mkdir -p` for creating directories only if they don't already exist.

**Changes Made:** Applied this advice in the `setup` target of the Makefile to ensure the `obj` and `bin` directories are created as needed.

### Prompt 6: Linking GoogleTest in Makefile
**Prompt:** "How to correctly link the GoogleTest library in a Makefile for a C++ project?"

**AI Response:** Provided a snippet demonstrating the use of `-L` and `-l` flags in `LDFLAGS` to include the GoogleTest library during the linking process.

**Changes Made:** Integrated this logic into the `$(EXECUTABLE)` target to ensure the GoogleTest library is correctly linked for unit testing.

### Prompt 7: Proper Cleanup Command in Makefile
**Prompt:** "Show the best practice for writing a cleanup command in a Makefile for a C++ project."

**AI Response:** Suggested using `rm -rf` to remove directories and their contents, ensuring a clean build environment.

**Changes Made:** Implemented this suggestion in the `clean` target to remove the `obj` and `bin` directories effectively.


### Prompt 8: Linking Object Files with GoogleTest
**Prompt:** "What is the correct approach to link object files with GoogleTest in a Makefile for C++ unit testing?"

**AI Response:** Suggested using `-lgtest` and `-lgtest_main` flags in the `LDFLAGS` and specifying object file dependencies for the executable target.

**Changes Made:** Incorporated these suggestions into the `$(EXECUTABLE)` target, ensuring that both `StringUtils.o` and `StringUtilsTest.o` are linked correctly with GoogleTest for unit testing.

### Prompt 9: Setting Up Test Execution in Makefile
**Prompt:** "Best practices for setting up a test execution command in a C++ project Makefile?"

**AI Response:** Recommended creating a `test` target that depends on the executable and executes it directly as part of the build process.

**Changes Made:** Implemented a `test` target in the Makefile that first builds the `$(EXECUTABLE)` and then executes it, running all unit tests.




---


---




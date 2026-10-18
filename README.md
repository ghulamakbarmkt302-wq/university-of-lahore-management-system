# University of Lahore Management System

A management system for the University of Lahore to organise departments, teachers, students and courses. Developed by **Muhammad Hamza**.

The project comes in two versions:

1. **Web version** (`index.html`): a single file that runs in any modern browser. No install and no server needed.
2. **Console version** (`University_of_Lahore_Management_System.cpp`): a C++ program that runs in the terminal.

## Features (web version)

- Up to 10 departments, each with up to 10 teachers, 10 students and 10 courses
- Teachers: name, age, degree, years of experience
- Students: name, age, unique student ID (unique within a department)
- Courses: name and course code
- Overview per department: totals, averages, and teachers by degree
- Add, edit, search and sort entries; search departments
- Duplicate department names and duplicate student IDs are rejected
- Responsive layout with dark mode support
- University logo built into the page

## Roles

| Action | Guest | Admin |
|---|---|---|
| View everything | Yes | Yes |
| Add and edit teachers, students, courses | Yes | Yes |
| Delete entries | No | Yes |
| Add departments | Yes | Yes |
| Rename or delete a department | No | Yes |
| Clear all data | No | Yes |

Click **Admin login** in the top bar. The first time, you create an admin password (at least 6 characters). The admin stays logged in until the browser tab is closed or you log out.

## Web version: how to run

1. Download `index.html`.
2. Double-click it, or open it in Chrome, Edge or Firefox.

Your data is saved in that browser (localStorage). It is not shared between computers or browsers, and clearing the browser's site data will delete it.

**Security note:** the admin password is checked in the browser. It keeps casual users from making changes, but it is not real security. Anyone with access to the file can read the code. For real protection, the app would need a server with proper login.

## Console version

Requires a C++ compiler that supports C++11 (for example `g++` or `clang++`).

```bash
g++ -std=c++11 -Wall -o university University_of_Lahore_Management_System.cpp
./university
```

On Windows with MinGW:

```bash
g++ -std=c++11 -Wall -o university.exe University_of_Lahore_Management_System.cpp
university.exe
```

The console version keeps data in memory only, so it is lost when the program exits.

## Project files

| File | Purpose |
|---|---|
| `index.html` | Web application (HTML, CSS and JavaScript in one file) |
| `University_of_Lahore_Management_System.cpp` | Console application in C++ |
| `README.md` | This file |
| `LICENSE` | MIT license |

## License

The source code is released under the MIT License. See [LICENSE](LICENSE).

The University of Lahore name and logo are the property of the University of Lahore. They are not covered by the MIT License. Use of the logo should be approved by the university.

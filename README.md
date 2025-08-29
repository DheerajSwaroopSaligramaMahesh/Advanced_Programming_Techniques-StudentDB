# Student Database Management System (C++)

A C++ **console-based Student Database Management System** that allows you to manage students, courses, and enrollments. The project demonstrates **Object-Oriented Programming (OOP)** concepts such as inheritance, polymorphism, encapsulation, and also integrates with the **POCO C++ libraries** for handling dates and times.

---

## Features
- Add new students with personal details & addresses  
- Create and manage **Block Courses** & **Weekly Courses**  
- Enroll students into courses (with semester info)  
- Update student info (name, DOB, address)  
- Manage enrollments (delete, update grades)  
- Search students by name  
- Save database to file (students, courses, enrollments)

---

## Project Structure
├── Course.cpp / Course.h<br>
├── BlockCourse.cpp / BlockCourse.h<br>
├── WeeklyCourse.cpp / WeeklyCourse.h<br>
├── Student.cpp / Student.h<br>
├── Address.cpp / Address.h<br>
├── Enrollment.cpp / Enrollment.h<br>
├── StudentDb.cpp / StudentDb.h<br>
├── SimpleUI.cpp / SimpleUI.h<br>
└── main.cpp # Entry point<br>

---

## Requirements
- **C++17 or later**
- [**POCO C++ Libraries**](https://pocoproject.org/)  
  (for handling Date, Time, and DateTime formatting)

---

## How to Run

1. Compile the provided source files with a C++ compiler:  
   [Source Code Link](https://github.com/DheerajSwaroopSaligramaMahesh/Advanced_Programming_Techniques-StudentDB/tree/main/StudentDB/myCode)  

2. Run the generated executable.  

3. Use the interactive menu to:  
   - Add students and courses  
   - Enroll students  
   - Update student details  
   - Manage enrollments and grades  
   - Search students  
   - Save the database to a file  

4. The program continues until you choose the **Exit (0)** option in the menu.  


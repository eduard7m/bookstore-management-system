# Library & Inventory Management System

A modular C++ console application designed to handle book lending, categorization, student records, and inventory tracking using direct binary file persistence.

## Overview
Developed as a coursework project for Universidad de Guadalajara (CUCEI), this application manages administrative workflows for a university library. It implements role-based access control, file serialization, structured data validation, and custom date calculation algorithms for book loan tracking without external database dependencies.

## Key Features
* **Role-Based Access Control:**
  * **Student Mode:** Browse catalog by subject areas and search available titles.
  * **Administrator Mode:** Protected with a masked password input, enabling inventory updates and system configuration.
* **Book & Inventory Management:** 
  * Add, search, edit, and delete books across 6 academic categories (Mathematics, Physics, Algebra, Engineering, Calculus, Programming).
  * Real-time stock decrement/increment on checkout and return operations.
* **Loan & Circulation Tracking:**
  * Link student identification codes with book records.
  * Custom date-difference calculation taking leap years into account to monitor active borrowing periods.
* **Binary File Persistence:** Efficient read/write operations using standard C++ file streams (`fstream`) storing data directly into local records (`Booksdata.txt`, `estudiante.txt`, `password.txt`).

## Technical Stack
* **Language:** C++ (Standard Template Library)
* **Paradigm:** Object-Oriented Programming (OOP)
* **File Handling:** Binary file streams (`ifstream`, `ofstream`, `fstream`)
* **Target Environment:** Windows Console (`conio.h`, MinGW / GCC)

## Getting Started

### Prerequisites
* Windows OS
* A C++ compiler supporting C++11 (GCC via MinGW or Code::Blocks)

### Build & Run
1. Clone this repository:
   ```bash
   git clone [https://github.com/eduard7m/cucei-library-management.git](https://github.com/eduard7m/cucei-library-management.git)

1. Navigate to the project directory:
   cd cucei-library-management

2. Compile with GCC:
   g++ main.cpp -o biblio.exe

3.Run the application:
  biblio.exe
Default Admin Password: pass

# Clinic Management System

A simple console-based Clinic Management System written in C. This project provides basic functionality for managing patients and appointments through a terminal interface.

---

## 🆕 Features

- Add, edit, and delete patient records.
- Schedule, view, and cancel appointments.
- User interaction through text-based menus.
- Structured project with modular C files (`.h` and `.c`).

---

##  Folder Structure


- **`main.c`** – Entry point of the application. Contains the main menu and high-level flow.
- **`FinalProject_interface.h`** – Header file with function prototypes and shared data definitions.
- **`FinalProject_program.c`** – Core implementation of functions declared in the header file.

---

##  Getting Started

### Prerequisites

- A C compiler (e.g., `gcc`) installed on your system.
- Basic familiarity with compiling and running C programs via terminal.

### Build Instructions

```bash
git clone https://github.com/TheRealRoshdy/Clinic-management-system.git
cd Clinic-management-system
gcc main.c FinalProject_program.c -o clinic_system
./clinic_system

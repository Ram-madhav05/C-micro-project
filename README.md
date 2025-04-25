# 📘 Student Record System (C Language)

## 📋 Description
This is a simple **Student Record Management System** written in **C**. It allows you to:

- Add new student records  
- View all stored student records  
- Search for a student by roll number  
- Count total number of student records  

The program uses **file handling** (`students.txt`) in **binary mode** to store and retrieve student data.

---

## 📦 Features

### ✅ Add Student
Input a student’s roll number, name, and marks. The data is stored in a binary file (`students.txt`).

### 👀 View All Students
Displays all student records stored in the file.

### 🔍 Search Student by Roll Number
Searches for a student using their roll number and displays the result.

### 🔢 Count Total Students
Shows the total number of students stored.

### 🚪 Exit
Terminates the program.

---

## 🧑‍💻 Structure Used

```c
struct Student {
    int roll;
    char name[50];
    float marks;
};
```

---

## 📂 Files

- `main.c` – Contains the complete source code.  
- `students.txt` – Binary file where all records are stored.

---

## ⚙️ How to Compile and Run

### Compile:
```bash
gcc main.c -o student_app
```

### Run:
```bash
./student_app
```

---

## 📝 Notes

- File operations are done in binary mode (`"rb"`, `"ab"`).
- Make sure `students.txt` is in the same directory as your executable.

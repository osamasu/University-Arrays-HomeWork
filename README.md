<div align="center">

# 📚 University Arrays HomeWork

### A C++ console application covering array fundamentals & a student grading system

[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)](https://visualstudio.microsoft.com/)
[![IDE](https://img.shields.io/badge/IDE-Visual%20Studio-5C2D91?style=for-the-badge&logo=visualstudio&logoColor=white)](https://visualstudio.microsoft.com/)
[![License](https://img.shields.io/badge/License-Educational-brightgreen?style=for-the-badge)](#-license)

<br/>

![Application Preview](https://github.com/osamasu/University-Arrays-HomeWork/assets/97795269/3ccf341d-19d4-4895-85b2-97e1f6145286)

</div>

---

## 📖 Overview

**University Arrays HomeWork** is a menu-driven C++ console project built as coursework, demonstrating practical mastery of **arrays**, **functions**, **file handling**, and **string manipulation**. It bundles seven standalone homework exercises together with a small **Student Grades Management System** that persists data to a text file.

The project is organized as a Visual Studio solution (`Arrays HomeWork.sln`) targeting Windows (x86/x64, Debug/Release).

## ✨ Features

| # | Homework | Description |
|:-:|----------|--------------|
| 1 | **Sum Two Arrays** | Fills two arrays with random numbers and sums them element-wise into a third array |
| 2 | **Min & Max Finder** | Reads an array and finds its biggest and lowest values |
| 3 | **Array Swap** | Swaps the first and last elements of an array |
| 4 | **Calculator** | A menu-based calculator supporting addition, subtraction, multiplication, and division |
| 5 | **Student Info System** | Add, list, and delete student records with grade averaging — persisted in `StudentsInfo.txt` |
| 6 | **Array Multiplication** | Multiplies two arrays element-wise into a third array |
| 7 | **Number to Text** | Converts a numeric value into its full English word representation |

### 🎓 Student Grades Management System

A mini CRUD system built on top of arrays and file I/O:

- ➕ **Add Student** — captures ID, name, and marks for Math, Quran, Physics, Islamic Studies, and History
- 📋 **Show All Students** — displays a formatted table with totals and computed averages
- ❌ **Delete Student** — locates a student by ID and removes their record with a confirmation prompt
- 💾 **Persistent Storage** — all records are saved to and loaded from `StudentsInfo.txt` using a custom serialization format

## 🗂️ Project Structure

```
University-Arrays-HomeWork/
├── Arrays HomeWork.sln              # Visual Studio solution
└── Arrays HomeWork/
    ├── Arrays HomeWork.cpp          # Main program: menus & homework implementations
    ├── Header.h                     # "legend" namespace — reusable helper library
    ├── StudentsInfo.txt             # Student records data file
    └── Arrays HomeWork.vcxproj      # Project configuration
```

### 🧰 The `legend` Helper Library

`Header.h` defines a reusable `legend` namespace with organized sub-namespaces for common console-app needs:

- `ReadNumber` / `ReadNumber_InRange` / `ReadPositiveNumbers` — validated numeric input
- `Strings` — trimming, casing, splitting/joining, vowel checks, letter counting
- `Arrays` — fill, search, copy, and print helpers
- `Matrix` — 3x3 matrix fill, sum, and search utilities
- `Files` — read/write/update/delete records in text files
- `Time` — local & GMT timestamp helpers
- Standalone utilities — prime/perfect/palindrome number checks, number reversal, random character generation

## 🚀 Getting Started

### Prerequisites

- **Windows** OS
- **Visual Studio 2019/2022** with the *Desktop development with C++* workload

### Build & Run

```bash
# Clone the repository
git clone https://github.com/osamasu/University-Arrays-HomeWork.git

# Open the solution
cd "University-Arrays-HomeWork"
start "Arrays HomeWork.sln"
```

1. Open `Arrays HomeWork.sln` in Visual Studio
2. Select your target configuration (**Debug/Release** — **x86/x64**)
3. Build the solution (`Ctrl+Shift+B`)
4. Run the project (`Ctrl+F5`)
5. Pick a homework number from the on-screen menu and follow the prompts

## 🖥️ Usage

On launch, the program presents a menu listing all seven homeworks grouped by category (**Arrays**, **Functions**, **Others**). Enter the number of the homework you want to run, follow the interactive prompts, and choose whether to run another homework afterward.

## 🛠️ Tech Stack

- **Language:** C++ (C++14/17, Standard Library — `<iostream>`, `<vector>`, `<fstream>`, `<string>`)
- **Build System:** MSBuild / Visual Studio Project (`.vcxproj`)
- **Storage:** Flat-file persistence with a custom `#//#` delimiter format

## 👤 Author

**Thabit Osama**

## 📄 License

This project was created for **educational purposes** as part of university coursework.

---

<div align="center">

Made with 💻 and ☕ while learning C++ Arrays

</div>

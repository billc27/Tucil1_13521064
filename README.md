# 24 Game Solver

Tugas Kecil I IF2211 Strategi Algoritma
<br />

## Table of Contents
* [General Info](#general-information)
* [How To Run](#how-to-run)
* [Tech Stack](#tech-stack)
* [Project Structure](#project-structure)
* [Credits](#credits)

## General Information
Permainan kartu 24 adalah permainan kartu dengan tujuan untuk mencari berbagai cara untuk mengoperasikan 4 buah angka acak dengan operasi matematika ('+', '-', '*', '/', '(', ')') untuk menghasilkan angka 24. Permainan ini biasanya dimainkan dengan menggunakan kartu remi yang berjumlah 52 kartu. Kartu-kartu tersebut terbagi menjadi empat jenis, yakni hati, wajik, sekop, dan keriting. Namun, dalam permainan, yang diperhatikan adalah nilai kartu dan bukan jenis kartunya. Nilai kartu pada kartu remi terdiri dari A, J, Q, K, 2, 3, 4, 5, 6, 7, 8, 9, dan 10. A memiliki nilai 1, J memiliki nilai 11, Q memiliki nilai 12, dan K memiliki nilai 13. Dalam permainan kartu 24 ini, keempat kartu harus digunakan tepat sekali dan urutan untuk menggunakannya bebas.

## How To Run
### Requirements
To be able to compile the program, you need to install the g++ compiler.
### Compile
To compile the program and generate the executable file in the bin folder, run:
```shell
g++ src/24GameSolver.cpp -o bin/24GameSolver.exe
```
### Run
To move to the bin folder and run the program, type:
```shell
cd bin
./24GameSolver.exe
```
If the program is compiled and run successfully, you can use the 24 Game Solver right away!


## Tech Stack
### Programming Languange
* C++

## Project Structure
```bash
Tucil1_13521064
│
├───bin
│   └── 24GameSolver.exe
│    
├───doc
│   └── Tucil1_K2_13521064_Bill Clinton.pdf
│
├───src
│   └── 24GameSolver.cpp
│
│───test
│    ├── testcase1.txt
│    ├── testcase3.txt
│    ├── testcase5.txt
│    ├── testcase7.txt
│    └── testcase9.txt
│
└───README.md
```

## Credits
This project is made by Bill Clinton (13521064).

# CSE 316 Assignment
This repository contains my solutions for Simulation-based 
Academic Task of Operating System CSE316 for the Academic Year 2019 (Semester 4).

## Personal Information

Name : Rajdeep Roy Chowdhury

Registration Number : 11712546

Roll Number : 18

Section : K17SJ

Group : 1

## Questions

### Task 05

A university computer science department has a teaching assistant (TA) who helps undergraduate students with their programming assignments during regular office hours. The TA’s office is rather small and has room for only one desk with a chair and computer. There are three chairs in the hallway outside the office where students can sit and wait if the TA is currently helping another student. When there are no students who need help during office hours, the TA sits at the desk and takes a nap. If a student arrives during office hours and finds the TA sleeping, the student must awaken the TA to ask for help. If a student arrives and finds the TA currently helping another student, the student sits on one of the chairs in the hallway and waits. If no chairs are available, the student will come back at a later time.

### Task 22
Write a program that implements the FIFO page replacement algorithm. First, generate a random page-reference string where page numbers range from 0 to 9. Apply the random page-reference string to each algorithm, and record the number of page faults incurred by each algorithm. Implement the replacement algorithm so that the number of page frames can vary from 1 to 7. Assume that demand paging is used.

## How to execute?
- [Task 05](./TASK05/README.md) Click here to navigate to the TASK05 guide
- [Task 22](./TASK22/README.md) Click here to navigate to the TASK22 guide

## Want to compile manually?
- Compile by firing the following command in the respected TASK directories
```sh
$ gcc main.c -lphread
```
- Run the executable object file by issuing the following command
```sh
$ ./a.out
```
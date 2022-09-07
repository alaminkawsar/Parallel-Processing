# Parallel-Processing
## Introduction

**Let's Introduce with a simple mpi ``hellow_world`` Program**
````
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv){
    int process_Rank, size_Of_Cluster;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

    printf("Hello World from process %d of %d\n", process_rank, size_Of_Cluster);

    MPI_Finalize();
    return 0;
}
````
We will discuss above common 4 directives.

***MPI_Init(&argc, &argv):*** This function initializes the MPI environment. It takes in the addresses of the C++ command line arguments argc and argv.

***MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster):***  This function returns the total size of the environment via quantity of processes. The function takes in the MPI environment, and the memory address of an integer variable.*Basically it is the number of process*

***MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank):***  This function returns the process id of the processor that called the function. The function takes in the MPI environment, and the memory address of an integer variable.

***MPI_Finalize():*** This function cleans up the MPI environment and ends MPI communications.



**How to run above c++ program in mpi**

*Compile*
````
mpic++ hello_world.cpp -o hello_world
````
*Run with 4 process*
````
mpirun -np 4 ./hello_world

````
It should looks like:
````
Hello World from process 3 of 4
Hello World from process 2 of 4
Hello World from process 1 of 4
Hello World from process 0 of 4
````

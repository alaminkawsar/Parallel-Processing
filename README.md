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



## Message Passing
Message passing is the primary utility in the MPI application interface that allows for processes to communicate with each other. Now we will learn the basics of message passing between 2 processes.

Message passing in MPI is handled by the corresponding functions and their arguments:
````
MPI_Send(void* message, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm, communicator);
MPI_Recv(void* data, int count, MPI_Datatype datatype, int from, int tag, MPI_Comm comm, MPI_Status* status);
````

The arguments are as follows:
***MPI_Send()***
````
void* message:          //Address for the message you are sending.
int count:              //Number of elements being sent through the address.
MPI_Datatype datatype:  //The MPI specific data type being passed through the address.
int dest:               //Rank of destination process.
int tag:                //Message tag.
MPI_Comm comm;          //The MPI Communicator handle.
````


***MPI_Recv()***
````
void* message;          //Address to the message you are receiving.
int count;              //Number of elements being sent through the address.
MPI_Datatype datatype;  //The MPI specific data type being passed through the address.
int from;               //Process rank of sending process.
int tag;                //Message tag.
MPI_Comm comm;          //The MPI Communicator handle.
MPI_Status* status;     //Status object.
````

### Example
We will create a two-process that will pass the number 42 from one process to another. We will use our “Hello World” program as a starting point for this program. Let’s begin by creating a variable to store some information.
````
#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
    int process_Rank, size_Of_Cluster, message_Item;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

    //This is master process, we will pass the number from it
    if(process_Rank == 0){
        message_Item = 42;
        MPI_Send(&message_Item, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Message Sent: %d\n", message_Item);
    }
    else if(process_Rank == 1){
        //this is slave process where we will recieve the number.
        MPI_Recv(&message_Item, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Message Received: %d\n", message_Item);
    }

    MPI_Finalize();
    return 0;
}
````

**Output should be looks like**
````
Message Sent: 42
Message Received: 42
````

If we match the parameter it should looks like:
````
MPI_Send(
    &message_Item,      //Address of the message we are sending.
    1,                  //Number of elements handled by that address.
    MPI_INT,            //MPI_TYPE of the message we are sending.
    1,                  //Rank of receiving process
    1,                  //Message Tag
    MPI_COMM_WORLD      //MPI Communicator
);

MPI_Recv(
    &message_Item,      //Address of the message we are receiving.
    1,                  //Number of elements handled by that address.
    MPI_INT,            //MPI_TYPE of the message we are sending.
    0,                  //Rank of sending process
    1,                  //Message Tag
    MPI_COMM_WORLD      //MPI Communicator
    MPI_STATUS_IGNORE   //MPI Status Object
);
````


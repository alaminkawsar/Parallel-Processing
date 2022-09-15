#include<bits/stdc++.h>
#include <stdio.h>
#include <mpi.h>

#define MAX 100

using namespace std;



int main(int argc, char** argv) {
    int process_Rank, size_Of_Cluster, message_Item;
    char message[MAX];

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size_Of_Cluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &process_Rank);

    //This is master process, we will pass the number from it
    if(process_Rank == 0){
        strcpy(message,"Hello Kawsar. You need to marry");
        MPI_Send(&message, strlen(message)+1, MPI_CHAR, 1, 1, MPI_COMM_WORLD);
        printf("Message Sent from Master process: %s\n", message);
    }
    else if(process_Rank == 1){
        //this is slave process where we will recieve the number.
        int n=10;
        MPI_Recv(&message, MAX, MPI_CHAR, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Message Received from Slave Process: %s\n", message);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
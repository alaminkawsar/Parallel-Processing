#include<bits/stdc++.h>
#include "mpi.h"
#include<time.h>
#include<sys/time.h>

using namespace std;

int main(int argc, char **argv){
    int ierr;
    ierr = MPI_Init(&argc, &argv);
    printf("Hello World!\n");

    ierr = MPI_Finalize();

}
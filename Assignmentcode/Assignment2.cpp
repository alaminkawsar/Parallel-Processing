#include<bits/stdc++.h>
#include <stdio.h>
#include <mpi.h>

using namespace std;

     
int   main(int argc, char **argv)
   {
      
      vector<int>mat1={{2,3,4},{1,2,3},{3,2, 1}};
      
      
      ierr = MPI_Init(&argc, &argv);

      /* find out MY process ID, and how many processes were started. */

      ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
      ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

      printf("I'm process %i out of %i processes\n", 
         my_id, num_procs);

      ierr = MPI_Finalize();
   }
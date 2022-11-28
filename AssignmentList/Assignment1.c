#include <stdio.h>
#include <mpi.h>
     
int   main(int argc, char **argv)
   {
      int ierr, num_procs, my_id;

      MPI_Init(&argc, &argv);

      /* find out MY process ID, and how many processes were started. */

      MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
      MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

      printf("I'm process %i out of %i processes\n", 
         my_id, num_procs);

      MPI_Finalize();
   }
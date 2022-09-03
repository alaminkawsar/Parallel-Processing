#include <stdio.h>
#include <mpi.h>
     
int   main(int argc, char **argv)
   {
    int a,b;
    //printf("Enter tow numbers:\n");
    // scanf("%d%d",&a,&b);
    a=6, b=2;

    int ierr, num_procs, my_id;

    ierr = MPI_Init(&argc, &argv);

    /* find out MY process ID, and how many processes were started. */

    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_id);
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    if (my_id==0){
        printf("sum(a,b)= %d\n",a+b);
    }
    else if(my_id==1){
        printf("Subtraction(a,b)=%d\n",a-b);
    }
    else if (my_id==2){
        printf("Multiply(a,b)= %d\n",a*b);
    }
    else{
        printf("Division(a,b)= %d\n",a/b);
    }
    
    //   printf("I'm process %i out of %i processes\n", 
    //      my_id, num_procs);

      ierr = MPI_Finalize();
   }
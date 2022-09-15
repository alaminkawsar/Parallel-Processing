#include<bits/stdc++.h>
#include<mpi.h>

using namespace std;

int n = 10;
int ar[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int tempArr[100];

int main(int argc,char* argv[]){
    int element_per_process, recieved_element,pid,nprocess;

    MPI_Status status;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&nprocess);
    MPI_Comm_rank(MPI_COMM_WORLD,&pid);

    if(pid==0){
        int index, i;
        element_per_process = n/nprocess;
        for(i=1;i<nprocess-1;i++){
            index = i*element_per_process;
            MPI_Send(&element_per_process, 1,MPI_INT,i, 0, MPI_COMM_WORLD);
            MPI_Send(&ar[index], element_per_process, MPI_INT,i, 0, MPI_COMM_WORLD);
        }

        // send last remaining element
        index = i*element_per_process;
        int remaining_element = n-index;
        MPI_Send(&remaining_element, 1,MPI_INT,i, 0, MPI_COMM_WORLD);
        MPI_Send(&ar[index], remaining_element, MPI_INT,i, 0, MPI_COMM_WORLD);
        int sum = 0;

        for(int i=0;i<element_per_process;i++){
            sum+=ar[i];
        }
        printf("Summation from Master process: %d\n",sum);

        int temp;
        //receve from n number of process
        for(int i=1;i<nprocess;i++){
            MPI_Recv(&temp,1, MPI_INT, i, 0, MPI_COMM_WORLD, &status);
            printf("%d\n",temp);
            sum+=temp;
        }
        
        //print the total sum
        printf("Toatal Sum From All Process: %d\n",sum);
    }else{
        MPI_Recv(&recieved_element,1,MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&tempArr,recieved_element, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        int temp=0;
        for(int i=0;i<recieved_element;i++){
            temp+=tempArr[i];
        }
        printf("Summation of Slave Process %d=%d\n",pid,temp);
        MPI_Send(&temp, 1,MPI_INT,0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
}

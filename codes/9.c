#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//applying the functionality of alltoall

MPI_Request request = MPI_REQUEST_NULL;




char sdata[10];
int rr=rank+48;
sdata[0]=(char)rr;
printf("\n HI I am sending the massage %d to all processes  and my rank is %d ...\n ",rank,rank);


for(int i=0;i<nprocs;i++){

MPI_Isend(&rank,1,MPI_INT,i,20,MPI_COMM_WORLD,&request);

}



int rdata;

for(int i=0;i<nprocs;i++){
MPI_Recv(&rdata,1,MPI_INT,i,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("\n I am recieving the massage %d and my rank is %d ...\n ",rdata,rank);
}



MPI_Finalize();
return 0;
}

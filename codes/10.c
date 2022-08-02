#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//applying the functionality of alltotalv

MPI_Request request = MPI_REQUEST_NULL;




char sdata[]="hello from talha";
//int rr=rank+48;
//sdata[0]=(char)rr;
char d[20];
for(int i=0;i<rank;i++){

d[i]=sdata[i];

}
d[rank]='\0';

printf("\n HI I am sending the massage %s to all processes  and my rank is %d ...\n ",d,rank);


for(int i=0;i<nprocs;i++){

MPI_Isend(d,10,MPI_CHAR,i,20,MPI_COMM_WORLD,&request);

}



char rdata[10];

for(int i=0;i<nprocs;i++){
MPI_Recv(rdata,10,MPI_CHAR,i,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);
}



MPI_Finalize();
return 0;
}

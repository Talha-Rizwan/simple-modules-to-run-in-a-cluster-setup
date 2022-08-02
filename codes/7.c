#include<stdio.h>
#include<mpi.h>


int main(int argc,char** argv){

int rank,nprocs;


MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&nprocs);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
//applying the functionality of gather




if(rank!=0){
char sdata[10];

int rr=rank+48;
sdata[0]=(char)rr;
printf("\n HI I am sending the massage %s to all processes  and my rank is %d ...\n ",sdata,rank);


MPI_Send(sdata,10,MPI_CHAR,0,20,MPI_COMM_WORLD);

}




if(rank==0){

printf("\n HI I am sending the massage %d to processor 0  and my rank is %d ...\n ",rank,rank);

char rdata[10];
char recdata[50];
int k=0;
recdata[k]='0';
k++;
recdata[k]=' ';
k++;

for(int i=1;i<nprocs;i++){
MPI_Recv(rdata,10,MPI_CHAR,i,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
recdata[k]=rdata[0];
//printf("\n I am recieving the massage %s and my rank is %d ...\n ",rdata,rank);
k++;
recdata[k]=' ';
k++;
}
recdata[k]='\0';
//printf("\n I am recieving the massage %d and my rank is %d ...\n ",rank,rank);


printf("the data recieved to process number %d is : %s \n",rank,recdata);

for(int i=1;i<nprocs;i++){

MPI_Send(recdata,20,MPI_CHAR,i,20,MPI_COMM_WORLD);


}
}




if(rank!=0){

char redata[50];
MPI_Recv(redata,20,MPI_CHAR,0,20,MPI_COMM_WORLD,MPI_STATUS_IGNORE);

printf("the data recieved to process number %d is : %s \n",rank,redata);

}





MPI_Finalize();
return 0;
}

#include <mpi.h>
#include <iostream>
#include <cstring>

int main(int argc, char** argv)
{
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int np, pid;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);

    if (np < 2) {
        if (pid == 0) {
            printf("This program requires at least 2 processes (2 nodes).\n");
        }
        MPI_Finalize();
        return 1;
    }

    const char* message_sent = "Hello from Node 0!";
    char message_received[100]; //Buffer

    if (pid == 0) {
        MPI_Send(message_sent, strlen(message_sent) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("Process %d sent: %s\n", pid, message_sent);
    } 
    else if (pid == 1) {
        MPI_Recv(message_received, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process %d received: %s\n", pid, message_received);
    }

    MPI_Finalize();
}
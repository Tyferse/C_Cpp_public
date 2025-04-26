#include <iostream>
#include <mpi.h>


int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int threads_num, thread_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &threads_num);
    MPI_Comm_rank(MPI_COMM_WORLD, &thread_rank);
    if (thread_rank == 0) {
        int msg[2] = {10, 2};
        for (int i=1; i < threads_num; i++) {
            // std::cout << msg[1] << std::endl;
            msg[1] += i;
            MPI_Send(&msg, 2, MPI_INTEGER, i, 42, MPI_COMM_WORLD);
            // printf("Process 0 sent message {%d, %d} to process %d\n", msg[0], msg[1], i);
            std::cout << "Process 0 sent message {" << msg[0] << ", " << msg[1] << "} to process " << i << std::endl << std::endl; 
        }
    }
    else {
        MPI_Status status;
        int recieved[2];
        MPI_Recv(&recieved, 2, MPI_INTEGER, 0, 42, MPI_COMM_WORLD, &status);
        // printf("Process %d recieved message {%d, %d} from process 0\n", thread_rank, recieved[0], recieved[1]);
        std::cout << "Process " << thread_rank << " recieved message {" << recieved[0] << ", " << recieved[1] << ") from process 0" << std::endl << std::endl; 
    }

    MPI_Finalize();
    return 0;
}

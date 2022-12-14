// SERVER CODE

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// MUST BE INCLUDED IN SAME SEQUENCE
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 10 // Size of message  string

struct keyServed
{
    int server_done; // Indicate who will operate on shared memory
    char key[SIZE];  // Stores the message
};

void main()
{
    // To Store shared memory id
    int shmid;

    void *sharedMemory = (void *)0;// NULL
    
    struct keyServed *sharedStuff;

    // Create Memory
    shmid = shmget((key_t)1234, sizeof(struct keyServed), 0666 | IPC_CREAT);

    // Get the Base Address of SM
    sharedMemory = (void *)shmat(shmid, NULL, 0);

    // Attach
    sharedStuff = (struct keyServed *)sharedMemory;
  
    // Initialization for Server
    sharedStuff->server_done = 1;

    // Pooling
    while (1)
    {
        if (sharedStuff->server_done == 1)
        {
            printf("\n Enter the key \n");
            scanf("%s", sharedStuff->key);
            sharedStuff->server_done = 0;
        }
    }
    exit(EXIT_SUCCESS);
}

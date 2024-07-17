#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>

using namespace std;

int main()
{
    // 1.create shared memoery
    char fileName[20] = {0};
    sprintf(fileName,"/letter%d",getpid());
    
    // return file descript
    int fd = shm_open(fileName,O_RDWR | O_CREAT,0664);
    if(fd < 0)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    //2. set the size of shared memory
    ftruncate64(fd,1024);

    //3. maping 
    char *addr = (char *)mmap(NULL,1024,PROT_READ | PROT_WRITE ,MAP_SHARED,fd,0);
    if(addr == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    // after maping you have to close the fd
    close(fd);

    //4. opetation
    int cpid = fork();

    if(cpid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if(cpid == 0)
    {
        strcpy(addr,"I've seen your kind, time and time again");
    }
    else
    {
        sleep(2);
        cout << "The information come from child: " << addr << endl;

        //5. unmaping
        int res = munmap(addr,1024);
        if(res < 0)
        {
            perror("munmap");
            exit(EXIT_FAILURE);
        }
    }

    // final release
    int res = shm_unlink(fileName);
    if(res < 0)
    {
        perror("shm_unlink");
        exit(EXIT_FAILURE);
    }
}

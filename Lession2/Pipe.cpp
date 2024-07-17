#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

int main()
{

    int pipefd[2];
    int res = pipe(pipefd);
    if(0 != res)
    {
        printf("Create Unknow Channel Fail");
        return -1;
    }

    int cpid = fork();
    if(cpid < 0)
    {
        printf("Fork Error");
        return 0;
    }

    if(cpid == 0)
    {
        
        cout << "Child Process" << endl;
        
        char data[100] = {};

        close(pipefd[1]);
        
        read(pipefd[0],data,100);
        cout << "data: " << data << endl;
        
        close(pipefd[0]);
        return 1;
    }
    else
    {
        cout << "Father Process" << endl;
        cout << "Close Read" << endl;

        char *data = "Write Data";

        close(pipefd[0]);
        write(pipefd[1],data,strlen(data));
        close(pipefd[1]);

        waitpid(cpid,NULL,0);

        return 1;
    }

    // perror ------------------------------------------
    //fopen("Test.txt","r");
    // Perror will printf error information
    //perror("Error Information OutPut: ");
}
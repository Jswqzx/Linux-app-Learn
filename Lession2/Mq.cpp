#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>
#include <mqueue.h>
#include <sys/stat.h>

using namespace std;

int main()
{
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_curmsgs = 0;
    attr.mq_maxmsg = 100;
    attr.mq_msgsize = 10;

    char mqName[50] = {0};
    sprintf(mqName,"/test_son");
    int cpid = 0;

    mqd_t md = mq_open(mqName,O_RDWR | O_CREAT,0664,&attr);

    if(md < 0)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    cpid = fork();

    if(cpid == 0)
    {
        struct timespec time_info;
        char data[100];
        for(int i = 0; i < 10; i++)
        {
            memset(data,0,100);
            clock_gettime(0,&time_info);
            time_info.tv_sec +=5;
            if(mq_timedreceive(md,data,100,0,&time_info) < 0)
                perror("mq_timereceive");

            cout << "Child: " << data << endl;
        }
    }
    else
    {
        struct timespec time_info;
        char data[100];

        for(int i = 0; i < 10; i++)
        {
            memset(data,0,100);
            sprintf(data,"Write Data: %d",i+1);
            clock_gettime(0,&time_info);
            time_info.tv_sec +=5;
            if(mq_timedsend(md,data,strlen(data),0,&time_info) < 0)
                perror("mq_timedsend");

            sleep(1);
        }
    }

    if(cpid > 0)
    {
        mq_unlink(mqName);
    }
}
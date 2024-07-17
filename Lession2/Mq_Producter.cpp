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
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 10;

    char mqName[50] = {0};
    sprintf(mqName,"/test_son");
    int cpid = 0;

    mqd_t md = mq_open(mqName,O_CREAT|O_RDWR,0664,&attr);

    if(md < 0)
    {
        perror("mq_open_producter");
        exit(EXIT_FAILURE);
    }


    struct timespec time_info;
    

    char data[10] = {0};
    while(1)
    {
        // data init
        memset(data,0,10);
        ssize_t count = read(0,data,10);
        // time init
        clock_gettime(0,&time_info);
        time_info.tv_sec += 5;

        if(count < 0)
        {
            perror("read_producter");
            continue;
        }
        else if(count == 0)
        {
            cout << "Exit" << endl;
            if(mq_timedsend(md,"Exit",4,0,&time_info))
            {
                perror("mq_timedsend_producter");
            }
            break;
        }
        else
        {
            if(mq_timedsend(md,data,sizeof(data),0,&time_info))
            {
                perror("mq_timedsend_producter");
            }
            cout << "Producter send the message" << endl;
        }
    }

    close(md);

    return 0;
}
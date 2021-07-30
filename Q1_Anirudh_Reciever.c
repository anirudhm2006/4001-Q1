#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define SIZE 128

mqd_t demomq;
struct mq_attr demomq_attr;
int msg_prio;
unsigned char buff[SIZE];

int main()
{
    demomq_attr.mq_flags = 0;
    demomq_attr.mq_maxmsg = 4;
    demomq_attr.mq_msgsize = 128;
    demomq_attr.mq_curmsgs = 0;

    demomq = mq_open("/demomq", O_RDONLY|O_CREAT, S_IRUSR|S_IWUSR,&demomq_attr);
    mq_receive(demomq, buff, 128, &msg_prio);
    printf("Recieved msg: %s\nMsg prio: %d\n", buff, msg_prio);
    int len = strlen(buff);
    printf("length of string = %d\n",len);
    mq_close(demomq);
    return 0;
}
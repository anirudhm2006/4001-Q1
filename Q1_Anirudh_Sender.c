#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>

mqd_t demomq;
struct mq_attr demomq_attr;

int main()
{
    demomq_attr.mq_flags = 0;
    demomq_attr.mq_maxmsg = 4;
    demomq_attr.mq_msgsize = 128;
    demomq_attr.mq_curmsgs = 0;

    demomq = mq_open("/demomq", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR,&demomq_attr);
    mq_send(demomq, "Message\n",7,0);
    mq_close(demomq);
    return 0;
}
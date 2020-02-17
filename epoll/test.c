/*
create fd with eventfd
create epoll group
epoll_wait
measure time
write to fd
return from epoll_wait
measure time

 */

#include <sys/epoll.h>
#include <sys/eventfd.h>
#include <sys/time.h>
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_EVENTS 10


int LOOPS = 4 * 1000 * 1000;
uint64_t u = 1;
struct timeval start, end;

void *w(void *arg)
{
	int ret;
	struct epoll_event events[MAX_EVENTS];
	//for (int i = 0; i < LOOPS; i++)
	//{
	sleep(1);
	gettimeofday(&start, NULL);
	//	epoll_wait(4, events, MAX_EVENTS, -1);
		ret = write(3, &u, sizeof(uint64_t));
	//}
}

int main()
{
	int fd = eventfd(0, 0);
	//printf("fd: %d\n", fd);
	int epollfd = epoll_create1(0);
	//printf("epollfd: %d\n", epollfd);

	struct epoll_event ev, events[MAX_EVENTS];
	ev.events = EPOLLIN;
	ev.data.fd = fd;

	int ret;
	ret = epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
	//printf("epoll_ctl ret: %d, errno: %d\n", ret, errno);

	pthread_t th;
	pthread_create(&th, NULL, w, NULL);
	//for (int i = 0; i < LOOPS; i++)
	//{
	//	ret = write(fd, &u, sizeof(uint64_t));
		ret = epoll_wait(epollfd, events, MAX_EVENTS, -1);
	//}
	gettimeofday(&end, NULL);
	long seconds = end.tv_sec - start.tv_sec;
	long micros = ((seconds * 1000000) + end.tv_usec) - start.tv_usec;
	printf("%ld\n", micros);

}

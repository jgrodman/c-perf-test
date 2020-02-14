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
#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_EVENTS 10

clock_t t;

void *w(void *arg)
{
	sleep(1);
	//printf("writing\n");
	int ret;
	uint64_t u = 1;
	t = clock();
	ret = write(3, &u, sizeof(uint64_t));
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
	ret = epoll_wait(epollfd, events, MAX_EVENTS, -1);
	t = clock() - t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC * 1000 * 1000; // in microseconds
	//printf("t: %ld\n", t);
	printf("%f\n", time_taken);


	//printf("epoll_wait ret: %d\n", ret);
}

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//prime number
void *MyThread1(){
	printf("create thread1!\n");
	int n, flag;
	double k;
	printf("Please enter an integer:");
	scanf("%d", &n);
	printf("From 1 to %d, all the prime number are:", n);
	for(int i = 1; i <= n; i++){
		flag = 1;
		for(int j = 2; j <= i; j++){
			if(i%j==0){
				flag = 0;
				break;
			}
		}
		if(flag){
			printf("%d ", i);
		}
	}
	return NULL;
}

//fib
void *MyThread2(){
	printf("create Thread2!\n");
	return NULL;
}

void thread_two(){
	pthread_t ntid1,ntid2;
	int err;
	if(err=pthread_create(&ntid1, NULL, MyThread1, NULL)){
		printf("Error: %d", err);
		return;
	}
	if(err=pthread_create(&ntid2, NULL, MyThread2, NULL)){
		printf("Error: %d", err);
		return;
	}
	pthread_join(ntid1, NULL);
	pthread_join(ntid2, NULL);
	printf("main thread exit!\n");
}

int main(){
	thread_two();
	printf("HelloWorld!");
	return 0;
}
//Developed by Ercan COŞ.

/*
* This program aims to generate random coordinates between x= (−10→10) and y= (−2→2),
* and stores these coordinates in separate text files in respect to the cartesian quadrants.
* 
* The program uses thread mechanism. The number of threads T must be specified as a command line argument.
* 
* Each thread is responsible from generating random N(x,  y) points between the ranges mentioned above.
* 
* According to specified range, total number of points will be T∗N.
* 
* Also, N is defined as a command line argument.
* 
* In order to prevent incorrect access to these files by multiple threads,
* It uses semaphores and critical regions mechanisms that make sure each file is in use by only one thread at a time.
* 
* 
* 
* 
* This program uses Unix's pthread.h and semaphore.h libraries/mechanisms.
* So it is compatible with Unix based operating systems.
* --Usage: ./test NRTHREAD POINTSPERTHREAD
* 
*/



//Libraries..
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


//Prototypes..
float randfloat(float, float);
void initrand();
void* engine(void* arg);


//Global Part..
sem_t f_mutex_NE, f_mutex_NW, f_mutex_SW, f_mutex_SE, f_mutex_XY;
sem_t c_mutex_NE, c_mutex_NW, c_mutex_SW, c_mutex_SE, c_mutex_XY;
sem_t func_mutex;

//Counters.
int count_NE=0, count_NW=0, count_SW=0, count_SE=0, count_XY=0;


int main(int argc, char* argv[]) {
	
	if (argc <=2 ){
		printf("\n\nThe command line arguments are wrong. Program terminated ! \n\n\n");
		return -1;
	}
	
	//Command Line Arguments..
	int num_Thread = atoi(argv[1]), pointsPerThread = atoi(argv[2]);
	

	//Test case for num_Thread variable lower than 1.
	if(num_Thread<1){
		printf("\n\nThe command line arguments are wrong. Thread number can not lower than 1. Program terminated ! \n\n\n");
		return -9;
	}


	//Variables..
	int i;


	//Initiliaze mutex part.
	sem_init(&f_mutex_NE, 0, 1);
	sem_init(&f_mutex_NW, 0, 1);
	sem_init(&f_mutex_SW, 0, 1);
	sem_init(&f_mutex_SE, 0, 1);
	sem_init(&f_mutex_XY, 0, 1);

	sem_init(&c_mutex_NE, 0, 1);
	sem_init(&c_mutex_NW, 0, 1);
	sem_init(&c_mutex_SW, 0, 1);
	sem_init(&c_mutex_SE, 0, 1);
	sem_init(&c_mutex_XY, 0, 1);

	sem_init(&func_mutex, 0, 1);
	//..


	//File pointers.
	FILE* fptr_NE, *fptr_NW, *fptr_SW, *fptr_SE, *fptr_XY;


	//Reset Section
	//To reset each text file for each run.
	fptr_NE = fopen("ne.txt", "w");
	fptr_NW = fopen("nw.txt", "w");
	fptr_SW = fopen("sw.txt", "w");
	fptr_SE = fopen("se.txt", "w");
	fptr_XY = fopen("xy.txt", "w");
	

	if (fptr_NE == NULL || fptr_NW == NULL || fptr_SW == NULL || fptr_SE == NULL || fptr_XY == NULL) {
		printf("Error. File pointers can not assign correctly. Program Terminated !");
		return -2;
	}

	fclose(fptr_NE);
	fclose(fptr_NW);
	fclose(fptr_SW);
	fclose(fptr_SE);
	fclose(fptr_XY);

	//..
	//End of Reset Section.


	//Thread creation part..

	//printf("\n num_Thread : %d , pointsPerThread : %d \n", num_Thread, pointsPerThread);//DEBUG Purpose..
	pthread_t *threads= malloc((sizeof(pthread_t)* num_Thread));

	
	for(i=0;i<num_Thread;i++)
		pthread_create(&threads[i], NULL, engine, &pointsPerThread);

	//..


	//Waiting for processes of threads to done.
	for(i=0;i<num_Thread;i++)
		pthread_join(threads[i], NULL);

	//..


	printf("\n\n count_NE : %d , count_NW : %d , count_SW : %d , count_SE : %d , count_XY : %d \n\n\n",count_NE, count_NW, count_SW, count_SE, count_XY);

	return 0;
}//End of main function.


void initrand()
{
	srand((unsigned)(time(0)));
}


float randfloat(float min, float max)
{
	//return (((rand() % 1000) / (float)(max / 2)) + min)/100;
	return (((rand() % ((int)max*100-(int)min*100+1))+(min*100))/(float)100);
}


void* engine(void* arg){
	
	//Parameter from caller function.
	int num=*((int*)arg);

	//printf("\n num = %d \n",num);//DEBUG Purpose..

	//File pointers.
	FILE* fptr_NE, *fptr_NW, *fptr_SW, *fptr_SE, *fptr_XY;
	
	//Numbers.
	float x,y;
	int i;

	initrand();
	for (i = 0; i < num; i++) {
		sem_wait(&func_mutex);
		x = randfloat(-10, 10);
		y = randfloat(-2, 2);
		//printf("Coordinates : %f %f \n", x, y);//DEBUG Purpose..
		sem_post(&func_mutex);

		if (x > 0 && y > 0)
		{
			sem_wait(&f_mutex_NE);
			//printf("Your coordinates in I. quadrant. \n");//DEBUG Purpose..
			fptr_NE = fopen("ne.txt", "a");
			if (fptr_NE == NULL) {
				printf("\nError. File pointers can not assign correctly. Program Terminated !\n\n");
				return -3;
			}
			fprintf (fptr_NE, "%f %f\n",x,y);
			fclose(fptr_NE);
			sem_post(&f_mutex_NE);

			sem_wait(&c_mutex_NE);
			count_NE++;
			sem_post(&c_mutex_NE);
		}
		else if (x < 0 && y>0)
		{
			sem_wait(&f_mutex_NW);
			//printf("Your coordinates in II. quadrant. \n");//DEBUG Purpose..
			fptr_NW = fopen("nw.txt", "a");
			if (fptr_NW == NULL) {
				printf("\nError. File pointers can not assign correctly. Program Terminated !\n\n");
				return -3;
			}
			fprintf (fptr_NW, "%f %f\n",x,y);
			fclose(fptr_NW);
			sem_post(&f_mutex_NW);

			sem_wait(&c_mutex_NW);
			count_NW++;
			sem_post(&c_mutex_NW);
		}
		else if (x < 0 && y < 0)
		{
			sem_wait(&f_mutex_SW);
			//printf("Your coordinates in III. quadrant. \n");//DEBUG Purpose..
			fptr_SW = fopen("sw.txt", "a");
			if (fptr_SW == NULL) {
				printf("\nError. File pointers can not assign correctly. Program Terminated !\n\n");
				return -3;
			}
			fprintf (fptr_SW, "%f %f\n",x,y);
			fclose(fptr_SW);
			sem_post(&f_mutex_SW);

			sem_wait(&c_mutex_SW);
			count_SW++;
			sem_post(&c_mutex_SW);
		}
		else if (x > 0 && y < 0)
		{
			sem_wait(&f_mutex_SE);
			//printf("Your coordinates in IV. quadrant. \n");//DEBUG Purpose..
			fptr_SE = fopen("se.txt", "a");
			if (fptr_SE == NULL) {
				printf("\nError. File pointers can not assign correctly. Program Terminated !\n\n");
				return -3;
			}
			fprintf (fptr_SE, "%f %f\n",x,y);
			fclose(fptr_SE);
			sem_post(&f_mutex_SE);

			sem_wait(&c_mutex_SE);
			count_SE++;
			sem_post(&c_mutex_SE);
		}
		else
		{
			sem_wait(&f_mutex_XY);
			//printf("Your coordinates on axis. \n");//DEBUG Purpose..
			fptr_XY = fopen("xy.txt", "a");
			if (fptr_XY == NULL) {
				printf("\nError. File pointers can not assign correctly. Program Terminated !\n\n");
				return -3;
			}
			fprintf (fptr_XY, "%f %f\n",x,y);
			fclose(fptr_XY);
			sem_post(&f_mutex_XY);

			sem_wait(&c_mutex_XY);
			count_XY++;
			sem_post(&c_mutex_XY);
		}

	}
	return;
}

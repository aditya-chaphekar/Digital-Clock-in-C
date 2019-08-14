/*

Title: Digital Clock in C.
Author: Tr4cEr

*/
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

void main()
{
	//initializing required variables
	int hr=0,min=0, sec=0,idxToDel=0,i,result;
	char current[30];
	time_t rawtime;
	struct tm * timeinfo;
	//getting the date & time from the time library
	time (&rawtime);
	//coping the fetched time into current variable
	timeinfo = localtime(&rawtime);
	strcpy(current,asctime(timeinfo));
	clrscr();
	
	{
		//this block extracts the current hour of the day by removing additional info.
		for(i=0;i<11;i++)
			memmove(&current[idxToDel], &current[idxToDel + 1], strlen(current) - idxToDel);
		idxToDel = 3;
		for(i=0;i<10;i++)
			memmove(&current[idxToDel], &current[idxToDel + 1], strlen(current) - idxToDel);
		result = atoi( current );
		hr=result;
	}
	timeinfo = localtime(&rawtime);
	strcpy(current,asctime(timeinfo));

	{
		//this block extracts the current minute of the day by removing additional info.
		idxToDel = 0;
		for(i=0;i<14;i++)
			memmove(&current[idxToDel], &current[idxToDel + 1], strlen(current) - idxToDel);
		idxToDel = 3;
		for(i=0;i<7;i++)
			memmove(&current[idxToDel], &current[idxToDel + 1], strlen(current) - idxToDel);
		result = atoi( current );
		min=result;
	}

	timeinfo = localtime(&rawtime);
	strcpy(current,asctime(timeinfo));

	{
		//this block extracts the current second of the day by removing additional info.
		idxToDel = 0;
		for(i=0;i<17;i++)
			memmove(&current[idxToDel], &current[idxToDel + 1], strlen(current) - idxToDel);
		idxToDel = 3;
		for(i=0;i<4;i++)
			memmove(&current[idxToDel], &current[idxToDel + 1], strlen(current) - idxToDel);
		result = atoi( current );
		sec=result;
	}

	clrscr();
	/*
	the loop below will continue executing until a keyboard hit is detected
	this loop updates the output screen every second and displays the current time in hh:mm:ss format.
	*/
	while(!kbhit())
	{
		if(hr>=12)
			hr=0;
		printf("%d : %d : %d",hr,min,sec);
		delay(1000);
		clrscr();
		sec++;
		if(sec==60)
		{
			min++;
			if(min==60)
			{
				hr++;
				if(hr==12)
					hr=0;
				min=0;
			}
			sec=0;
		}
	}
}

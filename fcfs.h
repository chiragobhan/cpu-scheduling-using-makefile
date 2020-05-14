#include "init.h"
#ifndef FCFS_H
#define FCFS_H
#include <stdio.h>
#include <unistd.h>

void fcfs()
{

	FILE *fpo;
	fpo = fopen("output.txt", "w");

	n = initialize();
	printf("\nExecuting FCFS algorithm..\n");
	sleep(3);
	printf("\n\nProcess  Burst  Arrival  Waiting  Turnaround\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;

				t = b[i];
				b[i] = b[j];
				b[j] = t;

				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
	t1 = a[0];
	for (i = 0; i < n; i++)
	{
		if (t1 - a[i] < 0)
		{
			gant[ef][0] = -1;
			gant[ef++][1] = t1;
			t1 += a[i] - t1;
		}
		if (i == 0)
			w[i] = 0;
		else
			w[i] = t1 - a[i];
		gant[ef][0] = a[i];
		gant[ef++][1] = t1;
		t1 += b[i];
	}
	gant[ef][1] = t1;
	for (i = 0; i < n; i++)
	{
		ta[i] = b[i] + w[i];
	}
	for (i = 0; i < n; i++)
	{
		printf("P[%d] \t  %d \t  %d \t  %d \t\t  %d\n", p[i], b[i], a[i], w[i], ta[i]);
	}
	printf("\n\nAverage waiting time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += w[i];
	}
	aw = sum1 / n;
	printf("%f", aw);

	printf("\n\nAverage turn around time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += ta[i];
	}
	at = sum1 / n;
	printf("%f", at);
	fprintf(fpo, "First Come First Serve:\n\n");
	for (i = 0; i < ef; i++)
	{
		fprintf(fpo, "P[%d],%d,%d,\t", p[i], gant[i][1], gant[i + 1][1]);
	}
	fprintf(fpo, "\n\nAverage Waiting Time = %f\nAverage Turnaround Time = %f\n", aw, at);
	printf("\n\nThe Gantt chart is:\n\n");

	printf(" ");
	for (i = 0; i < ef; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i < ef; i++)
		printf(gant[i][0] == -1 ? "|   " : "| %d ", gant[i][0]);
	printf("|\n ");
	for (i = 0; i < ef; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i <= ef; i++)
		printf("%d   ", gant[i][1]);
}

#endif
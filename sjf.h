#include "init.h"
#ifndef SJF_H
#define SJF_H
#include <stdio.h>
#include <unistd.h>

void sjf()
{

	FILE *fpo;
	fpo = fopen("output.txt", "a");

	n = initialize();
	printf("\n\nExecuting SJF algorithm..\n");
	sleep(3);
	printf("\n\nProcess  Burst  Arrival  Waiting  Turnaround\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if ((a[i] > a[j]) || ((a[i] == a[j]) && (b[i] > b[j])))
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
	k = a[0] + b[0];
	for (i = 1; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (b[i] > b[j] && k >= a[j])
			{
				m = 1;

				t = b[i];
				b[i] = b[j];
				b[j] = t;

				t = a[i];
				a[i] = a[j];
				a[j] = t;

				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
		if (m == 0)
			k = k + b[i];
		else
			k++;
		m = 0;
	}

	t1 = 0;
	for (i = 0; i < n; i++)
	{
		if (t1 - a[i] < 0)
		{
			gantt[e][0] = -1;
			gantt[e++][1] = t1;
			t1 += a[i] - t1;
		}
		if (i == 0)
			w[i] = 0;
		else
			w[i] = t1 - a[i];
		gantt[e][0] = a[i];
		gantt[e++][1] = t1;
		t1 += b[i];
	}
	gantt[e][1] = t1;
	for (i = 0; i < n; i++)
	{
		ta[i] = b[i] + w[i];
	}
	for (i = 0; i < n; i++)
	{
		printf("P[%d] \t  %d \t  %d \t  %d \t\t  %d\n", p[i], b[i], a[i], w[i], ta[i]);
	}
	printf("\nAverage waiting time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += w[i];
	}
	aw = sum1 / n;
	printf("%.2f", aw);

	printf("\nAverage turn around time is:");
	sum1 = 0.0;
	for (i = 0; i < n; i++)
	{
		sum1 += ta[i];
	}
	at = sum1 / n;
	printf("%.2f", at);
	printf("\n\nThe Gantt chart is:\n\n");

	printf(" ");
	for (i = 0; i < e; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i < e; i++)
	{
		printf(gantt[i][0] == -1 ? "|   " : "| %d ", gantt[i][0]);
	}
	fprintf(fpo, "\n\nShortest Job First:\n\n");
	for (i = 0; i < e; i++)
	{
		fprintf(fpo, "P[%d],%d,%d,\t", p[i], gantt[i][1], gantt[i + 1][1]);
	}
	fprintf(fpo, "\n\nAverage Waiting Time = %.2f\nAverage Turnaround Time = %.2f\n", aw, at);
	printf("|\n ");
	for (i = 0; i < e; i++)
		printf("--- ");
	printf("\n");
	for (i = 0; i <= e; i++)
		printf("%d   ", gantt[i][1]);
	printf("\n");
}

#endif
#ifndef INIT_H
#define INIT_H
#include <stdio.h>
#include <unistd.h>

#define MAX 100

int p[MAX], a[MAX], b[MAX], w[MAX], ta[MAX], t1, gantt[MAX][2], gant[MAX][2];
int i, j, n, k, t, sum = 0, ef = 0, e = 0, m = 0;
float aw, at, sum1;

int initialize()
{
  int n, n1, n2, n3, i = 0;
  FILE *fp;
  fp = fopen("input.txt", "r");
  if (fp == NULL)
  {
    printf("Error locating the file. Please try again!\n");
    exit(1);
  }

  while (fscanf(fp, "%d,%d,%d,", &n1, &n2, &n3) != EOF)
  {

    p[i] = n1;

    if (p[i] > MAX)
    {
      printf("Woah! I am not a super computer. Please input upto 100 processes :)\n");
      exit(1);
    }

    b[i] = n2;

    a[i] = n3;
    i++;
  }

  fclose(fp);

  return i;
}

#endif
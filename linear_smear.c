#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double linear(double m, double x, double b)
{
  return m*x+b;
}

int main(void)
{
  double m;
  double x;
  double b;
  int i;
  srand(time(NULL));
  m=10.0*(double)rand()/(double)RAND_MAX;
  for(i=0;i<1000;i++)
  {
     x=5000*(double)rand()/(double)RAND_MAX;
     b=3000*(double)rand()/(double)RAND_MAX;
     printf("%lf\t%lf\n",x,linear(m,x,b));

  }
  return 0;
}



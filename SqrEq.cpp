#include <stdio.h>
#include <math.h>

int SquareEq(double a, double b, double c, double* x1, double* x2);

int main(){

  double a = 0, b = 0, c = 0;
  double x1 = 0, x2 = 0;
  int NumberOfRoots = 0;

  printf("Enter a, b, c \n");
  scanf("%lg %lg %lg", &a, &b, &c);

  NumberOfRoots = SquareEq(a, b, c, &x1, &x2);

  switch(NumberOfRoots){
    case 0: printf("No roots");
            break;
    case 1: printf("x = %lg", x1);
            break;
    case 2: printf("x1 = %lg \nx2 = %lg", x1, x2);
            break;
    case -1: printf("Any x");
             break;
    default: printf("ERROR: Number of roots out of range %d", NumberOfRoots);
             break;
  }

  return 0;
}

int SquareEq(double a, double b, double c, double* x1, double* x2){
  if(a == 0){
    if(b == 0){
      return (c == 0)? -1 : 0;
    }
    else{ /*if (b != 0)*/
      *x1 = -c/b;
      return 1;
    }
  }
  else{  /*if (a != 0)*/
    int d = b*b - 4*a*c;

    if(d < 0){
      return 0;
    }
    else if (d == 0){
      *x1 = -b/(2*a);
      return 1;
    }
    else{ /*if (d > 0)*/
      *x1 = (-b + sqrt(d))/(2*a);
      *x2 = (-b - sqrt(d))/(2*a);
      return 2;
    }
  }
}

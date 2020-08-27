#include <stdio.h>
#include <math.h>
#include <assert.h>

#define INF_ROOTS -1

int SquareEq(double a, double b, double c, double* x1, double* x2);

int main(){

  //const int INF_ROOTS = -1;

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
    case INF_ROOTS: printf("Any x");
             break;
    default: printf("ERROR: Number of roots out of range %d", NumberOfRoots);
             break;
  }

  return 0;
}


//-----------------------------------------------------------------------------
//!  This function solve square equations
//!
//!  @param [in]   a  first coefficient
//!  @param [in]   b  second coefficient
//!  @param [in]   c  third coefficient
//!  @param [out]  x1 first root
//!  @param [out]  x2 second root
//!
//!  @return Number of roots
//-----------------------------------------------------------------------------

int SquareEq(double a, double b, double c, double* x1, double* x2){

  assert(std::isfinite (a));
  assert(std::isfinite (b));
  assert(std::isfinite (c));

  assert(x1 != NULL);
  assert(x2 != NULL);
  assert(x1 != x2);

  if(a == 0){
    if(b == 0){
      return (c == 0)? INF_ROOTS : 0;
    }
    else{ /*if (b != 0)*/
      *x1 = -c/b;
      return 1;
    }
  }
  else{  /*if (a != 0)*/
    double d = b*b - 4*a*c;

    if(d < -0.000001){
      return 0;
    }
    else if (d >= -0.000001 && d <= 0.000001){
      *x1 = -b/(2*a);
      return 1;
    }
    else{ /*if (d > 0.000001)*/
      *x1 = (-b + sqrt(d))/(2*a);
      *x2 = (-b - sqrt(d))/(2*a);
      return 2;
    }
  }
}

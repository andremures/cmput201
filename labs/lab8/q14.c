/**********************************************/
/* q14.c                                      */
/* Andreea Muresan                            */
/* SID: 1498868                               */
/**********************************************/

#define N 10                 // took away =
#define INC(x) x+1
#define SUB (x,y) x-y
#define SQR(x) ((x)*(x))
#define CUBE(x) (SQR(x)*(x))
#define M1(x,y) x##y
#define M2(x,y) #x #y

int main(void)
{
  int a[N], i, j, k, m;

#ifdef N
  i = j;
#else
  j = i;
#endif
  int jk;                    // defined jk for line 23
  i = 10 * INC(j);
  i = SUB(j, k);
  i = SQR(SQR(j));
  i = M1(j, k);
  puts(M2(i, j));

#undef SQR
  // i = SQR(j);             // SQR was undefined in line 26 so it cannot be called
#define SQR
  i = SQR(j);

  return 0;
}

// AFTER PREPROCESSING:

//
//
//
//
//
//
//
//
// int main(void)
// {
//   int a[N], i, j, k, m;
//
//
//   i = j;
//
//
//
//
//   i = 10 * INC(j);
//   i = SUB(j, k);
//   i = SQR(SQR(j));
//   i = M1(j, k);
//   puts(M2(i, j));
//
//
//   i = SQR(j);
//
//   i = SQR(j);
//
//   return 0;
// }

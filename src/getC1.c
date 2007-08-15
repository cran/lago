#include "lago.h"

void getC1( int *y, int *numRows, int *numCols, int *n1r, double *Xr, double *C1r )
{

  int i, j, n1;
  int n, index, index1, p;
  
  //Convert X from array form to 2-D array
  typedef struct Arr
  {
    double *arr;
  }Arr, *pArr;

  pArr *X, *C1;

  n1 = (*n1r);
  n = (*numRows);
  p = (*numCols);

//  if( ( X = ( pArr * ) Calloc( sizeof( Arr ) * n, Arr ) ) == NULL )
//  if( ( X = ( pArr * ) malloc( sizeof( Arr ) * n ) ) == NULL )
  if( ( X = ( pArr * ) R_alloc(n, sizeof( Arr ) ) ) == NULL )
    {
      printf("Insufficient memory.  Program terminating.\n");
      exit(1);
    }
  for( i = 0; i < n; i++ )
    {
//      if( ( X[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//      if( ( X[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
      if( ( X[i] = ( pArr ) R_alloc(1, sizeof(Arr) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
//      if( ( X[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//      if( ( X[i]->arr = ( double * ) malloc( p*sizeof(double) ) ) == NULL )
      if( ( X[i]->arr = ( double * ) R_alloc(p, sizeof(double) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
    }

  index = 0;
  for( i = 0; i < p; i++ )
    {
      for( j = 0; j < n; j++ )
        {
          X[j]->arr[i] = Xr[index];
          index++;
        }
    }
  // End of conversion


  //Divide X into C1
//  if( ( C1 = ( pArr * ) Calloc( sizeof( Arr ) * n1, Arr ) ) == NULL )
//  if( ( C1 = ( pArr * ) malloc( sizeof( Arr ) * n1 ) ) == NULL )
  if( ( C1 = ( pArr * ) R_alloc(n1, sizeof( Arr ) ) ) == NULL )
    {
      printf("Insufficient memory.  Program terminating.\n");
      exit(1);
    }
  for( i = 0; i < n1;i++ )
    {
//      if( ( C1[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//      if( ( C1[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
      if( ( C1[i] = ( pArr ) R_alloc(1, sizeof(Arr) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
//      if( ( C1[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//      if( ( C1[i]->arr = ( double * ) malloc( p*sizeof(double) ) ) == NULL )
      if( ( C1[i]->arr = ( double * ) R_alloc(p, sizeof(double) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
    }

  index1 = 0;


  for( i = 0; i < n; i++ )
  {
    if( y[i] == 1 )
      {
	// put observation in C0
	for( j = 0; j < p; j++ )
	{
		C1[index1]->arr[j] = X[i]->arr[j];
	}
	index1++;
      }
   }

  // Convert X, C0, and C1 to R array format.
  index=0;
  for( i = 0; i < p;i++)
    {
      for( j = 0; j < n; j++ )
        {
          Xr[index] = X[j]->arr[i];
          index++;
        }
    }

  index=0;
  for(i = 0; i < p; i++)
    {
      for( j = 0; j < n1; j++ )
	{
	  C1r[index] = C1[j]->arr[i];
	  index++;
	}
    }

   //end of conversions

/* Free XD, C1

  for( i = 0; i < n; i++ )
  {
    current = X[i];
    Free(current->arr);
  }
  Free(X);

  for( i = 0; i < n1; i++ )
  {
    current = C1[i];
    Free(current->arr);
  }
  Free(C1);
*/
  return;
}

#include "lago.h"

void getC0( int *y, int *numRows, int *numCols, int * n0r, double *Xr, double *C0r )
{

  int i, j, n0;
  int n, index, index0, p;
 
  
  //Convert X from array form to 2-D array
  typedef struct Arr
  {
    double *arr;
  }Arr, *pArr;

  pArr *X, *C0;

  n0= (*n0r);
  n = (*numRows);
  p = (*numCols);

  
//  if( ( X = ( pArr * ) Calloc( sizeof( Arr ) * n, Arr ) ) == NULL )
//  if( ( X = ( pArr * ) malloc( sizeof( Arr ) * n ) ) == NULL )
  if( ( X = ( pArr * ) R_alloc(n, sizeof(Arr) ) ) == NULL )
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
	  printf("Insufficient memory, program terminating.\n");
	  exit(1);
	}
//      if( ( X[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//      if( ( X[i]->arr = ( double * ) malloc( p*sizeof(double) ) ) == NULL )
      if( ( X[i]->arr = ( double * ) R_alloc(p, sizeof(double) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
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

 
  //Divide X into C0 and C1
//  if( ( C0 = ( pArr * ) Calloc( sizeof( Arr ) * n0, Arr ) ) == NULL )
//  if( ( C0 = ( pArr * ) malloc( sizeof( Arr ) * n0 ) ) == NULL )
  if( ( C0 = ( pArr * ) R_alloc(n0, sizeof( Arr ) ) ) == NULL )
    {
      printf("Insufficient memory.  Program Terminating.\n");
      exit(1);
    }
  for( i = 0; i < n0;i++ )
    {
//      if( ( C0[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//      if( ( C0[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
      if( ( C0[i] = ( pArr ) R_alloc(1, sizeof(Arr) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program Terminating.\n");
	  exit(1);
	}
//      if( ( C0[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//      if( ( C0[i]->arr = ( double * ) malloc( p*sizeof(double) ) ) == NULL )
      if( ( C0[i]->arr = ( double * ) R_alloc(p, sizeof(double) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program Terminating.\n");
	  exit(1);
	}
    }

  index0 = 0;


  for( i = 0; i < n; i++ )
  {
    if( y[i] == 0 )
      {
	// put observation in C0
	for( j = 0; j < p; j++ )
	{
		C0[index0]->arr[j] = X[i]->arr[j];
	}
	index0++;
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
      for( j = 0; j < n0; j++ )
	{
	  C0r[index] = C0[j]->arr[i];
	  index++;
	}
    }

   //end of conversions

/* Free X, C0

  for( i = 0; i < n; i++ )
  {
    current = X[i];
    Free(current->arr);
  }
  Free(X);

  for( i = 0; i < n0; i++ )
  {
    current = C0[i];
    Free(current->arr);
  }
  Free(C0);
*/
   return;
}

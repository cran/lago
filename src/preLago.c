#include "lago.h"

void preLago( int *y, double *C0r, double *C1r, int *n0r, int *n1r, int *pr, double *Dr)
{
  int i, j, k;
  double dist;
  int n0, n1, p;
  
  typedef struct Arr
  {
    double *arr;
  }Arr, *pArr;

  pArr *C0, *C1, *D;
  int in;

  n0 = (*n0r);
  n1 = (*n1r);
  p = (*pr);
 
//  if( ( D = ( pArr * ) Calloc( sizeof( Arr ) * n1, Arr) ) == NULL )
//  if( ( D = ( pArr * ) malloc( sizeof( Arr ) * n1 ) ) == NULL )
  if( ( D = ( pArr * ) R_alloc(n1, sizeof( Arr ) ) ) == NULL )
    {
      printf("Insufficient memory.  Program terminating\n");
      exit(1);
    }
  for( i = 0; i < n1; i++ )
    {
//      if( (  D[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//      if( (  D[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
      if( (  D[i] = ( pArr ) R_alloc(1, sizeof(Arr) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
//      if( ( D[i]->arr = ( double * ) Calloc( n0*sizeof(double), double) ) == NULL )
//      if( ( D[i]->arr = ( double * ) malloc( n0*sizeof(double) ) ) == NULL )
      if( ( D[i]->arr = ( double * ) R_alloc( n0, sizeof(double) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
    }

//  if( ( C0 = ( pArr * ) Calloc( sizeof( Arr ) * n0, Arr) ) == NULL )
//  if( ( C0 = ( pArr * ) malloc( sizeof( Arr ) * n0 ) ) == NULL )
  if( ( C0 = ( pArr * ) R_alloc(n0, sizeof( Arr ) ) ) == NULL )
    {
      printf("Insufficient memory.  Program Terminating.\n");
      exit(1);
    }
  for( i = 0; i < n0; i++ )
    {
//      if( ( C0[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//      if( ( C0[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
      if( ( C0[i] = ( pArr ) R_alloc(1, sizeof(Arr) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
//      C0[i]->arr = ( double * ) Calloc( p*sizeof(double), double);
//      C0[i]->arr = ( double * ) malloc( p*sizeof(double) );
      C0[i]->arr = ( double * ) R_alloc( p, sizeof(double));
    }

  in = 0;
  for( i = 0; i < p; i++ )
    {
      for( j = 0; j < n0; j++ )
        {
          C0[j]->arr[i] = C0r[in];
          in++;
        }
    }
 
//  if( ( C1 = ( pArr * ) Calloc( sizeof( Arr ) * n1, Arr ) ) == NULL )
//  if( ( C1 = ( pArr * ) malloc( sizeof( Arr ) * n1 ) ) == NULL )
  if( ( C1 = ( pArr * ) R_alloc(n1, sizeof( Arr ) ) ) == NULL )
    {
      printf("Insufficient memory.  Program terminating\n");
      exit(1);
    }
  for( i = 0; i < n1; i++ )
    {
//      if( ( C1[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//      if( ( C1[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
      if( ( C1[i] = ( pArr ) R_alloc(1, sizeof(Arr) ) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating\n");
	  exit(1);
	}

//      if( ( C1[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//      if( ( C1[i]->arr = ( double * ) malloc( p*sizeof(double)) ) == NULL )
      if( ( C1[i]->arr = ( double * ) R_alloc( p, sizeof(double)) ) == NULL )
	{
	  printf("Insufficient memory.  Program terminating.\n");
	  exit(1);
	}
    }

  
  in = 0;
  for( i = 0; i < p; i++ )
    {
      for( j = 0; j < n1; j++ )
        {
          C1[j]->arr[i] = C1r[in];
          in++;
        }
    }
  
  // End of converts
  
   
   //D(i,j) = distance between the i'th observation in C1 and the j'th observation in C0
  //      lowercase( m );

    for( i = 0; i < n1; i++ )
      {
	for( j = 0; j < n0; j++ )
        {
	  dist = 0;
          for( k = 0; k < p; k++ )
          {
             dist = dist + ( ( C1[i]->arr[k] - C0[j]->arr[k] ) * ( C1[i]->arr[k] - C0[j]->arr[k] ) );
          }

          D[i]->arr[j] = sqrt( dist );
          }
       }

  in = 0;
  for( i = 0; i < n0;i++)
    {
      for( j = 0; j < n1; j++ )
        {
	  Dr[in] = D[j]->arr[i];
          in++;
        }
    }
  

/* FREE D, C0, C1

  for( i = 0; i < n1; i++ )
  {
    current = D[i];
    Free(current->arr);
  }
  Free(D);

  for( i = 0; i < n0; i++ )
  {
    current = C0[i];
    Free(current->arr);
  }
  Free(C0);

  for(i = 0; i < n1; i++ )
  {
    current = C1[i];
    Free(current->arr);
  }
  Free(C1);
*/

return;
}

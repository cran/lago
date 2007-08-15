#include "lago.h"

void sLagoLearn( int *Y, double *Xr, double *Dr,  double *C0r, double *C1r, int *nr, int *pr, int *n0r, int *n1r, int *kr, double *ar, double *R )
{

// copied from Alexandra's predictLago.c and modified by Mu Zhu, Feb 2006

  int i, j, h, n, n0, n1,k,p;
  double a;
	double *KNeighbours;
	int *index;
	int myindex;
	int temp;
	double value;
	double sum;
	int biggestIndex;
	double biggestValue;
	double ratio;
	
	//Convert X from array form to 2-D array
	typedef struct Arr
	{
	  double *arr;
	}Arr, *pArr;

	pArr *X, *D, *C0, *C1;
	
	n = (*nr);
	n1 = (*n1r);
	n0 = (*n0r);
	p = (*pr);
//	N = (*nrNew);
	a = (*ar);
	k = (*kr);

//	if( ( X = ( pArr * ) Calloc( sizeof( Arr ) * n, Arr )) == NULL )
//	if( ( X = ( pArr * ) malloc( sizeof( Arr ) * n )) == NULL )
	if( ( X = ( pArr * ) R_alloc(n, sizeof( Arr ) )) == NULL )
	  {
	    printf("Error.  Insufficient memory.  Program terminating.\n");
	    exit(1);
	  }

	for( i = 0; i < n; i++ )
	  {
//	    if( ( X[i] = ( pArr ) Calloc( sizeof(Arr), Arr )) == NULL )
//	    if( ( X[i] = ( pArr ) malloc( sizeof(Arr) )) == NULL )
	    if( ( X[i] = ( pArr ) R_alloc(1, sizeof(Arr) )) == NULL )
	      {
		printf("Error.  Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
//	    if( ( X[i]->arr = ( double * ) Calloc( p*sizeof(double), double)) == NULL )
//	    if( ( X[i]->arr = ( double * ) malloc( p*sizeof(double))) == NULL )
	    if( ( X[i]->arr = ( double * ) R_alloc( p, sizeof(double))) == NULL )
	      {
		printf("Error.  Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
	  }
	
	myindex = 0;
	for( i = 0; i < p; i++ )
	  {
	    for( j = 0; j < n; j++ )
	      {
		X[j]->arr[i] = Xr[myindex];
		myindex++;
	      }
	  }
	// End of conversion

//	if( ( D = ( pArr * ) Calloc( sizeof( Arr ) * n1, Arr ) ) == NULL )
//	if( ( D = ( pArr * ) malloc( sizeof( Arr ) * n1 ) ) == NULL )
	if( ( D = ( pArr * ) R_alloc( n1, sizeof( Arr ) ) ) == NULL )
	  {
	    printf("Error.  Insufficient memory.  Program terminating.\n");
	    exit(1);
	  }

	for( i = 0; i < n1; i++ )
	  {
//	    if( ( D[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//	    if( ( D[i] = ( pArr ) malloc( sizeof(Arr) ) ) == NULL )
	    if( ( D[i] = ( pArr ) R_alloc( 1, sizeof(Arr) ) ) == NULL )
	      {
		printf("Error.  Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
//	    if( ( D[i]->arr = ( double * ) Calloc( n0*sizeof(double), double) ) == NULL )
//	    if( ( D[i]->arr = ( double * ) Calloc( n0*sizeof(double)) ) == NULL )
	    if( ( D[i]->arr = ( double * ) R_alloc( n0,sizeof(double)) ) == NULL )
	      {
		printf("Error. Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
	  }
	
	myindex = 0;
	for( i = 0; i < n0; i++ )
	  {
	    for( j = 0; j < n1; j++ )
	      {
		D[j]->arr[i] = Dr[myindex];
		myindex++;
	      }
	  }
	// End of conversion

//	if( ( C0 = ( pArr * ) Calloc( sizeof( Arr ) * n0, Arr ) ) == NULL )
//	if( ( C0 = ( pArr * ) malloc( sizeof( Arr ) * n0 ) ) == NULL )
	if( ( C0 = ( pArr * ) R_alloc( n0, sizeof( Arr )  ) ) == NULL )
	  {
	    printf("Insufficient memory.  Program terminating.\n");
	    exit(1);
	  }

	for( i = 0; i < n0; i++ )
	  {

//	    if( ( C0[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//	    if( ( C0[i] = ( pArr ) malloc( sizeof(Arr)) ) == NULL )
	    if( ( C0[i] = ( pArr ) R_alloc( 1, sizeof(Arr) ) ) == NULL )
	      {
		printf("Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
//	    if( ( C0[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//	    if( ( C0[i]->arr = ( double * ) malloc( p*sizeof(double)) ) == NULL )
	    if( ( C0[i]->arr = ( double * ) R_alloc( p, sizeof(double)) ) == NULL )
	      {
		printf("Insuffcient memory.  Program terminating\n");
		exit(1);
	      }
	  }

	
	myindex = 0;
	for( i = 0; i < p; i++ )
	  {
	    for( j = 0; j < n0; j++ )
	      {
		C0[j]->arr[i] = C0r[myindex];
		myindex++;
	      }
	  }
	// End of conversion
//	if( ( C1 = ( pArr * ) Calloc( sizeof( Arr ) * n1, Arr ) ) == NULL )
//	if( ( C1 = ( pArr * ) malloc( sizeof( Arr ) * n1 ) ) == NULL )
	if( ( C1 = ( pArr * ) R_alloc( n1, sizeof( Arr )) ) == NULL )
	  {
	    printf("Insufficient memory.  Program terminating.\n");
	    exit(1);
	  }
	for( i = 0; i < n1; i++ )
	  {
//	    if( ( C1[i] = ( pArr ) Calloc( sizeof(Arr), Arr ) ) == NULL )
//	    if( ( C1[i] = ( pArr ) malloc( sizeof(Arr)) ) == NULL )
	    if( ( C1[i] = ( pArr ) R_alloc( 1, sizeof(Arr) ) ) == NULL )
	      {
		printf("Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
//	    if( ( C1[i]->arr = ( double * ) Calloc( p*sizeof(double), double) ) == NULL )
//	    if( ( C1[i]->arr = ( double * ) malloc( p*sizeof(double)) ) == NULL )
	    if( ( C1[i]->arr = ( double * ) R_alloc( p,sizeof(double)) ) == NULL )
	      {
		printf("Insufficient memory.  Program Terminating.\n");
		exit(1);
	      }
	  }
       
	myindex = 0;
	for( i = 0; i < p; i++ )
	  {
	    for( j = 0; j < n1; j++ )
	      {
		C1[j]->arr[i] = C1r[myindex];
		myindex++;
	      }
	  }
	// End of conversion

/*
	i = 0;

	while ( (*kernel)[i] )
	  {
	    (*kernel)[i] = tolower((*kernel)[i]);
	    i++;
	  }
*/

	//ratio = sqrt( 5.642879 / 2 );
	ratio = 1;

	if( ( k > n0 ) || ( k <= 0 ) )
	{
		printf("k cannot be greater than n0 or smaller than 1.  Program is terminating...\n" );
		exit(-1);
	}

	// Allocate space for array K and array index
//	if( ( KNeighbours = ( double * ) Calloc( sizeof( double ) * k, double ) ) == NULL )
//	if( ( KNeighbours = ( double * ) malloc( sizeof( double ) * k ) ) == NULL )
	if( ( KNeighbours = ( double * ) R_alloc( k, sizeof( double ) ) ) == NULL )
	{
		printf("Error 107.  Program Terminating...\n");
		exit(1);
	}
//	if( ( index = ( int * ) Calloc( sizeof( int ) * k, int ) ) == NULL )
//	if( ( index = ( int * ) malloc( sizeof( int ) * k) ) == NULL )
	if( ( index = ( int * ) R_alloc( k, sizeof( int ) ) ) == NULL )
	{
		printf("Error 108.  Program Terminating...\n");
		exit(1);
	}

	
	// Step 2:  Split X into two parts

	// DONE

	// Step 3:  For every observation in C1
	//			- find its K-nearest neighbors in C0 using the information contained in D
	//			- calculate and store its radius vector as a row in R


	
	for( i = 0; i < n1; i++ )	// for every observation in C1
	{
		for( j = 0; j < n0; j++ )
		{
			
			value = D[i]->arr[j];

			if( j < k )
			{
				KNeighbours[j] = value;
				index[j] = j;
			}
			else
			{
				biggestValue = KNeighbours[0];
				biggestIndex = 0;

				for( h = 1; h < k; h++ )
				{
					if( KNeighbours[h] > biggestValue )
					{
						biggestValue = KNeighbours[h];
						biggestIndex = h;
					}
				}

				if( value < biggestValue )
				{
					KNeighbours[biggestIndex] = value;
					index[biggestIndex] = j;
				}
	
			}
			
		}// end of j loop

		
		// for sLago, there is no need to loop over dimensions, comment by Mu Zhu
		sum = 0;
		
		for( h = 0; h < k; h++ )
		{
			temp = index[h];
			sum = sum + D[i]->arr[temp];
		}

		sum = sum / k;

		R[i] = sum;
		

	}// end of i loop
       
myindex=0;
  for( i = 0; i < p;i++)
    {
      for( j = 0; j < n; j++ )
        {
          Xr[myindex] = X[j]->arr[i];
          myindex++;
        }
    }

myindex=0;
  for( i = 0; i < p;i++)
    {
      for( j = 0; j < n0; j++ )
        {
          C0r[myindex] = C0[j]->arr[i];
         myindex++;
        }
    }

myindex=0;
  for( i = 0; i < p;i++)
    {
      for( j = 0; j < n1; j++ )
        {
          C1r[myindex] = C1[j]->arr[i];
          myindex++;
        }
    }

myindex=0;
  for( i = 0; i < n0;i++)
    {
      for( j = 0; j < n1; j++ )
        {
          Dr[myindex] = D[j]->arr[i];
          myindex++;
        }
    }
/*
for( i = 0; i < n; i++ )
  {
    current = X[i];
    Free(current->arr);
  }
  Free(X);
 
for( i = 0; i < N; i++ )
  {
    current = validateX[i];
    Free(current->arr);
  }
  Free(validateX);
 
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

for( i = 0; i < n1; i++ )
  {
    current = C1[i];
    Free(current->arr);
  }
  Free(C1);

  Free(R);
  Free( index );
  Free( KNeighbours );
*/
  // Return R
  return;
}

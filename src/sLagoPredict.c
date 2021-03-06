#include "lago.h"

void sLagoPredict(double *C1r, int *pr, int *n1r, double *R, double *Xnewr, int *nrNew, double *ar, char **kernel, double *score)
{

// copied from Alexandra's predictLago.c and modified by Mu Zhu, Feb 2006

        int i, j, h, n1,N, p;
        double a;
	int myindex;
	double ratio, tempScore;
	
	//Convert X from array form to 2-D array
	typedef struct Arr
	{
	  double *arr;
	}Arr, *pArr;

	pArr *validateX, *C1;
	n1 = (*n1r);
	p = (*pr);
	N = (*nrNew);
	a = (*ar);

	if( ( validateX = ( pArr * ) R_alloc( N, sizeof( Arr ) ) ) == NULL )
	  {
	    printf("Error.  Insufficient memory.  Program Terminating.\n");
	    exit(1);
	  }

	for( i = 0; i < N; i++ )
	  {
	    if( ( validateX[i] = ( pArr ) R_alloc( 1, sizeof(Arr) ) ) == NULL )
	      {
		printf("Error.  Insufficient memory.  Program Terminating.\n");
		exit(1);
	      }

	    if( ( validateX[i]->arr = ( double * ) R_alloc( p, sizeof(double) ) ) == NULL )
	      {
		printf("Error.  Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
	  }
	
	myindex = 0;
	for( i = 0; i < p; i++ )
	  {
	    for( j = 0; j < N; j++ )
	      {
		validateX[j]->arr[i] = Xnewr[myindex];
		myindex++;
	      }
	  }
	// End of conversion

	if( ( C1 = ( pArr * ) R_alloc( n1, sizeof( Arr )) ) == NULL )
	  {
	    printf("Insufficient memory.  Program terminating.\n");
	    exit(1);
	  }
	for( i = 0; i < n1; i++ )
	  {
	    if( ( C1[i] = ( pArr ) R_alloc( 1, sizeof(Arr) ) ) == NULL )
	      {
		printf("Insufficient memory.  Program terminating.\n");
		exit(1);
	      }
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


	i = 0;

	while ( (*kernel)[i] )
	  {
	    (*kernel)[i] = tolower((*kernel)[i]);
	    i++;
	  }

	//ratio = sqrt( 5.642879 / 2 );
	ratio = 1;

	// Step 5: LAGO prediction
	for( i = 0; i < N; i++ ) // for each new observation
	{
		//Calculate LAGO prediction using the kernel function
		score[i] = 0;

		for( h = 0; h < n1; h++ )
		{
		  if( strcmp( (*kernel), "g" ) == 0 )		// Kernel = Gaussian
			{
			  
				tempScore = 0;

				for( j = 0; j < p; j++ )
				{
				  if( a*R[h] != 0 )
				  	tempScore = tempScore + pow( ( ( validateX[i]->arr[j] - C1[h]->arr[j] ) * ratio ) / ( a * R[h] ), 2 ) * ( -1 );
				  else
				    tempScore = 1;
				}
				tempScore = exp( tempScore);
			
			}

		  else if( strcmp( (*kernel), "t" ) == 0 )	// Kernel = Triangular; modified by Mu Zhu Feb 2006 'tr'->'t'
			{
				tempScore = 0;

				// here I use the variable tempScore to store distance, comment by Mu Zhu
				for( j = 0; j < p; j++ )
				{
					tempScore += pow( ( validateX[i]->arr[j] - C1[h]->arr[j] ), 2 );
				}
				tempScore =  sqrt(tempScore);

					
				if( tempScore > ( a * R[h]) ) 
				{
					tempScore = 0;		// now tempScore gets its real meaning
				}
				else
				{
				  if( a*R[h] != 0 )
					tempScore = 1-tempScore/(a*R[h]);
				  else
				    tempScore = 1;
				}

			}

			else									// Kernel = Uniform
			{
			// this part not modified yet, still old code for rLago, won't be using uniform kernel in sLago
				tempScore = 1;

				for( j = 0; j < p; j++ )
				{
				  if( (a*R[h] == 0) || ( fabs( validateX[i]->arr[j] - C1[h]->arr[j] ) / ( a * R[h] ) ) > 1 )
					{
						tempScore = 0;
						break;
					}
				}
			}
			score[i] = score[i] + tempScore;
		}
		score[i] = score[i] / n1;
	}

myindex=0;
  for( i = 0; i < p;i++)
    {
      for( j = 0; j < N; j++ )
        {
          Xnewr[myindex] = validateX[j]->arr[i];
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


  // Return score
  return;
}

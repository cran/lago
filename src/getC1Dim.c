void getC1Dim(int *y, int *size, int *n1)
{
  int i, counter=0;

  for( i = 0; i < *size; i++ )
    {
      if( y[i] == 1 )
	counter++;
    }

  *n1 = counter;
  return;
}

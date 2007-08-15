void getC0Dim( int *y, int *size, int *n0 )
{
  int i;
  int counter = 0;

  for( i = 0; i < *size; i++ )
    {
      if( y[i] == 0 )
	counter++;
    }

  *n0 = counter;
  return;
}

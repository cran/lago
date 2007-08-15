C1func <- function( Y, X, n1 )
{
	Y <- data.matrix(Y)
	X <- data.matrix(X)

	C1 <- myC1(Y,X,n1)

	C1 <- matrix(C1,n1,ncol(X))

	return(C1)
}

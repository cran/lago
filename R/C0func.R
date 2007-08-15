C0func <- function( Y, X, n0 )
{
	Y <- data.matrix(Y)
	X <- data.matrix(X)

	C0 <- myC0(Y,X,n0)

	C0 <- matrix(C0,n0,ncol(X))

	return(C0)
}

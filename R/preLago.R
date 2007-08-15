preLago <- function( y, X )
{
	Y<-data.matrix(y)
	X<-data.matrix(X)

	p<-ncol(X)

	# Get n0 and n1
	n0<- myn0(Y)
	n1<- myn1(Y)

	# Get C0 and convert it into a matrix
	C0 <- myC0(Y, X, n0)
	C0 <- matrix(C0,n0,ncol(X))

	C1 <- myC1(Y,X,n1)
	C1 <- matrix(C1,n1,ncol(X))

	D <- learn(Y,C0,C1,n0,n1,p)
	D <- matrix(D,n1,n0)
	
	return(D)
}


sLago <- function( Y, X, D = NULL, alpha = 1, K = 5, kernel='t' )
{
	Y<-data.matrix(Y)
        X<-data.matrix(X)

	n0 <- myn0(Y)
	n1 <- myn1(Y)

	C0 <- C0func(Y,X,n0)
	C1 <- C1func(Y,X,n1)

        if (is.null(D)) D <- preLago(Y,X)

	R <- .C( "sLagoLearn",
	as.integer(Y),
	as.double(X),
	as.double(D),
	as.double(C0),
	as.double(C1),
	as.integer(nrow(X)),
	as.integer(ncol(X)),
	as.integer(nrow(C0)),
	as.integer(nrow(C1)),
	as.integer(K),
	as.double(alpha),
	R = double(n1),PACKAGE="lago")$R

	return(list(C1=C1,R=R,alpha=alpha,kernel=kernel))
}


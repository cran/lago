myC1 <- function( y, X, n1 )
	.C("getC1",
	as.integer(y),
	as.integer(nrow(X)),
	as.integer(ncol(X)),
	as.integer(n1),
	as.double(X),
	C1 = double(ncol(X)*n1),PACKAGE="lago")$C1

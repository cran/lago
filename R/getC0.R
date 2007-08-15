myC0 <- function( y, X, n0 )
	.C("getC0",
	as.integer(y),
	as.integer(nrow(X)),
	as.integer(ncol(X)),
	as.integer(n0),
	as.double(X),
	C0=double(ncol(X)*n0),PACKAGE="lago")$C0

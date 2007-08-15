learn <- function( y, C0r, C1r, n0, n1, p )
	.C( "preLago",
	as.integer(y),
	as.double(C0r),
	as.double(C1r),
	as.integer(n0),
	as.integer(n1),
	as.integer(p),
	D = double(n1*n0),PACKAGE="lago")$D

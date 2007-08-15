myn0 <- function( y )
	.C("getC0Dim",
	as.integer(y),
	as.integer(length(y)),
	n0 = integer(1),PACKAGE="lago")$n0

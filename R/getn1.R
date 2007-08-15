myn1 <- function( y )
	.C("getC1Dim",
	as.integer(y),
	as.integer(length(y)),
	n1 = integer(1),PACKAGE="lago")$n1

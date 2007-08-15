rank.eLago <- function(obj,  Xnew)
{
	Xnew<-data.matrix(Xnew)
	C1 <- obj$C1

	S <- .C("eLagoPredict",
	as.double(C1), 
	as.integer(ncol(C1)), 
	as.integer(nrow(C1)), 
	as.double(obj$R), 
	as.double(Xnew), 
	as.integer(nrow(Xnew)), 
	as.double(obj$alpha), 
	as.character(obj$kernel), 
	score = double(nrow(Xnew)),PACKAGE="lago")$score
	return(S)
}


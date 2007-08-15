tuneLago <- function(Y,X,Ynew,Xnew,alphaGrid,Kgrid,func=avgp,kernel='t',version='s',plot=TRUE,...)
{
	Y<-data.matrix(Y)
	X<-data.matrix(X)
	Xnew<-data.matrix(Xnew)
	Ynew<-data.matrix(Ynew)
	alphaGrid<-data.matrix(alphaGrid)
	Kgrid<-data.matrix(Kgrid)
	perf<-matrix(0,length(alphaGrid),length(Kgrid))

	D <- preLago(Y,X)

	for (i in 1: length(alphaGrid))
	{
		for (j in 1:length(Kgrid))
		{
			if (version == 's') {
				obj <- sLago(Y, X, D = D, alpha = alphaGrid[i], K = Kgrid[j], kernel = kernel) 
				score <- rank.sLago(obj, Xnew) 
			}
			if (version == 'e') {
				obj <- eLago(Y, X, D = D, alpha = alphaGrid[i], K = Kgrid[j], kernel = kernel) 
				score <- rank.eLago(obj, Xnew) 
			}
			perf[i,j] <- func(Ynew[,1], score,...)
			gc()
		}
	}
	if (plot) aKcontour(Kgrid, alphaGrid, perf, main=paste(version,'LAGO: CV plot',sep=''))
	return(perf)
}
			

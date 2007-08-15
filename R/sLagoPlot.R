view.sLago <- function( obj, X )
{
  Xs <- data.matrix(scale(X,cen=TRUE,sca=FALSE))
  X <- data.matrix(X)

  svd(Xs)->pr
  pts<-X %*% pr$v[,1:2]
  centers<-obj$C1 %*% pr$v[,1:2]
  plot(pts, xlab='PC1', ylab='PC2', pch='.', col='blue', 
	main='Visualization of sLAGO',
	cex.main=1.75, cex.lab=1.5, cex.axis=1.25)
  points(centers, pch=4, col='red',cex=1.5)
  symbols(centers[,1],centers[,2],circles=obj$R/sqrt(ncol(X)),inches=FALSE,add=TRUE,lty=2)

  xrange<-c(min(pts[,1]), max(pts[,1]))
  yrange<-c(min(pts[,2]), max(pts[,2]))
  return(list(v=pr$v[,1:2],xrange=xrange,yrange=yrange))
}


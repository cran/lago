show.test <- function(stuff, Xnew, Ynew, score=NULL)
{
  Xnew <- data.matrix(Xnew)
  pts<-Xnew %*% stuff$v
  plot(pts, xlab='PC1', ylab='PC2', pch='.', col='blue', 
	main='Visualization of Test Data',
	cex.main=1.75, cex.lab=1.5, cex.axis=1.25,
	xlim=stuff$xrange,ylim=stuff$yrange)
  ind <- which(Ynew==1)
  points(pts[ind,], pch=4, col='red',cex=1.5)
  if (!is.null(score)) {
	ranking <- rank(-score)   # want large score to be ranked first
	text(pts[ind,], label=ranking[ind])
  }
}


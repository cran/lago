aKcontour<-function(Klist,alist,values,logscale='both', ...)
{
	if (logscale=='K') {
		y <- log(Klist); x <- alist
		ystr <- 'K on log-scale'; xstr <- 'alpha'
	}
	else if (logscale == 'alpha') {
		y <- Klist; x <- log(alist)
		ystr <- 'K'; xstr <- 'alpha on log-scale'
	}
	else {
		y <- log(Klist); x <- log(alist)
		ystr <- 'K on log-scale'; xstr <- 'alpha on log-scale'
	}
	contour(y=y, x=x, z=values,
   		xlab=xstr, ylab=ystr,
   		axes=FALSE, labcex=1.25, cex.axis=1.25, cex.lab=1.5, cex.main=1.75, ...)
		axis(side=2, at=y, label=Klist)
		axis(side=1, at=x, label=alist)
		box()
}

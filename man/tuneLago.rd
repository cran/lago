\name{tuneLago}
\alias{tuneLago}
\title{Tuning of LAGO}
\description{Uses a validation set to select tuning parameters for Lago. Based on options implemented so far, 
one can use either \code{\link{avgp}} or \code{\link{topn}} as the performance metric.}
\usage{
tuneLago(Y,X,Ynew,Xnew,alphaGrid,Kgrid,func=avgp,kernel='t',version='s',plot=TRUE,...)
}
\arguments{
	\item{Y}{vector of binary responses; training data.}
	\item{X}{matrix of covariates/predictors; training data.}
	\item{Ynew}{vector of binary responses; validation data.}
	\item{Xnew}{matrix of covariates/predictors; validation data.}
	\item{alphaGrid}{a vector listing candidates for the tuning parameter, \code{alpha}.}
	\item{Kgrid}{a vector listing candidates for the tuning parameter, \code{K}.}
	\item{func}{function used for performance evaluation; default is \code{func=\link{avgp}}.}
	\item{kernel}{either \sQuote{t} or \sQuote{g}, specifying the type of kernel to be used by LAGO.}
	\item{version}{either \sQuote{s} or \sQuote{e}, specifying whether sLAGO or eLAGO is to be fitted.}
	\item{plot}{if \code{TRUE}, a contour plot is generated; see \code{\link{aKcontour}}.}
	\item{...}{arguments passed to the criterion function, \code{func}.}
}
\seealso{
	\code{\link{avgp}, \link{topn}, \link{aKcontour}}
}
\keyword{utilities}
\author{Alexandra Laflamme-Sanders and Mu Zhu, University of Waterloo, Canada.}


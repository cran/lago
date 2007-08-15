\name{aKcontour}
\alias{aKcontour}
\title{Plotting Function for the Tuning of LAGO}
\description{Contour plot of evaluation metric (currently \code{\link{avgp}} or \code{\link{topn}}) for various values of 
\code{alpha} 
and \code{K}.}
\usage{
aKcontour(Klist, alist, values, logscale='both', ...)
}
\arguments{
	\item{Klist}{vector containing grid points for different \code{K}'s.}
	\item{alist}{vector containing grid points for different \code{alpha}'s.}
	\item{values}{matrix containing the performance evaluation LAGO for each set of tuning parameters, 
		often (if not always) the result of \code{\link{tuneLago}}.}
	\item{logscale}{'a', 'K' or 'both', indicating which axis should be plotted using a log-scale.}
	\item{...}{arguments passed to plot function, such as \code{main="sLAGO: CV plot"}.}
}
\seealso{
	\code{\link{tuneLago}}
}
\keyword{hplot}
\author{Mu Zhu, University of Waterloo, Canada.}


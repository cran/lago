\name{view.sLago}
\alias{view.sLago}
\title{Visualize Spherical LAGO}
\description{Produces a visualization of the fitted LAGO model.}
\synopsis{
view.sLago(obj, X)
}
\usage{
## build (default) sLAGO model
obj<-sLago(Y,X)

## visualize the model
view.sLago(obj, X)
}
\arguments{
	\item{obj}{result from \code{\link{sLago}}.}
	\item{X}{a matrix of covariates/predictors; training data.}
}
\value{An object which can be passed onto \code{\link{show.test}} to display the test data.}
\seealso{
	\code{\link{view.eLago}, \link{sLago}, \link{show.test}}
}
\keyword{hplot}
\author{Mu Zhu, University of Waterloo, Canada.}
\note{
The function is \strong{NOT} fast for large datasets because it performs 
a principal component analysis first in order to produce a 2-dimensional plot.
}

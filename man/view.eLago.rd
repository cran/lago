\name{view.eLago}
\alias{view.eLago}
\title{Visualize Elliptical LAGO}
\description{Produces a visualization of the fitted LAGO model. 
}
\synopsis{
view.eLago(obj, X)
}
\usage{
## build (default) eLAGO model
obj<-eLago(Y,X)

## visualize the model
view.eLago(obj, X)
}
\arguments{
	\item{obj}{result from \code{\link{eLago}}.}
	\item{X}{a matrix of covariates/predictors; training data.}
}
\value{An object which can be passed onto \code{\link{show.test}} to display the test data.}
\seealso{
	\code{\link{view.sLago}, \link{eLago}, \link{show.test}}
}
\keyword{hplot}
\author{Mu Zhu, University of Waterloo, Canada}
\note{
The function is \strong{NOT} fast for large datasets because it performs 
a principal component analysis first in order to produce a 2-dimensional plot.
}

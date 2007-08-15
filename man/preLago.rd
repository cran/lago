\name{preLago}
\alias{preLago}
\title{Preliminary calculation for LAGO}
\description{This procedure is useful for saving computational time, especially if the LAGO procedure will be called
repeatedly on the same data, e.g., during cross validation.}
\usage{
preLago(y, X)
}
\arguments{
	\item{y}{a vector of binary reponses; training data.}
	\item{X}{a matrix of covariates/predictors, training data.}
}
\value{
Returns an \code{n1}-by-\code{n0} matrix whose entries are the pairwise distances between all class-1 observations and all 
class-0 
observation in the training data \code{X}.}
\seealso{
        \code{\link{sLago}, \link{eLago}}
}
\keyword{array}
\author{Alexandra Laflamme-Sanders, University of Waterloo, Canada.}


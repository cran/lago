\name{rank.eLago}
\alias{rank.eLago}
\title{Predict with Elliptical LAGO}
\description{Predict function for \code{\link{eLago}}.}
\synopsis{
rank.eLago(obj, Xnew)
}
\usage{
obj<-eLago(Y, X)                                                               
rank.eLago(obj, Xnew)
}
\arguments{
	\item{obj}{object produced by \code{\link{eLago}}.}
	\item{Xnew}{a matrix of covariates/predictors; test data.}
}
\value{A vector of scores which ranks each item in \code{Xnew}.}
\seealso{
        \code{\link{eLago}, \link{view.eLago}}
}
\keyword{models}                             
\keyword{multivariate}                       
\keyword{nonparametric}                      
\author{Alexandra Laflamme-Sanders and Mu Zhu, University of Waterloo, Canada.}


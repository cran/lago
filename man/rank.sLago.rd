\name{rank.sLago}
\alias{rank.sLago}
\title{Predict with Spherical LAGO}
\description{Predict function for \code{\link{sLago}}.}
\synopsis{
rank.sLago(obj, Xnew)
}
\usage{
obj<-sLago(Y, X) 
rank.sLago(obj, Xnew)
}
\arguments{
	\item{obj}{object produced by \code{\link{sLago}}.}
	\item{Xnew}{a matrix of covariates/predictors; test data.}
}
\value{A vector of scores which ranks each item in \code{Xnew}.}
\seealso{
        \code{\link{sLago}, \link{view.sLago}}
}
\keyword{models}                             
\keyword{multivariate}                       
\keyword{nonparametric}                      
\author{Alexandra Laflamme-Sanders and Mu Zhu, University of Waterloo, Canada.}


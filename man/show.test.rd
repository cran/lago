\name{show.test}
\alias{show.test}
\title{Visualize the Test Data}
\description{To visualize the test data. Always to be used in conjunction with \code{\link{view.eLago}} or 
\code{\link{view.sLago}} so that the fitted LAGO model can be visualized side by side. }
\synopsis{
show.test(stuff, Xnew, Ynew, score=NULL)
}
\usage{
## build (default) eLAGO model
obj<-eLago(Y,X)

## visualize the model
stuff<-view.eLago(obj, X)

## make predictions
score<-rank.eLago(obj, Xnew)

## visualize the test data side by side
show.test(stuff, Xnew, Ynew, score=NULL)
}
\arguments{
	\item{stuff}{object produced by \code{\link{view.sLago}} or \code{\link{view.eLago}}.}
	\item{Xnew}{a matrix of covariates/predictors; test data.}
	\item{Ynew}{a vector of binary responses; test data.}
	\item{score}{optional; a vector of scores produced by LAGO to rank the items in \code{Xnew}. 
		If provided, the ranking position of every class-1 observation in \code{Xnew} will be 
		added to the plot.}
}
\seealso{
	\code{\link{view.sLago}, \link{view.eLago}}
}
\keyword{hplot}
\author{Mu Zhu, University of Waterloo, Canada.}


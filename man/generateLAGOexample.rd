\name{generateLAGOexample}
\alias{generateLAGOexample}
\title{Generate Toy Example}
\description{This generates some toy data just to show how this package 
is used. See examples in \link{lago-package}.}
\usage{
generateLAGOexample(n, show=TRUE)
}
\arguments{
\item{n}{sample size.}
\item{show}{if \code{TRUE}, plot the generated data set.}
}
\value{
\item{X}{\code{n}-by-\code{2} matrix, training data.}
\item{y}{\code{n}-by-\code{1} binary vector, training responses.}
}
\note{The predictors are generated uniformly. Given \code{x}, the 
responses are generated as Bernoulli(\code{p(x)}), where \code{p(x)} 
can be visualized by \code{\link{showLAGOexample}}.}
\author{Wanhua Su and Mu Zhu, University of Waterloo, Canada.}
\keyword{misc}


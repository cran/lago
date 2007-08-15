\name{avgp}
\alias{avgp}
\title{Average Precision}
\description{Calculates the average precision of a ranking algorithm.}
\synopsis{
avgp(y, phat, ties=FALSE)
}
\usage{
## use default LAGO to rank items
obj <- sLago(Y,X)
s <- rank.sLago(obj, Xnew)

## evaluate its performance by average precision
avgp(y=Ynew, phat=s, ties=T)
}
\arguments{
	\item{y}{a vector of binary responses.}
	\item{phat}{a vector of rankings. Often, one may want to use posterior probabilities to rank items, but 
	any monotonic transformation of posterior probabilities will, of course, give the same ranking.}
	\item{ties}{if \code{TRUE}, ties are 'equalized' (more computation); otherwise, ties are broken at random.}
}
\seealso{
	\code{\link{topn}, \link{tuneLago}}
}
\keyword{misc}
\author{Mu Zhu, University of Waterloo, Canada.}

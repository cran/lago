\name{topn}
\alias{topn}
\title{Top n}
\description{Reports the number of hits among the top-n ranked items.}
\synopsis{
topn(y, phat, n=5)
}
\usage{
## use default LAGO to rank items
obj <- sLago(Y,X)
s <- rank.sLago(obj,Xnew)

## evaluate its performance by average precision
topn(y=Ynew, phat=s, n=10)
}
\arguments{
	\item{y}{a vector of binary responses.}
	\item{phat}{a vector of rankings. Often, one may want to use posterior probabilities to rank items, but 
	any monotonic transformation of posterior probabilities will, of course, give the same ranking.}
	\item{n}{an integer indicating how many top ranked items to evaluate.}
}
\seealso{
	\code{\link{avgp}, \link{tuneLago}}
}
\keyword{misc}
\author{Mu Zhu, University of Waterloo, Canada.}

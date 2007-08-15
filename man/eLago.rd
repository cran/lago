\name{eLago}
\alias{eLago}
\title{Elliptical LAGO}
\description{This is the original LAGO procedure, called \dQuote{eLAGO} now to differentiate it from later variations such as 
\dQuote{sLAGO}.}
\synopsis{
eLago(Y, X, D = NULL, alpha = 1, K = 5, kernel = "t") 
}
\usage{
eLago(Y, X)
eLago(Y, X, D=preLago(Y,X), alpha = 0.5, K = 5, kernel="g")
eLago(Y, X, alpha = 0.5, K = 5, kernel="g") 
}
\arguments{
	\item{Y}{a vector of binary responses; training data.}
	\item{X}{a matrix of covariates/predictors; training data.}
	\item{D}{if \code{is.null(D)==T}, the matrix D will be calculated by the function; however, it's computationally 
		desirable to precompute D using \code{preLago(Y, X)}, 
		especially if the function \code{eLago} will be called
		repeatedly on the same data, e.g., during cross-validation.}
	\item{alpha}{a positive real number; if \code{alpha > 1}, the radius/bandwidth is stretched; 
		if \code{alpha < 1}, the radius/bandwidth is dampened.}
	\item{K}{a positive integer indicating the number of nearest neighbors to use for calculating the radius/bandwidth.}
	\item{kernel}{a character input; \sQuote{t} for \dQuote{triangular}; 
		\sQuote{g} for \dQuote{Gaussian}; otherwise a \dQuote{uniform} kernel is used but it
		important to note that a uniform kernel is \strong{not} very effective.}
}
\value{
        \item{C1}{an \code{n1}-by-\code{p} matrix whose rows are the centers of the LAGO radial basis function network.}      
        \item{R}{an \code{n1}-by-\code{p} matrix whose rows specify the radius vector of the \code{n1} radial basis functions.}
        \item{alpha}{the stretching/dampening parameter; see above; here passed on to be used for prediction.}
        \item{kernel}{either \sQuote{t} or \sQuote{g}; see above; here passed on to be used for prediction.}                       
}

\references{
Zhu M, Su W, Chipman HA (2006). LAGO: A
computationally efficient approach for statistical detection.
\cite{Technometrics}, 48(2), 193 -- 205. 

Zhu M (2008). Kernels and ensembles: Perspectives on statistical learning.
\cite{The American Statistician}, 62(2), 97 -- 109.   
}

\seealso{
	\code{\link{sLago}, \link{preLago}, \link{view.eLago}, \link{rank.eLago}}
}
\keyword{models}
\keyword{multivariate}
\keyword{nonparametric}
\author{Alexandra Laflamme-Sanders and Mu Zhu, University of Waterloo, Canada.}


\name{sLago}
\alias{sLago}
\title{Spherical LAGO}
\description{This is the spherical LAGO procedure, which is a variation of the original LAGO --- now called \dQuote{eLAGO}.
It is less adpative than the original LAGO but could actually be more generally useful. 
However, it is almost certainly true in this case that the covariates should be standardized a priori to 
have mean zero and variance one.}
\synopsis{
sLago(Y, X, D = NULL, alpha = 1, K = 5, kernel = "t")
}
\usage{
sLago(Y, X)
sLago(Y, X, D=preLago(Y,X), alpha = 0.5, K = 5, kernel="g")
sLago(Y, X, alpha = 0.5, K = 5, kernel="g")
}
\arguments{
	\item{Y}{a vector of binary responses; training data.}
	\item{X}{a matrix of covariates/predictors; training data.}
	\item{D}{if \code{is.null(D)==T}, the matrix D will be calculated by the function; however, it's computationally 
		desirable to precompute D using \code{preLago(Y, X)}, 
		especially if the function \code{sLago} will be called
		repeatedly on the same data, e.g., during cross-validation.}
	\item{alpha}{a positive real number; if \code{alpha > 1}, the radius/bandwidth is stretched; 
		if \code{alpha < 1}, the radius/bandwidth is dampened.}
	\item{K}{a positive integer indicating the number of nearest neighbors to use for calculating the radius/bandwidth.}
	\item{kernel}{a character input; \sQuote{t} for \dQuote{triangular}; 
		\sQuote{g} for \dQuote{Gaussian}; otherwise a \sQuote{uniform} kernel is 
		used, but 
		since the uniform kernel is not very effective, it is actually not fully implemented in this version so 
		do \strong{NOT} use it. Other kernels are not implemented in this version, but may be added in future versions.}
}
\value{
	\item{C1}{an \code{n1}-by-\code{p} matrix whose rows are the centers of the LAGO radial basis function network.}
	\item{R}{a vector of length \code{n1}, each specifying the radius of the \code{n1} radial basis functions.}
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
        \code{\link{eLago}, \link{preLago}, \link{view.sLago}, \link{rank.sLago}}
}
\keyword{models}                             
\keyword{multivariate}                       
\keyword{nonparametric}                      
\author{Alexandra Laflamme-Sanders and Mu Zhu, University of Waterloo, Canada.}

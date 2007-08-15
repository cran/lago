\name{lago}
\alias{lago-package}
\docType{package}
\title{The LAGO Suite: An Introductory Overview}
\description{LAGO is a tool for finding rare targets in a database.}
\details{
To find rare targets in a database, LAGO scores every item in the database 
with a specialized radial basis function network (RBFnet), trained with 
some learning data. Items with higher scores are deemed by LAGO to be more 
likely than others to be from the rare class.
The RBFnet constructed by LAGO has exactly the same form as the support 
vector machine (SVM), but it is constructed without the use of any 
iterative optimization procedure at all, whereas the SVM must solve a 
quadratic programming problem. Hence, LAGO is a very efficient kernel 
machine. 

A snapshot of the theoretical justification for why iterative optimization 
can be avoided is as follows: Suppose \code{p1} is the density function of 
the rare class and \code{p0}, the density function of the background 
class. The RBFnet constructed by LAGO is an adaptive-bandwidth kernel 
density estimator of \code{p1} adjusted locally by a factor that 
approximates \code{p0} to the first-order. The resulting ranking function 
\code{f(x)} is thus approximately a monotonic transformation of the 
posterior probability that item \code{x} belongs to the rare class.

The original LAGO uses elliptical radial basis functions which can adapt 
more flexibly to the training data. A simpler (but perhaps more generally 
useful) variation that uses spherical radial basis functions is also 
included in this package. To differentiate the two, the original LAGO is 
now referred to as eLAGO (e.g., \code{\link{eLago}, \link{rank.eLago}}) 
and the spherical variation, sLAGO (e.g., \command{\link{sLago}, 
\link{rank.sLago}}). We now recommended that you use sLAGO instead of 
eLAGO for your problem. 

Like most nonparametric models such as SVM and CART, LAGO need to be fine 
tuned by a number of control (or regularization) parameters. The two 
control parameters for LAGO are: \code{K} and \code{alpha}; see help pages 
for \code{\link{eLago}, \link{sLago}} and \code{\link{tuneLago}} for more 
details. It is important that one select these parameters carefully (e.g., 
by cross-validation) in order for LAGO to produce reasonable results. 
Between the two parameters, \code{alpha} is much more important than 
\code{K}. Often, it suffices to fix \code{K=5} and tune \code{alpha} 
alone.
}

\references{ 
Zhu M, Su W, Chipman HA (2006). LAGO: A 
computationally efficient approach for statistical detection. 
\cite{Technometrics}, 48(2), 193 -- 205. 

Zhu M (2008). Kernels and ensembles: Perspectives on statistical learning.
\cite{The American Statistician}, 62(2), 97 -- 109. [The relevant 
section is Section 4.2.]
} 

\keyword{models} 
\keyword{multivariate} 
\keyword{nonparametric}

\author{Alexandra Laflamme-Sanders and Mu Zhu, University of Waterloo, 
Canada. Alexandra is the principal C programmer for the package.}

\examples{
## generate some training data
stuff<-generateLAGOexample(n=500,show=TRUE)
X<-stuff$X
y<-stuff$y

## generate some independent test data 
stuff<-generateLAGOexample(n=500,show=TRUE)
Xnew<-stuff$X
ynew<-stuff$y

## sLAGO example
my.lago<-sLago(y, X, kernel="g") 
lago.score<-rank.sLago(my.lago, Xnew)
par(mfrow=c(2,2))
view.sLago(my.lago,X) -> stuff
show.test(stuff, Xnew, ynew, score=lago.score)
avgp(ynew, lago.score)
topn(ynew, lago.score, n=20)

## eLAGO example
my.lago<-eLago(y, X, kernel="g") 
lago.score<-rank.eLago(my.lago, Xnew)
view.eLago(my.lago,X) -> stuff
show.test(stuff, Xnew, ynew, score=lago.score)
avgp(ynew, lago.score)
topn(ynew, lago.score, n=20)

## use the test data above as validation data to tune the control parameters
aGrid<-c(0.05,0.1,0.5,1,2,5,10)
Kgrid<-c(2,5,10,20,30)
tuneLago(y,X,ynew,Xnew,aGrid,Kgrid,kernel="g",version='s')
tuneLago(y,X,ynew,Xnew,aGrid,Kgrid,kernel="g",version='e')
}

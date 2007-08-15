topn <- function(y, phat, n=5)
{
  if (n > length(y)) stop(paste("Can't find", n, "items when there are only", length(y), "!"))
  if (length(y)!=length(phat)) stop("Number of items being ranked not equal to total number of items!")
  ind<-order(phat, decreasing=TRUE)
  yy <- y[ind]
  return(sum(yy[1:n]))
}


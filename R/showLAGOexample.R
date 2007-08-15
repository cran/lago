showLAGOexample<-function()
{

plotx1=seq(-3,3,length=400)
plotx2=seq(-1,5,length=401)
plotmat=expand.grid(plotx1,plotx2)

ms1x1=c(-1.5, -1.75, -1.75, -1.25, -1.25)
ms1x2=c(3.5,3.25, 3.75, 3.25, 3.75)
ms2x1=seq(1.25, 1.75, length=3)
ms2x2=seq(0.25, 0.75, length=3)

ms1=cbind(ms1x1,ms1x2)
ms2=expand.grid(ms2x1,ms2x2)
n=nrow(ms1)+nrow(ms2)
class1=matrix(0,n,2)
class1[,1]=c(ms1[,1],ms2[,1])
class1[,2]=c(ms1[,2],ms2[,2])

tobj0=list()
tobj0$R=cbind(rep(0.25,n),rep(0.25,n))
tobj0$C1=class1
tobj0$alpha=1
tobj0$kernel="g"

b0=c(-2.8,45)
phat0=rank.eLago(tobj0,plotmat)
plotxmat=cbind(rep(1,length(phat0)),phat0)
plotbeta=crossprod(t(plotxmat),b0)
prob0=1/(1+exp(-plotbeta))

contour(plotx1, plotx2, 
matrix(prob0,length(plotx1),length(plotx2)),
xlab=expression(x[1]),ylab=expression(x[2]),
main=expression(paste("P(y=1|",x[1],",",x[2],")",sep="")))

}


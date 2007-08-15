generateLAGOexample<-function(n, show=TRUE)
{
range0x1<-c(-3,3)
range0x2<-c(-1,5)
newx01<-c(runif(n,range0x1[1],range0x1[2]))
newx02<-c(runif(n,range0x2[1],range0x2[2]))

trainx<-cbind(newx01, newx02)

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
trphat=rank.eLago(tobj0,trainx)
trxmat=cbind(rep(1,length(trphat)),trphat)
trxbeta=crossprod(t(trxmat),b0)
trprob=1/(1+exp(-trxbeta))
trainy=rbinom(length(trprob),1,trprob)

if (show)
{
 plot(trainx, col=ifelse(trainy==1,'red','black'),
 xlab=expression(x[1]),ylab=expression(x[2]),
 main='Some Toy Data')
}

return(list(X=trainx, y=trainy))
}


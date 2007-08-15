.First.lib <- function(lib,pkg)
{
	library.dynam("lago",pkg,lib)
	cat("LAGO 0.1-1 loaded\n")
}

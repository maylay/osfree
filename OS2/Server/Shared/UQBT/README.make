Instructions to make the static UQ binary translator
----------------------------------------------------

$Revision: 1.1 $

Manual changes required based on site:
	Makefile:	If target is Linux, uncomment the ISLINUX= line
	make:		uncomment appropriate MAKE= line
	mltk.sh:	set the first line to bash's path; check TKML= and HEAP= etc

Before first real make without running generating files already generated by
bison++, flex++, and njmc: 
	./make remote
or
    make remote

To see make options:
	./make

To make uqbtXY for X and Y architectures (but see "make change" below): 
	./make X Y

where X and Y can be:
    sparc
    pent
    mc68k (Palm)
    win32 (not working very well yet)
    hppa  (partly imlemented)

At present, to make the gcc/jvm back end, make uqbtss (ie ./make sparc sparc);
in the destination directory, "make java" (or more commonly, "makej java",
where makej is a script that sets variables such as cc1=, jas=, and does a
"make CCONE=$cc2 JASMIN=$jas ... $*"). See other readme file for making the
cc1 tool (the gcc compiler with the jvm back end).

To make another pair, for A to B architectures (i.e. if last translator made was
uqbtXY, and A != X, and/or B != Y):
	./make change
	./make A B

"./make change" can be shortened to "make change".

To clean out all object files, and all executables (uqbtXY for all X and Y):
	./make clean

As above, but to also delete generated files such as sparcDir/decoder.cc and
RTL/sslscanner.cc (do not do this if you don't have the toolkit, bison++, and
flex++):
    ./make cleanall
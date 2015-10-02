#!/bin/bash

#REGS=( "ttbar" "ZMuMu" "ZEE" "Zl" "Wl" )

VARS=(  "MET"
	"M3l"       )  

TODAY="150910" #$(date +"%y%m%d")

if [ ! -d "$MPAF/workdir/plots/WZsynchro" ]; then
    mkdir $MPAF/workdir/plots/WZsynchro
fi

cd $MPAF/display

DIR=$MPAF/workdir/plots/WZsynchro

#for reg in ${REGS[@]}; do
    if [ ! -d "$DIR/WZ3l_25" ]; then
	mkdir $DIR/WZ3l_25
    fi
    for var in ${VARS[@]}; do
	#plot=${reg}_${var}
	plot=${var}"WZCR"
	root -l -b -q cards/template_yieldsWZ_25ns.C\(\"${plot}\"\) 
	
	#mv $DIR/png/${plot}.png   $DIR/${reg}/${var}.png
	#mv $DIR/pdf/${plot}.pdf   $DIR/${reg}/${var}.pdf
	#mv $DIR/eps/${plot}.eps   $DIR/${reg}/${var}.eps
	#mv $DIR/root/${plot}.root $DIR/${reg}/${var}.root
	mv $DIR/png/${plot}.png   $DIR/WZ3l_25/${var}.png
	mv $DIR/pdf/${plot}.pdf   $DIR/WZ3l_25/${reg}/${var}.pdf
	mv $DIR/eps/${plot}.eps   $DIR/WZ3l_25/${reg}/${var}.eps
	mv $DIR/root/${plot}.root $DIR/WZ3l_25/${var}.root
    done
#done

rmdir $DIR/png
rmdir $DIR/pdf
rmdir $DIR/eps
rmdir $DIR/root

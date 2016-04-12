#!/bin/bash

# Run this to get validation plots for WZ selection, from rootfiles created with Sub_AnalysisWZ25_plots_850pb.sh

#REGS=( "ttbar" "ZMuMu" "ZEE" "Zl" "Wl" )
NAME="WZ3L_testdiff"
DIR="workdir/root/WZsynchro/"
#FLAVs=( "all" "eee" "eem" "mme" "mmm" )
FLAVs=( "all" )
#FLAVs=( "eee" "eem" "mme" "mmm" )
#WZSTEPs=( "0" )
WZSTEPs=( "0" "1" "2" "3" "4" "5" "6" )
#WZSTEPs=( "6" )

QSQRs=( "1001" )
#QSQRs=( "1001" "1002" "1003" "1004" "1005" "1006" "1007" "1008" "1009" )
#PDFrange=( "2001" "2100" )

LHEs=()
nQSQR=0
if [ ! -z "${QSQRs[0]}" ]; then
  LHEs=${QSQRs[@]}
  nQSQR=${#QSQRs[@]}
fi


if [ ! -z "${PDFrange[0]}" ]; then
  echo variable set
  for (( iter=${PDFrange[0]}; iter<=${PDFrange[1]}; iter++ )); do
    LHEs+=( ${iter} )
  done
fi


VARS=( "etaSc"
       "dEtaScTrkIn"
       "dPhiScTrkIn"
       "sigmaIEtaIEta"
       "hadronicOverEm"
       "eInvMinusPInv"
       "relIso03"
       "lostHits"
       "dxy"
       "dz"
       "convVeto"
       "ecalPFClusterIso"
       "hcalPFClusterIso"
       "dr03TkSumPt"
       "RelecalPFClusterIso"
       "RelhcalPFClusterIso"
       "Reldr03TkSumPt"   )


#TODAY="150910" #$(date +"%y%m%d")

if [ ! -d "$MPAF/workdir/plots/WZsynchro" ]; then
    mkdir $MPAF/workdir/plots/WZsynchro
fi

cd $MPAF/display

DIR=$MPAF/workdir/plots/WZsynchro


    if [ ! -d "$DIR/0selnoSkim" ]; then
	    mkdir $DIR/0selnoSkim
    fi
    
    	for iflav in ${FLAVs[@]}; do
    	  
	        flav=$iflav
	  
	        ilhe=0

	        for lhe in ${LHEs[@]}; do
	  
	      
	            LHESYS=""
	            replaceLHESYS=""
	            if (( ilhe < nQSQR )); then
	              LHESYS="LHE"
	              replaceLHESYS="replaceLHESYS"
                else
                  LHESYS="LHE"
	              replaceLHESYS="replaceLHESYS"
  	            fi
  	            filename=${NAME}_WZSTEP6_LEPFLAV${flav}_${LHESYS}${lhe}
  		        for var in ${VARS[@]}; do

		        	plot=${var}_WZSM0sel
		        	root -l -b -q cards/template_plotsWZ_testdiff.C\(\"${plot}\",\"${filename}\"\) 
		
		        	#mv $DIR/png/${plot}.png   $DIR/WZstep${wzstep}/${flav}/${var}.png
		        	#mv $DIR/pdf/${plot}.pdf   $DIR/WZstep${wzstep}/${flav}/${var}.pdf
		        	#mv $DIR/eps/${plot}.eps   $DIR/WZstep${wzstep}/${flav}/${var}.eps
		        	#mv $DIR/root/${plot}.root $DIR/WZstep${wzstep}/${flav}/${var}.root

		        	mv $DIR/png/${plot}.png   $DIR/0selnoSkim/${var}.png
		        	mv $DIR/root/${plot}.root $DIR/0selnoSkim/${var}.root
		        	mv $DIR/pdf/${plot}.pdf   $DIR/0selnoSkim/${var}.pdf
		        	mv $DIR/eps/${plot}.eps   $DIR/0selnoSkim/${var}.eps
	            done
	      done
    done


rmdir $DIR/png
rmdir $DIR/pdf
rmdir $DIR/eps
rmdir $DIR/root

cd ..

#!/bin/bash

# Run this to get validation plots for WZ selection, from rootfiles created with Sub_AnalysisWZ25_plots.sh

#REGS=( "ttbar" "ZMuMu" "ZEE" "Zl" "Wl" )
NAME="WZ3Lplots"
DIR="workdir/root/WZsynchro/"
#FLAVs=( "all" "eee" "eem" "mme" "mmm" )
FLAVs=( "all" )
#FLAVs=( "eee" "eem" "mme" "mmm" )
#WZSTEPs=( "0" )
WZSTEPs=( "1" "2" "3" "4" "5" "6" )

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


VARS=( "lepZ1_jetPtRatio"
       "lepZ1_jetPtRel"   
       "lepZ1_miniRelIso" 
       "lepZ1_Pt"         
       "lepZ1_Eta"        
       "lepZ1_SIP3D"      
       "lepZ2_jetPtRatio" 
       "lepZ2_jetPtRel"   
       "lepZ2_miniRelIso" 
       "lepZ2_Pt"         
       "lepZ2_Eta"        
       "lepZ2_SIP3D"      
       "lepW_jetPtRatio" 
       "lepW_jetPtRel"   
       "lepW_miniRelIso" 
       "lepW_Pt"         
       "lepW_Eta"        
       "lepW_SIP3D" 
       "METWZCR"
       "M3lWZCR"         
       "HTWZCR"         
       "htJet40j"        
       "mZ1"             
       "MTmin"           
       "NBJetsLoose25" 
       "NBJetsMedium25"
       "NBJetsTight40" 
       "NJets40"       )


#TODAY="150910" #$(date +"%y%m%d")

if [ ! -d "$MPAF/workdir/plots/WZsynchro" ]; then
    mkdir $MPAF/workdir/plots/WZsynchro
fi

cd $MPAF/display

DIR=$MPAF/workdir/plots/WZsynchro
for iwzstep in ${WZSTEPs[@]}; do

    wzstep=$iwzstep
    

    if [ ! -d "$DIR/WZstep${wzstep}" ]; then
	    mkdir $DIR/WZstep${wzstep}
    fi
    
    	for iflav in ${FLAVs[@]}; do
    	  
	        flav=$iflav
	  
	        ilhe=0
	        if [ ! -d "$DIR/WZstep${wzstep}/${flav}" ]; then
	             mkdir $DIR/WZstep${wzstep}/${flav}
            fi
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
  	            filename=${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}
  		        for var in ${VARS[@]}; do
		        	#plot=${reg}_${var}
		        	plot=${var}
		        	root -l -b -q cards/template_plotsWZ_25ns.C\(\"${plot}\",\"${filename}\"\) 
		
		        	mv $DIR/png/${plot}.png   $DIR/WZstep${wzstep}/${flav}/${var}.png
		        	mv $DIR/pdf/${plot}.pdf   $DIR/WZstep${wzstep}/${flav}/${var}.pdf
		        	mv $DIR/eps/${plot}.eps   $DIR/WZstep${wzstep}/${flav}/${var}.eps
		        	mv $DIR/root/${plot}.root $DIR/WZstep${wzstep}/${flav}/${var}.root

	            done
	      done
    done
done

rmdir $DIR/png
rmdir $DIR/pdf
rmdir $DIR/eps
rmdir $DIR/root

cd ..

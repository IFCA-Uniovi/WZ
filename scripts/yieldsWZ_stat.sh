 #!/bin/bash


####### Use with rootfiles produced by analyzer WZacc



# get WZ synchronization table
#templateCFG=template_fakeEstim.cfg
#templateCFG=template_WZ3l.cfg

NAME="WZ3L_statWZ"
DIR="workdir/root/WZsynchro/"
#FLAVs=( "all" "eee" "eem" "mme" "mmm" )
FLAVs=( "all" )
#FLAVs=( "eee" "eem" "mme" "mmm" )
#WZSTEPs=( "4" "3" "2" "1" "0" )
WZSTEPs=(  "6" )
#VARs=( "0" "1" "2" "3" "4")
#VARs=( "5" "6" )
VARs=( "0" )

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


#if [ ! -d "cfg/tmpFiles" ]; then
  #mkdir cfg/tmpFiles
#fi

if [ ! -d "workdir/logs" ]; then
  mkdir workdir/logs
fi

PROCS=( "Tree_WZTo3LNu_0" )
    
# "Tree_WZTo3LNu_0"
#"Tree_TW_0"
#	"Tree_TbarW_0"
#	"Tree_TToLeptons_sch_0"
#	"Tree_TToLeptons_tch_0"
#	"Tree_TbarToLeptons_tch_0"
#	"Tree_TTGJets_0"
#	"Tree_TTHnobb_0"
#	"Tree_TTWToLNu_0"
#	"Tree_TTZToLLNuNu_0"

#"Tree_ZGTo2LG_0"
#"Tree_ZZ_0"
#"Tree_WWZ_0"
#"Tree_WZZ_0"
#"Tree_ZZZ_0"

#> workdir/logs/yieldsWZ_stat.txt
for iproc in ${PROCS[@]}; do
  proc=$iproc
  echo $proc >> workdir/logs/yieldsWZ_stat.txt

  for iwzstep in ${WZSTEPs[@]}; do

      wzstep=$iwzstep
      ii=0

    #echo "STEP"$wzstep >> workdir/logs/yieldsWZ_stat.txt
	  
	for iflav in ${FLAVs[@]}; do  
	  flav=$iflav
	  
	  ilhe=0
	  for lhe in ${LHEs[@]}; do
	      
	      LHESYS=""
	      replaceLHESYS=""
	      
	      for ivar in ${VARs[@]}; do
	      var=$ivar
	      
	      if (( ilhe < nQSQR )); then
	         LHESYS="LHE"
	         replaceLHESYS="replaceLHESYS"
              else
                 LHESYS="LHE"
	         replaceLHESYS="replaceLHESYS"
              fi

              #cp cfg/$templateCFG cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
              #sed -i 's|replaceLEPPT|'all'|' cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
              #sed -i 's|replaceWZstep|'$wzstep'|' cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
              #sed -i 's|replaceLEPFLAV|'$flav'|' cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
              #sed -i 's|replaceQsqr|'$lhe'|' cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
              #sed -i 's|'$replaceLHESYS'|'$lhe'|' cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
   	
              #echo running: ${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg
              file=${DIR}${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.root
	      #echo $FILE
	      #qsub -q all.q -N MPAFjob -o $MPAF/workdir/logs/log_${sr}_${pt}_${mva}_${btag}_${flav}_${LHESYS}${lhe}.out -e $MPAF/workdir/logs/log_${sr}_${pt}_${mva}_${btag}_${flav}_${LHESYS}${lhe}.err $MPAF/scripts/submit.sh $MPAF/cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg              
	      #analysis -c cfg/tmpFiles/${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.cfg >& $MPAF/workdir/logs/log_${NAME}_WZSTEP${wzstep}_LEPFLAV${flav}_${LHESYS}${lhe}.log
	      root -q -l -b display/cards/listyieldsWZ_stat.C\(\"${file}\",${wzstep},\"${proc}\",${var},${lhe}\) >> workdir/logs/yieldsWZ_stat.txt
              ilhe=`echo $ilhe +1 | bc`

              #ii=`echo $ii +1 | bc`

          done
          done
	done
  done
done

sed -i '/Processing/d' workdir/logs/yieldsWZ_stat.txt
sed -i '/^$/d' workdir/logs/yieldsWZ_stat.txt


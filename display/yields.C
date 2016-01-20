#include <map>
#include <iostream>
#include <sstream>


#include "TFile.h"
#include "TH1F.h"
#include "TLegend.h"
#include "TCanvas.h"


std::map<std::string, std::map<std::string, double> > get_map_wsum();
std::map<std::string, double> get_map_xsec();

std::string LHEid = "1001";


std::vector<std::string> get_vec_SRs(int varset = 0) {
  std::vector<std::string> result;
  //result.push_back("MET");
  //result.push_back("NIso");

  if (varset == -1) {
    result.push_back("HT");
  }

  if (varset == 1) {

  result.push_back("HTSR1A");
  result.push_back("HTSR2A");
  result.push_back("HTSR3A");
  result.push_back("HTSR4A");
  result.push_back("HTSR5A");
  result.push_back("HTSR6A");
  result.push_back("HTSR7A");
  result.push_back("HTSR8A");
  result.push_back("HTSR9A");
  result.push_back("HTSR10A");
  result.push_back("HTSR11A");
  result.push_back("HTSR12A");
  result.push_back("HTSR13A");
  result.push_back("HTSR14A");
  result.push_back("HTSR15A");
  result.push_back("HTSR16A");
  result.push_back("HTSR17A");
  result.push_back("HTSR18A");
  result.push_back("HTSR19A");
  result.push_back("HTSR20A");
  result.push_back("HTSR21A");
  result.push_back("HTSR22A");
  result.push_back("HTSR23A");
  result.push_back("HTSR24A");
  result.push_back("HTSR25A");
  result.push_back("HTSR26A");
  result.push_back("HTSR27A");
  result.push_back("HTSR28A");
  result.push_back("HTSR29A");
  result.push_back("HTSR30A");
  result.push_back("HTSR31A");
  result.push_back("HTSR32A");
  }
  
   if (varset == 2) {
 
  result.push_back("HTSR1B");
  result.push_back("HTSR2B");
  result.push_back("HTSR3B");
  result.push_back("HTSR4B");
  result.push_back("HTSR5B");
  result.push_back("HTSR6B");
  result.push_back("HTSR7B");
  result.push_back("HTSR8B");
  result.push_back("HTSR9B");
  result.push_back("HTSR10B");
  result.push_back("HTSR11B");
  result.push_back("HTSR12B");
  result.push_back("HTSR13B");
  result.push_back("HTSR14B");
  result.push_back("HTSR15B");
  result.push_back("HTSR16B");
  result.push_back("HTSR17B");
  result.push_back("HTSR18B");
  result.push_back("HTSR19B");
  result.push_back("HTSR20B");
  result.push_back("HTSR21B");
  result.push_back("HTSR22B");
  result.push_back("HTSR23B");
  result.push_back("HTSR24B");
  result.push_back("HTSR25B");
  result.push_back("HTSR26B");
  }
  
  
  if (varset == 3) {

  result.push_back("HTSR1C");
  result.push_back("HTSR2C");
  result.push_back("HTSR3C");
  result.push_back("HTSR4C");
  result.push_back("HTSR5C");
  result.push_back("HTSR6C");
  result.push_back("HTSR7C");
  result.push_back("HTSR8C");

  }
  
  
  if (varset == 0) {
  /*
     result.push_back("HTBR00H");
     result.push_back("HTBR00M");
     result.push_back("HTBR00L");
     
     result.push_back("HTBR10H");
     result.push_back("HTBR10M");
     result.push_back("HTBR10L");
     
     result.push_back("HTBR20H");
     result.push_back("HTBR20M");
     result.push_back("HTBR20L");
     
     result.push_back("HTBR30H");
     result.push_back("HTBR30M");
     result.push_back("HTBR30L");
     */
     
  result.push_back("MET_WZSMstep0");
  result.push_back("MET_WZSMstep1");
  result.push_back("MET_WZSMstep2");
  result.push_back("MET_WZSMstep3");
  result.push_back("MET_WZSMstep4");
  result.push_back("MET_WZSMstep5");
  result.push_back("MET_WZSMstep6");
  
  }
  
  if (varset == 4) {
  
  
    result.push_back("HT");
    result.push_back("HTlNJlHT");
    result.push_back("HTlNJhHT");
    result.push_back("HThNJlHT");
    result.push_back("HThNJhHT");

    result.push_back("HTlNJlHTA");
    result.push_back("HTlNJhHTA");
    result.push_back("HThNJlHTA");
    result.push_back("HThNJhHTA");

    result.push_back("HTlNJlHTB");
    result.push_back("HTlNJhHTB");
    result.push_back("HThNJlHTB");
    result.push_back("HThNJhHTB");

    result.push_back("HTlNJlHTC");
    result.push_back("HTlNJhHTC");
    result.push_back("HThNJlHTC");
    result.push_back("HThNJhHTC");
 
    result.push_back("HTlNJ");
    result.push_back("HThNJ");
    result.push_back("HTlHT");
    result.push_back("HThHT");

    result.push_back("HTlNJA");
    result.push_back("HThNJA");
    result.push_back("HTlHTA");
    result.push_back("HThHTA");

    result.push_back("HTlNJB");
    result.push_back("HThNJB");
    result.push_back("HTlHTB");
    result.push_back("HThHTB");

    result.push_back("HTlNJC");
    result.push_back("HThNJC");
    result.push_back("HTlHTC");
    result.push_back("HThHTC");

  }
  
  //if (varset == 0) {
  //   result.push_back("HTBR0H");
  //   result.push_back("HTBR0M");
  //   result.push_back("HTBR0L");
  //}

  //result.push_back("HTWZCR");
  //result.push_back("HTBR00H");

  return result;
}



// std::vector<std::string> get_vec_samples() {
//   std::vector<std::string> result;
//   result.push_back("TTJets");
//   result.push_back("TTWJets");
//   //result.push_back("T5qqqqWW_mGo1200_mCh1000_mChi800_dilep");
//   return result;
// }

std::vector<std::string> get_vec_proc() {
  std::vector<std::string> result;

  //result.push_back("T1tttt_700_0");
  //result.push_back("T1tttt_700_475");
  //result.push_back("T1tttt_1100_800");
  //result.push_back("T1tttt_1300_0");
  //result.push_back("T1tttt_1300_1000");
  //result.push_back("T1tttt_1600_0");
  //result.push_back("T1tttt_1600_1200");

  result.push_back("Tree_WZTo3LNu_0");  
  result.push_back("Tree_TTWToLNu_0");
  result.push_back("Tree_TTZToLLNuNu_0");
  
  //result.push_back("fakes");
  //result.push_back("WJets");
  //result.push_back("ZJets");
  ////result.push_back("TTJets");
  ////result.push_back("TTWJets");
  ////result.push_back("TTZJets");
  ////result.push_back("ttH");
  //result.push_back("ttV");
  ////result.push_back("ttV/H");
  //result.push_back("rare");

  //result.push_back("TTW aMCatNLO");
  //result.push_back("TTZ aMCatNLO");


  ////result.push_back("ZZTo4L");
  ////result.push_back("WZJetsTo3LNu");
 
  return result;
}



std::map<std::string, std::vector<std::string> > get_map_proc() {


  //Spring 15 (fastsim) T1tttt scan
  std::vector<std::string> T1tttt_700_0;
  T1tttt_700_0.push_back("T1tttt_700_0");
  
  std::vector<std::string> T1tttt_700_475;
  T1tttt_700_475.push_back("T1tttt_700_475");
  
  std::vector<std::string> T1tttt_1100_800;
  T1tttt_1100_800.push_back("T1tttt_1100_800");
  
  std::vector<std::string> T1tttt_1300_0;
  T1tttt_1300_0.push_back("T1tttt_1300_0");
  
  std::vector<std::string> T1tttt_1300_1000;
  T1tttt_1300_1000.push_back("T1tttt_1300_1000");
  
  std::vector<std::string> T1tttt_1600_0;
  T1tttt_1600_0.push_back("T1tttt_1600_0");
  
  std::vector<std::string> T1tttt_1600_1200;
  T1tttt_1600_1200.push_back("T1tttt_1600_1200");

  //Spring 15 WZ
  std::vector<std::string> WZTo3LNu;
  WZTo3LNu.push_back("Tree_WZTo3LNu_0");

  //Spring 15 rares
  std::vector<std::string> TTWToLNu;
  TTWToLNu.push_back("Tree_TTWToLNu_0");

  std::vector<std::string> TTZToLLNuNu;
  TTZToLLNuNu.push_back("Tree_TTZToLLNuNu_0");

  //Phys14 SAMPLES 
  std::vector<std::string> WJets;
  WJets.push_back("WJetsToLNu_HT100to200"); 
  WJets.push_back("WJetsToLNu_HT200to400");  
  WJets.push_back("WJetsToLNu_HT400to600"); 
  WJets.push_back("WJetsToLNu_HT600toInf"); 

  std::vector<std::string> ZJets;
  ZJets.push_back("DYJetsToLL_M50_HT100to200"); 
  ZJets.push_back("DYJetsToLL_M50_HT200to400"); 
  ZJets.push_back("DYJetsToLL_M50_HT400to600"); 
  ZJets.push_back("DYJetsToLL_M50_HT600toInf"); 
  
  std::vector<std::string> SingleTop;
  SingleTop.push_back("TToLeptons_sch");
  SingleTop.push_back("TToLeptons_tch");
  SingleTop.push_back("T_tWch");
  SingleTop.push_back("TBarToLeptons_sch");
  SingleTop.push_back("TBarToLeptons_tch");
  SingleTop.push_back("TBar_tWch");
  
  std::vector<std::string> rare;
  rare.push_back("TTWJets");
  rare.push_back("TTZJets");
  rare.push_back("WZJetsTo3LNu");
  rare.push_back("ZZTo4L");
  rare.push_back("TTH");
  
  std::vector<std::string> fakes;
  fakes.push_back("DYJetsToLL_M50_HT100to200");
  fakes.push_back("DYJetsToLL_M50_HT200to400");
  fakes.push_back("DYJetsToLL_M50_HT400to600");
  fakes.push_back("DYJetsToLL_M50_HT600toInf");
  fakes.push_back("TTJets");
  fakes.push_back("TToLeptons_sch");
  fakes.push_back("TToLeptons_tch");
  fakes.push_back("T_tWch");
  fakes.push_back("TBarToLeptons_sch");
  fakes.push_back("TBarToLeptons_tch");
  fakes.push_back("TBar_tWch");

  std::vector<std::string> ttVH;
  ttVH.push_back("TTWJets");
  ttVH.push_back("TTZJets");
  ttVH.push_back("TTH");
  
  std::vector<std::string> ttV;
  ttV.push_back("TTWJets");
  ttV.push_back("TTZJets");

  std::vector<std::string> ZZTo4L;
  ZZTo4L.push_back("ZZTo4L");


  std::vector<std::string> TTJets; TTJets.push_back("TTJets");
  
  std::vector<std::string> TTWJets_aMCatNLO; TTWJets_aMCatNLO.push_back("TTWJets_aMCatNLO");
  std::vector<std::string> TTZJets_aMCatNLO; TTZJets_aMCatNLO.push_back("TTZJets_aMCatNLO");
  std::vector<std::string> TTWJets; TTWJets.push_back("TTWJets");
  std::vector<std::string> TTZJets; TTZJets.push_back("TTZJets");
  std::vector<std::string> WZJetsTo3LNu; WZJetsTo3LNu.push_back("WZJetsTo3LNu");
  std::vector<std::string> TTH; TTH.push_back("TTH");

  //Spring 15 T1tttt scan
  std::map<std::string, std::vector<std::string> > result;
  result["T1tttt_700_0"] = T1tttt_700_0;
  result["T1tttt_700_475"] = T1tttt_700_475;
  result["T1tttt_1100_800"] = T1tttt_1100_800;
  result["T1tttt_1300_0"] = T1tttt_1300_0;
  result["T1tttt_1300_1000"] = T1tttt_1300_1000;
  result["T1tttt_1600_0"] = T1tttt_1600_0;
  result["T1tttt_1600_1200"] = T1tttt_1600_1200;

  
  //Spring 15 WZ
  result["Tree_WZTo3LNu_0"] = WZTo3LNu;  
  
  //Spring 15 backgrounds
  result["Tree_TTWToLNu_0"] = TTWToLNu;
  result["Tree_TTZToLLNuNu_0"] = TTZToLLNuNu;

  //Phys14 SAMPLES
  result["WJets"] = WJets;
  result["ZJets"] = ZJets;
  result["Single-t"] = SingleTop;
  result["rare"] = rare;
  result["fakes"] = fakes;
  result["ttV/H"] = ttVH;
  result["ttV"] = ttV;
  result["ttH"] = TTH;
  result["TTJets"] = TTJets;
  result["TTWJets"] = TTWJets;
  result["TTZJets"] = TTZJets;
  result["TTW aMCatNLO"] = TTWJets_aMCatNLO;
  result["TTZ aMCatNLO"] = TTZJets_aMCatNLO;

  result["ZZTo4L"] = ZZTo4L;
  result["WZJetsTo3LNu"] = WZJetsTo3LNu;
  
  return result;
  
  
}

std::vector<std::string> get_vec_Q2sys() {
  std::vector<std::string> result;

  result.push_back("1001");//first one is the reference
  result.push_back("1005");
  result.push_back("1009");

  //result.push_back("1");//first one is the reference
  //result.push_back("5");
  //result.push_back("9");

  return result;
}

std::vector<std::string> get_vec_Q2sys_long() {
  std::vector<std::string> result;

  result.push_back("1001");//first one is the reference
  result.push_back("1002");
  result.push_back("1003");
  result.push_back("1004");
  result.push_back("1005");
  result.push_back("1006");
  result.push_back("1007");
  result.push_back("1008");
  result.push_back("1009");

  //result.push_back("1");//first one is the reference
  //result.push_back("5");
  //result.push_back("9");

  return result;
}


std::vector<std::string> get_vec_PDFsys() {
  std::vector<std::string> result;

  result.push_back("1001");//first one is the reference
  result.push_back("2001");
  result.push_back("2100");
  
  //result.push_back("1");//first one is the reference
  //result.push_back("5");
  //result.push_back("9");

  return result;
}

std::vector<std::string> get_vec_alphaS() {
  std::vector<std::string> result;

  result.push_back("1001");//first one is the reference
  result.push_back("2101");
  result.push_back("2102");

  //result.push_back("1");//first one is the reference
  //result.push_back("5");
  //result.push_back("9");

  return result;
}




float luminosity=3000;

void doSomething();
void doQ2(int total = 1, int varset = 0, bool latex = true);
void doPDF(int total = 1, int varset = 0, bool latex = true);
void doXsecPDFhisto();
void doWZ_steps();


void yields(int total = 1, int varset = 0, bool latex = true) {
 //doSomething();
 //doWZ_steps();
 

 doQ2(total, varset, latex);
// doPDF(total, varset, latex);
// doXsecPDFhisto();
}

void doWZ_steps() {
  int i = 0;
  i = i + 10;
}


void doQ2(int total, int varset, bool latex) {
  
  std::string fileroot = "/nfs/fanae/user/nachos/WZ/workdir/root/WZsynchro/theosystALL_LEPPTall_LEPFLAVall_LHE";
  
  //RA7
  //std::string fileroot = "/nfs/fanae/user/nachos/WZ/workdir/root/SUSY3L/pSUSY3L_BRnoMT2_ttWttZ_LEPPTall_LEPFLAVall_LHE";
  
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151019/MPAF/workdir/root/WZsynchro/FE_ttWttZ_XNJXHT_V2_LEPPTall_LEPFLAVall_LHE";
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151019/MPAF/workdir/root/WZsynchro/FE_ttWttZ_XNJXHT_LEPPTall_LEPFLAVall_LHE";
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151019/MPAF/workdir/root/WZsynchro/FE_ttWttZ_LEPPTall_LEPFLAVall_LHE";
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151019/MPAF/workdir/root/WZsynchro/FE_testyyy_LEPPTall_LEPFLAVall_LHE";
  
  //Spring 15 before synchro
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151009/MPAF/workdir/root/WZsynchro/FE_ttZlow_LEPPTall_LEPFLAVall_LHE";
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151009/MPAF/workdir/root/WZsynchro/FE_LEPPTall_LEPFLAVall_LHE";
  
  
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/FE_LEPPTall_LEPFLAVall_LHE";

  map<string,float> LumisXS;
  
  std::map<std::string, std::map<std::string, double> > map_wsum = get_map_wsum(); // map of process & variation with sum of weights
  std::map<std::string, double> map_xsec = get_map_xsec();
  std::vector<std::string> vec_SRs = get_vec_SRs(varset); // variable (& selection step) from the tree
  //std::vector<std::string> vec_samples = get_vec_samples();
  std::vector<std::string> vec_proc = get_vec_proc(); // list of processes
  std::map<std::string, std::vector<std::string> > map_proc = get_map_proc();
  std::vector<std::string> vec_Q2sys = get_vec_Q2sys();
  //std::vector<std::string> vec_Q2sys = get_vec_alphaS();
  std::vector<std::string> vec_Q2sys_long = get_vec_Q2sys_long();

  //print headter table
  if (latex) {
    printf ("%s\n", "\\begin{table}[ht]");
    printf ("%s\n", "\\begin{center}");
    printf ("%s", "\\begin{tabular}{|c|");
  }
  
  for (unsigned int iproc = 0; iproc < vec_proc.size(); iproc++) {
    if (latex) printf ("%s", "|c");
  }
  if (latex) printf ("%s\n", "|}\\hline");
  else printf ("%s", "\n");

  //print labels line
  if (latex) printf ("%s\t&", "Yields3fb-1");
  else printf ("%s\t", "Yields3fb-1");
  
  for (unsigned int iproc = 0; iproc < vec_proc.size() - 1; iproc++) {
    if (latex) printf ("%s\t&", vec_proc[iproc].c_str());
    else  printf ("%s\t%s\t%s\t%s\t", vec_proc[iproc].c_str(), "stat", "var+", "var-");
  }
  if (latex) printf ("%s\%s\n", vec_proc[vec_proc.size() - 1].c_str(), "\\\\ \\hline \\hline");
  else printf ("%s\t%s\t%s\t%s\n", vec_proc[vec_proc.size() - 1].c_str(), "stat", "var+", "var-");


  for (unsigned int iSR = 0; iSR < vec_SRs.size(); iSR++) {
    if (latex) printf ("%s%s", vec_SRs[iSR].c_str(), "\t& ");
    else printf ("%s%s", vec_SRs[iSR].c_str(), "\t ");
    
    for (unsigned int iproc = 0; iproc < vec_proc.size(); iproc++) {

      std::vector<std::string> sample = map_proc[vec_proc[iproc]];
      
      double val_Zero = 0;
      double err_square_Zero = 0;
            
      double valAcc_Plus = 0;
      double errAcc_square_Plus = 0;
      double valAcc_Minus = 0;
      double errAcc_square_Minus = 0;

      double valTot_Plus = 0;
      double errTot_square_Plus = 0;            
      double valTot_Minus = 0;
      double errTot_square_Minus = 0;
      
      double valAcc_vec[8];
      double errAcc_square_vec[8];
      double valTot_vec[8];
      double errTot_square_vec[8];
      
      double sysTot_Max = -999.0, sysAcc_Max = -999.0;
      double sysTot_Min = 999.0, sysAcc_Min = 999.0;
      
      std::string s_sysTot_Max = "";
      std::string s_sysTot_Min = "";
      std::string s_sysAcc_Max = "";
      std::string s_sysAcc_Min = "";
      
      double RMS = 0;

            
      for (unsigned int isample = 0; isample < sample.size(); isample++) {
        //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << std::endl;

	{
	  std::string fname = fileroot + vec_Q2sys[0] + ".root";
	  //std::cout << endl << fname << endl;
	  
	  TFile* _file = new TFile(fname.c_str());
	  TDirectoryFile *dfile = (TDirectoryFile*)_file->Get(vec_SRs[iSR].c_str());
	  TH1F* htmp = NULL;
	  htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  
	  //std::cout << "_file = " << _file << std::endl;
	  //std::cout << "dfile = " << dfile << std::endl;
	  //std::cout << "htmp = " << htmp << std::endl;
	  	  
	  if (htmp != 0) {
	    int nbin = htmp->GetNbinsX();
	    double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys[0]];
	    double tmperr;
	    double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	    val_Zero += tmpval*normFactor;
	    err_square_Zero += (tmperr*normFactor)*(tmperr*normFactor);
	    
	    //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	  }
	  else {
	    std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	    exit(0);
	  }
	
	}//pointers_Zero


	{
	  std::string fname = fileroot + vec_Q2sys[1] + ".root";
	  //std::cout << endl << fname << endl;
	  
	  TFile* _file = new TFile(fname.c_str());
	  TDirectoryFile *dfile = (TDirectoryFile*)_file->Get(vec_SRs[iSR].c_str());
	  TH1F* htmp = NULL;
	  htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  
	  //std::cout << "_file = " << _file << std::endl;
	  //std::cout << "dfile = " << dfile << std::endl;
	  //std::cout << "htmp = " << htmp << std::endl;
	  	  
	  if (htmp != 0) {
	    int nbin = htmp->GetNbinsX();
	    double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys[1]];
	    double normFactorTot = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys[0]];
	    double tmperr;
	    double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	    valAcc_Plus += tmpval*normFactor;
	    errAcc_square_Plus += (tmperr*normFactor)*(tmperr*normFactor);
	    valTot_Plus += tmpval*normFactorTot;
	    errTot_square_Plus += (tmperr*normFactorTot)*(tmperr*normFactorTot);
	    
	    //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	  }
	  else {
	    std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	    exit(0);
	  }
	
	}//pointers_Plus

	{
	  std::string fname = fileroot + vec_Q2sys[2] + ".root";
	  //std::cout << endl << fname << endl;
	  
	  TFile* _file = new TFile(fname.c_str());
	  TDirectoryFile *dfile = (TDirectoryFile*)_file->Get(vec_SRs[iSR].c_str());
	  TH1F* htmp = NULL;
	  htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  
	  //std::cout << "_file = " << _file << std::endl;
	  //std::cout << "dfile = " << dfile << std::endl;
	  //std::cout << "htmp = " << htmp << std::endl;
	  	  
	  if (htmp != 0) {
	    int nbin = htmp->GetNbinsX();
	    double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys[2]];
	    double normFactorTot = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys[0]];
	    double tmperr;
	    double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	    valAcc_Minus += tmpval*normFactor;
	    errAcc_square_Minus += (tmperr*normFactor)*(tmperr*normFactor);
	    valTot_Minus += tmpval*normFactorTot;
	    errTot_square_Minus += (tmperr*normFactorTot)*(tmperr*normFactorTot);
	    
	    //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	  }
	  else {
	    std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	    exit(0);
	  }
	
	}//pointers_Minus




	for (unsigned int iq2 = 0; iq2 < 8; iq2++) {

	  std::string fname = fileroot + vec_Q2sys_long[iq2+1] + ".root";
	  //std::cout << endl << fname << endl;
	  
	  TFile* _file = new TFile(fname.c_str());
	  TDirectoryFile *dfile = (TDirectoryFile*)_file->Get(vec_SRs[iSR].c_str());
	  TH1F* htmp = NULL;
	  htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  
	  //std::cout << "_file = " << _file << std::endl;
	  //std::cout << "dfile = " << dfile << std::endl;
	  //std::cout << "htmp = " << htmp << std::endl;
	  	  
	  if (htmp != 0) {
	    int nbin = htmp->GetNbinsX();
	    double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys_long[iq2+1]];
	    double normFactorTot = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_Q2sys_long[0]];
	    double tmperr;
	    double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	    valAcc_vec[iq2] = tmpval*normFactor;
	    errAcc_square_vec[iq2] += (tmperr*normFactor)*(tmperr*normFactor);
	    valTot_vec[iq2] = tmpval*normFactorTot;
	    errTot_square_vec[iq2] += (tmperr*normFactorTot)*(tmperr*normFactorTot);
	    
	    //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	  }
	  else {
	    std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	    exit(0);
	  }
	
	}//pointers_Loop



      } // isample loop
      
      double err_Zero = sqrt(err_square_Zero);
      double errAcc_Plus = sqrt(errAcc_square_Plus);
      double errAcc_Minus = sqrt(errAcc_square_Minus);
      double errTot_Plus = sqrt(errTot_square_Plus);
      double errTot_Minus = sqrt(errTot_square_Minus);
      
      double sysAcc_Plus = -1;
      double sysAcc_Minus = -1;      
      if (valAcc_Plus != 0 && val_Zero != 0) sysAcc_Plus = (valAcc_Plus > val_Zero)? valAcc_Plus/val_Zero - 1.0: -val_Zero/valAcc_Plus + 1.0;
      if (valAcc_Minus != 0 && val_Zero != 0)  sysAcc_Minus = (valAcc_Minus > val_Zero)? valAcc_Minus/val_Zero - 1.0: -val_Zero/valAcc_Minus + 1.0;
      
      double sysTot_Plus = -1;
      double sysTot_Minus = -1;      
      if (valTot_Plus != 0 && val_Zero != 0) sysTot_Plus = (valTot_Plus > val_Zero)? valTot_Plus/val_Zero - 1.0: -val_Zero/valTot_Plus + 1.0;
      if (valTot_Minus != 0 && val_Zero != 0)  sysTot_Minus = (valTot_Minus > val_Zero)? valTot_Minus/val_Zero - 1.0: -val_Zero/valTot_Minus + 1.0;
      
      
      double sysAcc_vec[8];
      double sysTot_vec[8];
      for (unsigned int iq2 = 0; iq2 < 8; iq2++) {
      if (iq2==4 || iq2==6) continue;
        if (valAcc_vec[iq2] != 0 && val_Zero != 0) sysAcc_vec[iq2] = (valAcc_vec[iq2] > val_Zero)? valAcc_vec[iq2]/val_Zero - 1.0: -val_Zero/valAcc_vec[iq2] + 1.0;
        if (valTot_vec[iq2] != 0 && val_Zero != 0) sysTot_vec[iq2] = (valTot_vec[iq2] > val_Zero)? valTot_vec[iq2]/val_Zero - 1.0: -val_Zero/valTot_vec[iq2] + 1.0;
        std::string sqsqr;
	    std::stringstream convert;
	    convert << (iq2+1002);
	    sqsqr = convert.str();
        
        if (total == 2) { // largest deviations in acceptance
          RMS += sysAcc_vec[iq2]*sysAcc_vec[iq2];
          if (sysAcc_vec[iq2] > sysAcc_Max) {
            sysTot_Max = sysTot_vec[iq2];
	        sysAcc_Max = sysAcc_vec[iq2];
	        s_sysAcc_Max = sqsqr;
	      }
	      if (sysAcc_vec[iq2] < sysAcc_Min) {
	        sysTot_Min = sysTot_vec[iq2];
	        sysAcc_Min = sysAcc_vec[iq2];
	        s_sysAcc_Min = sqsqr;
	      }
	    } else if (total == 3) { // largest deviations in total
	      RMS += sysTot_vec[iq2]*sysTot_vec[iq2];
          if (sysTot_vec[iq2] > sysTot_Max) {
            sysTot_Max = sysTot_vec[iq2];
	        sysAcc_Max = sysAcc_vec[iq2];
	        s_sysTot_Max = sqsqr;
	      }
	      if (sysTot_vec[iq2] < sysTot_Min) {
	        sysTot_Min = sysTot_vec[iq2];
	        sysAcc_Min = sysAcc_vec[iq2];
	        s_sysTot_Min = sqsqr;
	      }	      
        }
        
      }
      RMS = sqrt(RMS/9);
      if (total == 1) {
        if (latex) {
	      printf ("%.2f%s%.2f", val_Zero, "\t$\\pm$\t", err_Zero);
          printf ("%s%.3f%s", "\t\\textcolor{blue}{(", sysTot_Plus, ")}\t");
          printf ("%s%.3f%s", "\t\\textcolor{green}{(", sysTot_Minus, ")}\t");
        }
        else {
	      printf ("%.2f%s%.2f", val_Zero, "\t", err_Zero);
          printf ("%s%.3f", "\t", sysTot_Plus);
          printf ("%s%.3f", "\t", sysTot_Minus);
	    }
      }
      else if (total == 0) {
        if (latex) {
	      printf ("%.2f%s%.2f", val_Zero, "\t$\\pm$\t", err_Zero);
          printf ("%s%.3f%s", "\t\\textcolor{blue}{(", sysAcc_Plus, ")}\t");
          printf ("%s%.3f%s", "\t\\textcolor{green}{(", sysAcc_Minus, ")}\t");
	    }
	    else {
          printf ("%.2f%s%.2f", val_Zero, "\t", err_Zero);
          printf ("%s%.3f", "\t", sysAcc_Plus);
          printf ("%s%.3f", "\t", sysAcc_Minus);
	    }

      } else if (total == 2) {
        if (latex) {
	      printf ("%.2f%s%.2f", val_Zero, "\t$\\pm$\t", err_Zero);
          std::string tmp_smax = "-$>$"+s_sysAcc_Max;
          std::string tmp_smin = "-$>$"+s_sysAcc_Min;
          printf ("%s%.3f%s%s", "\t\\textcolor{blue}{(", sysAcc_Max, tmp_smax.c_str(), ")}\t");
          printf ("%s%.3f%s%s", "\t\\textcolor{green}{(", sysAcc_Min, tmp_smin.c_str(),")}");
	    }        
      } else if (total == 3) {
        if (latex) {
	      printf ("%.2f%s%.2f", val_Zero, "\t$\\pm$\t", err_Zero);
          std::string tmp_smax = "-$>$"+s_sysTot_Max;
          std::string tmp_smin = "-$>$"+s_sysTot_Min;
          printf ("%s%.3f%s%s", "\t\\textcolor{blue}{(", sysTot_Max, tmp_smax.c_str(), ")}\t");
          printf ("%s%.3f%s%s", "\t\\textcolor{green}{(", sysTot_Min, tmp_smin.c_str(),")}");
	    }         
      }
      
      //print just values
      //printf ("%.2f%s%.2f", val_Zero, "\t$\\pm$\t", err_Zero);
      //printf ("%.2f%s%.2f", valAcc_Plus, "\t$\\pm$\t", errAcc_Plus);
      //printf ("%.2f%s%.2f", valAcc_Minus, "\t$\\pm$\t", errAcc_Minus);
      
      if (iproc != vec_proc.size() -1) {
        if (latex) printf ("%s", "\t& ");
	    else printf ("%s", "\t ");
      }
      else {
        if (latex) printf ("\\\\\n");
	    else printf ("\n");
      }
      
    }//iproc loop
    
  }//SRs loop
  
  if (latex) {
    printf ("%s\n", "\\hline");
    printf ("%s\n", "\\end{tabular}");
    printf ("%s\n", "\\end{center}");
    printf ("%s\n", "\\end{table}");
  }
}


void doPDF(int total, int varset, bool latex) {
  
  std::string fileroot = "/nfs/fanae/user/nachos/WZ/workdir/root/WZsynchro/theosystALL_LEPPTall_LEPFLAVall_LHE";
  
  //RA7
  //std::string fileroot = "/nfs/fanae/user/nachos/WZ/workdir/root/SUSY3L/pSUSY3L_BRnoMT2_ttWttZ_LEPPTall_LEPFLAVall_LHE";

  
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Spring15_151009/MPAF/workdir/root/WZsynchro/FE_LEPPTall_LEPFLAVall_LHE";
  
  
  //Phys14
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/FE_LEPPTall_LEPFLAVall_LHE";
  //std::string fileroot = "/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/FE_LEPPTall_LEPFLAVall_LHE";

  map<string,float> LumisXS;
  
  std::map<std::string, std::map<std::string, double> > map_wsum = get_map_wsum();
  std::map<std::string, double> map_xsec = get_map_xsec();
  std::vector<std::string> vec_SRs = get_vec_SRs(varset);
  //std::vector<std::string> vec_samples = get_vec_samples();
  std::vector<std::string> vec_proc = get_vec_proc();
  std::map<std::string, std::vector<std::string> > map_proc = get_map_proc();
  std::vector<std::string> vec_PDFsys = get_vec_PDFsys();

  //print headter table
  printf ("%s\n", "\\begin{table}[ht]");
  printf ("%s\n", "\\begin{center}");
  printf ("%s", "\\begin{tabular}{|c|");
  for (unsigned int iproc = 0; iproc < vec_proc.size(); iproc++) printf ("%s", "|c");
  printf ("%s\n", "|}\\hline");

  //print labels line
  printf ("%s\t&", "Yields3fb-1");
  for (unsigned int iproc = 0; iproc < vec_proc.size() - 1; iproc++) printf ("%s\t&", vec_proc[iproc].c_str());
  printf ("%s\%s\n", vec_proc[vec_proc.size() - 1].c_str(), "\\\\ \\hline \\hline");


  for (unsigned int iSR = 0; iSR < vec_SRs.size(); iSR++) {
    printf ("%s%s", vec_SRs[iSR].c_str(), "\t& ");
    
    for (unsigned int iproc = 0; iproc < vec_proc.size(); iproc++) {

      std::vector<std::string> sample = map_proc[vec_proc[iproc]];
      
      double val_Zero = 0;
      double err_square_Zero = 0;
      
            

       
      double sysTot_Max = -999.0, sysAcc_Max = -999.0;
      double sysTot_Min = 999.0, sysAcc_Min = 999.0;
      
      std::string s_sysTot_Max = "";
      std::string s_sysTot_Min = "";
      std::string s_sysAcc_Max = "";
      std::string s_sysAcc_Min = "";
      
      double RMS = 0;
      


      
      std::string spdf_first = vec_PDFsys[1];
      std::string spdf_last = vec_PDFsys[2];
      int ipdf_first = atoi(spdf_first.c_str());
      int ipdf_last = atoi(spdf_last.c_str());
      
      for (unsigned int isample = 0; isample < sample.size(); isample++) {
        //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << std::endl;

	{
	  std::string fname = fileroot + vec_PDFsys[0] + ".root";
	  //std::cout << endl << fname << endl;
	  
	  TFile* _file = new TFile(fname.c_str());
	  TDirectoryFile *dfile = (TDirectoryFile*)_file->Get(vec_SRs[iSR].c_str());
	  TH1F* htmp = NULL;
	  htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  	  	  
	  if (htmp != 0) {
	    int nbin = htmp->GetNbinsX();
	    double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_PDFsys[0]];
	    double tmperr;
	    double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	    val_Zero += tmpval*normFactor;
	    err_square_Zero += (tmperr*normFactor)*(tmperr*normFactor);
	    
	    //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	  }
	  else {
	    std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	    exit(0);
	  }
	    
	  _file->Close();
	  //dfile->Close();
	  //delete htmp;
	
	}//pointers_Zero


      }//isample
      double err_Zero = sqrt(err_square_Zero);
      
      //std::cout << endl;
      for (int ipdf = ipdf_first; ipdf <= ipdf_last ; ipdf++) {
        std::string spdf;
	std::stringstream convert;
	convert << ipdf;
	spdf = convert.str();
        //std::cout << "ipdf = " << ipdf << "\t" << spdf << std::endl;     
        
	//printf("%d\t", ipdf);
	
	double valAcc_PDF = 0;
        double errAcc_square_PDF = 0;
        double valTot_PDF = 0;
        double errTot_square_PDF = 0;            
        double valTot_Plus = 0;
        double errTot_square_Plus = 0;            

	
    for (unsigned int isample = 0; isample < sample.size(); isample++) {
          //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << std::endl;
	  //std::cout << "wsumNom:" << map_wsum[sample[isample].c_str()][vec_PDFsys[0]]
	  //	    << "wsumVar:" << map_wsum[sample[isample].c_str()][spdf] << std::endl;
	  

	  {
	    std::string fname = fileroot + spdf + ".root";
	    //std::cout << endl << fname << endl;
	  
	    TFile* _file = new TFile(fname.c_str());
	    TDirectoryFile *dfile = (TDirectoryFile*)_file->Get(vec_SRs[iSR].c_str());
	    TH1F* htmp = NULL;
	    htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  	  	  
	    if (htmp != 0) {
	      int nbin = htmp->GetNbinsX();
	      double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][spdf];
	      double normFactorTot = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][vec_PDFsys[0]];
	      double tmperr;
	      double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	      valAcc_PDF += tmpval*normFactor;
	      errAcc_square_PDF += (tmperr*normFactor)*(tmperr*normFactor);
	      valTot_PDF += tmpval*normFactorTot;
	      errTot_square_PDF += (tmperr*normFactorTot)*(tmperr*normFactorTot);
	    
	      //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	    }
	    else {
	      std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	      exit(0);
	    }
	    
	    _file->Close();
	    //dfile->Close();
	    //delete htmp;
	    //double xxx = map_wsum[sample[isample].c_str()][vec_PDFsys[0]];
	    //double xxx = map_wsum[sample[isample].c_str()][spdf];
	    //printf ("%.3f%s%.3f%s%.3f", valAcc_PDF, "\t", valTot_PDF, "\t", xxx);
	  }//pointers_PDF
	  //std::cout << endl;


    }//isample

        double errAcc_PDF = sqrt(errAcc_square_PDF);
        double errTot_PDF = sqrt(errTot_square_PDF);
      

      
        double sysAcc_PDF = -1;
        double sysTot_PDF = -1;

      
        if (valAcc_PDF != 0 && val_Zero != 0) sysAcc_PDF = (valAcc_PDF > val_Zero)? valAcc_PDF/val_Zero - 1.0: -val_Zero/valAcc_PDF + 1.0;
        if (valTot_PDF != 0 && val_Zero != 0) sysTot_PDF = (valTot_PDF > val_Zero)? valTot_PDF/val_Zero - 1.0: -val_Zero/valTot_PDF + 1.0;
	
	RMS += sysTot_PDF*sysTot_PDF;
        
        
    if (total != 2) {    
	  if (sysTot_PDF > sysTot_Max) {
          sysTot_Max = sysTot_PDF;
	  sysAcc_Max = sysAcc_PDF;
	  s_sysTot_Max = spdf;
        } 
        if (sysTot_PDF < sysTot_Min) {
          sysTot_Min = sysTot_PDF;
	  sysAcc_Min = sysAcc_PDF;
	  s_sysTot_Min = spdf;	
        }
        
    } else {
      RMS += sysAcc_PDF*sysAcc_PDF;
      if (sysAcc_PDF > sysAcc_Max) {
        sysTot_Max = sysTot_PDF;
	    sysAcc_Max = sysAcc_PDF;
	    s_sysAcc_Max = spdf;
	  }
	  if (sysAcc_PDF < sysAcc_Min) {
	    sysTot_Min = sysTot_PDF;
	    sysAcc_Min = sysAcc_PDF;
	    s_sysAcc_Min = spdf;
	  }
	}

        
        
        
        
      }//iPDF
      
      double npdf = double (ipdf_last - ipdf_first + 1);
      //std::cout << endl << "npdf=" << npdf << std::endl;
      RMS = sqrt(RMS/npdf);
      
      //std::cout << "ipdf = "<< ipdf << " val_Zero=" << val_Zero << " " << " acc=" << valAcc_PDF << " tot=" << valTot_PDF << std::endl;
      

      
      printf ("%.2f%s%.2f", val_Zero, "\t$\\pm$\t", err_Zero);
      
      if (total == 0) {
        printf ("%s%.3f%s", "\t\\textcolor{blue}{(", sysAcc_Max, ")}\t");
        printf ("%s%.3f%s", "\t\\textcolor{green}{(", sysAcc_Min, ")}\t");
      }
      else if (total == 1) {
        std::string tmp_smax = "-$>$"+s_sysTot_Max;
        std::string tmp_smin = "-$>$"+s_sysTot_Min;
        printf ("%s%.3f%s%s", "\t\\textcolor{blue}{(", sysTot_Max, tmp_smax.c_str(), ")}\t");
        printf ("%s%.3f%s%s%.3f", "\t\\textcolor{green}{(", sysTot_Min, tmp_smin.c_str(),")}\tRMS: ", RMS);
        //printf ("%s%.3f%s%s", "\t\\textcolor{green}{(", sysTot_Min, tmp_smin.c_str(),")}\t");
        //printf ("%s%.3f%s", "\t\\textcolor{blue}{(", sysTot_Max, ")}\t");
        //printf ("%s%.3f%s", "\t\\textcolor{green}{(", sysTot_Min, ")}\t");
      }
      else if (total == 2) {
        std::string tmp_smax = "-$>$"+s_sysAcc_Max;
        std::string tmp_smin = "-$>$"+s_sysAcc_Min;
        printf ("%s%.3f%s%s", "\t\\textcolor{blue}{(", sysAcc_Max, tmp_smax.c_str(), ")}\t");
        printf ("%s%.3f%s%s%.3f", "\t\\textcolor{green}{(", sysAcc_Min, tmp_smin.c_str(),")}\tRMS: ", RMS);
        //printf ("%s%.3f%s%s", "\t\\textcolor{green}{(", sysTot_Min, tmp_smin.c_str(),")}\t");
        //printf ("%s%.3f%s", "\t\\textcolor{blue}{(", sysTot_Max, ")}\t");
        //printf ("%s%.3f%s", "\t\\textcolor{green}{(", sysTot_Min, ")}\t");
      }
      //std::string tmp_smax = "->"+s_sysTot_Max;
      //std::string tmp_smin = "->"+s_sysTot_Min;
      //printf ("%s%.5f%s%s", "\t\\textcolor{blue}{(", sysTot_Max, tmp_smax.c_str(), ")}\t");
      //printf ("%s%.5f%s%s", "\t\\textcolor{green}{(", sysTot_Min, tmp_smin.c_str(),")}\t");
      
      
      //print just values
      //printf ("%.2f%s%.2f%s", val_Zero, "\t$\\pm$\t", err_Zero,"\t");
      //printf ("%.2f%s%.2f%s", valAcc_PDF, "\t$\\pm$\t", errAcc_PDF, "\t");
      //printf ("%.2f%s%.2f", valTot_PDF, "\t$\\pm$\t", errTot_PDF);
      //printf ("%.3f%s%.3f%s", sysAcc_Max, "\t$\\pm$\t", sysAcc_Min, "\t");
      //printf ("%.3f%s%.3f%s", sysTot_Max, "\t$\\pm$\t", sysTot_Min, "\t");

      
      if (iproc != vec_proc.size() -1) printf ("%s", "\t& ");
      else printf ("\\\\\n");
      
    }// iproc loop
    
  }//SRs loop
  
    printf ("%s\n", "\\hline");
    printf ("%s\n", "\\end{tabular}");
    printf ("%s\n", "\\end{center}");
    printf ("%s\n", "\\end{table}");

}

TH1F* h_pdfXsec_WZ  = new TH1F("WZ distribution & fit" , "WZ PDF variation"       , 120, -0.060, 0.060);
TH1F* h_pdfXsec_TTW = new TH1F("ttW distribution & fit", "t#bar{t}W PDF variation", 120, -0.060, 0.060);
TH1F* h_pdfXsec_TTZ = new TH1F("ttZ distribution & fit", "t#bar{t}Z PDF variation", 120, -0.060, 0.060);

//TH1F* h_pdfXsec_TTW = new TH1F("h_pdfXsec_TTW", "h_pdfXsec_TTW", 101, -0.05, 0.05);
//TH1F* h_pdfXsec_TTZ = new TH1F("h_pdfXsec_TTZ", "h_pdfXsec_TTZ", 101, -0.05, 0.05);
void doXsecPDFhisto() {

  std::map<std::string, std::map<std::string, double> > map_wsum = get_map_wsum();
  
  std::string spdf_first = "2001";
  std::string spdf_last  = "2100";
  
  int ipdf_first = atoi(spdf_first.c_str());
  int ipdf_last = atoi(spdf_last.c_str());
  
  //Spring15
  std::string s_wz  = "Tree_WZTo3LNu_0";
  std::string s_ttw = "Tree_TTWToLNu_0";
  std::string s_ttz = "Tree_TTZToLLNuNu_0";
  
  //Phys14
  //std::string s_ttw = "TTWJets_aMCatNLO";
  //std::string s_ttz = "TTZJets_aMCatNLO";

  double nom_wz  = map_wsum[s_wz]["1001"];  
  double nom_ttw = map_wsum[s_ttw]["1001"];
  double nom_ttz = map_wsum[s_ttz]["1001"];

  for (int ipdf = ipdf_first; ipdf <= ipdf_last ; ipdf++) {
    std::string spdf;
    std::stringstream convert;
    convert << ipdf;
    spdf = convert.str();

    double val_wz  = map_wsum[s_wz][spdf];    
    double val_ttw = map_wsum[s_ttw][spdf];
    double val_ttz = map_wsum[s_ttz][spdf];

    double var_wz  = -1;    
    double var_ttw = -1;
    double var_ttz = -1;

    if (val_wz  != 0 && nom_wz  != 0) var_wz  = (val_wz  > nom_wz )? val_wz /nom_wz  - 1.0: -nom_wz /val_wz  + 1.0;    
    if (val_ttw != 0 && nom_ttw != 0) var_ttw = (val_ttw > nom_ttw)? val_ttw/nom_ttw - 1.0: -nom_ttw/val_ttw + 1.0;
    if (val_ttz != 0 && nom_ttz != 0) var_ttz = (val_ttz > nom_ttz)? val_ttz/nom_ttz - 1.0: -nom_ttz/val_ttz + 1.0;
    
    h_pdfXsec_WZ ->Fill(var_wz );
    h_pdfXsec_TTW->Fill(var_ttw);
    h_pdfXsec_TTZ->Fill(var_ttz);
    
    //std::cout << "ipdf = " << ipdf << "\t" << spdf << std::endl;
    std::cout << "ipdf = " << ipdf << "\t" << spdf << "\t" << val_wz << "\t" << val_ttw << "\t" << val_ttz << "\t" << var_wz << "\t" << var_ttw << "\t" << var_ttz << std::endl;
        
  }
  
  gStyle->SetOptFit(0001);
  
  TCanvas c1;
  h_pdfXsec_WZ ->SetLineColor(kOrange-2);
  h_pdfXsec_TTW->SetLineColor(kGreen-6);
  h_pdfXsec_TTZ->SetLineColor(kRed);
  h_pdfXsec_WZ ->SetLineWidth(3);
  h_pdfXsec_TTW->SetLineWidth(3);
  h_pdfXsec_TTZ->SetLineWidth(3);
  
  h_pdfXsec_WZ ->Rebin(12);
  h_pdfXsec_TTW->Rebin(12);
  h_pdfXsec_TTZ->Rebin(12);
  /*
  if (h_pdfXsec_TTW->GetMaximum() > h_pdfXsec_TTZ->GetMaximum()) {
    h_pdfXsec_TTW->Draw();
    h_pdfXsec_TTZ->Draw("sames");
  }
  else {
    h_pdfXsec_TTZ->Draw();
    h_pdfXsec_TTW->Draw("sames");
  }
  */
  
  //h_pdfXsec_TTZ->Draw();
  
  
  
  TLegend * leg = new TLegend(0.15,0.7,0.4,0.85);
  //leg ->AddEntry(h_pdfXsec_TTW, "variation ttW");
  //leg ->AddEntry(h_pdfXsec_TTZ, "variation ttZ");
  
  //leg ->AddEntry(h_pdfXsec_WZ , "variation WZ" );
  //h_pdfXsec_WZ->Draw();
  
  //leg->Draw("sames");
  
  //h_pdfXsec_TTW->Fit("gaus");
  //h_pdfXsec_TTZ->Fit("gaus");
  h_pdfXsec_WZ->Fit("gaus");
  //leg->Draw("sames");
  
  c1.SaveAs("c_pdfXsec.png");
}



void doSomething() {


  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/fakeEstim_test.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/p_testone.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/p_testoneSanti.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/p_testoneSantiWZ.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/p_testoneWZ.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/p_testoneWZ_ftv4.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/fakeEstim_ftv4_all.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150519/MPAF/workdir/root/FakeEstim/FE_LEPPTall_LEPFLAVall_LHE1001.root");


  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150618/MPAF/workdir/root/WZsynchro/FE_LEPPTall_LEPFLAVall_LHE1001.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150618/MPAF/workdir/root/WZsynchro/FE_LEPPTall_LEPFLAVall_LHE1001_replica2.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150618/MPAF/workdir/root/WZsynchro/test_WZstep0.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150618/MPAF/workdir/root/WZsynchro/FE_LEPPTall_LEPFLAVall_LHE1001_WZstep4.root");
  TFile* f = new TFile("/nfs/fanae/user/nachos/WZ/workdir/root/WZsynchro/theosystALL_LEPPTall_LEPFLAVall_LHE1001.root");
  //TFile* f = new TFile("/nfs/fanae/user/vizan/MPAF/Phys14_150618/MPAF/workdir/root/WZsynchro/testWZSTEP5.root");
  
  
  //general parameters ********************* general parameters
  string dir="FakeEstim";
  
  //md.dp.setObservables("MET");


  map<string,float> LumisXS;
  
  std::map<std::string, std::map<std::string, double> > map_wsum = get_map_wsum();
  std::map<std::string, double> map_xsec = get_map_xsec();
  std::vector<std::string> vec_SRs = get_vec_SRs();
  //std::vector<std::string> vec_samples = get_vec_samples();
  std::vector<std::string> vec_proc = get_vec_proc();
  std::map<std::string, std::vector<std::string> > map_proc = get_map_proc();
  
  
  
  //f->cd();
  
   //print headter table
  printf ("%s\n", "\\begin{table}[ht]");
  printf ("%s\n", "\\begin{center}");
  printf ("%s", "\\begin{tabular}{|c|");
  for (unsigned int iproc = 0; iproc < vec_proc.size(); iproc++) printf ("%s", "|c");
  printf ("%s\n", "|}\\hline");
 
  //print labels line
  printf ("%s\t&", "Yields3fb-1");
  for (unsigned int iproc = 0; iproc < vec_proc.size() - 1; iproc++) printf ("%s\t&", vec_proc[iproc].c_str());
  printf ("%s\%s\n", vec_proc[vec_proc.size() - 1].c_str(), "\\\\ \\hline \\hline");

  for (unsigned int iSR = 0; iSR < vec_SRs.size(); iSR++) {
    //std::cout << "dir=" << TString(vec_SRs[iSR].c_str()) << std::endl;
    TDirectoryFile *dfile = (TDirectoryFile*)f->Get(vec_SRs[iSR].c_str());
    if (dfile == 0) {
      std::cout << "Couldn't find folder: " << vec_SRs[iSR].c_str() << std::endl;
      exit(0);
    }
    //std::cout << dfile << std::endl;
    
    
    /*for (unsigned int i = 0; i < vec_samples.size(); i++) {
      {
        //std::cout << TString(vec_samples[i].c_str()) << std::endl;
	
	TH1F* htmp = NULL;
	htmp = (TH1F*)dfile->Get(vec_samples[i].c_str());
	if (htmp != 0) {
	  int nbin = htmp->GetNbinsX();
	  double normFactor = luminosity*map_xsec[vec_samples[i].c_str()]/map_wsum[vec_samples[i].c_str()][LHEid];
	  double err;
	  double val = htmp->IntegralAndError(0, nbin + 1, err);
	  err*=normFactor; val*=normFactor;
	  
	  std::cout << vec_SRs[iSR] << "\t" << vec_samples[i].c_str() << "\t" << val << "\t$pm$\t" << err << std::endl; 
	  
	}
	else {
	  std::cout << "Couldn't find histogram: " << vec_samples[i].c_str() << std::endl;
	  exit(0);
	}
	//std::cout << htmp << " entries()= " << htmp->GetEntries() <<std::endl;
	
      
      }//NULL
    }*/
    
    printf ("%s%s", vec_SRs[iSR].c_str(), "\t& ");
    
    for (unsigned int iproc = 0; iproc < vec_proc.size(); iproc++) {
      //std::cout << "vec_proc: " << vec_proc[iproc] << std::endl;
      
      std::vector<std::string> sample = map_proc[vec_proc[iproc]];
      
      double val = 0;
      double err_square = 0;
      
      for (unsigned int isample = 0; isample < sample.size(); isample++) {
        //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << std::endl;
	{
	  TH1F* htmp = NULL;
	  htmp = (TH1F*)dfile->Get(sample[isample].c_str());
	  if (htmp != 0) {
	    int nbin = htmp->GetNbinsX();
	    double normFactor = luminosity*map_xsec[sample[isample].c_str()]/map_wsum[sample[isample].c_str()][LHEid];
	    double tmperr;
	    double tmpval = htmp->IntegralAndError(0, nbin + 1, tmperr);
	    
	    val += tmpval*normFactor;
	    err_square += (tmperr*normFactor)*(tmperr*normFactor);
	    
	    //std::cout << "sample[" << vec_proc[iproc] << "][" << isample << "]=" << sample[isample] << "\t" << tmpval*normFactor << "\t$pm$\t" << tmperr*normFactor << std::endl; 
	  
	  }
	  else {
	    std::cout << "Couldn't find histogram: " << sample[isample].c_str() << std::endl;
	    exit(0);
	  }
	  
	}//NULL
      }
      double err = sqrt(err_square);
      
      if (iproc != vec_proc.size() -1) printf ("%.2f%s%.2f%s", val, "\t$\\pm$\t", err, "\t& ");
      else printf ("%.2f%s%.2f\\\\\n", val, "\t$\\pm$\t", err);
    }
    
    

  }//SRs loop
  
    printf ("%s\n", "\\hline");
    printf ("%s\n", "\\end{tabular}");
    printf ("%s\n", "\\end{center}");
    printf ("%s\n", "\\end{table}");
  
  
}

std::map<std::string, std::map<std::string, double> > get_map_wsum() {

  std::map<std::string, std::map<std::string, double> > result; 
  //result["TTWJets_aMCatNLO"]["1001"]=4343.38450095;
  //result["TTZJets_aMCatNLO"]["1001"]=2608.27010085;
  
  //Spring 15 T1tttt scan
  result["T1tttt_1100_800"]["1"] = 0.0667931;
  result["T1tttt_1100_800"]["2"] = 0.0579765;
  result["T1tttt_1100_800"]["3"] = 0.0780286;
  result["T1tttt_1100_800"]["4"] = 0.0575046;
  result["T1tttt_1100_800"]["5"] = 0.0499129;
  result["T1tttt_1100_800"]["6"] = 0.0671776;
  result["T1tttt_1100_800"]["7"] = 0.0785307;
  result["T1tttt_1100_800"]["8"] = 0.0681648;
  result["T1tttt_1100_800"]["9"] = 0.0917388;
  result["T1tttt_1100_800"]["10"] = 0.0667931;
  result["T1tttt_1100_800"]["11"] = 0.0570101;
  result["T1tttt_1100_800"]["12"] = 0.044903;
  result["T1tttt_1100_800"]["13"] = 0.0648954;
  result["T1tttt_1100_800"]["14"] = 0.0694064;
  result["T1tttt_1100_800"]["15"] = 0.0564597;
  result["T1tttt_1100_800"]["16"] = 0.0529152;
  result["T1tttt_1100_800"]["17"] = 0.0827943;
  result["T1tttt_1100_800"]["18"] = 0.0552434;
  result["T1tttt_1100_800"]["19"] = 0.0753582;
  result["T1tttt_1100_800"]["20"] = 0.0425699;
  result["T1tttt_1100_800"]["21"] = 0.0512892;
  result["T1tttt_1100_800"]["22"] = 0.0518214;
  result["T1tttt_1100_800"]["23"] = 0.0672533;
  result["T1tttt_1100_800"]["24"] = 0.0797124;
  result["T1tttt_1100_800"]["25"] = 0.0641352;
  result["T1tttt_1100_800"]["26"] = 0.0516787;
  result["T1tttt_1100_800"]["27"] = 0.0818006;
  result["T1tttt_1100_800"]["28"] = 0.0843809;
  result["T1tttt_1100_800"]["29"] = 0.0702443;
  result["T1tttt_1100_800"]["30"] = 0.0643302;
  result["T1tttt_1100_800"]["31"] = 0.0760192;
  result["T1tttt_1100_800"]["32"] = 0.0576371;
  result["T1tttt_1100_800"]["33"] = 0.0643896;
  result["T1tttt_1100_800"]["34"] = 0.0521253;
  result["T1tttt_1100_800"]["35"] = 0.0841721;
  result["T1tttt_1100_800"]["36"] = 0.082118;
  result["T1tttt_1100_800"]["37"] = 0.084041;
  result["T1tttt_1100_800"]["38"] = 0.0708733;
  result["T1tttt_1100_800"]["39"] = 0.0629807;
  result["T1tttt_1100_800"]["40"] = 0.0668921;
  result["T1tttt_1100_800"]["41"] = 0.0599593;
  result["T1tttt_1100_800"]["42"] = 0.0809175;
  result["T1tttt_1100_800"]["43"] = 0.0691982;
  result["T1tttt_1100_800"]["44"] = 0.0558707;
  result["T1tttt_1100_800"]["45"] = 0.0538175;
  result["T1tttt_1100_800"]["46"] = 0.0568093;
  result["T1tttt_1100_800"]["47"] = 0.0509213;
  result["T1tttt_1100_800"]["48"] = 0.0533123;
  result["T1tttt_1100_800"]["49"] = 0.0674099;
  result["T1tttt_1100_800"]["50"] = 0.0754058;
  result["T1tttt_1100_800"]["51"] = 0.0545177;
  result["T1tttt_1100_800"]["52"] = 0.0633329;
  result["T1tttt_1100_800"]["53"] = 0.0727303;
  result["T1tttt_1100_800"]["54"] = 0.0575802;
  result["T1tttt_1100_800"]["55"] = 0.0771817;
  result["T1tttt_1100_800"]["56"] = 0.0826075;
  result["T1tttt_1100_800"]["57"] = 0.0556795;
  result["T1tttt_1100_800"]["58"] = 0.0765595;
  result["T1tttt_1100_800"]["59"] = 0.0516494;
  result["T1tttt_1100_800"]["60"] = 0.0801774;
  result["T1tttt_1100_800"]["61"] = 0.0697148;
  result["T1tttt_1100_800"]["62"] = 0.0556704;
  result["T1tttt_1100_800"]["63"] = 0.0734097;
  result["T1tttt_1100_800"]["64"] = 0.101205;
  result["T1tttt_1100_800"]["65"] = 0.0578392;
  result["T1tttt_1100_800"]["66"] = 0.102411;
  result["T1tttt_1100_800"]["67"] = 0.0567433;
  result["T1tttt_1100_800"]["68"] = 0.0612302;
  result["T1tttt_1100_800"]["69"] = 0.0715185;
  result["T1tttt_1100_800"]["70"] = 0.0585876;
  result["T1tttt_1100_800"]["71"] = 0.0715882;
  result["T1tttt_1100_800"]["72"] = 0.0622804;
  result["T1tttt_1100_800"]["73"] = 0.0789273;
  result["T1tttt_1100_800"]["74"] = 0.0634286;
  result["T1tttt_1100_800"]["75"] = 0.0656935;
  result["T1tttt_1100_800"]["76"] = 0.0720096;
  result["T1tttt_1100_800"]["77"] = 0.0953842;
  result["T1tttt_1100_800"]["78"] = 0.0629735;
  result["T1tttt_1100_800"]["79"] = 0.0699825;
  result["T1tttt_1100_800"]["80"] = 0.0516252;
  result["T1tttt_1100_800"]["81"] = 0.0709079;
  result["T1tttt_1100_800"]["82"] = 0.0861092;
  result["T1tttt_1100_800"]["83"] = 0.0762232;
  result["T1tttt_1100_800"]["84"] = 0.0535645;
  result["T1tttt_1100_800"]["85"] = 0.0718941;
  result["T1tttt_1100_800"]["86"] = 0.0768197;
  result["T1tttt_1100_800"]["87"] = 0.0742543;
  result["T1tttt_1100_800"]["88"] = 0.052164;
  result["T1tttt_1100_800"]["89"] = 0.062931;
  result["T1tttt_1100_800"]["90"] = 0.0679118;
  result["T1tttt_1100_800"]["91"] = 0.0631108;
  result["T1tttt_1100_800"]["92"] = 0.0709601;
  result["T1tttt_1100_800"]["93"] = 0.06005;
  result["T1tttt_1100_800"]["94"] = 0.0686745;
  result["T1tttt_1100_800"]["95"] = 0.073543;
  result["T1tttt_1100_800"]["96"] = 0.0641048;
  result["T1tttt_1100_800"]["97"] = 0.0904918;
  result["T1tttt_1100_800"]["98"] = 0.099562;
  result["T1tttt_1100_800"]["99"] = 0.0677263;
  result["T1tttt_1100_800"]["100"] = 0.0768258;
  result["T1tttt_1100_800"]["101"] = 0.0532315;
  result["T1tttt_1100_800"]["102"] = 0.0565003;
  result["T1tttt_1100_800"]["103"] = 0.0535995;
  result["T1tttt_1100_800"]["104"] = 0.086268;
  result["T1tttt_1100_800"]["105"] = 0.0560889;
  result["T1tttt_1100_800"]["106"] = 0.0708386;
  result["T1tttt_1100_800"]["107"] = 0.0570904;
  result["T1tttt_1100_800"]["108"] = 0.085882;
  result["T1tttt_1100_800"]["109"] = 0.0727341;
  result["T1tttt_1100_800"]["110"] = 0.0577895;
  result["T1tttt_1100_800"]["111"] = 0.0693153;
  result["T1tttt_1100_800"]["112"] = 0.0699919;
  result["T1tttt_1100_800"]["113"] = 0.0686939;
  result["T1tttt_1100_800"]["114"] = 0.0696153;
  result["T1tttt_1100_800"]["115"] = 0.0690136;
  result["T1tttt_1100_800"]["116"] = 0.0680179;
  result["T1tttt_1100_800"]["117"] = 0.0704488;
  result["T1tttt_1100_800"]["118"] = 0.0722012;
  result["T1tttt_1100_800"]["119"] = 0.0669312;
  result["T1tttt_1100_800"]["120"] = 0.0693598;
  result["T1tttt_1100_800"]["121"] = 0.0693457;
  result["T1tttt_1100_800"]["122"] = 0.0686815;
  result["T1tttt_1100_800"]["123"] = 0.0698008;
  result["T1tttt_1100_800"]["124"] = 0.0729869;
  result["T1tttt_1100_800"]["125"] = 0.064255;
  result["T1tttt_1100_800"]["126"] = 0.0697765;
  result["T1tttt_1100_800"]["127"] = 0.068992;
  result["T1tttt_1100_800"]["128"] = 0.0711428;
  result["T1tttt_1100_800"]["129"] = 0.0681476;
  result["T1tttt_1100_800"]["130"] = 0.0657183;
  result["T1tttt_1100_800"]["131"] = 0.0709881;
  result["T1tttt_1100_800"]["132"] = 0.0685142;
  result["T1tttt_1100_800"]["133"] = 0.0700112;
  result["T1tttt_1100_800"]["134"] = 0.0606331;
  result["T1tttt_1100_800"]["135"] = 0.0829857;
  result["T1tttt_1100_800"]["136"] = 0.0692257;
  result["T1tttt_1100_800"]["137"] = 0.0698906;
  result["T1tttt_1100_800"]["138"] = 0.0677786;
  result["T1tttt_1100_800"]["139"] = 0.070641;
  result["T1tttt_1100_800"]["140"] = 0.070485;
  result["T1tttt_1100_800"]["141"] = 0.0686583;
  result["T1tttt_1100_800"]["142"] = 0.068643;
  result["T1tttt_1100_800"]["143"] = 0.0702475;
  result["T1tttt_1100_800"]["144"] = 0.0675222;
  result["T1tttt_1100_800"]["145"] = 0.0734749;
  result["T1tttt_1100_800"]["146"] = 0.0687902;
  result["T1tttt_1100_800"]["147"] = 0.069401;
  result["T1tttt_1100_800"]["148"] = 0.069114;
  result["T1tttt_1100_800"]["149"] = 0.0699899;
  result["T1tttt_1100_800"]["150"] = 0.067377;
  result["T1tttt_1100_800"]["151"] = 0.0718721;
  result["T1tttt_1100_800"]["152"] = 0.0708007;
  result["T1tttt_1100_800"]["153"] = 0.0684459;
  result["T1tttt_1100_800"]["154"] = 0.0705765;
  result["T1tttt_1100_800"]["155"] = 0.0684836;
  result["T1tttt_1100_800"]["156"] = 0.0686336;
  result["T1tttt_1100_800"]["157"] = 0.0705627;
  result["T1tttt_1100_800"]["158"] = 0.0678057;
  result["T1tttt_1100_800"]["159"] = 0.0810146;
  result["T1tttt_1100_800"]["160"] = 0.0692177;
  result["T1tttt_1100_800"]["161"] = 0.0699244;
  result["T1tttt_1100_800"]["162"] = 0.0689539;
  result["T1tttt_1100_800"]["163"] = 0.0664808;
  result["T1tttt_1100_800"]["164"] = 0.0664442;
  result["T1tttt_1100_800"]["165"] = 0.0661177;
  result["T1tttt_1100_800"]["166"] = 0.0705428;
  result["T1tttt_1100_800"]["167"] = 0.0670132;
  result["T1tttt_1100_800"]["168"] = 0.067455;
  result["T1tttt_1100_800"]["169"] = 0.0670156;
  result["T1tttt_1100_800"]["170"] = 0.0672201;
  result["T1tttt_1100_800"]["171"] = 0.0640909;
  result["T1tttt_1100_800"]["172"] = 0.0670739;
  result["T1tttt_1100_800"]["173"] = 0.0698695;
  result["T1tttt_1100_800"]["174"] = 0.0677543;
  result["T1tttt_1100_800"]["175"] = 0.0684239;
  result["T1tttt_1100_800"]["176"] = 0.0653913;
  result["T1tttt_1100_800"]["177"] = 0.0730371;
  result["T1tttt_1100_800"]["178"] = 0.0739888;
  result["T1tttt_1100_800"]["179"] = 0.067618;
  result["T1tttt_1100_800"]["180"] = 0.0639653;
  result["T1tttt_1100_800"]["181"] = 0.0836449;
  result["T1tttt_1100_800"]["182"] = 0.0710818;
  result["T1tttt_1100_800"]["183"] = 0.0608126;
  result["T1tttt_1100_800"]["184"] = 0.0627317;
  result["T1tttt_1100_800"]["185"] = 0.0630469;
  result["T1tttt_1100_800"]["186"] = 0.0584488;
  result["T1tttt_1100_800"]["187"] = 0.0608644;
  result["T1tttt_1100_800"]["188"] = 0.0601395;
  result["T1tttt_1100_800"]["189"] = 0.0664307;
  result["T1tttt_1100_800"]["190"] = 0.0650938;
  result["T1tttt_1100_800"]["191"] = 0.0818273;
  result["T1tttt_1100_800"]["192"] = 0.0726049;
  result["T1tttt_1100_800"]["193"] = 0.0683109;
  result["T1tttt_1100_800"]["194"] = 0.0595633;
  result["T1tttt_1100_800"]["195"] = 0.0635195;
  result["T1tttt_1100_800"]["196"] = 0.0667586;
  result["T1tttt_1100_800"]["197"] = 0.0641301;
  result["T1tttt_1100_800"]["198"] = 0.0561708;
  result["T1tttt_1100_800"]["199"] = 0.0733945;
  result["T1tttt_1100_800"]["200"] = 0.0635212;
  result["T1tttt_1100_800"]["201"] = 0.0703185;
  result["T1tttt_1100_800"]["202"] = 0.0607549;
  result["T1tttt_1100_800"]["203"] = 0.063432;
  result["T1tttt_1100_800"]["204"] = 0.0633675;
  result["T1tttt_1100_800"]["205"] = 0.0598786;
  result["T1tttt_1100_800"]["206"] = 0.0654736;
  result["T1tttt_1100_800"]["207"] = 0.0605369;
  result["T1tttt_1100_800"]["208"] = 0.0639059;
  result["T1tttt_1100_800"]["209"] = 0.0590006;
  result["T1tttt_1100_800"]["210"] = 0.0524372;
  result["T1tttt_1100_800"]["211"] = 0.0713052;
  result["T1tttt_1100_800"]["212"] = 0.0703673;
  result["T1tttt_1100_800"]["213"] = 0.066925;
  result["T1tttt_1100_800"]["214"] = 0.0653566;
  result["T1tttt_1100_800"]["215"] = 0.0636368;
  result["T1tttt_1100_800"]["216"] = 0.0687653;
  result["T1tttt_1100_800"]["217"] = 0.0605858;
  result["T1tttt_1100_800"]["218"] = 0.0743144;
  result["T1tttt_1100_800"]["219"] = 0.0660719;
  result["T1tttt_1100_800"]["220"] = 0.0733119;
  result["T1tttt_1100_800"]["221"] = 0.0633633;
  result["T1tttt_1100_800"]["222"] = 0.0666916;
  result["T1tttt_1100_800"]["223"] = 0.0633078;
  result["T1tttt_1100_800"]["224"] = 0.0620792;
  result["T1tttt_1100_800"]["225"] = 0.0605984;
  result["T1tttt_1100_800"]["226"] = 0.0612535;
  result["T1tttt_1100_800"]["227"] = 0.0706009;
  result["T1tttt_1100_800"]["228"] = 0.0732213;
  result["T1tttt_1100_800"]["229"] = 0.0720073;
  result["T1tttt_1100_800"]["230"] = 0.063776;
  result["T1tttt_1100_800"]["231"] = 0.0618031;
  result["T1tttt_1100_800"]["232"] = 0.0674948;
  result["T1tttt_1100_800"]["233"] = 0.0745308;
  result["T1tttt_1100_800"]["234"] = 0.0737315;
  result["T1tttt_1100_800"]["235"] = 0.0590153;
  result["T1tttt_1100_800"]["236"] = 0.063969;
  result["T1tttt_1100_800"]["237"] = 0.0743862;
  result["T1tttt_1100_800"]["238"] = 0.0700542;
  result["T1tttt_1100_800"]["239"] = 0.068864;
  result["T1tttt_1100_800"]["240"] = 0.0598178;
  result["T1tttt_1100_800"]["241"] = 0.0620126;
  result["T1tttt_1100_800"]["242"] = 0.0691131;
  result["T1tttt_1100_800"]["243"] = 0.0640377;
  result["T1tttt_1100_800"]["244"] = 0.0646944;
  result["T1tttt_1100_800"]["245"] = 0.0610327;
  result["T1tttt_1100_800"]["246"] = 0.0667358;
  result["T1tttt_1100_800"]["247"] = 0.0667762;
  result["T1tttt_1100_800"]["248"] = 0.0652863;
  result["T1tttt_1100_800"]["249"] = 0.0704901;
  result["T1tttt_1100_800"]["250"] = 0.0710589;
  result["T1tttt_1100_800"]["251"] = 0.0715572;
  result["T1tttt_1100_800"]["252"] = 0.0701237;
  result["T1tttt_1100_800"]["253"] = 0.0675406;
  result["T1tttt_1100_800"]["254"] = 0.0688548;
  result["T1tttt_1100_800"]["255"] = 0.0682407;
  result["T1tttt_1100_800"]["256"] = 0.0622509;
  result["T1tttt_1100_800"]["257"] = 0.0692438;
  result["T1tttt_1100_800"]["258"] = 0.0600604;
  result["T1tttt_1100_800"]["259"] = 0.0786687;
  result["T1tttt_1100_800"]["260"] = 0.0662256;
  result["T1tttt_1100_800"]["261"] = 0.0681674;
  result["T1tttt_1100_800"]["262"] = 0.0578762;
  result["T1tttt_1100_800"]["263"] = 0.0690183;
  result["T1tttt_1100_800"]["264"] = 0.0741176;
  result["T1tttt_1100_800"]["265"] = 0.0652529;
  result["T1tttt_1100_800"]["266"] = 0.0652476;
  result["T1tttt_1100_800"]["267"] = 0.0652571;
  result["T1tttt_1100_800"]["268"] = 0.0653412;
  result["T1tttt_1100_800"]["269"] = 0.0651895;
  result["T1tttt_1100_800"]["270"] = 0.0655408;
  result["T1tttt_1100_800"]["271"] = 0.0649748;
  result["T1tttt_1100_800"]["272"] = 0.0654202;
  result["T1tttt_1100_800"]["273"] = 0.065049;
  result["T1tttt_1100_800"]["274"] = 0.0649687;
  result["T1tttt_1100_800"]["275"] = 0.0656069;
  result["T1tttt_1100_800"]["276"] = 0.0650815;
  result["T1tttt_1100_800"]["277"] = 0.0655959;
  result["T1tttt_1100_800"]["278"] = 0.0652674;
  result["T1tttt_1100_800"]["279"] = 0.0652309;
  result["T1tttt_1100_800"]["280"] = 0.0655712;
  result["T1tttt_1100_800"]["281"] = 0.0650344;
  result["T1tttt_1100_800"]["282"] = 0.0651518;
  result["T1tttt_1100_800"]["283"] = 0.0653644;
  result["T1tttt_1100_800"]["284"] = 0.0649346;
  result["T1tttt_1100_800"]["285"] = 0.0654958;
  result["T1tttt_1100_800"]["286"] = 0.0649687;
  result["T1tttt_1100_800"]["287"] = 0.0655448;
  result["T1tttt_1100_800"]["288"] = 0.0649216;
  result["T1tttt_1100_800"]["289"] = 0.0655416;
  result["T1tttt_1100_800"]["290"] = 0.0643267;
  result["T1tttt_1100_800"]["291"] = 0.0664174;
  result["T1tttt_1100_800"]["292"] = 0.0647924;
  result["T1tttt_1100_800"]["293"] = 0.0654145;
  result["T1tttt_1100_800"]["294"] = 0.0633355;
  result["T1tttt_1100_800"]["295"] = 0.0676277;
  result["T1tttt_1100_800"]["296"] = 0.0635986;
  result["T1tttt_1100_800"]["297"] = 0.0668095;
  result["T1tttt_1100_800"]["298"] = 0.0651354;
  result["T1tttt_1100_800"]["299"] = 0.0654496;
  result["T1tttt_1100_800"]["300"] = 0.0654652;
  result["T1tttt_1100_800"]["301"] = 0.0647525;
  result["T1tttt_1100_800"]["302"] = 0.0648849;
  result["T1tttt_1100_800"]["303"] = 0.0653286;
  result["T1tttt_1100_800"]["304"] = 0.0647095;
  result["T1tttt_1100_800"]["305"] = 0.0657164;
  result["T1tttt_1100_800"]["306"] = 0.0642419;
  result["T1tttt_1100_800"]["307"] = 0.0665914;
  result["T1tttt_1100_800"]["308"] = 0.0651581;
  result["T1tttt_1100_800"]["309"] = 0.0652718;
  result["T1tttt_1100_800"]["310"] = 0.0650287;
  result["T1tttt_1100_800"]["311"] = 0.0658844;
  result["T1tttt_1100_800"]["312"] = 0.0642397;
  result["T1tttt_1100_800"]["313"] = 0.0676639;
  result["T1tttt_1100_800"]["314"] = 0.0649209;
  result["T1tttt_1100_800"]["315"] = 0.0656505;
  result["T1tttt_1300_0"]["1"] = 0.010625;
  result["T1tttt_1300_0"]["2"] = 0.00919114;
  result["T1tttt_1300_0"]["3"] = 0.0124562;
  result["T1tttt_1300_0"]["4"] = 0.00917065;
  result["T1tttt_1300_0"]["5"] = 0.00793287;
  result["T1tttt_1300_0"]["6"] = 0.0107511;
  result["T1tttt_1300_0"]["7"] = 0.0124555;
  result["T1tttt_1300_0"]["8"] = 0.0107745;
  result["T1tttt_1300_0"]["9"] = 0.0146017;
  result["T1tttt_1300_0"]["10"] = 0.010625;
  result["T1tttt_1300_0"]["11"] = 0.00917985;
  result["T1tttt_1300_0"]["12"] = 0.00680812;
  result["T1tttt_1300_0"]["13"] = 0.00999189;
  result["T1tttt_1300_0"]["14"] = 0.0108467;
  result["T1tttt_1300_0"]["15"] = 0.00905316;
  result["T1tttt_1300_0"]["16"] = 0.00792578;
  result["T1tttt_1300_0"]["17"] = 0.0134299;
  result["T1tttt_1300_0"]["18"] = 0.00882586;
  result["T1tttt_1300_0"]["19"] = 0.0120472;
  result["T1tttt_1300_0"]["20"] = 0.0064274;
  result["T1tttt_1300_0"]["21"] = 0.00787136;
  result["T1tttt_1300_0"]["22"] = 0.00816159;
  result["T1tttt_1300_0"]["23"] = 0.0108767;
  result["T1tttt_1300_0"]["24"] = 0.0124571;
  result["T1tttt_1300_0"]["25"] = 0.0100728;
  result["T1tttt_1300_0"]["26"] = 0.00817851;
  result["T1tttt_1300_0"]["27"] = 0.0133799;
  result["T1tttt_1300_0"]["28"] = 0.0136137;
  result["T1tttt_1300_0"]["29"] = 0.0109121;
  result["T1tttt_1300_0"]["30"] = 0.0104876;
  result["T1tttt_1300_0"]["31"] = 0.0121385;
  result["T1tttt_1300_0"]["32"] = 0.00915454;
  result["T1tttt_1300_0"]["33"] = 0.0102466;
  result["T1tttt_1300_0"]["34"] = 0.00827087;
  result["T1tttt_1300_0"]["35"] = 0.0132997;
  result["T1tttt_1300_0"]["36"] = 0.0135444;
  result["T1tttt_1300_0"]["37"] = 0.0140092;
  result["T1tttt_1300_0"]["38"] = 0.0109771;
  result["T1tttt_1300_0"]["39"] = 0.00984157;
  result["T1tttt_1300_0"]["40"] = 0.0106776;
  result["T1tttt_1300_0"]["41"] = 0.0093341;
  result["T1tttt_1300_0"]["42"] = 0.0133966;
  result["T1tttt_1300_0"]["43"] = 0.0109283;
  result["T1tttt_1300_0"]["44"] = 0.00905264;
  result["T1tttt_1300_0"]["45"] = 0.00853615;
  result["T1tttt_1300_0"]["46"] = 0.00904638;
  result["T1tttt_1300_0"]["47"] = 0.00780641;
  result["T1tttt_1300_0"]["48"] = 0.00842242;
  result["T1tttt_1300_0"]["49"] = 0.0107096;
  result["T1tttt_1300_0"]["50"] = 0.0124159;
  result["T1tttt_1300_0"]["51"] = 0.00866309;
  result["T1tttt_1300_0"]["52"] = 0.00993486;
  result["T1tttt_1300_0"]["53"] = 0.0115363;
  result["T1tttt_1300_0"]["54"] = 0.00899012;
  result["T1tttt_1300_0"]["55"] = 0.0124843;
  result["T1tttt_1300_0"]["56"] = 0.0129078;
  result["T1tttt_1300_0"]["57"] = 0.00911307;
  result["T1tttt_1300_0"]["58"] = 0.0124464;
  result["T1tttt_1300_0"]["59"] = 0.00857268;
  result["T1tttt_1300_0"]["60"] = 0.0125841;
  result["T1tttt_1300_0"]["61"] = 0.0112483;
  result["T1tttt_1300_0"]["62"] = 0.00932333;
  result["T1tttt_1300_0"]["63"] = 0.011896;
  result["T1tttt_1300_0"]["64"] = 0.0162001;
  result["T1tttt_1300_0"]["65"] = 0.0089167;
  result["T1tttt_1300_0"]["66"] = 0.0169078;
  result["T1tttt_1300_0"]["67"] = 0.0091743;
  result["T1tttt_1300_0"]["68"] = 0.00954332;
  result["T1tttt_1300_0"]["69"] = 0.0113376;
  result["T1tttt_1300_0"]["70"] = 0.00899338;
  result["T1tttt_1300_0"]["71"] = 0.0115853;
  result["T1tttt_1300_0"]["72"] = 0.00998262;
  result["T1tttt_1300_0"]["73"] = 0.0125859;
  result["T1tttt_1300_0"]["74"] = 0.0101279;
  result["T1tttt_1300_0"]["75"] = 0.0103998;
  result["T1tttt_1300_0"]["76"] = 0.0117269;
  result["T1tttt_1300_0"]["77"] = 0.0156405;
  result["T1tttt_1300_0"]["78"] = 0.00985109;
  result["T1tttt_1300_0"]["79"] = 0.0115029;
  result["T1tttt_1300_0"]["80"] = 0.00774769;
  result["T1tttt_1300_0"]["81"] = 0.0114673;
  result["T1tttt_1300_0"]["82"] = 0.0140722;
  result["T1tttt_1300_0"]["83"] = 0.0124336;
  result["T1tttt_1300_0"]["84"] = 0.00818096;
  result["T1tttt_1300_0"]["85"] = 0.0114379;
  result["T1tttt_1300_0"]["86"] = 0.0122505;
  result["T1tttt_1300_0"]["87"] = 0.0116868;
  result["T1tttt_1300_0"]["88"] = 0.00845759;
  result["T1tttt_1300_0"]["89"] = 0.00993068;
  result["T1tttt_1300_0"]["90"] = 0.0111402;
  result["T1tttt_1300_0"]["91"] = 0.0100631;
  result["T1tttt_1300_0"]["92"] = 0.0109716;
  result["T1tttt_1300_0"]["93"] = 0.00940282;
  result["T1tttt_1300_0"]["94"] = 0.0110809;
  result["T1tttt_1300_0"]["95"] = 0.0119386;
  result["T1tttt_1300_0"]["96"] = 0.00989712;
  result["T1tttt_1300_0"]["97"] = 0.0144427;
  result["T1tttt_1300_0"]["98"] = 0.0162988;
  result["T1tttt_1300_0"]["99"] = 0.0107432;
  result["T1tttt_1300_0"]["100"] = 0.0127417;
  result["T1tttt_1300_0"]["101"] = 0.00836078;
  result["T1tttt_1300_0"]["102"] = 0.00901827;
  result["T1tttt_1300_0"]["103"] = 0.00831559;
  result["T1tttt_1300_0"]["104"] = 0.0143908;
  result["T1tttt_1300_0"]["105"] = 0.00865568;
  result["T1tttt_1300_0"]["106"] = 0.0113434;
  result["T1tttt_1300_0"]["107"] = 0.00894012;
  result["T1tttt_1300_0"]["108"] = 0.0141993;
  result["T1tttt_1300_0"]["109"] = 0.0116057;
  result["T1tttt_1300_0"]["110"] = 0.00913775;
  result["T1tttt_1300_0"]["111"] = 0.0111369;
  result["T1tttt_1300_0"]["112"] = 0.0112498;
  result["T1tttt_1300_0"]["113"] = 0.011033;
  result["T1tttt_1300_0"]["114"] = 0.0111895;
  result["T1tttt_1300_0"]["115"] = 0.0110839;
  result["T1tttt_1300_0"]["116"] = 0.0109048;
  result["T1tttt_1300_0"]["117"] = 0.0113402;
  result["T1tttt_1300_0"]["118"] = 0.0115907;
  result["T1tttt_1300_0"]["119"] = 0.0107671;
  result["T1tttt_1300_0"]["120"] = 0.0111462;
  result["T1tttt_1300_0"]["121"] = 0.0111422;
  result["T1tttt_1300_0"]["122"] = 0.010974;
  result["T1tttt_1300_0"]["123"] = 0.011259;
  result["T1tttt_1300_0"]["124"] = 0.0117929;
  result["T1tttt_1300_0"]["125"] = 0.0102472;
  result["T1tttt_1300_0"]["126"] = 0.0112479;
  result["T1tttt_1300_0"]["127"] = 0.0110531;
  result["T1tttt_1300_0"]["128"] = 0.0114636;
  result["T1tttt_1300_0"]["129"] = 0.0109303;
  result["T1tttt_1300_0"]["130"] = 0.010504;
  result["T1tttt_1300_0"]["131"] = 0.0114317;
  result["T1tttt_1300_0"]["132"] = 0.0111134;
  result["T1tttt_1300_0"]["133"] = 0.011163;
  result["T1tttt_1300_0"]["134"] = 0.00955306;
  result["T1tttt_1300_0"]["135"] = 0.0138224;
  result["T1tttt_1300_0"]["136"] = 0.0111364;
  result["T1tttt_1300_0"]["137"] = 0.011226;
  result["T1tttt_1300_0"]["138"] = 0.0108409;
  result["T1tttt_1300_0"]["139"] = 0.0113879;
  result["T1tttt_1300_0"]["140"] = 0.0113604;
  result["T1tttt_1300_0"]["141"] = 0.0110174;
  result["T1tttt_1300_0"]["142"] = 0.0110968;
  result["T1tttt_1300_0"]["143"] = 0.0112393;
  result["T1tttt_1300_0"]["144"] = 0.0106381;
  result["T1tttt_1300_0"]["145"] = 0.0121097;
  result["T1tttt_1300_0"]["146"] = 0.0108545;
  result["T1tttt_1300_0"]["147"] = 0.0113324;
  result["T1tttt_1300_0"]["148"] = 0.0110796;
  result["T1tttt_1300_0"]["149"] = 0.011309;
  result["T1tttt_1300_0"]["150"] = 0.0107828;
  result["T1tttt_1300_0"]["151"] = 0.0117024;
  result["T1tttt_1300_0"]["152"] = 0.0114096;
  result["T1tttt_1300_0"]["153"] = 0.010981;
  result["T1tttt_1300_0"]["154"] = 0.0113865;
  result["T1tttt_1300_0"]["155"] = 0.0109876;
  result["T1tttt_1300_0"]["156"] = 0.0110091;
  result["T1tttt_1300_0"]["157"] = 0.0113961;
  result["T1tttt_1300_0"]["158"] = 0.0107974;
  result["T1tttt_1300_0"]["159"] = 0.0139621;
  result["T1tttt_1300_0"]["160"] = 0.0111257;
  result["T1tttt_1300_0"]["161"] = 0.0112658;
  result["T1tttt_1300_0"]["162"] = 0.0110745;
  result["T1tttt_1300_0"]["163"] = 0.0106224;
  result["T1tttt_1300_0"]["164"] = 0.0103058;
  result["T1tttt_1300_0"]["165"] = 0.0102749;
  result["T1tttt_1300_0"]["166"] = 0.0111692;
  result["T1tttt_1300_0"]["167"] = 0.0103238;
  result["T1tttt_1300_0"]["168"] = 0.0106739;
  result["T1tttt_1300_0"]["169"] = 0.0104102;
  result["T1tttt_1300_0"]["170"] = 0.0104473;
  result["T1tttt_1300_0"]["171"] = 0.00996298;
  result["T1tttt_1300_0"]["172"] = 0.0101389;
  result["T1tttt_1300_0"]["173"] = 0.0112875;
  result["T1tttt_1300_0"]["174"] = 0.0105366;
  result["T1tttt_1300_0"]["175"] = 0.0104468;
  result["T1tttt_1300_0"]["176"] = 0.0101493;
  result["T1tttt_1300_0"]["177"] = 0.0116978;
  result["T1tttt_1300_0"]["178"] = 0.0116774;
  result["T1tttt_1300_0"]["179"] = 0.0104664;
  result["T1tttt_1300_0"]["180"] = 0.00986031;
  result["T1tttt_1300_0"]["181"] = 0.0136093;
  result["T1tttt_1300_0"]["182"] = 0.0112197;
  result["T1tttt_1300_0"]["183"] = 0.00916827;
  result["T1tttt_1300_0"]["184"] = 0.00971347;
  result["T1tttt_1300_0"]["185"] = 0.00969576;
  result["T1tttt_1300_0"]["186"] = 0.00892088;
  result["T1tttt_1300_0"]["187"] = 0.00938521;
  result["T1tttt_1300_0"]["188"] = 0.00911201;
  result["T1tttt_1300_0"]["189"] = 0.0104451;
  result["T1tttt_1300_0"]["190"] = 0.010163;
  result["T1tttt_1300_0"]["191"] = 0.01315;
  result["T1tttt_1300_0"]["192"] = 0.0114808;
  result["T1tttt_1300_0"]["193"] = 0.0104479;
  result["T1tttt_1300_0"]["194"] = 0.00886191;
  result["T1tttt_1300_0"]["195"] = 0.00977831;
  result["T1tttt_1300_0"]["196"] = 0.0103791;
  result["T1tttt_1300_0"]["197"] = 0.00989127;
  result["T1tttt_1300_0"]["198"] = 0.00829197;
  result["T1tttt_1300_0"]["199"] = 0.0115482;
  result["T1tttt_1300_0"]["200"] = 0.00988083;
  result["T1tttt_1300_0"]["201"] = 0.0110143;
  result["T1tttt_1300_0"]["202"] = 0.00914388;
  result["T1tttt_1300_0"]["203"] = 0.00949947;
  result["T1tttt_1300_0"]["204"] = 0.00978164;
  result["T1tttt_1300_0"]["205"] = 0.00910464;
  result["T1tttt_1300_0"]["206"] = 0.0100719;
  result["T1tttt_1300_0"]["207"] = 0.00914956;
  result["T1tttt_1300_0"]["208"] = 0.00979032;
  result["T1tttt_1300_0"]["209"] = 0.00878692;
  result["T1tttt_1300_0"]["210"] = 0.00748141;
  result["T1tttt_1300_0"]["211"] = 0.0112379;
  result["T1tttt_1300_0"]["212"] = 0.0110316;
  result["T1tttt_1300_0"]["213"] = 0.0102238;
  result["T1tttt_1300_0"]["214"] = 0.0100776;
  result["T1tttt_1300_0"]["215"] = 0.00960272;
  result["T1tttt_1300_0"]["216"] = 0.0110678;
  result["T1tttt_1300_0"]["217"] = 0.0092431;
  result["T1tttt_1300_0"]["218"] = 0.0118516;
  result["T1tttt_1300_0"]["219"] = 0.0101646;
  result["T1tttt_1300_0"]["220"] = 0.0115641;
  result["T1tttt_1300_0"]["221"] = 0.00984774;
  result["T1tttt_1300_0"]["222"] = 0.0103019;
  result["T1tttt_1300_0"]["223"] = 0.009615;
  result["T1tttt_1300_0"]["224"] = 0.00949352;
  result["T1tttt_1300_0"]["225"] = 0.00892783;
  result["T1tttt_1300_0"]["226"] = 0.00926025;
  result["T1tttt_1300_0"]["227"] = 0.0112335;
  result["T1tttt_1300_0"]["228"] = 0.0114689;
  result["T1tttt_1300_0"]["229"] = 0.0114053;
  result["T1tttt_1300_0"]["230"] = 0.0097968;
  result["T1tttt_1300_0"]["231"] = 0.00933297;
  result["T1tttt_1300_0"]["232"] = 0.0104158;
  result["T1tttt_1300_0"]["233"] = 0.0118118;
  result["T1tttt_1300_0"]["234"] = 0.0117041;
  result["T1tttt_1300_0"]["235"] = 0.00903469;
  result["T1tttt_1300_0"]["236"] = 0.00988907;
  result["T1tttt_1300_0"]["237"] = 0.0118554;
  result["T1tttt_1300_0"]["238"] = 0.0110888;
  result["T1tttt_1300_0"]["239"] = 0.0110876;
  result["T1tttt_1300_0"]["240"] = 0.00901827;
  result["T1tttt_1300_0"]["241"] = 0.00944639;
  result["T1tttt_1300_0"]["242"] = 0.010732;
  result["T1tttt_1300_0"]["243"] = 0.00969141;
  result["T1tttt_1300_0"]["244"] = 0.00994417;
  result["T1tttt_1300_0"]["245"] = 0.00928111;
  result["T1tttt_1300_0"]["246"] = 0.0104822;
  result["T1tttt_1300_0"]["247"] = 0.0102607;
  result["T1tttt_1300_0"]["248"] = 0.0101121;
  result["T1tttt_1300_0"]["249"] = 0.0110838;
  result["T1tttt_1300_0"]["250"] = 0.0111961;
  result["T1tttt_1300_0"]["251"] = 0.0114736;
  result["T1tttt_1300_0"]["252"] = 0.0110075;
  result["T1tttt_1300_0"]["253"] = 0.0106367;
  result["T1tttt_1300_0"]["254"] = 0.0108827;
  result["T1tttt_1300_0"]["255"] = 0.0107697;
  result["T1tttt_1300_0"]["256"] = 0.00954346;
  result["T1tttt_1300_0"]["257"] = 0.01085;
  result["T1tttt_1300_0"]["258"] = 0.00873493;
  result["T1tttt_1300_0"]["259"] = 0.0127197;
  result["T1tttt_1300_0"]["260"] = 0.0103229;
  result["T1tttt_1300_0"]["261"] = 0.0105996;
  result["T1tttt_1300_0"]["262"] = 0.00882892;
  result["T1tttt_1300_0"]["263"] = 0.0108199;
  result["T1tttt_1300_0"]["264"] = 0.0118066;
  result["T1tttt_1300_0"]["265"] = 0.0100935;
  result["T1tttt_1300_0"]["266"] = 0.0100936;
  result["T1tttt_1300_0"]["267"] = 0.010093;
  result["T1tttt_1300_0"]["268"] = 0.0101076;
  result["T1tttt_1300_0"]["269"] = 0.0100831;
  result["T1tttt_1300_0"]["270"] = 0.0101386;
  result["T1tttt_1300_0"]["271"] = 0.0100498;
  result["T1tttt_1300_0"]["272"] = 0.0101253;
  result["T1tttt_1300_0"]["273"] = 0.010054;
  result["T1tttt_1300_0"]["274"] = 0.0100446;
  result["T1tttt_1300_0"]["275"] = 0.0101544;
  result["T1tttt_1300_0"]["276"] = 0.0100632;
  result["T1tttt_1300_0"]["277"] = 0.0101535;
  result["T1tttt_1300_0"]["278"] = 0.0100948;
  result["T1tttt_1300_0"]["279"] = 0.0100914;
  result["T1tttt_1300_0"]["280"] = 0.010149;
  result["T1tttt_1300_0"]["281"] = 0.0100555;
  result["T1tttt_1300_0"]["282"] = 0.0100729;
  result["T1tttt_1300_0"]["283"] = 0.0101162;
  result["T1tttt_1300_0"]["284"] = 0.0100434;
  result["T1tttt_1300_0"]["285"] = 0.0101313;
  result["T1tttt_1300_0"]["286"] = 0.0100368;
  result["T1tttt_1300_0"]["287"] = 0.0101514;
  result["T1tttt_1300_0"]["288"] = 0.0100402;
  result["T1tttt_1300_0"]["289"] = 0.0101391;
  result["T1tttt_1300_0"]["290"] = 0.00994772;
  result["T1tttt_1300_0"]["291"] = 0.0102771;
  result["T1tttt_1300_0"]["292"] = 0.0100082;
  result["T1tttt_1300_0"]["293"] = 0.0101335;
  result["T1tttt_1300_0"]["294"] = 0.00974916;
  result["T1tttt_1300_0"]["295"] = 0.0105215;
  result["T1tttt_1300_0"]["296"] = 0.00983911;
  result["T1tttt_1300_0"]["297"] = 0.0103437;
  result["T1tttt_1300_0"]["298"] = 0.0100621;
  result["T1tttt_1300_0"]["299"] = 0.0101428;
  result["T1tttt_1300_0"]["300"] = 0.0101205;
  result["T1tttt_1300_0"]["301"] = 0.0100335;
  result["T1tttt_1300_0"]["302"] = 0.010022;
  result["T1tttt_1300_0"]["303"] = 0.0101074;
  result["T1tttt_1300_0"]["304"] = 0.00999142;
  result["T1tttt_1300_0"]["305"] = 0.0101762;
  result["T1tttt_1300_0"]["306"] = 0.0099391;
  result["T1tttt_1300_0"]["307"] = 0.0102979;
  result["T1tttt_1300_0"]["308"] = 0.010101;
  result["T1tttt_1300_0"]["309"] = 0.0100735;
  result["T1tttt_1300_0"]["310"] = 0.0100575;
  result["T1tttt_1300_0"]["311"] = 0.0101936;
  result["T1tttt_1300_0"]["312"] = 0.00990333;
  result["T1tttt_1300_0"]["313"] = 0.0105377;
  result["T1tttt_1300_0"]["314"] = 0.0100329;
  result["T1tttt_1300_0"]["315"] = 0.0101804;
  result["T1tttt_1300_1000"]["1"] = 0.0178741;
  result["T1tttt_1300_1000"]["2"] = 0.0154609;
  result["T1tttt_1300_1000"]["3"] = 0.0209544;
  result["T1tttt_1300_1000"]["4"] = 0.0154265;
  result["T1tttt_1300_1000"]["5"] = 0.0133441;
  result["T1tttt_1300_1000"]["6"] = 0.0180858;
  result["T1tttt_1300_1000"]["7"] = 0.0209531;
  result["T1tttt_1300_1000"]["8"] = 0.0181248;
  result["T1tttt_1300_1000"]["9"] = 0.0245645;
  result["T1tttt_1300_1000"]["10"] = 0.0178741;
  result["T1tttt_1300_1000"]["11"] = 0.0153998;
  result["T1tttt_1300_1000"]["12"] = 0.0113758;
  result["T1tttt_1300_1000"]["13"] = 0.0168109;
  result["T1tttt_1300_1000"]["14"] = 0.0184988;
  result["T1tttt_1300_1000"]["15"] = 0.0153279;
  result["T1tttt_1300_1000"]["16"] = 0.013369;
  result["T1tttt_1300_1000"]["17"] = 0.0224871;
  result["T1tttt_1300_1000"]["18"] = 0.0148745;
  result["T1tttt_1300_1000"]["19"] = 0.0202014;
  result["T1tttt_1300_1000"]["20"] = 0.0108018;
  result["T1tttt_1300_1000"]["21"] = 0.0132599;
  result["T1tttt_1300_1000"]["22"] = 0.0137143;
  result["T1tttt_1300_1000"]["23"] = 0.018448;
  result["T1tttt_1300_1000"]["24"] = 0.021038;
  result["T1tttt_1300_1000"]["25"] = 0.0170419;
  result["T1tttt_1300_1000"]["26"] = 0.0137128;
  result["T1tttt_1300_1000"]["27"] = 0.0222993;
  result["T1tttt_1300_1000"]["28"] = 0.022875;
  result["T1tttt_1300_1000"]["29"] = 0.0184499;
  result["T1tttt_1300_1000"]["30"] = 0.0176188;
  result["T1tttt_1300_1000"]["31"] = 0.0203879;
  result["T1tttt_1300_1000"]["32"] = 0.0154148;
  result["T1tttt_1300_1000"]["33"] = 0.0171832;
  result["T1tttt_1300_1000"]["34"] = 0.0139145;
  result["T1tttt_1300_1000"]["35"] = 0.0223088;
  result["T1tttt_1300_1000"]["36"] = 0.0228386;
  result["T1tttt_1300_1000"]["37"] = 0.0236465;
  result["T1tttt_1300_1000"]["38"] = 0.018548;
  result["T1tttt_1300_1000"]["39"] = 0.0166603;
  result["T1tttt_1300_1000"]["40"] = 0.0179725;
  result["T1tttt_1300_1000"]["41"] = 0.0157649;
  result["T1tttt_1300_1000"]["42"] = 0.0222776;
  result["T1tttt_1300_1000"]["43"] = 0.0183424;
  result["T1tttt_1300_1000"]["44"] = 0.0152802;
  result["T1tttt_1300_1000"]["45"] = 0.0144106;
  result["T1tttt_1300_1000"]["46"] = 0.0152225;
  result["T1tttt_1300_1000"]["47"] = 0.0131372;
  result["T1tttt_1300_1000"]["48"] = 0.0142373;
  result["T1tttt_1300_1000"]["49"] = 0.0178332;
  result["T1tttt_1300_1000"]["50"] = 0.0209208;
  result["T1tttt_1300_1000"]["51"] = 0.014516;
  result["T1tttt_1300_1000"]["52"] = 0.0167952;
  result["T1tttt_1300_1000"]["53"] = 0.0193699;
  result["T1tttt_1300_1000"]["54"] = 0.0151919;
  result["T1tttt_1300_1000"]["55"] = 0.0209342;
  result["T1tttt_1300_1000"]["56"] = 0.021816;
  result["T1tttt_1300_1000"]["57"] = 0.015303;
  result["T1tttt_1300_1000"]["58"] = 0.0210199;
  result["T1tttt_1300_1000"]["59"] = 0.014451;
  result["T1tttt_1300_1000"]["60"] = 0.0212047;
  result["T1tttt_1300_1000"]["61"] = 0.0189305;
  result["T1tttt_1300_1000"]["62"] = 0.0155838;
  result["T1tttt_1300_1000"]["63"] = 0.0199617;
  result["T1tttt_1300_1000"]["64"] = 0.0271431;
  result["T1tttt_1300_1000"]["65"] = 0.0150764;
  result["T1tttt_1300_1000"]["66"] = 0.0284082;
  result["T1tttt_1300_1000"]["67"] = 0.0154723;
  result["T1tttt_1300_1000"]["68"] = 0.0160882;
  result["T1tttt_1300_1000"]["69"] = 0.0190063;
  result["T1tttt_1300_1000"]["70"] = 0.0150757;
  result["T1tttt_1300_1000"]["71"] = 0.0194493;
  result["T1tttt_1300_1000"]["72"] = 0.0168878;
  result["T1tttt_1300_1000"]["73"] = 0.0211841;
  result["T1tttt_1300_1000"]["74"] = 0.0171338;
  result["T1tttt_1300_1000"]["75"] = 0.0176445;
  result["T1tttt_1300_1000"]["76"] = 0.0195395;
  result["T1tttt_1300_1000"]["77"] = 0.0262993;
  result["T1tttt_1300_1000"]["78"] = 0.0166586;
  result["T1tttt_1300_1000"]["79"] = 0.0193346;
  result["T1tttt_1300_1000"]["80"] = 0.0130077;
  result["T1tttt_1300_1000"]["81"] = 0.0191975;
  result["T1tttt_1300_1000"]["82"] = 0.0236206;
  result["T1tttt_1300_1000"]["83"] = 0.020951;
  result["T1tttt_1300_1000"]["84"] = 0.0137834;
  result["T1tttt_1300_1000"]["85"] = 0.0192159;
  result["T1tttt_1300_1000"]["86"] = 0.0207031;
  result["T1tttt_1300_1000"]["87"] = 0.0198571;
  result["T1tttt_1300_1000"]["88"] = 0.0142293;
  result["T1tttt_1300_1000"]["89"] = 0.0166115;
  result["T1tttt_1300_1000"]["90"] = 0.0187208;
  result["T1tttt_1300_1000"]["91"] = 0.0170262;
  result["T1tttt_1300_1000"]["92"] = 0.0186266;
  result["T1tttt_1300_1000"]["93"] = 0.0159356;
  result["T1tttt_1300_1000"]["94"] = 0.0186601;
  result["T1tttt_1300_1000"]["95"] = 0.0200432;
  result["T1tttt_1300_1000"]["96"] = 0.0167078;
  result["T1tttt_1300_1000"]["97"] = 0.0243859;
  result["T1tttt_1300_1000"]["98"] = 0.0274313;
  result["T1tttt_1300_1000"]["99"] = 0.0180642;
  result["T1tttt_1300_1000"]["100"] = 0.0214253;
  result["T1tttt_1300_1000"]["101"] = 0.0140452;
  result["T1tttt_1300_1000"]["102"] = 0.0151877;
  result["T1tttt_1300_1000"]["103"] = 0.0139886;
  result["T1tttt_1300_1000"]["104"] = 0.0240381;
  result["T1tttt_1300_1000"]["105"] = 0.0146554;
  result["T1tttt_1300_1000"]["106"] = 0.0189876;
  result["T1tttt_1300_1000"]["107"] = 0.01511;
  result["T1tttt_1300_1000"]["108"] = 0.0238784;
  result["T1tttt_1300_1000"]["109"] = 0.0195628;
  result["T1tttt_1300_1000"]["110"] = 0.0154675;
  result["T1tttt_1300_1000"]["111"] = 0.0180296;
  result["T1tttt_1300_1000"]["112"] = 0.0180938;
  result["T1tttt_1300_1000"]["113"] = 0.0186284;
  result["T1tttt_1300_1000"]["114"] = 0.0181381;
  result["T1tttt_1300_1000"]["115"] = 0.0181912;
  result["T1tttt_1300_1000"]["116"] = 0.0177985;
  result["T1tttt_1300_1000"]["117"] = 0.0183334;
  result["T1tttt_1300_1000"]["118"] = 0.0180406;
  result["T1tttt_1300_1000"]["119"] = 0.0176232;
  result["T1tttt_1300_1000"]["120"] = 0.0187666;
  result["T1tttt_1300_1000"]["121"] = 0.0182194;
  result["T1tttt_1300_1000"]["122"] = 0.0180979;
  result["T1tttt_1300_1000"]["123"] = 0.0180902;
  result["T1tttt_1300_1000"]["124"] = 0.01971;
  result["T1tttt_1300_1000"]["125"] = 0.018423;
  result["T1tttt_1300_1000"]["126"] = 0.0182339;
  result["T1tttt_1300_1000"]["127"] = 0.0176103;
  result["T1tttt_1300_1000"]["128"] = 0.0210171;
  result["T1tttt_1300_1000"]["129"] = 0.018507;
  result["T1tttt_1300_1000"]["130"] = 0.0165607;
  result["T1tttt_1300_1000"]["131"] = 0.0177815;
  result["T1tttt_1300_1000"]["132"] = 0.0175697;
  result["T1tttt_1300_1000"]["133"] = 0.0169394;
  result["T1tttt_1300_1000"]["134"] = 0.0159612;
  result["T1tttt_1300_1000"]["135"] = 0.0193335;
  result["T1tttt_1300_1000"]["136"] = 0.0181325;
  result["T1tttt_1300_1000"]["137"] = 0.018001;
  result["T1tttt_1300_1000"]["138"] = 0.02006;
  result["T1tttt_1300_1000"]["139"] = 0.0191659;
  result["T1tttt_1300_1000"]["140"] = 0.0184345;
  result["T1tttt_1300_1000"]["141"] = 0.016836;
  result["T1tttt_1300_1000"]["142"] = 0.0175801;
  result["T1tttt_1300_1000"]["143"] = 0.0181105;
  result["T1tttt_1300_1000"]["144"] = 0.0172398;
  result["T1tttt_1300_1000"]["145"] = 0.0172231;
  result["T1tttt_1300_1000"]["146"] = 0.0188078;
  result["T1tttt_1300_1000"]["147"] = 0.017784;
  result["T1tttt_1300_1000"]["148"] = 0.018565;
  result["T1tttt_1300_1000"]["149"] = 0.0172167;
  result["T1tttt_1300_1000"]["150"] = 0.0171341;
  result["T1tttt_1300_1000"]["151"] = 0.0180782;
  result["T1tttt_1300_1000"]["152"] = 0.0172609;
  result["T1tttt_1300_1000"]["153"] = 0.017782;
  result["T1tttt_1300_1000"]["154"] = 0.017368;
  result["T1tttt_1300_1000"]["155"] = 0.0175738;
  result["T1tttt_1300_1000"]["156"] = 0.0167045;
  result["T1tttt_1300_1000"]["157"] = 0.0160282;
  result["T1tttt_1300_1000"]["158"] = 0.0185443;
  result["T1tttt_1300_1000"]["159"] = 0.0208731;
  result["T1tttt_1300_1000"]["160"] = 0.0179396;
  result["T1tttt_1300_1000"]["161"] = 0.0180137;
  result["T1tttt_1300_1000"]["162"] = 0.0174761;
  result["T1tttt_1300_1000"]["163"] = 0.0181567;
  result["T1tttt_1300_1000"]["164"] = 0.0165342;
  result["T1tttt_1300_1000"]["165"] = 0.0186799;
  result["T1tttt_1300_1000"]["166"] = 0.0179902;
  result["T1tttt_1300_1000"]["167"] = 0.018412;
  result["T1tttt_1300_1000"]["168"] = 0.0171992;
  result["T1tttt_1300_1000"]["169"] = 0.0174832;
  result["T1tttt_1300_1000"]["170"] = 0.0169222;
  result["T1tttt_1300_1000"]["171"] = 0.0164276;
  result["T1tttt_1300_1000"]["172"] = 0.0161347;
  result["T1tttt_1300_1000"]["173"] = 0.0172647;
  result["T1tttt_1300_1000"]["174"] = 0.0183504;
  result["T1tttt_1300_1000"]["175"] = 0.0184855;
  result["T1tttt_1300_1000"]["176"] = 0.018163;
  result["T1tttt_1300_1000"]["177"] = 0.0181512;
  result["T1tttt_1300_1000"]["178"] = 0.0176396;
  result["T1tttt_1300_1000"]["179"] = 0.0175894;
  result["T1tttt_1300_1000"]["180"] = 0.0180931;
  result["T1tttt_1300_1000"]["181"] = 0.0213398;
  result["T1tttt_1300_1000"]["182"] = 0.0170057;
  result["T1tttt_1300_1000"]["183"] = 0.0160575;
  result["T1tttt_1300_1000"]["184"] = 0.018005;
  result["T1tttt_1300_1000"]["185"] = 0.0174977;
  result["T1tttt_1300_1000"]["186"] = 0.016621;
  result["T1tttt_1300_1000"]["187"] = 0.0155964;
  result["T1tttt_1300_1000"]["188"] = 0.0156858;
  result["T1tttt_1300_1000"]["189"] = 0.0177641;
  result["T1tttt_1300_1000"]["190"] = 0.0167888;
  result["T1tttt_1300_1000"]["191"] = 0.0194374;
  result["T1tttt_1300_1000"]["192"] = 0.0174611;
  result["T1tttt_1300_1000"]["193"] = 0.0175436;
  result["T1tttt_1300_1000"]["194"] = 0.0162234;
  result["T1tttt_1300_1000"]["195"] = 0.0167133;
  result["T1tttt_1300_1000"]["196"] = 0.0179173;
  result["T1tttt_1300_1000"]["197"] = 0.0177618;
  result["T1tttt_1300_1000"]["198"] = 0.0165249;
  result["T1tttt_1300_1000"]["199"] = 0.0189576;
  result["T1tttt_1300_1000"]["200"] = 0.0172671;
  result["T1tttt_1300_1000"]["201"] = 0.0183922;
  result["T1tttt_1300_1000"]["202"] = 0.0167214;
  result["T1tttt_1300_1000"]["203"] = 0.0160783;
  result["T1tttt_1300_1000"]["204"] = 0.0173414;
  result["T1tttt_1300_1000"]["205"] = 0.0152075;
  result["T1tttt_1300_1000"]["206"] = 0.0190906;
  result["T1tttt_1300_1000"]["207"] = 0.0164182;
  result["T1tttt_1300_1000"]["208"] = 0.0171729;
  result["T1tttt_1300_1000"]["209"] = 0.0148808;
  result["T1tttt_1300_1000"]["210"] = 0.0154858;
  result["T1tttt_1300_1000"]["211"] = 0.0192918;
  result["T1tttt_1300_1000"]["212"] = 0.0185694;
  result["T1tttt_1300_1000"]["213"] = 0.0179641;
  result["T1tttt_1300_1000"]["214"] = 0.0176949;
  result["T1tttt_1300_1000"]["215"] = 0.0174692;
  result["T1tttt_1300_1000"]["216"] = 0.0184856;
  result["T1tttt_1300_1000"]["217"] = 0.0168919;
  result["T1tttt_1300_1000"]["218"] = 0.0194486;
  result["T1tttt_1300_1000"]["219"] = 0.0182374;
  result["T1tttt_1300_1000"]["220"] = 0.0186972;
  result["T1tttt_1300_1000"]["221"] = 0.0175486;
  result["T1tttt_1300_1000"]["222"] = 0.0180049;
  result["T1tttt_1300_1000"]["223"] = 0.0172284;
  result["T1tttt_1300_1000"]["224"] = 0.0173352;
  result["T1tttt_1300_1000"]["225"] = 0.0173602;
  result["T1tttt_1300_1000"]["226"] = 0.0163342;
  result["T1tttt_1300_1000"]["227"] = 0.0188198;
  result["T1tttt_1300_1000"]["228"] = 0.018906;
  result["T1tttt_1300_1000"]["229"] = 0.0191423;
  result["T1tttt_1300_1000"]["230"] = 0.0173774;
  result["T1tttt_1300_1000"]["231"] = 0.016616;
  result["T1tttt_1300_1000"]["232"] = 0.0183116;
  result["T1tttt_1300_1000"]["233"] = 0.0191657;
  result["T1tttt_1300_1000"]["234"] = 0.0191873;
  result["T1tttt_1300_1000"]["235"] = 0.0155872;
  result["T1tttt_1300_1000"]["236"] = 0.0197474;
  result["T1tttt_1300_1000"]["237"] = 0.0191943;
  result["T1tttt_1300_1000"]["238"] = 0.0186798;
  result["T1tttt_1300_1000"]["239"] = 0.0182862;
  result["T1tttt_1300_1000"]["240"] = 0.017108;
  result["T1tttt_1300_1000"]["241"] = 0.0174188;
  result["T1tttt_1300_1000"]["242"] = 0.0182034;
  result["T1tttt_1300_1000"]["243"] = 0.0174363;
  result["T1tttt_1300_1000"]["244"] = 0.0177276;
  result["T1tttt_1300_1000"]["245"] = 0.0167157;
  result["T1tttt_1300_1000"]["246"] = 0.0187838;
  result["T1tttt_1300_1000"]["247"] = 0.0177512;
  result["T1tttt_1300_1000"]["248"] = 0.0179004;
  result["T1tttt_1300_1000"]["249"] = 0.0185019;
  result["T1tttt_1300_1000"]["250"] = 0.0188627;
  result["T1tttt_1300_1000"]["251"] = 0.0186091;
  result["T1tttt_1300_1000"]["252"] = 0.0189878;
  result["T1tttt_1300_1000"]["253"] = 0.0184525;
  result["T1tttt_1300_1000"]["254"] = 0.018302;
  result["T1tttt_1300_1000"]["255"] = 0.0185313;
  result["T1tttt_1300_1000"]["256"] = 0.0171742;
  result["T1tttt_1300_1000"]["257"] = 0.0183042;
  result["T1tttt_1300_1000"]["258"] = 0.0169156;
  result["T1tttt_1300_1000"]["259"] = 0.0196395;
  result["T1tttt_1300_1000"]["260"] = 0.0200675;
  result["T1tttt_1300_1000"]["261"] = 0.0181359;
  result["T1tttt_1300_1000"]["262"] = 0.0167888;
  result["T1tttt_1300_1000"]["263"] = 0.0183675;
  result["T1tttt_1300_1000"]["264"] = 0.0187684;
  result["T1tttt_1300_1000"]["265"] = 0.0169076;
  result["T1tttt_1300_1000"]["266"] = 0.0169077;
  result["T1tttt_1300_1000"]["267"] = 0.0169069;
  result["T1tttt_1300_1000"]["268"] = 0.0169313;
  result["T1tttt_1300_1000"]["269"] = 0.0168902;
  result["T1tttt_1300_1000"]["270"] = 0.0169831;
  result["T1tttt_1300_1000"]["271"] = 0.0168344;
  result["T1tttt_1300_1000"]["272"] = 0.0169617;
  result["T1tttt_1300_1000"]["273"] = 0.0168407;
  result["T1tttt_1300_1000"]["274"] = 0.0168244;
  result["T1tttt_1300_1000"]["275"] = 0.0170114;
  result["T1tttt_1300_1000"]["276"] = 0.0168582;
  result["T1tttt_1300_1000"]["277"] = 0.0170057;
  result["T1tttt_1300_1000"]["278"] = 0.0169098;
  result["T1tttt_1300_1000"]["279"] = 0.016904;
  result["T1tttt_1300_1000"]["280"] = 0.017001;
  result["T1tttt_1300_1000"]["281"] = 0.0168437;
  result["T1tttt_1300_1000"]["282"] = 0.0168728;
  result["T1tttt_1300_1000"]["283"] = 0.0169459;
  result["T1tttt_1300_1000"]["284"] = 0.0168235;
  result["T1tttt_1300_1000"]["285"] = 0.0169712;
  result["T1tttt_1300_1000"]["286"] = 0.0168137;
  result["T1tttt_1300_1000"]["287"] = 0.0170035;
  result["T1tttt_1300_1000"]["288"] = 0.0168175;
  result["T1tttt_1300_1000"]["289"] = 0.0169847;
  result["T1tttt_1300_1000"]["290"] = 0.0166639;
  result["T1tttt_1300_1000"]["291"] = 0.0172145;
  result["T1tttt_1300_1000"]["292"] = 0.0167641;
  result["T1tttt_1300_1000"]["293"] = 0.016977;
  result["T1tttt_1300_1000"]["294"] = 0.0163361;
  result["T1tttt_1300_1000"]["295"] = 0.0176177;
  result["T1tttt_1300_1000"]["296"] = 0.0164824;
  result["T1tttt_1300_1000"]["297"] = 0.0173245;
  result["T1tttt_1300_1000"]["298"] = 0.0168562;
  result["T1tttt_1300_1000"]["299"] = 0.0169888;
  result["T1tttt_1300_1000"]["300"] = 0.0169523;
  result["T1tttt_1300_1000"]["301"] = 0.016808;
  result["T1tttt_1300_1000"]["302"] = 0.0167885;
  result["T1tttt_1300_1000"]["303"] = 0.0169292;
  result["T1tttt_1300_1000"]["304"] = 0.0167412;
  result["T1tttt_1300_1000"]["305"] = 0.0170433;
  result["T1tttt_1300_1000"]["306"] = 0.0166513;
  result["T1tttt_1300_1000"]["307"] = 0.0172473;
  result["T1tttt_1300_1000"]["308"] = 0.0169143;
  result["T1tttt_1300_1000"]["309"] = 0.0168774;
  result["T1tttt_1300_1000"]["310"] = 0.0168418;
  result["T1tttt_1300_1000"]["311"] = 0.0170753;
  result["T1tttt_1300_1000"]["312"] = 0.0165949;
  result["T1tttt_1300_1000"]["313"] = 0.0176404;
  result["T1tttt_1300_1000"]["314"] = 0.0168034;
  result["T1tttt_1300_1000"]["315"] = 0.0170595;
  result["T1tttt_1600_0"]["1"] = 0.000913061;
  result["T1tttt_1600_0"]["2"] = 0.000786356;
  result["T1tttt_1600_0"]["3"] = 0.00107505;
  result["T1tttt_1600_0"]["4"] = 0.000790436;
  result["T1tttt_1600_0"]["5"] = 0.000680711;
  result["T1tttt_1600_0"]["6"] = 0.000930636;
  result["T1tttt_1600_0"]["7"] = 0.00106669;
  result["T1tttt_1600_0"]["8"] = 0.000918638;
  result["T1tttt_1600_0"]["9"] = 0.00125587;
  result["T1tttt_1600_0"]["10"] = 0.000913061;
  result["T1tttt_1600_0"]["11"] = 0.000823953;
  result["T1tttt_1600_0"]["12"] = 0.000536713;
  result["T1tttt_1600_0"]["13"] = 0.000813346;
  result["T1tttt_1600_0"]["14"] = 0.00095354;
  result["T1tttt_1600_0"]["15"] = 0.0008478;
  result["T1tttt_1600_0"]["16"] = 0.000614129;
  result["T1tttt_1600_0"]["17"] = 0.00115884;
  result["T1tttt_1600_0"]["18"] = 0.000806546;
  result["T1tttt_1600_0"]["19"] = 0.00100526;
  result["T1tttt_1600_0"]["20"] = 0.000501124;
  result["T1tttt_1600_0"]["21"] = 0.000655439;
  result["T1tttt_1600_0"]["22"] = 0.000710058;
  result["T1tttt_1600_0"]["23"] = 0.000973409;
  result["T1tttt_1600_0"]["24"] = 0.00103197;
  result["T1tttt_1600_0"]["25"] = 0.000856681;
  result["T1tttt_1600_0"]["26"] = 0.000715187;
  result["T1tttt_1600_0"]["27"] = 0.00117759;
  result["T1tttt_1600_0"]["28"] = 0.00118174;
  result["T1tttt_1600_0"]["29"] = 0.000891947;
  result["T1tttt_1600_0"]["30"] = 0.000994353;
  result["T1tttt_1600_0"]["31"] = 0.00101186;
  result["T1tttt_1600_0"]["32"] = 0.000800623;
  result["T1tttt_1600_0"]["33"] = 0.000875472;
  result["T1tttt_1600_0"]["34"] = 0.000728432;
  result["T1tttt_1600_0"]["35"] = 0.00114824;
  result["T1tttt_1600_0"]["36"] = 0.00121687;
  result["T1tttt_1600_0"]["37"] = 0.00128655;
  result["T1tttt_1600_0"]["38"] = 0.000910767;
  result["T1tttt_1600_0"]["39"] = 0.000822989;
  result["T1tttt_1600_0"]["40"] = 0.000908859;
  result["T1tttt_1600_0"]["41"] = 0.000790592;
  result["T1tttt_1600_0"]["42"] = 0.00118703;
  result["T1tttt_1600_0"]["43"] = 0.000913391;
  result["T1tttt_1600_0"]["44"] = 0.000808744;
  result["T1tttt_1600_0"]["45"] = 0.000746773;
  result["T1tttt_1600_0"]["46"] = 0.000797204;
  result["T1tttt_1600_0"]["47"] = 0.000645135;
  result["T1tttt_1600_0"]["48"] = 0.000726914;
  result["T1tttt_1600_0"]["49"] = 0.000915622;
  result["T1tttt_1600_0"]["50"] = 0.00111008;
  result["T1tttt_1600_0"]["51"] = 0.000775146;
  result["T1tttt_1600_0"]["52"] = 0.000861528;
  result["T1tttt_1600_0"]["53"] = 0.000957417;
  result["T1tttt_1600_0"]["54"] = 0.000756969;
  result["T1tttt_1600_0"]["55"] = 0.00106401;
  result["T1tttt_1600_0"]["56"] = 0.00106529;
  result["T1tttt_1600_0"]["57"] = 0.000852365;
  result["T1tttt_1600_0"]["58"] = 0.00109354;
  result["T1tttt_1600_0"]["59"] = 0.000811834;
  result["T1tttt_1600_0"]["60"] = 0.00103919;
  result["T1tttt_1600_0"]["61"] = 0.000987262;
  result["T1tttt_1600_0"]["62"] = 0.000919355;
  result["T1tttt_1600_0"]["63"] = 0.00102786;
  result["T1tttt_1600_0"]["64"] = 0.00134502;
  result["T1tttt_1600_0"]["65"] = 0.000739114;
  result["T1tttt_1600_0"]["66"] = 0.00149737;
  result["T1tttt_1600_0"]["67"] = 0.000825107;
  result["T1tttt_1600_0"]["68"] = 0.000831987;
  result["T1tttt_1600_0"]["69"] = 0.000942154;
  result["T1tttt_1600_0"]["70"] = 0.000732454;
  result["T1tttt_1600_0"]["71"] = 0.00100991;
  result["T1tttt_1600_0"]["72"] = 0.00089838;
  result["T1tttt_1600_0"]["73"] = 0.00105193;
  result["T1tttt_1600_0"]["74"] = 0.000893215;
  result["T1tttt_1600_0"]["75"] = 0.000898102;
  result["T1tttt_1600_0"]["76"] = 0.0010249;
  result["T1tttt_1600_0"]["77"] = 0.00138519;
  result["T1tttt_1600_0"]["78"] = 0.000827039;
  result["T1tttt_1600_0"]["79"] = 0.00104159;
  result["T1tttt_1600_0"]["80"] = 0.000613426;
  result["T1tttt_1600_0"]["81"] = 0.000988756;
  result["T1tttt_1600_0"]["82"] = 0.00122283;
  result["T1tttt_1600_0"]["83"] = 0.00113037;
  result["T1tttt_1600_0"]["84"] = 0.000659108;
  result["T1tttt_1600_0"]["85"] = 0.000961159;
  result["T1tttt_1600_0"]["86"] = 0.00102952;
  result["T1tttt_1600_0"]["87"] = 0.000982304;
  result["T1tttt_1600_0"]["88"] = 0.000780321;
  result["T1tttt_1600_0"]["89"] = 0.000884475;
  result["T1tttt_1600_0"]["90"] = 0.00100816;
  result["T1tttt_1600_0"]["91"] = 0.000900776;
  result["T1tttt_1600_0"]["92"] = 0.000883693;
  result["T1tttt_1600_0"]["93"] = 0.000782954;
  result["T1tttt_1600_0"]["94"] = 0.000994382;
  result["T1tttt_1600_0"]["95"] = 0.00104395;
  result["T1tttt_1600_0"]["96"] = 0.000820097;
  result["T1tttt_1600_0"]["97"] = 0.00119514;
  result["T1tttt_1600_0"]["98"] = 0.00143183;
  result["T1tttt_1600_0"]["99"] = 0.00089744;
  result["T1tttt_1600_0"]["100"] = 0.00114704;
  result["T1tttt_1600_0"]["101"] = 0.000709168;
  result["T1tttt_1600_0"]["102"] = 0.000812723;
  result["T1tttt_1600_0"]["103"] = 0.000700171;
  result["T1tttt_1600_0"]["104"] = 0.00127377;
  result["T1tttt_1600_0"]["105"] = 0.000710671;
  result["T1tttt_1600_0"]["106"] = 0.000949141;
  result["T1tttt_1600_0"]["107"] = 0.000750389;
  result["T1tttt_1600_0"]["108"] = 0.00126373;
  result["T1tttt_1600_0"]["109"] = 0.000990984;
  result["T1tttt_1600_0"]["110"] = 0.000797944;
  result["T1tttt_1600_0"]["111"] = 0.000932284;
  result["T1tttt_1600_0"]["112"] = 0.000941903;
  result["T1tttt_1600_0"]["113"] = 0.000923432;
  result["T1tttt_1600_0"]["114"] = 0.000937428;
  result["T1tttt_1600_0"]["115"] = 0.00092712;
  result["T1tttt_1600_0"]["116"] = 0.000910172;
  result["T1tttt_1600_0"]["117"] = 0.00095174;
  result["T1tttt_1600_0"]["118"] = 0.000968239;
  result["T1tttt_1600_0"]["119"] = 0.000903587;
  result["T1tttt_1600_0"]["120"] = 0.000933999;
  result["T1tttt_1600_0"]["121"] = 0.000931635;
  result["T1tttt_1600_0"]["122"] = 0.000909272;
  result["T1tttt_1600_0"]["123"] = 0.0009491;
  result["T1tttt_1600_0"]["124"] = 0.000993516;
  result["T1tttt_1600_0"]["125"] = 0.000850676;
  result["T1tttt_1600_0"]["126"] = 0.000946731;
  result["T1tttt_1600_0"]["127"] = 0.000920736;
  result["T1tttt_1600_0"]["128"] = 0.000962518;
  result["T1tttt_1600_0"]["129"] = 0.000913405;
  result["T1tttt_1600_0"]["130"] = 0.000874282;
  result["T1tttt_1600_0"]["131"] = 0.000959341;
  result["T1tttt_1600_0"]["132"] = 0.000945757;
  result["T1tttt_1600_0"]["133"] = 0.000922355;
  result["T1tttt_1600_0"]["134"] = 0.000784239;
  result["T1tttt_1600_0"]["135"] = 0.00120368;
  result["T1tttt_1600_0"]["136"] = 0.000933372;
  result["T1tttt_1600_0"]["137"] = 0.000940663;
  result["T1tttt_1600_0"]["138"] = 0.000903764;
  result["T1tttt_1600_0"]["139"] = 0.000956513;
  result["T1tttt_1600_0"]["140"] = 0.000958047;
  result["T1tttt_1600_0"]["141"] = 0.000918461;
  result["T1tttt_1600_0"]["142"] = 0.000937693;
  result["T1tttt_1600_0"]["143"] = 0.000934364;
  result["T1tttt_1600_0"]["144"] = 0.000874892;
  result["T1tttt_1600_0"]["145"] = 0.00104092;
  result["T1tttt_1600_0"]["146"] = 0.000883426;
  result["T1tttt_1600_0"]["147"] = 0.000971798;
  result["T1tttt_1600_0"]["148"] = 0.000924619;
  result["T1tttt_1600_0"]["149"] = 0.000954659;
  result["T1tttt_1600_0"]["150"] = 0.00090859;
  result["T1tttt_1600_0"]["151"] = 0.000989653;
  result["T1tttt_1600_0"]["152"] = 0.000958763;
  result["T1tttt_1600_0"]["153"] = 0.000918084;
  result["T1tttt_1600_0"]["154"] = 0.000959346;
  result["T1tttt_1600_0"]["155"] = 0.000917585;
  result["T1tttt_1600_0"]["156"] = 0.000923077;
  result["T1tttt_1600_0"]["157"] = 0.000955613;
  result["T1tttt_1600_0"]["158"] = 0.000896311;
  result["T1tttt_1600_0"]["159"] = 0.00124938;
  result["T1tttt_1600_0"]["160"] = 0.000932036;
  result["T1tttt_1600_0"]["161"] = 0.000948224;
  result["T1tttt_1600_0"]["162"] = 0.000926235;
  result["T1tttt_1600_0"]["163"] = 0.000883132;
  result["T1tttt_1600_0"]["164"] = 0.000834253;
  result["T1tttt_1600_0"]["165"] = 0.000832362;
  result["T1tttt_1600_0"]["166"] = 0.000932611;
  result["T1tttt_1600_0"]["167"] = 0.000826109;
  result["T1tttt_1600_0"]["168"] = 0.000883364;
  result["T1tttt_1600_0"]["169"] = 0.000839503;
  result["T1tttt_1600_0"]["170"] = 0.00083235;
  result["T1tttt_1600_0"]["171"] = 0.000814508;
  result["T1tttt_1600_0"]["172"] = 0.000798957;
  result["T1tttt_1600_0"]["173"] = 0.000985778;
  result["T1tttt_1600_0"]["174"] = 0.000845504;
  result["T1tttt_1600_0"]["175"] = 0.000794613;
  result["T1tttt_1600_0"]["176"] = 0.000812149;
  result["T1tttt_1600_0"]["177"] = 0.000983932;
  result["T1tttt_1600_0"]["178"] = 0.000963821;
  result["T1tttt_1600_0"]["179"] = 0.000830878;
  result["T1tttt_1600_0"]["180"] = 0.000797829;
  result["T1tttt_1600_0"]["181"] = 0.00117171;
  result["T1tttt_1600_0"]["182"] = 0.000917853;
  result["T1tttt_1600_0"]["183"] = 0.000730554;
  result["T1tttt_1600_0"]["184"] = 0.000798357;
  result["T1tttt_1600_0"]["185"] = 0.000779051;
  result["T1tttt_1600_0"]["186"] = 0.000722153;
  result["T1tttt_1600_0"]["187"] = 0.000755632;
  result["T1tttt_1600_0"]["188"] = 0.000721278;
  result["T1tttt_1600_0"]["189"] = 0.000859441;
  result["T1tttt_1600_0"]["190"] = 0.00082816;
  result["T1tttt_1600_0"]["191"] = 0.00111568;
  result["T1tttt_1600_0"]["192"] = 0.000933743;
  result["T1tttt_1600_0"]["193"] = 0.000808909;
  result["T1tttt_1600_0"]["194"] = 0.000684665;
  result["T1tttt_1600_0"]["195"] = 0.00079179;
  result["T1tttt_1600_0"]["196"] = 0.000850415;
  result["T1tttt_1600_0"]["197"] = 0.000798291;
  result["T1tttt_1600_0"]["198"] = 0.000635615;
  result["T1tttt_1600_0"]["199"] = 0.000952006;
  result["T1tttt_1600_0"]["200"] = 0.00080129;
  result["T1tttt_1600_0"]["201"] = 0.000906871;
  result["T1tttt_1600_0"]["202"] = 0.000711588;
  result["T1tttt_1600_0"]["203"] = 0.000749306;
  result["T1tttt_1600_0"]["204"] = 0.000805224;
  result["T1tttt_1600_0"]["205"] = 0.000743677;
  result["T1tttt_1600_0"]["206"] = 0.000799763;
  result["T1tttt_1600_0"]["207"] = 0.000709183;
  result["T1tttt_1600_0"]["208"] = 0.00079665;
  result["T1tttt_1600_0"]["209"] = 0.000702834;
  result["T1tttt_1600_0"]["210"] = 0.000555366;
  result["T1tttt_1600_0"]["211"] = 0.000907503;
  result["T1tttt_1600_0"]["212"] = 0.000892663;
  result["T1tttt_1600_0"]["213"] = 0.000814918;
  result["T1tttt_1600_0"]["214"] = 0.000783556;
  result["T1tttt_1600_0"]["215"] = 0.000717716;
  result["T1tttt_1600_0"]["216"] = 0.000938429;
  result["T1tttt_1600_0"]["217"] = 0.000741437;
  result["T1tttt_1600_0"]["218"] = 0.00097212;
  result["T1tttt_1600_0"]["219"] = 0.00078859;
  result["T1tttt_1600_0"]["220"] = 0.000948548;
  result["T1tttt_1600_0"]["221"] = 0.000809706;
  result["T1tttt_1600_0"]["222"] = 0.000811896;
  result["T1tttt_1600_0"]["223"] = 0.000771843;
  result["T1tttt_1600_0"]["224"] = 0.000770121;
  result["T1tttt_1600_0"]["225"] = 0.00066152;
  result["T1tttt_1600_0"]["226"] = 0.000757731;
  result["T1tttt_1600_0"]["227"] = 0.000948765;
  result["T1tttt_1600_0"]["228"] = 0.000933365;
  result["T1tttt_1600_0"]["229"] = 0.000936016;
  result["T1tttt_1600_0"]["230"] = 0.000780267;
  result["T1tttt_1600_0"]["231"] = 0.000717039;
  result["T1tttt_1600_0"]["232"] = 0.000816605;
  result["T1tttt_1600_0"]["233"] = 0.000971954;
  result["T1tttt_1600_0"]["234"] = 0.000939112;
  result["T1tttt_1600_0"]["235"] = 0.00070695;
  result["T1tttt_1600_0"]["236"] = 0.000788654;
  result["T1tttt_1600_0"]["237"] = 0.000974837;
  result["T1tttt_1600_0"]["238"] = 0.000915267;
  result["T1tttt_1600_0"]["239"] = 0.000996475;
  result["T1tttt_1600_0"]["240"] = 0.000684353;
  result["T1tttt_1600_0"]["241"] = 0.000727126;
  result["T1tttt_1600_0"]["242"] = 0.000878886;
  result["T1tttt_1600_0"]["243"] = 0.000763226;
  result["T1tttt_1600_0"]["244"] = 0.00080666;
  result["T1tttt_1600_0"]["245"] = 0.000718437;
  result["T1tttt_1600_0"]["246"] = 0.000863738;
  result["T1tttt_1600_0"]["247"] = 0.000796839;
  result["T1tttt_1600_0"]["248"] = 0.000842042;
  result["T1tttt_1600_0"]["249"] = 0.000912708;
  result["T1tttt_1600_0"]["250"] = 0.000938543;
  result["T1tttt_1600_0"]["251"] = 0.000957286;
  result["T1tttt_1600_0"]["252"] = 0.000903505;
  result["T1tttt_1600_0"]["253"] = 0.000875099;
  result["T1tttt_1600_0"]["254"] = 0.000893903;
  result["T1tttt_1600_0"]["255"] = 0.000884107;
  result["T1tttt_1600_0"]["256"] = 0.000749127;
  result["T1tttt_1600_0"]["257"] = 0.000895928;
  result["T1tttt_1600_0"]["258"] = 0.000661712;
  result["T1tttt_1600_0"]["259"] = 0.00108951;
  result["T1tttt_1600_0"]["260"] = 0.000842754;
  result["T1tttt_1600_0"]["261"] = 0.000870554;
  result["T1tttt_1600_0"]["262"] = 0.000698194;
  result["T1tttt_1600_0"]["263"] = 0.000878965;
  result["T1tttt_1600_0"]["264"] = 0.000993383;
  result["T1tttt_1600_0"]["265"] = 0.00079805;
  result["T1tttt_1600_0"]["266"] = 0.000798148;
  result["T1tttt_1600_0"]["267"] = 0.000797887;
  result["T1tttt_1600_0"]["268"] = 0.00079915;
  result["T1tttt_1600_0"]["269"] = 0.000797187;
  result["T1tttt_1600_0"]["270"] = 0.000801669;
  result["T1tttt_1600_0"]["271"] = 0.000794468;
  result["T1tttt_1600_0"]["272"] = 0.000801153;
  result["T1tttt_1600_0"]["273"] = 0.000794139;
  result["T1tttt_1600_0"]["274"] = 0.00079375;
  result["T1tttt_1600_0"]["275"] = 0.000803379;
  result["T1tttt_1600_0"]["276"] = 0.000795392;
  result["T1tttt_1600_0"]["277"] = 0.000803199;
  result["T1tttt_1600_0"]["278"] = 0.000798136;
  result["T1tttt_1600_0"]["279"] = 0.00079781;
  result["T1tttt_1600_0"]["280"] = 0.000802957;
  result["T1tttt_1600_0"]["281"] = 0.000794668;
  result["T1tttt_1600_0"]["282"] = 0.000795803;
  result["T1tttt_1600_0"]["283"] = 0.000800491;
  result["T1tttt_1600_0"]["284"] = 0.000794117;
  result["T1tttt_1600_0"]["285"] = 0.000800919;
  result["T1tttt_1600_0"]["286"] = 0.000791939;
  result["T1tttt_1600_0"]["287"] = 0.000804203;
  result["T1tttt_1600_0"]["288"] = 0.000793761;
  result["T1tttt_1600_0"]["289"] = 0.00080158;
  result["T1tttt_1600_0"]["290"] = 0.000786307;
  result["T1tttt_1600_0"]["291"] = 0.000812778;
  result["T1tttt_1600_0"]["292"] = 0.000789735;
  result["T1tttt_1600_0"]["293"] = 0.000803065;
  result["T1tttt_1600_0"]["294"] = 0.000765393;
  result["T1tttt_1600_0"]["295"] = 0.000838655;
  result["T1tttt_1600_0"]["296"] = 0.000778393;
  result["T1tttt_1600_0"]["297"] = 0.000818561;
  result["T1tttt_1600_0"]["298"] = 0.000793705;
  result["T1tttt_1600_0"]["299"] = 0.000804401;
  result["T1tttt_1600_0"]["300"] = 0.000799436;
  result["T1tttt_1600_0"]["301"] = 0.000795453;
  result["T1tttt_1600_0"]["302"] = 0.000790523;
  result["T1tttt_1600_0"]["303"] = 0.000799716;
  result["T1tttt_1600_0"]["304"] = 0.000788084;
  result["T1tttt_1600_0"]["305"] = 0.000805562;
  result["T1tttt_1600_0"]["306"] = 0.000787279;
  result["T1tttt_1600_0"]["307"] = 0.000812392;
  result["T1tttt_1600_0"]["308"] = 0.000802785;
  result["T1tttt_1600_0"]["309"] = 0.00079248;
  result["T1tttt_1600_0"]["310"] = 0.000794834;
  result["T1tttt_1600_0"]["311"] = 0.00080584;
  result["T1tttt_1600_0"]["312"] = 0.00078046;
  result["T1tttt_1600_0"]["313"] = 0.000839316;
  result["T1tttt_1600_0"]["314"] = 0.000791826;
  result["T1tttt_1600_0"]["315"] = 0.000808784;
  result["T1tttt_1600_1200"]["1"] = 0.00304286;
  result["T1tttt_1600_1200"]["2"] = 0.00262175;
  result["T1tttt_1600_1200"]["3"] = 0.00358108;
  result["T1tttt_1600_1200"]["4"] = 0.00263435;
  result["T1tttt_1600_1200"]["5"] = 0.00226958;
  result["T1tttt_1600_1200"]["6"] = 0.00310007;
  result["T1tttt_1600_1200"]["7"] = 0.00355494;
  result["T1tttt_1600_1200"]["8"] = 0.00306272;
  result["T1tttt_1600_1200"]["9"] = 0.00418334;
  result["T1tttt_1600_1200"]["10"] = 0.00304286;
  result["T1tttt_1600_1200"]["11"] = 0.00276709;
  result["T1tttt_1600_1200"]["12"] = 0.00180245;
  result["T1tttt_1600_1200"]["13"] = 0.0027115;
  result["T1tttt_1600_1200"]["14"] = 0.00313559;
  result["T1tttt_1600_1200"]["15"] = 0.00287823;
  result["T1tttt_1600_1200"]["16"] = 0.0020602;
  result["T1tttt_1600_1200"]["17"] = 0.00382824;
  result["T1tttt_1600_1200"]["18"] = 0.00267515;
  result["T1tttt_1600_1200"]["19"] = 0.00333026;
  result["T1tttt_1600_1200"]["20"] = 0.00167756;
  result["T1tttt_1600_1200"]["21"] = 0.00219342;
  result["T1tttt_1600_1200"]["22"] = 0.00234567;
  result["T1tttt_1600_1200"]["23"] = 0.00326551;
  result["T1tttt_1600_1200"]["24"] = 0.00343406;
  result["T1tttt_1600_1200"]["25"] = 0.00282977;
  result["T1tttt_1600_1200"]["26"] = 0.00236474;
  result["T1tttt_1600_1200"]["27"] = 0.00388906;
  result["T1tttt_1600_1200"]["28"] = 0.00394805;
  result["T1tttt_1600_1200"]["29"] = 0.00295295;
  result["T1tttt_1600_1200"]["30"] = 0.00331948;
  result["T1tttt_1600_1200"]["31"] = 0.00335476;
  result["T1tttt_1600_1200"]["32"] = 0.00265539;
  result["T1tttt_1600_1200"]["33"] = 0.00290937;
  result["T1tttt_1600_1200"]["34"] = 0.00244689;
  result["T1tttt_1600_1200"]["35"] = 0.00381443;
  result["T1tttt_1600_1200"]["36"] = 0.0040387;
  result["T1tttt_1600_1200"]["37"] = 0.00431064;
  result["T1tttt_1600_1200"]["38"] = 0.0030341;
  result["T1tttt_1600_1200"]["39"] = 0.00275799;
  result["T1tttt_1600_1200"]["40"] = 0.0030349;
  result["T1tttt_1600_1200"]["41"] = 0.00264436;
  result["T1tttt_1600_1200"]["42"] = 0.00391429;
  result["T1tttt_1600_1200"]["43"] = 0.00304743;
  result["T1tttt_1600_1200"]["44"] = 0.00272066;
  result["T1tttt_1600_1200"]["45"] = 0.0025047;
  result["T1tttt_1600_1200"]["46"] = 0.0026518;
  result["T1tttt_1600_1200"]["47"] = 0.00217807;
  result["T1tttt_1600_1200"]["48"] = 0.00244927;
  result["T1tttt_1600_1200"]["49"] = 0.00302025;
  result["T1tttt_1600_1200"]["50"] = 0.00370914;
  result["T1tttt_1600_1200"]["51"] = 0.0026234;
  result["T1tttt_1600_1200"]["52"] = 0.00287848;
  result["T1tttt_1600_1200"]["53"] = 0.00319086;
  result["T1tttt_1600_1200"]["54"] = 0.00253424;
  result["T1tttt_1600_1200"]["55"] = 0.00352987;
  result["T1tttt_1600_1200"]["56"] = 0.00354852;
  result["T1tttt_1600_1200"]["57"] = 0.00285436;
  result["T1tttt_1600_1200"]["58"] = 0.00363993;
  result["T1tttt_1600_1200"]["59"] = 0.0027352;
  result["T1tttt_1600_1200"]["60"] = 0.00347412;
  result["T1tttt_1600_1200"]["61"] = 0.0033099;
  result["T1tttt_1600_1200"]["62"] = 0.00303731;
  result["T1tttt_1600_1200"]["63"] = 0.0034202;
  result["T1tttt_1600_1200"]["64"] = 0.00446058;
  result["T1tttt_1600_1200"]["65"] = 0.00249209;
  result["T1tttt_1600_1200"]["66"] = 0.00499766;
  result["T1tttt_1600_1200"]["67"] = 0.00276985;
  result["T1tttt_1600_1200"]["68"] = 0.00274545;
  result["T1tttt_1600_1200"]["69"] = 0.00314501;
  result["T1tttt_1600_1200"]["70"] = 0.00244494;
  result["T1tttt_1600_1200"]["71"] = 0.00337536;
  result["T1tttt_1600_1200"]["72"] = 0.00303538;
  result["T1tttt_1600_1200"]["73"] = 0.00349429;
  result["T1tttt_1600_1200"]["74"] = 0.0030012;
  result["T1tttt_1600_1200"]["75"] = 0.00301452;
  result["T1tttt_1600_1200"]["76"] = 0.00340072;
  result["T1tttt_1600_1200"]["77"] = 0.00459345;
  result["T1tttt_1600_1200"]["78"] = 0.00277678;
  result["T1tttt_1600_1200"]["79"] = 0.00346819;
  result["T1tttt_1600_1200"]["80"] = 0.00205004;
  result["T1tttt_1600_1200"]["81"] = 0.0032836;
  result["T1tttt_1600_1200"]["82"] = 0.00404843;
  result["T1tttt_1600_1200"]["83"] = 0.00378283;
  result["T1tttt_1600_1200"]["84"] = 0.0022064;
  result["T1tttt_1600_1200"]["85"] = 0.00319043;
  result["T1tttt_1600_1200"]["86"] = 0.00342553;
  result["T1tttt_1600_1200"]["87"] = 0.0032913;
  result["T1tttt_1600_1200"]["88"] = 0.00260276;
  result["T1tttt_1600_1200"]["89"] = 0.00292142;
  result["T1tttt_1600_1200"]["90"] = 0.00338912;
  result["T1tttt_1600_1200"]["91"] = 0.00299821;
  result["T1tttt_1600_1200"]["92"] = 0.00294588;
  result["T1tttt_1600_1200"]["93"] = 0.00263758;
  result["T1tttt_1600_1200"]["94"] = 0.00327742;
  result["T1tttt_1600_1200"]["95"] = 0.00348066;
  result["T1tttt_1600_1200"]["96"] = 0.00272586;
  result["T1tttt_1600_1200"]["97"] = 0.00397856;
  result["T1tttt_1600_1200"]["98"] = 0.00475869;
  result["T1tttt_1600_1200"]["99"] = 0.00299177;
  result["T1tttt_1600_1200"]["100"] = 0.00381766;
  result["T1tttt_1600_1200"]["101"] = 0.00236329;
  result["T1tttt_1600_1200"]["102"] = 0.00271937;
  result["T1tttt_1600_1200"]["103"] = 0.00232723;
  result["T1tttt_1600_1200"]["104"] = 0.00421192;
  result["T1tttt_1600_1200"]["105"] = 0.00237401;
  result["T1tttt_1600_1200"]["106"] = 0.00315321;
  result["T1tttt_1600_1200"]["107"] = 0.00253192;
  result["T1tttt_1600_1200"]["108"] = 0.0041639;
  result["T1tttt_1600_1200"]["109"] = 0.00332006;
  result["T1tttt_1600_1200"]["110"] = 0.00268701;
  result["T1tttt_1600_1200"]["111"] = 0.00308905;
  result["T1tttt_1600_1200"]["112"] = 0.00312077;
  result["T1tttt_1600_1200"]["113"] = 0.0030598;
  result["T1tttt_1600_1200"]["114"] = 0.00310606;
  result["T1tttt_1600_1200"]["115"] = 0.00307192;
  result["T1tttt_1600_1200"]["116"] = 0.00301513;
  result["T1tttt_1600_1200"]["117"] = 0.00315407;
  result["T1tttt_1600_1200"]["118"] = 0.00320599;
  result["T1tttt_1600_1200"]["119"] = 0.00299579;
  result["T1tttt_1600_1200"]["120"] = 0.00309514;
  result["T1tttt_1600_1200"]["121"] = 0.00308597;
  result["T1tttt_1600_1200"]["122"] = 0.00301019;
  result["T1tttt_1600_1200"]["123"] = 0.00314602;
  result["T1tttt_1600_1200"]["124"] = 0.00329032;
  result["T1tttt_1600_1200"]["125"] = 0.00282069;
  result["T1tttt_1600_1200"]["126"] = 0.00313808;
  result["T1tttt_1600_1200"]["127"] = 0.00304966;
  result["T1tttt_1600_1200"]["128"] = 0.00318808;
  result["T1tttt_1600_1200"]["129"] = 0.00302695;
  result["T1tttt_1600_1200"]["130"] = 0.00289653;
  result["T1tttt_1600_1200"]["131"] = 0.00317865;
  result["T1tttt_1600_1200"]["132"] = 0.00313588;
  result["T1tttt_1600_1200"]["133"] = 0.00305381;
  result["T1tttt_1600_1200"]["134"] = 0.00260381;
  result["T1tttt_1600_1200"]["135"] = 0.00398092;
  result["T1tttt_1600_1200"]["136"] = 0.0030927;
  result["T1tttt_1600_1200"]["137"] = 0.00311611;
  result["T1tttt_1600_1200"]["138"] = 0.00299412;
  result["T1tttt_1600_1200"]["139"] = 0.00316924;
  result["T1tttt_1600_1200"]["140"] = 0.00317704;
  result["T1tttt_1600_1200"]["141"] = 0.00304104;
  result["T1tttt_1600_1200"]["142"] = 0.0031094;
  result["T1tttt_1600_1200"]["143"] = 0.00309284;
  result["T1tttt_1600_1200"]["144"] = 0.00290347;
  result["T1tttt_1600_1200"]["145"] = 0.00344699;
  result["T1tttt_1600_1200"]["146"] = 0.00292676;
  result["T1tttt_1600_1200"]["147"] = 0.00322153;
  result["T1tttt_1600_1200"]["148"] = 0.00306421;
  result["T1tttt_1600_1200"]["149"] = 0.0031611;
  result["T1tttt_1600_1200"]["150"] = 0.00301515;
  result["T1tttt_1600_1200"]["151"] = 0.00327711;
  result["T1tttt_1600_1200"]["152"] = 0.0031767;
  result["T1tttt_1600_1200"]["153"] = 0.00304122;
  result["T1tttt_1600_1200"]["154"] = 0.00318135;
  result["T1tttt_1600_1200"]["155"] = 0.003036;
  result["T1tttt_1600_1200"]["156"] = 0.0030603;
  result["T1tttt_1600_1200"]["157"] = 0.00316301;
  result["T1tttt_1600_1200"]["158"] = 0.00297138;
  result["T1tttt_1600_1200"]["159"] = 0.00418362;
  result["T1tttt_1600_1200"]["160"] = 0.00308852;
  result["T1tttt_1600_1200"]["161"] = 0.00313713;
  result["T1tttt_1600_1200"]["162"] = 0.00306981;
  result["T1tttt_1600_1200"]["163"] = 0.00292652;
  result["T1tttt_1600_1200"]["164"] = 0.00277059;
  result["T1tttt_1600_1200"]["165"] = 0.00276545;
  result["T1tttt_1600_1200"]["166"] = 0.00309386;
  result["T1tttt_1600_1200"]["167"] = 0.00274555;
  result["T1tttt_1600_1200"]["168"] = 0.0029344;
  result["T1tttt_1600_1200"]["169"] = 0.00277954;
  result["T1tttt_1600_1200"]["170"] = 0.00277653;
  result["T1tttt_1600_1200"]["171"] = 0.0026944;
  result["T1tttt_1600_1200"]["172"] = 0.0026101;
  result["T1tttt_1600_1200"]["173"] = 0.00330403;
  result["T1tttt_1600_1200"]["174"] = 0.00280943;
  result["T1tttt_1600_1200"]["175"] = 0.00267315;
  result["T1tttt_1600_1200"]["176"] = 0.00272827;
  result["T1tttt_1600_1200"]["177"] = 0.00329644;
  result["T1tttt_1600_1200"]["178"] = 0.00320735;
  result["T1tttt_1600_1200"]["179"] = 0.00276027;
  result["T1tttt_1600_1200"]["180"] = 0.00268636;
  result["T1tttt_1600_1200"]["181"] = 0.00388264;
  result["T1tttt_1600_1200"]["182"] = 0.00303804;
  result["T1tttt_1600_1200"]["183"] = 0.00242094;
  result["T1tttt_1600_1200"]["184"] = 0.00269155;
  result["T1tttt_1600_1200"]["185"] = 0.00262586;
  result["T1tttt_1600_1200"]["186"] = 0.00244534;
  result["T1tttt_1600_1200"]["187"] = 0.00252556;
  result["T1tttt_1600_1200"]["188"] = 0.00240575;
  result["T1tttt_1600_1200"]["189"] = 0.00289523;
  result["T1tttt_1600_1200"]["190"] = 0.00275346;
  result["T1tttt_1600_1200"]["191"] = 0.00366522;
  result["T1tttt_1600_1200"]["192"] = 0.00310389;
  result["T1tttt_1600_1200"]["193"] = 0.00271046;
  result["T1tttt_1600_1200"]["194"] = 0.00226267;
  result["T1tttt_1600_1200"]["195"] = 0.00263436;
  result["T1tttt_1600_1200"]["196"] = 0.00280305;
  result["T1tttt_1600_1200"]["197"] = 0.00265445;
  result["T1tttt_1600_1200"]["198"] = 0.00212144;
  result["T1tttt_1600_1200"]["199"] = 0.00315356;
  result["T1tttt_1600_1200"]["200"] = 0.00265896;
  result["T1tttt_1600_1200"]["201"] = 0.00301546;
  result["T1tttt_1600_1200"]["202"] = 0.00235851;
  result["T1tttt_1600_1200"]["203"] = 0.00244426;
  result["T1tttt_1600_1200"]["204"] = 0.00268934;
  result["T1tttt_1600_1200"]["205"] = 0.0024684;
  result["T1tttt_1600_1200"]["206"] = 0.00265584;
  result["T1tttt_1600_1200"]["207"] = 0.0023614;
  result["T1tttt_1600_1200"]["208"] = 0.00265163;
  result["T1tttt_1600_1200"]["209"] = 0.00230897;
  result["T1tttt_1600_1200"]["210"] = 0.00185144;
  result["T1tttt_1600_1200"]["211"] = 0.00303879;
  result["T1tttt_1600_1200"]["212"] = 0.0029583;
  result["T1tttt_1600_1200"]["213"] = 0.00268431;
  result["T1tttt_1600_1200"]["214"] = 0.00265583;
  result["T1tttt_1600_1200"]["215"] = 0.00241208;
  result["T1tttt_1600_1200"]["216"] = 0.00313523;
  result["T1tttt_1600_1200"]["217"] = 0.00246168;
  result["T1tttt_1600_1200"]["218"] = 0.00325528;
  result["T1tttt_1600_1200"]["219"] = 0.00263884;
  result["T1tttt_1600_1200"]["220"] = 0.0031382;
  result["T1tttt_1600_1200"]["221"] = 0.00268603;
  result["T1tttt_1600_1200"]["222"] = 0.00277649;
  result["T1tttt_1600_1200"]["223"] = 0.00255949;
  result["T1tttt_1600_1200"]["224"] = 0.00258913;
  result["T1tttt_1600_1200"]["225"] = 0.00218378;
  result["T1tttt_1600_1200"]["226"] = 0.00249613;
  result["T1tttt_1600_1200"]["227"] = 0.00314838;
  result["T1tttt_1600_1200"]["228"] = 0.00309026;
  result["T1tttt_1600_1200"]["229"] = 0.00310919;
  result["T1tttt_1600_1200"]["230"] = 0.00261109;
  result["T1tttt_1600_1200"]["231"] = 0.00237452;
  result["T1tttt_1600_1200"]["232"] = 0.00272541;
  result["T1tttt_1600_1200"]["233"] = 0.00319472;
  result["T1tttt_1600_1200"]["234"] = 0.00316252;
  result["T1tttt_1600_1200"]["235"] = 0.00236562;
  result["T1tttt_1600_1200"]["236"] = 0.00262508;
  result["T1tttt_1600_1200"]["237"] = 0.00320765;
  result["T1tttt_1600_1200"]["238"] = 0.00304301;
  result["T1tttt_1600_1200"]["239"] = 0.00329787;
  result["T1tttt_1600_1200"]["240"] = 0.00231809;
  result["T1tttt_1600_1200"]["241"] = 0.00241947;
  result["T1tttt_1600_1200"]["242"] = 0.00289828;
  result["T1tttt_1600_1200"]["243"] = 0.0025289;
  result["T1tttt_1600_1200"]["244"] = 0.00266411;
  result["T1tttt_1600_1200"]["245"] = 0.00239292;
  result["T1tttt_1600_1200"]["246"] = 0.00286092;
  result["T1tttt_1600_1200"]["247"] = 0.00266328;
  result["T1tttt_1600_1200"]["248"] = 0.00281518;
  result["T1tttt_1600_1200"]["249"] = 0.00300578;
  result["T1tttt_1600_1200"]["250"] = 0.00309923;
  result["T1tttt_1600_1200"]["251"] = 0.00319497;
  result["T1tttt_1600_1200"]["252"] = 0.00298006;
  result["T1tttt_1600_1200"]["253"] = 0.00294049;
  result["T1tttt_1600_1200"]["254"] = 0.00297749;
  result["T1tttt_1600_1200"]["255"] = 0.00294697;
  result["T1tttt_1600_1200"]["256"] = 0.00249331;
  result["T1tttt_1600_1200"]["257"] = 0.00295591;
  result["T1tttt_1600_1200"]["258"] = 0.00221271;
  result["T1tttt_1600_1200"]["259"] = 0.00361486;
  result["T1tttt_1600_1200"]["260"] = 0.00280151;
  result["T1tttt_1600_1200"]["261"] = 0.00284488;
  result["T1tttt_1600_1200"]["262"] = 0.00231578;
  result["T1tttt_1600_1200"]["263"] = 0.00293161;
  result["T1tttt_1600_1200"]["264"] = 0.00327599;
  result["T1tttt_1600_1200"]["265"] = 0.00264203;
  result["T1tttt_1600_1200"]["266"] = 0.00264234;
  result["T1tttt_1600_1200"]["267"] = 0.00264152;
  result["T1tttt_1600_1200"]["268"] = 0.00264567;
  result["T1tttt_1600_1200"]["269"] = 0.00263913;
  result["T1tttt_1600_1200"]["270"] = 0.00265392;
  result["T1tttt_1600_1200"]["271"] = 0.00263022;
  result["T1tttt_1600_1200"]["272"] = 0.0026524;
  result["T1tttt_1600_1200"]["273"] = 0.00262891;
  result["T1tttt_1600_1200"]["274"] = 0.00262769;
  result["T1tttt_1600_1200"]["275"] = 0.00265979;
  result["T1tttt_1600_1200"]["276"] = 0.00263319;
  result["T1tttt_1600_1200"]["277"] = 0.00265917;
  result["T1tttt_1600_1200"]["278"] = 0.00264245;
  result["T1tttt_1600_1200"]["279"] = 0.00264101;
  result["T1tttt_1600_1200"]["280"] = 0.00265826;
  result["T1tttt_1600_1200"]["281"] = 0.00263082;
  result["T1tttt_1600_1200"]["282"] = 0.0026348;
  result["T1tttt_1600_1200"]["283"] = 0.00264983;
  result["T1tttt_1600_1200"]["284"] = 0.00262874;
  result["T1tttt_1600_1200"]["285"] = 0.00265173;
  result["T1tttt_1600_1200"]["286"] = 0.00262121;
  result["T1tttt_1600_1200"]["287"] = 0.00266295;
  result["T1tttt_1600_1200"]["288"] = 0.00262749;
  result["T1tttt_1600_1200"]["289"] = 0.00265398;
  result["T1tttt_1600_1200"]["290"] = 0.00260352;
  result["T1tttt_1600_1200"]["291"] = 0.00269028;
  result["T1tttt_1600_1200"]["292"] = 0.00261446;
  result["T1tttt_1600_1200"]["293"] = 0.00265854;
  result["T1tttt_1600_1200"]["294"] = 0.00253426;
  result["T1tttt_1600_1200"]["295"] = 0.00277587;
  result["T1tttt_1600_1200"]["296"] = 0.00257771;
  result["T1tttt_1600_1200"]["297"] = 0.00270919;
  result["T1tttt_1600_1200"]["298"] = 0.00262707;
  result["T1tttt_1600_1200"]["299"] = 0.00266384;
  result["T1tttt_1600_1200"]["300"] = 0.00264622;
  result["T1tttt_1600_1200"]["301"] = 0.00263416;
  result["T1tttt_1600_1200"]["302"] = 0.0026174;
  result["T1tttt_1600_1200"]["303"] = 0.00264592;
  result["T1tttt_1600_1200"]["304"] = 0.00260881;
  result["T1tttt_1600_1200"]["305"] = 0.002667;
  result["T1tttt_1600_1200"]["306"] = 0.00260587;
  result["T1tttt_1600_1200"]["307"] = 0.00268985;
  result["T1tttt_1600_1200"]["308"] = 0.0026568;
  result["T1tttt_1600_1200"]["309"] = 0.00262405;
  result["T1tttt_1600_1200"]["310"] = 0.00263178;
  result["T1tttt_1600_1200"]["311"] = 0.00266813;
  result["T1tttt_1600_1200"]["312"] = 0.0025845;
  result["T1tttt_1600_1200"]["313"] = 0.00277747;
  result["T1tttt_1600_1200"]["314"] = 0.00262061;
  result["T1tttt_1600_1200"]["315"] = 0.00267852;
  result["T1tttt_700_0"]["1"] = 1.85022;
  result["T1tttt_700_0"]["2"] = 1.61916;
  result["T1tttt_700_0"]["3"] = 2.14176;
  result["T1tttt_700_0"]["4"] = 1.58133;
  result["T1tttt_700_0"]["5"] = 1.38384;
  result["T1tttt_700_0"]["6"] = 1.83053;
  result["T1tttt_700_0"]["7"] = 2.19401;
  result["T1tttt_700_0"]["8"] = 1.92006;
  result["T1tttt_700_0"]["9"] = 2.53969;
  result["T1tttt_700_0"]["10"] = 1.85022;
  result["T1tttt_700_0"]["11"] = 1.59909;
  result["T1tttt_700_0"]["12"] = 1.39336;
  result["T1tttt_700_0"]["13"] = 1.86843;
  result["T1tttt_700_0"]["14"] = 1.93587;
  result["T1tttt_700_0"]["15"] = 1.58769;
  result["T1tttt_700_0"]["16"] = 1.59887;
  result["T1tttt_700_0"]["17"] = 2.20963;
  result["T1tttt_700_0"]["18"] = 1.55112;
  result["T1tttt_700_0"]["19"] = 2.0318;
  result["T1tttt_700_0"]["20"] = 1.31573;
  result["T1tttt_700_0"]["21"] = 1.553;
  result["T1tttt_700_0"]["22"] = 1.50504;
  result["T1tttt_700_0"]["23"] = 1.81306;
  result["T1tttt_700_0"]["24"] = 2.25197;
  result["T1tttt_700_0"]["25"] = 1.78443;
  result["T1tttt_700_0"]["26"] = 1.49874;
  result["T1tttt_700_0"]["27"] = 2.11625;
  result["T1tttt_700_0"]["28"] = 2.30043;
  result["T1tttt_700_0"]["29"] = 1.98632;
  result["T1tttt_700_0"]["30"] = 1.73287;
  result["T1tttt_700_0"]["31"] = 2.04597;
  result["T1tttt_700_0"]["32"] = 1.63208;
  result["T1tttt_700_0"]["33"] = 1.78266;
  result["T1tttt_700_0"]["34"] = 1.52156;
  result["T1tttt_700_0"]["35"] = 2.34063;
  result["T1tttt_700_0"]["36"] = 2.13918;
  result["T1tttt_700_0"]["37"] = 2.11688;
  result["T1tttt_700_0"]["38"] = 2.01454;
  result["T1tttt_700_0"]["39"] = 1.77436;
  result["T1tttt_700_0"]["40"] = 1.82924;
  result["T1tttt_700_0"]["41"] = 1.72807;
  result["T1tttt_700_0"]["42"] = 2.12556;
  result["T1tttt_700_0"]["43"] = 1.91968;
  result["T1tttt_700_0"]["44"] = 1.55054;
  result["T1tttt_700_0"]["45"] = 1.53933;
  result["T1tttt_700_0"]["46"] = 1.5823;
  result["T1tttt_700_0"]["47"] = 1.53056;
  result["T1tttt_700_0"]["48"] = 1.53921;
  result["T1tttt_700_0"]["49"] = 1.88011;
  result["T1tttt_700_0"]["50"] = 1.96504;
  result["T1tttt_700_0"]["51"] = 1.58272;
  result["T1tttt_700_0"]["52"] = 1.7924;
  result["T1tttt_700_0"]["53"] = 1.99027;
  result["T1tttt_700_0"]["54"] = 1.65868;
  result["T1tttt_700_0"]["55"] = 2.05727;
  result["T1tttt_700_0"]["56"] = 2.27673;
  result["T1tttt_700_0"]["57"] = 1.53015;
  result["T1tttt_700_0"]["58"] = 2.00136;
  result["T1tttt_700_0"]["59"] = 1.4202;
  result["T1tttt_700_0"]["60"] = 2.24381;
  result["T1tttt_700_0"]["61"] = 1.8775;
  result["T1tttt_700_0"]["62"] = 1.50122;
  result["T1tttt_700_0"]["63"] = 1.9664;
  result["T1tttt_700_0"]["64"] = 2.72838;
  result["T1tttt_700_0"]["65"] = 1.69867;
  result["T1tttt_700_0"]["66"] = 2.66864;
  result["T1tttt_700_0"]["67"] = 1.58417;
  result["T1tttt_700_0"]["68"] = 1.77874;
  result["T1tttt_700_0"]["69"] = 1.96462;
  result["T1tttt_700_0"]["70"] = 1.69682;
  result["T1tttt_700_0"]["71"] = 1.95394;
  result["T1tttt_700_0"]["72"] = 1.74779;
  result["T1tttt_700_0"]["73"] = 2.12268;
  result["T1tttt_700_0"]["74"] = 1.77536;
  result["T1tttt_700_0"]["75"] = 1.81218;
  result["T1tttt_700_0"]["76"] = 1.92587;
  result["T1tttt_700_0"]["77"] = 2.52158;
  result["T1tttt_700_0"]["78"] = 1.80096;
  result["T1tttt_700_0"]["79"] = 1.87012;
  result["T1tttt_700_0"]["80"] = 1.58544;
  result["T1tttt_700_0"]["81"] = 1.90761;
  result["T1tttt_700_0"]["82"] = 2.24463;
  result["T1tttt_700_0"]["83"] = 2.01638;
  result["T1tttt_700_0"]["84"] = 1.57884;
  result["T1tttt_700_0"]["85"] = 1.97156;
  result["T1tttt_700_0"]["86"] = 2.08942;
  result["T1tttt_700_0"]["87"] = 1.9869;
  result["T1tttt_700_0"]["88"] = 1.47048;
  result["T1tttt_700_0"]["89"] = 1.77747;
  result["T1tttt_700_0"]["90"] = 1.82353;
  result["T1tttt_700_0"]["91"] = 1.76277;
  result["T1tttt_700_0"]["92"] = 1.95426;
  result["T1tttt_700_0"]["93"] = 1.70424;
  result["T1tttt_700_0"]["94"] = 1.86113;
  result["T1tttt_700_0"]["95"] = 1.95488;
  result["T1tttt_700_0"]["96"] = 1.84009;
  result["T1tttt_700_0"]["97"] = 2.36974;
  result["T1tttt_700_0"]["98"] = 2.57395;
  result["T1tttt_700_0"]["99"] = 1.84452;
  result["T1tttt_700_0"]["100"] = 1.93262;
  result["T1tttt_700_0"]["101"] = 1.53637;
  result["T1tttt_700_0"]["102"] = 1.60128;
  result["T1tttt_700_0"]["103"] = 1.56328;
  result["T1tttt_700_0"]["104"] = 2.19482;
  result["T1tttt_700_0"]["105"] = 1.62779;
  result["T1tttt_700_0"]["106"] = 1.92639;
  result["T1tttt_700_0"]["107"] = 1.63162;
  result["T1tttt_700_0"]["108"] = 2.17221;
  result["T1tttt_700_0"]["109"] = 1.96705;
  result["T1tttt_700_0"]["110"] = 1.65333;
  result["T1tttt_700_0"]["111"] = 1.86215;
  result["T1tttt_700_0"]["112"] = 1.8735;
  result["T1tttt_700_0"]["113"] = 1.87046;
  result["T1tttt_700_0"]["114"] = 1.8746;
  result["T1tttt_700_0"]["115"] = 1.85373;
  result["T1tttt_700_0"]["116"] = 1.85135;
  result["T1tttt_700_0"]["117"] = 1.88172;
  result["T1tttt_700_0"]["118"] = 1.91154;
  result["T1tttt_700_0"]["119"] = 1.81424;
  result["T1tttt_700_0"]["120"] = 1.87503;
  result["T1tttt_700_0"]["121"] = 1.86997;
  result["T1tttt_700_0"]["122"] = 1.87562;
  result["T1tttt_700_0"]["123"] = 1.85793;
  result["T1tttt_700_0"]["124"] = 1.94306;
  result["T1tttt_700_0"]["125"] = 1.82353;
  result["T1tttt_700_0"]["126"] = 1.87511;
  result["T1tttt_700_0"]["127"] = 1.85638;
  result["T1tttt_700_0"]["128"] = 1.97138;
  result["T1tttt_700_0"]["129"] = 1.87076;
  result["T1tttt_700_0"]["130"] = 1.77943;
  result["T1tttt_700_0"]["131"] = 1.87304;
  result["T1tttt_700_0"]["132"] = 1.81021;
  result["T1tttt_700_0"]["133"] = 1.85157;
  result["T1tttt_700_0"]["134"] = 1.70533;
  result["T1tttt_700_0"]["135"] = 2.00481;
  result["T1tttt_700_0"]["136"] = 1.855;
  result["T1tttt_700_0"]["137"] = 1.86626;
  result["T1tttt_700_0"]["138"] = 1.91877;
  result["T1tttt_700_0"]["139"] = 1.91217;
  result["T1tttt_700_0"]["140"] = 1.89574;
  result["T1tttt_700_0"]["141"] = 1.81967;
  result["T1tttt_700_0"]["142"] = 1.82056;
  result["T1tttt_700_0"]["143"] = 1.88687;
  result["T1tttt_700_0"]["144"] = 1.85562;
  result["T1tttt_700_0"]["145"] = 1.83961;
  result["T1tttt_700_0"]["146"] = 1.91266;
  result["T1tttt_700_0"]["147"] = 1.82809;
  result["T1tttt_700_0"]["148"] = 1.87902;
  result["T1tttt_700_0"]["149"] = 1.84466;
  result["T1tttt_700_0"]["150"] = 1.81341;
  result["T1tttt_700_0"]["151"] = 1.87012;
  result["T1tttt_700_0"]["152"] = 1.84977;
  result["T1tttt_700_0"]["153"] = 1.84038;
  result["T1tttt_700_0"]["154"] = 1.84517;
  result["T1tttt_700_0"]["155"] = 1.83535;
  result["T1tttt_700_0"]["156"] = 1.81367;
  result["T1tttt_700_0"]["157"] = 1.80878;
  result["T1tttt_700_0"]["158"] = 1.86434;
  result["T1tttt_700_0"]["159"] = 2.00149;
  result["T1tttt_700_0"]["160"] = 1.86904;
  result["T1tttt_700_0"]["161"] = 1.86687;
  result["T1tttt_700_0"]["162"] = 1.84772;
  result["T1tttt_700_0"]["163"] = 1.82024;
  result["T1tttt_700_0"]["164"] = 1.84161;
  result["T1tttt_700_0"]["165"] = 1.90281;
  result["T1tttt_700_0"]["166"] = 1.9237;
  result["T1tttt_700_0"]["167"] = 1.92838;
  result["T1tttt_700_0"]["168"] = 1.84099;
  result["T1tttt_700_0"]["169"] = 1.89295;
  result["T1tttt_700_0"]["170"] = 1.87405;
  result["T1tttt_700_0"]["171"] = 1.81577;
  result["T1tttt_700_0"]["172"] = 1.8815;
  result["T1tttt_700_0"]["173"] = 1.87354;
  result["T1tttt_700_0"]["174"] = 1.90801;
  result["T1tttt_700_0"]["175"] = 1.9494;
  result["T1tttt_700_0"]["176"] = 1.87439;
  result["T1tttt_700_0"]["177"] = 1.92543;
  result["T1tttt_700_0"]["178"] = 1.97852;
  result["T1tttt_700_0"]["179"] = 1.91481;
  result["T1tttt_700_0"]["180"] = 1.88643;
  result["T1tttt_700_0"]["181"] = 2.1368;
  result["T1tttt_700_0"]["182"] = 1.8984;
  result["T1tttt_700_0"]["183"] = 1.79293;
  result["T1tttt_700_0"]["184"] = 1.86533;
  result["T1tttt_700_0"]["185"] = 1.83477;
  result["T1tttt_700_0"]["186"] = 1.7607;
  result["T1tttt_700_0"]["187"] = 1.74997;
  result["T1tttt_700_0"]["188"] = 1.74812;
  result["T1tttt_700_0"]["189"] = 1.87288;
  result["T1tttt_700_0"]["190"] = 1.82348;
  result["T1tttt_700_0"]["191"] = 2.08301;
  result["T1tttt_700_0"]["192"] = 1.93229;
  result["T1tttt_700_0"]["193"] = 1.91939;
  result["T1tttt_700_0"]["194"] = 1.79566;
  result["T1tttt_700_0"]["195"] = 1.81528;
  result["T1tttt_700_0"]["196"] = 1.90107;
  result["T1tttt_700_0"]["197"] = 1.8562;
  result["T1tttt_700_0"]["198"] = 1.75547;
  result["T1tttt_700_0"]["199"] = 2.00185;
  result["T1tttt_700_0"]["200"] = 1.82844;
  result["T1tttt_700_0"]["201"] = 1.93735;
  result["T1tttt_700_0"]["202"] = 1.81786;
  result["T1tttt_700_0"]["203"] = 1.81298;
  result["T1tttt_700_0"]["204"] = 1.83352;
  result["T1tttt_700_0"]["205"] = 1.74868;
  result["T1tttt_700_0"]["206"] = 1.91687;
  result["T1tttt_700_0"]["207"] = 1.77833;
  result["T1tttt_700_0"]["208"] = 1.83593;
  result["T1tttt_700_0"]["209"] = 1.73453;
  result["T1tttt_700_0"]["210"] = 1.70778;
  result["T1tttt_700_0"]["211"] = 1.97906;
  result["T1tttt_700_0"]["212"] = 1.92347;
  result["T1tttt_700_0"]["213"] = 1.90897;
  result["T1tttt_700_0"]["214"] = 1.85223;
  result["T1tttt_700_0"]["215"] = 1.84057;
  result["T1tttt_700_0"]["216"] = 1.87351;
  result["T1tttt_700_0"]["217"] = 1.77887;
  result["T1tttt_700_0"]["218"] = 1.96007;
  result["T1tttt_700_0"]["219"] = 1.88662;
  result["T1tttt_700_0"]["220"] = 1.95012;
  result["T1tttt_700_0"]["221"] = 1.81889;
  result["T1tttt_700_0"]["222"] = 1.87338;
  result["T1tttt_700_0"]["223"] = 1.85103;
  result["T1tttt_700_0"]["224"] = 1.81606;
  result["T1tttt_700_0"]["225"] = 1.83459;
  result["T1tttt_700_0"]["226"] = 1.78597;
  result["T1tttt_700_0"]["227"] = 1.90099;
  result["T1tttt_700_0"]["228"] = 1.97678;
  result["T1tttt_700_0"]["229"] = 1.93887;
  result["T1tttt_700_0"]["230"] = 1.82473;
  result["T1tttt_700_0"]["231"] = 1.81379;
  result["T1tttt_700_0"]["232"] = 1.90026;
  result["T1tttt_700_0"]["233"] = 1.96237;
  result["T1tttt_700_0"]["234"] = 1.95919;
  result["T1tttt_700_0"]["235"] = 1.70763;
  result["T1tttt_700_0"]["236"] = 1.90326;
  result["T1tttt_700_0"]["237"] = 1.97906;
  result["T1tttt_700_0"]["238"] = 1.91872;
  result["T1tttt_700_0"]["239"] = 1.87882;
  result["T1tttt_700_0"]["240"] = 1.78318;
  result["T1tttt_700_0"]["241"] = 1.80428;
  result["T1tttt_700_0"]["242"] = 1.90339;
  result["T1tttt_700_0"]["243"] = 1.8391;
  result["T1tttt_700_0"]["244"] = 1.85308;
  result["T1tttt_700_0"]["245"] = 1.80113;
  result["T1tttt_700_0"]["246"] = 1.87826;
  result["T1tttt_700_0"]["247"] = 1.89131;
  result["T1tttt_700_0"]["248"] = 1.84728;
  result["T1tttt_700_0"]["249"] = 1.93562;
  result["T1tttt_700_0"]["250"] = 1.93342;
  result["T1tttt_700_0"]["251"] = 1.92757;
  result["T1tttt_700_0"]["252"] = 1.93886;
  result["T1tttt_700_0"]["253"] = 1.88559;
  result["T1tttt_700_0"]["254"] = 1.87922;
  result["T1tttt_700_0"]["255"] = 1.89315;
  result["T1tttt_700_0"]["256"] = 1.80068;
  result["T1tttt_700_0"]["257"] = 1.91089;
  result["T1tttt_700_0"]["258"] = 1.81588;
  result["T1tttt_700_0"]["259"] = 2.03563;
  result["T1tttt_700_0"]["260"] = 1.9151;
  result["T1tttt_700_0"]["261"] = 1.88571;
  result["T1tttt_700_0"]["262"] = 1.74288;
  result["T1tttt_700_0"]["263"] = 1.90155;
  result["T1tttt_700_0"]["264"] = 1.96591;
  result["T1tttt_700_0"]["265"] = 1.84148;
  result["T1tttt_700_0"]["266"] = 1.84137;
  result["T1tttt_700_0"]["267"] = 1.84158;
  result["T1tttt_700_0"]["268"] = 1.84338;
  result["T1tttt_700_0"]["269"] = 1.84011;
  result["T1tttt_700_0"]["270"] = 1.85004;
  result["T1tttt_700_0"]["271"] = 1.83323;
  result["T1tttt_700_0"]["272"] = 1.84375;
  result["T1tttt_700_0"]["273"] = 1.83877;
  result["T1tttt_700_0"]["274"] = 1.83645;
  result["T1tttt_700_0"]["275"] = 1.84774;
  result["T1tttt_700_0"]["276"] = 1.83841;
  result["T1tttt_700_0"]["277"] = 1.84763;
  result["T1tttt_700_0"]["278"] = 1.84198;
  result["T1tttt_700_0"]["279"] = 1.84079;
  result["T1tttt_700_0"]["280"] = 1.8469;
  result["T1tttt_700_0"]["281"] = 1.83777;
  result["T1tttt_700_0"]["282"] = 1.83956;
  result["T1tttt_700_0"]["283"] = 1.84359;
  result["T1tttt_700_0"]["284"] = 1.83464;
  result["T1tttt_700_0"]["285"] = 1.84673;
  result["T1tttt_700_0"]["286"] = 1.83685;
  result["T1tttt_700_0"]["287"] = 1.84621;
  result["T1tttt_700_0"]["288"] = 1.83422;
  result["T1tttt_700_0"]["289"] = 1.84796;
  result["T1tttt_700_0"]["290"] = 1.81758;
  result["T1tttt_700_0"]["291"] = 1.87135;
  result["T1tttt_700_0"]["292"] = 1.83338;
  result["T1tttt_700_0"]["293"] = 1.84272;
  result["T1tttt_700_0"]["294"] = 1.80162;
  result["T1tttt_700_0"]["295"] = 1.89053;
  result["T1tttt_700_0"]["296"] = 1.79184;
  result["T1tttt_700_0"]["297"] = 1.88443;
  result["T1tttt_700_0"]["298"] = 1.84223;
  result["T1tttt_700_0"]["299"] = 1.84106;
  result["T1tttt_700_0"]["300"] = 1.84903;
  result["T1tttt_700_0"]["301"] = 1.82287;
  result["T1tttt_700_0"]["302"] = 1.83562;
  result["T1tttt_700_0"]["303"] = 1.84284;
  result["T1tttt_700_0"]["304"] = 1.83059;
  result["T1tttt_700_0"]["305"] = 1.85168;
  result["T1tttt_700_0"]["306"] = 1.81421;
  result["T1tttt_700_0"]["307"] = 1.87674;
  result["T1tttt_700_0"]["308"] = 1.83828;
  result["T1tttt_700_0"]["309"] = 1.84461;
  result["T1tttt_700_0"]["310"] = 1.83589;
  result["T1tttt_700_0"]["311"] = 1.85621;
  result["T1tttt_700_0"]["312"] = 1.8261;
  result["T1tttt_700_0"]["313"] = 1.88362;
  result["T1tttt_700_0"]["314"] = 1.83468;
  result["T1tttt_700_0"]["315"] = 1.84659;
  result["T1tttt_700_475"]["1"] = 2.01664;
  result["T1tttt_700_475"]["2"] = 1.76493;
  result["T1tttt_700_475"]["3"] = 2.33392;
  result["T1tttt_700_475"]["4"] = 1.7236;
  result["T1tttt_700_475"]["5"] = 1.50852;
  result["T1tttt_700_475"]["6"] = 1.9949;
  result["T1tttt_700_475"]["7"] = 2.39107;
  result["T1tttt_700_475"]["8"] = 2.09276;
  result["T1tttt_700_475"]["9"] = 2.76734;
  result["T1tttt_700_475"]["10"] = 2.01664;
  result["T1tttt_700_475"]["11"] = 1.74514;
  result["T1tttt_700_475"]["12"] = 1.51889;
  result["T1tttt_700_475"]["13"] = 2.03619;
  result["T1tttt_700_475"]["14"] = 2.11614;
  result["T1tttt_700_475"]["15"] = 1.73259;
  result["T1tttt_700_475"]["16"] = 1.7415;
  result["T1tttt_700_475"]["17"] = 2.40569;
  result["T1tttt_700_475"]["18"] = 1.69203;
  result["T1tttt_700_475"]["19"] = 2.20758;
  result["T1tttt_700_475"]["20"] = 1.43589;
  result["T1tttt_700_475"]["21"] = 1.69363;
  result["T1tttt_700_475"]["22"] = 1.64035;
  result["T1tttt_700_475"]["23"] = 1.97725;
  result["T1tttt_700_475"]["24"] = 2.45431;
  result["T1tttt_700_475"]["25"] = 1.94236;
  result["T1tttt_700_475"]["26"] = 1.63518;
  result["T1tttt_700_475"]["27"] = 2.30383;
  result["T1tttt_700_475"]["28"] = 2.50604;
  result["T1tttt_700_475"]["29"] = 2.16126;
  result["T1tttt_700_475"]["30"] = 1.89366;
  result["T1tttt_700_475"]["31"] = 2.22758;
  result["T1tttt_700_475"]["32"] = 1.77902;
  result["T1tttt_700_475"]["33"] = 1.94522;
  result["T1tttt_700_475"]["34"] = 1.66006;
  result["T1tttt_700_475"]["35"] = 2.55355;
  result["T1tttt_700_475"]["36"] = 2.32914;
  result["T1tttt_700_475"]["37"] = 2.30658;
  result["T1tttt_700_475"]["38"] = 2.19544;
  result["T1tttt_700_475"]["39"] = 1.93666;
  result["T1tttt_700_475"]["40"] = 1.99396;
  result["T1tttt_700_475"]["41"] = 1.8853;
  result["T1tttt_700_475"]["42"] = 2.31389;
  result["T1tttt_700_475"]["43"] = 2.09396;
  result["T1tttt_700_475"]["44"] = 1.68824;
  result["T1tttt_700_475"]["45"] = 1.67936;
  result["T1tttt_700_475"]["46"] = 1.72475;
  result["T1tttt_700_475"]["47"] = 1.66863;
  result["T1tttt_700_475"]["48"] = 1.68124;
  result["T1tttt_700_475"]["49"] = 2.04869;
  result["T1tttt_700_475"]["50"] = 2.14465;
  result["T1tttt_700_475"]["51"] = 1.72385;
  result["T1tttt_700_475"]["52"] = 1.95453;
  result["T1tttt_700_475"]["53"] = 2.16464;
  result["T1tttt_700_475"]["54"] = 1.80959;
  result["T1tttt_700_475"]["55"] = 2.2394;
  result["T1tttt_700_475"]["56"] = 2.48236;
  result["T1tttt_700_475"]["57"] = 1.67208;
  result["T1tttt_700_475"]["58"] = 2.18516;
  result["T1tttt_700_475"]["59"] = 1.5478;
  result["T1tttt_700_475"]["60"] = 2.44938;
  result["T1tttt_700_475"]["61"] = 2.04631;
  result["T1tttt_700_475"]["62"] = 1.63793;
  result["T1tttt_700_475"]["63"] = 2.1404;
  result["T1tttt_700_475"]["64"] = 2.96993;
  result["T1tttt_700_475"]["65"] = 1.85535;
  result["T1tttt_700_475"]["66"] = 2.90415;
  result["T1tttt_700_475"]["67"] = 1.72822;
  result["T1tttt_700_475"]["68"] = 1.94198;
  result["T1tttt_700_475"]["69"] = 2.13748;
  result["T1tttt_700_475"]["70"] = 1.85068;
  result["T1tttt_700_475"]["71"] = 2.12626;
  result["T1tttt_700_475"]["72"] = 1.91133;
  result["T1tttt_700_475"]["73"] = 2.308;
  result["T1tttt_700_475"]["74"] = 1.93961;
  result["T1tttt_700_475"]["75"] = 1.9757;
  result["T1tttt_700_475"]["76"] = 2.09768;
  result["T1tttt_700_475"]["77"] = 2.74163;
  result["T1tttt_700_475"]["78"] = 1.96466;
  result["T1tttt_700_475"]["79"] = 2.03709;
  result["T1tttt_700_475"]["80"] = 1.72887;
  result["T1tttt_700_475"]["81"] = 2.07643;
  result["T1tttt_700_475"]["82"] = 2.4427;
  result["T1tttt_700_475"]["83"] = 2.19349;
  result["T1tttt_700_475"]["84"] = 1.72114;
  result["T1tttt_700_475"]["85"] = 2.14781;
  result["T1tttt_700_475"]["86"] = 2.27423;
  result["T1tttt_700_475"]["87"] = 2.1677;
  result["T1tttt_700_475"]["88"] = 1.60561;
  result["T1tttt_700_475"]["89"] = 1.93774;
  result["T1tttt_700_475"]["90"] = 1.9887;
  result["T1tttt_700_475"]["91"] = 1.92421;
  result["T1tttt_700_475"]["92"] = 2.13487;
  result["T1tttt_700_475"]["93"] = 1.85825;
  result["T1tttt_700_475"]["94"] = 2.03138;
  result["T1tttt_700_475"]["95"] = 2.12937;
  result["T1tttt_700_475"]["96"] = 2.00688;
  result["T1tttt_700_475"]["97"] = 2.57977;
  result["T1tttt_700_475"]["98"] = 2.80087;
  result["T1tttt_700_475"]["99"] = 2.00984;
  result["T1tttt_700_475"]["100"] = 2.10571;
  result["T1tttt_700_475"]["101"] = 1.674;
  result["T1tttt_700_475"]["102"] = 1.7487;
  result["T1tttt_700_475"]["103"] = 1.70716;
  result["T1tttt_700_475"]["104"] = 2.38234;
  result["T1tttt_700_475"]["105"] = 1.77677;
  result["T1tttt_700_475"]["106"] = 2.09739;
  result["T1tttt_700_475"]["107"] = 1.77892;
  result["T1tttt_700_475"]["108"] = 2.36437;
  result["T1tttt_700_475"]["109"] = 2.14193;
  result["T1tttt_700_475"]["110"] = 1.80361;
  result["T1tttt_700_475"]["111"] = 2.02844;
  result["T1tttt_700_475"]["112"] = 2.04399;
  result["T1tttt_700_475"]["113"] = 2.0229;
  result["T1tttt_700_475"]["114"] = 2.03887;
  result["T1tttt_700_475"]["115"] = 2.01904;
  result["T1tttt_700_475"]["116"] = 2.00861;
  result["T1tttt_700_475"]["117"] = 2.04939;
  result["T1tttt_700_475"]["118"] = 2.10145;
  result["T1tttt_700_475"]["119"] = 1.96557;
  result["T1tttt_700_475"]["120"] = 2.03415;
  result["T1tttt_700_475"]["121"] = 2.03155;
  result["T1tttt_700_475"]["122"] = 2.03479;
  result["T1tttt_700_475"]["123"] = 2.0269;
  result["T1tttt_700_475"]["124"] = 2.11365;
  result["T1tttt_700_475"]["125"] = 1.94581;
  result["T1tttt_700_475"]["126"] = 2.03421;
  result["T1tttt_700_475"]["127"] = 2.02655;
  result["T1tttt_700_475"]["128"] = 2.10257;
  result["T1tttt_700_475"]["129"] = 2.01863;
  result["T1tttt_700_475"]["130"] = 1.94397;
  result["T1tttt_700_475"]["131"] = 2.0536;
  result["T1tttt_700_475"]["132"] = 1.97535;
  result["T1tttt_700_475"]["133"] = 2.04682;
  result["T1tttt_700_475"]["134"] = 1.85033;
  result["T1tttt_700_475"]["135"] = 2.24167;
  result["T1tttt_700_475"]["136"] = 2.01889;
  result["T1tttt_700_475"]["137"] = 2.04224;
  result["T1tttt_700_475"]["138"] = 2.04137;
  result["T1tttt_700_475"]["139"] = 2.06678;
  result["T1tttt_700_475"]["140"] = 2.05931;
  result["T1tttt_700_475"]["141"] = 2.00022;
  result["T1tttt_700_475"]["142"] = 1.99033;
  result["T1tttt_700_475"]["143"] = 2.05838;
  result["T1tttt_700_475"]["144"] = 2.02937;
  result["T1tttt_700_475"]["145"] = 2.04425;
  result["T1tttt_700_475"]["146"] = 2.0632;
  result["T1tttt_700_475"]["147"] = 1.99757;
  result["T1tttt_700_475"]["148"] = 2.0341;
  result["T1tttt_700_475"]["149"] = 2.02433;
  result["T1tttt_700_475"]["150"] = 1.98372;
  result["T1tttt_700_475"]["151"] = 2.05663;
  result["T1tttt_700_475"]["152"] = 2.04179;
  result["T1tttt_700_475"]["153"] = 2.00623;
  result["T1tttt_700_475"]["154"] = 2.03251;
  result["T1tttt_700_475"]["155"] = 2.00602;
  result["T1tttt_700_475"]["156"] = 1.99914;
  result["T1tttt_700_475"]["157"] = 2.01463;
  result["T1tttt_700_475"]["158"] = 2.01021;
  result["T1tttt_700_475"]["159"] = 2.20635;
  result["T1tttt_700_475"]["160"] = 2.031;
  result["T1tttt_700_475"]["161"] = 2.03572;
  result["T1tttt_700_475"]["162"] = 2.01946;
  result["T1tttt_700_475"]["163"] = 1.96896;
  result["T1tttt_700_475"]["164"] = 2.02403;
  result["T1tttt_700_475"]["165"] = 2.05448;
  result["T1tttt_700_475"]["166"] = 2.1084;
  result["T1tttt_700_475"]["167"] = 2.08508;
  result["T1tttt_700_475"]["168"] = 2.01514;
  result["T1tttt_700_475"]["169"] = 2.06675;
  result["T1tttt_700_475"]["170"] = 2.05043;
  result["T1tttt_700_475"]["171"] = 1.98354;
  result["T1tttt_700_475"]["172"] = 2.05585;
  result["T1tttt_700_475"]["173"] = 2.06581;
  result["T1tttt_700_475"]["174"] = 2.07541;
  result["T1tttt_700_475"]["175"] = 2.10812;
  result["T1tttt_700_475"]["176"] = 2.02421;
  result["T1tttt_700_475"]["177"] = 2.1175;
  result["T1tttt_700_475"]["178"] = 2.18716;
  result["T1tttt_700_475"]["179"] = 2.08566;
  result["T1tttt_700_475"]["180"] = 2.02836;
  result["T1tttt_700_475"]["181"] = 2.35239;
  result["T1tttt_700_475"]["182"] = 2.10623;
  result["T1tttt_700_475"]["183"] = 1.94149;
  result["T1tttt_700_475"]["184"] = 2.00348;
  result["T1tttt_700_475"]["185"] = 1.98074;
  result["T1tttt_700_475"]["186"] = 1.89361;
  result["T1tttt_700_475"]["187"] = 1.9123;
  result["T1tttt_700_475"]["188"] = 1.90102;
  result["T1tttt_700_475"]["189"] = 2.0351;
  result["T1tttt_700_475"]["190"] = 1.99099;
  result["T1tttt_700_475"]["191"] = 2.31716;
  result["T1tttt_700_475"]["192"] = 2.13718;
  result["T1tttt_700_475"]["193"] = 2.10172;
  result["T1tttt_700_475"]["194"] = 1.93332;
  result["T1tttt_700_475"]["195"] = 1.97345;
  result["T1tttt_700_475"]["196"] = 2.05884;
  result["T1tttt_700_475"]["197"] = 2.00451;
  result["T1tttt_700_475"]["198"] = 1.86425;
  result["T1tttt_700_475"]["199"] = 2.19174;
  result["T1tttt_700_475"]["200"] = 1.9798;
  result["T1tttt_700_475"]["201"] = 2.11122;
  result["T1tttt_700_475"]["202"] = 1.96109;
  result["T1tttt_700_475"]["203"] = 1.9692;
  result["T1tttt_700_475"]["204"] = 1.97843;
  result["T1tttt_700_475"]["205"] = 1.90666;
  result["T1tttt_700_475"]["206"] = 2.04107;
  result["T1tttt_700_475"]["207"] = 1.91768;
  result["T1tttt_700_475"]["208"] = 1.99324;
  result["T1tttt_700_475"]["209"] = 1.88896;
  result["T1tttt_700_475"]["210"] = 1.81279;
  result["T1tttt_700_475"]["211"] = 2.14731;
  result["T1tttt_700_475"]["212"] = 2.10581;
  result["T1tttt_700_475"]["213"] = 2.07381;
  result["T1tttt_700_475"]["214"] = 2.01818;
  result["T1tttt_700_475"]["215"] = 1.99577;
  result["T1tttt_700_475"]["216"] = 2.04401;
  result["T1tttt_700_475"]["217"] = 1.92297;
  result["T1tttt_700_475"]["218"] = 2.15007;
  result["T1tttt_700_475"]["219"] = 2.0417;
  result["T1tttt_700_475"]["220"] = 2.15604;
  result["T1tttt_700_475"]["221"] = 1.97232;
  result["T1tttt_700_475"]["222"] = 2.04361;
  result["T1tttt_700_475"]["223"] = 2.00453;
  result["T1tttt_700_475"]["224"] = 1.96555;
  result["T1tttt_700_475"]["225"] = 1.97093;
  result["T1tttt_700_475"]["226"] = 1.93706;
  result["T1tttt_700_475"]["227"] = 2.07856;
  result["T1tttt_700_475"]["228"] = 2.17585;
  result["T1tttt_700_475"]["229"] = 2.1181;
  result["T1tttt_700_475"]["230"] = 1.98521;
  result["T1tttt_700_475"]["231"] = 1.97985;
  result["T1tttt_700_475"]["232"] = 2.06995;
  result["T1tttt_700_475"]["233"] = 2.16234;
  result["T1tttt_700_475"]["234"] = 2.14452;
  result["T1tttt_700_475"]["235"] = 1.86529;
  result["T1tttt_700_475"]["236"] = 2.02969;
  result["T1tttt_700_475"]["237"] = 2.17732;
  result["T1tttt_700_475"]["238"] = 2.09644;
  result["T1tttt_700_475"]["239"] = 2.05444;
  result["T1tttt_700_475"]["240"] = 1.91957;
  result["T1tttt_700_475"]["241"] = 1.94572;
  result["T1tttt_700_475"]["242"] = 2.07962;
  result["T1tttt_700_475"]["243"] = 1.99649;
  result["T1tttt_700_475"]["244"] = 2.00659;
  result["T1tttt_700_475"]["245"] = 1.95004;
  result["T1tttt_700_475"]["246"] = 2.03866;
  result["T1tttt_700_475"]["247"] = 2.0607;
  result["T1tttt_700_475"]["248"] = 2.01102;
  result["T1tttt_700_475"]["249"] = 2.11915;
  result["T1tttt_700_475"]["250"] = 2.1151;
  result["T1tttt_700_475"]["251"] = 2.11941;
  result["T1tttt_700_475"]["252"] = 2.11605;
  result["T1tttt_700_475"]["253"] = 2.05253;
  result["T1tttt_700_475"]["254"] = 2.05533;
  result["T1tttt_700_475"]["255"] = 2.06456;
  result["T1tttt_700_475"]["256"] = 1.95192;
  result["T1tttt_700_475"]["257"] = 2.09224;
  result["T1tttt_700_475"]["258"] = 1.95179;
  result["T1tttt_700_475"]["259"] = 2.25192;
  result["T1tttt_700_475"]["260"] = 2.04876;
  result["T1tttt_700_475"]["261"] = 2.05109;
  result["T1tttt_700_475"]["262"] = 1.87192;
  result["T1tttt_700_475"]["263"] = 2.07889;
  result["T1tttt_700_475"]["264"] = 2.17041;
  result["T1tttt_700_475"]["265"] = 2.007;
  result["T1tttt_700_475"]["266"] = 2.00686;
  result["T1tttt_700_475"]["267"] = 2.00714;
  result["T1tttt_700_475"]["268"] = 2.00906;
  result["T1tttt_700_475"]["269"] = 2.00552;
  result["T1tttt_700_475"]["270"] = 2.01629;
  result["T1tttt_700_475"]["271"] = 1.99806;
  result["T1tttt_700_475"]["272"] = 2.0095;
  result["T1tttt_700_475"]["273"] = 2.00401;
  result["T1tttt_700_475"]["274"] = 2.0016;
  result["T1tttt_700_475"]["275"] = 2.01372;
  result["T1tttt_700_475"]["276"] = 2.00351;
  result["T1tttt_700_475"]["277"] = 2.01401;
  result["T1tttt_700_475"]["278"] = 2.00755;
  result["T1tttt_700_475"]["279"] = 2.00625;
  result["T1tttt_700_475"]["280"] = 2.01298;
  result["T1tttt_700_475"]["281"] = 2.0029;
  result["T1tttt_700_475"]["282"] = 2.00507;
  result["T1tttt_700_475"]["283"] = 2.00912;
  result["T1tttt_700_475"]["284"] = 1.99951;
  result["T1tttt_700_475"]["285"] = 2.01274;
  result["T1tttt_700_475"]["286"] = 2.0017;
  result["T1tttt_700_475"]["287"] = 2.01243;
  result["T1tttt_700_475"]["288"] = 1.99897;
  result["T1tttt_700_475"]["289"] = 2.01417;
  result["T1tttt_700_475"]["290"] = 1.98108;
  result["T1tttt_700_475"]["291"] = 2.0394;
  result["T1tttt_700_475"]["292"] = 1.99818;
  result["T1tttt_700_475"]["293"] = 2.00817;
  result["T1tttt_700_475"]["294"] = 1.96395;
  result["T1tttt_700_475"]["295"] = 2.05999;
  result["T1tttt_700_475"]["296"] = 1.95334;
  result["T1tttt_700_475"]["297"] = 2.0534;
  result["T1tttt_700_475"]["298"] = 2.00779;
  result["T1tttt_700_475"]["299"] = 2.00659;
  result["T1tttt_700_475"]["300"] = 2.01522;
  result["T1tttt_700_475"]["301"] = 1.98674;
  result["T1tttt_700_475"]["302"] = 2.00052;
  result["T1tttt_700_475"]["303"] = 2.00854;
  result["T1tttt_700_475"]["304"] = 1.99511;
  result["T1tttt_700_475"]["305"] = 2.01809;
  result["T1tttt_700_475"]["306"] = 1.97729;
  result["T1tttt_700_475"]["307"] = 2.04539;
  result["T1tttt_700_475"]["308"] = 2.00346;
  result["T1tttt_700_475"]["309"] = 2.01058;
  result["T1tttt_700_475"]["310"] = 2.0013;
  result["T1tttt_700_475"]["311"] = 2.023;
  result["T1tttt_700_475"]["312"] = 1.99051;
  result["T1tttt_700_475"]["313"] = 2.05239;
  result["T1tttt_700_475"]["314"] = 1.99966;
  result["T1tttt_700_475"]["315"] = 2.01247;
  
  //Spring 15 WZ
  result["Tree_WZTo3LNu_0"]["1001"] = 1.9808e+06;
  result["Tree_WZTo3LNu_0"]["1002"] = 2.03422e+06;
  result["Tree_WZTo3LNu_0"]["1003"] = 1.90614e+06;
  result["Tree_WZTo3LNu_0"]["1004"] = 1.93424e+06;
  result["Tree_WZTo3LNu_0"]["1005"] = 1.99359e+06;
  result["Tree_WZTo3LNu_0"]["1006"] = 1.85366e+06;
  result["Tree_WZTo3LNu_0"]["1007"] = 2.03843e+06;
  result["Tree_WZTo3LNu_0"]["1008"] = 2.08513e+06;
  result["Tree_WZTo3LNu_0"]["1009"] = 1.97086e+06;
  result["Tree_WZTo3LNu_0"]["2001"] = 1.8659e+06;
  result["Tree_WZTo3LNu_0"]["2002"] = 1.96964e+06;
  result["Tree_WZTo3LNu_0"]["2003"] = 2.00983e+06;
  result["Tree_WZTo3LNu_0"]["2004"] = 2.0028e+06;
  result["Tree_WZTo3LNu_0"]["2005"] = 1.83934e+06;
  result["Tree_WZTo3LNu_0"]["2006"] = 1.945e+06;
  result["Tree_WZTo3LNu_0"]["2007"] = 1.98898e+06;
  result["Tree_WZTo3LNu_0"]["2008"] = 1.96814e+06;
  result["Tree_WZTo3LNu_0"]["2009"] = 1.99015e+06;
  result["Tree_WZTo3LNu_0"]["2010"] = 2.01809e+06;
  result["Tree_WZTo3LNu_0"]["2011"] = 1.9656e+06;
  result["Tree_WZTo3LNu_0"]["2012"] = 1.97351e+06;
  result["Tree_WZTo3LNu_0"]["2013"] = 2.00365e+06;
  result["Tree_WZTo3LNu_0"]["2014"] = 1.99608e+06;
  result["Tree_WZTo3LNu_0"]["2015"] = 1.98793e+06;
  result["Tree_WZTo3LNu_0"]["2016"] = 1.9587e+06;
  result["Tree_WZTo3LNu_0"]["2017"] = 1.96582e+06;
  result["Tree_WZTo3LNu_0"]["2018"] = 1.92976e+06;
  result["Tree_WZTo3LNu_0"]["2019"] = 1.97844e+06;
  result["Tree_WZTo3LNu_0"]["2020"] = 1.97218e+06;
  result["Tree_WZTo3LNu_0"]["2021"] = 2.0307e+06;
  result["Tree_WZTo3LNu_0"]["2022"] = 1.98778e+06;
  result["Tree_WZTo3LNu_0"]["2023"] = 2.0549e+06;
  result["Tree_WZTo3LNu_0"]["2024"] = 2.00615e+06;
  result["Tree_WZTo3LNu_0"]["2025"] = 1.9804e+06;
  result["Tree_WZTo3LNu_0"]["2026"] = 2.00242e+06;
  result["Tree_WZTo3LNu_0"]["2027"] = 1.94873e+06;
  result["Tree_WZTo3LNu_0"]["2028"] = 1.98662e+06;
  result["Tree_WZTo3LNu_0"]["2029"] = 1.95878e+06;
  result["Tree_WZTo3LNu_0"]["2030"] = 1.98769e+06;
  result["Tree_WZTo3LNu_0"]["2031"] = 2.01881e+06;
  result["Tree_WZTo3LNu_0"]["2032"] = 2.00469e+06;
  result["Tree_WZTo3LNu_0"]["2033"] = 2.00287e+06;
  result["Tree_WZTo3LNu_0"]["2034"] = 1.9996e+06;
  result["Tree_WZTo3LNu_0"]["2035"] = 2.03184e+06;
  result["Tree_WZTo3LNu_0"]["2036"] = 1.96817e+06;
  result["Tree_WZTo3LNu_0"]["2037"] = 1.96846e+06;
  result["Tree_WZTo3LNu_0"]["2038"] = 1.94151e+06;
  result["Tree_WZTo3LNu_0"]["2039"] = 1.94761e+06;
  result["Tree_WZTo3LNu_0"]["2040"] = 1.99093e+06;
  result["Tree_WZTo3LNu_0"]["2041"] = 1.99775e+06;
  result["Tree_WZTo3LNu_0"]["2042"] = 1.98959e+06;
  result["Tree_WZTo3LNu_0"]["2043"] = 1.99664e+06;
  result["Tree_WZTo3LNu_0"]["2044"] = 1.98657e+06;
  result["Tree_WZTo3LNu_0"]["2045"] = 2.0188e+06;
  result["Tree_WZTo3LNu_0"]["2046"] = 1.97436e+06;
  result["Tree_WZTo3LNu_0"]["2047"] = 1.96148e+06;
  result["Tree_WZTo3LNu_0"]["2048"] = 1.96824e+06;
  result["Tree_WZTo3LNu_0"]["2049"] = 1.95486e+06;
  result["Tree_WZTo3LNu_0"]["2050"] = 1.99499e+06;
  result["Tree_WZTo3LNu_0"]["2051"] = 1.99488e+06;
  result["Tree_WZTo3LNu_0"]["2052"] = 1.9766e+06;
  result["Tree_WZTo3LNu_0"]["2053"] = 2.00378e+06;
  result["Tree_WZTo3LNu_0"]["2054"] = 2.00327e+06;
  result["Tree_WZTo3LNu_0"]["2055"] = 1.99731e+06;
  result["Tree_WZTo3LNu_0"]["2056"] = 1.94987e+06;
  result["Tree_WZTo3LNu_0"]["2057"] = 1.97651e+06;
  result["Tree_WZTo3LNu_0"]["2058"] = 1.98848e+06;
  result["Tree_WZTo3LNu_0"]["2059"] = 1.99184e+06;
  result["Tree_WZTo3LNu_0"]["2060"] = 1.99511e+06;
  result["Tree_WZTo3LNu_0"]["2061"] = 1.97461e+06;
  result["Tree_WZTo3LNu_0"]["2062"] = 1.97706e+06;
  result["Tree_WZTo3LNu_0"]["2063"] = 1.98625e+06;
  result["Tree_WZTo3LNu_0"]["2064"] = 1.94142e+06;
  result["Tree_WZTo3LNu_0"]["2065"] = 2.01557e+06;
  result["Tree_WZTo3LNu_0"]["2066"] = 1.98823e+06;
  result["Tree_WZTo3LNu_0"]["2067"] = 2.07463e+06;
  result["Tree_WZTo3LNu_0"]["2068"] = 1.9935e+06;
  result["Tree_WZTo3LNu_0"]["2069"] = 1.98085e+06;
  result["Tree_WZTo3LNu_0"]["2070"] = 1.97523e+06;
  result["Tree_WZTo3LNu_0"]["2071"] = 1.99379e+06;
  result["Tree_WZTo3LNu_0"]["2072"] = 1.96917e+06;
  result["Tree_WZTo3LNu_0"]["2073"] = 1.91919e+06;
  result["Tree_WZTo3LNu_0"]["2074"] = 2.0233e+06;
  result["Tree_WZTo3LNu_0"]["2075"] = 1.96589e+06;
  result["Tree_WZTo3LNu_0"]["2076"] = 1.98558e+06;
  result["Tree_WZTo3LNu_0"]["2077"] = 1.9927e+06;
  result["Tree_WZTo3LNu_0"]["2078"] = 2.00414e+06;
  result["Tree_WZTo3LNu_0"]["2079"] = 1.96948e+06;
  result["Tree_WZTo3LNu_0"]["2080"] = 1.99112e+06;
  result["Tree_WZTo3LNu_0"]["2081"] = 2.01495e+06;
  result["Tree_WZTo3LNu_0"]["2082"] = 1.98881e+06;
  result["Tree_WZTo3LNu_0"]["2083"] = 1.9566e+06;
  result["Tree_WZTo3LNu_0"]["2084"] = 1.98552e+06;
  result["Tree_WZTo3LNu_0"]["2085"] = 1.96786e+06;
  result["Tree_WZTo3LNu_0"]["2086"] = 1.97867e+06;
  result["Tree_WZTo3LNu_0"]["2087"] = 1.99706e+06;
  result["Tree_WZTo3LNu_0"]["2088"] = 1.97748e+06;
  result["Tree_WZTo3LNu_0"]["2089"] = 1.96337e+06;
  result["Tree_WZTo3LNu_0"]["2090"] = 1.99598e+06;
  result["Tree_WZTo3LNu_0"]["2091"] = 1.98686e+06;
  result["Tree_WZTo3LNu_0"]["2092"] = 1.9803e+06;
  result["Tree_WZTo3LNu_0"]["2093"] = 1.96085e+06;
  result["Tree_WZTo3LNu_0"]["2094"] = 1.9896e+06;
  result["Tree_WZTo3LNu_0"]["2095"] = 1.92911e+06;
  result["Tree_WZTo3LNu_0"]["2096"] = 1.98904e+06;
  result["Tree_WZTo3LNu_0"]["2097"] = 1.98455e+06;
  result["Tree_WZTo3LNu_0"]["2098"] = 2.00997e+06;
  result["Tree_WZTo3LNu_0"]["2099"] = 1.99055e+06;
  result["Tree_WZTo3LNu_0"]["2100"] = 1.9146e+06;
  result["Tree_WZTo3LNu_0"]["2101"] = 1.96496e+06;
  result["Tree_WZTo3LNu_0"]["2102"] = 1.99206e+06;
  result["Tree_WZTo3LNu_0"]["3001"] = 2.0201e+06;
  result["Tree_WZTo3LNu_0"]["3002"] = 1.99899e+06;
  result["Tree_WZTo3LNu_0"]["3003"] = 2.0397e+06;
  result["Tree_WZTo3LNu_0"]["3004"] = 2.00863e+06;
  result["Tree_WZTo3LNu_0"]["3005"] = 2.03196e+06;
  result["Tree_WZTo3LNu_0"]["3006"] = 2.00968e+06;
  result["Tree_WZTo3LNu_0"]["3007"] = 2.02928e+06;
  result["Tree_WZTo3LNu_0"]["3008"] = 1.98075e+06;
  result["Tree_WZTo3LNu_0"]["3009"] = 2.05646e+06;
  result["Tree_WZTo3LNu_0"]["3010"] = 2.01444e+06;
  result["Tree_WZTo3LNu_0"]["3011"] = 2.02708e+06;
  result["Tree_WZTo3LNu_0"]["3012"] = 2.01463e+06;
  result["Tree_WZTo3LNu_0"]["3013"] = 2.02318e+06;
  result["Tree_WZTo3LNu_0"]["3014"] = 1.99939e+06;
  result["Tree_WZTo3LNu_0"]["3015"] = 2.04734e+06;
  result["Tree_WZTo3LNu_0"]["3016"] = 2.02208e+06;
  result["Tree_WZTo3LNu_0"]["3017"] = 2.01718e+06;
  result["Tree_WZTo3LNu_0"]["3018"] = 2.01017e+06;
  result["Tree_WZTo3LNu_0"]["3019"] = 2.02332e+06;
  result["Tree_WZTo3LNu_0"]["3020"] = 2.01271e+06;
  result["Tree_WZTo3LNu_0"]["3021"] = 2.02096e+06;
  result["Tree_WZTo3LNu_0"]["3022"] = 2.01415e+06;
  result["Tree_WZTo3LNu_0"]["3023"] = 2.02246e+06;
  result["Tree_WZTo3LNu_0"]["3024"] = 2.03143e+06;
  result["Tree_WZTo3LNu_0"]["3025"] = 1.98981e+06;
  result["Tree_WZTo3LNu_0"]["3026"] = 2.02275e+06;
  result["Tree_WZTo3LNu_0"]["3027"] = 2.0124e+06;
  result["Tree_WZTo3LNu_0"]["3028"] = 2.02138e+06;
  result["Tree_WZTo3LNu_0"]["3029"] = 2.01695e+06;
  result["Tree_WZTo3LNu_0"]["3030"] = 2.01759e+06;
  result["Tree_WZTo3LNu_0"]["3031"] = 2.02141e+06;
  result["Tree_WZTo3LNu_0"]["3032"] = 2.02006e+06;
  result["Tree_WZTo3LNu_0"]["3033"] = 2.02153e+06;
  result["Tree_WZTo3LNu_0"]["3034"] = 2.00701e+06;
  result["Tree_WZTo3LNu_0"]["3035"] = 2.01832e+06;
  result["Tree_WZTo3LNu_0"]["3036"] = 2.00409e+06;
  result["Tree_WZTo3LNu_0"]["3037"] = 2.0261e+06;
  result["Tree_WZTo3LNu_0"]["3038"] = 2.02331e+06;
  result["Tree_WZTo3LNu_0"]["3039"] = 2.01949e+06;
  result["Tree_WZTo3LNu_0"]["3040"] = 2.03491e+06;
  result["Tree_WZTo3LNu_0"]["3041"] = 2.00642e+06;
  result["Tree_WZTo3LNu_0"]["3042"] = 2.02833e+06;
  result["Tree_WZTo3LNu_0"]["3043"] = 2.0162e+06;
  result["Tree_WZTo3LNu_0"]["3044"] = 2.01966e+06;
  result["Tree_WZTo3LNu_0"]["3045"] = 2.02188e+06;
  result["Tree_WZTo3LNu_0"]["3046"] = 2.02024e+06;
  result["Tree_WZTo3LNu_0"]["3047"] = 2.03548e+06;
  result["Tree_WZTo3LNu_0"]["3048"] = 2.01807e+06;
  result["Tree_WZTo3LNu_0"]["3049"] = 1.99279e+06;
  result["Tree_WZTo3LNu_0"]["3050"] = 2.01478e+06;
  result["Tree_WZTo3LNu_0"]["3051"] = 2.01008e+06;
  result["Tree_WZTo3LNu_0"]["3052"] = 2.01192e+06;
  result["Tree_WZTo3LNu_0"]["3053"] = 2.01539e+06;
  result["Tree_WZTo3LNu_0"]["3054"] = 2.00738e+06;
  result["Tree_WZTo3LNu_0"]["3055"] = 2.03272e+06;
  result["Tree_WZTo3LNu_0"]["4001"] = 1.9932e+06;
  result["Tree_WZTo3LNu_0"]["4002"] = 1.99418e+06;
  result["Tree_WZTo3LNu_0"]["4003"] = 1.99215e+06;
  result["Tree_WZTo3LNu_0"]["4004"] = 1.98741e+06;
  result["Tree_WZTo3LNu_0"]["4005"] = 1.99711e+06;
  result["Tree_WZTo3LNu_0"]["4006"] = 1.98664e+06;
  result["Tree_WZTo3LNu_0"]["4007"] = 1.99929e+06;
  result["Tree_WZTo3LNu_0"]["4008"] = 1.99212e+06;
  result["Tree_WZTo3LNu_0"]["4009"] = 1.99436e+06;
  result["Tree_WZTo3LNu_0"]["4010"] = 1.99232e+06;
  result["Tree_WZTo3LNu_0"]["4011"] = 1.99404e+06;
  result["Tree_WZTo3LNu_0"]["4012"] = 1.99346e+06;
  result["Tree_WZTo3LNu_0"]["4013"] = 1.99263e+06;
  result["Tree_WZTo3LNu_0"]["4014"] = 1.99239e+06;
  result["Tree_WZTo3LNu_0"]["4015"] = 1.99463e+06;
  result["Tree_WZTo3LNu_0"]["4016"] = 1.99152e+06;
  result["Tree_WZTo3LNu_0"]["4017"] = 1.99411e+06;
  result["Tree_WZTo3LNu_0"]["4018"] = 1.99658e+06;
  result["Tree_WZTo3LNu_0"]["4019"] = 1.98935e+06;
  result["Tree_WZTo3LNu_0"]["4020"] = 1.99563e+06;
  result["Tree_WZTo3LNu_0"]["4021"] = 1.99108e+06;
  result["Tree_WZTo3LNu_0"]["4022"] = 1.99595e+06;
  result["Tree_WZTo3LNu_0"]["4023"] = 1.98971e+06;
  result["Tree_WZTo3LNu_0"]["4024"] = 1.99884e+06;
  result["Tree_WZTo3LNu_0"]["4025"] = 1.98976e+06;
  result["Tree_WZTo3LNu_0"]["4026"] = 1.99136e+06;
  result["Tree_WZTo3LNu_0"]["4027"] = 1.98889e+06;
  result["Tree_WZTo3LNu_0"]["4028"] = 1.99676e+06;
  result["Tree_WZTo3LNu_0"]["4029"] = 1.99351e+06;
  result["Tree_WZTo3LNu_0"]["4030"] = 1.99882e+06;
  result["Tree_WZTo3LNu_0"]["4031"] = 1.98615e+06;
  result["Tree_WZTo3LNu_0"]["4032"] = 2.00871e+06;
  result["Tree_WZTo3LNu_0"]["4033"] = 1.97513e+06;
  result["Tree_WZTo3LNu_0"]["4034"] = 1.98811e+06;
  result["Tree_WZTo3LNu_0"]["4035"] = 1.99791e+06;
  result["Tree_WZTo3LNu_0"]["4036"] = 1.99087e+06;
  result["Tree_WZTo3LNu_0"]["4037"] = 2.00137e+06;
  result["Tree_WZTo3LNu_0"]["4038"] = 1.9926e+06;
  result["Tree_WZTo3LNu_0"]["4039"] = 1.99547e+06;
  result["Tree_WZTo3LNu_0"]["4040"] = 1.99478e+06;
  result["Tree_WZTo3LNu_0"]["4041"] = 1.9911e+06;
  result["Tree_WZTo3LNu_0"]["4042"] = 1.98627e+06;
  result["Tree_WZTo3LNu_0"]["4043"] = 1.99338e+06;
  result["Tree_WZTo3LNu_0"]["4044"] = 1.99439e+06;
  result["Tree_WZTo3LNu_0"]["4045"] = 1.98823e+06;
  result["Tree_WZTo3LNu_0"]["4046"] = 1.99169e+06;
  result["Tree_WZTo3LNu_0"]["4047"] = 1.99712e+06;
  result["Tree_WZTo3LNu_0"]["4048"] = 1.99139e+06;
  result["Tree_WZTo3LNu_0"]["4049"] = 1.99249e+06;
  result["Tree_WZTo3LNu_0"]["4050"] = 1.99338e+06;
  result["Tree_WZTo3LNu_0"]["4051"] = 1.99292e+06;
  result["Tree_WZTo3LNu_0"]["4052"] = 2.02869e+06;
  result["Tree_WZTo3LNu_0"]["4053"] = 1.97559e+06;
  result["Tree_WZTo3LNu_0"]["4054"] = 1.9932e+06;
  result["Tree_WZTo3LNu_0"]["4055"] = 2.01058e+06;
  result["Tree_WZTo3LNu_0"]["4056"] = 2.04476e+06;
  
  //Spring 15 backgrounds
  result["Tree_TTWToLNu_0"]["1001"] = 85407.1;
  result["Tree_TTWToLNu_0"]["1002"] = 83507.3;
  result["Tree_TTWToLNu_0"]["1003"] = 87815.5;
  result["Tree_TTWToLNu_0"]["1004"] = 76613.1;
  result["Tree_TTWToLNu_0"]["1005"] = 74545.8;
  result["Tree_TTWToLNu_0"]["1006"] = 79116;
  result["Tree_TTWToLNu_0"]["1007"] = 93634.5;
  result["Tree_TTWToLNu_0"]["1008"] = 92297;
  result["Tree_TTWToLNu_0"]["1009"] = 95555.9;
  result["Tree_TTWToLNu_0"]["2001"] = 82928;
  result["Tree_TTWToLNu_0"]["2002"] = 84784.6;
  result["Tree_TTWToLNu_0"]["2003"] = 86583.5;
  result["Tree_TTWToLNu_0"]["2004"] = 86760.1;
  result["Tree_TTWToLNu_0"]["2005"] = 86154.2;
  result["Tree_TTWToLNu_0"]["2006"] = 83187.1;
  result["Tree_TTWToLNu_0"]["2007"] = 85981.2;
  result["Tree_TTWToLNu_0"]["2008"] = 84772.9;
  result["Tree_TTWToLNu_0"]["2009"] = 86811.9;
  result["Tree_TTWToLNu_0"]["2010"] = 86560.3;
  result["Tree_TTWToLNu_0"]["2011"] = 84215.6;
  result["Tree_TTWToLNu_0"]["2012"] = 85175.3;
  result["Tree_TTWToLNu_0"]["2013"] = 86676.8;
  result["Tree_TTWToLNu_0"]["2014"] = 86256.9;
  result["Tree_TTWToLNu_0"]["2015"] = 85096.3;
  result["Tree_TTWToLNu_0"]["2016"] = 85740.7;
  result["Tree_TTWToLNu_0"]["2017"] = 85485.8;
  result["Tree_TTWToLNu_0"]["2018"] = 84210;
  result["Tree_TTWToLNu_0"]["2019"] = 84300.2;
  result["Tree_TTWToLNu_0"]["2020"] = 86728.9;
  result["Tree_TTWToLNu_0"]["2021"] = 87187.1;
  result["Tree_TTWToLNu_0"]["2022"] = 85272.5;
  result["Tree_TTWToLNu_0"]["2023"] = 87707.3;
  result["Tree_TTWToLNu_0"]["2024"] = 87489.9;
  result["Tree_TTWToLNu_0"]["2025"] = 85284.4;
  result["Tree_TTWToLNu_0"]["2026"] = 85862.1;
  result["Tree_TTWToLNu_0"]["2027"] = 85844;
  result["Tree_TTWToLNu_0"]["2028"] = 85440.3;
  result["Tree_TTWToLNu_0"]["2029"] = 84413.9;
  result["Tree_TTWToLNu_0"]["2030"] = 85467.1;
  result["Tree_TTWToLNu_0"]["2031"] = 86792.8;
  result["Tree_TTWToLNu_0"]["2032"] = 86812.3;
  result["Tree_TTWToLNu_0"]["2033"] = 85657.3;
  result["Tree_TTWToLNu_0"]["2034"] = 85551.4;
  result["Tree_TTWToLNu_0"]["2035"] = 88530.5;
  result["Tree_TTWToLNu_0"]["2036"] = 84386.7;
  result["Tree_TTWToLNu_0"]["2037"] = 84594.4;
  result["Tree_TTWToLNu_0"]["2038"] = 84433;
  result["Tree_TTWToLNu_0"]["2039"] = 84643.5;
  result["Tree_TTWToLNu_0"]["2040"] = 85051.8;
  result["Tree_TTWToLNu_0"]["2041"] = 85127.6;
  result["Tree_TTWToLNu_0"]["2042"] = 84330.3;
  result["Tree_TTWToLNu_0"]["2043"] = 85187.6;
  result["Tree_TTWToLNu_0"]["2044"] = 84634.2;
  result["Tree_TTWToLNu_0"]["2045"] = 85566.3;
  result["Tree_TTWToLNu_0"]["2046"] = 83978;
  result["Tree_TTWToLNu_0"]["2047"] = 83569.3;
  result["Tree_TTWToLNu_0"]["2048"] = 85317;
  result["Tree_TTWToLNu_0"]["2049"] = 85422.5;
  result["Tree_TTWToLNu_0"]["2050"] = 84855.7;
  result["Tree_TTWToLNu_0"]["2051"] = 84354.7;
  result["Tree_TTWToLNu_0"]["2052"] = 85663.7;
  result["Tree_TTWToLNu_0"]["2053"] = 85917.2;
  result["Tree_TTWToLNu_0"]["2054"] = 86802.7;
  result["Tree_TTWToLNu_0"]["2055"] = 85936.1;
  result["Tree_TTWToLNu_0"]["2056"] = 84069.5;
  result["Tree_TTWToLNu_0"]["2057"] = 84338.6;
  result["Tree_TTWToLNu_0"]["2058"] = 84153.5;
  result["Tree_TTWToLNu_0"]["2059"] = 85157.3;
  result["Tree_TTWToLNu_0"]["2060"] = 85601;
  result["Tree_TTWToLNu_0"]["2061"] = 84999.8;
  result["Tree_TTWToLNu_0"]["2062"] = 84695.7;
  result["Tree_TTWToLNu_0"]["2063"] = 86646.1;
  result["Tree_TTWToLNu_0"]["2064"] = 82365.2;
  result["Tree_TTWToLNu_0"]["2065"] = 87486.4;
  result["Tree_TTWToLNu_0"]["2066"] = 85457.1;
  result["Tree_TTWToLNu_0"]["2067"] = 87314.9;
  result["Tree_TTWToLNu_0"]["2068"] = 85557.6;
  result["Tree_TTWToLNu_0"]["2069"] = 86842.4;
  result["Tree_TTWToLNu_0"]["2070"] = 85408;
  result["Tree_TTWToLNu_0"]["2071"] = 84914.1;
  result["Tree_TTWToLNu_0"]["2072"] = 84678;
  result["Tree_TTWToLNu_0"]["2073"] = 85635.1;
  result["Tree_TTWToLNu_0"]["2074"] = 87178.7;
  result["Tree_TTWToLNu_0"]["2075"] = 84763;
  result["Tree_TTWToLNu_0"]["2076"] = 85145.3;
  result["Tree_TTWToLNu_0"]["2077"] = 85593;
  result["Tree_TTWToLNu_0"]["2078"] = 86392.1;
  result["Tree_TTWToLNu_0"]["2079"] = 85105.3;
  result["Tree_TTWToLNu_0"]["2080"] = 86108.9;
  result["Tree_TTWToLNu_0"]["2081"] = 85866.9;
  result["Tree_TTWToLNu_0"]["2082"] = 86734.5;
  result["Tree_TTWToLNu_0"]["2083"] = 82905;
  result["Tree_TTWToLNu_0"]["2084"] = 86401.9;
  result["Tree_TTWToLNu_0"]["2085"] = 85120.6;
  result["Tree_TTWToLNu_0"]["2086"] = 84820.6;
  result["Tree_TTWToLNu_0"]["2087"] = 85399.3;
  result["Tree_TTWToLNu_0"]["2088"] = 84946.5;
  result["Tree_TTWToLNu_0"]["2089"] = 84641.3;
  result["Tree_TTWToLNu_0"]["2090"] = 86071.1;
  result["Tree_TTWToLNu_0"]["2091"] = 85473.8;
  result["Tree_TTWToLNu_0"]["2092"] = 86317;
  result["Tree_TTWToLNu_0"]["2093"] = 85109.3;
  result["Tree_TTWToLNu_0"]["2094"] = 85515.8;
  result["Tree_TTWToLNu_0"]["2095"] = 82820.7;
  result["Tree_TTWToLNu_0"]["2096"] = 85374.9;
  result["Tree_TTWToLNu_0"]["2097"] = 87062.8;
  result["Tree_TTWToLNu_0"]["2098"] = 85558.3;
  result["Tree_TTWToLNu_0"]["2099"] = 85100.5;
  result["Tree_TTWToLNu_0"]["2100"] = 82416.9;
  result["Tree_TTWToLNu_0"]["2101"] = 83631.8;
  result["Tree_TTWToLNu_0"]["2102"] = 86923.6;
  result["Tree_TTZToLLNuNu_0"]["1001"] = 100112;
  result["Tree_TTZToLLNuNu_0"]["1002"] = 97855.7;
  result["Tree_TTZToLLNuNu_0"]["1003"] = 102885;
  result["Tree_TTZToLLNuNu_0"]["1004"] = 91911.4;
  result["Tree_TTZToLLNuNu_0"]["1005"] = 89139.4;
  result["Tree_TTZToLLNuNu_0"]["1006"] = 95228.7;
  result["Tree_TTZToLLNuNu_0"]["1007"] = 107918;
  result["Tree_TTZToLLNuNu_0"]["1008"] = 106677;
  result["Tree_TTZToLLNuNu_0"]["1009"] = 109597;
  result["Tree_TTZToLLNuNu_0"]["2001"] = 98344;
  result["Tree_TTZToLLNuNu_0"]["2002"] = 101242;
  result["Tree_TTZToLLNuNu_0"]["2003"] = 101615;
  result["Tree_TTZToLLNuNu_0"]["2004"] = 98815.3;
  result["Tree_TTZToLLNuNu_0"]["2005"] = 98207.9;
  result["Tree_TTZToLLNuNu_0"]["2006"] = 100158;
  result["Tree_TTZToLLNuNu_0"]["2007"] = 99547.7;
  result["Tree_TTZToLLNuNu_0"]["2008"] = 101173;
  result["Tree_TTZToLLNuNu_0"]["2009"] = 101288;
  result["Tree_TTZToLLNuNu_0"]["2010"] = 100240;
  result["Tree_TTZToLLNuNu_0"]["2011"] = 98395.2;
  result["Tree_TTZToLLNuNu_0"]["2012"] = 100123;
  result["Tree_TTZToLLNuNu_0"]["2013"] = 101858;
  result["Tree_TTZToLLNuNu_0"]["2014"] = 102725;
  result["Tree_TTZToLLNuNu_0"]["2015"] = 101944;
  result["Tree_TTZToLLNuNu_0"]["2016"] = 100564;
  result["Tree_TTZToLLNuNu_0"]["2017"] = 105145;
  result["Tree_TTZToLLNuNu_0"]["2018"] = 101794;
  result["Tree_TTZToLLNuNu_0"]["2019"] = 98759.8;
  result["Tree_TTZToLLNuNu_0"]["2020"] = 101307;
  result["Tree_TTZToLLNuNu_0"]["2021"] = 99748.7;
  result["Tree_TTZToLLNuNu_0"]["2022"] = 96981.7;
  result["Tree_TTZToLLNuNu_0"]["2023"] = 100775;
  result["Tree_TTZToLLNuNu_0"]["2024"] = 98189;
  result["Tree_TTZToLLNuNu_0"]["2025"] = 99648.8;
  result["Tree_TTZToLLNuNu_0"]["2026"] = 99145.7;
  result["Tree_TTZToLLNuNu_0"]["2027"] = 105189;
  result["Tree_TTZToLLNuNu_0"]["2028"] = 101477;
  result["Tree_TTZToLLNuNu_0"]["2029"] = 101835;
  result["Tree_TTZToLLNuNu_0"]["2030"] = 99444.2;
  result["Tree_TTZToLLNuNu_0"]["2031"] = 98896.7;
  result["Tree_TTZToLLNuNu_0"]["2032"] = 99551.1;
  result["Tree_TTZToLLNuNu_0"]["2033"] = 98796.6;
  result["Tree_TTZToLLNuNu_0"]["2034"] = 96443.4;
  result["Tree_TTZToLLNuNu_0"]["2035"] = 104625;
  result["Tree_TTZToLLNuNu_0"]["2036"] = 99029.7;
  result["Tree_TTZToLLNuNu_0"]["2037"] = 101973;
  result["Tree_TTZToLLNuNu_0"]["2038"] = 99103.6;
  result["Tree_TTZToLLNuNu_0"]["2039"] = 97989.5;
  result["Tree_TTZToLLNuNu_0"]["2040"] = 98339.9;
  result["Tree_TTZToLLNuNu_0"]["2041"] = 98126.6;
  result["Tree_TTZToLLNuNu_0"]["2042"] = 98905.5;
  result["Tree_TTZToLLNuNu_0"]["2043"] = 97314.4;
  result["Tree_TTZToLLNuNu_0"]["2044"] = 98752.8;
  result["Tree_TTZToLLNuNu_0"]["2045"] = 98108.8;
  result["Tree_TTZToLLNuNu_0"]["2046"] = 96527;
  result["Tree_TTZToLLNuNu_0"]["2047"] = 100767;
  result["Tree_TTZToLLNuNu_0"]["2048"] = 101045;
  result["Tree_TTZToLLNuNu_0"]["2049"] = 101205;
  result["Tree_TTZToLLNuNu_0"]["2050"] = 99593.2;
  result["Tree_TTZToLLNuNu_0"]["2051"] = 98864.6;
  result["Tree_TTZToLLNuNu_0"]["2052"] = 99657.9;
  result["Tree_TTZToLLNuNu_0"]["2053"] = 98543.7;
  result["Tree_TTZToLLNuNu_0"]["2054"] = 101798;
  result["Tree_TTZToLLNuNu_0"]["2055"] = 99705;
  result["Tree_TTZToLLNuNu_0"]["2056"] = 101544;
  result["Tree_TTZToLLNuNu_0"]["2057"] = 99217.6;
  result["Tree_TTZToLLNuNu_0"]["2058"] = 99266.3;
  result["Tree_TTZToLLNuNu_0"]["2059"] = 101039;
  result["Tree_TTZToLLNuNu_0"]["2060"] = 99124.7;
  result["Tree_TTZToLLNuNu_0"]["2061"] = 99203.9;
  result["Tree_TTZToLLNuNu_0"]["2062"] = 99446.8;
  result["Tree_TTZToLLNuNu_0"]["2063"] = 100032;
  result["Tree_TTZToLLNuNu_0"]["2064"] = 101569;
  result["Tree_TTZToLLNuNu_0"]["2065"] = 101627;
  result["Tree_TTZToLLNuNu_0"]["2066"] = 99197.1;
  result["Tree_TTZToLLNuNu_0"]["2067"] = 103069;
  result["Tree_TTZToLLNuNu_0"]["2068"] = 100413;
  result["Tree_TTZToLLNuNu_0"]["2069"] = 101090;
  result["Tree_TTZToLLNuNu_0"]["2070"] = 100724;
  result["Tree_TTZToLLNuNu_0"]["2071"] = 97087.9;
  result["Tree_TTZToLLNuNu_0"]["2072"] = 99342;
  result["Tree_TTZToLLNuNu_0"]["2073"] = 100781;
  result["Tree_TTZToLLNuNu_0"]["2074"] = 101579;
  result["Tree_TTZToLLNuNu_0"]["2075"] = 99997.3;
  result["Tree_TTZToLLNuNu_0"]["2076"] = 96732.9;
  result["Tree_TTZToLLNuNu_0"]["2077"] = 97852.4;
  result["Tree_TTZToLLNuNu_0"]["2078"] = 101366;
  result["Tree_TTZToLLNuNu_0"]["2079"] = 99229.4;
  result["Tree_TTZToLLNuNu_0"]["2080"] = 99425.8;
  result["Tree_TTZToLLNuNu_0"]["2081"] = 98968.9;
  result["Tree_TTZToLLNuNu_0"]["2082"] = 99425.5;
  result["Tree_TTZToLLNuNu_0"]["2083"] = 101259;
  result["Tree_TTZToLLNuNu_0"]["2084"] = 99732.7;
  result["Tree_TTZToLLNuNu_0"]["2085"] = 101345;
  result["Tree_TTZToLLNuNu_0"]["2086"] = 100840;
  result["Tree_TTZToLLNuNu_0"]["2087"] = 101701;
  result["Tree_TTZToLLNuNu_0"]["2088"] = 101231;
  result["Tree_TTZToLLNuNu_0"]["2089"] = 101656;
  result["Tree_TTZToLLNuNu_0"]["2090"] = 99912.2;
  result["Tree_TTZToLLNuNu_0"]["2091"] = 100289;
  result["Tree_TTZToLLNuNu_0"]["2092"] = 98968;
  result["Tree_TTZToLLNuNu_0"]["2093"] = 101429;
  result["Tree_TTZToLLNuNu_0"]["2094"] = 99567.1;
  result["Tree_TTZToLLNuNu_0"]["2095"] = 102845;
  result["Tree_TTZToLLNuNu_0"]["2096"] = 100191;
  result["Tree_TTZToLLNuNu_0"]["2097"] = 100693;
  result["Tree_TTZToLLNuNu_0"]["2098"] = 97884.5;
  result["Tree_TTZToLLNuNu_0"]["2099"] = 101668;
  result["Tree_TTZToLLNuNu_0"]["2100"] = 102468;
  result["Tree_TTZToLLNuNu_0"]["2101"] = 98668.4;
  result["Tree_TTZToLLNuNu_0"]["2102"] = 101317;
  
  
  
  //Phys14 SAMPLES
  result["TTWJets_aMCatNLO"]["1001"] = 4343.38;
  result["TTWJets_aMCatNLO"]["1002"] = 4236.05;
  result["TTWJets_aMCatNLO"]["1003"] = 4473.8;
  result["TTWJets_aMCatNLO"]["1004"] = 3830.14;
  result["TTWJets_aMCatNLO"]["1005"] = 3720.82;
  result["TTWJets_aMCatNLO"]["1006"] = 3958.83;
  result["TTWJets_aMCatNLO"]["1007"] = 4877.85;
  result["TTWJets_aMCatNLO"]["1008"] = 4787.55;
  result["TTWJets_aMCatNLO"]["1009"] = 4995.51;
  result["TTWJets_aMCatNLO"]["2001"] = 4219.37;
  result["TTWJets_aMCatNLO"]["2002"] = 4322.56;
  result["TTWJets_aMCatNLO"]["2003"] = 4393.43;
  result["TTWJets_aMCatNLO"]["2004"] = 4404.65;
  result["TTWJets_aMCatNLO"]["2005"] = 4414.72;
  result["TTWJets_aMCatNLO"]["2006"] = 4230.65;
  result["TTWJets_aMCatNLO"]["2007"] = 4386.22;
  result["TTWJets_aMCatNLO"]["2008"] = 4296.06;
  result["TTWJets_aMCatNLO"]["2009"] = 4439.37;
  result["TTWJets_aMCatNLO"]["2010"] = 4414.29;
  result["TTWJets_aMCatNLO"]["2011"] = 4250.87;
  result["TTWJets_aMCatNLO"]["2012"] = 4319.38;
  result["TTWJets_aMCatNLO"]["2013"] = 4390.02;
  result["TTWJets_aMCatNLO"]["2014"] = 4389.93;
  result["TTWJets_aMCatNLO"]["2015"] = 4323.58;
  result["TTWJets_aMCatNLO"]["2016"] = 4372.59;
  result["TTWJets_aMCatNLO"]["2017"] = 4328.27;
  result["TTWJets_aMCatNLO"]["2018"] = 4289.43;
  result["TTWJets_aMCatNLO"]["2019"] = 4270.83;
  result["TTWJets_aMCatNLO"]["2020"] = 4432.61;
  result["TTWJets_aMCatNLO"]["2021"] = 4432.5;
  result["TTWJets_aMCatNLO"]["2022"] = 4346.73;
  result["TTWJets_aMCatNLO"]["2023"] = 4462.89;
  result["TTWJets_aMCatNLO"]["2024"] = 4455.57;
  result["TTWJets_aMCatNLO"]["2025"] = 4335.28;
  result["TTWJets_aMCatNLO"]["2026"] = 4377.19;
  result["TTWJets_aMCatNLO"]["2027"] = 4342.35;
  result["TTWJets_aMCatNLO"]["2028"] = 4348.36;
  result["TTWJets_aMCatNLO"]["2029"] = 4276.55;
  result["TTWJets_aMCatNLO"]["2030"] = 4355.42;
  result["TTWJets_aMCatNLO"]["2031"] = 4429.44;
  result["TTWJets_aMCatNLO"]["2032"] = 4457.73;
  result["TTWJets_aMCatNLO"]["2033"] = 4374.22;
  result["TTWJets_aMCatNLO"]["2034"] = 4365.78;
  result["TTWJets_aMCatNLO"]["2035"] = 4503.02;
  result["TTWJets_aMCatNLO"]["2036"] = 4306.49;
  result["TTWJets_aMCatNLO"]["2037"] = 4284.53;
  result["TTWJets_aMCatNLO"]["2038"] = 4296.74;
  result["TTWJets_aMCatNLO"]["2039"] = 4291.06;
  result["TTWJets_aMCatNLO"]["2040"] = 4309.91;
  result["TTWJets_aMCatNLO"]["2041"] = 4344.72;
  result["TTWJets_aMCatNLO"]["2042"] = 4272.83;
  result["TTWJets_aMCatNLO"]["2043"] = 4318.33;
  result["TTWJets_aMCatNLO"]["2044"] = 4284.93;
  result["TTWJets_aMCatNLO"]["2045"] = 4389.26;
  result["TTWJets_aMCatNLO"]["2046"] = 4278.95;
  result["TTWJets_aMCatNLO"]["2047"] = 4233.04;
  result["TTWJets_aMCatNLO"]["2048"] = 4333.77;
  result["TTWJets_aMCatNLO"]["2049"] = 4346.03;
  result["TTWJets_aMCatNLO"]["2050"] = 4289.2;
  result["TTWJets_aMCatNLO"]["2051"] = 4258.73;
  result["TTWJets_aMCatNLO"]["2052"] = 4358.2;
  result["TTWJets_aMCatNLO"]["2053"] = 4382.77;
  result["TTWJets_aMCatNLO"]["2054"] = 4404.25;
  result["TTWJets_aMCatNLO"]["2055"] = 4373.04;
  result["TTWJets_aMCatNLO"]["2056"] = 4274.77;
  result["TTWJets_aMCatNLO"]["2057"] = 4324.32;
  result["TTWJets_aMCatNLO"]["2058"] = 4226.88;
  result["TTWJets_aMCatNLO"]["2059"] = 4324.08;
  result["TTWJets_aMCatNLO"]["2060"] = 4367.19;
  result["TTWJets_aMCatNLO"]["2061"] = 4319.81;
  result["TTWJets_aMCatNLO"]["2062"] = 4286.53;
  result["TTWJets_aMCatNLO"]["2063"] = 4443.15;
  result["TTWJets_aMCatNLO"]["2064"] = 4164.41;
  result["TTWJets_aMCatNLO"]["2065"] = 4435.21;
  result["TTWJets_aMCatNLO"]["2066"] = 4348.07;
  result["TTWJets_aMCatNLO"]["2067"] = 4414.11;
  result["TTWJets_aMCatNLO"]["2068"] = 4353.8;
  result["TTWJets_aMCatNLO"]["2069"] = 4425.47;
  result["TTWJets_aMCatNLO"]["2070"] = 4336.68;
  result["TTWJets_aMCatNLO"]["2071"] = 4309.94;
  result["TTWJets_aMCatNLO"]["2072"] = 4315.41;
  result["TTWJets_aMCatNLO"]["2073"] = 4382.98;
  result["TTWJets_aMCatNLO"]["2074"] = 4433.22;
  result["TTWJets_aMCatNLO"]["2075"] = 4298.39;
  result["TTWJets_aMCatNLO"]["2076"] = 4292.56;
  result["TTWJets_aMCatNLO"]["2077"] = 4353.19;
  result["TTWJets_aMCatNLO"]["2078"] = 4367.9;
  result["TTWJets_aMCatNLO"]["2079"] = 4308.31;
  result["TTWJets_aMCatNLO"]["2080"] = 4402.6;
  result["TTWJets_aMCatNLO"]["2081"] = 4367.99;
  result["TTWJets_aMCatNLO"]["2082"] = 4437.1;
  result["TTWJets_aMCatNLO"]["2083"] = 4183.68;
  result["TTWJets_aMCatNLO"]["2084"] = 4429.78;
  result["TTWJets_aMCatNLO"]["2085"] = 4334.43;
  result["TTWJets_aMCatNLO"]["2086"] = 4318.75;
  result["TTWJets_aMCatNLO"]["2087"] = 4381.04;
  result["TTWJets_aMCatNLO"]["2088"] = 4320.68;
  result["TTWJets_aMCatNLO"]["2089"] = 4293.72;
  result["TTWJets_aMCatNLO"]["2090"] = 4392.77;
  result["TTWJets_aMCatNLO"]["2091"] = 4348.68;
  result["TTWJets_aMCatNLO"]["2092"] = 4395.18;
  result["TTWJets_aMCatNLO"]["2093"] = 4341.14;
  result["TTWJets_aMCatNLO"]["2094"] = 4304.5;
  result["TTWJets_aMCatNLO"]["2095"] = 4209.91;
  result["TTWJets_aMCatNLO"]["2096"] = 4341.25;
  result["TTWJets_aMCatNLO"]["2097"] = 4447.41;
  result["TTWJets_aMCatNLO"]["2098"] = 4367.8;
  result["TTWJets_aMCatNLO"]["2099"] = 4307.68;
  result["TTWJets_aMCatNLO"]["2100"] = 4198.66;
  result["TTZJets_aMCatNLO"]["1001"] = 2608.27;
  result["TTZJets_aMCatNLO"]["1002"] = 2550.64;
  result["TTZJets_aMCatNLO"]["1003"] = 2679.13;
  result["TTZJets_aMCatNLO"]["1004"] = 2404.15;
  result["TTZJets_aMCatNLO"]["1005"] = 2332.69;
  result["TTZJets_aMCatNLO"]["1006"] = 2489.64;
  result["TTZJets_aMCatNLO"]["1007"] = 2795.83;
  result["TTZJets_aMCatNLO"]["1008"] = 2765.19;
  result["TTZJets_aMCatNLO"]["1009"] = 2837.61;
  result["TTZJets_aMCatNLO"]["2001"] = 2566.91;
  result["TTZJets_aMCatNLO"]["2002"] = 2636.36;
  result["TTZJets_aMCatNLO"]["2003"] = 2644.95;
  result["TTZJets_aMCatNLO"]["2004"] = 2568.34;
  result["TTZJets_aMCatNLO"]["2005"] = 2562.12;
  result["TTZJets_aMCatNLO"]["2006"] = 2607.34;
  result["TTZJets_aMCatNLO"]["2007"] = 2597.29;
  result["TTZJets_aMCatNLO"]["2008"] = 2638.6;
  result["TTZJets_aMCatNLO"]["2009"] = 2639;
  result["TTZJets_aMCatNLO"]["2010"] = 2611.76;
  result["TTZJets_aMCatNLO"]["2011"] = 2559.21;
  result["TTZJets_aMCatNLO"]["2012"] = 2604.05;
  result["TTZJets_aMCatNLO"]["2013"] = 2644.68;
  result["TTZJets_aMCatNLO"]["2014"] = 2674.81;
  result["TTZJets_aMCatNLO"]["2015"] = 2652.65;
  result["TTZJets_aMCatNLO"]["2016"] = 2629.92;
  result["TTZJets_aMCatNLO"]["2017"] = 2726;
  result["TTZJets_aMCatNLO"]["2018"] = 2649.81;
  result["TTZJets_aMCatNLO"]["2019"] = 2579.06;
  result["TTZJets_aMCatNLO"]["2020"] = 2646.53;
  result["TTZJets_aMCatNLO"]["2021"] = 2601.43;
  result["TTZJets_aMCatNLO"]["2022"] = 2538.16;
  result["TTZJets_aMCatNLO"]["2023"] = 2629.3;
  result["TTZJets_aMCatNLO"]["2024"] = 2565.37;
  result["TTZJets_aMCatNLO"]["2025"] = 2592.54;
  result["TTZJets_aMCatNLO"]["2026"] = 2583.55;
  result["TTZJets_aMCatNLO"]["2027"] = 2732.73;
  result["TTZJets_aMCatNLO"]["2028"] = 2636.53;
  result["TTZJets_aMCatNLO"]["2029"] = 2652.67;
  result["TTZJets_aMCatNLO"]["2030"] = 2601.13;
  result["TTZJets_aMCatNLO"]["2031"] = 2577.88;
  result["TTZJets_aMCatNLO"]["2032"] = 2594.51;
  result["TTZJets_aMCatNLO"]["2033"] = 2574.41;
  result["TTZJets_aMCatNLO"]["2034"] = 2521.16;
  result["TTZJets_aMCatNLO"]["2035"] = 2721.73;
  result["TTZJets_aMCatNLO"]["2036"] = 2579.29;
  result["TTZJets_aMCatNLO"]["2037"] = 2653.75;
  result["TTZJets_aMCatNLO"]["2038"] = 2591.01;
  result["TTZJets_aMCatNLO"]["2039"] = 2561.02;
  result["TTZJets_aMCatNLO"]["2040"] = 2563.41;
  result["TTZJets_aMCatNLO"]["2041"] = 2566.94;
  result["TTZJets_aMCatNLO"]["2042"] = 2575.53;
  result["TTZJets_aMCatNLO"]["2043"] = 2538.75;
  result["TTZJets_aMCatNLO"]["2044"] = 2577.05;
  result["TTZJets_aMCatNLO"]["2045"] = 2569.54;
  result["TTZJets_aMCatNLO"]["2046"] = 2532.9;
  result["TTZJets_aMCatNLO"]["2047"] = 2620.67;
  result["TTZJets_aMCatNLO"]["2048"] = 2629.64;
  result["TTZJets_aMCatNLO"]["2049"] = 2636.4;
  result["TTZJets_aMCatNLO"]["2050"] = 2591.7;
  result["TTZJets_aMCatNLO"]["2051"] = 2574.65;
  result["TTZJets_aMCatNLO"]["2052"] = 2588.81;
  result["TTZJets_aMCatNLO"]["2053"] = 2573.44;
  result["TTZJets_aMCatNLO"]["2054"] = 2640.9;
  result["TTZJets_aMCatNLO"]["2055"] = 2594.35;
  result["TTZJets_aMCatNLO"]["2056"] = 2641.35;
  result["TTZJets_aMCatNLO"]["2057"] = 2586.35;
  result["TTZJets_aMCatNLO"]["2058"] = 2582.55;
  result["TTZJets_aMCatNLO"]["2059"] = 2636.81;
  result["TTZJets_aMCatNLO"]["2060"] = 2589.38;
  result["TTZJets_aMCatNLO"]["2061"] = 2591.01;
  result["TTZJets_aMCatNLO"]["2062"] = 2596.32;
  result["TTZJets_aMCatNLO"]["2063"] = 2600.61;
  result["TTZJets_aMCatNLO"]["2064"] = 2641.22;
  result["TTZJets_aMCatNLO"]["2065"] = 2636.44;
  result["TTZJets_aMCatNLO"]["2066"] = 2585.82;
  result["TTZJets_aMCatNLO"]["2067"] = 2687.94;
  result["TTZJets_aMCatNLO"]["2068"] = 2616.01;
  result["TTZJets_aMCatNLO"]["2069"] = 2623.83;
  result["TTZJets_aMCatNLO"]["2070"] = 2613.76;
  result["TTZJets_aMCatNLO"]["2071"] = 2532.21;
  result["TTZJets_aMCatNLO"]["2072"] = 2590.93;
  result["TTZJets_aMCatNLO"]["2073"] = 2624.41;
  result["TTZJets_aMCatNLO"]["2074"] = 2639.8;
  result["TTZJets_aMCatNLO"]["2075"] = 2603.8;
  result["TTZJets_aMCatNLO"]["2076"] = 2520.21;
  result["TTZJets_aMCatNLO"]["2077"] = 2551.29;
  result["TTZJets_aMCatNLO"]["2078"] = 2635.6;
  result["TTZJets_aMCatNLO"]["2079"] = 2592.46;
  result["TTZJets_aMCatNLO"]["2080"] = 2594.06;
  result["TTZJets_aMCatNLO"]["2081"] = 2580.4;
  result["TTZJets_aMCatNLO"]["2082"] = 2588.8;
  result["TTZJets_aMCatNLO"]["2083"] = 2636.52;
  result["TTZJets_aMCatNLO"]["2084"] = 2605.48;
  result["TTZJets_aMCatNLO"]["2085"] = 2636.48;
  result["TTZJets_aMCatNLO"]["2086"] = 2624.44;
  result["TTZJets_aMCatNLO"]["2087"] = 2644.81;
  result["TTZJets_aMCatNLO"]["2088"] = 2632.88;
  result["TTZJets_aMCatNLO"]["2089"] = 2645.81;
  result["TTZJets_aMCatNLO"]["2090"] = 2599.08;
  result["TTZJets_aMCatNLO"]["2091"] = 2610.03;
  result["TTZJets_aMCatNLO"]["2092"] = 2578.37;
  result["TTZJets_aMCatNLO"]["2093"] = 2642.75;
  result["TTZJets_aMCatNLO"]["2094"] = 2606.55;
  result["TTZJets_aMCatNLO"]["2095"] = 2667.24;
  result["TTZJets_aMCatNLO"]["2096"] = 2607.24;
  result["TTZJets_aMCatNLO"]["2097"] = 2625.29;
  result["TTZJets_aMCatNLO"]["2098"] = 2556.3;
  result["TTZJets_aMCatNLO"]["2099"] = 2643.72;
  result["TTZJets_aMCatNLO"]["2100"] = 2664.28;

  result["WJetsToLNu_HT100to200"]["1001"] = 5262265.0;
  result["WJetsToLNu_HT200to400"]["1001"] = 4936077.0;
  result["WJetsToLNu_HT400to600"]["1001"] = 4640594.0;
  result["WJetsToLNu_HT600toInf"]["1001"] = 4581841.0;
  result["DYJetsToLL_M50"]["1001"] = 2829164.0;
  result["DYJetsToLL_M50_HT100to200"]["1001"] = 4054159.0;
  result["DYJetsToLL_M50_HT200to400"]["1001"] = 4666496.0;
  result["DYJetsToLL_M50_HT400to600"]["1001"] = 4931372.0;
  result["DYJetsToLL_M50_HT600toInf"]["1001"] = 4493574.0;
  result["TTJets"]["1001"] = 25446993.0;
  result["TTWJets"]["1001"] = 246521.0;
  result["TTZJets"]["1001"] = 249275.0;
  result["WZJetsTo3LNu"]["1001"] = 237484.0;
  result["TBarToLeptons_sch"]["1001"] = 250000.0;
  result["TBarToLeptons_tch"]["1001"] = 1999800.0;
  result["TBar_tWch"]["1001"] = 971800.0;
  result["TTH"]["1001"] = 199700.0;
  result["TToLeptons_sch"]["1001"] = 500000.0;
  result["TToLeptons_tch"]["1001"] = 3991000.0;
  result["T_tWch"]["1001"] = 986100.0;
  result["ZZTo4L"]["1001"] = 1958600.0;
  result["GGHZZ4L"]["1001"] = 204684.0;
  result["SMS_T1tttt_2J_mGl1200_mLSP800"]["1001"] = 100322.0;
  result["SMS_T1tttt_2J_mGl1500_mLSP100"]["1001"] = 105679.0;
  result["T1ttbbWW_mGo1300_mCh300_mChi290"]["1001"] = 43975.0;
  result["T1ttbbWW_mGo1000_mCh725_mChi720"]["1001"] = 52212.0;
  result["T5ttttDeg_mGo1000_mStop300_mChi280"]["1001"] = 52102.0;
  result["T5ttttDeg_mGo1000_mStop300_mCh285_mChi280"]["1001"] = 52499.0;
  result["T6ttWW_mSbot650_mCh150_mChi50"]["1001"] = 105124.0;
  result["T6ttWW_mSbot600_mCh425_mChi50"]["1001"] = 52954.0;
  result["T5qqqqWW_mGo1200_mCh1000_mChi800"]["1001"] = 112720.0;
  result["T5qqqqWW_mGo1200_mCh1000_mChi800_dilep"]["1001"] = 54319.0;
  result["T1ttbbWW_mGo1000_mCh725_mChi715"]["1001"] = 51318.0;
  result["T1ttbbWW_mGo1300_mCh300_mChi295"]["1001"] = 44242.0;
  result["T1tttt_mGo1300_mChi100"]["1001"] = 39960.0;
  result["T5qqqqWWDeg_mGo1000_mCh310_mChi300_dilep"]["1001"] = 52169.0;
  result["T5qqqqWWDeg_mGo1000_mCh315_mChi300_dilep"]["1001"] = 51955.0;
  result["T5qqqqWWDeg_mGo1000_mCh325_mChi300_dilep"]["1001"] = 51924.0;
  result["T5qqqqWWDeg_mGo800_mCh305_mChi300_dilep"]["1001"] = 73114.0;
  result["T5qqqqWW_mGo1000_mCh800_mChi700_dilep"]["1001"] = 52555.0;
  result["T5qqqqWW_mGo1400_mCh315_mChi300"]["1001"] = 37070.0;
  result["T5qqqqWW_mGo1500_mCh800_mChi100"]["1001"] = 120160.0;
  result["T5ttttDeg_mGo1000_mStop300_mCh285_mChi280_dil"]["1001"] = 75914.0;
  result["T5ttttDeg_mGo1300_mStop300_mCh285_mChi280_dil"]["1001"] = 70347.0;
  result["T5ttttDeg_mGo1300_mStop300_mCh285_mChi280"]["1001"] = 43818.0;
  result["T5ttttDeg_mGo1300_mStop300_mChi280"]["1001"] = 44011.0;

  return result;

}


std::map<std::string, double> get_map_xsec() {

  std::map<std::string, double> result; 
  
  //Spring 15 T1tttt scan
  //set to 1 for the moment
  result["T1tttt_700_0"] = 1.;
  result["T1tttt_700_475"] = 1.;
  result["T1tttt_1100_800"] = 1.;
  result["T1tttt_1300_0"] = 1.;
  result["T1tttt_1300_1000"] = 1.;
  result["T1tttt_1600_0"] = 1.;
  result["T1tttt_1600_1200"] = 1.;
  
  result["Tree_WZTo3LNu_0"] = (4.42965);
  result["Tree_TTWToLNu_0"] = (0.2043);
  result["Tree_TTZToLLNuNu_0"] = (0.2529);



  //Phys14 SAMPLES
  result["TTWJets_aMCatNLO"] = (0.215 * 0.175);
  result["TTZJets_aMCatNLO"] = (0.097 * 0.27 );

  result["WJetsToLNu_HT100to200"] = (1817.0*1.23);
  result["WJetsToLNu_HT200to400"] = (471.6*1.23);
  result["WJetsToLNu_HT400to600"] = (55.61*1.23);
  result["WJetsToLNu_HT600toInf"] = (18.81*1.23);
  result["DYJetsToLL_M50"] = 6024;
  result["DYJetsToLL_M50_HT100to200"] = (194.3*1.27);
  result["DYJetsToLL_M50_HT200to400"] = (52.24*1.27);
  result["DYJetsToLL_M50_HT400to600"] = (6.546*1.27);
  result["DYJetsToLL_M50_HT600toInf"] = (2.179*1.27);
  result["TTJets"] = 809.1;
  result["TTWJets"] = 0.6647;
  result["TTZJets"] = 0.8565;
  result["WZJetsTo3LNu"] = 2.29;
  result["TBarToLeptons_sch"] = 0.44928;
  result["TBarToLeptons_tch"] = 8.74476;
  result["TBar_tWch"] = 35.6;
  result["TTH"] = 0.5085;
  result["TToLeptons_sch"] = 0.7776;
  result["TToLeptons_tch"] = 14.6934;
  result["T_tWch"] = 35.6;
  result["ZZTo4L"] = 0.0360292;
  result["GGHZZ4L"] = 0.0121219;
  result["SMS_T1tttt_2J_mGl1200_mLSP800"] = (0.0856418*20);
  result["SMS_T1tttt_2J_mGl1500_mLSP100"] = (0.0141903*20);
  result["T1ttbbWW_mGo1300_mCh300_mChi290"] = (0.0460525*20);
  result["T1ttbbWW_mGo1000_mCh725_mChi720"] = (0.325388*20);
  result["T5ttttDeg_mGo1000_mStop300_mChi280"] = (0.325388*20);
  result["T5ttttDeg_mGo1000_mStop300_mCh285_mChi280"] = (0.325388*20);
  result["T6ttWW_mSbot650_mCh150_mChi50"] = (0.107045*20);
  result["T6ttWW_mSbot600_mCh425_mChi50"] = (0.174599*20);
  result["T5qqqqWW_mGo1200_mCh1000_mChi800"] = (0.0856418*20);
  result["T5qqqqWW_mGo1200_mCh1000_mChi800_dilep"] = (0.0089903*20);
  result["T1ttbbWW_mGo1000_mCh725_mChi715"] = (0.325388*20);
  result["T1ttbbWW_mGo1300_mCh300_mChi295"] = (0.0460525*20);
  result["T1tttt_mGo1300_mChi100"] = (0.0460525*20);
  result["T5qqqqWWDeg_mGo1000_mCh310_mChi300_dilep"] = (0.0360819*20);
  result["T5qqqqWWDeg_mGo1000_mCh315_mChi300_dilep"] = (0.2291257*20);
  result["T5qqqqWWDeg_mGo1000_mCh325_mChi300_dilep"] = (0.0341579*20);
  result["T5qqqqWWDeg_mGo800_mCh305_mChi300_dilep"] = (0.174171*20);
  result["T5qqqqWW_mGo1000_mCh800_mChi700_dilep"] = (0.0341579*20);
  result["T5qqqqWW_mGo1400_mCh315_mChi300"] = (0.0252977*20);
  result["T5qqqqWW_mGo1500_mCh800_mChi100"] = (0.0141903*20);
  result["T5ttttDeg_mGo1000_mStop300_mCh285_mChi280_dil"] = (0.325388*20);
  result["T5ttttDeg_mGo1300_mStop300_mCh285_mChi280_dil"] = (0.0460525*20);
  result["T5ttttDeg_mGo1300_mStop300_mCh285_mChi280"] = (0.0460525*20);
  result["T5ttttDeg_mGo1300_mStop300_mChi280"] = (0.0460525*20);
  
  
  return result;

}

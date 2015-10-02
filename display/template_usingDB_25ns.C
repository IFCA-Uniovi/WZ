#include "display/core/MPAFDisplay.hh"

MPAFDisplay md;
//std::map<std::string, std::map<std::string, double> > get_map_wsum();


void template_usingDB_25ns(int setproc = 2)  {
  cout << "1" << endl;
  gStyle->SetOptStat(0);
  md.refresh();
  //general parameters ********************* general parameters
  string dir="WZsynchro";
  string fileName="template_WZ25"; // not needed for statistics
  string fileList="template_WZ25"; // put command line that gives all files as in a "ls" command


  bool mcOnly = false;
  cout << "2" << endl;
  //if(md.isInitStatus()) {
    md.anConf.configureNames( dir, fileName, fileList);
    md.anConf.configureData(false, 0, mcOnly);
    //}

  //observables **********************
  //string obs[6]={"","","","","",""};
    //std::string s_region="";//global
    //std::string s_region="BR00H";
    std::string s_region="BR0H";
    
    //std::string s_region_dat = s_region;
    //if (s_region != "")  s_region_dat = "_" + s_region;
    std::string s_region_dat="_BR0H"; //Avoiding "_"+string Cling problem manually
  cout << "3" << endl;
    md.dp.setObservables("METWZCR");
    //md.dp.setObservables("MET"+s_region);
    //md.dp.setObservables("HT"+s_region);
    //md.dp.setObservables("MT"+s_region);
    //md.dp.setObservables("l1Pt"+s_region);
    //md.dp.setObservables("l2Pt"+s_region);
    //md.dp.setObservables("NJets"+s_region);
    //md.dp.setObservables("NBJets"+s_region);
    
    //md.dp.setObservables("METBR00H");
     //md.dp.setObservables("MTminBR00H");
    //md.dp.setObservables("HTBR00H");
    //md.dp.setObservables("NBJetsBR00H");
    //md.dp.setObservables("NJetsBR00H");
  
    //md.dp.setObservables("METBR0H");
     //md.dp.setObservables("MTminBR0H");
    //md.dp.setObservables("HTBR0H");
    //md.dp.setObservables("NBJetsBR0H");
    //md.dp.setObservables("NJetsBR0H");
  
  cout << "4" << endl;
  //Binning & title ************************* Binning & titre
  string yTitle="number of events";
  int binning=40;
  int addBinBkg=1; //BinB = binning*AddBin
  double rangeY[2]={0,0};
  double rangeX[2]={0.,500.};
  int xDiv[3]={8,6,0};
  int yDiv[3]={6,6,0}; //Nlabel /  sous-Div /ssdiv
  bool logYScale=false;
  bool overFlowBin=true;
  bool underFlowBin=false;
  bool showDMCRatio=true;
  bool showGrid=false;
  float markerSize=0.8;
  float lineWidth=2;

  bool summedSignal=false;
  bool stacking=true;

  bool cmsPrel=true;

  float xt=0.68;
  float yt=0.48;
  float st=0.039;
  string addText="";
  cout << "5" << endl;
  string autoBinFile="susybinning_50ns";
  md.dp.loadAutoBinning(autoBinFile);

  //Systematic uncertainties ********************************
  bool addSystematics=true;
  
  bool mcStatSyst=true;
  string systSources="";

  bool uncDet=false;

  string Norm="";
    cout << "6" << endl;
  //Lumis( or XSections ) pb-1 & KFactors ************************************
  float lumi=10000; //pb-1 19470
  float energy=13; //TeV
  cout << "7" << endl;
  bool useXS=false;
  md.anConf.loadXSDB("XSectionsSpring15.db");
  map<string,float> LumisXS;
  
  map<string,float> KFactors;

  md.anConf.configureLumi( LumisXS, KFactors, lumi, useXS );
  cout << "8" << endl;
  // SDYJetsM50_HT600toInf_PU_S14_POSTLS170_skimamples **************************  samples
  //if( md.isInitStatus() ) {


//   md.anConf.addSample( "WZJetsTo3LNu"                   , "WZ", kOrange-4); 
//   //md.anConf.addSample( "TTJets"     , "t#bar{t}", kBlue+1); 
//   md.anConf.addSample( "SMS_T1tttt_2J_mGl1200_mLSP800", "T1tttt (1.2/0.8) sig * 20", kViolet-3);
// 
//   md.anConf.addSample( "WJetsToLNu_HT100to200"         , "W+Jets", kAzure-2); 
//   md.anConf.addSample( "WJetsToLNu_HT200to400"         , "W+Jets", kAzure-2);  
//   md.anConf.addSample( "WJetsToLNu_HT400to600"         , "W+Jets", kAzure-2); 
//   md.anConf.addSample( "WJetsToLNu_HT600toInf"         , "W+Jets", kAzure-2); 
//  
//   //md.anConf.addSample( "DYJetsToLL_M50"                      , "Z+Jets", kAzure+6); 
//   md.anConf.addSample( "DYJetsToLL_M50_HT100to200"    , "Z+Jets", kAzure+6); 
//   md.anConf.addSample( "DYJetsToLL_M50_HT200to400"    , "Z+Jets", kAzure+6); 
//   md.anConf.addSample( "DYJetsToLL_M50_HT400to600"    , "Z+Jets", kAzure+6); 
//   md.anConf.addSample( "DYJetsToLL_M50_HT600toInf"    , "Z+Jets", kAzure+6); 
// 
//   md.anConf.addSample( "TTJets"     , "t#bar{t}", kBlue+1); 
// 
//   md.anConf.addSample("TToLeptons_sch"     , "Single top", kBlue+3);
//   md.anConf.addSample("TToLeptons_tch"     , "Single top", kBlue+3);
//   md.anConf.addSample("T_tWch"     , "Single top", kBlue+3);
//   md.anConf.addSample("TBarToLeptons_sch"     , "Single top", kBlue+3);
//   md.anConf.addSample("TBarToLeptons_tch"     , "Single top", kBlue+3);
//   md.anConf.addSample("TBar_tWch"     , "Single top", kBlue+3);
// 
//   md.anConf.addSample( "TTWJets"                        , "rare", kOrange-2); 
//   md.anConf.addSample( "TTZJets"                        , "rare", kOrange-2); 
//   //md.anConf.addSample( "WZJetsTo3LNu"                   , "rare", kOrange-2); 
//   md.anConf.addSample( "ZZTo4L"                   , "rare", kOrange-2); 
//   md.anConf.addSample( "TTH"                   , "rare", kOrange-2); 
// /*
//   md.anConf.addSample( "SMS_T1tttt_2J_mGl1200_mLSP800", "T1tttt (1.2/0.8) sig * 20", kViolet-3);
//   //md.anConf.addSample( "SMS_T1tttt_2J_mGl1500_mLSP100", "T1tttt (1.5/0.1) sig * 20", kViolet-3);
//   //md.anConf.addSample( "T1ttbbWW_mGo1300_mCh300_mChi290"                             , "T1ttbbWW (1.3/0.3) sig * 20", kBlue); 
//   md.anConf.addSample( "T1ttbbWW_mGo1000_mCh725_mChi720"                             , "T1ttbbWW (1.0/0.7) sig * 20", kBlue); 
//   md.anConf.addSample( "T5ttttDeg_mGo1000_mStop300_mChi280"                          , "T5tttt deg. (1.0/0.3, 4bd) sig * 20", kGreen+2); 
//   //md.anConf.addSample( "T5ttttDeg_mGo1000_mStop300_mCh285_mChi280"                   , "T5tttt deg. (1.0/0.3, Chi) sig * 20", kGreen+2); 
//   //md.anConf.addSample( "T6ttWW_mSbot650_mCh150_mChi50"                               , "T6ttWW (650/150/50) sig * 20", kRed+1); 
//   md.anConf.addSample( "T6ttWW_mSbot600_mCh425_mChi50"                               , "T6ttWW (600/425/50) sig * 20", kRed+1); 
//   md.anConf.addSample( "T5qqqqWW_mGo1200_mCh1000_mChi800_dilep"                            , "T5qqqqWW (1.2/0.8) sig * 20", kOrange+6); 
//   */
//  
// 
//   md.anConf.addSample( "TTWJets_aMCatNLO"                        , "TTWaMCatNLO", kBlue+3); 
//   md.anConf.addSample( "TTZJets_aMCatNLO"                        , "TTZaMCatNLO", kBlue+3); 
// 
//   md.anConf.addSample( "TTWJets"                        , "TTWmadgraph", kGreen-2); 
//   md.anConf.addSample( "TTZJets"                        , "TTZmadgraph", kGreen-2); 
//  


  //Santis version for WZ
/*
  md.anConf.addSample( "DYJetsToLL_M50_HT100to200"    , "fakes", kAzure+6); 
  md.anConf.addSample( "DYJetsToLL_M50_HT200to400"    , "fakes", kAzure+6); 
  md.anConf.addSample( "DYJetsToLL_M50_HT400to600"    , "fakes", kAzure+6); 
  md.anConf.addSample( "DYJetsToLL_M50_HT600toInf"    , "fakes", kAzure+6); 
  
  md.anConf.addSample( "TTJets"            , "fakes", kBlue+1); 
  //md.anConf.addSample( "TToLeptons_sch"    , "fakes", kBlue+1);
  //md.anConf.addSample( "TToLeptons_tch"    , "fakes", kBlue+1);
  //md.anConf.addSample( "T_tWch"            , "fakes", kBlue+1);
  //md.anConf.addSample( "TBarToLeptons_sch" , "fakes", kBlue+1);
  //md.anConf.addSample( "TBarToLeptons_tch" , "fakes", kBlue+1);
  //md.anConf.addSample( "TBar_tWch"         , "fakes", kBlue+1);
  
  md.anConf.addSample( "TTWJets"          , "t#bar{t}V", kBlue+3  ); 
  md.anConf.addSample( "TTZJets"          , "t#bar{t}V", kBlue+3  ); 
  md.anConf.addSample( "TTH"              , "t#bar{t}V", kBlue+3  );
  //  md.anConf.addSample( "ZZTo4L"           , "ZZ"       , kRed+2   );
  
  md.anConf.addSample( "WZJetsTo3LNu"     , "WZ"       , kOrange-2); 
*/
  
  //md.anConf.addSample( "TTJets"            , "TTJets", kRed+2); 


  //my 'a la Santi' processes for WZ study using available Spring 15 samples
  
  //md.anConf.addSample( "DYJetsToLL_M10to50"    , "fakes", kAzure+6);
//   md.anConf.addSample( "DYJetsToLL_M50"    , "fakes", kAzure+6);
//   md.anConf.addSample( "TTJets"            , "fakes", kBlue+1); 
//   //md.anConf.addSample( "TToLeptons_sch"    , "fakes", kBlue+1);
//   //md.anConf.addSample( "TToLeptons_tch"    , "fakes", kBlue+1);
//   //md.anConf.addSample( "T_tWch"            , "fakes", kBlue+1);
//   //md.anConf.addSample( "TBar_tWch"         , "fakes", kBlue+1);
// 
  //md.anConf.addSample( "WJetsToLNu_HT100to200"         , "W+Jets", kAzure-2); 
  //md.anConf.addSample( "WJetsToLNu_HT200to400"         , "W+Jets", kAzure-2);  
  //md.anConf.addSample( "WJetsToLNu_HT400to600"         , "W+Jets", kAzure-2); 
  //md.anConf.addSample( "WJetsToLNu_HT600toInf"         , "W+Jets", kAzure-2); 
  
  //md.anConf.addSample( "WJetsToLNu"         , "W+Jets", kAzure-2); 

  //md.anConf.addSample( "DYJetsToLL_M50"    , "Z+Jets", kAzure+6); 

  //md.anConf.addSample( "TTJets_50ns"            , "TTJets", kRed+2); 

  //md.anConf.addSample( "WZp8_50ns"     , "WZ"       , kOrange-2); 
// 
  // md.anConf.addSample( "TTJets"            , "TTJets", kRed+2); 
  
//   md.anConf.addSample("DYJetsToLL_LO_M50_50ns", "DYJetsToLL_LO_M50_50ns", 1);
//   md.anConf.addSample("DYJetsToLL_M10to50_50ns", "DYJetsToLL_M10to50_50ns", 2);
//   md.anConf.addSample("DYJetsToLL_M50_50ns", "DYJetsToLL_M50_50ns", 3);
//   md.anConf.addSample("TBar_tWch_50ns", "TBar_tWch_50ns", 4);
//   md.anConf.addSample("TTJets_50ns", "TTJets_50ns", 5);
//   md.anConf.addSample("TTJets_LO_50ns", "TTJets_LO_50ns", 6);
//   md.anConf.addSample("TToLeptons_tch_50ns", "TToLeptons_tch_50ns", 7);
//   md.anConf.addSample("TT_pow_50ns", "TT_pow_50ns", 8);
//   md.anConf.addSample("T_tWch_50ns", "T_tWch_50ns", 9);
//   md.anConf.addSample("WJetsToLNu_50ns", "WJetsToLNu_50ns", 10);
//   md.anConf.addSample("WWTo2L2Nu_50ns", "WWTo2L2Nu_50ns", 11);
//   md.anConf.addSample("WZp8_50ns", "WZp8_50ns", 12);
//   md.anConf.addSample("ZZp8_50ns", "ZZp8_50ns", 13);

  if (setproc == 0) {
    md.anConf.addSample("WJetsToLNu_50ns", "WJets(inc)", kAzure-2);
    md.anConf.addSample("DYJetsToLL_M50_50ns", "ZJets(inc)", kAzure+6);
    md.anConf.addSample("TT_pow_50ns", "tt(pow)", kRed+2);
    md.anConf.addSample("WZp8_50ns", "WZp8", kOrange-2);
  }
  
  else if (setproc==1) {
    md.anConf.addSample("DYJetsToLL_LO_M50_50ns", "ZJets(incLO)", 1);
    md.anConf.addSample("DYJetsToLL_M10to50_50ns", "ZJets(10Mll50)", 2);
    md.anConf.addSample("TTJets_50ns", "tt(aMCNLO)", 5);
    md.anConf.addSample("TTJets_LO_50ns", "tt(LO)", 6);
    md.anConf.addSample("WWTo2L2Nu_50ns", "WW(2l2n)", 11);
    md.anConf.addSample("ZZp8_50ns", "ZZp8", 13);
    md.anConf.addSample("TToLeptons_tch_50ns", "TToLep(tch)", 7);
    md.anConf.addSample("T_tWch_50ns", "tWch", 9);
    md.anConf.addSample("TBar_tWch_50ns", "tWch", 4);
  }
  
  else if (setproc == 2) {
    md.anConf.addSample("DYJetsToLL_LO_M50_50ns", "DYJetsToLL_LO_M50_50ns", 1);
      cout << "9" << endl;
    md.anConf.addSample("DYJetsToLL_M10to50_50ns", "DYJetsToLL_M10to50_50ns", 2);
    md.anConf.addSample("DYJetsToLL_M50_50ns", "DYJetsToLL_M50_50ns", 3);
    md.anConf.addSample("TBar_tWch_50ns", "TBar_tWch_50ns", 4);
    md.anConf.addSample("TTJets_50ns", "tt(aMCNLO)", 5);
    md.anConf.addSample("TTJets_LO_50ns", "tt(LO)", 6);
    md.anConf.addSample("TToLeptons_tch_50ns", "TToLeptons_tch_50ns", 7);
    md.anConf.addSample("TT_pow_50ns", "TT_pow_50ns", 8);
    md.anConf.addSample("T_tWch_50ns", "T_tWch_50ns", 9);
    md.anConf.addSample("WJetsToLNu_50ns", "WJetsToLNu_50ns", 10);
    md.anConf.addSample("WWTo2L2Nu_50ns", "WW(2l2n)", 11);
    md.anConf.addSample("WZp8_50ns", "WZp8_50ns", 12);
      cout << "10" << endl;
    md.anConf.addSample("ZZp8_50ns", "ZZp8_50ns", 13);
  
  }

  else if (setproc == 3) {
    md.anConf.addSample("DYJetsToLL_M10to50", "DYJetsToLL_M10to50", 1);
    md.anConf.addSample("DYJetsToLL_M50", "DYJetsToLL_M50", 2);
   // md.anConf.addSample("DYJetsToLL_M50_50ns", "DYJetsToLL_M50_50ns", 3);
    md.anConf.addSample("TBar_tWch", "TBar_tWch", 3);
   // md.anConf.addSample("TTJets_50ns", "tt(aMCNLO)", 5);
    md.anConf.addSample("TTJets_LO", "tt(LO)", 4);
    md.anConf.addSample("TToLeptons_sch", "TToLeptons_sch", 5);
    md.anConf.addSample("TToLeptons_tch", "TToLeptons_tch", 6);
  //  md.anConf.addSample("TT_pow_50ns", "TT_pow_50ns", 8);
    md.anConf.addSample("T_tWch", "T_tWch", 7);
    md.anConf.addSample("WJetsToLNu", "WJetsToLNu", 8);
    md.anConf.addSample("WWTo2L2Nu", "WW(2l2n)", 9);
    md.anConf.addSample("WZp8", "WZp8", 10);
    md.anConf.addSample("ZZp8", "ZZp8", 11);
  md.anConf.addSample( "DoubleEG_Run2015C_v1"              , "data", kBlack);
  md.anConf.addSample( "DoubleMuon_Run2015C_v1"            , "data", kBlack);
  md.anConf.addSample( "MuonEG_Run2015C_v1"                , "data", kBlack);
  md.anConf.addSample( "SingleElectron_Run2015C_v1"        , "data", kBlack);
  md.anConf.addSample( "SingleMuon_Run2015C_v1"            , "data", kBlack);
  }


  // }
  //===============================================================

  //*********************************************************************²
  //Execution macro ******************************************************
 
  //Configuration ================
  //if( md.isInitStatus() ) {
  
  //md.anConf.configureLumi( LumisXS, KFactors, lumi, useXS );
  // }

  //plotting ================
  md.dp.setLumiAndEnergy( lumi, energy );
  md.dp.setNormalization( Norm );
  md.dp.configureDisplay(yTitle, rangeY, rangeX, logYScale, xDiv,
          yDiv, binning, addBinBkg, overFlowBin,
          underFlowBin, showDMCRatio, showGrid,
          stacking, addSystematics, mcStatSyst,
          markerSize, lineWidth,summedSignal,
          mcOnly,cmsPrel, uncDet);

  md.prepareDisplay();
  md.doPlot();
  //md.makeDataCard(fileList, "global", "SR b-jet multiplicity");
/*  std::cout << "getStatistis_WZCR" << std::endl;  md.getStatistics("global_WZCR");
  std::cout << "getStatistis_2LepH" <<  std::endl;  md.getStatistics("global_2LepH");
  std::cout << "getStatistis_2LepHtH" <<  std::endl;  md.getStatistics("global_2LepHtH");
  std::cout << "getStatistis_2LepHtMetH" <<  std::endl;  md.getStatistics("global_2LepHtMetH");
  std::cout << "getStatistis_BR0H" <<  std::endl;  md.getStatistics("global_BR0H");*/
  std::cout << "getStatistis_WZSM" <<  std::endl;  md.getStatistics("global_WZSM");
  
  //std::cout << "getStatistics: " << "global" + s_region_dat << std::endl;
  //md.getStatistics("global" + s_region_dat);
  //md.getStatistics("global");
  //md.getStatistics("global_BR00H");
  //md.getStatistics("global_BR0H");
  //md.savePlot("phys14exerc");
  // md.dp.addText(xt,yt,st,addText);

  //gROOT->ProcessLine(".q");

}




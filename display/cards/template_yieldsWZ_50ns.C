MPAFDisplay md;

//string today = "150910";
void template_yieldsWZ_50ns(std::string var){
  gStyle->SetOptStat(0);

  md.refresh();
  
  //general parameters ********************* general parameters
  string dir="WZsynchro"; //_Jun16_WZCR_RA7comp";
  string fileName="template_WZ50";
  string fileList="template_WZ50";
  bool mcOnly = false;

  //observables **********************
  md.dp.setObservables(var);
  
  md.anConf.configureNames( dir, fileName, fileList );
  md.anConf.configureData(false, 0, mcOnly);
 
  //Binning & title ************************* Binning & title
  string yTitle="number of events";
  int binning=40;
  int addBinBkg=1; //BinB = binning*AddBin 
  double rangeY[2]={0, 0};
  double rangeX[2]={0., 500.};
  int xDiv[3]={8,6,0};
  int yDiv[3]={6,6,0}; //Nlabel /  sous-Div /ssdiv
  bool logYScale=false;
  if (var.find("miniRelIso") != std::string::npos && 
      (var.find("ttbar") != std::string::npos ||  
       var.find("ZMuMu") != std::string::npos ||  
       var.find("ZEE")   != std::string::npos)
      ) {
    logYScale = true;
  }
  bool overFlowBin=true;
  bool underFlowBin=false;
  bool showDMCRatio=false;
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

  string autoBinFile="WZ50binning";
  md.dp.loadAutoBinning(autoBinFile);

  //Systematic uncertainties ********************************
  bool addSystematics=false; 
  bool mcStatSyst=false;
  string systSources="";
  bool uncDet=false;
  
  //Lumis( or XSections ) pb-1 & KFactors ************************************
  string Norm="";
  
  float lumi=10000; //pb-1 19470
  float energy=13; //TeV

  bool useXS=true;
  map<string,float> LumisXS;
  map<string,float> KFactors;

  md.anConf.loadXSDB("XSectionsSpring15.db");
  //md.anConf.loadKFDB("kFactorsSpring15.db");
  md.anConf.configureLumi( LumisXS, KFactors, lumi, useXS );

  //===============================================================  
  /*
  md.anConf.addSample( "TBar_tWch_50ns"          , "Single top" ,  kGray+2); 
  md.anConf.addSample( "T_tWch_50ns"             , "Single top" ,  kGray+2);
  md.anConf.addSample( "TToLeptons_tch_50ns"     , "Single top" ,  kGray+2);
  //md.anConf.addSample( "TToLeptons_sch"     , "Single top" ,  kGray+2);
  md.anConf.addSample( "WJetsToLNu_50ns"         , "W+jets"     ,  kCyan+2);
  md.anConf.addSample( "WWTo2L2Nu_50ns"          , "VV"         ,  kViolet-4);
  md.anConf.addSample( "WZp8_50ns"               , "VV"         ,  kViolet-4);
  md.anConf.addSample( "ZZp8_50ns"               , "VV"         ,  kViolet-4);
  md.anConf.addSample( "TTJets_LO_50ns"          , "t#bar{t}"   ,  kGray  );
  md.anConf.addSample( "DYJetsToLL_M10to50_50ns" , "DY"         ,  kCyan  );
  md.anConf.addSample( "DYJetsToLL_M50_50ns"     , "DY"         ,  kCyan  );
  */
  
  md.anConf.addSample( "TBar_tWch_50ns"          , "TBar_tWch_50ns"         ,  1); 
  md.anConf.addSample( "T_tWch_50ns"             , "T_tWch_50ns"            ,  2);
  md.anConf.addSample( "TToLeptons_tch_50ns"     , "TToLeptons_tch_50ns"    ,  3);
  md.anConf.addSample( "TToLeptons_sch"     , "Single top" ,  kGray+2);
  md.anConf.addSample( "WJetsToLNu_50ns"         , "WJetsToLNu_50ns"        ,  4);
  md.anConf.addSample( "WWTo2L2Nu_50ns"          , "WWTo2L2Nu_50ns"         ,  5);
  md.anConf.addSample( "WZp8_50ns"               , "WZp8_50ns"              ,  6);
  md.anConf.addSample( "ZZp8_50ns"               , "ZZp8_50ns"              ,  7);
  md.anConf.addSample( "TTJets_LO_50ns"          , "TTJets_LO_50ns"         ,  8);
  md.anConf.addSample( "TTJets_50ns"             , "TTJets_50ns"            ,  9);
  md.anConf.addSample( "TT_pow_50ns"             , "TT_pow_50ns"            ,  10);
  md.anConf.addSample( "DYJetsToLL_M10to50_50ns" , "DYJetsToLL_M10to50_50ns",  11);
  md.anConf.addSample( "DYJetsToLL_M50_50ns"     , "DYJetsToLL_M50_50ns"    ,  12);
  md.anConf.addSample( "DYJetsToLL_LO_M50_50ns"  , "DYJetsToLL_LO_M50_50ns" ,  13);
  
  
  // the order MATTERS!!!
  /* 
  md.anConf.addSample( "DoubleEG_Run2015C_v1"              , "data", kBlack);
  md.anConf.addSample( "DoubleMuon_Run2015C_v1"            , "data", kBlack);
  md.anConf.addSample( "MuonEG_Run2015C_v1"                , "data", kBlack);
  md.anConf.addSample( "SingleElectron_Run2015C_v1"        , "data", kBlack);
  md.anConf.addSample( "SingleMuon_Run2015C_v1"            , "data", kBlack);
  */
  /*
  md.anConf.addSample( "DoubleEG_Run2015B_17Jul2015_runs_251244_251562"              , "data", kBlack);
  md.anConf.addSample( "DoubleEG_Run2015B_v1_runs_251643_251883"              , "data", kBlack);
  md.anConf.addSample( "DoubleMuon_Run2015B_17Jul2015_runs_251244_251562"            , "data", kBlack);
  md.anConf.addSample( "DoubleMuon_Run2015B_v1_runs_251643_251883"            , "data", kBlack);
  md.anConf.addSample( "MuonEG_Run2015B_17Jul2015_runs_251244_251562"                , "data", kBlack);
  md.anConf.addSample( "MuonEG_Run2015B_v1_runs_251643_251883"                , "data", kBlack);
  md.anConf.addSample( "SingleElectron_Run2015B_17Jul2015_runs_251244_251562"        , "data", kBlack);
  md.anConf.addSample( "SingleElectron_Run2015B_v1_runs_251643_251883"        , "data", kBlack);
  md.anConf.addSample( "SingleMuon_Run2015B_17Jul2015_runs_251244_251562"            , "data", kBlack);
  md.anConf.addSample( "SingleMuon_Run2015B_v1_runs_251643_251883"            , "data", kBlack);
  */
//  //===============================================================
  
  //*********************************************************************²
  //Execution macro ******************************************************
  
  //Configuration ================
  
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
  md.getStatistics("global");
  //md.savePlot(dir);
  
  //gROOT->ProcessLine(".q");
}

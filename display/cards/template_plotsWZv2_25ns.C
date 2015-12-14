MPAFDisplay md;
// template plot producer for WZ validation plots, called by Sub_SynchroPlots850_WZ25.sh
//string today = "150910";
void template_plotsWZv2_25ns(std::string var,std::string fileName){
  gStyle->SetOptStat(0);

  md.refresh();
  
  //general parameters ********************* general parameters
  string dir="WZsynchro"; 
  //string fileName="template_WZ25";
  //string fileList="template_WZ25";
  string fileList=fileName;
  bool mcOnly = true;

  //observables **********************
  md.dp.setObservables(var);
  
  md.anConf.configureNames( dir, fileName, fileList );
  md.anConf.configureData(false, 0, mcOnly);
 
  //Binning & title ************************* Binning & title
  string yTitle="number of events";
  int binning=40;
  int addBinBkg=1; //BinB = binning*AddBin 
  double rangeY[2]={0 , 0};
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
  /*if (var.find("M3l") != std::string::npos){
      logYScale = true;
      rangeY[0]={0.1};
      rangeY[1]={100000.};
  }*/
  
  bool overFlowBin=true;
  bool underFlowBin=true;
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

  string autoBinFile="WZ50binning_rebin1";
  md.dp.loadAutoBinning(autoBinFile);

  //Systematic uncertainties ********************************
  bool addSystematics=false; 
  bool mcStatSyst=false;
  string systSources="";
  bool uncDet=false;
  
  //Lumis( or XSections ) pb-1 & KFactors ************************************
  string Norm="";
  
  float lumi=1263.9; //pb-1 19470 // runs 
  float energy=13; //TeV

  bool useXS=true;
  map<string,float> LumisXS;
  map<string,float> KFactors;

  md.anConf.loadXSDB("XSectionsSpring15_UO.db");
  //md.anConf.loadKFDB("kFactorsSpring15.db");
  md.anConf.configureLumi( LumisXS, KFactors, lumi, useXS );

  //===============================================================  
      //md.anConf.addSample( "WZTo3LNu"                    , "WZp8"         ,  kGreen+3);

/*
  md.anConf.addSample( "Tree_WZTo3LNu_0"         , "WZ"         ,  kGreen+3);
  md.anConf.addSample( "Tree_DYJetsToLL_M10to50_aMCatNLO_0","DY",  kCyan  );
  md.anConf.addSample( "Tree_DYJetsToLL_M50_aMCatNLO"      ,"DY",  kCyan  );
  md.anConf.addSample( "Tree_TW_0"               , "Single top" ,  kGray+2);
  md.anConf.addSample( "Tree_TbarW_0"            , "Single top" ,  kGray+2); 
  md.anConf.addSample( "Tree_TToLeptons_sch_0"   , "Single top" ,  kGray+2); 
  md.anConf.addSample( "Tree_TToLeptons_tch_0"   , "Single top" ,  kGray+2); 
  md.anConf.addSample( "Tree_TbarToLeptons_tch_0", "Single top" ,  kGray+2); 
  md.anConf.addSample( "Tree_WJetsToLNu_aMCatNLO_0"       , "W+jets"     ,  kCyan+2);
  //md.anConf.addSample( "Tree_WWTo2L2Nu_0"        , "WW"         ,  kSpring+10);
  md.anConf.addSample( "Tree_WW_0"               , "WW"         ,  kSpring+10);
  md.anConf.addSample( "Tree_ZZ_0"               , "ZZ"         ,  kViolet-5);
  md.anConf.addSample( "Tree_GGHZZ4L_0"          , "ZZ"         ,  kViolet-5);
  md.anConf.addSample( "Tree_TTJets"             , "t#bar{t}"   ,  kRed   );
  //md.anConf.addSample( "Tree_TTLep_pow_0"        , "t#bar{t}"   ,  kRed   );
  //md.anConf.addSample( "Tree_TTLep_pow_1"        , "t#bar{t}"   ,  kRed   );
  md.anConf.addSample( "Tree_TTWToLNu_0"         , "t#bar{t}W"  ,  kMagenta-10);
  md.anConf.addSample( "Tree_TTZToLLNuNu_0"      , "t#bar{t}Z"  ,  kBlue  );
  md.anConf.addSample( "Tree_TTHnobb_0"          , "t#bar{t}H"  ,  kOrange+3  );
  md.anConf.addSample( "Tree_TTGJets_0"          , "t#bar{t}#gamma"    ,  kOrange-1  );
*/

  md.anConf.addSample( "Tree_WZTo3LNu_0"         , "WZ"         ,  kOrange-2);
  md.anConf.addSample( "Tree_DYJetsToLL_M10to50_aMCatNLO_0","Z+jets",  kGreen+2 );
  md.anConf.addSample( "Tree_DYJetsToLL_M50_aMCatNLO"      ,"Z+jets",  kGreen+2 );
  md.anConf.addSample( "Tree_TW_0"               , "Single top" ,  kYellow-6);
  md.anConf.addSample( "Tree_TbarW_0"            , "Single top" ,  kYellow-6); 
  md.anConf.addSample( "Tree_TToLeptons_sch_0"   , "Single top" ,  kYellow-6); 
  md.anConf.addSample( "Tree_TToLeptons_tch_0"   , "Single top" ,  kYellow-6); 
  md.anConf.addSample( "Tree_TbarToLeptons_tch_0", "Single top" ,  kYellow-6); 
  md.anConf.addSample( "Tree_WJetsToLNu_aMCatNLO_0","W+jets"    ,  kAzure-9);
  //md.anConf.addSample( "Tree_WWTo2L2Nu_0"        , "WW"         ,  kSpring+10);
  md.anConf.addSample( "Tree_WW_0"               , "WW"         ,  kAzure-7);
  md.anConf.addSample( "Tree_WGToLNuG_0"         , "W#gamma"    ,  kBlue);
  md.anConf.addSample( "Tree_ZZ_0"               , "ZZ"         ,  kRed+3);
  md.anConf.addSample( "Tree_GGHZZ4L_0"          , "ZZ"         ,  kRed+3);
  md.anConf.addSample( "Tree_TTJets"             , "t#bar{t}"   ,  kYellow  );
  //md.anConf.addSample( "Tree_TTLep_pow_0"        , "t#bar{t}"   ,  kRed   );
  //md.anConf.addSample( "Tree_TTLep_pow_1"        , "t#bar{t}"   ,  kRed   );
  md.anConf.addSample( "Tree_TTWToLNu_0"         , "t#bar{t}W"  ,  kGreen-6);
  md.anConf.addSample( "Tree_TTZToLLNuNu_0"      , "t#bar{t}Z"  ,  kRed  );
  md.anConf.addSample( "Tree_TTHnobb_0"          , "t#bar{t}H"  ,  kOrange+3  );
  md.anConf.addSample( "Tree_TTGJets_0"          , "t#bar{t}#gamma",kOrange-1 );
  
  // the order MATTERS!!!
  
  md.anConf.addSample( "Tree_DoubleEG_Run2015D_05Oct_0"       , "data", kBlack);
  md.anConf.addSample( "Tree_DoubleEG_Run2015D_v4_0"      , "data", kBlack);
  md.anConf.addSample( "Tree_DoubleMuon_Run2015D_05Oct_0"     , "data", kBlack);
  md.anConf.addSample( "Tree_DoubleMuon_Run2015D_v4_0"    , "data", kBlack);
  md.anConf.addSample( "Tree_MuonEG_Run2015D_05Oct_0"         , "data", kBlack);
  md.anConf.addSample( "Tree_MuonEG_Run2015D_v4_0"        , "data", kBlack); 

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
  //md.getStatistics("global");
  md.savePlot(dir);
  
  //gROOT->ProcessLine(".q");
}

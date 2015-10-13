MPAFDisplay md;
// template plot producer for WZ validation plots, called by Sub_SynchroPlots200_WZ25.sh
//string today = "150910";
void template_plotsWZ200_25ns(std::string var,std::string fileName){
  gStyle->SetOptStat(0);

  md.refresh();
  
  //general parameters ********************* general parameters
  string dir="WZsynchro"; 
  //string fileName="template_WZ25";
  //string fileList="template_WZ25";
  string fileList=fileName;
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
  if (var.find("M3l") != std::string::npos) logXScale = true;
  
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
  
  float lumi=205; //pb-1 19470
  float energy=13; //TeV

  bool useXS=true;
  map<string,float> LumisXS;
  map<string,float> KFactors;

  md.anConf.loadXSDB("XSectionsSpring15.db");
  //md.anConf.loadKFDB("kFactorsSpring15.db");
  md.anConf.configureLumi( LumisXS, KFactors, lumi, useXS );

  //===============================================================  
      //md.anConf.addSample( "WZTo3LNu"                    , "WZp8"         ,  kGreen+3);
      /*
  md.anConf.addSample( "TBar_tWch"               , "Single top" ,  kGray+2); 
  md.anConf.addSample( "T_tWch"                  , "Single top" ,  kGray+2);
  md.anConf.addSample( "TToLeptons_tch"          , "Single top" ,  kGray+2);
  md.anConf.addSample( "TToLeptons_sch"          , "Single top" ,  kGray+2);
  md.anConf.addSample( "WJetsToLNu"              , "W+jets"     ,  kCyan+2);
  md.anConf.addSample( "WWTo2L2Nu"               , "WW"         ,  kSpring+10);
  md.anConf.addSample( "WZp8"                    , "WZ"         ,  kGreen+3);
  md.anConf.addSample( "ZZp8"                    , "ZZ"         ,  kViolet-4);
  md.anConf.addSample( "TTJets_LO"               , "t#bar{t}"   ,  kRed   );
  md.anConf.addSample( "DYJetsToLL_M10to50"      , "DY"         ,  kCyan  );
  md.anConf.addSample( "DYJetsToLL_M50"          , "DY"         ,  kCyan  );
  */

  md.anConf.addSample( "WZp8"                    , "WZ"         ,  kGreen+3);
  md.anConf.addSample( "DYJetsToLL_M10to50"      , "DY"         ,  kCyan  );
  md.anConf.addSample( "DYJetsToLL_M50"          , "DY"         ,  kCyan  );
  md.anConf.addSample( "TBar_tWch"               , "Single top" ,  kGray+2); 
  md.anConf.addSample( "T_tWch"                  , "Single top" ,  kGray+2);
  md.anConf.addSample( "TToLeptons_tch"          , "Single top" ,  kGray+2);
  md.anConf.addSample( "TToLeptons_sch"          , "Single top" ,  kGray+2);
  md.anConf.addSample( "WJetsToLNu"              , "W+jets"     ,  kCyan+2);
  md.anConf.addSample( "WWTo2L2Nu"               , "WW"         ,  kSpring+10);
  md.anConf.addSample( "ZZp8"                    , "ZZ"         ,  kViolet-4);
  md.anConf.addSample( "TT_pow"                  , "t#bar{t}"   ,  kRed   );
  md.anConf.addSample( "TTWToLNu"                , "t#bar{t}W"         ,  kMagenta  );
  md.anConf.addSample( "TTZToLLNuNu"             , "t#bar{t}Z"         ,  kBlue  );
  md.anConf.addSample( "TTHnobb_pow"                 , "t#bar{t}H"         ,  kOrange+3  );
  
  
  // the order MATTERS!!!
  
  md.anConf.addSample( "DoubleEG_Run2015D_v3_runs_256630_257599"              , "data", kBlack);
  md.anConf.addSample( "DoubleMuon_Run2015D_v3_runs_256630_257599"            , "data", kBlack);
  md.anConf.addSample( "MuonEG_Run2015D_v3_runs_256630_257599"                , "data", kBlack);
  md.anConf.addSample( "SingleElectron_Run2015D_v3_runs_256630_257599"        , "data", kBlack);
  md.anConf.addSample( "SingleMuon_Run2015D_v3_runs_256630_257599"            , "data", kBlack);
  

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

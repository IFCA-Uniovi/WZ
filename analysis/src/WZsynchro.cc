#include "analysis/src/WZsynchro.hh"

#include <algorithm>
#include <sstream>
#include <iostream>

WZsynchro::WZsynchro(std::string cfg){

  startExecution(cfg);
  initialize();

}

WZsynchro::~WZsynchro(){
 
}

void
WZsynchro::initialize(){


  _vc->registerVar("run"                          );
  _vc->registerVar("lumi"                         );
  _vc->registerVar("evt"                          );
  _vc->registerVar("HLT_SingleEl"                 );
  _vc->registerVar("isData"                       );
  _vc->registerVar("HLT_SingleMu"                 );
  _vc->registerVar("HLT_SingleEl50ns"             );
  _vc->registerVar("HLT_SingleMu50ns"             );
  _vc->registerVar("HLT_MuEG"                     );
  _vc->registerVar("HLT_TripleEl"                 );
  _vc->registerVar("HLT_DoubleEl"                 );
  _vc->registerVar("HLT_DoubleMu"                 );
  _vc->registerVar("nVert"                        );
  _vc->registerVar("nTrueInt"                     );
  _vc->registerVar("nTrueInt"                     );
  _vc->registerVar("nBJetPt40Medium"              );
  _vc->registerVar("puWeight"                     );
  _vc->registerVar("genWeight"                    );
  _vc->registerVar("nLepGood"                     );
  _vc->registerVar("LepGood_pt"                   );
  _vc->registerVar("LepGood_eta"                  );
  _vc->registerVar("LepGood_etaSc"                );
  _vc->registerVar("LepGood_tightId"              );
  _vc->registerVar("LepGood_phi"                  );
  _vc->registerVar("LepGood_charge"               );
  _vc->registerVar("LepGood_tightCharge"          );
  _vc->registerVar("LepGood_mediumMuonId"         );
  _vc->registerVar("LepGood_mvaIdPhys14"          );
  _vc->registerVar("LepGood_mvaIdSpring15"        );
  _vc->registerVar("LepGood_pdgId"                );
  _vc->registerVar("LepGood_relIso03"             );
  _vc->registerVar("LepGood_relIso04"             );
  _vc->registerVar("LepGood_trackIso"             );
  _vc->registerVar("LepGood_jetPtRatio"           );
  _vc->registerVar("LepGood_jetPtRatio_LepAwareJEC");
  _vc->registerVar("LepGood_jetPtRatiov2"         );
  _vc->registerVar("LepGood_jetPtRel"             );
  _vc->registerVar("LepGood_jetPtRelv2"           );
  _vc->registerVar("LepGood_jetBTagCSV"           );
  _vc->registerVar("LepGood_miniRelIso"           );
  _vc->registerVar("LepGood_dxy"                  );
  _vc->registerVar("LepGood_dz"                   );
  _vc->registerVar("LepGood_sip3d"                );
  _vc->registerVar("LepGood_convVeto"             );
  _vc->registerVar("LepGood_lostHits"             );
  _vc->registerVar("LepGood_mvaSusy"              );
  _vc->registerVar("LepGood_mcMatchId"            );
  _vc->registerVar("LepGood_mcMatchAny"           );

  _vc->registerVar("LepGood_ecalPFClusterIso"     );
  _vc->registerVar("LepGood_hcalPFClusterIso"     );
  _vc->registerVar("LepGood_dr03TkSumPt"          );
  _vc->registerVar("LepGood_jetLepAwareJEC_pt"    );
  _vc->registerVar("LepGood_jetLepAwareJEC_eta"    );
  _vc->registerVar("LepGood_jetLepAwareJEC_phi"    );
  _vc->registerVar("LepGood_jetLepAwareJEC_energy"    );
  _vc->registerVar("LepGood_jetCorrFactor_L1L2L3Res"    );
  
  _vc->registerVar("met_pt"                       );
  _vc->registerVar("met_eta"                      );
  _vc->registerVar("met_phi"                      );
  _vc->registerVar("met_mass"                     );
  _vc->registerVar("metNoHF_pt"                   );
  _vc->registerVar("metNoHF_eta"                  );
  _vc->registerVar("metNoHF_phi"                  );
  _vc->registerVar("metNoHF_mass"                 );
  
  _vc->registerVar("nJet25"                       );
  _vc->registerVar("nJet40"                       );
  _vc->registerVar("nJet"                         );
  _vc->registerVar("Jet_id"                       );
  _vc->registerVar("Jet_pt"                       );
  _vc->registerVar("Jet_rawPt"                    );
  _vc->registerVar("Jet_eta"                      );
  _vc->registerVar("Jet_phi"                      );
  _vc->registerVar("Jet_mass"                     );
  _vc->registerVar("Jet_btagCSV"                  );
  _vc->registerVar("Jet_CorrFactor_L1"            );
  _vc->registerVar("Jet_CorrFactor_L1L2L3Res"     );

  _vc->registerVar("nJetFwd"                      );
  _vc->registerVar("JetFwd_pt"                    );
  _vc->registerVar("JetFwd_phi"                   );
  _vc->registerVar("JetFwd_eta"                   );

  _vc->registerVar("htJet40j"                     );
  _vc->registerVar("minMllAFAS"                   );
  _vc->registerVar("minMllAFOS"                   );
  _vc->registerVar("mZ1"                          );
  _vc->registerVar("nLepGood10"                   );
  _vc->registerVar("m3l"                          );
 
  //generator informations
  _vc->registerVar("nGenPart"                     );
  _vc->registerVar("GenPart_pt"                   );
  _vc->registerVar("GenPart_eta"                  );
  _vc->registerVar("GenPart_phi"                  );
  _vc->registerVar("GenPart_pdgId"                );
  _vc->registerVar("GenPart_motherId"             );

  //LHE gen level weights
  _vc->registerVar("nLHEweight"                   );
  _vc->registerVar("LHEweight_id"                 );
  _vc->registerVar("LHEweight_wgt"                );

  //bjets
  _vc->registerVar("nBJetLoose25"                 );
  _vc->registerVar("nBJetMedium40"                );
  _vc->registerVar("nBJetMedium25"                );
  _vc->registerVar("nBJetTight40"                 );
  _vc->registerVar("nSoftBJetMedium25"            );

  //Discarded (they don't pass the cleaning at Heppy level) jets
  _vc->registerVar("nDiscJet"                     );
  _vc->registerVar("DiscJet_id"                   );
  _vc->registerVar("DiscJet_pt"                   );
  _vc->registerVar("DiscJet_rawPt"                );
  _vc->registerVar("DiscJet_eta"                  );
  _vc->registerVar("DiscJet_phi"                  );
  _vc->registerVar("DiscJet_mass"                 );
  _vc->registerVar("DiscJet_btagCSV"              );
  

  //minitree variables
  _vc->registerVar("iL1TV_Mini" );
  _vc->registerVar("iL2TV_Mini" );
  _vc->registerVar("nLepGood10_Mini" );
  _vc->registerVar("nLepTightVeto10_Mini" );
  _vc->registerVar("nLepGood_Mini");
  _vc->registerVar("nLepTightVeto_Mini");
  _vc->registerVar("mZ1cut10TL_Mini" );
  _vc->registerVar("minMllAFOSTL_Mini" );
  _vc->registerVar("minMllAFASTL_Mini" );
  _vc->registerVar("nJet40_Mini" );
  _vc->registerVar("htJet40j_Mini" );
  // _vc->registerVar("_Mini" );
  _vc->registerVar("nBJetMedium25_Mini" );
  
  // FLAGS
  _vc->registerVar("hbheFilterNew25ns"            );
  _vc->registerVar("hbheFilterIso"                );
  _vc->registerVar("Flag_CSCTightHaloFilter"      );
  _vc->registerVar("Flag_eeBadScFilter"           );
  _vc->registerVar("Flag_goodVertices"            );
  
  //pileup
  _vc->registerVar("puWeight"                     );
  _vc->registerVar("vtxWeight"                    );
  
  // for loose leptons used in jet cleaning
  _vc->registerVar("LepGood_sigmaIEtaIEta"        );
  _vc->registerVar("LepGood_sigmaIEtaIEta_full5x" );
  _vc->registerVar("LepGood_hadronicOverEm"       );
  _vc->registerVar("LepGood_dEtaScTrkIn"          );
  _vc->registerVar("LepGood_dPhiScTrkIn"          );
  _vc->registerVar("LepGood_eInvMinusPInv"        );
  
  // HLT paths
  _vc->registerVar("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v");
  _vc->registerVar("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v");
  _vc->registerVar("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v");
  _vc->registerVar("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v");
  _vc->registerVar("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v");
  


  _wzMod = new WZModule(_vc, _dbm);

  int nCateg=156; //78 156
  _categs.resize(nCateg);
  string srs[156]={ 

    "SR1A", "SR2A", "SR3A", "SR4A", "SR5A", "SR6A", "SR7A", "SR8A",
    "SR9A", "SR10A", "SR11A", "SR12A", "SR13A", "SR14A", "SR15A", "SR16A",
    "SR17A", "SR18A", "SR19A", "SR20A", "SR21A", "SR22A", "SR23A", "SR24A",
    "SR25A", "SR26A", "SR27A", "SR28A", "SR29A", "SR30A", "SR31A", "SR32A",
    
    "SR1B", "SR2B", "SR3B", "SR4B", "SR5B", "SR6B", "SR7B", "SR8B",
    "SR9B", "SR10B", "SR11B", "SR12B", "SR13B", "SR14B", "SR15B", "SR16B",
    "SR17B", "SR18B", "SR19B", "SR20B", "SR21B", "SR22B", "SR23B", "SR24B",
    "SR25B","SR26B",
    
    "SR1C", "SR2C", "SR3C", "SR4C", "SR5C", "SR6C", "SR7C", "SR8C",

    //"BR0H", "BR0M", "BR0L",

    "BR00H", "BR00M", "BR00L",
    "BR10H", "BR10M", "BR10L",
    "BR20H", "BR20M", "BR20L",
    "BR30H", "BR30M", "BR30L",
    
    // //fake workflows ==================================================

    "SR1A_Fake", "SR2A_Fake", "SR3A_Fake", "SR4A_Fake", "SR5A_Fake", "SR6A_Fake", "SR7A_Fake", "SR8A_Fake",
    "SR9A_Fake", "SR10A_Fake", "SR11A_Fake", "SR12A_Fake", "SR13A_Fake", "SR14A_Fake", "SR15A_Fake", "SR16A_Fake",
    "SR17A_Fake", "SR18A_Fake", "SR19A_Fake", "SR20A_Fake", "SR21A_Fake", "SR22A_Fake", "SR23A_Fake", "SR24A_Fake",
    "SR25A_Fake", "SR26A_Fake", "SR27A_Fake", "SR28A_Fake", "SR29A_Fake", "SR30A_Fake", "SR31A_Fake", "SR32A_Fake",
    
    "SR1B_Fake", "SR2B_Fake", "SR3B_Fake", "SR4B_Fake", "SR5B_Fake", "SR6B_Fake", "SR7B_Fake", "SR8B_Fake",
    "SR9B_Fake", "SR10B_Fake", "SR11B_Fake", "SR12B_Fake", "SR13B_Fake", "SR14B_Fake", "SR15B_Fake", "SR16B_Fake",
    "SR17B_Fake", "SR18B_Fake", "SR19B_Fake", "SR20B_Fake", "SR21B_Fake", "SR22B_Fake", "SR23B_Fake", "SR24B_Fake",
    "SR25B_Fake","SR26B_Fake",
    
    "SR1C_Fake", "SR2C_Fake", "SR3C_Fake", "SR4C_Fake", "SR5C_Fake", "SR6C_Fake", "SR7C_Fake", "SR8C_Fake",



    "BR00H_Fake", "BR00M_Fake", "BR00L_Fake",
    "BR10H_Fake", "BR10M_Fake", "BR10L_Fake",
    "BR20H_Fake", "BR20M_Fake", "BR20L_Fake",
    "BR30H_Fake", "BR30M_Fake", "BR30L_Fake",

 
  };
  _categs.assign(srs, srs+nCateg);

  for(size_t ic=0;ic< _categs.size();ic++) {
    _SR = _categs[ic];
    //setSignalRegions();
    //addWorkflow( ic+1, _categs[ic] );
  }

  addWorkflow( kGlobalFake, "Fake" );
  addWorkflow( kWZCR, "WZCR");
  //addWorkflow( kGlobalmId, "mId" );  
  addWorkflow( kWZSM, "WZSM");
  addWorkflow( kWZSM_3l, "WZSMstep0");
  addWorkflow( kWZSM_3lwz, "WZSMstep1");
  addWorkflow( kWZSM_3lwzZsel, "WZSMstep2");
  addWorkflow( kWZSM_3lwzZselWsel, "WZSMstep3");
  addWorkflow( kWZSM_3lwzZselWselM3l, "WZSMstep4");
  addWorkflow( kWZSM_3lwzZselWselM3lNbj1, "WZSMstep5");
  addWorkflow( kWZSM_3lwzZselWselM3lNbj0, "WZSMstep6");  
  
  //extra input variables
  _lepflav = getCfgVarS("LEPFLAV","all");
  _leppt   = getCfgVarS("LEPPT"  ,"all");
  _SR      = getCfgVarS("SR"     ,"SRFLAG");
  _FR      = getCfgVarS("FR"     ,"FO2C");
  _LHESYS  = getCfgVarI("LHESYS", 0);
  _categorization = getCfgVarI("categorization",1);
  _DoValidationPlots = getCfgVarI("ValidationPlots",1);
  //_WZstep = getCfgVarI("WZstep",6);
  _DoCheckPlots = getCfgVarI("CheckPlots",0);
  _DoEventDump = getCfgVarI("EventDump",0);
  _DoPupiDump = getCfgVarI("PupiDump",0);


//  vector<string> jess;
//  jess.push_back("Jet_pt");
//  addSystSource("JES",SystUtils::kNone, "%", jess, "JES8TeV.db", "" );
  
  //FR databases
  if(_FR=="FO2C") {
    _dbm->loadDb("ElNIso"    , "FR_Nov2.root", "FRElPtCorr_UCSX_non");
    _dbm->loadDb("MuNIso"    , "FR_Nov2.root", "FRMuPtCorr_UCSX_non");
    _dbm->loadDb("ElIso"     , "FR_Nov2.root", "FRElPtCorr_UCSX_iso");
    _dbm->loadDb("MuIso"     , "FR_Nov2.root", "FRMuPtCorr_UCSX_iso");

    _dbm->loadDb("ElNIsoMC"  , "FR_Nov2.root", "FRElPtCorr_qcd_non");
    _dbm->loadDb("MuNIsoMC"  , "FR_Nov2.root", "FRMuPtCorr_qcd_non");
    _dbm->loadDb("ElIsoMC"   , "FR_Nov2.root", "FRElPtCorr_qcd_iso");
    _dbm->loadDb("MuIsoMC"   , "FR_Nov2.root", "FRMuPtCorr_qcd_iso");

    _dbm->loadDb("ElNIsoUp"  , "FR_Nov2.root", "FRElPtCorr_UCSX_HI_non");
    _dbm->loadDb("MuNIsoUp"  , "FR_Nov2.root", "FRMuPtCorr_UCSX_HI_non");
    _dbm->loadDb("ElIsoUp"   , "FR_Nov2.root", "FRElPtCorr_UCSX_HI_iso");
    _dbm->loadDb("MuIsoUp"   , "FR_Nov2.root", "FRMuPtCorr_UCSX_HI_iso");
    
    _dbm->loadDb("ElNIsoMCUp", "FR_Nov2.root", "FRElPtCorr_qcd_non");
    _dbm->loadDb("MuNIsoMCUp", "FR_Nov2.root", "FRMuPtCorr_qcd_non");
    _dbm->loadDb("ElIsoMCUp" , "FR_Nov2.root", "FRElPtCorr_qcd_iso");
    _dbm->loadDb("MuIsoMCUp" , "FR_Nov2.root", "FRMuPtCorr_qcd_iso");
    
    _dbm->loadDb("ElNIsoDo"  , "FR_Nov2.root", "FRElPtCorr_UCSX_LO_non");
    _dbm->loadDb("MuNIsoDo"  , "FR_Nov2.root", "FRMuPtCorr_UCSX_LO_non");
    _dbm->loadDb("ElIsoDo"   , "FR_Nov2.root", "FRElPtCorr_UCSX_LO_iso");
    _dbm->loadDb("MuIsoDo"   , "FR_Nov2.root", "FRMuPtCorr_UCSX_LO_iso");

    _dbm->loadDb("ElNIsoMCDo", "FR_Nov2.root", "FRElPtCorr_qcd_non");
    _dbm->loadDb("MuNIsoMCDo", "FR_Nov2.root", "FRMuPtCorr_qcd_non");
    _dbm->loadDb("ElIsoMCDo" , "FR_Nov2.root", "FRElPtCorr_qcd_iso");
    _dbm->loadDb("MuIsoMCDo" , "FR_Nov2.root", "FRMuPtCorr_qcd_iso");
  }
  if(_FR=="FO4C") {
    _dbm->loadDb("El","MaySync/CH_FRFile_090615.root","tt/nosel/FRISisofo4RElPtMIso2");
    _dbm->loadDb("Mu","MaySync/CH_FRFile_090615.root","tt/nosel/FRISisofo4RMuPtMIso2");
  }

  //chargeflip DB
  //_dbm->loadDb("chargeMId","superDB.db");
  
  
  //chargeflip DB
  _dbm->loadDb("chargeMId"  , "flipMapUCSX.root", "flipMapUCSX");
  _dbm->loadDb("chargeMIdMC", "flipMapUCSX.root", "flipMapUCSX");
  
  // SF DB
  _dbm->loadDb("hltSF"      , "hltSF.db"                                           ); 
  _dbm->loadDb("BTagSF"     , "BTagSFMedium.db"                                    ); 
  _dbm->loadDb("BTagEffUSDG", "GC_BTagEffs.root", "h2_BTaggingEff_csv_med_Eff_udsg");
  _dbm->loadDb("BTagEffC"   , "GC_BTagEffs.root", "h2_BTaggingEff_csv_med_Eff_c"   );
  _dbm->loadDb("BTagEffB"   , "GC_BTagEffs.root", "h2_BTaggingEff_csv_med_Eff_b"   );

  //lepton SF
  _dbm->loadDb("FastSimElSF", "sf_el_tight_IDEmu_ISOEMu_ra5.root", "histo3D");
  _dbm->loadDb("FastSimMuSF", "sf_mu_mediumID_multi.root"        , "histo3D");

}

void
WZsynchro::modifyWeight() {

  if (_vc->get("isData") != 1) {
    //generator weights
    if (_LHESYS == 0) {_weight *= _vc->get("genWeight");}
    else {_weight *= _wzMod->getLHEweight(_LHESYS);}
    //_weight *= _vc->get("genWeight");
    //pileup weights
    //_weight *= _vc->get("vtxWeight");
    if (!_DoPupiDump) _weight *= _vc->get("puWeight");
  }

}



void
WZsynchro::modifySkimming() {

}


void
WZsynchro::defineOutput() {
  ///////////////////////////////////////////////////////////////////////////
  // GLOBAL PLOTS:  These plots are drawn for every SR
  ///////////////////////////////////////////////////////////////////////////
  /*
  //Original sizes with large range and minimal binning
  _hm->addVariable("l1Pt_"  , 150, 0.,  150, "p_{T}(l_{1}) [GeV]"                 );
  _hm->addVariable("l2Pt_"  , 150, 0.,  150, "p_{T}(l_{2}) [GeV]"                 );
  _hm->addVariable("MET_"   , 500, 0. , 500, "#slash{E}_{T} [GeV]"                );
  _hm->addVariable("HT_"    , 800, 0. , 800, "H_{T} [GeV]"                        );
  _hm->addVariable("MT_"    , 200, 0. , 200, "min(M_{T,1}, M_{T,2}) [GeV]"        );
  _hm->addVariable("NBJets_",   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 25 GeV, medium)");
  _hm->addVariable("NJets_" ,   8,-0.5, 7.5, "N_{jets} (p_{T} > 40 GeV)"          );
  _hm->addVariable("M3l_"   , 3000, 0.,  3000, "M_{3l} [GeV]"            );
  */
  //_hm->addVariable("l1Pt_"  , 150, 0.,  150, "p_{T}(l_{1}) [GeV]"                 );
  //_hm->addVariable("l2Pt_"  , 150, 0.,  150, "p_{T}(l_{2}) [GeV]"                 );
  _hm->addVariable("MET_"   , 30, 0. , 300., "#slash{E}_{T} [GeV]"                );
  _hm->addVariable("HT_"    , 30, 0. , 600., "H_{T} [GeV]"                        );
  //_hm->addVariable("MT_"    , 200, 0. , 200., "min(M_{T,1}, M_{T,2}) [GeV]"        );
  _hm->addVariable("NBJets_",   7,-0.5, 6.5, "N_{b-jets} (p_{T} > 25 GeV, medium)");
  _hm->addVariable("NJets_" ,   7,-0.5, 6.5, "N_{jets} (p_{T} > 40 GeV)"          );
  _hm->addVariable("M3l_"   ,  30, 60.,360., "M_{3l} [GeV]"            );
  _hm->addVariable("M3lfull_" ,40, 0., 4000, "M_{3l} [GeV]"            );

  vector<string> reg;
  //reg.push_back("WZSM");
  reg.push_back("WZSMstep0");
  reg.push_back("WZSMstep1");
  reg.push_back("WZSMstep2");
  reg.push_back("WZSMstep3");
  reg.push_back("WZSMstep4");
  reg.push_back("WZSMstep5");
  reg.push_back("WZSMstep6");

    
  for (size_t r=0; r<reg.size(); r++) {
  /*
    // lepton variables
    _hm->addVariable("lepZ1_jetPtRatio_"+reg[r], 100, 0., 1.2, "Z Leading Lepton Jet p_{T} Ratio [GeV]", false);
    _hm->addVariable("lepZ1_jetPtRel_"+reg[r]  , 150, 0.,120., "Z Leading Lepton Jet p_{T} Rel   [GeV]", false);
    _hm->addVariable("lepZ1_miniRelIso_"+reg[r], 100, 0., 0.4, "Z Leading Lepton Isolation", false);
    _hm->addVariable("lepZ1_Pt_"+reg[r]        , 300, 0., 300, "Z Leading Lepton p_{T} [GeV]", false);
    _hm->addVariable("lepZ1_Eta_"+reg[r]       , 100, 0., 2.5, "Z Leading Lepton #eta", false);
    _hm->addVariable("lepZ1_SIP3D_"+reg[r]     , 400, 0., 20., "Z Leading Lepton SIP_{3D}", false);
    _hm->addVariable("lepZ2_jetPtRatio_"+reg[r], 100, 0., 1.2, "Z Subleading Lepton Jet p_{T} Ratio [GeV]", false);
    _hm->addVariable("lepZ2_jetPtRel_"+reg[r]  , 100, 0., 80., "Z Subleading Lepton Jet p_{T} Rel   [GeV]", false);
    _hm->addVariable("lepZ2_miniRelIso_"+reg[r], 100, 0., 0.4, "Z Subleading Lepton Isolation", false);
    _hm->addVariable("lepZ2_Pt_"+reg[r]        , 300, 0., 300, "Z Subleading Lepton p_{T} [GeV]", false);
    _hm->addVariable("lepZ2_Eta_"+reg[r]       , 100, 0., 2.5, "Z Subleading Lepton #eta", false);
    _hm->addVariable("lepZ2_SIP3D_"+reg[r]     , 400, 0., 20., "Z Subleading Lepton SIP_{3D}", false);
    _hm->addVariable("lepW_jetPtRatio_"+reg[r] , 100, 0., 1.2, "W Lepton Jet p_{T} Ratio [GeV]", false);
    _hm->addVariable("lepW_jetPtRel_"+reg[r]   , 100, 0., 80., "W Lepton Jet p_{T} Rel   [GeV]", false);
    _hm->addVariable("lepW_miniRelIso_"+reg[r] , 100, 0., 0.4, "W Lepton Isolation", false);
    _hm->addVariable("lepW_Pt_"+reg[r]         , 300, 0., 300, "W Lepton p_{T} [GeV]", false);
    _hm->addVariable("lepW_Eta_"+reg[r]        , 100, 0., 2.5, "W Lepton #eta", false);
    _hm->addVariable("lepW_SIP3D_"+reg[r]      , 400, 0., 20., "W Lepton SIP_{3D}", false);
    
    // event variables 
    //_hm->addVariable("MET"            , 500, 0. , 500, "#slash{E}_{T} [GeV]", false);
    _hm->addVariable("htJet40j_"+reg[r]       , 800, 0. , 800, "H_{T} [GeV]", false);
    _hm->addVariable("mZ1_"+reg[r]            , 800, 0. , 800, "best m_{l^{+}l^{-}} [GeV]", false);
    _hm->addVariable("MTmin_"+reg[r]          ,  20, 0. , 200, "min(M_{T,1}, M_{T,2}) [GeV]", false);
    _hm->addVariable("NBJetsLoose25_"+reg[r]  ,   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 25 GeV, loose)", false);
    _hm->addVariable("NBJetsMedium25_"+reg[r] ,   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 25 GeV, medium)", false);
    _hm->addVariable("NBJetsTight40_"+reg[r]  ,   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 40 GeV, tight)", false);
    _hm->addVariable("NJets40_"+reg[r]        ,   8,-0.5, 7.5, "N_{jets} (p_{T} > 40 GeV)", false);
    //_hm->addVariable("m3l"             , 250, 0.,  500, "M_{3l} [GeV]", false);
    */
    
    _hm->addVariable("lepZ1_jetPtRatio_"+reg[r],  20, 0., 1.2, "Z Leading Lepton Jet p_{T} Ratio [GeV]", false);
    _hm->addVariable("lepZ1_jetPtRel_"+reg[r]  ,  30, 0., 80., "Z Leading Lepton Jet p_{T} Rel   [GeV]", false);
    _hm->addVariable("lepZ1_miniRelIso_"+reg[r],  20, 0., 0.4, "Z Leading Lepton Isolation", false);
    _hm->addVariable("lepZ1_Pt_"+reg[r]        ,  15, 0., 150, "Z Leading Lepton p_{T} [GeV]", false);
    _hm->addVariable("lepZ1_Eta_"+reg[r]       ,  20, 0., 2.5, "Z Leading Lepton #eta", false);
    _hm->addVariable("lepZ1_SIP3D_"+reg[r]     ,  40, 0., 20., "Z Leading Lepton SIP_{3D}", false);
    _hm->addVariable("lepZ2_jetPtRatio_"+reg[r],  20, 0., 1.2, "Z Subleading Lepton Jet p_{T} Ratio [GeV]", false);
    _hm->addVariable("lepZ2_jetPtRel_"+reg[r]  ,  30, 0., 80., "Z Subleading Lepton Jet p_{T} Rel   [GeV]", false);
    _hm->addVariable("lepZ2_miniRelIso_"+reg[r],  20, 0., 0.4, "Z Subleading Lepton Isolation", false);
    _hm->addVariable("lepZ2_Pt_"+reg[r]        ,  15, 0., 150, "Z Subleading Lepton p_{T} [GeV]", false);
    _hm->addVariable("lepZ2_Eta_"+reg[r]       ,  20, 0., 2.5, "Z Subleading Lepton #eta", false);
    _hm->addVariable("lepZ2_SIP3D_"+reg[r]     ,  40, 0., 20., "Z Subleading Lepton SIP_{3D}", false);
    _hm->addVariable("lepW_jetPtRatio_"+reg[r] ,  20, 0., 1.2, "W Lepton Jet p_{T} Ratio [GeV]", false);
    _hm->addVariable("lepW_jetPtRel_"+reg[r]   ,  30, 0., 80., "W Lepton Jet p_{T} Rel   [GeV]", false);
    _hm->addVariable("lepW_miniRelIso_"+reg[r] ,  20, 0., 0.4, "W Lepton Isolation", false);
    _hm->addVariable("lepW_Pt_"+reg[r]         ,  15, 0., 150, "W Lepton p_{T} [GeV]", false);
    _hm->addVariable("lepW_Eta_"+reg[r]        ,  20, 0., 2.5, "W Lepton #eta", false);
    _hm->addVariable("lepW_SIP3D_"+reg[r]      ,  40, 0., 20., "W Lepton SIP_{3D}", false);
    
    // event variables 
    //_hm->addVariable("MET"            , 500, 0. , 500, "#slash{E}_{T} [GeV]", false);
    //_hm->addVariable("htJet40j_"+reg[r]       , 800, 0. , 800, "H_{T} [GeV]", false);
    _hm->addVariable("mZ1_"+reg[r]            ,  30, 60.,120., "best m_{l^{+}l^{-}} [GeV]", false);
    //_hm->addVariable("MTmin_"+reg[r]          ,  20, 0. , 200, "min(M_{T,1}, M_{T,2}) [GeV]", false);
    //_hm->addVariable("NBJetsLoose25_"+reg[r]  ,   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 25 GeV, loose)", false);
    //_hm->addVariable("NBJetsMedium25_"+reg[r] ,   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 25 GeV, medium)", false);
    //_hm->addVariable("NBJetsTight40_"+reg[r]  ,   8,-0.5, 7.5, "N_{b-jets} (p_{T} > 40 GeV, tight)", false);
    //_hm->addVariable("NJets40_"+reg[r]        ,   8,-0.5, 7.5, "N_{jets} (p_{T} > 40 GeV)", false);
    //_hm->addVariable("m3l"             , 250, 0.,  500, "M_{3l} [GeV]", false);
    
    if(!_DoCheckPlots) continue;
    _hm->addVariable("lepZ1_mediumMuonId_"+reg[r], 20, 0., 2., "Z Leading Lepton medium #mu Id", false);
    _hm->addVariable("lepZ2_mediumMuonId_"+reg[r], 20, 0., 2., "Z Subleading Lepton medium #mu Id", false);
    _hm->addVariable("lepW_mediumMuonId_"+reg[r] , 20, 0., 2., "W Lepton medium #mu Id", false);
    _hm->addVariable("lepZ1_mvaIdPhys14_"+reg[r] , 240, 0., 1.2, "Z Leading Lepton mva Id (Phys14)", false);
    _hm->addVariable("lepZ2_mvaIdPhys14_"+reg[r] , 240, 0., 1.2, "Z Subleading Lepton mva Id (Phys14)", false);
    _hm->addVariable("lepW_mvaIdPhys14_"+reg[r]  , 240, 0., 1.2, "W Lepton medium mva Id (Phys14)", false);
  }

 


  if(!_DoValidationPlots) return; 
  ///////////////////////////////////////////////////////////////////////////
  // VALIDATION PLOTS:  plotting these varibles for a general SS selection //
  ///////////////////////////////////////////////////////////////////////////
  



  
}


void
WZsynchro::writeOutput() {
 
}


void
WZsynchro::run() {
  
  if(_vc->get("isData") && !checkDoubleCount()) return;

  if (_DoEventDump) txt_eventdump.open("workdir/logs/WZTo3LNu_eventdump.txt",std::ios_base::app);

  if (_DoPupiDump){
    if (_vc->get("evt") > 35000) return;
    txt_pupidump.open("workdir/logs/WZTo3LNu_pupidump.txt",std::ios_base::app);
    if (_LHESYS == 1001){
      txt_metdump.open("workdir/logs/WZTo3LNu_metdump.txt",std::ios_base::app);
      txt_evtnumberdump.open("workdir/logs/WZTo3LNu_evtnumberdump.txt",std::ios_base::app);
      //txt_pupidump << Form("%d",_LHESYS);
    }
  }
  
  counter("denominator");
  
  retrieveObjects();
  
  WZ3lSelection();

  //cout<<_vc->get("evt")<<"   "<<_jets[0]->pt()<<endl;

  // int run=_vc->get("run");
  // int lumi=_vc->get("lumi");
  // int event=_vc->get("evt");
  // int nLep = _tightLeps10.size();//_vc->get("nLepGood_Mini");
  // // cout<<" <====> "<<_vc->get("nLepGood_Mini")<<"  "<<_looseLepsVeto.size()<<"  "<<_looseLeps.size()<<endl;
  // int id1 = _l1Cand->pdgId();
  // double pt1 = _l1Cand->pt();
  // int id2 = _l2Cand->pdgId();
  // double pt2 = _l2Cand->pt();
  // int njet = _nJets;
  // int nbjet = _nBJets;
  // double met = _met->pt();
  // double HT = _HT;
  // int sr = ((getCurrentWorkflow()<kBR00H)?(getCurrentWorkflow()):(0));
  
  // cout << Form("%1d %9d %12d\t%2d\t%+2d %5.1f\t%+2d %5.1f\t%d\t%2d\t%5.1f\t%6.1f\t%2d",
  // 	       run, lumi, event, nLep,
  // 	       id1, pt1, id2, pt2,
  // 	       njet, nbjet, met, HT,
  // 	       sr ) << endl;
  if (_DoEventDump) txt_eventdump.close();
  if (_DoPupiDump){
    txt_pupidump.close();
    if (_LHESYS == 1001){
      txt_metdump.close();
      txt_evtnumberdump.close();
      //txt_pupidump << Form("%d",_LHESYS);
    }
  }

 
}

bool
WZsynchro::noIsoSel() {
  
  if( _fakableLepsVeto10.size()!=0 ) return false;
  
  float p=getProbAtLeastNIso( _fakableLepsVeto10 ,_fakableLepsVeto10Idx , 2);
  _weight *= p/(1-p);
  return true;
}

bool
WZsynchro::oneIsoSel() {
  
  if( _fakableLepsVeto10.size()!=1 ) return false;

  float p=getProbAtLeastNIso( _fakableLepsVeto10 ,_fakableLepsVeto10Idx , 1);
  _weight *= p/(1-p);

  return true;
}

bool
WZsynchro::twoIsoSel() {
  
  if( _fakableLepsVeto10.size()!=2 ) return false;

  float p=getProbAtLeastNIso( _fakableLepsVeto10 ,_fakableLepsVeto10Idx , 2);
  _weight *= p/(1-p);

  return true;
}

float
WZsynchro::getProbAtLeastNIso(CandList fObjs, vector<unsigned int> fObjIdx,
			      int nIso) {

  //MM tirage Bernoulli sans remise non ordonne avec probas individuelles
  //formule generale probablement tres compliquee, et surtout pas trouvee

  if(fObjs.size()<(size_t)nIso) {cout<<"not enough leptons for your configuration : "<<fObjs.size()<<" vs  "<<nIso<<endl; return 0;}
  if(nIso>2) {cout<<"not implemented for nIso>2"<<endl; return 0;}

  vector<float> frs(fObjs.size(),0);
 
  float pNoIso = 1;
  for(size_t io=0;io<fObjs.size(); io++) {
    frs[io] = getFR(fObjs[io], fObjIdx[io]);
    pNoIso *= (1-frs[io]);
  }

  if(nIso==0) return pNoIso;// no isolated lepton among all leptons
  if(nIso==1) return (1-pNoIso);// at least one isolated lepton among all leptons

  //at least 2 iso case : computes proba to have only 1 iso within N
  float p1Iso = 0;
  for(size_t ii=0;ii<fObjs.size(); ii++) {
    float pii = frs[ii];
    for(size_t ij=0;ij<fObjs.size(); ij++) {
      if(ij!=ii)
	pii *= 1-frs[ij];
    }
    p1Iso += pii;
  }

  if(nIso==2) return (1-p1Iso-pNoIso);

  return 0;
}


//==================================================================================================
void 
WZsynchro::retrieveObjects(){
  
  _jets.clear();
  

  _l1Cand=nullptr;
  _l2Cand=nullptr;

  _lZ1Cand=nullptr;
  _lZ2Cand=nullptr;
  _lWCand=nullptr; 
  
  _fakableLeps10.clear();
  _fakableLeps10Idx.clear();

  _fakableLepsVeto10.clear();
  _fakableLepsVeto10Idx.clear();

  _tightLeps10.clear();
  _tightLeps10Idx.clear();
  
  _looseLeps10.clear();
  _looseLeps10Idx.clear();
  
  _tightLeps10.clear();
  _tightLeps10Idx.clear();

  _tightLeps20.clear();
  _tightLeps20Idx.clear();
  
  _jetCleanLeps10.clear();
  _jetCleanLeps10Idx.clear();

  selectLeptons3l();

  //jet cleaning leptons =============================
  for(size_t il=0;il<_looseLeps10.size();il++) {
    if(!fakableLepton(_looseLeps10[il], _looseLeps10Idx[il], _looseLeps10[il]->pdgId(),true)) continue;
    
    _jetCleanLeps10.push_back( _looseLeps10[il] );
    _jetCleanLeps10Idx.push_back( _looseLeps10Idx[il] );
  }

  
  _wzMod->cleanJets( &_jetCleanLeps10, _jets, _jetsIdx, _bJets, _bJetsIdx,
		       _lepJets, _lepJetsIdx, (float)40., (float)25., getUncName()=="JES", getUncDir() );
  _nJets=_jets.size();
  _nBJets=_bJets.size();
  _HT=_wzMod->HT( &(_jets) );
  _m3l=_vc->get("m3l");

  if(false) {
    TVector2 met = varyMET();
    _met = Candidate::create( met.Mod(), met.Phi() );
  }
  else
    _met = Candidate::create( _vc->get("met_pt"), _vc->get("met_phi") );

  _metPt = _met->pt();

  //MET and MT
 

}

//=========================================================



void 
WZsynchro::WZ3lSelection() {
  setWorkflow(kWZSM);
  
  // HLT selection
  if (!passHLT()) return;
  
  //step 0 only 3 leptons with pt > 10 GeV
  if(!makeCut(_tightLeps10.size()==3,"Three leptons")) return;

  //if (_WZstep == 0) fillWZhistos(0.0, 0.0);
  CandList l3 =_wzMod->ThreeLeps( (&_tightLeps10));
  
  int munumber = 0;
  if(std::abs(l3[0]->pdgId())==13 ) munumber++;
  if(std::abs(l3[1]->pdgId())==13 ) munumber++;
  if(std::abs(l3[2]->pdgId())==13 ) munumber++;
  if (_lepflav=="eee" && munumber!=0) return;
  if (_lepflav=="eem" && munumber!=1) return;
  if (_lepflav=="mme" && munumber!=2) return;
  if (_lepflav=="mmm" && munumber!=3) return;
  
  int ossfpair = 0;
  if ( (l3[0]->pdgId() + l3[1]->pdgId()) == 0 ) ossfpair++;
  if ( (l3[1]->pdgId() + l3[2]->pdgId()) == 0 ) ossfpair++;
  if ( (l3[0]->pdgId() + l3[2]->pdgId()) == 0 ) ossfpair++;
  if ( ossfpair == 0 ) return;
  
  if(_DoEventDump) EventDump();

/*  
  if ( _vc->get("isData")!=1 && !_DoPupiDump) {
    _weight *= _wzMod->GCleptonScaleFactorZZ (l3[0]->pdgId(), l3[0]->pt(), l3[0]->eta() );
    _weight *= _wzMod->GCleptonScaleFactorZZ (l3[1]->pdgId(), l3[1]->pt(), l3[1]->eta() );
    _weight *= _wzMod->GCleptonScaleFactorZZ (l3[2]->pdgId(), l3[2]->pt(), l3[2]->eta() );
  }
*/  
  
  setWorkflow(kWZSM_3l); fillWZhistos(&l3,"WZSMstep0",0.0); setWorkflow(kWZSM);


  CandList candWZ =_wzMod->bestWZ( (&_tightLeps10), _idxLZ1, _idxLZ2, _idxLW);
  
  if (candWZ.size() < 3) return;
  
  _lZ1Cand = candWZ[0];
  _lZ2Cand = candWZ[1];
  _lWCand = candWZ[2];
    
  if(_lZ1Cand==nullptr || _lZ2Cand==nullptr || _lWCand==nullptr) return;
  _idxLZ1 = _tightLeps10Idx[_idxLZ1];
  _idxLZ2 = _tightLeps10Idx[_idxLZ2];
  _idxLW = _tightLeps10Idx[_idxLW];
  
  if (_lepflav=="eee") {
    if(std::abs(_lZ1Cand->pdgId())!=11 ) return;
    if(std::abs(_lZ2Cand->pdgId())!=11 ) return;
    if(std::abs(_lWCand->pdgId())!=11 ) return;
  }
  if (_lepflav=="eem") {
    if(std::abs(_lZ1Cand->pdgId())!=11 ) return;
    if(std::abs(_lZ2Cand->pdgId())!=11 ) return;
    if(std::abs(_lWCand->pdgId())!=13 ) return;
  }
  if (_lepflav=="mme") {
    if(std::abs(_lZ1Cand->pdgId())!=13 ) return;
    if(std::abs(_lZ2Cand->pdgId())!=13 ) return;
    if(std::abs(_lWCand->pdgId())!=11 ) return;
  }
  if (_lepflav=="mmm") {
    if(std::abs(_lZ1Cand->pdgId())!=13 ) return;
    if(std::abs(_lZ2Cand->pdgId())!=13 ) return;
    if(std::abs(_lWCand->pdgId())!=13 ) return;
  }
  
  
  if(!makeCut( 1>0, "WZ candidate" ) ) return;
  //if (_WZstep == 1) fillWZhistos(0.0, 0.0);
  float MllZ = Candidate::create(_lZ1Cand, _lZ2Cand)->mass();
  setWorkflow(kWZSM_3lwz); fillWZhistos(&candWZ,"WZSMstep1",MllZ); setWorkflow(kWZSM);
  

  if (std::fabs(MllZ - 90) > 30) return;
  
  if(!makeCut( _lZ1Cand->pt()>20, "Z sel" ) ) return;
  //if (_WZstep == 2) fillWZhistos(0.0, 0.0);
  setWorkflow(kWZSM_3lwzZsel); fillWZhistos(&candWZ,"WZSMstep2",MllZ); setWorkflow(kWZSM);
  
  if (_met->pt() < 30) return;
  
  /*if (
      (_lZ1Cand->dR(_lWCand) < 0.1) ||
      (_lWCand->dR(_lZ2Cand) < 0.1) 
     ) return;
  */
  if ( Candidate::create(_lZ1Cand, _lWCand)->mass() < 4 || Candidate::create(_lZ2Cand, _lWCand)->mass() < 4 ) return;
  if(!makeCut( _lWCand->pt()>20, "W sel" ) ) return;
  //if (_WZstep == 3) fillWZhistos(0.0, 0.0);
  setWorkflow(kWZSM_3lwzZselWsel); fillWZhistos(&candWZ,"WZSMstep3",MllZ); setWorkflow(kWZSM);
  
  
  if(!makeCut(_m3l > 100, "M(3l) > 100 GeV" )) return;
  //if (_WZstep == 4) fillWZhistos(0.0, 0.0);
  setWorkflow(kWZSM_3lwzZselWselM3l); fillWZhistos(&candWZ,"WZSMstep4",MllZ); setWorkflow(kWZSM);
  
  
  if(_DoPupiDump) PupiDump();
  
  if(!makeCut(_nBJets<=1,"1 or 0 b-jets")) return;
  //if (_WZstep == 5) fillWZhistos(0.0, 0.0);
  setWorkflow(kWZSM_3lwzZselWselM3lNbj1); fillWZhistos(&candWZ,"WZSMstep5",MllZ); setWorkflow(kWZSM);
  
  if(!makeCut(_nBJets==0,"0 b-jets")) return;
  //if (_WZstep == 6) fillWZhistos(0.0, 0.0);
  setWorkflow(kWZSM_3lwzZselWselM3lNbj0); fillWZhistos(&candWZ,"WZSMstep6",MllZ); setWorkflow(kWZSM);
  
   
  setWorkflow(kGlobal); 
}



//=====================================================================
// signal region selection

void 
WZsynchro::setSignalRegions() {
    
  //objects ===========================================
  _val["NB"]  = &(_nBJets);
  _val["MT"]  = &(_mTmin);
  _val["MET"] = &(_metPt);
  _val["NJ"]  = &(_nJets);
  _val["HT"]  = &(_HT);

  //HH-regions =============================================================
  //0b-jet =================================================================
  if( _SR== "SR1A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:<:300");
  }
  else if( _SR== "SR2A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR3A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:<:300");
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
    setSelLine("LL:=:hh|NB:=:0|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR4A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR5A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:200:500|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR6A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:<:120|MET:[]:200:500|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR7A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:>=:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR8A" ) {
    setSelLine("LL:=:hh|NB:=:0|MT:>=:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
    setSelLine("LL:=:hh|NB:=:0|MT:>=:120|MET:[]:200:500|NJ:>=:2|HT:[]:300:1600");
  }

 //1b-jet =================================================================
  else if( _SR== "SR9A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:<:300");
  }
  else if( _SR== "SR10A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR11A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:<:300");
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
    setSelLine("LL:=:hh|NB:=:1|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR12A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR13A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:200:500|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR14A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:<:120|MET:[]:200:500|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR15A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:>=:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR16A" ) {
    setSelLine("LL:=:hh|NB:=:1|MT:>=:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
    setSelLine("LL:=:hh|NB:=:1|MT:>=:120|MET:[]:200:500|NJ:>=:2|HT:[]:300:1600");
  }
  
  //2b-jet =================================================================
 else if( _SR== "SR17A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:<:300");
  }
  else if( _SR== "SR18A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR19A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:<:300");
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
    setSelLine("LL:=:hh|NB:=:2|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR20A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR21A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:200:500|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR22A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:<:120|MET:[]:200:500|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR23A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:>=:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR24A" ) {
    setSelLine("LL:=:hh|NB:=:2|MT:>=:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
    setSelLine("LL:=:hh|NB:=:2|MT:>=:120|MET:[]:200:500|NJ:>=:2|HT:[]:300:1600");
  }
  
  //3b-jet =================================================================
  else if( _SR== "SR25A" ) {
    setSelLine("LL:=:hh|NB:>=:3|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR26A" ) {
    setSelLine("LL:=:hh|NB:>=:3|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:[]:300:1600");
  }
  else if( _SR== "SR27A" ) {
    setSelLine("LL:=:hh|NB:>=:3|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR28A" ) {
    setSelLine("LL:=:hh|NB:>=:3|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:[]:300:1600");
  }
  else if( _SR== "SR29A" ) {
    setSelLine("LL:=:hh|NB:>=:3|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR30A" ) {
    setSelLine("LL:=:hh|NB:>=:3|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:[]:300:1600");
  }
  
  //inclusive H-MET ==========================================================
  else if( _SR== "SR31A" ) {
    setSelLine("LL:=:hh|MET:>=:500|NJ:>=:2|HT:>=:300");
  }

  //inclusive H-HT ==========================================================
  else if( _SR== "SR32A" ) {
    setSelLine("LL:=:hh|MET:[]:50:500|NJ:>=:2|HT:>=:1600");
  }

  
  //HL-regions =============================================================
  //0b-jet =================================================================
  else if( _SR== "SR1B" ) {
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:<:300");
  }
  else if( _SR== "SR2B" ) {
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR3B" ) {
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:<:300");
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR4B" ) {
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR5B" ) {
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:200:500|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR6B" ) {
    setSelLine("LL:=:hl|NB:=:0|MT:<:120|MET:[]:200:500|NJ:>=:5|HT:[]:300:1600");
  }
  
  //1b-jet =================================================================
 else if( _SR== "SR7B" ) {
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:<:300");
  }
  else if( _SR== "SR8B" ) {
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR9B" ) {
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:<:300");
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR10B" ) {
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR11B" ) {
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:200:500|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR12B" ) {
    setSelLine("LL:=:hl|NB:=:1|MT:<:120|MET:[]:200:500|NJ:>=:5|HT:[]:300:1600");
  }
  
  //2b-jet =================================================================
  else if( _SR== "SR13B" ) {
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:<:300");
  }
  else if( _SR== "SR14B" ) {
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:50:200|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR15B" ) {
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:<:300");
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR16B" ) {
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:50:200|NJ:>=:5|HT:[]:300:1600");
  }
  else if( _SR== "SR17B" ) {
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:200:500|NJ:[]:2:4|HT:[]:300:1600");
  }
  else if( _SR== "SR18B" ) {
    setSelLine("LL:=:hl|NB:=:2|MT:<:120|MET:[]:200:500|NJ:>=:5|HT:[]:300:1600");
  }

  //3+b-jet =================================================================
  else if( _SR== "SR19B" ) {
    setSelLine("LL:=:hl|NB:>=:3|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR20B" ) {
    setSelLine("LL:=:hl|NB:>=:3|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:[]:300:1600");
  }
  else if( _SR== "SR21B" ) {
    setSelLine("LL:=:hl|NB:>=:3|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR22B" ) {
    setSelLine("LL:=:hl|NB:>=:3|MT:<:120|MET:[]:200:500|NJ:>=:2|HT:[]:300:1600");
  }

  //inclusive H-MT =============================================================
  else if( _SR== "SR23B" ) {
    setSelLine("LL:=:hl|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:<:300");
  }
  else if( _SR== "SR24B" ) {
    setSelLine("LL:=:hl|MT:>=:120|MET:[]:50:500|NJ:>=:2|HT:[]:300:1600");
  }
  
  //inclusive H-MET ==========================================================
  else if( _SR== "SR25B" ) {
    setSelLine("LL:=:hl|MET:>=:500|NJ:>=:2|HT:>=:300");
  }
  
  //inclusive H-HT ==========================================================
  else if( _SR== "SR26B" ) {
    setSelLine("LL:=:hl|MET:[]:50:500|NJ:>=:2|HT:>=:1600");
  }


  //LL-regions =============================================================
  else if( _SR== "SR1C" ) {
    setSelLine("LL:=:ll|NB:=:0|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:>:300");
  }
  else if( _SR== "SR2C" ) {
    setSelLine("LL:=:ll|NB:=:0|MT:<:120|MET:>:200|NJ:>=:2|HT:>:300");
  }
  else if( _SR== "SR3C" ) {
    setSelLine("LL:=:ll|NB:=:1|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:>:300");
  }
  else if( _SR== "SR4C" ) {
    setSelLine("LL:=:ll|NB:=:1|MT:<:120|MET:>:200|NJ:>=:2|HT:>:300");
  }
  else if( _SR== "SR5C" ) {
    setSelLine("LL:=:ll|NB:=:2|MT:<:120|MET:[]:50:200|NJ:>=:2|HT:>:300");
  }
  else if( _SR== "SR6C" ) {
    setSelLine("LL:=:ll|NB:=:2|MT:<:120|MET:>:200|NJ:>=:2|HT:>:300");
  }
 else if( _SR== "SR7C" ) {
    setSelLine("LL:=:ll|NB:>=:3|MT:<:120|MET:>=:50|NJ:>=:2|HT:>:300");
  }
  else if( _SR== "SR8C" ) {
    setSelLine("LL:=:ll|MT:>=:120|MET:>=:50|NJ:>=:2|HT:>:300");
  }



  //baselines =============================================================
  //so stupid.....
  else if( _SR== "BR0H" ) {
    setSelLine("LL:=:hh|NB:>=:0|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hh|NB:>=:0|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR0M" ) {
    setSelLine("LL:=:hl|NB:>=:0|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hl|NB:>=:0|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR0L" ) {
    setSelLine("LL:=:ll|NB:>=:0|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:ll|NB:>=:0|NJ:>=:2|HT:>=:500");
  }

 else if( _SR== "BR00H" ) {
    setSelLine("LL:=:hh|NB:=:0|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hh|NB:=:0|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR00M" ) {
    setSelLine("LL:=:hl|NB:=:0|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hl|NB:=:0|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR00L" ) {
    setSelLine("LL:=:ll|NB:=:0|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:ll|NB:=:0|NJ:>=:2|HT:>=:500");
  }

 else if( _SR== "BR10H" ) {
    setSelLine("LL:=:hh|NB:=:1|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hh|NB:=:1|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR10M" ) {
    setSelLine("LL:=:hl|NB:=:1|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hl|NB:=:1|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR10L" ) {
    setSelLine("LL:=:ll|NB:=:1|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:ll|NB:=:1|NJ:>=:2|HT:>=:500");
  }

  else if( _SR== "BR20H" ) {
    setSelLine("LL:=:hh|NB:=:2|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hh|NB:=:2|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR20M" ) {
    setSelLine("LL:=:hl|NB:=:2|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hl|NB:=:2|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR20L" ) {
    setSelLine("LL:=:ll|NB:=:2|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:ll|NB:=:2|NJ:>=:2|HT:>=:500");
  }

 else if( _SR== "BR30H" ) {
    setSelLine("LL:=:hh|NB:>=:3|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hh|NB:>=:3|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR30M" ) {
    setSelLine("LL:=:hl|NB:>=:3|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:hl|NB:>=:3|NJ:>=:2|HT:>=:500");
  }
  else if( _SR== "BR30L" ) {
    setSelLine("LL:=:ll|NB:>=:3|MET:>:30|NJ:>=:2|HT:<:500");
    setSelLine("LL:=:ll|NB:>=:3|NJ:>=:2|HT:>=:500");
  }




}

void
WZsynchro::setSelLine(string str) {

  //MM could be done in a better way

  //parsing full selection into variable selections
  stringstream ss(str);
  string item;
  string tk;
  
  vector<vector<string> > sel;
  while (std::getline(ss, item, '|')) {
    
    vector<string> vars(4,"");
    stringstream sssel( item );
  
    int n=0;
    while (std::getline(sssel, tk, ':')) {
      vars[n]= (tk);
      n++;
    }

    if(vars.size()==3)
      vars.push_back("");

    sel.push_back(vars);
  }

  _sels[_SR].push_back( sel );
}


//================================================
bool 
WZsynchro::genMatchedToFake(int idx) {

  if (_vc->get("isData") == 1) return false;

  int id1  = _vc->get("LepGood_mcMatchId" ,idx); 
  if(id1==0 || id1==100) return true;

  return false;
}

bool
WZsynchro::genMatchedMisCharge() {


  if (_vc->get("isData")==1) return false;
  
  int mid1=_vc->get("LepGood_mcMatchId" ,_idxL1);
  int mid2=_vc->get("LepGood_mcMatchId" ,_idxL2);
  
  //DY case
  if(mid1==23 && mid2==23 && 
     _l1Cand->pdgId()*_l2Cand->pdgId()>0 ) {
    return true;
  }
  if(std::abs(mid1)==24 && std::abs(mid2)==24 &&
     _l1Cand->pdgId()*_l2Cand->pdgId()>0 ) {
    return true;
  }
  
  return false;
}

int 
WZsynchro::genMatchCateg(const Candidate* cand) {

  // //loop over the number of generated leptons
  // int nGenL = _vc->get("nGenPart");

  // for(int ig = 0; ig < nGenL; ++ig) {
	
  //   if(Tools::dR(cand->eta(), _vc->get("GenPart_eta", ig),
  // 		 cand->phi(), _vc->get("GenPart_phi", ig) ) < 0.05 ) { //to be tuned
		  		
  //     //if( genMatchedToFake(idx) ) return kMisMatchPdgId; //taus are exception to the rule
  //     else if(cand->pdgId()*_vc->get("GenPart_pdgId",ig) < 0 ) return kMisChargePdgId; //+*- = -...
  //     else return kGenMatched;
			
  //     break;
  //   } //dr matching
  // } //gen loop
	
  return kNoGenMatch;
}

bool
WZsynchro::passGenSelection() {


  if( _sampleName.find("DYJets")!=(size_t)-1 || _sampleName.find("TTJets")!=(size_t)-1 ) {
    
    if(_sampleName.find("charge")!=(size_t)-1) {
      if( !genMatchedMisCharge() )
	return false;
    }
    else if(_sampleName.find("fake")!=(size_t)-1) {
      if(!genMatchedToFake(_idxL1) && !genMatchedToFake(_idxL2) ) return false;
    }
    else {
      //if( genMatchedToFake(_idxL1) || genMatchedToFake(_idxL2) ) return false;
    }
  }
  return true;
}


float 
WZsynchro::getFR(Candidate* cand, int idx) {
  string db;
  float ptM=10;
  if( std::abs(cand->pdgId())==13) db="Mu";
  else { db="El"; ptM=15;}
  
  if(_HT<300) db+= "Iso";
  else db += "NIso";

  if(_vc->get("isData")!=1) db +="MC";


  if(isInUncProc() && getUncName()=="EWKFR" && getUncDir()==SystUtils::kUp ) db+="Up";
  if(isInUncProc() && getUncName()=="EWKFR" && getUncDir()==SystUtils::kDown ) db+="Do";

  float ptVal=cand->pt();
  //float etaVal=std::abs(cand->eta()); //commented due to "unused variable" message during compilation

  int wp=std::abs(cand->pdgId()==11)?SusyModule::kTight:SusyModule::kMedium;

  if(_FR.find("C")!=string::npos) ptVal=std::max(_wzMod->conePt(idx,wp), (double)ptM);
  if(_FR.find("J")!=string::npos) ptVal/=_vc->get("LepGood_jetPtRatiov2", idx);

  ptVal=std::max(ptVal, ptM);

  return 0.000001;
  //return _dbm->getDBValue(db, std::min( ptVal,(float)69.9),
//			  std::min(etaVal,(float)2.49) );
}


void
WZsynchro::chargeFlipProb() {

  string db="chargeMId";
  if(!_vc->get("isData") ) db="chargeMIdMC";

  float w=0;
  for(unsigned int i=0;i<_auxPairs.size();i++) {

    if(_auxFlags[i]!=kIsOS) continue;

    float p1=_dbm->getDBValue(db, _auxPairs[i][0]->pt(), std::abs(_auxPairs[i][0]->eta()));
    float p2=_dbm->getDBValue(db, _auxPairs[i][1]->pt(), std::abs(_auxPairs[i][1]->eta()));

    if(p1>0.01) p1=0.0005;
    if(p2>0.01) p2=0.0005;

    w += (p1+p2-2*p1*p2)/(p1*p2+(1-p1)*(1-p2) );
  }
  
  _weight *= w;
}

//===============================================================
//===============================================================
bool
WZsynchro::testRegion() {

  bool passSel=true;

  for(size_t is=0;is<_sels[_SR].size();is++) {
    passSel=true;
    //cout<<"new region ================== "<<_SR<<endl;
    for(size_t ii=0;ii<_sels[_SR][is].size();ii++) {
    
      //cout<<_sels[_SR][is][ii][0]<<" >> "<<endl;

      if(_sels[_SR][is][ii][0]=="LL") { //lepton pt scheme, specific case 
	if(_sels[_SR][is][ii][2]=="hh" && 
	   (_l1Cand->pt()<25 || _l2Cand->pt()<25) ) {passSel=false;break;}
	if(_sels[_SR][is][ii][2]=="hl" &&
	   ( (_l1Cand->pt()<25 && _l2Cand->pt()<25) ||
	     (_l1Cand->pt()>=25 && _l2Cand->pt()>=25) ) ) {passSel=false;break;}
	if(_sels[_SR][is][ii][2]=="ll" && 
	   (_l1Cand->pt()>=25 || _l2Cand->pt()>=25) ) {passSel=false;break;}
      
      }
      else { //all other selections

	//cout<<":: "<<_sels[_SR][is][ii][0]<<" :: "<<(*(_val[_sels[_SR][is][ii][0] ]))<<" "<<_sels[_SR][is][ii][1]<<" "<<atof(_sels[_SR][is][ii][2].c_str() )<<"  "<<atof(_sels[_SR][is][ii][3].c_str())<<endl;

	// bool dec=(_au->simpleCut<float>( (*(_val[_sels[_SR][is][ii][0] ])) , atof(_sels[_SR][is][ii][2].c_str() ), _sels[_SR][is][ii][1], atof(_sels[_SR][is][ii][3].c_str()) ));
	if(!_au->simpleCut<float>( (*(_val[_sels[_SR][is][ii][0] ])) , atof(_sels[_SR][is][ii][2].c_str() ),
				   _sels[_SR][is][ii][1], atof(_sels[_SR][is][ii][3].c_str()) ) ) 
	  {passSel=false;break;}
      }
      
    }
    //cout<<" --> passing selection? "<<passSel<<endl;
    if(passSel) return true;
  }

  return false;
}


void
WZsynchro::categorize() {

  int offset=1;
  string categ="";
  for(size_t ic=0;ic< _categs.size();ic++) {
    _SR = _categs[ic];
    if(testRegion() ) {setWorkflow(ic+offset); return;}
  }
  std::cout << "WARNING: WZsynchro::categorize() did not find any workflow that matches this event. The workflow returns to kGlobal what may cause problems with the histograms" << std::endl;
  //std::cout<<"====> "<<_looseLepsPtCut.size()<<" / "<<_tightLepsPtCut.size()<<" / "<<_nJets<<" / "<<_nBJets<<" / "<<hltSelection()<<" / "<<_met->pt()<<" / "<<_HT<<" / "<<_vc->get("evt")<<" / "<<_vc->get("lumi")<<std::endl;
  setWorkflow(kGlobal);
}



bool 
WZsynchro::looseLepton(int idx, int pdgId) {

  if (abs(pdgId) == 13) {//muons
    return _wzMod->IsLooseMuonWW(idx);
  }
  else if (abs(pdgId) == 11 && abs(_vc->get("LepGood_etaSc", idx)) <= 1.479) { //barrel electron
    return _wzMod->IsLooseBarrelElectronWW(idx);
  }
  else if (abs(pdgId) == 11 && abs(_vc->get("LepGood_etaSc", idx)) > 1.479 && abs(_vc->get("LepGood_etaSc", idx)) < 2.5) { //endcap electron
    return _wzMod->IsLooseEndcapElectronWW(idx);
  }
  else {
    //std::cout << "WARNING [WZsynchro::tightLepton](" << idx << ", " << pdgId << ", idx) not valid lepton candidate, with LepGood_etaSc=" << _vc->get("LepGood_etaSc", idx) << std::endl;
  }
  return false;
  
}


bool 
WZsynchro::tightLepton(int idx, int pdgId) {

  if (abs(pdgId) == 13) {//muons
    return _wzMod->IsTightMuonWW(idx);
  }
  else if (abs(pdgId) == 11 && abs(_vc->get("LepGood_etaSc", idx)) <= 1.479) { //barrel electron
    return _wzMod->IsTightBarrelElectronWW(idx);
  }
  else if (abs(pdgId) == 11 && abs(_vc->get("LepGood_etaSc", idx)) > 1.479 && abs(_vc->get("LepGood_etaSc", idx)) < 2.5) { //endcap electron
    return _wzMod->IsTightEndcapElectronWW(idx);
  }
  else {
    //std::cout << "WARNING [WZsynchro::tightLepton](" << idx << ", " << pdgId << ", idx) not valid lepton candidate, with LepGood_etaSc=" << _vc->get("LepGood_etaSc", idx) << std::endl;
  }
  return false;
  
}


bool 
WZsynchro::fakableLepton(const Candidate* c, int idx, int pdgId, bool bypass) {
  if(abs(pdgId)==13) {//mu case
    if(!_wzMod->muIdSel(c, idx, SusyModule::kTight) ) return false;
    if(!_wzMod->multiIsoSel(idx, SusyModule::kDenom) ) return false;
    
    if(_FR.find("FO4")!=string::npos && !_wzMod->invMultiIsoSel(idx, SusyModule::kSpecFakeMu) ) return false;
  }
  else {
    int elMva=(_HT<300)?SusyModule::kLooseHT:SusyModule::kLoose;
    if(bypass) elMva=SusyModule::kLoose;
    bool hltDLHT=bypass?false:(_HT<300);
    
    if(_FR.find("FO2")==string::npos && !_wzMod->elIdSel(c, idx, SusyModule::kTight, SusyModule::kTight )) return false;
    if(_FR.find("FO2")!=string::npos && !_wzMod->elIdSel(c, idx, SusyModule::kTight, elMva )) return false;
    if(!_wzMod->multiIsoSel(idx, SusyModule::kDenom) ) return false; 
     if(!_wzMod->elHLTEmulSel(idx, hltDLHT ) ) return false; 
    
    if(_FR.find("FO4")!=string::npos && !_wzMod->invMultiIsoSel(idx, SusyModule::kSpecFakeEl) ) return false;
  }
  return true;
}


bool
WZsynchro::passHLT() {
  // Same for ZZ and WW leptons (WW analysis also uses SingleMuon and SingleElectron)
  bool passhlt = ( _vc->get("HLT_BIT_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_v") || 
    _vc->get("HLT_BIT_HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ_v") || 
    _vc->get("HLT_BIT_HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_v") || 
    _vc->get("HLT_BIT_HLT_Mu8_TrkIsoVVL_Ele17_CaloIdL_TrackIdL_IsoVL_v") || 
    _vc->get("HLT_BIT_HLT_Mu17_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_v") );
  
  return passhlt;
}



bool
WZsynchro::passCERNSelection() {

  if(!makeCut( _vc->get("nLepGood10_Mini"), "CERN lepmult" ) ) return false;
  if(!makeCut<float>( _vc->get("mZ1cut10TL_Mini"), 76 , "]![", "CERN Z veto",  106 ) ) return false;
  if(!makeCut<float>( _vc->get("minMllAFOSTL_Mini"), 0 , "]!]", "CERN g veto OS", 12) ) return false;
  if(!makeCut<float>( _vc->get("minMllAFASTL_Mini"), 8 , ">", "CERN g veto AS" ) ) return false;
     
// > = 2 good leptons: nLepGood10 >= 2
// minMllAS8:  minMllAFAS > 8
// minMllOS12: minMllAFOS <= 0 || minMllAFOS > 12
// zveto3l:    mZ1 < 76 || mZ1 > 106

     if(!makeCut( abs(_l1Cand->pdgId()) > 0 && abs(_l2Cand->pdgId()) > 0, "pdgId") ) return false;
     if(!makeCut( _l1Cand->charge()*_l2Cand->charge()>0, "charge") ) return false;
     if(!makeCut( _l1Cand->pt()>25 && _l2Cand->pt()>25, "pt") ) return false;
     
     cout<<_l1Cand->pdgId()<<"  "<<_l2Cand->pdgId()<<"  "<<SusyModule::kMedium<<"  "<<SusyModule::kTight<<endl;

     int wp1 = SusyModule::kMedium;//((abs(_l1Cand->pdgId())==13)?(SusyModule::kMedium):SusyModule::kTight);
     int wp2 = SusyModule::kMedium;//((abs(_l2Cand->pdgId())==13)?(SusyModule::kMedium):SusyModule::kTight);
     if(abs(_l1Cand->pdgId())==13) wp1 = SusyModule::kTight;
     if(abs(_l2Cand->pdgId())==13) wp2 = SusyModule::kTight;


     // cout<<wp1<<"  "<<wp2<<"   "<<_idxL1<<"  "<<_idxL2<<"   "<< _wzMod->multiIsoSel(_idxL1, wp1 )
     // 	 <<"   "<<_wzMod->multiIsoSel(_idxL2, wp2 )<<endl;

     if(!makeCut( _wzMod->multiIsoSel(_idxL1, wp1 ), "iso1") ) return false;
     if(!makeCut( _wzMod->multiIsoSel(_idxL2, wp2 ), "iso2") ) return false;

     bool id= _vc->get("LepGood_mediumMuonId", _idxL1)>0 && 
              _vc->get("LepGood_mediumMuonId", _idxL2)>0;

     if(!makeCut(id, "id") ) return false;

     bool elId= ( _vc->get("LepGood_mvaIdPhys14",_idxL1) >=0.73+(0.57-0.73)*(abs(_l1Cand->eta())>0.8)+(+0.05-0.57)*(abs(_l1Cand->eta())>1.479) || abs(_l1Cand->pdgId()) == 13) && 
     ( _vc->get("LepGood_mvaIdPhys14",_idxL2) >=0.73+(0.57-0.73)*(abs(_l2Cand->eta())>0.8)+(+0.05-0.57)*(abs(_l2Cand->eta())>1.479) || abs(_l2Cand->pdgId()) == 13); 

     cout<<_vc->get("LepGood_mvaIdPhys14",_idxL1)<<"   "<<_l1Cand->eta()<<"   "<<_vc->get("LepGood_mvaIdPhys14",_idxL2)<<"   "<<_l2Cand->eta()<<endl;

     if(!makeCut(elId, "elId") ) return false;

// exclusive:  nLepGood10 == 2
// anyll: abs(LepGood1_pdgId) > 0 && abs(LepGood2_pdgId) > 0
// same-sign: LepGood1_charge*LepGood2_charge > 0
// lep1_pt25: LepGood1_pt > 25 
// lep2_pt25: LepGood2_pt > 25 
// lep iso: multiIso_multiWP(LepGood1_pdgId,LepGood1_pt,LepGood1_eta,LepGood1_miniRelIso,LepGood1_jetPtRatio,LepGood1_jetPtRel,2) > 0 && 
//          multiIso_multiWP(LepGood2_pdgId,LepGood2_pt,LepGood2_eta,LepGood2_miniRelIso,LepGood2_jetPtRatio,LepGood2_jetPtRel,2) > 0
//lep mu id: LepGood1_mediumMuonId > 0 && LepGood2_mediumMuonId > 0 
// lep el id: ( LepGood1_mvaIdPhys14 >=0.73+(0.57-0.73)*(abs(LepGood1_eta)>0.8)+(+0.05-0.57)*(abs(LepGood1_eta)>1.479) || abs(LepGood1_pdgId) == 13) && 
//            ( LepGood2_mvaIdPhys14 >=0.73+(0.57-0.73)*(abs(LepGood2_eta)>0.8)+(+0.05-0.57)*(abs(LepGood2_eta)>1.479) || abs(LepGood2_pdgId) == 13) 

     // cout<<_idxL1<<"  "<<_idxL2<<"   "<<_vc->get("LepGood_sip3d",_idxL1)<<"   "<<_vc->get("LepGood_sip3d",_idxL2)<<endl;

     if(!makeCut( max(_vc->get("LepGood_sip3d",_idxL1),_vc->get("LepGood_sip3d",_idxL2)) < 4, "sip") ) return false;

     bool conv= (abs(_l1Cand->pdgId())==13 || (_vc->get("LepGood_convVeto",_idxL1) && _vc->get("LepGood_lostHits",_idxL1) == 0)) &&
                (abs(_l2Cand->pdgId())==13 || (_vc->get("LepGood_convVeto",_idxL2) && _vc->get("LepGood_lostHits",_idxL2) == 0));

     if(!makeCut(  conv, "conversion") ) return false;

     bool charge= (_vc->get("LepGood_tightCharge",_idxL1)> (abs(_l1Cand->pdgId())==11)) &&
		   (_vc->get("LepGood_tightCharge",_idxL2)> (abs(_l2Cand->pdgId())==11));

     if(!makeCut(  charge, "tight charge") ) return false;
     
  return true;

}
bool WZsynchro::ttbarSelection(){
  ///filters : hbheFilterNew25ns==1 && Flag_CSCTightHaloFilter==1 && Flag_eeBadScFilter==1
  ///trigger : HLT_DoubleMu || HLT_DoubleEl || HLT_MuEG
  ///nL : nLepGood >= 2
  ///EE_MuMu_MuE : LepGood1_pdgId == -LepGood2_pdgId || abs(LepGood1_pdgId+LepGood2_pdgId)==2
  ///pt2515 : LepGood1_pt>25 && LepGood2_pt>15
  ///mll > 12 : minMllAFAS > 12
  ///nJet40 : nJet40 >= 2
  ///nBJetMedium25 : nBJetMedium25 >= 1 || nBJetLoose25 == 2
  ///Z peak : abs(mZ1-91.2) > 10
  if (_vc->get("hbheFilterNew25ns")==0 || _vc->get("Flag_CSCTightHaloFilter")==0 || _vc->get("Flag_eeBadScFilter")==0) return false;   
  if (!(_vc->get("HLT_DoubleMu") || _vc->get("HLT_DoubleEl") || _vc->get("HLT_MuEG"))) return false;
  if (_vc->get("nLepGood") < 2) return false;
  _idxL1 = 0;
  _idxL2 = 1;
  if (!(_vc->get("LepGood_pdgId", _idxL1) == -_vc->get("LepGood_pdgId", _idxL2) || 
	abs(_vc->get("LepGood_pdgId", _idxL1)+_vc->get("LepGood_pdgId", _idxL2)) == 2)
      ) return false;
  if (_vc->get("LepGood_pt", _idxL1) < 25. || _vc->get("LepGood_pt", _idxL2) < 15.) return false;
  if (_vc->get("minMllAFAS") < 12.) return false;
  if (_vc->get("nJet40") < 2) return false;
  if (!(_vc->get("nBJetMedium25") >= 1 || _vc->get("nBJetLoose25") == 2)) return false; 
  if (abs(_vc->get("mZ1")-91.2) < 10.)  return false;
  
  return true;
}

bool WZsynchro::ZlSelection(){
  if (_vc->get("hbheFilterNew25ns")==0 || _vc->get("Flag_CSCTightHaloFilter")==0 || _vc->get("Flag_eeBadScFilter")==0) return false;   
  if (!(_vc->get("HLT_DoubleMu") || _vc->get("HLT_DoubleEl") || _vc->get("HLT_MuEG"))) return false;
  if (_vc->get("nLepGood10") !=3 ) return false;
  if (!(_vc->get("LepGood_pdgId", 0) == -_vc->get("LepGood_pdgId", 1))) return false;
  if (abs(_vc->get("mZ1")-91.2) > 15.) return false;
  
  Candidate* lep3=Candidate::create(_vc->get("LepGood_pt", 2),
				    _vc->get("LepGood_eta", 2),
				    _vc->get("LepGood_phi", 2),
				    _vc->get("LepGood_pdgId", 2),
				    _vc->get("LepGood_charge", 2),
				    0.105);
  float mT= Candidate::create(lep3, _met)->mass();
  
  if (mT > 55.) return false;
  if (_vc->get("minMllAFAS") < 12.) return false;
  if (_vc->get("LepGood_pt", 2) > 50.) return false;
  if (_vc->get("met_pt") > 60.) return false;

  _idxL1 = 0;
  _idxL2 = 2;
    
  return true;
}
bool WZsynchro::WlSelection(){
  if (_vc->get("hbheFilterNew25ns")==0 || _vc->get("Flag_CSCTightHaloFilter")==0 || _vc->get("Flag_eeBadScFilter")==0) return false;   
  if (!(_vc->get("HLT_SingleMu") || _vc->get("HLT_SingleEl"))) return false;
  if (_vc->get("nLepGood10") != 2) return false;
  if (_vc->get("LepGood_charge", 0)*_vc->get("LepGood_charge", 1) < 0) return false;
  
  _idxL1 = 0;
  _idxL2 = 1;
  
  bool charge= (_vc->get("LepGood_tightCharge",_idxL1) > (abs(_vc->get("LepGood_pdgId",_idxL1))==11))  && 
               (_vc->get("LepGood_tightCharge",_idxL2) > (abs(_vc->get("LepGood_pdgId",_idxL2))==11));
  
  if (!charge) return false;
  
  Candidate* lep=Candidate::create(_vc->get("LepGood_pt", _idxL1),
				   _vc->get("LepGood_eta", _idxL1),
				   _vc->get("LepGood_phi", _idxL1),
				   _vc->get("LepGood_pdgId", _idxL1),
				   _vc->get("LepGood_charge", _idxL1),
				   0.105);
  float mT= Candidate::create(lep, _met)->mass();

  if (_vc->get("LepGood_sip3d",_idxL1) > 4) return false;
  if (_vc->get("LepGood_relIso03",_idxL1) > 0.05) return false;
  if (_vc->get("LepGood_miniRelIso",_idxL1) > 0.05) return false;
  if (_vc->get("nBJetMedium25") != 0) return false;
  if (_vc->get("met_pt") < 30.) return false;
  if (mT < 40.) return false;

  if ((abs(_vc->get("LepGood_pdgId",_idxL1))==11 && abs(_vc->get("LepGood_pdgId",_idxL2))==11) && 
       (_vc->get("mZ1") > 76. && _vc->get("mZ1") < 106.))  return false;
  
  return true;
}

bool WZsynchro::ZMuMuSelection(){
  if (_vc->get("hbheFilterNew25ns")==0 || _vc->get("Flag_CSCTightHaloFilter")==0 || _vc->get("Flag_eeBadScFilter")==0) return false;   
  if (!(_vc->get("HLT_SingleMu"))) return false;
  if (_vc->get("nLepGood") < 2) return false;
  if (_vc->get("nLepGood10") != 2) return false;
  if (!(_vc->get("LepGood_pdgId", 0) == -_vc->get("LepGood_pdgId", 1))) return false;
  //  cout << _vc->get("LepGood_pdgId", 0)  << " = " << _vc->get("LepGood_pdgId", 1) << endl;
  if (abs(_vc->get("LepGood_pdgId", 0)) != 13) return false;
  if (_vc->get("mZ1") < 60. || _vc->get("mZ1") > 120.) return false;
  
  if (_vc->get("LepGood_charge", 0) < 0) {
    _idxL1 = 0;
    _idxL2 = 1;
  }
  else if (_vc->get("LepGood_charge", 1) < 0) {
    _idxL1 = 1;
    _idxL2 = 0;
  }
  
  if (_vc->get("LepGood_pt", _idxL1) < 20) return false;
  if (_vc->get("LepGood_relIso03", _idxL1) > 0.2 ) return false;
  if (abs(_vc->get("LepGood_eta", _idxL1)) > 2.1) return false;

  return true;
}

bool WZsynchro::ZEESelection(){
  if (_vc->get("hbheFilterNew25ns")==0 || _vc->get("Flag_CSCTightHaloFilter")==0 || _vc->get("Flag_eeBadScFilter")==0) return false;   
  if (!(_vc->get("HLT_SingleEl"))) return false;
  if (_vc->get("nLepGood") < 2) return false;
  if (!(_vc->get("LepGood_pdgId", 0) == -_vc->get("LepGood_pdgId", 1))) return false;
  if (abs(_vc->get("LepGood_pdgId", 0)) != 11) return false;
  if (_vc->get("mZ1") < 60. || _vc->get("mZ1") > 120.) return false;
  
  if (_vc->get("LepGood_charge", 0) < 0) {
    _idxL1 = 0;
    _idxL2 = 1;
  }
  else if (_vc->get("LepGood_charge", 1) < 0) {
    _idxL1 = 1;
    _idxL2 = 0;
  }
  
  if (_vc->get("LepGood_pt", _idxL1) < 30) return false;
  if (_vc->get("LepGood_relIso03", _idxL1) > 0.2 ) return false;
  if (abs(_vc->get("LepGood_eta", _idxL1)) > 2.1) return false;
  
  return true;
}


//===========================================================================
void
WZsynchro::selectLeptons3l() {
  for(size_t il=0;il<_vc->get("nLepGood"); il++) {

    bool isMu=std::abs(_vc->get("LepGood_pdgId", il))==13;

    Candidate* cand=Candidate::create(_vc->get("LepGood_pt", il),
				      _vc->get("LepGood_eta", il),
				      _vc->get("LepGood_phi", il),
				      _vc->get("LepGood_pdgId", il),
				      _vc->get("LepGood_charge", il),
				      isMu?0.105:0.0005);

    //cout<<" pt: "<<cand->pt()<<"  eta: "<<cand->eta()<<"   phi: "<<cand->phi()<<"  pdgId: "<<_vc->get("LepGood_pdgId", il)<<"   dxy: "<<_vc->get("LepGood_dxy",il)<<"  dz: "<<_vc->get("LepGood_dz",il)<<endl;
    //cout<<" LepGood_pdgId: "<<_vc->get("LepGood_pdgId", il)<<" cand->pdgId()=" << cand->pdgId() << std::endl;
    
    if(!looseLepton(il, cand->pdgId() ) ) continue;
    if(cand->pt()<10) continue;
    _looseLeps10.push_back(cand);
    _looseLeps10Idx.push_back(il);  
      
    if(!tightLepton(il, cand->pdgId() ) ) continue;
    _tightLeps10.push_back(cand);
    _tightLeps10Idx.push_back(il);

    if(cand->pt()<20) continue;
    _tightLeps20.push_back(cand);
    _tightLeps20Idx.push_back(il);
    
  }
}


//===========================================================================

//==============================================
//MET uncertainty variation
TVector2
WZsynchro::varyMET() {

  unsigned int nJets=_vc->get("nJet");
  unsigned int nDiscJets=_vc->get("nDiscJet");
  unsigned int nFwdJets=_vc->get("nJetFwd");
  if(!isInUncProc() ) {//first, store the jets
    _uncleanJets.clear();
    _uncleanDiscJets.clear();
    _uncleanFwdJets.clear();
    for(unsigned int ij=0;ij<nJets;ij++) { 
      TVector2 jet; jet.SetMagPhi( _vc->get("Jet_pt", ij), _vc->get("Jet_phi", ij)   );
      _uncleanJets.push_back(jet);
    }
    for(unsigned int ij=0;ij<nDiscJets;ij++) { 
      TVector2 jet; jet.SetMagPhi( _vc->get("DiscJet_pt", ij), _vc->get("DiscJet_phi", ij)   );
      _uncleanDiscJets.push_back(jet);
    }
    for(unsigned int ij=0;ij<nFwdJets;ij++) { 
      TVector2 jet; jet.SetMagPhi(_vc->get("JetFwd_pt", ij),_vc->get("JetFwd_phi", ij));
      _uncleanFwdJets.push_back(jet);
    }
  
    // for(unsigned int ij=0;ij<nJets;ij++) {
    //   cout<<getUncName()<<" -> "<<_vc->get("Jet_pt", ij)<<" / "<<_vc->get("Jet_eta", ij)<<endl;
    // }
    // for(unsigned int ij=0;ij<nDiscJets;ij++) {
    //   cout<<getUncName()<<" -> "<<_vc->get("DiscJet_pt", ij)<<" / "<<_vc->get("DiscJet_eta", ij)<<endl;
    // }
    // for(unsigned int ij=0;ij<nFwdJets;ij++) {
    //   cout<<getUncName()<<" -> "<<_vc->get("JetFwd_pt", ij)<<" / "<<_vc->get("JetFwd_eta", ij)<<endl;
    // }
  }

  TVector2 met; met.SetMagPhi(_vc->get("met_pt"), _vc->get("met_phi") );
  if(!(isInUncProc() &&  getUncName()=="JES") ) return met;

  for(unsigned int ij=0;ij<nJets;ij++) { 
    
    bool find=false;
    for(unsigned int iv=0;iv<_lepJetsIdx.size();iv++) {
      if("Jet"==_lepJetsIdx[iv].first && ij==_lepJetsIdx[iv].second) { find=true; break;}
    }
    if(find) continue; //bloody lepton cleaning
   
    //add back the standard jets
    met += _uncleanJets[ij];
    //JES varied jets
    float scale=_dbm->getDBValue("jes", _vc->get("Jet_eta", ij), _vc->get("Jet_pt", ij));
    scale = ((SystUtils::kUp==getUncDir())?1:(-1))*scale;
    TVector2 jet; jet.SetMagPhi( _vc->get("Jet_pt", ij)*(1+scale), _vc->get("Jet_phi", ij)   );
    met -= jet;
    //cout<<" -> "<<_vc->get("Jet_pt", ij)*(1+scale)<<" / "<<_vc->get("Jet_eta", ij)<<endl;
  }
  for(unsigned int ij=0;ij<nDiscJets;ij++) { 
    
    bool find=false;
    for(unsigned int iv=0;iv<_lepJetsIdx.size();iv++) {
      if("DiscJet"==_lepJetsIdx[iv].first && ij==_lepJetsIdx[iv].second) { find=true; break;}
    }
    if(find) continue; //bloody lepton cleaning
    
    //add back the standard jets
    met += _uncleanDiscJets[ij];
    //JES varied jets
    float scale=_dbm->getDBValue("jes", _vc->get("DiscJet_eta", ij), _vc->get("DiscJet_pt", ij));
    scale = ((SystUtils::kUp==getUncDir())?1:(-1))*scale;
    TVector2 jet; jet.SetMagPhi( _vc->get("DiscJet_pt", ij), _vc->get("DiscJet_phi", ij)   );
    met -= jet;
    //cout<<" -> "<<_vc->get("DiscJet_pt", ij)*(1+scale)<<" / "<<_vc->get("DiscJet_eta", ij)<<endl;
  }
  for(unsigned int ij=0;ij<nFwdJets;ij++) { 
    //add back the standard jets
    met += _uncleanFwdJets[ij];
    //JES varied jets
    float scale=_dbm->getDBValue("jes", _vc->get("JetFwd_eta", ij), _vc->get("JetFwd_pt", ij));
    scale = ((SystUtils::kUp==getUncDir())?1:(-1))*scale;
    TVector2 jet; jet.SetMagPhi(_vc->get("JetFwd_pt", ij), _vc->get("JetFwd_phi", ij) );
    met -= jet;
    //cout<<" -> "<<_vc->get("JetFwd_pt", ij)*(1+scale)<<" / "<<_vc->get("JetFwd_eta", ij)<<endl;
  }

  return met;
}

void WZsynchro::fillhistos() {
  fill("l1Pt", (_idxFake==_idxL2)?(_l1Cand->pt()):_l2Cand->pt(), _weight );
  fill("l2Pt", (_idxFake==_idxL2)?(_l2Cand->pt()):_l1Cand->pt(), _weight );
  fill("HT"    , _HT       , _weight);
  fill("MET"   , _met->pt(), _weight);
  fill("MT"    , _mTmin        , _weight);
  fill("NBJets", _nBJets   , _weight);
  fill("NJets" , _nJets    , _weight);
}

void WZsynchro::fillValidationHistos(string reg){
  
  fill(reg+"_lep1_jetPtRatio", _vc->get("LepGood_jetPtRatio_LepAwareJEC", _idxL1) , _weight);
  fill(reg+"_lep1_jetPtRel"  , _vc->get("LepGood_jetPtRelv2", _idxL1)               , _weight);
  fill(reg+"_lep1_miniRelIso", _vc->get("LepGood_miniRelIso", _idxL1)             , _weight);
  fill(reg+"_lep1_Pt"        , _vc->get("LepGood_pt", _idxL1)                     , _weight);
  fill(reg+"_lep1_Eta"       , fabs(_vc->get("LepGood_eta", _idxL1))              , _weight);
  fill(reg+"_lep1_SIP3D"     , _vc->get("LepGood_sip3d", _idxL1)                  , _weight);
  
  fill(reg+"_lep2_jetPtRatio", _vc->get("LepGood_jetPtRatio_LepAwareJEC", _idxL2) , _weight);
  fill(reg+"_lep2_jetPtRel"  , _vc->get("LepGood_jetPtRelv2", _idxL2)               , _weight);
  fill(reg+"_lep2_miniRelIso", _vc->get("LepGood_miniRelIso", _idxL2)             , _weight);
  fill(reg+"_lep2_Pt"        , _vc->get("LepGood_pt", _idxL2)                     , _weight);
  fill(reg+"_lep2_Eta"       , fabs(_vc->get("LepGood_eta", _idxL2))              , _weight);
  fill(reg+"_lep2_SIP3D"     , _vc->get("LepGood_sip3d", _idxL2)                  , _weight);
   
  fill(reg+"_MET"            , _vc->get("met_pt")        , _weight);
  fill(reg+"_htJet40j"       , _vc->get("htJet40j")      , _weight);
  fill(reg+"_mZ1"            , _vc->get("mZ1")           , _weight);
  fill(reg+"_MTmin"          , _mTmin                    , _weight);
  fill(reg+"_NBJetsLoose25"  , _vc->get("nBJetLoose25")  , _weight);
  fill(reg+"_NBJetsMedium25" , _vc->get("nBJetMedium25") , _weight);
  fill(reg+"_NBJetsTight40"  , _vc->get("nBJetTight40")  , _weight);
  fill(reg+"_NJets40"        , _vc->get("nJet40")        , _weight);
}  

void WZsynchro::fillWZhistos(CandList* leps, string reg, float MllZ) {
  //fill("l1Pt", (_idxFake==_idxL2)?(_l1Cand->pt()):_l2Cand->pt(), _weight );
  //fill("l2Pt", (_idxFake==_idxL2)?(_l2Cand->pt()):_l1Cand->pt(), _weight );
  fill("HT_"    , _HT       , _weight);
  fill("MET_"   , _met->pt(), _weight);
  //fill("MT"    , mt        , _weight);
  //fill("MTmin"    , mtmin        , _weight);
  fill("NBJets_", _nBJets   , _weight);
  fill("NJets_" , _nJets    , _weight);
  fill("M3l_"   , _wzMod->m3lTight(leps), _weight); // avoiding cases such as [tight, tight, loose, tight]
  fill("M3lfull_", _wzMod->m3lTight(leps), _weight); // avoiding cases such as [tight, tight, loose, tight]
  if (_DoValidationPlots) {
      if (reg.find("0")==std::string::npos) {
        //fill("lepZ1_jetPtRatio_"+reg, _vc->get("LepGood_jetPtRatio", _idxLZ1)           , _weight);
        //fill("lepZ1_jetPtRel_"+reg  , _vc->get("LepGood_jetPtRel", _idxLZ1)             , _weight);
        fill("lepZ1_miniRelIso_"+reg, _vc->get("LepGood_miniRelIso", _idxLZ1)             , _weight);
        fill("lepZ1_Pt_"+reg        , _vc->get("LepGood_pt", _idxLZ1)                     , _weight);
        fill("lepZ1_Eta_"+reg       , fabs(_vc->get("LepGood_eta", _idxLZ1))              , _weight);
        fill("lepZ1_SIP3D_"+reg     , _vc->get("LepGood_sip3d", _idxLZ1)                  , _weight);
  
        //fill("lepZ2_jetPtRatio_"+reg, _vc->get("LepGood_jetPtRatio", _idxLZ2)           , _weight);
        //fill("lepZ2_jetPtRel_"+reg  , _vc->get("LepGood_jetPtRel", _idxLZ2)             , _weight);
        fill("lepZ2_miniRelIso_"+reg, _vc->get("LepGood_miniRelIso", _idxLZ2)             , _weight);
        fill("lepZ2_Pt_"+reg        , _vc->get("LepGood_pt", _idxLZ2)                     , _weight);
        fill("lepZ2_Eta_"+reg       , fabs(_vc->get("LepGood_eta", _idxLZ2))              , _weight);
        fill("lepZ2_SIP3D_"+reg     , _vc->get("LepGood_sip3d", _idxLZ2)                  , _weight);
  
        //fill("lepW_jetPtRatio_"+reg, _vc->get("LepGood_jetPtRatio", _idxLW)           , _weight);
        //fill("lepW_jetPtRel_"+reg  , _vc->get("LepGood_jetPtRel", _idxLW)             , _weight);
        fill("lepW_miniRelIso_"+reg, _vc->get("LepGood_miniRelIso", _idxLW)             , _weight);
        fill("lepW_Pt_"+reg        , _vc->get("LepGood_pt", _idxLW)                     , _weight);
        fill("lepW_Eta_"+reg       , fabs(_vc->get("LepGood_eta", _idxLW))              , _weight);
        fill("lepW_SIP3D_"+reg     , _vc->get("LepGood_sip3d", _idxLW)                  , _weight);
      }
      //fill("MET"            , _vc->get("met_pt")        , _weight);
      //fill("htJet40j_"+reg       , _vc->get("htJet40j")      , _weight); // not present in MiniAODv2 Heppy Trees
      //fill("mZ1_"+reg            , _vc->get("mZ1")           , _weight);
      if (reg.find("0")!=std::string::npos) fill("mZ1_"+reg            , _wzMod->bestmZ(leps)      , _weight); // avoiding cases such as [tight, tight, loose, tight]
      else fill("mZ1_"+reg            , MllZ      , _weight); // consult WZModule.cc for explanation of this if-else
      //fill("MTmin_"+reg          , _mTmin                    , _weight);
      //fill("NBJetsLoose25_"+reg  , _vc->get("nBJetLoose25")  , _weight); // not present in MiniAODv2 Heppy Trees
      //fill("NBJetsMedium25_"+reg , _vc->get("nBJetMedium25") , _weight); // not present in MiniAODv2 Heppy Trees
      //fill("NBJetsTight40_"+reg  , _vc->get("nBJetTight40")  , _weight); // not present in MiniAODv2 Heppy Trees
      //fill("NJets40_"+reg        , _vc->get("nJet40")        , _weight); // not present in MiniAODv2 Heppy Trees

  }
  if (_DoCheckPlots && reg.find("0")==std::string::npos) {
/*
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ2)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLW )          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("muon_eta_"+reg, _vc->get("LepGood_Eta", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("lepZ1_mediumMuonId_"+reg, _vc->get("LepGood_mediumMuonId", _idxLZ1)          , _weight);
    if (abs(_vc->get("LepGood_pdgId",_idxLZ1))==13) fill("lepZ1_mediumMuonId_"+reg, _vc->get("LepGood_mediumMuonId", _idxLZ1)          , _weight);*/
  }
}


bool
WZsynchro::checkDoubleCount() {
  int run=_vc->get("run");
  int lumi=_vc->get("lumi");
  unsigned long int evt=(unsigned long int)_vc->get("evt");
  
  bool doubleCount=false;
  std::pair<int,unsigned long int> tmp(lumi,evt);
  std::pair<int, std::pair<int,unsigned long int> > tmp2(run, tmp);
  _itEvt = _events.find( tmp2 );
  if(_itEvt != _events.end() ) {
    doubleCount=true;
    //abort(); ?? FIXME -> no abort by default
  }
  int nT = 1;
  if(doubleCount)
    { 
      //cout<<" ==> multiple counting "<< _ids<<"  "<<run<<"  "<<event<<"  "<< anConf.getDataset(_ids)->findProcess(_ie)<<endl;
      nT = _itEvt->second.second +1;
      return false;
    }
  
 
  string t1("");
  std::pair<string,int> tt( t1, nT );
	  
  _events[ tmp2 ] = tt;
  //_evtsInFile.push_back(event);
   
  return true;
}

void WZsynchro::EventDump(){
  //if (!(_wzMod->IsDumpable(_vc->get("evt")))) return;
  if (_vc->get("evt") < 10000 || _vc->get("evt") > 750000) return;

  for (int i=0; i<3; i++){
      //int index = AnalysisLeptons[i].index;
      if (abs(_vc->get("LepGood_pdgId",i))==13){
        txt_eventdump << Form("%.0f:%d:%.4f:%.4f:%.4f:%d",
			      _vc->get("evt"),
			      (int)_vc->get("LepGood_pdgId", i),
			      _vc->get("LepGood_pt", i),
			      _vc->get("LepGood_eta", i),
			      _vc->get("LepGood_relIso04", i),
			      1);

      }else if (abs(_vc->get("LepGood_pdgId",i))==11){
      
        txt_eventdump << Form("%.0f:%d:%.4f:%.4f:%.4f:%d",
			      _vc->get("evt"),
			      (int)_vc->get("LepGood_pdgId", i),
			      _vc->get("LepGood_pt", i),
			      _vc->get("LepGood_eta", i),
			      _vc->get("LepGood_relIso03", i),
			      1);
      
	    txt_eventdump << Form(":%.4f:%.0f:%.4f:%.4f:%.0f",
				    _vc->get("LepGood_etaSc", i),
				    _vc->get("LepGood_convVeto", i),
				    _vc->get("LepGood_dxy", i),
				    _vc->get("LepGood_dz", i),
				    _vc->get("LepGood_lostHits", i));
	  }
      
      txt_eventdump << Form("\n");
  }
}

void WZsynchro::PupiDump(){
  //if (!(_wzMod->IsDumpable(_vc->get("evt")))) return;
  //if (_vc->get("evt") < 35000) cout << _vc->get("evt") << endl;
  if (_vc->get("evt") > 35000){
    //if (_vc->get("evt") < 35100) txt_pupidump << Form("\n");
    return;
  }
  if (_LHESYS == 1001){
    txt_metdump << Form("%.2f\t",_met->pt());
    txt_evtnumberdump << Form("%.0f\t",_vc->get("evt"));
  }
    
    
  txt_pupidump << Form("%.5f\t",_weight);

  
}

#include "analysis/modules/WZModule.hh"

/*
WZModule::WZModule(VarClass* vc):
  _vc(vc),_dbm(nullptr)
{
  defineLeptonWPS();
  
}

WZModule::WZModule(VarClass* vc, DataBaseManager* dbm):
  _vc(vc), _dbm(dbm)
{
  defineLeptonWPS();
  loadDBs();
}
*/

WZModule::WZModule(VarClass* vc):SusyModule(vc) {}

WZModule::WZModule(VarClass* vc, DataBaseManager* dbm):SusyModule(vc,dbm) {}

WZModule::~WZModule() {}


CandList WZModule::bestWZ(const CandList* leps, int& idxZ1, int& idxZ2, int& idxW) {
  CandList clist(3,NULL);

  idxZ1 = -1;
  idxZ2 = -1;
  idxW = -1;
  
  CandList Zcand = bestZ(leps, idxZ1, idxZ2);
  clist[0] = Zcand[0];
  clist[1] = Zcand[1];
/*
  for(size_t il=0;il<cands->size();il++) {
    if( c1==cands->at(il) ) continue;
    //cout<<" passng veto? "<<passMllSingleVeto(c1, cands->at(il), mllm, mllM, ossf)<<endl;
    if(!passMllSingleVeto(c1, cands->at(il), mllm, mllM, ossf)) return false;
  }
*/
  for(unsigned int il1=0;il1<leps->size();il1++) {
    if (clist[0] == leps->at(il1)) continue;
    if (clist[1] == leps->at(il1)) continue;
    
    idxW = il1;
    clist[2] = leps->at(il1);
    break;

  }//il1
  
  return clist;

}

CandList WZModule::bestZ(const CandList* leps, int& idxZ1, int& idxZ2) {
  CandList clist(2,NULL);

  idxZ1 = -1;
  idxZ2 = -1;
  
  float massdiffMin = 9999.9;
  
  for(unsigned int il1=0;il1<leps->size()-1;il1++) {
    for(unsigned int il2=il1+1;il2<leps->size();il2++) {
    
      int flav = leps->at(il1)->pdgId() + leps->at(il2)->pdgId();
      if (flav != 0 ) continue;
      
      float mll = Candidate::create(leps->at(il1), leps->at(il2))->mass();
      float massdiff = std::abs(91.1876 - mll);
      float massdiff90 = std::abs(91 - mll);
      

      //if (massdiff90 > 15) continue;

      if (massdiffMin < massdiff) continue;
      
      massdiffMin = massdiff;
      
      clist[0]=leps->at(il1);
      clist[1]=leps->at(il2);
      idxZ1 = il1;
      idxZ2 = il2;

    }//il2
  }//il1
 
  return clist;
}


CandList WZModule::ThreeLeps(const CandList* leps) {
  CandList clist(3,NULL);
  clist[0] = leps->at(0);
  clist[1] = leps->at(1);
  clist[2] = leps->at(2);
  return clist;
}

float WZModule::m3lTight(const CandList* leps){
  float m3ltight = Candidate::create(*leps)->mass();
  return m3ltight;
}

float WZModule::bestmZ(const CandList* leps){
  //this ensures that best mZ is calculated using 3 tight leptons (possibility of [tight, tight, loose or not even loose, tight] in event, for example)
  float mlltemp = 0;
  float mll = 0;
  float mlltemp = 0;
  float massdiffMin = 9999.9;
  for(unsigned int il1=0;il1<leps->size()-1;il1++) {
    for(unsigned int il2=il1+1;il2<leps->size();il2++) {
   
      int flav = leps->at(il1)->pdgId() + leps->at(il2)->pdgId();
      if (flav != 0 ) continue;
      
      mlltemp = Candidate::create(leps->at(il1), leps->at(il2))->mass();

      float massdiff = std::abs(91.1876 - mlltemp);
      
      if (massdiffMin < massdiff) continue;
      mll = mlltemp;
      massdiffMin = massdiff;
      
    }//il2
  }//il1
  
  return mll; 
}
//--------------------
CandList WZModule::bestGenWZ(const CandList* leps, int& idxZ1, int& idxZ2, int& idxW) {
  CandList clist(3,NULL);

  idxZ1 = -1;
  idxZ2 = -1;
  idxW = -1;
  
  CandList Zcand = bestZ(leps, idxZ1, idxZ2);
  clist[0] = Zcand[0];
  clist[1] = Zcand[1];
/*
  for(size_t il=0;il<cands->size();il++) {
    if( c1==cands->at(il) ) continue;
    //cout<<" passng veto? "<<passMllSingleVeto(c1, cands->at(il), mllm, mllM, ossf)<<endl;
    if(!passMllSingleVeto(c1, cands->at(il), mllm, mllM, ossf)) return false;
  }
*/
  for(unsigned int il1=0;il1<leps->size();il1++) {
    if (clist[0] == leps->at(il1)) continue;
    if (clist[1] == leps->at(il1)) continue;
    
    idxW = il1;
    clist[2] = leps->at(il1);
    break;

  }//il1
  
  return clist;

}

CandList WZModule::bestGenZ(const CandList* leps, int& idxZ1, int& idxZ2) {
  CandList clist(2,NULL);

  idxZ1 = -1;
  idxZ2 = -1;
  
  float massdiffMin = 9999.9;
  
  for(unsigned int il1=0;il1<leps->size()-1;il1++) {
    for(unsigned int il2=il1+1;il2<leps->size();il2++) {
    
      int flav = leps->at(il1)->pdgId() + leps->at(il2)->pdgId();
      if (flav != 0 ) continue;
      if (_vc->get("genLep_motherId",il1) != _vc->get("genLep_motherId",il2) ) continue;
      
      float mll = Candidate::create(leps->at(il1), leps->at(il2))->mass();
      float massdiff = std::abs(91.1876 - mll);
      float massdiff90 = std::abs(91 - mll);
      
      //if (massdiff90 > 15) continue;
      if (massdiffMin < massdiff) continue;
      
      massdiffMin = massdiff;
      
      clist[0]=leps->at(il1);
      clist[1]=leps->at(il2);
      idxZ1 = il1;
      idxZ2 = il2;

    }//il2
  }//il1
 
  return clist;
}
float WZModule::bestGenmZ(const CandList* leps){
  //this ensures that best mZ is calculated using 3 tight leptons (possibility of [tight, tight, loose, tight] in event, for example)
  float mlltemp = 0;
  float mll = 0;
  float massdiffMin = 9999.9;
  for(unsigned int il1=0;il1<leps->size()-1;il1++) {
    for(unsigned int il2=il1+1;il2<leps->size();il2++) {
   
      int flav = leps->at(il1)->pdgId() + leps->at(il2)->pdgId();
      if (flav != 0 ) continue;
      
      mlltemp = Candidate::create(leps->at(il1), leps->at(il2))->mass();
      float massdiff = std::abs(91.1876 - mlltemp);
      
      if (massdiffMin < massdiff) continue;
      mll = mlltemp;
      massdiffMin = massdiff;
      
    }//il2
  }//il1
  
  return mll; 
}


bool WZModule::truthMatch(const vector<unsigned int> recolepsidx){
  if (recolepsidx.size()==0) return false;
 
  unsigned int matchedcount = 0;  
  for(unsigned int il1=0;il1<recolepsidx.size();il1++) {
    if (_vc->get("LepGood_mcMatchId",recolepsidx[il1])!=0 && _vc->get("LepGood_mcMatchAny",recolepsidx[il1])==1) matchedcount++;
  }//il1
  
  return (matchedcount==recolepsidx.size());
  
}




// ------------------------------------------------------------------------------------------

// WW leptons
// Slide 4 https://indico.cern.ch/event/485788/contribution/3/attachments/1214544/1772984/OviIFCA-WZstatus.pdf
// https://twiki.cern.ch/twiki/bin/view/CMS/WW2015Variables
// Better S/B than ZZ leptons for WZ analysis

bool
WZModule::IsLooseMuonWW(int idx) {

  if( std::abs(_vc->get("LepGood_eta"             , idx))  > 2.4     ) return false;
  if( _vc->get("LepGood_mediumMuonId"             , idx)   !=1       ) return false;
  if( _vc->get("LepGood_relIso04"                 , idx)   > 0.4     ) return false;
  if( _vc->get("LepGood_dr03TkSumPt", idx)/_vc->get("LepGood_pt", idx)   > 0.4     ) return false;

  return true;

}

bool
WZModule::IsTightMuonWW(int idx) {

  if( std::abs(_vc->get("LepGood_eta"             , idx))  > 2.4     ) return false;
  if( _vc->get("LepGood_mediumMuonId"             , idx)   !=1       ) return false;
  if( _vc->get("LepGood_relIso04"                 , idx)   > 0.15    ) return false;
  if( _vc->get("LepGood_pt", idx) > 20 ){
    if( std::abs(_vc->get("LepGood_dxy"           , idx))  > 0.02    ) return false;
  } else {
    if( std::abs(_vc->get("LepGood_dxy"           , idx))  > 0.01    ) return false;
  }
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.1     ) return false;
  
  return true;

}


bool
WZModule::IsLooseBarrelElectronWW(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.01    ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.04    ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta"            , idx)   > 0.011   ) return false;
//  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.011   ) return false; // USE THIS FOR SYNCHRO!!!!!!!!!
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.08    ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.01    ) return false;
  if( _vc->get("LepGood_ecalPFClusterIso", idx)/_vc->get("LepGood_pt", idx)   > 0.45    ) return false;
  if( _vc->get("LepGood_hcalPFClusterIso", idx)/_vc->get("LepGood_pt", idx)   > 0.25    ) return false;
  if( _vc->get("LepGood_dr03TkSumPt", idx)/_vc->get("LepGood_pt", idx)        > 0.2     ) return false;
//  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.766     ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 2       ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.1     ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.373   ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

bool
WZModule::IsLooseEndcapElectronWW(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  < 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 2.5     ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.01    ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.08    ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta"            , idx)   > 0.031   ) return false; 
//  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.031   ) return false; // USE THIS FOR SYNCHRO!!!!!!!!!
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.08    ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.01    ) return false;
  if( _vc->get("LepGood_ecalPFClusterIso", idx)/_vc->get("LepGood_pt", idx)   > 0.45    ) return false;
  if( _vc->get("LepGood_hcalPFClusterIso", idx)/_vc->get("LepGood_pt", idx)   > 0.25    ) return false;
  if( _vc->get("LepGood_dr03TkSumPt", idx)/_vc->get("LepGood_pt", idx)        > 0.2     ) return false;
//  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.766     ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 1       ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.2     ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.602   ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

bool
WZModule::IsMediumBarrelElectronWW(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.0103  ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.0336  ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta"            , idx)   > 0.0101  ) return false;
//  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0101  ) return false; // USE THIS FOR SYNCHRO!!!!!!!!!
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.0876  ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.0174  ) return false;
//  if( _vc->get("LepGood_ecalPFClusterIso"         , idx)   > 0.45    ) return false;
//  if( _vc->get("LepGood_hcalPFClusterIso"         , idx)   > 0.25    ) return false;
//  if( _vc->get("LepGood_trackIso"                 , idx)   > 0.2     ) return false;
  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.766     ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 2       ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0118   ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.373   ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

bool
WZModule::IsMediumEndcapElectronWW(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  < 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 2.5     ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.00733 ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.11400 ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta"            , idx)   > 0.02830 ) return false;
//  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.02830 ) return false; // USE THIS FOR SYNCHRO!!!!!!!!!
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.06780 ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.08980 ) return false;
//  if( _vc->get("LepGood_ecalPFClusterIso"         , idx)   > 0.45    ) return false;
//  if( _vc->get("LepGood_hcalPFClusterIso"         , idx)   > 0.25    ) return false;
//  if( _vc->get("LepGood_trackIso"                 , idx)   > 0.2     ) return false;
  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.0678  ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 1       ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0739  ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.602   ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}


bool
WZModule::IsTightBarrelElectronWW(int idx) {

  if( _vc->get("LepGood_tightId"                  , idx)   < 3       ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
//  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0101  ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.00926 ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.0336  ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.0597  ) return false;
  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.0354  ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.012   ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0111  ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.0466  ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 2       ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

bool
WZModule::IsTightEndcapElectronWW(int idx) {

  if( _vc->get("LepGood_tightId"                  , idx)   < 3       ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  < 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 2.5     ) return false;
//  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0279  ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.00724 ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.0918  ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.0615  ) return false;
  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.0646  ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.00999 ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0351  ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.417   ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 1       ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------

// ZZ leptons
// https://twiki.cern.ch/twiki/bin/viewauth/CMS/WZ13TeV#Objects
// Slide 4 https://indico.cern.ch/event/485788/contribution/3/attachments/1214544/1772984/OviIFCA-WZstatus.pdf

bool
WZModule::IsLooseBarrelElectronZZ(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
  if( _vc->get("LepGood_tightId"                  , idx)   < 1       ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0103  ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.0105  ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.115   ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.104   ) return false;
//  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.0893  ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.102   ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0261  ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.41    ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 2       ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

bool
WZModule::IsLooseEndcapElectronZZ(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  < 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 2.5     ) return false;
  if( _vc->get("LepGood_tightId"                  , idx)   < 1       ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0301  ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.00814 ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.182   ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.0897  ) return false;
//  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.121   ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.126   ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.118   ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.822   ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 1       ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}


bool
WZModule::IsLooseMuonZZ(int idx) {
  if( std::abs(_vc->get("LepGood_eta"             , idx))  > 2.4     ) return false;
  return true;
}

bool
WZModule::IsTightMuonZZ(int idx) {

  if( std::abs(_vc->get("LepGood_eta"             , idx))  > 2.4     ) return false;
  if( _vc->get("LepGood_tightId"                  , idx)   !=1       ) return false;
  if( _vc->get("LepGood_relIso04"                 , idx)   > 0.12    ) return false;
  
  return true;

}


bool
WZModule::IsTightBarrelElectronZZ(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
  if( _vc->get("LepGood_tightId"                  , idx)   < 2       ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0101  ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.0103  ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.0336  ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.0876  ) return false;
  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.0766  ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.0174  ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0118  ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.373   ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 2       ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

bool
WZModule::IsTightEndcapElectronZZ(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  < 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 2.5     ) return false;
  if( _vc->get("LepGood_tightId"                  , idx)   < 2       ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0283  ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.00733 ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.114   ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.0678  ) return false;
  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.0678  ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.0898  ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.0739  ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.602   ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 1       ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}

// ------------------------------------------------------------------------------------------
void
WZModule::cleanJetsOld(CandList* leptons, 
		      CandList& cleanJets, vector<pair<string, unsigned int> >& jetIdxs,
		      CandList& cleanBJets, vector<pair<string, unsigned int> >& bJetIdxs,
		      CandList& lepJets, vector<pair<string, unsigned int> >& lepJetsIdxs,
		      float thr, float bthr,
		      bool isJESVar, int dir ) {

  cleanJets.clear();
  cleanBJets.clear();
  jetIdxs.clear();
  bJetIdxs.clear();

  lepJets.clear();
  lepJetsIdxs.clear();
  
  vector<string> jetTypes({"Jet","DiscJet"});
  CandList jets;
  vector<bool> bvals;
  vector<pair<string, unsigned int> > tmpIdxs;

  for(size_t it=0;it<jetTypes.size();it++) {
    string jType=jetTypes[it];
    
    for(int ij=0;ij<_vc->get("n"+jType);ij++) {
      if(_vc->get(jType+"_id",ij)<1) continue;
      
      float scale=0.;
      if(isJESVar) {
	scale = _dbm->getDBValue("jes", _vc->get(jType+"_eta", ij), _vc->get(jType+"_pt", ij) );
	scale = ((SystUtils::kUp==dir)?1:(-1))*scale;
      }

    Candidate* jet=Candidate::create(_vc->get(jType+"_pt", ij)*(1+scale),
				       _vc->get(jType+"_eta", ij),
				       _vc->get(jType+"_phi", ij) );

      jets.push_back(jet);
      bvals.push_back( _vc->get(jType+"_btagCSV",ij)<0.970 );//0.814
      tmpIdxs.push_back(make_pair(jType, ij));
    }
  }


  map<Candidate*, std::pair<float,Candidate*> > cmap;
  map<Candidate*, std::pair<float,Candidate*> >::const_iterator it;

  for(unsigned int il=0;il<leptons->size();il++) {
    for(unsigned int ij=0;ij<jets.size();ij++) {

      float dR=leptons->at(il)->dR( jets[ij] );
      it = cmap.find(leptons->at(il));
      if(it==cmap.end() ) {
	cmap[ leptons->at(il) ] =std::make_pair(dR, jets[ij] );
      }
      else if(dR<it->second.first) {
	cmap[ leptons->at(il) ] =std::make_pair(dR, jets[ij] );
      }
    }
  }

  bool pass=true;
  for(unsigned int ij=0;ij<jets.size();ij++) {

    pass=true;
    for(unsigned int il=0;il<leptons->size();il++) {
      it = cmap.find(leptons->at(il));
      if(it->second.first > 0.3 ) continue;
      if(it->second.second == jets[ij] ) {pass=false; break;}
    }
    if(!pass) { 
      lepJetsIdxs.push_back(tmpIdxs[ij]);
      continue;
    }

    if(jets[ij]->pt()<bthr) continue;
    
    if(jets[ij]->pt()>thr) {
      cleanJets.push_back(jets[ij] );
      jetIdxs.push_back(tmpIdxs[ij]);
    }
    
    if(bvals[ij]) continue;
    
    cleanBJets.push_back(jets[ij]);
    bJetIdxs.push_back(tmpIdxs[ij]);
  } //loop jets

}



// -------------------------------------------------------------------------------------------

bool WZModule::IsDumpable(int evt){

  string search = std::to_string(evt);
  ifstream inFile;
  string line;
  bool dumpable = false;

  inFile.open("workdir/data/dumpables.txt");

  if(!inFile){
    cout << "Unable to open file" << endl;
    exit(1);
  }


  
  while(inFile.good())
  {
      getline(inFile,line); // get line from file
      if(line.find(search)!=string::npos) // string::npos is returned if string is not found
        {
            //cout <<"Found!";
            dumpable = true;
            break;
        }
  }
  return dumpable;
}

// --------------- B-tag SF -----------------------------

float
WZModule::bTagSF_HL(CandList& jets, vector<pair<string, unsigned int> >& jetIdx,
                   CandList& bJets, vector<pair<string, unsigned int> >& bJetIdx,
                   int heavy, int light){
  // put heavy = -1 / 0 / +1 for down / central / up for b/c jets
  // put light = -1 / 0 / +1 for down / central / up for light jets

  float pdata = 1.0;
  float pmc   = 1.0;
  int   st = 1;

  for(unsigned int i=0;i<jets.size(); ++i) {
    bool find=false;
    unsigned int  flavor = 2;
    st = light;
    
    if(std::abs(_vc->get( (string)(jetIdx[i].first+"_mcFlavour") , jetIdx[i].second)) == 5){
      flavor = 0; // b jet
      st = heavy;
    }
    else if(std::abs(_vc->get( (string)(jetIdx[i].first+"_mcFlavour") , jetIdx[i].second)) == 4){
      flavor = 1; // c jet
      st = heavy;
    }
    
    for(unsigned int iv=0;iv<bJets.size();iv++) {
      if(jetIdx[i].first==bJetIdx[iv].first && jetIdx[i].second==bJetIdx[iv].second) { find=true; break;}
    }



    if(find){
      pdata*=bTagMediumEfficiency(jets[i], flavor) * 
	bTagMediumScaleFactor(jets[i], flavor, st);
      pmc*=bTagMediumEfficiency(jets[i], flavor);
    }
    else {
      pdata*=(1-bTagMediumEfficiency(jets[i], flavor) * 
	      bTagMediumScaleFactor(jets[i], flavor, st));
      pmc*=(1-bTagMediumEfficiency(jets[i], flavor));
    }
  }

  //cout<<"pd " <<pdata<<"  "<<pmc<<endl;
  if(pmc != 0) return pdata/pmc;
  return 1.0;

}





// ------------------ SF stuff from Giuseppe -------------------


float 
WZModule::GCtriggerScaleFactorZZ(int pdgId1, int pdgId2, float pt1, float pt2, float ht) {
  if (ht>300) {
    if ((abs(pdgId1)+abs(pdgId2))==22) return 1.;
    if ((abs(pdgId1)+abs(pdgId2))==26) return 0.985*0.985;
    if ((abs(pdgId1)+abs(pdgId2))==24) return 0.985;
  } else {
    if ((abs(pdgId1)+abs(pdgId2))==22) return 0.997*0.997*0.998;
    if ((abs(pdgId1)+abs(pdgId2))==26) return 0.982*0.985*0.973;
    if ((abs(pdgId1)+abs(pdgId2))==24) {
      if (abs(pdgId1)==11) {
	if (pt1>pt2) return 0.997*0.985;
	else return 0.997*0.982;
      } else {
	if (pt1>pt2) return 0.997*0.982;
	else return 0.997*0.985;
      }
    }
  }
  return 0.;
}



float 
WZModule::GCelectronScaleFactorZZ(float pt, float eta) {
// "passingMedium" 
   if (std::abs(eta)>=0 && std::abs(eta)<1.5){
      if (pt>=10 && pt<20) return 1.0161064863204956;
      if (pt>=20 && pt<30) return 0.9780689477920532;
      if (pt>=30 && pt<40) return 0.98564213514328;
      if (pt>=40 && pt<50) return 0.9833754301071167;
      if (pt>=50 && pt<100) return 0.9775973558425903;
      if (pt>=100 && pt<1000) return 0.9868901371955872;
   } else if (std::abs(eta)>=1.5 && std::abs(eta)<2.5){
      if (pt>=10 && pt<20) return 0.9601008296012878;
      if (pt>=20 && pt<30) return 0.9666073322296143;
      if (pt>=30 && pt<40) return 0.9795471429824829;
      if (pt>=40 && pt<50) return 1.0002920627593994;
      if (pt>=50 && pt<100) return 1.0050536394119263;
      if (pt>=100 && pt<1000) return 1.0306119918823242;
   }
   return 0.;
}
float 
WZModule::GCmuonScaleFactorZZ(float pt, float eta) {
// "passingIDWZTight"*"passingIsoWZTight_passingIDWZTight"
   if (std::abs(eta)>=0 && std::abs(eta)<1.5){
      if (pt>=10 && pt<20) return 0.9868156909942627*1.0183368921279907;
      if (pt>=20 && pt<30) return 0.9889848232269287*1.0212706327438354;
      if (pt>=30 && pt<40) return 0.9884716272354126*1.0095585584640503;
      if (pt>=40 && pt<50) return 0.9884045720100403*1.0068796873092651;
      if (pt>=50 && pt<100) return 0.9861332178115845*1.0042873620986938;
      if (pt>=100 && pt<1000) return 0.9815685153007507*1.0076546669006348;
   } else if (std::abs(eta)>=1.5 && std::abs(eta)<2.5){
      if (pt>=10 && pt<20) return 0.9885789155960083*0.9871252179145813;
      if (pt>=20 && pt<30) return 0.9853408932685852*1.0046104192733765;
      if (pt>=30 && pt<40) return 0.9872066974639893*1.008818507194519;
      if (pt>=40 && pt<50) return 0.9892857670783997*1.0051954984664917;
      if (pt>=50 && pt<100) return 0.9863803386688232*1.0021514892578125;
      if (pt>=100 && pt<1000) return 0.9731688499450684*1.0111212730407715;
   }
   return 0.;
}


float 
WZModule::GCleptonScaleFactorZZ(int pdgId, float pt, float eta) {
  if (abs(pdgId)==13) return GCmuonScaleFactor(pt, eta);
  else if (abs(pdgId)==11) return GCelectronScaleFactorZZ(pt, eta);
    //if(ht>300) return GCelectronScaleFactorHighHT(pt, eta);
    //else       return GCelectronScaleFactorLowHT(pt, eta);
  //}
  return 0.;
}

float 
WZModule::GCeventScaleFactorZZ(int pdgId1, int pdgId2, float pt1, float pt2, float eta1, float eta2, float ht) {
  return GCtriggerScaleFactor(pdgId1, pdgId2, pt1, pt2, ht) * 
         GCleptonScaleFactorZZ(pdgId1, pt1, eta1) * 
         GCleptonScaleFactorZZ(pdgId2, pt2, eta2);
}



//--------------
float 
WZModule::LeptonScaleFactorWW(int pdgId, float pt, float eta) {
  if (abs(pdgId)==13) return MediumMuonScaleFactorWW(pt, eta);
  else if (abs(pdgId)==11) return MediumElectronScaleFactorWW(pt, eta);
    //if(ht>300) return electronScaleFactorHighHT(pt, eta);
    //else       return electronScaleFactorLowHT(pt, eta);
  //}
  return 0.;
}


float 
WZModule::MediumElectronScaleFactorWW(float pt, float eta) {
// "passingMedium" 
   if (std::abs(eta)>=0 && std::abs(eta)<1.5){
      if (pt>=10 && pt<20) return 0.951;
      if (pt>=20 && pt<30) return 0.952;
      if (pt>=30 && pt<40) return 0.932;
      if (pt>=40 && pt<50) return 0.972;
      if (pt>=50 && pt<70) return 0.980;
      if (pt>=70) return 0.974;
   } else if (std::abs(eta)>=1.5 && std::abs(eta)<2.5){
      if (pt>=10 && pt<20) return 0.951;
      if (pt>=20 && pt<30) return 0.927;
      if (pt>=30 && pt<40) return 0.957;
      if (pt>=40 && pt<50) return 0.984;
      if (pt>=50 && pt<70) return 0.977;
      if (pt>=70) return 0.962;
   }
   return 0.;
}

float 
WZModule::POGMediumElectronScaleFactorWW(float pt, float eta) {
// "Medium, 80%" 
   if (eta >= -2.5 && eta < -1.56){
      if (pt>=10 && pt<25) return 0.875092;
      if (pt>=25 && pt<35) return 0.909022;
      if (pt>=35 && pt<45) return 0.933497;
      if (pt>=45 && pt<55) return 0.943781;
      if (pt>=55) return 0.964878;
   } else if (eta >= -1.56 && eta < -1.442){
      if (pt>=10 && pt<25) return 0.919841;
      if (pt>=25 && pt<35) return 0.958816;
      if (pt>=35 && pt<45) return 0.948981;
      if (pt>=45 && pt<55) return 0.959025;
      if (pt>=55) return 0.960032;
   } else if (eta >= -1.442 && eta < -0.8){
      if (pt>=10 && pt<25) return 0.951201;
      if (pt>=25 && pt<35) return 0.962405;
      if (pt>=35 && pt<45) return 0.972345;
      if (pt>=45 && pt<55) return 0.978349;
      if (pt>=55) return 0.972738;
   } else if (eta >= -0.8 && eta < 0){
      if (pt>=10 && pt<25) return 0.932862;
      if (pt>=25 && pt<35) return 0.964012;
      if (pt>=35 && pt<45) return 0.972032;
      if (pt>=45 && pt<55) return 0.97981;
      if (pt>=55) return 0.985638;
   } else if (eta>=0 && eta<0.8){
      if (pt>=10 && pt<25) return 0.945258;
      if (pt>=25 && pt<35) return 0.969;
      if (pt>=35 && pt<45) return 0.977363;
      if (pt>=45 && pt<55) return 0.985956;
      if (pt>=55) return 0.984022;
   } else if (eta>=0.8 && eta<1.442){
      if (pt>=10 && pt<25) return 0.953177;
      if (pt>=25 && pt<35) return 0.962386;
      if (pt>=35 && pt<45) return 0.971577;
      if (pt>=45 && pt<55) return 0.974854;
      if (pt>=55) return 0.974689;
   } else if (eta>=1.442 && eta<1.56){
      if (pt>=10 && pt<25) return 0.875;
      if (pt>=25 && pt<35) return 0.918064;
      if (pt>=35 && pt<45) return 0.942505;
      if (pt>=45 && pt<55) return 0.932182;
      if (pt>=55) return 0.989869;
   } else if (eta>=1.56 && eta<=2.5){
      if (pt>=10 && pt<25) return 0.876512;
      if (pt>=25 && pt<35) return 0.910395;
      if (pt>=35 && pt<45) return 0.935298;
      if (pt>=45 && pt<55) return 0.9487;
      if (pt>=55) return 0.962644;
   }
   return 0.;
}


float 
WZModule::TightElectronScaleFactorWW(float pt, float eta) {
// "passingMedium" 
   if (std::abs(eta)>=0 && std::abs(eta)<1.5){
      if (pt>=10 && pt<20) return 0.960;
      if (pt>=20 && pt<30) return 0.942;
      if (pt>=30 && pt<40) return 0.959;
      if (pt>=40 && pt<50) return 0.964;
      if (pt>=50 && pt<70) return 0.973;
      if (pt>=70) return 0.977;
   } else if (std::abs(eta)>=1.5 && std::abs(eta)<2.5){
      if (pt>=10 && pt<20) return 0.922;
      if (pt>=20 && pt<30) return 0.916;
      if (pt>=30 && pt<40) return 0.942;
      if (pt>=40 && pt<50) return 0.975;
      if (pt>=50 && pt<70) return 0.970;
      if (pt>=70) return 0.953;
   }
   return 0.;
}


float 
WZModule::MediumMuonScaleFactorWW(float pt, float eta) {
// "passingMedium" 
   if (std::abs(eta)>=0 && std::abs(eta)<1.5){
      if (pt>=10 && pt<20) return 0.856;
      if (pt>=20 && pt<30) return 0.955;
      if (pt>=30 && pt<40) return 0.996;
      if (pt>=40 && pt<50) return 1.001;
      if (pt>=50 && pt<70) return 0.996;
      if (pt>=70) return 0.994;
   } else if (std::abs(eta)>=1.5 && std::abs(eta)<2.5){
      if (pt>=10 && pt<20) return 0.888;
      if (pt>=20 && pt<30) return 0.960;
      if (pt>=30 && pt<40) return 0.991;
      if (pt>=40 && pt<50) return 0.994;
      if (pt>=50 && pt<70) return 0.994;
      if (pt>=70) return 0.985;
   }
   return 0.;
}

float 
WZModule::POGMediumMuonScaleFactorWW(float pt, float eta) {
// "passingMedium" 
   if (std::abs(eta)>=0 && std::abs(eta)<0.9){
      if (pt>=10 && pt<25) return 0.979414*1.00451;
      if (pt>=25 && pt<30) return 0.984815*1.001;
      if (pt>=30 && pt<40) return 0.989551*1.00079;
      if (pt>=40 && pt<50) return 0.991315*0.998682;
      if (pt>=50 && pt<60) return 0.987545*1.0;
      if (pt>=60) return 0.991321*0.998554;
   } else if (std::abs(eta)>=0.9 && std::abs(eta)<1.2){
      if (pt>=10 && pt<25) return 0.987974*1.00434;
      if (pt>=25 && pt<30) return 0.985705*1.00373;
      if (pt>=30 && pt<40) return 0.991785*1.00471;
      if (pt>=40 && pt<50) return 0.992362*1.00166;
      if (pt>=50 && pt<60) return 0.991781*0.997668;
      if (pt>=60) return 0.992222*1.00443;
   } else if (std::abs(eta)>=1.2 && std::abs(eta)<2.1){
      if (pt>=10 && pt<25) return 0.995794*0.99689;
      if (pt>=25 && pt<30) return 0.991305*1.00028;
      if (pt>=30 && pt<40) return 0.993265*1.00312;
      if (pt>=40 && pt<50) return 0.994487*0.999851;
      if (pt>=50 && pt<60) return 0.991223*1.00065;
      if (pt>=60) return 0.995587*1.00057;
   } else if (std::abs(eta)>=2.1 && std::abs(eta)<=2.4){
      if (pt>=10 && pt<25) return 0.976729*0.993198;
      if (pt>=25 && pt<30) return 0.967756*0.993565;
      if (pt>=30 && pt<40) return 0.96795*0.996759;
      if (pt>=40 && pt<50) return 0.965109*1.00271;
      if (pt>=50 && pt<60) return 0.957879*1.00429;
      if (pt>=60) return 0.97477*0.998136;
   }
   return 0.;
}

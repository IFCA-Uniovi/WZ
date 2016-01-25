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
      float massdiff = std::fabs(91.1876 - mll);
      float massdiff90 = std::fabs(90 - mll);
      
      if (massdiff90 > 30) continue;
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
  //this ensures that best mZ is calculated using 3 tight leptons (possibility of [tight, tight, loose, tight] in event, for example)
  // PENDING TASK: understand why, after Z peak selection, this function gives values outside the window, as if there were no valid Z candidate (though such an event shouldn't have passed the cut!)
  float mll = 0;
  float massdiffMin = 9999.9;
  for(unsigned int il1=0;il1<leps->size()-1;il1++) {
    for(unsigned int il2=il1+1;il2<leps->size();il2++) {
   
      int flav = leps->at(il1)->pdgId() + leps->at(il2)->pdgId();
      if (flav != 0 ) continue;
      
      mll = Candidate::create(leps->at(il1), leps->at(il2))->mass();
      float massdiff = std::fabs(91.1876 - mll);
      
      if (massdiffMin < massdiff) continue;
      
      massdiffMin = massdiff;
      
    }//il2
  }//il1
  
  return mll; 
}



// ------------------------------------------------------------------------------------------

// WW leptons
// Slide 4 https://indico.cern.ch/event/485788/contribution/3/attachments/1214544/1772984/OviIFCA-WZstatus.pdf
// Better S/B than ZZ leptons for WZ analysis

bool
WZModule::IsLooseBarrelElectronWW(int idx) {

  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
  if( std::abs(_vc->get("LepGood_dEtaScTrkIn"     , idx))  > 0.01    ) return false;
  if( std::abs(_vc->get("LepGood_dPhiScTrkIn"     , idx))  > 0.04    ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta"            , idx)   > 0.011   ) return false;
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.08    ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.01    ) return false;
  if( _vc->get("LepGood_ecalPFClusterIso"         , idx)   > 0.45    ) return false;
  if( _vc->get("LepGood_hcalPFClusterIso"         , idx)   > 0.25    ) return false;
  if( _vc->get("LepGood_trackIso"                 , idx)   > 0.2     ) return false;
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
  if( _vc->get("LepGood_hadronicOverEm"           , idx)   > 0.08    ) return false;
  if( std::abs(_vc->get("LepGood_eInvMinusPInv"   , idx))  > 0.01    ) return false;
  if( _vc->get("LepGood_ecalPFClusterIso"         , idx)   > 0.45    ) return false;
  if( _vc->get("LepGood_hcalPFClusterIso"         , idx)   > 0.25    ) return false;
  if( _vc->get("LepGood_trackIso"                 , idx)   > 0.2     ) return false;
//  if( _vc->get("LepGood_relIso03"                 , idx)   > 0.766     ) return false;
  if( _vc->get("LepGood_lostHits"                 , idx)   > 1       ) return false;
  if( std::abs(_vc->get("LepGood_dxy"             , idx))  > 0.2     ) return false;
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.602   ) return false;
  if( _vc->get("LepGood_convVeto"                 , idx)   !=1       ) return false;

  return true;

}


bool
WZModule::IsLooseMuonWW(int idx) {

  if( std::abs(_vc->get("LepGood_eta"             , idx))  > 2.4     ) return false;
  if( _vc->get("LepGood_mediumMuonId"             , idx)   !=1       ) return false;
  if( _vc->get("LepGood_relIso04"                 , idx)   > 0.4     ) return false;
  if( _vc->get("LepGood_dr03TkSumPt"              , idx)   > 0.4     ) return false;

  return true;

}

bool
WZModule::IsTightMuonWW(int idx) {

  if( std::abs(_vc->get("LepGood_eta"             , idx))  > 2.4     ) return false;
  if( _vc->get("LepGood_mediumMuonId"             , idx)   !=1       ) return false;
  if( _vc->get("LepGood_relIso04"                 , idx)   > 0.4     ) return false;
  if( _vc->get("LepGood_pt", idx) > 20 ){
    if( std::abs(_vc->get("LepGood_dxy"           , idx))  > 0.02    ) return false;
  } else {
    if( std::abs(_vc->get("LepGood_dxy"           , idx))  > 0.01    ) return false;
  }
  if( std::abs(_vc->get("LepGood_dz"              , idx))  > 0.1     ) return false;
  
  return true;

}


bool
WZModule::IsTightBarrelElectronWW(int idx) {

  if( _vc->get("LepGood_tightId"                  , idx)   < 3       ) return false;
  if( std::abs(_vc->get("LepGood_etaSc"           , idx))  > 1.479   ) return false;
  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0101  ) return false;
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
  if( _vc->get("LepGood_sigmaIEtaIEta_full5x"     , idx)   > 0.0279  ) return false;
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
         GCleptonScaleFactor (pdgId1, pt1, eta1, ht) * 
         GCleptonScaleFactor(pdgId2, pt2, eta2, ht);
}



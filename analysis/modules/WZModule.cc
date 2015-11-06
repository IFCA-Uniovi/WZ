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

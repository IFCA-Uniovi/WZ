#ifndef WZModule_hh
#define WZModule_hh

#include "analysis/core/VarClass.hh"
#include "analysis/tools/Candidate.hh"
#include "analysis/utils/KineUtils.hh"
#include "tools/src/DataBaseManager.hh"
#include "analysis/modules/SusyModule.hh"

class WZModule: public SusyModule {

public:

  WZModule(VarClass* vc);
  WZModule(VarClass* vc, DataBaseManager* dbm);
  ~WZModule();

  CandList bestWZ(const CandList* leps, int& idxZ1, int& idxZ2, int& idxW);
  CandList bestZ(const CandList* leps, int& idxZ1, int& idxZ2);
  CandList ThreeLeps(const CandList* leps);
  float bestmZ(const CandList* leps);
  float m3lTight(const CandList* leps);


  bool IsLooseBarrelElectronWW(int idx) const;
  bool IsLooseEndcapElectronWW(int idx) const;
  bool IsLooseMuonWW(int idx) const;
  bool IsTightBarrelElectronWW(int idx) const;
  bool IsTightEndcapElectronWW(int idx) const;
  bool IsTightMuonWW(int idx) const;
 
  
  float GCleptonScaleFactorZZ(int pdgId, float pt, float eta);
  float GCelectronScaleFactorZZ(float pt, float eta);
  float GCmuonScaleFactorZZ(float pt, float eta);
  
  float GCtriggerScaleFactorZZ(int pdgId1, int pdgId2, float pt1, float pt2, float ht);
  float GCeventScaleFactorZZ(int pdgId1, int pdgId2, float pt1, float pt2, float eta1, float eta2, float ht);
  
  
  bool IsDumpable(int evt);

protected:
  //const
  VarClass* _vc;
  DataBaseManager* _dbm;


};

#endif

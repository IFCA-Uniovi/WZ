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


  bool IsLooseBarrelElectronWW(int idx);
  bool IsLooseEndcapElectronWW(int idx);
  bool IsLooseMuonWW(int idx);
  bool IsMediumBarrelElectronWW(int idx);
  bool IsMediumEndcapElectronWW(int idx);
  bool IsTightBarrelElectronWW(int idx);
  bool IsTightEndcapElectronWW(int idx);
  bool IsTightMuonWW(int idx);
  
  bool IsLooseBarrelElectronZZ(int idx);
  bool IsLooseEndcapElectronZZ(int idx);
  bool IsLooseMuonZZ(int idx);
  bool IsTightBarrelElectronZZ(int idx);
  bool IsTightEndcapElectronZZ(int idx);
  bool IsTightMuonZZ(int idx);
 
  float bTagSF_HL(CandList& jets , vector<pair<string, unsigned int> >& jetIdx ,
               CandList& bJets, vector<pair<string, unsigned int> >& bJetIdx,
	           int heavy, int light);
  
  float GCleptonScaleFactorZZ(int pdgId, float pt, float eta);
  float GCelectronScaleFactorZZ(float pt, float eta);
  float GCmuonScaleFactorZZ(float pt, float eta);
  
  float GCtriggerScaleFactorZZ(int pdgId1, int pdgId2, float pt1, float pt2, float ht);
  float GCeventScaleFactorZZ(int pdgId1, int pdgId2, float pt1, float pt2, float eta1, float eta2, float ht);
  
  
  bool IsDumpable(int evt);

protected:
  //const
  //VarClass* _vc;
  //DataBaseManager* _dbm;


};

#endif

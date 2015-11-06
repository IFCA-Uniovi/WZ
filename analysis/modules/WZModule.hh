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

protected:
  //const
  VarClass* _vc;
  DataBaseManager* _dbm;

};

#endif

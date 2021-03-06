#include "analysis/src/AnalysisFactory.hh"

using namespace std;

//list of analyzers and modules in alphabetical order
//#include "analysis/src/csa14exerc.hh"
#include "analysis/src/SSDLBoosted.hh"
#include "analysis/src/synchECO.hh"
#include "analysis/src/synchRA5.hh"
#include "analysis/src/phys14exerc.hh"
#include "analysis/src/SUSY3L.hh"
#include "analysis/src/SUSY3L_sync.hh"
#include "analysis/src/SUSY3L_sync2.hh"
#include "analysis/src/SUSY3L_sync3.hh"
#include "analysis/src/phys14limits.hh"
#include "analysis/src/FakeRatio.hh"
#include "analysis/src/FakeRatioStudy.hh"
#include "analysis/src/sideband.hh"
#include "analysis/src/FRinSitu.hh"
#include "analysis/src/SSDL2015.hh"
#include "analysis/src/UncertaintyTest.hh"
//#include "analysis/src/Comissioning.hh"
#include "analysis/src/WZsynchro.hh"
#include "analysis/src/FakeRatioWZ.hh"
#include "analysis/src/WZsyst.hh"
#include "analysis/src/WZacc.hh"


MPAF*
AnalysisFactory::get(const string& analysis, const string& cfg) {
 
// list of analyzers and modules in alphabetical order 
  
//  if(analysis=="csa14exerc") {
//    return new csa14exerc(cfg);
//  }
  if(analysis=="SSDLBoosted") {
    return new SSDLBoosted(cfg);
  }
//  if(analysis=="synchECO") {
//    return new synchECO(cfg);
//  }
//  if(analysis=="synchRA5") {
//    return new synchRA5(cfg);
//  }
  if(analysis=="phys14limits") {
    return new phys14limits(cfg);
  }
  if(analysis=="SUSY3L") {
    return new SUSY3L(cfg);
  }
  if(analysis=="SUSY3L_sync") {
    return new SUSY3L_sync(cfg);
  }
  if(analysis=="SUSY3L_sync2") {
    return new SUSY3L_sync2(cfg);
  }
  if(analysis=="SUSY3L_sync3") {
    return new SUSY3L_sync3(cfg);
  }
  if(analysis=="FakeRatio") {
    return new FakeRatio(cfg);
  }
  if(analysis=="FakeRatioStudy") {
    return new FakeRatioStudy(cfg);
  }
  if(analysis=="sideband") {
    return new sideband(cfg);
  }
  if(analysis=="FRinSitu") {
    return new FRinSitu(cfg);
  }
  if(analysis=="SSDL2015") {
    return new SSDL2015(cfg);
  }
  if(analysis=="UncertaintyTest") {
    return new UncertaintyTest(cfg);
  }
  //if(analysis=="Comissioning") {
    //return new Comissioning(cfg);
  //}
  if(analysis=="WZsynchro") {
    return new WZsynchro(cfg);
  }
  if(analysis=="FakeRatioWZ") {
    return new FakeRatioWZ(cfg);
  }
  if(analysis=="WZsyst") {
    return new WZsyst(cfg);
  }
  if(analysis=="WZacc") {
    return new WZacc(cfg);
  }
  return 0;
}

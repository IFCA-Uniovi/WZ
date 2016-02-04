#include <iostream>
#include <math.h>
//called by yieldsWZ_test.sh to get yields with variations for uncertainties
////////// Use with rootfiles produced by analyzer WZsyst




void listyieldsWZ_test(std::string rootfile, int wzstep, std::string proc,int var){
	string WZstepname [7]= {"Three leptons",
	"WZ candidate",
	"Z sel",
	"W sel",
	"M(3l) > 100 GeV",
	"1 or 0 b-jets",
	"0 b-jets"};
	
	string variation [5]= {"Central",
	"Up b-tag",
	"Down b-tag",
	"Up b-mistag",
	"Down b-mistag"};
	
	TH1F *histo = nullptr;
	TFile *f = new TFile(rootfile.c_str());
	if (var == 0) histo = (TH1F*)f->Get(Form("MET_WZSMstep%i/%s",wzstep, proc.c_str() ));
	if (var == 1) histo = (TH1F*)f->Get(Form("MET_UncBTAGUp/%s", proc.c_str() ));
	if (var == 2) histo = (TH1F*)f->Get(Form("MET_UncBTAGDo/%s", proc.c_str() ));
	if (var == 3) histo = (TH1F*)f->Get(Form("MET_UncBMISTAGUp/%s", proc.c_str() ));
	if (var == 4) histo = (TH1F*)f->Get(Form("MET_UncBMISTAGDo/%s", proc.c_str() ));
	Int_t yield = histo->GetEntries();
	Double_t integral = histo->Integral();
	
	Double_t normfactor;
	
	if (proc.find("DYJetsToLL_M10to50") != std::string::npos) normfactor=18610/2.967885e+07;
	else if (proc.find("DYJetsToLL_M50") != std::string::npos) normfactor=6025.2/2.874797e+07;
	else if (proc.find("TbarW") != std::string::npos) normfactor=35.6/988500;
	else if (proc.find("TToLeptons_sch") != std::string::npos) normfactor=3.68064/984400;
	else if (proc.find("TToLeptons_tch") != std::string::npos) normfactor=44.071956/3299800;
	else if (proc.find("TbarToLeptons_tch") != std::string::npos) normfactor=26.2278/1680200;
	else if (proc.find("TTJets") != std::string::npos) normfactor=831.8/8.970451e+07;
	else if (proc.find("TTWToLNu") != std::string::npos) normfactor=0.2043/252908;
	else if (proc.find("TTZToLLNuNu") != std::string::npos) normfactor=0.2529/398000;
	else if (proc.find("TTHnobb") != std::string::npos) normfactor=0.2151/1562609;
	else if (proc.find("TTGJets") != std::string::npos) normfactor=3.697/4832230;
	else if (proc.find("_TW_") != std::string::npos) normfactor=35.6/995600;
	else if (proc.find("WJetsToLNu") != std::string::npos) normfactor=61526.7/2.239467e+07;
	else if (proc.find("WWTo2L2Nu") != std::string::npos) normfactor=12.178/1965200;
	else if (proc.find("WZTo3LNu") != std::string::npos) normfactor=4.42965/1980800;
	else if (proc.find("_ZZ_") != std::string::npos) normfactor=16.523/996944;
	else if (proc.find("GGHZZ4L") != std::string::npos) normfactor=0.01212/498000;
	else if (proc.find("WGToLNuG") != std::string::npos) normfactor=585.8/6099599;
	else if (proc.find("_WWZ_") != std::string::npos) normfactor=0.1651/250000;
	else if (proc.find("_WZZ_") != std::string::npos) normfactor=0.05565/250000;
	else if (proc.find("_ZZZ_") != std::string::npos) normfactor=0.01398/250000;

	
    Double_t yield_scaled = histo->Integral(0,100000000)*normfactor*2260;

	if (rootfile.find("all") != std::string::npos){
		cout << WZstepname[wzstep] << "" << "\t" << variation[var] <<"\t" << yield_scaled << endl;
	} else if (rootfile.find("eee") != std::string::npos) {
		cout << "Selection step:	" << WZstepname[wzstep] << "	" << "eee	" << yield << endl;
	} else if (rootfile.find("eem") != std::string::npos) {
		cout << "Selection step:	" << WZstepname[wzstep] << "	" << "eem	" << yield << endl;
	} else if (rootfile.find("mme") != std::string::npos) {
		cout << "Selection step:	" << WZstepname[wzstep] << "	" << "mme	" << yield << endl;
	} else if (rootfile.find("mmm") != std::string::npos) {
		cout << "Selection step:	" << WZstepname[wzstep] << "	" << "mmm	" << yield << endl;
	}
}

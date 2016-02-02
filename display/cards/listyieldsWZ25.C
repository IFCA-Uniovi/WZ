
#include <iostream>
#include <math.h>
//called by yieldsWZ25_table.sh to get WZ yields
void listyieldsWZ25(std::string rootfile, int wzstep){
	string WZstepname [7]= {"Three leptons",
	"WZ candidate",
	"Z sel",
	"W sel",
	"M(3l) > 100 GeV",
	"1 or 0 b-jets",
	"0 b-jets"};
	
	
	TFile *f = new TFile(rootfile.c_str());
	TH1F *histo = (TH1F*)f->Get(Form("M3l_WZSMstep%i/Tree_WZTo3LNu_0",wzstep));
	Int_t yield = histo->GetEntries();

	
	if (rootfile.find("all") != std::string::npos){
		cout << "Selection step:	" << WZstepname[wzstep] << "	" << "all	" << yield << endl;
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

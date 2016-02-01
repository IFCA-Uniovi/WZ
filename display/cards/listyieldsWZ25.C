#include <iostream>
#include <math.h>
//called by yieldsWZ25_table.sh to get WZ yields
void listyieldsWZ25(std::string rootfile, int wzstep, std::string proc){
	string WZstepname [7]= {"Three leptons",
	"WZ candidate",
	"Z sel",
	"W sel",
	"M(3l) > 100 GeV",
	"1 or 0 b-jets",
	"0 b-jets"};
	
	
	TFile *f = new TFile(rootfile.c_str());
	TH1F *histo = (TH1F*)f->Get(Form("MET_WZSMstep%i/%s",wzstep, proc.c_str() ));
	Int_t yield = histo->GetEntries();
	Double_t integral = histo->Integral();
	
	Double_t xsec;
	
	if (rootfile.find("DYJetsToLL_M10to50") != std::string::npos) xsec=18610;
	else if (rootfile.find("DYJetsToLL_M50") != std::string::npos) xsec=6025.2;
	else if (rootfile.find("TbarW") != std::string::npos) xsec=35.6;
	else if (rootfile.find("TToLeptons_sch") != std::string::npos) xsec=3.68064;
	else if (rootfile.find("TToLeptons_tch") != std::string::npos) xsec=44.071956;
	else if (rootfile.find("TbarToLeptons_tch") != std::string::npos) xsec=26.2278;
	else if (rootfile.find("TTJets") != std::string::npos) xsec=831.8;
	else if (rootfile.find("TTWToLNu") != std::string::npos) xsec=0.2043;
	else if (rootfile.find("TTZToLLNuNu") != std::string::npos) xsec=0.2529;
	else if (rootfile.find("TTHnobb") != std::string::npos) xsec=0.2151;
	else if (rootfile.find("TTGJets") != std::string::npos) xsec=3.697;
	else if (rootfile.find("_TW_") != std::string::npos) xsec=35.6;
	else if (rootfile.find("WJetsToLNu") != std::string::npos) xsec=61526.7;
	else if (rootfile.find("WWTo2L2Nu") != std::string::npos) xsec=12.178;
	else if (rootfile.find("WZTo3LNu") != std::string::npos) xsec=4.42965;
	else if (rootfile.find("_ZZ_") != std::string::npos) xsec=16.523;
	else if (rootfile.find("GGHZZ4L") != std::string::npos) xsec=0.01212;
	else if (rootfile.find("WGToLNuG") != std::string::npos) xsec=585.8;
	else if (rootfile.find("_WWZ_") != std::string::npos) xsec=0.1651;
	else if (rootfile.find("_WZZ_") != std::string::npos) xsec=0.05565;
	else if (rootfile.find("_ZZZ_") != std::string::npos) xsec=0.01398;

	
    Double_t yield_scaled = 2260.*xsec*integral;
	
	if (rootfile.find("all") != std::string::npos){
		cout << WZstepname[wzstep] << "" << "\tall\t" << yield_scaled << endl;
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

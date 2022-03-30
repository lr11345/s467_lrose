//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//Si Units
float m_proton = 0.93827208816;//   GeV/c^2
float m_nuetron = 0.93956542052;//  GeV/c^2
float m_electron = 0.51099895000*pow(10,-3);// GeV/c^2
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//Conditions for specific incoming nuclei.
double FRS_A = 40;
double FRS_Z = 20;
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//Particle Conditions
double FRSBeta, FRSBrho,FRSAoQ,FRSGamma;
double FRAG_A,FRAG_Z,FRAG_BRHO,FRAG_BETA;
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//Detector Conditions
double Mw0_Z = 0.0;//mm
double Mw1_Z = 2794.0;//mm
double Mw2_Z = 3434.0;//mm
double MwT_Z = 1830.5;//mm
double MusicE,MusicZ,MusicTheta,TwimE,TwimZ,TwimTheta;
double Mw0_X,Mw0_Y,Mw1_X,Mw1_Y,Mw2_X,Mw2_Y,Mw3_X,Mw3_Y,MwT_X,MwT_Y;
double MusicZC;
double Tofw_Y,Tofw_Paddle;
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//load merged cal runs.
//Tree should have the same structure.
TFile*file_empty = new TFile("mktree_fragment_empty.root","READ");
TFile*file_empty_all = new TFile("mktree_fragment_empty_all.root","READ");
TFile*file_empty_e = new TFile("mktree_fragment_empty_early.root","READ");
TFile*file_empty_l = new TFile("mktree_fragment_empty_end.root","READ");
TFile*file_C = new TFile("mktree_fragment_carbon.root","READ");
TFile*file_CH2 = new TFile("mktree_fragment_ch2-24mm.root","READ");
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//List of Histograms for before and after gates
TH2D*MWPC0;
TH2D*MWPC1;
TH2D*MWPC2;
TH2D*MWPC3;
TH2D*MWPCT;
TH1D*MWPCT_X;
TH1D*MWPCT_Y;
TH2D*MUSIC_Z_TH;
TH2D*MWPC0_FRS;
TH2D*MWPC1_FRS;
TH2D*MWPC2_FRS;
TH2D*MWPC3_FRS;
TH2D*MUSIC_Z_TH_FRS;
TH1D*FRS_MASS_GATE;
TH1D*FRS_BETA_GATE;
TH1D*MUSIC_Z;
TH1D*MUSIC_Z_T;
TH1D*MUSIC_ZN;
TH1D*TWIM_Z;
TH1D*TWIM_Z_T;
TH1D*TWIM_ZN;
TGraph*MUSIC_CAL;
TH1D*MUSIC_BETA_ELOSS;
TGraph*CAL;
TH1D*GAUS_FIT[10];

TF1*gaus = new TF1("gaus","gaus");
TF1*pol1 = new TF1("pol1","pol1");
TF1*pol2 = new TF1("pol2","pol2");
TF1*pol3 = new TF1("pol3","pol3");

//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
void TH1DNAME(TH1D*HIST,char*name,char*xaxis,char*yaxis){
HIST->SetTitle(name);
HIST->SetName(name);
HIST->GetXaxis()->SetTitle(xaxis);
HIST->GetYaxis()->SetTitle(yaxis);
gStyle->SetPalette(1);
}
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+





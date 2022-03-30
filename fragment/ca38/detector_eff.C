#include "detector_eff.hh"
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
//ASSUMPTIONS
// (0,0) centre of MWPC0-2 -->200x200 hence +/-100mm
// (0,0) centre of MWPC3 -->900�~W600 mm2 -->
// Small angle Approx Tan(X)~X --> Sin(X)~X, Cos(X)~1
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+

void detector_eff()
{
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
TTree*tree = (TTree*)file_C->Get("Tree");//Edit file of choice here

TLeaf*FRSBetaL= tree->FindLeaf("FRSBeta");
TLeaf*FRSBrhoL = tree->FindLeaf("FRSBrho");
TLeaf*FRSAoQL = tree->FindLeaf("FRSAoQ");
TLeaf*FRAG_AL = tree->FindLeaf("FragAoQ");
TLeaf*FRAG_ZL = tree->FindLeaf("FragZ");
TLeaf*FRAG_BRHOL = tree->FindLeaf("FragBrho");
TLeaf*FRAG_BETAL = tree->FindLeaf("FragBeta");
TLeaf*MusicEL = tree->FindLeaf("MusicE");
TLeaf*MusicZL = tree->FindLeaf("MusicZ");
TLeaf*MusicThetaL = tree->FindLeaf("MusicTheta");
TLeaf*TwimEL = tree->FindLeaf("TwimE");
TLeaf*TwimZL = tree->FindLeaf("TwimZ");
TLeaf*TwimThetaL = tree->FindLeaf("TwimTheta");
TLeaf*Mw0_XL = tree->FindLeaf("Mw0_X");
TLeaf*Mw0_YL = tree->FindLeaf("Mw0_Y");
TLeaf*Mw1_XL = tree->FindLeaf("Mw1_X");
TLeaf*Mw1_YL = tree->FindLeaf("Mw1_Y");
TLeaf*Mw2_XL = tree->FindLeaf("Mw2_X");
TLeaf*Mw2_YL = tree->FindLeaf("Mw2_Y");
TLeaf*Mw3_XL = tree->FindLeaf("Mw3_X");
TLeaf*Mw3_YL = tree->FindLeaf("Mw3_Y");
TLeaf*Tofw_YL = tree->FindLeaf("Tofw_Y");
TLeaf*Tofw_PaddleL = tree->FindLeaf("Tofw_Paddle");
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
  MWPCT = new TH2D("MWPCT","Target Phase Space",200,-100,100,200,-100,100);
MWPCT->GetXaxis()->SetTitle("X position [mm]");
MWPCT->GetYaxis()->SetTitle("Y position [mm]");

MWPCT_X = new TH1D("MWPCT_X","Target X position",200,-100,100);
MWPCT_X->GetXaxis()->SetTitle("X position [mm]");

MWPCT_Y = new TH1D("MWPCT_Y","Target Y position",200,-100,100);
MWPCT_Y->GetXaxis()->SetTitle("Y position [mm]");

MWPC0 = new TH2D("MWPC0","MWPC0 Phase Space",200,-100,100,200,-100,100);
MWPC0->GetXaxis()->SetTitle("X position [mm]");
MWPC0->GetYaxis()->SetTitle("Y position [mm]");

MWPC1 = new TH2D("MWPC1","MWPC1 Phase Space",200,-100,100,200,-100,100);
MWPC1->GetXaxis()->SetTitle("X position [mm]");
MWPC1->GetYaxis()->SetTitle("Y position [mm]");

MWPC2 = new TH2D("MWPC2","MWPC2 Phase Space",200,-100,100,200,-100,100);
MWPC2->GetXaxis()->SetTitle("X position [mm]");
MWPC2->GetYaxis()->SetTitle("Y position [mm]");

MWPC3 = new TH2D("MWPC3","MWPC3 Phase Space",900,-450,450,600,-300,300);
MWPC3->GetXaxis()->SetTitle("X position [mm]");
MWPC3->GetYaxis()->SetTitle("Y position [mm]");

MWPC0_FRS = new TH2D("MWPC0_FRS","MWPC0 Phase Space After FRS Cut",200,-100,100,200,-100,100);
MWPC0_FRS->GetXaxis()->SetTitle("X position [mm]");
MWPC0_FRS->GetYaxis()->SetTitle("Y position [mm]");

MWPC1_FRS = new TH2D("MWPC1_FRS","MWPC1 Phase Space After FRS Cut",200,-100,100,200,-100,100);
MWPC1_FRS->GetXaxis()->SetTitle("X position [mm]");
MWPC1_FRS->GetYaxis()->SetTitle("Y position [mm]");

MWPC2_FRS = new TH2D("MWPC2_FRS","MWPC2 Phase Space After FRS Cut",200,-100,100,200,-100,100);
MWPC2_FRS->GetXaxis()->SetTitle("X position [mm]");
MWPC2_FRS->GetYaxis()->SetTitle("Y position [mm]");

MWPC3_FRS = new TH2D("MWPC3_FRS","MWPC3 Phase Space After FRS Cut",900,-450,450,600,-300,300);
MWPC3_FRS->GetXaxis()->SetTitle("X position [mm]");
MWPC3_FRS->GetYaxis()->SetTitle("Y position [mm]");

MUSIC_Z_TH_FRS = new TH2D("MUSIC_Z_TH_FRS","R3BMusic Z vs Theta After FRS Cut ",200,10,30,200,-50,50);
MUSIC_Z_TH_FRS->GetXaxis()->SetTitle("Z");
MUSIC_Z_TH_FRS->GetYaxis()->SetTitle("Theta [mrad]");
MUSIC_Z_TH = new TH2D("MUSIC_Z_TH","R3BMusic Z vs Theta ",200,10,30,200,-50,50);
MUSIC_Z_TH->GetXaxis()->SetTitle("Z");
MUSIC_Z_TH->GetYaxis()->SetTitle("Theta [mrad]");
MUSIC_Z = new TH1D("MUSIC_Z","Music Z Measure",200,10,30);
MUSIC_Z->GetXaxis()->SetTitle("Z");

FRS_MASS_GATE = new TH1D("FRS_MASS_GATE","",200,30,50);
FRS_MASS_GATE->GetXaxis()->SetTitle("Mass of Nuclei [A]");
FRS_BETA_GATE = new TH1D("FRS_BETA_GATE","",500,0.6,0.8);
FRS_BETA_GATE->GetXaxis()->SetTitle("Beta [c]");
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
for(int i = 0 ; i < tree->GetEntries();i++)
{
tree->GetEntry(i);
FRSBeta=FRSBetaL->GetValue();
FRSAoQ=FRSAoQL->GetValue();
FRSBrho=FRSBrhoL->GetValue();
FRAG_A=FRAG_AL->GetValue();
FRAG_Z=FRAG_ZL->GetValue();
FRAG_BRHO=FRAG_BRHOL->GetValue();
FRAG_BETA=FRAG_BETAL->GetValue();
MusicE=MusicEL->GetValue();
MusicZ=MusicZL->GetValue();
MusicZC = MusicZ+0.464063;
MusicTheta=MusicThetaL->GetValue();//X only
TwimE=TwimEL->GetValue();
TwimZ=TwimZL->GetValue();
TwimTheta=TwimThetaL->GetValue();//X only
Mw0_X=Mw0_XL->GetValue();
Mw0_Y=Mw0_YL->GetValue();
Mw1_X=Mw1_XL->GetValue();
Mw1_Y=Mw1_YL->GetValue();
Mw2_X=Mw2_XL->GetValue();
Mw2_Y=Mw2_YL->GetValue();
Mw3_X=Mw3_XL->GetValue();
Mw3_Y=Mw3_YL->GetValue();
Tofw_Y=Tofw_YL->GetValue();
Tofw_Paddle=Tofw_PaddleL->GetValue();

MwT_Y = (MwT_Z*(Mw2_Y-Mw0_Y)/(Mw2_Z-Mw0_Z))+Mw0_Y;
MwT_X = MwT_Z*MusicTheta + Mw0_X;

//Linear transform?? ^^^^
cout << MusicZC  << endl;
MWPC0->Fill(Mw0_X,Mw0_Y);
MWPC1->Fill(Mw1_X,Mw1_Y);
MWPC2->Fill(Mw2_X,Mw2_Y);
MWPC3->Fill(Mw3_X,Mw3_Y);
MUSIC_Z_TH->Fill(MusicZC,MusicTheta*1000);
MUSIC_Z->Fill(MusicZC);
FRS_MASS_GATE->Fill(FRSAoQ*MusicZC);
FRS_BETA_GATE->Fill(FRSBeta);
//MUSIC SHIFTED -->Gain Correction Needed
//Fix these for more automatic after R3BMusics CAL.
//if((FRSAoQ*MusicZC)<40.5 && (FRSAoQ*MusicZC)>39.5 && MusicZC>19.5 && MusicZC<20.5 )
{
MWPC0_FRS->Fill(Mw0_X,Mw0_Y);
MWPC1_FRS->Fill(Mw1_X,Mw1_Y);
MWPC2_FRS->Fill(Mw2_X,Mw2_Y);
MWPC3_FRS->Fill(Mw3_X,Mw3_Y);
MUSIC_Z_TH_FRS->Fill(MusicZC,MusicTheta*1000);
MWPCT->Fill(MwT_X,MwT_Y);
MWPCT_X->Fill(MwT_X);
MWPCT_Y->Fill(MwT_Y);

}

}
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+


//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
TCanvas*can1 = new TCanvas("can1","MWPC Phase Space");
can1->Divide(2,2);
can1->cd(1);
MWPC0->Draw("COLZ");
can1->cd(2);
MWPC1->Draw("COLZ");
can1->cd(3);
MWPC2->Draw("COLZ");
can1->cd(4);
MWPC3->Draw("COLZ");
/*
TCanvas*can2 = new TCanvas("can2","R3BMusic");
can2->Divide(2,2);
can2->cd(1);
MUSIC_Z_TH->Draw("COLZ");
can2->cd(2);
MUSIC_Z_TH_FRS->Draw("COLZ");
*/
TCanvas*can3 = new TCanvas("can3","MWPC Phase Space After FRS Cut");
can3->Divide(2,2);
can3->cd(1);
MWPC0_FRS->Draw("COLZ");
can3->cd(2);
MWPC1_FRS->Draw("COLZ");
can3->cd(3);
MWPC2_FRS->Draw("COLZ");
can3->cd(4);
MWPC3_FRS->Draw("COLZ");
TCanvas*can4 = new TCanvas("can4","FRS Gate");
can4->Divide(2,1);
can4->cd(1);
FRS_MASS_GATE->Draw();
can4->cd(2);
FRS_BETA_GATE->Draw();
can4->cd(3);
MUSIC_Z->Draw();

TCanvas*can5 = new TCanvas("can5","Target Position after gating");
can5->Divide(2,2);
can5->cd(1);
MWPCT->Draw("COLZ");
can5->cd(2);
MWPCT_X->Draw();
can5->cd(3);
MWPCT_Y->Draw();
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+




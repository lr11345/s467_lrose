#include <iostream>
#include <fstream>
#include "detector_eff.hh"
#include "TMath.h"
TH2D*MUSIC_V_TWIM;
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
void start(const char *name){


    std::ifstream f(name);

    if (f.is_open())
        std::cout << f.rdbuf();

}
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+
#define BAR "\e[31m>>>>>>>>>>>>>>>>>>>>>>>>>>>><\e[0m"
#define BARW (sizeof BAR - 1 )
void printProgress(double percentage)
{
int val = (int)(percentage*100);
int lpad =(int)(percentage*BARW);
int rpad = BARW-lpad;
printf("\r%3d%% [%.*s%*s]",val,lpad,BAR,rpad,"");
fflush(stdout);
}
//+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+**+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+*+




void R3BMusic_Gain(){
start("art.txt");

TFile* ofile = new TFile("GainShift.root","RECREATE");
ofile->cd();
TTree*tree = (TTree*)file_empty_all->Get("Tree");//Edit file of choice here
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

double maxNumber = tree->GetEntries();
cout <<"Number of entries in tree:  " << maxNumber << endl;
TH2D*GainMusic;
TH2D*GainTwim;
GainMusic = new TH2D("GainMusic","Gain Shift in R3BMusic",maxNumber/10000,0,maxNumber/1000,1000,2000,5000);
GainTwim = new TH2D("GainTwim","Gain Shift in R3BTwinMusic",maxNumber/10000,0,maxNumber/1000,1000,2000,5000);
for(int i = 0 ; i < tree->GetEntries();i++)
        {
        tree->GetEntry(i);
        Mw0_X = Mw0_XL->GetValue();
        MusicE=MusicEL->GetValue();
        TwimE=TwimEL->GetValue();
        if(Mw0_X<0){
        GainMusic->Fill(i/1000,MusicE);
        GainTwim->Fill(i/1000,TwimE);
        //cout << MusicE << " , " ;
        double per = (i+1.) /maxNumber;
        printProgress(per);
        }

        }
cout << endl;



TCanvas*c1 = new TCanvas("c1","Gain Shift in The R3BMusic");
c1->cd(1);
GainMusic->GetXaxis()->SetTitle("{(Event Number)}/{10000}");
GainMusic->GetYaxis()->SetTitle("Energy Measurment of R3BMusic");
GainMusic->Draw("COLZ");
TCanvas*c2 = new TCanvas("c2","Gain Shift in The R3BTwinMusic");
c2->cd(1);
GainTwim->GetXaxis()->SetTitle("{(Event Number)}/{10000}");
GainTwim->GetYaxis()->SetTitle("Energy Measurment of R3BTwinMusic");
GainTwim->Draw("COLZ");

TH1D*TwimYProj[1000];
TH1D*MusicYProj[1000];
int maxBinTwim[1000];
int maxBinMusic[1000];
double maxPosTwim[1000];
double maxPosMusic[1000];
double maxMeanPosTwim[1000];
double maxMeanPosMusic[1000];
int num = maxNumber/10000;
TGraph*GainDriftMusic;
TGraph*GainDriftTwim;
GainDriftMusic = new TGraph();
GainDriftTwim = new TGraph();
int setPoint=0;
for(int i =0 ; i<num;i++)
{
TwimYProj[i] = (TH1D*)GainTwim->ProjectionY(Form("TwimProj_%d",i),i,i+1);
MusicYProj[i] = (TH1D*)GainMusic->ProjectionY(Form("MusicProj_%d",i),i,i+1);
;

maxBinTwim[i] =TwimYProj[i]-> GetMaximumBin();
maxBinMusic[i] =MusicYProj[i]-> GetMaximumBin();


maxPosTwim[i] = TwimYProj[i]->GetXaxis()->GetBinCenter(maxBinTwim[i]);
maxPosMusic[i] = MusicYProj[i]->GetXaxis()->GetBinCenter(maxBinMusic[i]);
TwimYProj[i]->GetXaxis()->SetRange(maxBinTwim[i]-80 ,maxBinTwim[i]+80);
MusicYProj[i]->GetXaxis()->SetRange(maxBinMusic[i]-80,maxBinMusic[i]+80);
TwimYProj[i]->Fit("gaus","Q");
maxMeanPosTwim[i] = gaus->GetParameter(1);
MusicYProj[i]->Fit("gaus","Q");
maxMeanPosMusic[i] = gaus->GetParameter(1);
ofile->Write();
//cout<< "Twin Music Max Energy: " << maxPosTwim[i]<<endl;
//cout<< "Music Max Energy: " << maxPosMusic[i]<<endl;
GainDriftMusic->SetPoint(setPoint,i,maxMeanPosMusic[i]);
GainDriftTwim->SetPoint(setPoint,i,maxMeanPosTwim[i]);
setPoint++;
        double per1 = (i+1.) /num;
      //  printProgress(per1);
cout << maxMeanPosMusic[i] - maxPosMusic[i] <<endl;
cout << maxMeanPosTwim[i] - maxPosTwim[i] <<endl;
}
TCanvas*c3 = new TCanvas("c3","Gain Drifts in R3BMusic and R3BTwinMusic");
c3->Divide(1,2);
c3->SetTitle("Gain Drifts for Ca38 Setting");
c3->cd(1);
GainDriftMusic->SetTitle("Gain Drifts Measured in R3BMusic");
GainDriftMusic->GetYaxis()->SetTitle("Mean Energy Measured in R3BMusic");
GainDriftMusic->SetMarkerStyle(22);
GainDriftMusic->SetMarkerColor(kBlue);
GainDriftMusic->Draw("ALP*");
c3->cd(2);
GainDriftTwim->SetTitle("Gain Drifts Measured in R3BTwinMusic");
GainDriftTwim->GetYaxis()->SetTitle("Mean Energy Measured in R3BTwinMusic");
GainDriftTwim->SetMarkerStyle(22);
GainDriftTwim->SetMarkerColor(kRed);
GainDriftTwim->Draw("ALP*");







}

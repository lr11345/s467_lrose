double C_12 = 12.096;//1.11%c13+98.89%c12
double CH2 = 14.0236;
double Thick_C = 10.86*pow(10,-3);//m
double Thick_CH2=24.53*pow(10,-3);//m
double Rho_C = 1.84*pow(10,6);//gm^-3           1.84gcm^-3    1 kg/m3 = 0.001 g/cm3             ->>>1840kgm^-3   cancels with mm
double Rho_CH2 = 0.94*pow(10,6);//gm^-3
double Barn = pow(10,28);//m^2
double N_a = 6.022*pow(10,23);//mol^-1

float m_proton = 0.93827208816;//   GeV/c^2
float m_nuetron = 0.93956542052;//  GeV/c^2
float m_electron = 0.51099895000;//DONT NEED ION

double C_12_NUMDEN = C_12*N_a;
double CH2_NUMDEN = CH2*N_a;

Int_t A,Z,A_F,Z_F;
double p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
double p11,p12,p13,p14,p15,p16,p17,p18,p19,p20;
double p21,p22,p23,p24,p25,p26,p27,p28;
double TOT;
double TOT_tmp;
double sigma;
double percentage =0;

double  a_nuclei,a_frag,z_nuclei,z_frag,p_ce,p_ch2e,percentage_carbon,percentage_ch2,percentage_empty;
double sigma_ce,sigma_ch2e,sigma_r;

double eff_track=0;


double unreacted=0.;

void cross_section_R(const char * ifile , TFile*ofile,TTree*tree)
{
        fstream file;
        file.open(ifile,ios::in);
        if(file==NULL){cout << "KYS"<<endl;}
        ofile->cd();
struct STRUCTURE{
        int A,Z,A_FRAG,Z_FRAG,TOT;
        STRUCTURE(int AP,int ZP,int A_FRAGP,int Z_FRAGP,int TOTP):
        A(AP),Z(ZP),A_FRAG(A_FRAGP),Z_FRAG(Z_FRAGP),TOT(TOTP)
        {}

};
std::vector<STRUCTURE> vec_tot;


        while(file>>Z>>A>>Z_F>>A_F>>p1>>p2>>p3>>p4>>p5>>p6>>p7>>p8>>p9>>p10>>p11>>p12>>p13>>p14>>p15>>p16>>p17>>p18>>p19>>p20>>p21>>p22>>p23>>p24>>p25>>p26>>p27>>p28>>TOT)
        {
                          if(A_F==0 && Z_F==0){TOT_tmp=TOT;vec_tot.clear();}
                vec_tot.push_back(STRUCTURE(A,Z,A_F,Z_F,TOT));
                if(A_F==A && Z_F==Z){
                auto &last=vec_tot[vec_tot.size()-1];
                        for(int i = 1 ; i<vec_tot.size()-1;i++){
                        auto &s=vec_tot[i];
                        if(last.TOT!=0){
                                percentage = ((float)s.TOT/last.TOT);
                                //cout <<Z << " " << A << " "  <<(vec_tot[vec_tot.size()-1]) << " " << vec_tot[i]<< endl;
                                A=s.A;
                                Z=s.Z;
                                A_F=s.A_FRAG;
                                Z_F=s.Z_FRAG;
                                tree->Fill();
                                }
                        }

                }                       cout << A << " " << Z << " " << A_F << " " << Z_F << " "  << percentage <<endl; //"   " << TOT_tmp<<endl;
                //else(percentage =0);
                //if(TOT>0 && A_F==A && Z_F==Z){cout << A << " " << Z << " " << A_F << " " << Z_F << " " <<TOT<<endl;}
                //if(TOT>0){
                //percentage = TOT/TOT_tmp;
                        //if(unreacted>0){eff_track = unreacted/TOT_tmp * 100.0;}
        //      cout << A<< " " << Z << " " << A_F << " " << Z_F << " "<<unreacted <<"   "  << TOT<<"  "<<eff_track<<endl;
        //
        //      }
        //      else{
        //              percentage=0;
                        //eff_track=0;

        //      }

                /*
                                //sigma = ((C_12_NUMDEN*TOT)/(Thick_C*Rho_C*TOT_tmp))*Barn;//barns
                if(TOT>0)
                {



                }
                else(cout << A << " " << Z << " " << A_F << " " << Z_F << " "  << "0" <<endl);
                */

        }
        tree->Write();
        file.close();


void cross_section_C(TFile*ofile,TTree*tree)
{

TFile*CROSS = new TFile("CROSS_SECTION_tmp.root","READ");
TTree*carbon_tree = (TTree*)CROSS->Get("carbon");
TTree*empty_tree = (TTree*)CROSS->Get("empty");
TTree*ch2_tree = (TTree*)CROSS->Get("ch2");
TLeaf*A_C = carbon_tree->FindLeaf("A");
TLeaf*Z_C = carbon_tree->FindLeaf("Z");
TLeaf*Z_F_C = carbon_tree->FindLeaf("Z_F");
TLeaf*A_F_C = carbon_tree->FindLeaf("A_F");
TLeaf*P_C = carbon_tree->FindLeaf("percentage");
TLeaf*A_CH2 = ch2_tree->FindLeaf("A");
TLeaf*Z_CH2 = ch2_tree->FindLeaf("Z");
TLeaf*Z_F_CH2 = ch2_tree->FindLeaf("Z_F");
TLeaf*A_F_CH2 = ch2_tree->FindLeaf("A_F");
TLeaf*P_CH2 = ch2_tree->FindLeaf("percentage");
TLeaf*A_E = empty_tree->FindLeaf("A");
TLeaf*Z_E = empty_tree->FindLeaf("Z");
TLeaf*Z_F_E = empty_tree->FindLeaf("Z_F");
TLeaf*A_F_E = empty_tree->FindLeaf("A_F");
TLeaf*P_E = empty_tree->FindLeaf("percentage");
ofile->cd();
int n = carbon_tree->GetEntries();//COULD PUT IF CONDITION THAT ALL TREES SAME SIZE??
for(int i=0;i<n;i++)
        {
        carbon_tree->GetEntry(i);
        empty_tree->GetEntry(i);
        ch2_tree->GetEntry(i);

        a_nuclei = A_C->GetValue();
        z_nuclei = Z_C->GetValue();
        a_frag = A_F_C->GetValue();
        z_frag = Z_F_C->GetValue();
        percentage_empty = P_E->GetValue();
        percentage_carbon = P_C->GetValue();
        percentage_ch2 =  P_CH2->GetValue();
        p_ce = percentage_carbon - percentage_empty;
        p_ch2e = percentage_ch2 - percentage_empty;
        //cout << p_ce << " " <<percentage_carbon <<" " <<  percentage_empty <<  endl;

        cout<< percentage_ch2 << "  " << percentage_empty << "  " << p_ch2e << endl;
        //if((p_ce>-1 or p_ch2e>-1) && (p_ce<1 and p_ch2e<1) && (p_ce!=0 or p_ch2e!=0) && ((a_nuclei - a_frag!=0)  or (z_nuclei - z_frag!=0))  ){
                //      cout << "a_nuclei  "<<a_nuclei << "  z_nuclei " << z_nuclei << "  "<<endl ;
                sigma_ce = (C_12*p_ce)/(N_a*Thick_C*Rho_C)*Barn*1000;//mB
                sigma_ch2e = (CH2*p_ch2e)/(N_a*Thick_CH2*Rho_CH2)*Barn*1000;//mB
                sigma_r  = (sigma_ch2e-sigma_ce)/2;
                cout <<a_nuclei <<" " << z_nuclei << " " <<a_nuclei - a_frag<<" " << z_nuclei - z_frag<< " "   <<sigma_ce << " " << sigma_ch2e << endl;
                tree->Fill();
        //}
        }
tree->Write();





}


  
  
 
void cross_section()
{
TFile*out_f = new TFile("CROSS_SECTION_tmp.root","RECREATE");

TTree*out_c = new TTree("carbon","carbon");
out_c->Branch("A",&A);
out_c->Branch("Z",&Z);
out_c->Branch("A_F",&A_F);
out_c->Branch("Z_F",&Z_F);
out_c->Branch("percentage",&percentage);
TTree*out_ch2 = new TTree("ch2","ch2");
out_ch2->Branch("A",&A);
out_ch2->Branch("Z",&Z);
out_ch2->Branch("A_F",&A_F);
out_ch2->Branch("Z_F",&Z_F);
out_ch2->Branch("percentage",&percentage);
TTree*out_e = new TTree("empty","empty");
out_e->Branch("A",&A);
out_e->Branch("Z",&Z);
out_e->Branch("A_F",&A_F);
out_e->Branch("Z_F",&Z_F);
out_e->Branch("percentage",&percentage);
cross_section_R("tofw_beta_offset_paddle_carbon_nofrsgate.txt",out_f,out_c);
cross_section_R("tofw_beta_offset_paddle_ch2_nofrsgate.txt",out_f,out_ch2);
cross_section_R("tofw_beta_offset_paddle_empty_nofrsgate.txt",out_f,out_e);

TFile*out_f1 = new TFile("CROSS_SECTION.root","RECREATE");
TTree*CROSS_SECTION = new TTree("cross_section_T","cross_section_T");
CROSS_SECTION->Branch("a_nuclei",&a_nuclei);
CROSS_SECTION->Branch("z_nuclei",&z_nuclei);
CROSS_SECTION->Branch("a_frag",&a_frag);
CROSS_SECTION->Branch("z_frag",&z_frag);
CROSS_SECTION->Branch("p_ce",&p_ce);
CROSS_SECTION->Branch("p_ch2e",&p_ch2e);
CROSS_SECTION->Branch("sigma_ce",&sigma_ce);
CROSS_SECTION->Branch("sigma_ch2e",&sigma_ch2e);
CROSS_SECTION->Branch("sigma_r",&sigma_r);
cross_section_C(out_f1,CROSS_SECTION);
out_f1->Close();




}


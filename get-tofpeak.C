{
  // Use CUTbasic, CUTlimits as defined in read-gates-we?.C
 
  char name[128];

  Int_t nrofruns=17; 
  Int_t run_no[128]={1041,1045,1051,1084,1090,1094,1099,1105,1110,1112,1117,1123,1128,1133,1138,1144,1149};

  //TF1 *fit = new TF1("fit","gaus(0) + pol1(3)",1,800);

  Double_t a0,a1,a2,a3,a4,norm;
  Double_t width = 5.;
  Double_t par[5];


  Float_t peakposition[nrofruns];
  Float_t sigma[nrofruns];

  for(Int_t i=0;i<nrofruns;i++)	{
	  sprintf(name,"~/DATA/ROOT/PR260/sorted0%4d.root",run_no[i]);
          cout << name << endl;
	  TFile *_file0 = TFile::Open(name);     
  	  TH1F *htof = new TH1F("htof","TOF",700,1500.,2200.);
          //DATA->Draw("toftdc1>>htof","","");
          DATA->Draw("tof>>htof","","");

	  switch(run_no[i]){
	  	case 1041 :htof->Fit("gaus","R","",2000,2200);   break; 
	  	case 1045 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1051 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1084 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1090 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1094 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1099 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1105 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1110 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1112 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1117 :htof->Fit("gaus","R","",2000,2200);   break;
	  	case 1123 :htof->Fit("gaus","R","",1900,2200);   break;
	  	case 1128 :htof->Fit("gaus","R","",1900,2200);   break;
	  	case 1133 :htof->Fit("gaus","R","",1900,2200);   break;
	  	case 1138 :htof->Fit("gaus","R","",1900,2200);   break;
	  	case 1144 :htof->Fit("gaus","R","",1900,2200);   break;
	  	case 1149 :htof->Fit("gaus","R","",1900,2200);   break;
 	  }

//	  fit->GetParameters(par);
	  gaus->GetParameters(par);

	  //a0=par[0];a1=par[1];a2=par[2];a3=par[3];
          //cout << endl << " par0 " << a0 <<"; par1 " << a1 <<"; par2 " << a2 << "; par3 "<< a3 << "; par4 "<< a4<< endl << endl;

          peakposition[i] = par[1];
          sigma[i] = par[2];

	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive(); 
  }
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << " "<< run_no[i] <<" "<< peakposition[i] <<" "<< sigma[i] << endl;
  }
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << ""<< run_no[i] <<"  Difference compared with run "<<run_no[0] <<"  "<< peakposition[i]-peakposition[0] << endl;
  }
 
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << run_no[i] <<"  "<< int(peakposition[0]-peakposition[i]) << endl;
  }


}





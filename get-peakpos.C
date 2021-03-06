{
  // Use CUTbasic, CUTlimits as defined elsewhee 
  char name[128];
  char text[128];

  //PR260, 0degr, 24Mg
  //Int_t run_no[]={1041,1045,1051,1084,1090,1094,1099,1105,1112,1117,1123,1128,1133,1138,1144,1149};
  Int_t run_no[]={1041,1051,1084,1090};
  Int_t nrofruns=sizeof(run_no)/sizeof(run_no[0]);  
 
  // for first pass fit: only gaussian
  Double_t par[5];
  Double_t peakposition[nrofruns];
  Double_t sigma[nrofruns];
  Double_t strength[nrofruns];
  Double_t fitgauslow=678;  // to define range where gauss fitting is done
  Double_t fitgaushi=688;   // to define range where gauss fitting is done

  // for fit with gaussian plus polynomial
  Double_t peakposition2[nrofruns];
  Double_t sigma2[nrofruns];
  Double_t pol0=100,pol1=0;
  Double_t rangelow=670;    // range of TF1 fit
  Double_t rangehi=700;     // range of TF1 fit
  Double_t fitcombinedlow=670;    // range over which fitting is performed
  Double_t fitcombinedhi=685;	  // range over which fitting is performed
  TF1 *fit = new TF1("fit","gaus(0) + pol2(3)",rangelow,rangehi);
  Double_t par2[5];

  for(Int_t i=0;i<nrofruns;i++)	{
	  sprintf(text,"-------- Fitting run nr %4d:",run_no[i]);
          cout << text << endl;
	  sprintf(name,"~/DATA/ROOT/PR260/sorted0%4d.root",run_no[i]);
	  TFile *_file0 = TFile::Open(name);     

	  cout<<"First fitting a single gaussian..."<<endl;
  	  TH1F *hX1pos = new TH1F("hX1pos","X1 Position",400,640.,740.);
          DATA->Draw("X1posC>>hX1pos",CUTbasic && CUTlimits,"");
	  if(run_no[i]<1080)  hX1pos->Fit("gaus","QR","",fitgauslow,fitgaushi);  // for Mg run 1064 and earlier
	  if(run_no[i]>1080)  hX1pos->Fit("gaus","QR","",fitgauslow+7,fitgaushi+7);  // for Mg run 1064 and after
	  gaus->GetParameters(par);
          strength[i] = par[0];
          peakposition[i] = par[1];
          sigma[i] = par[2];
	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive();
 
	  cout<<"Now use the gaussian fit as a starting point for a fit of a gaussian and a polynomial"<<endl;
	  fit->SetParameters(strength[i],peakposition[i],sigma[i],pol0,pol1);
          if(run_no[i]<1080) hX1pos->Fit("fit","QR","",fitcombinedlow,fitcombinedhi);
          if(run_no[i]>1080) hX1pos->Fit("fit","QR","",fitcombinedlow+5,fitcombinedhi+10);
          fit->GetParameters(par2);
          peakposition2[i] = par2[1];
          sigma2[i] = par2[2];
	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive(); 
  }
  cout << endl;
  cout << "First pass fit: extract estimates for gaussian position and width: "<< endl;
  for(Int_t i=0;i<nrofruns;i++)	{
    	 cout << "Run nr: "<< run_no[i] <<"  Peak position: "<< peakposition[i] <<"  Peak sigma:"<< sigma[i] << endl;
  }	  
  cout << endl;
  cout << "Final fit: gaussian plus a polynomial: "<< endl;
  for(Int_t i=0;i<nrofruns;i++)	{
     cout << "Run nr: "<< run_no[i] <<"  Peak position: "<< peakposition2[i] <<"  Peak sigma:"<< sigma2[i] << endl;
  }
  cout << endl;
  cout << "Note the difference between fitting a single gaussian compared to a more complete fit... "<< endl;
  cout << "-----------------------------------------------------"<< endl; 
  cout << endl;
  cout << "Copy the following into your x1 position offset file: "<< endl;
  cout << endl;
  for(Int_t i=0;i<nrofruns;i++)	{
     cout <<  run_no[i] <<"  "<< peakposition2[0] - peakposition2[i]<< endl;
  }



}





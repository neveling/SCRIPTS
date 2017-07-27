{
  Double_t pi=3.14159265359;
  // Use CUTbasic, CUTlimits as defined elsewhee 
  char name[128];
  char text2[128];

  int nrofpeaks=11;
  Double_t Ex[nrofpeaks];
  Double_t low[nrofpeaks];
  Double_t high[nrofpeaks];
  Double_t Ex[nrofpeaks];

//-------------------------------------------------------------

  // for 24Mg:

  Ex[0]= 9.00334;
  Ex[1]= 9.14599;
  Ex[2]= 9.30549;
  Ex[3]= 10.36051;
  Ex[4]= 10.6797;
  Ex[5]= 11.5182;
  Ex[6]= 11.7281;
  Ex[6]= 11.8649;
  Ex[7]= 12.776;
  Ex[8]= 13.0868;
  Ex[9]= 15.25;
  Ex[10]= 13.85;

  low[0]=Ex[0]-0.07;   high[0]=Ex[0]+0.07;
  low[1]=Ex[1]-0.05;   high[1]=Ex[1]+0.05;
  low[2]=Ex[2]-0.07;   high[2]=Ex[2]+0.07;
  low[3]=Ex[3]-0.07;   high[3]=Ex[3]+0.07;
  low[4]=Ex[4]-0.07;   high[4]=Ex[4]+0.07;
  low[5]=Ex[5]-0.07;   high[5]=Ex[5]+0.07;
  low[6]=Ex[6]-0.05;   high[6]=Ex[6]+0.05;
  low[7]=Ex[7]-0.07;   high[7]=Ex[7]+0.07;
  low[8]=Ex[8]-0.07;   high[8]=Ex[8]+0.07;
  low[9]=Ex[9]-0.07;   high[9]=Ex[9]+0.07;
  low[10]=Ex[10]-0.07;   high[10]=Ex[10]+0.07;

  // for first pass fit: only gaussian
  Double_t par[nrofpeaks];
  Double_t peakposition[nrofpeaks];
  Double_t sigma[nrofpeaks];
  Double_t strength[nrofpeaks];

  // for fit with gaussian plus polynomial
  Double_t par2[nrofpeaks];
  Double_t peakposition2[nrofpeaks];
  Double_t sigma2[nrofpeaks];

  Double_t pol0=100,pol1=0;

  TF1 *fit = new TF1("fit","gaus(0) + pol2(3)",0,25);
 
  // for fit with gaussian plus polynomial
  for(Int_t i=0;i<nrofpeaks;i++)	{
	  sprintf(text2,"-------- Fitting peak %1d:",i);
          cout << text2 << endl;

	  hExdiff->Fit("gaus","QR","",low[i],high[i]);  
	  //hEx->Fit("gaus","QR","",low[i],high[i]);  
	  gaus->GetParameters(par);
          strength[i] = par[0];
          peakposition[i] = par[1];
          sigma[i] = par[2];
	  c1->Modified(); c1->Update();
	  //c10->Modified(); c10->Update();
	  //c1->WaitPrimitive();

	  fit->SetParameters(strength[i],peakposition[i],sigma[i],pol0,pol1);
          hExdiff->Fit("fit","QR","",low[i],high[i]);
          //hEx->Fit("fit","QR","",low[i],high[i]);
          fit->GetParameters(par2);
          peakposition2[i] = par2[1];
          sigma2[i] = par2[2];
	  //c10->Modified(); c10->Update();
	  c1->Modified(); c1->Update();
	  //c10->WaitPrimitive(); 
	  c1->WaitPrimitive(); 
  }



  cout << "Final fit: gaussian plus a polynomial: "<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout <<"  Peak position: "<< peakposition2[i] <<"  Peak sigma: "<< sigma2[i] << endl;
  }
  cout << endl;

  cout <<"Ex NNDC (MeV)   Ex(fit) (MeV)   Diff (keV) "<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout << Ex[i]  <<"          "<< peakposition2[i] <<"         "<< 1000.*(Ex[i]-peakposition2[i]) <<endl;
  }
  cout << endl;



}





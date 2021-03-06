{
  Double_t pi=3.14159265359;
  // Use CUTbasic, CUTlimits as defined elsewhee 
  char name[128];
  char text2[128];

  int nrofpeaks=9;
  Double_t startposition[nrofpeaks];
  Double_t low[nrofpeaks];
  Double_t high[nrofpeaks];
  Double_t Ex[nrofpeaks];
  Double_t ExErr[nrofpeaks];


//-------------------------------------------------------------
  startposition[0]=690.;
  startposition[1]=685.4;
  startposition[2]=680.6;
  startposition[3]=647.3;
  startposition[4]=636.4;
  startposition[5]=610.7;
  startposition[6]=604.2;
  startposition[7]=599.5;
  startposition[8]=536.5.;
  //startposition[9]=491.2;


  low[0]=startposition[0]-1.8;   high[0]=startposition[0]+2.2;
  low[1]=startposition[1]-2;   high[1]=startposition[1]+2;
  low[2]=startposition[2]-2;   high[2]=startposition[2]+2;
  low[3]=startposition[3]-1.5; high[3]=startposition[3]+1.5;
  low[4]=startposition[4]-1.5;   high[4]=startposition[4]+1.5;
  low[5]=startposition[5]-1.5;   high[5]=startposition[5]+1.5;
  low[6]=startposition[6]-1.5;   high[6]=startposition[6]+1.5;
  low[7]=startposition[7]-1.5;   high[7]=startposition[7]+1.5;
  low[8]=startposition[8]-1.5;   high[8]=startposition[8]+1.5;
//  low[9]=startposition[9]-1.5;   high[9]=startposition[9]+1.5;
//  low[10]=startposition[10]-1.5;   high[10]=startposition[10]+1.5;

  Ex[0]= 9.00334;
  Ex[1]= 9.14599;
  Ex[2]= 9.30549;
  Ex[3]= 10.36051;
  Ex[4]= 10.6797;
  Ex[5]= 11.5182;
  Ex[6]= 11.7281;
  Ex[7]= 11.8649;
  Ex[8]= 13.85;
  //Ex[11]= 17.36;

  ExErr[0]= 0.00009;
  ExErr[1]= 0.00015;
  ExErr[2]= 0.00024;
  ExErr[3]= 0.00013;
  ExErr[4]= 0.0004;
  ExErr[5]= 0.0006;
  ExErr[6]= 0.0001;
  ExErr[7]= 0.00013;
  ExErr[8]= 0.02;
  //ExErr[11]=0.05;

/*
//-------------------------------------------------------------
  startposition[0]=680.;
  startposition[1]=636.;
  startposition[2]=604.;
  startposition[3]=536.;

  low[0]=startposition[0]-2;   high[0]=startposition[0]+2;
  low[1]=startposition[1]-2;   high[1]=startposition[1]+2;
  low[2]=startposition[2]-2;   high[2]=startposition[2]+2;
  low[3]=startposition[3]-1.5;   high[3]=startposition[3]+1.5;

  Ex[0]=9.30549.;
  Ex[1]=10.6797.;
  Ex[2]=11.7281.;
  Ex[3]=13.85.;
-----------------------------------------------------
*/

  // for first pass fit: only gaussian
  Double_t par[nrofpeaks];
  Double_t peakposition[nrofpeaks];
  Double_t sigma[nrofpeaks];
  Double_t strength[nrofpeaks];

  // for fit with gaussian plus polynomial
  Double_t par2[nrofpeaks];
  Double_t peakposition2[nrofpeaks];
  Double_t sigma2[nrofpeaks];

  Double_t posErr[nrofpeaks];

  Double_t pol0=100,pol1=0;

  TF1 *fit = new TF1("fit","gaus(0) + pol2(3)",0,800);
 
  // for fit with gaussian plus polynomial
  for(Int_t i=0;i<nrofpeaks;i++)	{
	  sprintf(text2,"-------- Fitting peak %1d:",i);
          cout << text2 << endl;

	  hX1diff->Fit("gaus","R","",low[i],high[i]);  
	  gaus->GetParameters(par);
          strength[i] = par[0];
          peakposition[i] = par[1];
          sigma[i] = par[2];
	  
	  c1->Modified(); c1->Update();
	  //c1->WaitPrimitive();

	  fit->SetParameters(strength[i],peakposition[i],sigma[i],pol0,pol1);
          hX1diff->Fit("fit","R","",low[i],high[i]);
          fit->GetParameters(par2);
          peakposition2[i] = par2[1];
          sigma2[i] = par2[2];
          posErr[i] = fit->GetParError(1);

	  c1->Modified(); c1->Update();
	  c1->WaitPrimitive(); 
  }

  cout << "Final fit: gaussian plus a polynomial: "<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout <<"  Peak position: "<< peakposition2[i] <<"  Peak sigma: "<< sigma2[i] << endl;
  }
  cout << endl;

  cout <<"Ex (MeV)  Peak position (mm)   Peak Err "<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout << Ex[i]  <<" "<< peakposition2[i] << " " << posErr[i]<< endl;
  }
  cout << endl;



//---------------------------------------------------------------------
// without target thickness
//  Double_t Rigidity[nrofpeaks]= {4031.2391214857,4029.689137627,4027.9553014719,4016.4663041375,4012.9866141292,4003.8180382014,4001.5212312748,4000.0217314505,3990.0266109613,3986.6107767399,3962.74735412345};

// when including target thickness, interaction at the back only
//  Double_t Rigidity[nrofpeaks]= {4030.3227419764,4028.7724363855,4027.0382399757,4015.5469549106,4012.0664265587,4002.8959216804,3999.0988130565,3989.1015723905,3985.6850106047,3961.8164621291};

// when including target thickness, average of interaction in front or at the back
//  Double_t Rigidity[nrofpeaks]= {4030.306147318,4028.7555613875,4027.0210508417,4015.5276696239,4012.0465013411,4002.8742990388,3999.0764827429,3989.0773651866,3985.66015739,3961.7870296581};

// when including target thickness, average of interaction in front or at the back, for latest version (26 Jul 17) of calibration
  Double_t Rigidity[nrofpeaks]= {4030.306147318,4028.7555613875,4027.0210508417,4015.5275605135,4012.043224943,4002.8742990388,4000.5754838472,3999.0764827429,3977.2552961014};



  // Double_t Rigidity[nrofpeaks]= {4027.9553014719,4012.9833390216,4001.5201361728,3978.2093104017};
  // rigidity array from jrelkin

  //Int_t nrofRigidity=sizeof(Rigidity)/sizeof(Rigidity[0]);
  //if(nrofpeaks != nrofRigidity) cout<< "The Rigidity array is of wrong length!"<<endl;

  TCanvas *c5= new TCanvas("c5","c5",1700,10,1100,500);
  c5->cd();

  //TGraph *GREx = new TGraph(nrofpeaks,peakposition2,Rigidity);
  TGraphErrors *GREx = new TGraphErrors(nrofpeaks,peakposition2,Rigidity,posErr,ExErr);

  GREx->SetMarkerColor(1);
  GREx->SetMarkerStyle(20);
  GREx->SetMarkerSize(0.65);
  GREx->SetLineStyle(3);
  GREx->GetXaxis()->SetTitle("Position (mm)");
  GREx->GetYaxis()->SetTitle("QBRho (QTmm)");
  GREx->Draw();


  //TF1 *fitEx = new TF1("fitEx","[0] + [1]*x + [2]*x*x + [3]*x*x*x",400.,750.);
  TF1 *fitEx = new TF1("fitEx","[0] + [1]*x + [2]*x*x ",488.,695.);
  fitEx->SetParameter(0,3800.);
  fitEx->SetParameter(1,0.27);
  fitEx->SetParameter(2,0.00005);
  GREx->Fit("fitEx","R");

  cout <<"ExNNDC (MeV)     Rigidity"<< endl;
  for(Int_t i=0;i<nrofpeaks;i++)	{
     cout << Ex[i]  <<"      " << Rigidity[i]<< endl;
  }


/*
//---------------------------------------------------------------------
  Double_t fitpar[5];

  fitEx->GetParameters(fitpar);
  double a,b,c,d;
  a = fitpar[0];
  b = fitpar[1];
  c = fitpar[2];
  d = fitpar[3];
  
  double calcEx[nrofpeaks];
  for(Int_t i=0;i<nrofpeaks;i++){  
     calcEx[i]= a + b*peakposition[i] + c*peakposition[i]**2 +d*peakposition[i]**3;
 
     cout << " "<<Ex[i] <<"  "<< calcEx[i] <<" Diff = "<< 1000*(ExNNDC[i] - calcEx[i]) <<" keV" << endl;
  }
//---------------------------------------------------------------------
*/

}





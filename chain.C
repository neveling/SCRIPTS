{
  TChain *DATAChain = new TChain("DATA","MEGA Tree");
  char name[128];


  Char_t name1[30];
  sprintf(name1,".x ../SCRIPTS/histosPR236.C");
  gROOT->ProcessLine(name1);
  //sprintf(name1,".x ../SCRIPTS/read-gates-tgt5-run29x.C");
  //gROOT->ProcessLine(name1);

  TH1F *hX1pos1 = new TH1F("hX1pos1","X1 Position",2400,0.,800.);
 
  //PR236, WE1, Mg
  Int_t run_no1[]={1093,1100,1104,1108,1112,1117,1123,1128};
  
  //PR236, WE2, Ca
  //Int_t run_no1[]={2125,2126,2130,2134};

  Int_t nrofruns1=sizeof(run_no1)/sizeof(run_no1[0]);  

  for(Int_t i=0;i<nrofruns1;i++)	{
	  sprintf(name,"/home/neveling/DATA/ROOT/PR236/run0%4d.root",run_no1[i]);
          cout<< name<<endl;
	  DATAChain->Add(name);
  }
  DATAChain->Draw("X1posC>>hX1pos1",CUTbasic && CUTlimits,"");

  //DATAChain->Draw("pad1:tof>>hpad1vstof",CUTbasic && CUTlimits,"col");

}

//DATAChain->Draw("thetaFP*(-0.5795 -0.0000457*X1pos) + (23.1-0.003541*X1pos):X1pos>>hThSCATvsX1",CUTbasic,"");
//the following is from Daniel
//DATAChain->SetAlias("newX1","X1pos + 0.1211*thetaSCAT - 0.0001*pow(thetaSCAT-1.,2)  ")

//DATAChain->Draw("(X1pos-1.2*thetaSCAT)>>hX1pos",CUTbasic && CUTlimits,"");

//  DATAChain->Draw("SiliconEnergy:X1pos>>hESivsX",CUTbasic && CUTlimits && CUTsitime && CUTsip0 && "pulser==0","col");

//  DATAChain->Draw("SiliconEnergy:SiliconTime>>h(10000,-12000,14000,100,0,4000)",CUTbasic && CUTlimits &&  "ADCChannelFront>0 && ADCChannelFront<16 && pulser==0","col");

//  DATAChain->Draw("X1pos>>hX1posall",CUTbasic && CUTlimits &&  "pulser==0","col");
  
//  DATAChain->Draw("X1pos>>hX1posp0",CUTbasic && CUTlimits && CUTsitime && CUTsip0 && "pulser==0","col");

//  DATAChain->Draw("GammaRawADC:X1pos>>hESivsX",CUTbasic && CUTlimits && CUTsip0 && "pulser==0","col");

//  DATAChain->Draw("GammaEnergy:GammaTime>>h(10000,-12000,14000,1000,0,20000)",CUTbasic && CUTlimits &&  "GammaDetectorLabel==1 && pulser==0","col");

//  DATAChain->Draw("GammaEnergy:X1pos>>hENaiX(800,0,800,500,0,20000)",CUTbasic && CUTlimits && CUTnaitime && "pulser==0","col");

//  DATAChain->Draw("GammaEnergy:X1pos>>hENaiX(800,0,800,600,0,6000)",CUTbasic && CUTlimits,"col");


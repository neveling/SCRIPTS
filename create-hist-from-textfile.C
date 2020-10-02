{
  TString file;
  TString pathname="/Data/ANALYSIS/PR183/RCNP/";
  TString filename="rcnp_40Ca.dat";
  file=pathname+filename;
  double cs[6000];
  double err[6000];
  double Ex[6000];
  int counter=0;
  Char_t file_name[100];
//==================read input=======================
  sprintf(file_name,"%s",file.Data());
  ifstream inputfile(file_name);  
  if(!inputfile)  { 
    cerr<<"Can't open input file, -> exit"<<endl; 
    exit(1);
  }
  else cerr << "Opening file " <<file_name<<endl;

  while(!inputfile.eof()){     
	inputfile >> Ex[counter] >> cs[counter] >> err[counter];
	//inputfile >> Ex[counter] >> cs[counter];
	//cout<<"   "<<counter<<"   "<<Ex[counter]<<" "<<cs[counter]<<" "<<err[counter]<<"  "<<endl;	
	counter++;
  }
//==================create histogram=======================
  //TH1F *hrcnp = new TH1F("hrcnp","Excitation energy",4400,3.,25.);   // for Pb
  TH1F *hrcnp = new TH1F("hrcnp","Excitation energy",6000,0.,30.);
  for(Int_t j = 0; j < (counter-1); j++) {
	   hrcnp->SetBinContent(j,cs[j]);
  }

  inputfile.close();


  //TH1F *hrcnp24Mg = new TH1F("hrcnp24Mg","Excitation energy",6000,0.,30.);
  //TH1F *hrcnp16O = new TH1F("hrcnp16O","Excitation energy",6000,0.,30.);
  TH1F *hrcnp40Ca = new TH1F("hrcnp40Ca","Excitation energy",6000,0.,30.);
  //TH1F *hrcnp96Mo = new TH1F("hrcnp96Mo","Excitation energy",6000,0.,30.);
  //TH1F *hrcnp208Pb = new TH1F("hrcnp208Pb","Excitation energy",4400,3.,25.);

}

hrcnp40Ca->Add(hrcnp);


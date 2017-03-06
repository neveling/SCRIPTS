{
gStyle->SetPalette(1,0);


Char_t name1[30];
     
sprintf(name1,".x SCRIPTS/rd_gate_tofX1-run1126.C");
gROOT->ProcessLine(name1);
sprintf(name1,".x SCRIPTS/rd_gate_pad1tof-run1126.C");
gROOT->ProcessLine(name1);

//sprintf(name1,"_file0->cd()");
//gROOT->ProcessLine(name1);

sprintf(name1,".x SCRIPTS/histosPR236.C");
gROOT->ProcessLine(name1);

TCut CUTbasic = "CUTpad1tof  && CUTtofX1 ";
TCut CUTlimits = "X1flag==0 && U1flag==0 && U2flag==0 && X1pos>-100";
// && thetaSCAT>-2. && thetaSCAT<2.";
TCut CUTy = "Y1>-15 && Y1<25";      
TCut CUTybckg = "Y1>-40 && Y1<-20";      
TCut CUTtrigvsCI = "triggerI/CII<3";


}

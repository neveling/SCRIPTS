{
gStyle->SetPalette(1,0);


Char_t name1[30];

/*     
sprintf(name1,".x ../SCRIPTS/rd_gate_tofX1-run1126.C");
gROOT->ProcessLine(name1);
sprintf(name1,".x ../SCRIPTS/rd_gate_pad1tof-run1126.C");
gROOT->ProcessLine(name1);
*/
//sprintf(name1,"_file0->cd()");
//gROOT->ProcessLine(name1);
//TCut CUTbasic = "CUTpad1tof  && CUTtofX1 ";
TCut CUTbasic = "tof>2250 && tof<2350 && pad1>1500 && pad1<2300";


TCut CUTlimits = "X1flag==0 && U1flag==0 && X2flag==0 && U2flag==0 && X1pos>-100";
// && thetaSCAT>-2. && thetaSCAT<2.";
TCut CUTy = "Y1>-14 && Y1<20";      
TCut CUTybckg = "Y1>-40 && Y1<-20";      
TCut CUTtrigvsCI = "triggerI/CII<3";

sprintf(name1,".x /home/neveling/K600/PR260-Iyabo-GMR/ANALYSIS/SCRIPTS/histosPR260.C");
gROOT->ProcessLine(name1);

}

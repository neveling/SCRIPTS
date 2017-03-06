{
gStyle->SetPalette(1,0);

c3 = new TCanvas("c3","c3",800,10,1000,600);
c3->SetFillColor(0);
c3->SetGridy(0);
c3->SetFillColor(0);

TCut CUTYbck1 = "Y1>-32 && Y1<-15";   
TCut CUTYbck2 = "Y1>26 && Y1<32";  
 
// Create 1 dimensional histograms for Position
TH1F *hEx = new TH1F("hEx","Excitation energy",3000,0,30);
TH1F *hExback1 = new TH1F("hExback1","Excitation energy",3000,0,30);
TH1F *hExback2 = new TH1F("hExback2","Excitation energy",3000,0,30);
TH1F *hExbacktot = new TH1F("hExbacktot","Excitation energy",3000,0,30);
TH1F *hExdiff = new TH1F("hExdiff","Excitation energy",3000,0,30);

DATAChain->Draw("Ex>>hEx",CUTbasic && CUTlimits && CUTy,"");
DATAChain->Draw("Ex>>hExback2",CUTbasic && CUTlimits && CUTYbck1,"");
DATAChain->Draw("Ex>>hExback1",CUTbasic && CUTlimits && CUTYbck2,"");

hExdiff->SetTitle("^{7}Li_{2}CO_{3}(#alpha,#alpha) at 0^{o} (background subtracted)");
hExdiff->SetStats(0);
hExdiff->GetXaxis()->SetTitle("E_{x} (MeV)");
hExdiff->GetXaxis()->CenterTitle(true);
hExdiff->GetYaxis()->SetTitle("Counts/10keV");
hExdiff->GetYaxis()->CenterTitle(true);
hExdiff->GetXaxis()->SetTitleOffset(1.1);  
hExdiff->GetYaxis()->SetTitleOffset(1.4); 

hExdiff->Add(hEx);
hExdiff->Add(hExback1,-20.5/17.);
hExdiff->Add(hExback2,-20.5/6.);
hExbacktot->Add(hExback1,20.5/17.);
hExbacktot->Add(hExback2,20.5/6.);

hEx->SetLineColor(4);
hExback1->SetLineColor(2);
hExback2->SetLineColor(3);
hExdiff->SetLineColor(1);
hExbacktot->SetLineColor(6);

hEx->Draw();
hExdiff->Draw("same");
hExback1->Draw("same");
hExback2->Draw("same");
hExbacktot->Draw("same");


}



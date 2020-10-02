//#include <iostream>

{
  ofstream out;
  out.open("Ex-24Mg.dat");

  float lut;
  Int_t nbins = hExdiff->GetNbinsX();

  // Now write to a datafile
  for(Int_t i=0;i<nbins;i++) {
    out << (float(i)*0.01-0.005) << "  " << hExdiff->GetBinContent(i)  << endl;
    //out << i << "  " << hExdiff->GetBinCenter(i)  << endl;   // give value of xaxis of bin
    //out << hExdiff->GetBinCenter(i)  << "  " << hExdiff->GetBinContent(i)  << endl;   // give value of xaxis of bin

  }

  out.close();
}

{
gStyle->SetPalette(1,0);

//==============================================
TH1F *hExCs = new TH1F("hExCs","Cross-section Excitation energy",3100,-1.,30.);
hExCs->Add(hExdiff);

SA = 1.74;  // msr   -->3.48/2 
cii  = 3422517; 
tgtthick =  0.95;     // mg/cm^2       
A=96;
e=1.60217733;
eff=0.92*0.86*0.9;   
range=6;
NA=6.0221367;
elecdead=0.99;
ebin=0.01;

incidentflux=(cii*range)/e;
scatterers=(tgtthick*NA)/A;
temp=elecdead*eff*ebin*SA;
norm=incidentflux*scatterers*temp;

cout<<"cii= "<<cii<<endl;
cout<<"Incident flux= "<<incidentflux<<endl;
cout<<"scatterers="<<scatterers <<endl;
cout<<"temp="<< temp<<endl;

hExCs->Scale(1000/norm);
hExCs->Draw();

}





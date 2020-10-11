#include<TCanvas.h>
#include<TF2.h>
#include<TMath.h>


void bindingEnergyPerNucleon()
{
    TCanvas* c1 = new TCanvas("c1", "canvas 1 - 2D Function", 700,700);
    
    TF2* bindungsEnergie = new TF2("bindungsEnergie","pow(x + y,-1.)*( -23.2*pow(x - y,2.)/(x + y) - (0.714*pow(y,2.))/pow(x + y,1./3.) - 18.3*pow(x + y,2./3.) + 15.8*(x + y))",0,200,0,200);
    bindungsEnergie->SetTitle("Bindungsenergie Pro Nukleon;N;Z");
    
    c1->cd();
    bindungsEnergie->Draw("cont4");

}

void probabilityDistributions(){
    // set up BW distribution
    TH1D *h_RanNum_BW = new TH1D("h_RanNum_BW", "Breit-Wigner dist.",100,0.0,20.0);
    TH1D *h_RanNum_Gaus = new TH1D("h_RanNum_Gaus","Gaussian dist.",100,0.0,20.0);
    TRandom3 rndgen;
    for (int i = 0; i< 10000; i++){
        h_RanNum_BW->Fill(rndgen.BreitWigner(10.0,3.0));
        h_RanNum_Gaus->Fill(rndgen.BreitWigner(10.0,3.0/2.3548));
    }


    // Declare Canvas
    TCanvas *c_probDists = new TCanvas("c_probDists", "Random Number Distributions", 600,400);
    c_probDists->cd();
    gStyle->SetOptStat(0);

    //display parameters
    h_RanNum_Gaus->SetLineColor(kRed);
    h_RanNum_Gaus->SetFillColor(kRed);
    h_RanNum_Gaus->SetFillStyle(3003);
    h_RanNum_Gaus->Draw();
    
    h_RanNum_BW->SetLineColor(kBlue);
    h_RanNum_BW->SetFillColor(kBlue);
    h_RanNum_BW->SetFillStyle(3005);
    h_RanNum_BW->Draw("SAME");


    TLegend *legend = c_probDists->BuildLegend(0.7,0.7,0.9,0.9,"Probability Distributions");
legend->Draw();

c_probDists->Print("probDists_BW_Gaus.pdf");

}

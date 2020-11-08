void poissonDistribution(){
    TH1F *poisson_dist  = new TH1F("poisson_dist",  "#mu = 0.5; k; N_{events}", 15,0.0,15.0);
    TH1F *poisson_dist2 = new TH1F("poisson_dist2", "#mu = 2; k; N_{events}", 15,0.0,15.0);
    TH1F *poisson_dist3 = new TH1F("poisson_dist3", "#mu = 8; k; N_{events}", 15,0.0,15.0);
    TRandom3 rndgen;
    for (int i = 0; i < 10000; i++){
        poisson_dist->Fill(rndgen.Poisson(0.5));
        poisson_dist2->Fill(rndgen.Poisson(2));
        poisson_dist3->Fill(rndgen.Poisson(8));
    }
   
    TCanvas *c_probDists = new TCanvas("c_probDists","Poisson Distributions",600,600);
    c_probDists->cd();


    poisson_dist->SetLineColor(kGreen);
    poisson_dist->SetFillColor(kGreen);
    poisson_dist->SetFillStyle(3005);
    poisson_dist->Draw();


    poisson_dist2->SetLineColor(kBlue);
    poisson_dist2->SetFillColor(kBlue);
    poisson_dist2->SetFillStyle(3005);
    poisson_dist2->Draw("SAME");


    poisson_dist3->SetLineColor(kRed);
    poisson_dist3->SetFillColor(kRed);
    poisson_dist3->SetFillStyle(3005);
    poisson_dist3->Draw("SAME");

    TLegend *leg;
    leg = c_probDists->BuildLegend(0.75, 0.7, 0.9, 0.9);

    c_probDists->Print("poissonDists.pdf");
}

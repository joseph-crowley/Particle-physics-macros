void oneDFunction()
{
    TF1* oneDFunction = new TF1("oneDFunction", "pow(x, [0])");
    oneDFunction->SetParameter(0, 1);
    oneDFunction->SetTitle("#lambda = 1");


    TCanvas* can = new TCanvas("can", "1D functions",600,400);
    can->cd();

    oneDFunction->Draw();
    TF1* oneDFunction2 = new TF1(*oneDFunction); 
    oneDFunction2->SetParameter(0, 2);
    oneDFunction2->SetTitle("#lambda = 2");
    oneDFunction2->SetLineColor(kBlue);
    oneDFunction2->Draw("same");

    TLegend* leg;
    leg = can->BuildLegend(0.55,0.7,0.9,0.9);
    leg->SetHeader("Legend");
 
    oneDFunction->SetTitle("my plot of x^{#lambda}; x;y");

    can->SaveAs("problem_Set_3.pdf");
}

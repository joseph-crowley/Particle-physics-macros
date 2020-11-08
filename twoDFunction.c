void twoDFunction()
{
    TCanvas* can = new TCanvas("can", "twoDFunctionCanvas", 600,400); 
    can->cd();

    TF2* twoDFunction = new TF2("twoDFunction", "sin(x * y)/(x*y)",-2*sqrt(TMath::Pi()),2*sqrt(TMath::Pi()),-2*sqrt(TMath::Pi()),2*sqrt(TMath::Pi()));
    const Int_t Number = 3;
    twoDFunction->SetTitle("sin(x * y)/(x*y); x; y");
    Double_t Red[Number]    = { 1.00, 0.00, 0.00};
    Double_t Green[Number]  = { 0.00, 1.00, 0.00};
    Double_t Blue[Number]   = { 1.00, 0.00, 1.00};
    Double_t Length[Number] = { 0.00, 0.50, 1.00 };
    Int_t nb=50;
    TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
    twoDFunction->SetContour(nb);
    twoDFunction->Draw("colz");


    can->SaveAs("twoDFunction.pdf");
}
